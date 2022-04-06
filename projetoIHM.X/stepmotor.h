#ifndef STEPMOTOR_H
#define STEPMOTOR_H

// Unidade
#define DEGREES     0
#define STEPS       1
// Meio passo / Passo completo
#define FULL_STEP   0
#define HALF_STEP   1
// Sentido 
#define CW          0 
#define CCW         1


void stepmotor_init( unsigned int pulsosPorRevolucao );
void stepmotor(unsigned long qtd_graus_passos,
               unsigned char unidade, 
               unsigned char sentido,
               unsigned char meio_passo,
               unsigned int t );

#endif
