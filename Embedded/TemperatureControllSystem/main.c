                    /*
 * main.c    ATmega16A    F_CPU = 8000000 Hz
 *
 * Created on: 15.02.2019
 *     Author: admin
*/
#include <avr/io.h>
#include <util/delay.h>
#include "rtc.h"
#include "HD44780.h"
#include "dht.h"

void initButtons() {

    DDRA &= ~( 1 << PA0 ); //Ustawienie PA0 jako pin wejœciowy
    PORTA |= ( 1 << PA0 ); //Pin od przycisku na wejœciu ma 1

    DDRA &= ~( 1 << PA1 ); //Ustawienie PA1 jako pin wejœciowy
    PORTA |= ( 1 << PA1 ); //Pin od przycisku na wejœciu ma 1

    DDRC &= ~( 1 << PC6 ); //Ustawienie PC6 jako pin wejœciowy
    PORTC |= ( 1 << PC6 ); //Pin od przycisku na wejœciu ma 1
}

void initDiodes(){
    DDRC |= ( 1 << PC7 ); //DIODA 1
    PORTC &= ~( 1 << PC7 ); //ZGASZONA

    DDRD |= ( 1 << PD7 ); //DIODA 2
    PORTD &= ~( 1 << PD7 ); //ZGASZONA

    DDRD |= ( 1 << PD4 ); //DIODA 3
    PORTD &= ~( 1 << PD4 ); //ZGASZONA
}

int main( void ) {

    char outputString1[16];
    char outputString2[16];
    int viewNumber = 0;
    int sensorNumber = 0;
    int isPressed = 0;
    int okSensor;
    int8_t temp1;
    int8_t temp2;
    int8_t temp3;
    int8_t hum1;
    int8_t hum2;
    int8_t hum3;
    int flag1 = 0;
    int flag2 = 0;
    int flag3 = 0;
    int errorTemp1;
    int errorTemp2;
    int errorTemp3;
    struct rtc errorTime1;
    struct rtc errorTime2;
    struct rtc errorTime3;
    int timer = 0;
    int checkTemperature = 1;

    LCD_Initalize();
    rtcInit();
    initButtons();
    initDiodes();

    while(1) {

        if ( !( PINA & ( 1 << PA1 ) ) ){ //jeœli pierwszy przysisk jest wciœniêty
            if ( isPressed == 0 ){
                sensorNumber++;
                isPressed = 1;
                if(sensorNumber > 2)
                    sensorNumber = 0;
            }
        }
        else if ( !( PINA & ( 1 << PA0 ) ) ){ //jeœli drugi przysisk jest wciœniêty
             if ( isPressed == 0 ){
                 viewNumber++;
                 isPressed = 1;
                 if(viewNumber > 1)
                     viewNumber = 0;
             }
        }
        else
            isPressed = 0;

        if(checkTemperature == 1){
            dht_gettemperaturehumidity(&temp1, &hum1, 0);
            dht_gettemperaturehumidity(&temp2, &hum2, 1);
            dht_gettemperaturehumidity(&temp3, &hum3, 2);

            if(temp1 >= 28){
                rtcGetAll( &errorTime1 );
                errorTemp1 = temp1;
                flag1 = 1;
                PORTC |= ( 1 << PC7 );
                _delay_ms(10);
            }
            if(temp2 >= 28){
                rtcGetAll( &errorTime2 );
                errorTemp2 = temp2;
                flag2 = 1;
                PORTD |= ( 1 << PD7 );
                _delay_ms(10);
            }
            if(temp3 >= 28){
                rtcGetAll( &errorTime3 );
                errorTemp3 = temp3;
                flag3 = 1;
                PORTD |= ( 1 << PD4 );
                _delay_ms(10);
            }
            checkTemperature = 0;
            timer = 0;
        }

        if(viewNumber == 0){
            sprintf( outputString1, "SENSOR %01i", sensorNumber+1 );
            if(sensorNumber == 0)
                sprintf( outputString2, "T: %02i*C H: %02i%%", temp1, hum1 );
            else if(sensorNumber == 1)
                sprintf( outputString2, "T: %02i*C H: %02i%%", temp2, hum2 );
            else if(sensorNumber == 2)
                sprintf( outputString2, "T: %02i*C H: %02i%%", temp3, hum3 );
            LCD_Clear();
            LCD_GoTo( 0, 0 );
            LCD_WriteText(outputString1);
            LCD_GoTo( 0, 1 );
            LCD_WriteText(outputString2);
            _delay_ms(100);
            timer++;
            if(timer > 100)
                checkTemperature = 1;
        }
        else {
            if(sensorNumber == 0){
                if(flag1 == 1){
                    sprintf( outputString1, "SENSOR 1 T: %02i*C", errorTemp1 );
                    sprintf( outputString2, " %02i:%02i:%02i %02i.%02i", errorTime1.hour, errorTime1.min, errorTime1.sec, errorTime1.day, errorTime1.month );

                    if ( !( PINC & ( 1 << PC6 ) ) ){ //jeœli trzeci przysisk jest wciœniêty
                        flag1 = 0;
                        PORTC &= ~( 1 << PC7 );
                    }
                }
                else {
                    sprintf( outputString1, "SENSOR 1");
                    sprintf( outputString2, "brak ostrzezen");
                }
            }
            else if(sensorNumber == 1){
                if(flag2 == 1){
                    sprintf( outputString1, "SENSOR 2 T: %02i*C", errorTemp2 );
                    sprintf( outputString2, " %02i:%02i:%02i %02i.%02i", errorTime2.hour, errorTime2.min, errorTime2.sec, errorTime2.day, errorTime2.month );

                    if ( !( PINC & ( 1 << PC6 ) ) ){ //jeœli trzeci przysisk jest wciœniêty
                        flag2 = 0;
                        PORTD &= ~( 1 << PD7 );
                    }
                }
                else {
                    sprintf( outputString1, "SENSOR 2" );
                    sprintf( outputString2, "brak ostrzezen");
                }
            }
            else if(sensorNumber == 2){
                if(flag3 == 1){
                    sprintf( outputString1, "SENSOR 3 T: %02i*C", errorTemp3 );
                    sprintf( outputString2, " %02i:%02i:%02i %02i.%02i", errorTime3.hour, errorTime3.min, errorTime3.sec, errorTime3.day, errorTime3.month );

                    if ( !( PINC & ( 1 << PC6 ) ) ){ //jeœli trzeci przysisk jest wciœniêty
                        flag3 = 0;
                        PORTD &= ~( 1 << PD4 );
                    }
                }
                else {
                    sprintf( outputString1, "SENSOR 3" );
                    sprintf( outputString2, "brak ostrzezen");
                }
            }
            LCD_Clear();
            LCD_GoTo( 0, 0 );
            LCD_WriteText(outputString1);
            LCD_GoTo( 0, 1 );
            LCD_WriteText(outputString2);
            _delay_ms(100);
            timer++;
            if(timer > 100)
                checkTemperature = 1;
        }
    }
}