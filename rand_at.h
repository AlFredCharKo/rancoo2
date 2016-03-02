//
//  rand_at.h
//  rancoo2
//
//  Created by Alexander Kompch on 11.10.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#ifndef __rancoo2__rand_at__
#define __rancoo2__rand_at__

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <gsl/gsl_rng.h>


gsl_rng* init_rand_at(void);

long int rand_at(gsl_rng* r, long int max);

#endif /* defined(__rancoo2__rand_at__) */
