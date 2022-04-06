/*
 * File:   stepMotor.c
 * Author: josewrpereira
 *
 * Created on 28 de Maio de 2021, 12:42
 */


#include <xc.h>
#include "delay.h"
#include "stepmotor.h"

char            passo;
unsigned char   motor[8] = {0x04, 0x06, 0x02, 0x03, 0x01, 0x09, 0x08, 0x0C};
unsigned int    ppr;
unsigned long   contador_passos;

#define BOBINAS(x)     PORTB &= 0xF0, PORTB |= ( x & 0x0F)


void stepmotor_init( unsigned int pulsosPorRevolucao )
{
    TRISCbits.TRISC4 = 0;   PORTCbits.RC4 = 0;
    TRISCbits.TRISC5 = 0;   PORTCbits.RC5 = 0;
    TRISCbits.TRISC6 = 0;   PORTCbits.RC6 = 0;
    TRISCbits.TRISC7 = 0;   PORTCbits.RC7 = 0;

    ppr = pulsosPorRevolucao;
    contador_passos = 0;
    passo = 0;
    BOBINAS( motor[passo] );
}


void stepmotor(unsigned long qtd_graus_passos,
               unsigned char unidade, 
               unsigned char sentido,
               unsigned char meio_passo,
               unsigned int t )
{
    char passo_sentido = 2; // Full Step, hor�rio
    
    if( unidade == DEGREES )
        contador_passos = (qtd_graus_passos * ppr) / 360;
    else
        contador_passos = qtd_graus_passos;
    
    if( meio_passo == HALF_STEP )
    {
        contador_passos *= 2;
        passo_sentido = 1;
    }
    
    if( sentido == CCW )
        passo_sentido *= -1;
    
    while( contador_passos )
    {
        passo = (passo + passo_sentido) % 8;
        BOBINAS( motor[passo] );
        --contador_passos;
        delay( t );
    }
}

