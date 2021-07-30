/*
Adonay Pichardo, adonaypichardo@gmail.com

@file
CH1_Arrays_and_Strings.c

@description
Cracking the Coding Interview:
Chapter 1 Problems

1.1:
    Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you cannot use
    additional data structures?

1.2:


1.3:


1.4:


1.5:


1.6:


1.7:


1.8:


1.9:
    

*/

// STANDARD LIBRARIES
#include <stdio.h>

// NON-STANDARD LIBRARIES
#include "..\adopic.h"

// MACROS
#define True  1
#define False 0
#define MAX_BUFFER_SIZE 512

// GLOBAL VARIABLES
// None

// STRUCTURES
// None

// PROTOTYPES
void print_unique_chars(char string[]);

int main(int argc, char** argv){
    printf("\n\n%s executing\n\n", argv[0]);

    // LOCAL MEMORY
    bool successful = False;

    // DYNAMIC MEMORY
    // None

    ////////////////////////////////////////////////////////////////
    // 1.1 Is Unique
    ////////////////////////////////////////////////////////////////
    // Open input file for test
    FILE* file_stream = NULL;
    int file_reader = 0;
    int char_reader = 0;
    char delimiter[2] = ".\0";
    char as_char[2] = "\0";
    char buffer[MAX_BUFFER_SIZE] = "\0";
    unsigned int buffer_insert = 0;

    file_stream = verify_file_stream_pointer(argv[1]);
    if(file_stream != NULL) successful = True;

    if(successful){
        putchar('\n');
        while(file_reader != EOF){
            buffer_insert = 0; // Reset the buffer_insert to start writing to the buffer from index 0
            file_reader = getc(file_stream);
            as_char[0] = (char)file_reader;
            putchar(file_reader);
            buffer[buffer_insert] = file_reader;
            buffer_insert++;
            if((strcmp(as_char, delimiter) == 0)){
                // Process buffer
                print_unique_chars(buffer);
                printf("print_unique_chars executed.\n");
            }
        }
    }
    fclose(file_stream);



    printf("\n\n%s executed\n\n", argv[0]);
    return 0;
}// END main

// DEFINITIONS
void print_unique_chars(char string[]){
/*
void print_unique_chars: O(n^2)
    Prints all unique chars in string by comparing each char with all others and printing out char if no duplicate was
    found.

Input:
    char string[]:
        The string to read for unique chars.

Output: None

Example Usage:


*/

    // LOCAL MEMORY
    bool found_duplicate = False; // Assume we have not found a duplicate
    char* string_reader  = &string[0];
    char* char_reader    = string_reader;

    putchar('\n');
    while(strcmp(string_reader, "\0") != 0){
        char_reader++; // Advance one char forward of string_reader to avoid comparing to itself

        while(strcmp(char_reader, "\0") != 0){
            if(string_reader == char_reader){
                found_duplicate = True; // Set flag
                break; // Stop search
            }
            char_reader++; // Advance to the next char to compare
        }
        if(found_duplicate == True) printf("%c, ", char_reader); // Print out the unique char

        found_duplicate = False; // Reset the flag
        char_reader = string_reader; // Reset char_reader
        string_reader++; // Advance to new char to interogate
    }
}
