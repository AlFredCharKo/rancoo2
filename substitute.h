//
//  substitute.h
//  rancoo2
//
//  Created by Alexander Kompch on 11.10.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#ifndef __rancoo2__substitute__
#define __rancoo2__substitute__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gsl/gsl_rng.h>
#include "defs.h"
#include "structs.h"
#include "coords_helper.h"
#include "rand_at.h"

coords* substitute(parameters *pars, coords *coo);

#endif /* defined(__rancoo2__substitute__) */
