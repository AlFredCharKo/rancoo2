//
//  pars_helper.c
//  MkHexLat
//
//  Created by Alexander Kompch on 01.03.16.
//  Copyright (c) 2016 Alexander Kompch. All rights reserved.
//

#include "pars_helper.h"

int pars_free(parameters *given) {
    free(given->infile);
    free(given->outfile);
    free(given->parfile);
    free(given);
    return EXIT_SUCCESS;
}