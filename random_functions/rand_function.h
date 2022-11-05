/*****************************************************************************************************/
/* software name: rand_function.h                                                                    */
/* date: 2022/11/5                                                                                   */
/* name: Sin.Hat                                                                                     */
/* overview:                                                                                         */
/*****************************************************************************************************/
/* include guard */
#ifndef RAND_FUNCTION_H
#define RAND_FUNCTION_H

/* include files */
#include <math.h>

/* for C++ */
#ifdef __cplusplus
extern "C" 
{
#endif

    /* extern funtions */
    /* Get rand max */
    extern unsigned int Rand_get_MAX(void);

    /* Set random seed */
    extern int Rand_set_seed(unsigned int rand_seed);

    /* Get random value */
    extern unsigned int Rand_get_rand(void);

    /* Get Gaussian Random Value */
    extern double Rand_get_gaus_rand(double set_Mu, double set_Variance);

#ifdef __cplusplus
}
#endif

#endif /* RAND_FUNCTION_H */