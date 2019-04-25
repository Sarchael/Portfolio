                    #include "hd44780.h"
#include "rtc.h"
#include "bmp280.h"
#include <stdlib.h>

void initSPI() {

    DDRB = ( 1 << PB4 ) | ( 1 << PB5 ) | ( 1 << PB7 ); //MOSI, SS, SCK jako wyjscia

    SPCR |= ( 1 << SPE ) | ( 1 << MSTR ); //Init
    SPCR &= ~(( 1 << CPHA ) | ( 1 << CPOL ) ); //Tryb 00
    SPCR |= ( 1 << SPR1 ); //czestotliwosc 1/128
}

void initButtons() {

    DDRD &= ~( 1 << PD5 ); //Ustawienie PD6 jaki pin wejœciowy
    PORTD |= ( 1 << PD5 ); //Pin od przycisku na wejœciu ma 1

    DDRD &= ~( 1 << PD6 ); //Ustawienie PD6 jaki pin wejœciowy
    PORTD |= ( 1 << PD6 ); //Pin od przycisku na wejœciu ma 1
}

void initDiodes( struct bmp280_dev bmp ) {

    DDRD |= ( 1 << PD0 ) | ( 1 << PD2 ) | ( 1 << PD4 );

    int8_t rslt = bmp280_set_power_mode( BMP280_NORMAL_MODE, &bmp );
    uint8_t meas_dur = bmp280_compute_meas_time( &bmp );


    if ( rslt == BMP280_OK ) {

       struct bmp280_uncomp_data ucomp_data;

       bmp.delay_ms( meas_dur );

       rslt = bmp280_get_uncomp_data( &ucomp_data, &bmp );

       if ( rslt == BMP280_OK ) {

          double temp = bmp280_comp_temp_double( ucomp_data.uncomp_temp, &bmp );
          double pres = bmp280_comp_pres_double( ucomp_data.uncomp_press, &bmp ) / 100.0;

          if( ( temp > 25.0 || temp < 20.0 ) && ( pres > 1030.0 || pres < 1000.0 ) )
          {
             //œwieci siê dioda czerwona
             PORTD |= ( 1 << PD4 );
             PORTD &= ~( 1 << PD0 );
             PORTD &= ~( 1 << PD2 );
          }
          else if( ( temp > 25.0 || temp < 20.0 ) || ( pres > 1030.0 || pres < 1000.0 ) )
          {
             //œwieci siê dioda ¿ó³ta
             PORTD |= ( 1 << PD2 );
             PORTD &= ~( 1 << PD0 );
             PORTD &= ~( 1 << PD4 );
          }
          else
          {
             //œwieci siê dioda zielona
             PORTD |= ( 1 << PD0 );
             PORTD &= ~( 1 << PD2 );
             PORTD &= ~( 1 << PD4 );
          }
       }
    }
}

int main( void ) {

    char buffer[16];
    double temp;
    double pres;

    struct rtc clock;

    struct bmp280_dev bmp;
    struct bmp280_uncomp_data ucomp_data;
    int8_t rslt;
    uint8_t meas_dur;

    int counter = 0;

    initSPI();
    LCD_Initalize();
    rtcInit();
    initSensor( &bmp );
    initButtons();
    initDiodes( bmp );

    while ( 1 ) {

        if (( PIND & ( 1 << PD5 ) ) && ( PIND & ( 1 << PD6 ) ) ) { //Jak nie s¹ wciœniête przyciski

            rtcGetAll( &clock );

            sprintf( buffer, "Godzina %02i:%02i:%02i", clock.hour, clock.min, clock.sec );
            LCD_GoTo( 0, 0 );
            LCD_WriteText( buffer );

            sprintf( buffer, "%s, %02i.%02i.20%02ir", clock.wd, clock.day, clock.month, clock.year );
            LCD_GoTo( 0, 1 );
            LCD_WriteText( buffer );

        } else if ( !( PIND & ( 1 << PD5 ) ) && ( PIND & ( 1 << PD6 ) ) ) { //gdy przycisk 1 wciœniêty

            rslt = bmp280_set_power_mode( BMP280_NORMAL_MODE, &bmp );
            meas_dur = bmp280_compute_meas_time( &bmp );

            if ( rslt == BMP280_OK ) {

                bmp.delay_ms( meas_dur );

                rslt = bmp280_get_uncomp_data( &ucomp_data, &bmp );

                if ( rslt == BMP280_OK ) {

                    temp = bmp280_comp_temp_double( ucomp_data.uncomp_temp, &bmp );

                    LCD_Clear();
                    LCD_GoTo( 2, 0 );
                    LCD_WriteText( "TEMPERATURA:" );
                    dtostrf( temp, 2, 1, buffer );
                    LCD_GoTo( 5, 1 );
                    LCD_WriteText( buffer );
                    LCD_GoTo( 10, 1 );
                    LCD_WriteText( "C" );

                    bmp.delay_ms( 1000 );
                }
            }

        } else if (( PIND & ( 1 << PD5 ) ) && !( PIND & ( 1 << PD6 ) ) ) { //gdy przycisk 2 wciœniêty

            rslt = bmp280_set_power_mode( BMP280_NORMAL_MODE, &bmp );
            meas_dur = bmp280_compute_meas_time( &bmp );

            if ( rslt == BMP280_OK ) {

                bmp.delay_ms( meas_dur );

                rslt = bmp280_get_uncomp_data( &ucomp_data, &bmp );

                if ( rslt == BMP280_OK ) {

                    pres = bmp280_comp_pres_double( ucomp_data.uncomp_press, &bmp ) / 100.0;

                    LCD_Clear();
                    LCD_GoTo( 3, 0 );
                    LCD_WriteText( "CISNIENIE:" );
                    dtostrf( pres, 4, 1, buffer );
                    LCD_GoTo( 3, 1 );
                    LCD_WriteText( buffer );
                    LCD_GoTo( 10, 1 );
                    LCD_WriteText( "HPa" );

                    bmp.delay_ms( 1000 );
                }
            }
        }

        if( counter > 600 )
        {
            counter = 0;

            rslt = bmp280_set_power_mode( BMP280_NORMAL_MODE, &bmp );
            meas_dur = bmp280_compute_meas_time( &bmp );


            if ( rslt == BMP280_OK ) {

                bmp.delay_ms( meas_dur );

                rslt = bmp280_get_uncomp_data( &ucomp_data, &bmp );

                if ( rslt == BMP280_OK ) {

                    temp = bmp280_comp_temp_double( ucomp_data.uncomp_temp, &bmp );
                    pres = bmp280_comp_pres_double( ucomp_data.uncomp_press, &bmp ) / 100.0;

                    if( ( temp > 25.0 || temp < 20.0 ) && ( pres > 1030.0 || pres < 1000.0 ) )
                    {
                        //œwieci siê dioda czerwona
                        PORTD |= ( 1 << PD4 );
                        PORTD &= ~( 1 << PD0 );
                        PORTD &= ~( 1 << PD2 );
                    }
                    else if( ( temp > 25.0 || temp < 20.0 ) || ( pres > 1030.0 || pres < 1000.0 ) )
                    {
                        //œwieci siê dioda ¿ó³ta
                        PORTD |= ( 1 << PD2 );
                        PORTD &= ~( 1 << PD0 );
                        PORTD &= ~( 1 << PD4 );
                    }
                    else
                    {
                        //œwieci siê dioda zielona
                        PORTD |= ( 1 << PD0 );
                        PORTD &= ~( 1 << PD2 );
                        PORTD &= ~( 1 << PD4 );
                    }
                }
            }
        }
        else
            counter++;

        _delay_ms( 100 );
    }
}