//
//  read_parfile.c
//  mklatc
//
//  Created by Alexander Kompch on 09.06.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#include "read_parfile.h"

parameters* read_parfile(char* parfile)
{
    int line = 0;
    char *buffer = (char*)calloc(MAX_LEN, sizeof(char));
    parameters* pars = (parameters *)calloc(1,sizeof(parameters));
    FILE *FP;
    
    FP=fopen(parfile, "rt");
    if (FP == NULL) {
        printf("\n***   read_parfile:Could not open <%s>.", parfile);
        return NULL;
    }
    
    pars->parfile = (char *)calloc(strlen(parfile)+1, sizeof(char));
    strcpy(pars->parfile, parfile);
    
    while (fgets(buffer, MAX_LEN, FP) != NULL) {
        line ++;
        if (line == 1) {
            trim(buffer);
            pars->infile = (char *)calloc(strlen(buffer)+1, sizeof(char));
            strcpy(pars->infile, buffer);
        } else if (line == 2) {
            trim(buffer);
            pars->outfile = (char *)calloc(strlen(buffer)+1, sizeof(char));
            strcpy(pars->outfile, buffer);
        } else if (line == 3) sscanf(buffer, "%2s %d %d", pars->ch2atnesymb, &(pars->ch2atn), &(pars->chatn));
          else if (line == 4) sscanf(buffer, "%2s %d %lf %d", pars->dopesymb, &(pars->atnofdop), &(pars->dopc), &(pars->atn2sub));
    }
    fclose(FP);
    free(buffer);
    return pars;
}