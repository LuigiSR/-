#include "config.h"
#include <xc.h>
#include "delay.h"
#include "lcd.h"
#include "teclado.h"
#include  "stepmotor.h"
void main( void )
{
    char tecla = 0; 
    lcd_init();
    teclado_init();
    stepmotor_init( 200 );
    while( 1 )
    {   
        tecla = teclado();
        if (tecla == '1')
        {
            lcd_print(0,0, "motor de passos" );
            stepmotor( 200, STEPS,  CW, FULL_STEP, 200 );
        }
        if (tecla == '2')
            lcd_print (0,0,"stepper motor");
    }
}
