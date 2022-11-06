/*****************************************************************************************************/
/* software name: probability_density_function.h                                                     */
/* date: 2022/11/6                                                                                   */
/* name: Sin.Hat                                                                                     */
/* overview:                                                                                         */
/*****************************************************************************************************/
/* include guard */
#ifndef PROBABILITY_DENSITY_FUNCTION_H
#define PROBABILITY_DENSITY_FUNCTION_H

/* include files */
#include <math.h>

/* for C++ */
#ifdef __cplusplus
extern "C" 
{
#endif

    /* extern funtions */
    /* Uniform probability density function */
    extern double uni_probability_density_func(double set_X, double set_Min, double set_Max);

    /* Exponential probability density function */
    extern double exp_probability_density_func(double set_X, double set_Lambda);

    /* Gaussian probability density function */
    extern double gaus_probability_density_func(double set_X, double set_Mu, double set_Variance);

#ifdef __cplusplus
}
#endif

#endif /* PROBABILITY_DENSITY_FUNCTION_H */