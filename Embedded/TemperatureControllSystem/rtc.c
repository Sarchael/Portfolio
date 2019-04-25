#include "rtc.h"

#define CE PC0
#define IO PC2
#define SCLK PC1


void rtcInit( void )
{
    DDRC |= ( 1 << CE );
    DDRC |= ( 1 << SCLK );
    DDRC &= ~( 1 << IO );

    PORTC &= ~( 1 << CE );
    PORTC &= ~( 1 << SCLK );
}

void rtcSetTime( char hour, char min, char sec )
{
    rtcWrite( &hour, 0x84 );
    rtcWrite( &min, 0x82 );
    rtcWrite( &sec, 0x80 );
}
void rtcSetDate( char day, char month, char year, char wd )
{
    rtcWrite( &day, 0x86 );
    rtcWrite( &month, 0x88 );
    rtcWrite( &year, 0x8C );
    rtcWrite( &wd, 0x8A );
}

void rtcGetAll( struct rtc * clock )
{
    char data;

    rtcRead( &data, 0x81 );
    clock->sec = ( data & 0x0f ) + (( data & 0x70 ) >> 4 ) * 10;

    rtcRead( &data, 0x83 );
    clock->min = ( data & 0x0f ) + (( data & 0x70 ) >> 4 ) * 10;

    rtcRead( &data, 0x85 );
    clock->hour = ( data & 0x0f ) + (( data & 0x30 ) >> 4 ) * 10;

    rtcRead( &data, 0x87 );
    clock->day = ( data & 0x0f ) + (( data & 0x30 ) >> 4 ) * 10;

    rtcRead( &data, 0x89 );
    clock->month = ( data & 0x0f ) + (( data & 0x10 ) >> 4 ) * 10;

    rtcRead( &data, 0x8D );
    clock->year = ( data & 0x0f ) + (( data & 0xf0 ) >> 4 ) * 10;

    rtcRead( &data, 0x8B );

    switch ( data ) {
    case 0x01:
        clock->wd = "PON";
        break;
    case 0x02:
        clock->wd = "WTO";
        break;
    case 0x03:
        clock->wd = "SRO";
        break;
    case 0x04:
        clock->wd = "CZW";
        break;
    case 0x05:
        clock->wd = "PIA";
        break;
    case 0x06:
        clock->wd = "SOB";
        break;
    case 0x07:
        clock->wd = "NIE";
        break;
    default:
        clock->wd = "ERR";
        break;
    }
}

void rtcRead( char * data, char address )
{
    char temp;

    temp = address;

    PORTC |= ( 1 << CE );
    DDRC |= ( 1 << IO );

    for ( int i = 0; i < 8; i++ )
    {
        if ( temp & ( 1 << i ) )
            PORTC |= ( 1 << IO );
        else
            PORTC &= ~( 1 << IO );

        PORTC |= ( 1 << SCLK );
        PORTC &= ~( 1 << SCLK );
    }

    DDRC &= ~( 1 << IO );
    temp = 0;

    for ( int i = 0; i < 8; i++ )
    {
        if ( PINC & ( 1 << IO ) )
            temp |= ( 1 << i );
        else
            temp &= ~( 1 << i );

        PORTC |= ( 1 << SCLK );
        PORTC &= ~( 1 << SCLK );
    }

    *data = temp;

    PORTC &= ~( 1 << CE );
    //DDRC &= ~( 1 << IO );
    //PORTC &= ~( 1 << IO );
}

void rtcWrite( char * data, char address )
{
    char temp;

    temp = address;

    PORTC |= ( 1 << CE );
    DDRC |= ( 1 << IO );

    for ( int i = 0; i < 8; i++ )
    {
        if ( temp & ( 1 << i ) )
            PORTC |= ( 1 << IO );
        else
            PORTC &= ~( 1 << IO );

        PORTC |= ( 1 << SCLK );
        PORTC &= ~( 1 << SCLK );
    }

    temp = *data;

    for ( int i = 0; i < 8; i++ )
    {
        if ( temp & ( 1 << i ) )
            PORTC |= ( 1 << IO );
        else
            PORTC &= ~( 1 << IO );

        PORTC |= ( 1 << SCLK );
        PORTC &= ~( 1 << SCLK );
    }

    PORTC &= ~( 1 << CE );
    //DDRC &= ~( 1 << IO );
    //PORTC &= ~( 1 << IO );
}