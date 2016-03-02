//
//  print_pars.c
//  mklatc
//
//  Created by Alexander Kompch on 09.06.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#include "print_pars.h"

int print_pars(parameters *pars)
{    
    printf("\n***   IN print_pars   ***\n");
    
    printf("\nparameters read from <%s>", pars->parfile);
    printf("\ninput file <%s>", pars->infile);
    printf("\noutput file: <%s>", pars->outfile);
    printf("\nswitch all of atomic number %d to atomic number %d (%2s)", pars->chatn, pars->ch2atn, pars->ch2atnesymb);
    printf("\nsubstitute %7.4f of atomic number %d by atomic number %d (%2s)", pars->dopc, pars->atn2sub, pars->atnofdop, pars->dopesymb);
    printf("\n");
    return EXIT_SUCCESS;
}