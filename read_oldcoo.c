//
//  read_oldcoo.c
//  rancoo2
//
//  Created by Alexander Kompch on 11.10.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#include "read_oldcoo.h"


coords* read_oldcoo(char *filename) {
    FILE *FP;
    vec boxL = {.x=-1.0, .y=-1.0, .z=-1.0};
    char *buffer = (char*)calloc(MAX_LEN, sizeof(char));
    int i=0;
    
    printf("\nread_oldcoo: filename = %s",filename);
    
    FP=fopen(filename, "rt");
    if (FP == NULL) {
        printf("\n***   read_oldcoo:Could not open <%s>.", filename);
        return NULL;
    }
    //read all lines in files; number of lines = total number of atoms
    while (fgets(buffer, MAX_LEN, FP) != NULL) {
        i++;
    }
    
    coords *coo = init_coords(i, boxL);
    if (coo == NULL) {
        printf("\n***   read_oldcoo: coo could be initialized");
    }
    
    rewind(FP);
    for(i=0;i<coo->nat;i++) {
        fgets(buffer, MAX_LEN, FP);
        sscanf(buffer, "%d %d %lf %lf %lf",&coo->at[i]->n, &coo->at[i]->atn, &coo->at[i]->pnt.x, &coo->at[i]->pnt.y, &coo->at[i]->pnt.z);
        //esymb cannot be read or determined in oldcoo
        strcpy(coo->at[i]->esymb,"XX");
    }
    fclose(FP);
    return coo;
}