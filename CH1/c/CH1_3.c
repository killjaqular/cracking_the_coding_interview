/*
Adonay Pichardo, adonaypichardo@gmail.com
github.com/killjaqular

@description
Cracking the Coding Interview:
Chapter 1 Problems

1.3 URLify:
    Write a method to replace all spaces in a string with "%20". You may assume that
    the string has sufficient space at the end to hold the additional charcters, and
    that you are given the "true" length of the string. (Note: If implementing in Java,
    please use a character array so that you  can perform this operation in place.)

    Example:
                Input:  "Mr John Smith    ", 13
                Output: "Mr%20John%20Smith"
*/

#include <stdio.h> // Standard input and output streams
#include <ctype.h> // bool type

#include "../../adolib/adolib_c/adopic.h"

#define True  1
#define False 0
#define MAX_BUFFER_SIZE  128

void URLify(char* string, unsigned int size, const char* newChars); // Replaces spaces

int main(int argc, char** argv){
    printf("\n\n%s executing\n\n", argv[0]);

    printf("////////////////\n");
    printf("// 1.3 URLify //\n");
    printf("////////////////\n");

    bool isStreamAtEOF            = False;
    char buffer[MAX_BUFFER_SIZE]  = {0};
    unsigned int stringSize       = 0;
    FILE* fileStream = fopen(argv[1], "r");

    if(fileStream == NULL){
        printf("\n %s WAS NOT FOUND.\n", argv[1]);
        exit(0);
    }

    // If we haven't reached the end of the file,
    while(isStreamAtEOF != True){ // Read from file, write to buffer
        isStreamAtEOF = write_to_buffer(fileStream, buffer, MAX_BUFFER_SIZE, "\"", "\"");
        stringSize    = length_of_string(buffer);

        if(isStreamAtEOF == True) break; // Stop test

        URLify(buffer, stringSize, "%20");
        printf("%s\n", buffer);

        set_string_to_null(buffer, MAX_BUFFER_SIZE);
    }

    fclose(fileStream);

    printf("\n\n%s executed\n\n", argv[0]);
    return 0;
}

void URLify(char* string, unsigned int size, const char* newChars){
/*
ASSUMPTIONS: String must have enough space to contain all newChars being inserted for
             every space. This also assumes that string has a "\0" to terminate.

Time O(n), Space O(n); Where n is the length of string.

Replaces all instances of space chars in string with newChars.

Input:
    char* string:
        The string to read and write into.
    unsigned int size:
        The size of string. It is assumed to be the length of string + (length of
        newChars * however many space chars.
        there are in string)
    char* newChars:
        The char to used to replace space chars.

Output: None

Example Usage:

char buffer[MAX_BUFFER] = {0};
unsigned int stringSize = length_of_string(buffer);
URLify(buffer, stringSize, "%20");
printf("%s\n", buffer);
*/
    if(newChars == NULL) return; // If nothing is to be replaced, return
    if(size < 1) return;          // Nothing to do if the string is size 0, return

    unsigned int master = 0;        // Keep track where in the string we are reading
    unsigned int pull = 0;          // Rewrite chars to right when inserting a new char
    unsigned int newCharsSize = 0;  // Size of the new string to replace spaces
    unsigned int newCharInsert = 0; // Insert into string
    const char*  newCharReader;     // Read the newChars string
    unsigned int temp = 0;          // Shift each char newCharsSize spaces to right

    newCharsSize = length_of_string(newChars);

    printf("%s\n", string);

    for(master = 0; master < size; master++){

        if(string[master] == 32){ // 32 is " " (blank space) in the ASCII table
            // Move all chars to avoid overwritting
            for(temp = 1; temp < newCharsSize; temp++){
                for(pull = size - 2; pull > master + 1; pull--){
                    string[pull] = string[pull - 1];
                }
            }

            // Insert newChars
            newCharReader = newChars; // Set the reader at the beginning
            newCharInsert = master;    // Start where the space was found
            while(strcmp(newCharReader, "\0") != 0){      // While char in newChars,
                string[newCharInsert] = *newCharReader; // Write into string
                newCharReader++;                          // Advance pointer
                newCharInsert++;
            }
        }
    }

    return;
}
