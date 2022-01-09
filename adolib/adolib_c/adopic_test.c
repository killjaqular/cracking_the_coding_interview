/*
Adonay Pichardo, adonaypichardo@gmail.com

@file
adopic_test.c

@description
A program to test adopic library structures and functions.

*/

// STANDARD LIBRARIES
#include <stdio.h>

// NON-STANDARD LIBRARIES
#include "adopic.h"

// MACROS
#define True  1
#define False 0

// GLOBAL VARIABLES
// None

// STRUCTURES
// None

// PROTOTYPES
// None

int main(int argc, char** argv){
    printf("\n\n%s executing\n\n", argv[0]);

    // LOCAL MEMORY
    bool successful = False;

    ////////////////////////////////////////////////////////////////
    // Test verify_argc
    ////////////////////////////////////////////////////////////////
    printf("verify_argc(%d, %s)\n", argc, argv[1]);
    successful = verify_argc(argc, argv);
    printf("verify_argc returned %d\n", successful);
    successful = False;

    ////////////////////////////////////////////////////////////////
    // Test verify_argv
    ////////////////////////////////////////////////////////////////
    printf("verify_argv(%s)\n", argv[1]);
    successful = verify_argv(argv);
    printf("verify_argv returned %d\n", successful);
    successful = False;

    ////////////////////////////////////////////////////////////////
    // Test verify_file_stream_pointer
    ////////////////////////////////////////////////////////////////
    FILE* file_stream = NULL;
    printf("verify_file_stream_pointer(%s)\n", argv[1]);
    file_stream = verify_file_stream_pointer(argv[1]);
    if(file_stream != NULL) successful = True;
    int reader;
    char buffer[256] = "\0";
    unsigned int counter = 0;
    if(successful){
        while((reader = getc(file_stream)) != EOF){
            putchar(reader);
            buffer[counter] = reader;
            counter++;
        }
    }
    fclose(file_stream);
    printf("buffer = %s\n", buffer);
    printf("verify_file_stream_pointer returned %d\n", successful);
    successful = False;

    ////////////////////////////////////////////////////////////////
    // Test length_of_string
    ////////////////////////////////////////////////////////////////
    printf("length_of_string(%s)\n", buffer);
    unsigned int size_of_string = length_of_string(buffer);
    printf("buffer after length_of_string = %s\n", buffer);
    printf("length_of_string returned %d\n", size_of_string);

    ////////////////////////////////////////////////////////////////
    // Test insert_null_char
    ////////////////////////////////////////////////////////////////
    printf("insert_null_char(%s)\n", buffer);
    char *new_string;
    new_string = insert_null_char(buffer);
    printf("buffer after insert_null_char = %s\n", buffer);
    printf("new_string after insert_null_char = %s\n", new_string);

    ////////////////////////////////////////////////////////////////
    // Test string_to_uppercase
    ////////////////////////////////////////////////////////////////
    printf("string_to_uppercase(%s)\n", new_string);
    char *uppercase;
    uppercase = string_to_uppercase(new_string);
    printf("buffer after string_to_uppercase = %s\n", buffer);
    printf("uppercase after string_to_uppercase = %s\n", uppercase);

    ////////////////////////////////////////////////////////////////
    // Test string_to_lowercase
    ////////////////////////////////////////////////////////////////
    printf("string_to_lowercase(%s)\n", new_string);
    char *lowercase;
    lowercase = string_to_lowercase(new_string);
    printf("buffer after string_to_lowercase = %s\n", buffer);
    printf("lowercase after string_to_lowercase = %s\n", lowercase);

    ////////////////////////////////////////////////////////////////
    // Test copy_first_word
    ////////////////////////////////////////////////////////////////
    printf("copy_first_word(%s)\n", new_string);
    char *first_word;
    first_word = copy_first_word(new_string);
    printf("buffer after copy_first_word = %s\n", buffer);
    printf("first_word after copy_first_word = %s\n", first_word);

    printf("\n\n%s executed\n\n", argv[0]);
    return 0;
}// END main

// DEFINITIONS
// None
