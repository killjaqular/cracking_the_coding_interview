/*
Adonay Pichardo, adonaypichardo@gmail.com
github.com/killjaqular

@description
Cracking the Coding Interview:
Chapter 1 Problems

1.1 Is Unique:
    Implement an algorithm to determine if a string has all unique characters. What if
    you cannot use additional data structures?
*/

#include <stdio.h> // Standard input and output streams
#include <ctype.h> // bool type

#include "../../adolib/adolib_c/adopic.h"

#define True  1
#define False 0
#define MAX_BUFFER_SIZE 128

bool isUnique(char* string); // All chars unique

int main(int argc, char** argv){
    printf("\n\n%s executing\n\n", argv[0]);

    printf("///////////////////////////\n");
    printf("// 1.1 Is Unique //////////\n");
    printf("///////////////////////////\n");

    bool isStreamAtEOF           = False;
    char buffer[MAX_BUFFER_SIZE] = {0};
    FILE* fileStream = fopen(argv[1], "r");

    if(fileStream == NULL){
        printf("\n %s WAS NOT FOUND.\n", argv[1]);
        exit(0);
    }

    while(isStreamAtEOF != True){
        isStreamAtEOF = write_to_buffer(fileStream, buffer, MAX_BUFFER_SIZE, NULL, "\n");

        if(isStreamAtEOF == True) break;

        if(isUnique(buffer)){
            printf("All unique characters.\n\n");
        }else{
            printf("Not unique characters.\n\n");
        }

        set_string_to_null(buffer, MAX_BUFFER_SIZE);
    }

    fclose(fileStream);

    printf("\n\n%s executed\n\n", argv[0]);
    return 0;
}

bool isUnique(char* string){
/*
ASSUMPTIONS: String has a '\0' char in it to stop the while loops.

Time O(n^2), Space O(n); Where n is the length of string.

Prints all unique chars in string by comparing each char with all others and printing out
char if no duplicate was found.

Input:
    char* string: The string to read for unique chars.

Output:
    bool allUnique: True if all unique, else False.

Example Usage:

bool booleanResult = False;
char buffer[MAX_BUFFER_SIZE] = {0};
// Write something into buffer
booleanResult = isUnique(buffer);
*/

    // CHECKS
    if(is_string_empty(string) == True) return False; // If string is empty

    bool  allUnique    = True;   // Assume we have not found a duplicate
    char* masterReader = string;
    char* charReader   = string;

    printf("%s\n", string);

    while(strcmp(masterReader, "\0") != 0){ // While not end

        if(isspace(*masterReader)){         // If we found a space char,
            masterReader++;                 // Advance pointer
            continue;                        // Restart search
        }

        while(strcmp(charReader, "\0") != 0){                         // While not end

            if(strcmp(masterReader, charReader) == 0) charReader++; // Avoid equality
            if(strcmp(charReader, "\0") == 0) break;
            if(isspace(*charReader)){                                 // If space char
                charReader++;                                         // Advance pointer
                continue;                                              // Restart search
            }

            if(*masterReader == *charReader){ // If we found matching chars
                allUnique = False;             // Flip flag
                break;                          // On the first duplicate found, stop
            }

            charReader++;
        }

        if(!allUnique) break; // On the first duplicate found, stop search
        masterReader++;       // Move to the next character in string to check
        charReader = string;  // Reset charReader to the beginning of string
    }

    return allUnique;
}
