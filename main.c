//
//  main.c
//  rancoo2
//
//  Created by Alexander Kompch on 11.10.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#include "main.h"

int main(int argc, const char * argv[]) {
    
    char *parfile = handle_cmdlargs(argc, argv);
    parameters *pars = read_parfile(parfile);
    if (pars == NULL) {
        printf("\n***   main: read_parfile failed! Will exit!");
        exit(EXIT_FAILURE);
    }
    
    print_pars(pars);
    
    coords *coo = read_newcoo(pars->infile);
    if (coo == NULL) {
        printf("\n***   main: read_oldcoo failed! Will exit!");
        exit(EXIT_FAILURE);
    }
    
    coords *subcoo = substitute(pars, coo);
    if (subcoo == NULL) {
        printf("\n***   main: substitute failed! Will exit!");
        exit(EXIT_FAILURE);
    }
    
//    if (write_oldcoo(pars->outfile1, subcoo) == EXIT_FAILURE) {
//        printf("\n***   main: write_coo failed! Will exit!");
//        exit(EXIT_FAILURE);
//    }
    
    char *filename = append_filename(pars->outfile, ".sub", ".pdb");
    write_pdb(filename, subcoo);
    free(filename);
    
//    if (write_pdb(pars->outfile, subcoo) == EXIT_FAILURE) {
//        printf("\n***   main: write_coo failed! Will exit!");
//        exit(EXIT_FAILURE);
//    }
    
    
    printf("\n");
    return EXIT_SUCCESS;
}
