//
//  rand_at.c
//  rancoo2
//
//  Created by Alexander Kompch on 11.10.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#include "rand_at.h"

//intitialize random number generator
gsl_rng* init_rand_at(void) {

//    const gsl_rng_type * T;
    gsl_rng *r;
    //seed with time
    long int s=time(NULL);
//    gsl_rng_env_setup();
//    T = gsl_rng_default;
    //use ranlxd1 as randon number generator
    r = gsl_rng_alloc(gsl_rng_ranlxd1);
    //set seed value
    gsl_rng_set(r, s);
    printf ("\nseed = time = %lu", s);
    printf ("\ngenerator type: %s", gsl_rng_name (r));
//    printf ("\nseed = %lu", gsl_rng_default_seed);
    printf("\nmin value = %lu", gsl_rng_min(r));
    printf("\nmax value = %lu", gsl_rng_max(r));
    
    return r;
}

//returns an integer random number based on the RNG initialized with init_rand_at(void)
//in the interval [0;max]
long int rand_at(gsl_rng* r, long int max) {
    long int rnd = 0;
    double u = 0.0;

    u = gsl_rng_uniform(r);
    u = (double)max * u;
    rnd = lrint(u);
    return rnd;
}