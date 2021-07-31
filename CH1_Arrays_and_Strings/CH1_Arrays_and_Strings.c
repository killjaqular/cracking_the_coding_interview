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
#include <unistd.h> // Used for sleep()

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
void print_unique_chars(char* string);

int main(int argc, char** argv){
    printf("\n\n%s executing\n\n", argv[0]);

    // LOCAL MEMORY
    bool successful = False;

    // DYNAMIC MEMORY
    // None

    ////////////////////////////////////////////////////////////////
    // 1.1 Is Unique
    printf("\n1.1: Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?\n");
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
            file_reader = getc(file_stream);
            as_char[0] = (char)file_reader;
            buffer[buffer_insert] = file_reader;
            buffer_insert++;
            if((strcmp(as_char, delimiter) == 0)){
                // Process buffer
                buffer[buffer_insert] = 0;
                print_unique_chars(buffer);
                buffer_insert = 0; // Reset the buffer_insert to start writing to the buffer from index 0
            }
        }
    }
    fclose(file_stream);



    printf("\n\n%s executed\n\n", argv[0]);
    return 0;
}// END main

// DEFINITIONS
void print_unique_chars(char* string){
/*
void print_unique_chars: O(n^2)
    Prints all unique chars in string by comparing each char with all others and printing out char if no duplicate was
    found.

Input:
    char* string:
        The string to read for unique chars.

Output: None

Example Usage:

char buffer[MAX_BUFFER_SIZE] = "\0";
// Write something into buffer
print_unique_chars(buffer);

*/

    // LOCAL MEMORY
    bool found_duplicate = False;  // Assume we have not found a duplicate
    char* string_reader  = string; // Begin at the first character
    char* char_reader    = string; // Begin at the first character

    printf("%s\n", string);
    printf("\nUnique characters: [");
    while(strcmp(string_reader, "\0") != 0){ // While we have not reached the end of the string,

        while(strcmp(char_reader, "\0") != 0){
            if(string_reader == char_reader) char_reader++; // Avoid comparing the same chars

            if(*string_reader == *char_reader){
                found_duplicate = True; // Set flag
                break;                  // Stop searching
            }
            char_reader++;
        }

        if(found_duplicate == False){
            printf("%c", *string_reader);
        }

        string_reader++;          // Move to the next character in string to interogate
        char_reader     = string; // Reset the pointer to the start
        found_duplicate = False;  // Reset flag
    }

    printf("]\n");

    return;
}
