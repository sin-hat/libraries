/*****************************************************************************************************/
/* software name: rand_function.c                                                                    */
/* date: 2022/11/5                                                                                   */
/* name: Sin.Hat                                                                                     */
/* overview:                                                                                         */
/*****************************************************************************************************/

/* include files */
#include "rand_function.h"

/* define */
#define rand_A (1103515245)              /* A refer to glibc (used by GCC) */
#define rand_B (12345)                   /* B refer to glibc (used by GCC) */
#define rand_M (2147483648)              /* M refer to glibc (used by GCC) */
#define math_PI (3.14159265358979323846) /* PI */
#define truncation_bit (3)               /* bit truncation */
#define Error_state (-1)                 /* Error state */
#define Normal_state (0)                 /* Normal state */

/* static variables */
static unsigned int rand_x = 123;
static unsigned int output_counter = 0;

/* Linear congruential generator(LCG): X_n+1 = (A * X_n + B) % M */
/* set seed(0 - (rand_M - 1)) */
int Rand_set_seed(unsigned int rand_seed)
{
    /* define variables */
    int ret_val;

    /* init variables */
    ret_val = Error_state;

    /* set seed */
    rand_x = rand_seed;

    /* set OK */
    ret_val = Normal_state;

    /* return */
    return ret_val;
}

/* get rand max(rand_M - 1) */
unsigned int Rand_get_MAX(void)
{
    return (rand_M - 1);
}

/* get rand(0 - (rand_M - 1))) */
unsigned int Rand_get_rand(void)
{
    /* define variables */

    /* init variables */

    /* get rand: X_n+1 = (A * X_n + B) % M */
    rand_x = (rand_A * rand_x + rand_B) % rand_M;

    /* return rand value */
    return rand_x;
}

/* get rand max truncated((rand_M - 1) >> truncation_bit) */
unsigned int Rand_get_MAX_truncated(void)
{
    return ((rand_M - 1) >> truncation_bit);
}

/* get rand(0 - ((rand_M - 1) >> truncation_bit))) */
unsigned int Rand_get_rand_truncated(void)
{
    /* define variables */

    /* init variables */

    /* get rand: X_n+1 = (A * X_n + B) % M */
    rand_x = (rand_A * rand_x + rand_B) % rand_M;

    /* return rand value */
    return (rand_x >> truncation_bit);
}

/* Get Uniform Random Value */
double Rand_get_uni_rand(double min, double max)
{
    /* define variables */
    double temp_uni_rand, ret_val;

    /* get uniform distribution([0, 1]) */
   temp_uni_rand = (double)Rand_get_rand_truncated() / (double)Rand_get_MAX_truncated();

   /* transform(from [0, 1] to [min, max]) */
   ret_val = (temp_uni_rand * (max - min)) + min;

   /* max, min value check */
   if(ret_val > max)
   {
       ret_val = max;
   }
   else if(ret_val < min)
   {
       ret_val = min;
   }
   else
   {
       /* no action */
   } 

   /* return */
   return ret_val;
}

/* Get Exponential Random Value */
double Rand_get_exp_rand(double lambda)
{
    /* define variables */
    double ret_val;

    /* get exponential random value -log(U[0, 1])/lambda  */
    ret_val = (-1.0 * log(Rand_get_uni_rand(0.0, 1.0))) / lambda;

    /* return */
    return ret_val;
}

/* Get Gaussian Random Value(Box-Muller's method) */
double Rand_get_gaus_rand(double set_Mu, double set_Variance)
{
    /* define variables */
    double ret_val;
    double rand_U1, rand_U2;
    double temp_gaus_val1, temp_gaus_val2;
    static double output_gaus_val1, output_gaus_val2;

    /* init variables */
    ret_val = 0.0;
    
    /* check counter(You can get two Gaussian values at once.) */
    if(output_counter % 2 == 0)
    {
        /* get uniform distribution([0, 1]) */
        rand_U1 = Rand_get_uni_rand(0.0, 1.0);
        rand_U2 = Rand_get_uni_rand(0.0, 1.0);

        /* calculate gaussian value */
        temp_gaus_val1 = (sqrt(-2.0 * log(rand_U1))) * (cos(2.0 * math_PI * rand_U2));
        temp_gaus_val2 = (sqrt(-2.0 * log(rand_U1))) * (sin(2.0 * math_PI * rand_U2));

        /* transform (Mu, Sigma^2) */
        output_gaus_val1 = (set_Variance * temp_gaus_val1) + set_Mu;
        output_gaus_val2 = (set_Variance * temp_gaus_val2) + set_Mu;

        /* set output value */
        ret_val = output_gaus_val1;
    }
    else
    {
        /* set output value */
        ret_val = output_gaus_val2;
    }

    /* update the counter(0, 99) */
    if(output_counter < (100 - 1))
    {
        output_counter++;
    }
    else
    {
        output_counter = 0;
    }

    /* return */
    return ret_val;
}
