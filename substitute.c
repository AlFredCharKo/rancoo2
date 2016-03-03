//
//  substitute.c
//  rancoo2
//
//  Created by Alexander Kompch on 11.10.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#include "substitute.h"


coords* substitute(parameters *pars, coords *coo) {
    int count1=0, count2=0;
    long int m = 0;
    double frac = -1.0;
    FILE *FP;
    gsl_rng *r = init_rand_at();
    
    coords *subcoo = init_coords(coo->nat, coo->boxL);
    cp_coords(coo, subcoo);
    
    FP=fopen("sub_stats.dat", "wt");
    if (FP == NULL) {
        printf("\n***   substitute:Could not open <sub_stats.dat>.");
        return NULL;
    }
    fprintf(FP,"some info about substitute routine");
    fprintf(FP,"\nnat = %6d", subcoo->nat);
    fprintf(FP,"\ncount1 = %d", count1);
    
    
//do random substitution loop
    count2 = 0;
    frac = 0.0;
    while (frac < pars->dopc) {
        m = rand_at(r, (long int)subcoo->nat);
        if (m >= subcoo->nat) {
            continue;
        }
        if (subcoo->at[m]->atn == pars->atn2sub) {
            subcoo->at[m]->atn = pars->atnofdop;
            strcpy(subcoo->at[m]->esymb, pars->dopesymb);
            count2++;
        }
        frac = (double)count2/(double)subcoo->nat;
        fprintf(FP,"\nm = %6ld\tatn = %2d\tcount2 = %6d\tfrac = %9.6f",m, coo->at[m]->atn, count2, frac);
    }
    printf("\nnumber of atoms substituted %d corresponds to a fraction of %9.6f", count2, frac);
    fprintf(FP,"\n\nnumber of atoms substituted %d corresponds to a fraction of %9.6f", count2, frac);
    fclose(FP);
    gsl_rng_free(r);
    return subcoo;
}