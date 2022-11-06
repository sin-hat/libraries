/*****************************************************************************************************/
/* software name: probability_density_function.c                                                     */
/* date: 2022/11/6                                                                                   */
/* name: Sin.Hat                                                                                     */
/* overview:                                                                                         */
/*****************************************************************************************************/
/* include files */
#include "probability_density_function.h"

/* define */
#define math_PI (3.14159265358979323846) /* PI */

/* Uniform probability density function */
double uni_probability_density_func(double set_X, double set_Min, double set_Max)
{
    /* define variables */
    double ret_val;

    /* calclate probability density */
    if((set_Min <= set_X)
    && (set_Max >= set_X)
    && (set_Min < set_Max))
    {
        ret_val = 1.0 / (set_Max - set_Min);
    }
    else
    {
        ret_val = 0.0;
    }

    /* retun */
    return ret_val;
}

/* Exponential probability density function */
double exp_probability_density_func(double set_X, double set_Lambda)
{
    /* define variables */
    double ret_val;

    /* calclate probability density */
    ret_val = set_Lambda * (exp(-1.0 * set_Lambda * set_X));

    /* retun */
    return ret_val;
}

/* Gaussian probability density function */
double gaus_probability_density_func(double set_X, double set_Mu, double set_Variance)
{
    /* define variables */
    double ret_val;

    /* calclate probability density */
    ret_val = (1.0 / sqrt(2.0 * math_PI * set_Variance)) * (exp((-1.0 * pow((set_X - set_Mu), 2.0)) / (2.0 * set_Variance)));

    /* return */
    return ret_val;
}