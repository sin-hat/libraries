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
    /* Set random seed */
    extern int Rand_set_seed(unsigned int rand_seed);

    /* Get rand max LCG refer to glibc (used by GCC)*/
    extern unsigned int Rand_get_MAX(void);

    /* Get random value(LCG) */
    extern unsigned int Rand_get_rand(void);

    /* Get rand max(lower bit truncated) */
    extern unsigned int Rand_get_MAX_truncated(void);

    /* Get random value(lower bit trauncated) */
    extern unsigned int Rand_get_rand_truncated(void);

    /* Get Uniform Random value [min, max] */
    extern double Rand_get_uni_rand(double min, double max);

    /* Get Exponential Random value(lambda) */
    extern double Rand_get_exp_rand(double lambda);

    /* Get Gaussian Random Value(Mu, Variance) */
    extern double Rand_get_gaus_rand(double set_Mu, double set_Variance);

#ifdef __cplusplus
}
#endif

#endif /* RAND_FUNCTION_H */