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
#include <ctype.h>


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
bool all_unique_chars(char* string);

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
    FILE* file_stream            = NULL;  // The input file
    int file_reader              = 0;     // Steps through the input file
    char delimiter[2]            = ".\0"; // Used to splice the input file
    char as_char[2]              = "\0";  // Used to cast the read int as a char for comparison
    char buffer[MAX_BUFFER_SIZE] = "\0";  // The buffer used to read in the input file
    unsigned int buffer_insert   = 0;     // Used to step through the buffer
    bool all_unique              = False; // Used to flag if all chars in a string are unique
    bool new_line                = False; // Used to flag if one or more newlines were encountered reading file_stream

    file_stream = verify_file_stream_pointer(argv[1]); // Open the input file
    if(file_stream != NULL) successful = True;         // Verify the file stream is valid

    if(successful){
        putchar('\n');
        while(file_reader != EOF){                 // If we haven't reached the end of the file,
            file_reader = getc(file_stream);       // Get a char from the stream
            as_char[0] = (char)file_reader;        // Cast it as a char to use as a comparison with another char

            // Ignore newlines
            new_line = False;                      // Reset the flag
            while(strcmp(as_char, "\n") == 0){     // While we read newlines,
                file_reader = getc(file_stream);   // Get a char from the stream
                as_char[0] = (char)file_reader;    // Cast it as a char to use as a comparison with another char
                new_line = True;
            }

            if((new_line == True) && (buffer_insert != 0)){ // If we read in newlines, one or more,
                strcpy(&buffer[buffer_insert], " ");        // Insert a single space regardless of how many newlines were consumed
                buffer_insert++;                            // Advance the inserter
            }
            buffer[buffer_insert] = file_reader;            // Write the new char into the buffer
            buffer_insert++;                                // Advance the inserter

            if((strcmp(as_char, delimiter) == 0)){ // If we read in a '.',
                // Process buffer
                buffer[buffer_insert] = '\0'; // Manually insert the null char at the end of the string
                all_unique = all_unique_chars(buffer);
                if(all_unique == True){
                    printf("All unique characters.\n\n");
                }else{
                    printf("Not unique characters.\n\n");
                }
                all_unique = False; // Reset flag
                buffer_insert = 0;  // Reset the buffer_insert to start writing to the buffer from index 0
            }
        }
    }
    fclose(file_stream);



    printf("\n\n%s executed\n\n", argv[0]);
    return 0;
}// END main

// DEFINITIONS
bool all_unique_chars(char* string){
/*
void all_unique_chars: O(n^2)
    Prints all unique chars in string by comparing each char with all others and printing out char if no duplicate was
    found.

Input:
    char* string:
        The string to read for unique chars.

Output: None

Example Usage:

char buffer[MAX_BUFFER_SIZE] = "\0";
// Write something into buffer
all_unique_chars(buffer);

*/

    // LOCAL MEMORY
    bool  all_unique    = True;   // Assume we have not found a duplicate
    char* string_reader = string; // Begin at the first character
    char* char_reader   = string; // Begin at the first character

    printf("%s\n", string);

    while(strcmp(string_reader, "\0") != 0){   // While we have not reached the end of the string,
        if(isspace(*string_reader)){   // If we found a space char
            string_reader++;                   // Advance pointer
            continue;                          // Restart search
        }
        while(strcmp(char_reader, "\0") != 0){                         // While we have not reached the end of the string,
            if(strcmp(string_reader, char_reader) == 0) char_reader++; // Avoid comparing equal pointers
            if(strcmp(char_reader, "\0") == 0) break;                  // We have reached the end of the string, stop
            if(isspace(*char_reader)){                                 // If we found a space char
                char_reader++;                                         // Advance pointer
                continue;                                              // Restart search
            }

            if(*string_reader == *char_reader){ // If we found matching chars
                all_unique = False;             // Flip flag
                break;                          // On the first duplicate found, stop search
            }

            char_reader++;
        }

        if(all_unique == False) break; // On the first duplicate found, stop search
        string_reader++;               // Move to the next character in string to interogate
        char_reader = string;          // Reset char_reader to the beginning of string
    }

    return all_unique;
}
