/*
Adonay Pichardo, adonaypichardo@gmail.com

@file
c_template.c

@description
Template file for all C source files.

*/

// STANDARD LIBRARIES
#include <stdio.h>

// NON-STANDARD LIBRARIES
#include "adopic.h"

//MACROS
#define True  1
#define False 0

//GLOBAL VARIABLES
bool boolean_result = False;

//STRUCTURES
typedef struct program_arguments{
    unsigned int argument_total_count;
    char **arguments;
}PROGRAM_ARGUMENTS_t;

//PROTOTYPES
bool print_all_argv(PROGRAM_ARGUMENTS_t* given_program_arguments); // Short comment describing the function
PROGRAM_ARGUMENTS_t* init_PROGRAM_ARGUMENTS(void); // Initializes a PROGRAM_ARGUMENTS_t structure
void set_PROGRAM_ARGUMENTS(PROGRAM_ARGUMENTS_t* program_arguments, unsigned int argc, char** argv); // Uses argc and argv to set values for program_arguments
bool free_PROGRAM_ARGUMENTS(PROGRAM_ARGUMENTS_t** program_arguments); // Used to set all fields to NULL and free the memory for a PROGRAM_ARGUMENTS_t struct

int main(int argc, char** argv){
    printf("\n\n%s executing\n\n", argv[0]);

    //LOCAL MEMORY
    bool successful = False;

    //DYNAMIC MEMORY
    PROGRAM_ARGUMENTS_t* program_arguments;
    program_arguments = init_PROGRAM_ARGUMENTS();
    if(program_arguments != NULL){
        printf("Initialized a PROGRAM_ARGUMENTS_t structure.\n");
    }

    set_PROGRAM_ARGUMENTS(program_arguments, argc, argv);
    successful = print_all_argv(program_arguments);
    if(successful){
        printf("print_all_argv executed successfully.\n");
    }
    successful = False;

    successful = free_PROGRAM_ARGUMENTS(&program_arguments);
    if(program_arguments == NULL && successful == True){
        printf("Freed a PROGRAM_ARGUMENTS_t structure.\n");
    }

    printf("\n\n%s executed\n\n", argv[0]);
    return 0;
}//END main

//DEFINITIONS
bool print_all_argv(PROGRAM_ARGUMENTS_t* given_program_arguments){
/*
print_all_argv:
    Prints all arguments passed to program.

Input:  PROGRAM_ARGUMENTS_t* given_program_arguments:
            Contains all arguments passed to program.

Output: bool True:
            Returns 1 if execution was successful.
*/

    // LOCAL MEMORY
    unsigned int arg_counter;

    printf("Arguments passed to %s\n", given_program_arguments->arguments[0]);

    for(arg_counter = 1; arg_counter < given_program_arguments->argument_total_count; arg_counter++){
        printf("%s ", given_program_arguments->arguments[arg_counter]);
    }
    printf("\n");

    return True;
}

PROGRAM_ARGUMENTS_t* init_PROGRAM_ARGUMENTS(){
/*
init_PROGRAM_ARGUMENTS:
    Initializes a PROGRAM_ARGUMENTS_t structure.

Input:  void

Output: PROGRAM_ARGUMENTS_t* new_PROGRAM_ARGUMENTS:
            A malloced PROGRAM_ARGUMENTS_t structure.
*/
    //LOCAL MEMORY
    // None

    PROGRAM_ARGUMENTS_t* new_PROGRAM_ARGUMENTS = (PROGRAM_ARGUMENTS_t*) malloc(sizeof(PROGRAM_ARGUMENTS_t));

    return new_PROGRAM_ARGUMENTS;
}

void set_PROGRAM_ARGUMENTS(PROGRAM_ARGUMENTS_t* program_arguments, unsigned int argc, char** argv){
/*
set_PROGRAM_ARGUMENTS:
    Uses argc and argv to set the values in program_arguments

Input:  PROGRAM_ARGUMENTS_t* program_arguments:
            Will contain argc and argv values.
        unsigned int argc:
            Total number of arguments passed to the program.
        char** argv:
            The arguments passed to the program.

Output: PROGRAM_ARGUMENTS_t* new_PROGRAM_ARGUMENTS:
        A malloced PROGRAM_ARGUMENTS_t structure.
*/
    //LOCAL MEMORY
    // None

    program_arguments->argument_total_count = argc;
    program_arguments->arguments = argv;

    return;
}

bool free_PROGRAM_ARGUMENTS(PROGRAM_ARGUMENTS_t** program_arguments){
/*
set_PROGRAM_ARGUMENTS:
    Uses argc and argv to set the values in program_arguments

Input:  PROGRAM_ARGUMENTS_t* program_arguments:
            The PROGRAM_ARGUMENTS_t structure to delete.

Output: bool True:
            Returns 1 if execution was successful.
*/
    //LOCAL MEMORY
    // None

    (*program_arguments)->argument_total_count = 0;
    (*program_arguments)->arguments = 0;
    (*program_arguments) = NULL;
    free((*program_arguments));

    return True;
}
