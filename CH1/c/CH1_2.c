/*
Adonay Pichardo, adonaypichardo@gmail.com
github.com/killjaqular

@description
Cracking the Coding Interview:
Chapter 1 Problems

1.2 Check Permutation:
    Given two strings, write a method to decide if one is a permutation of the other.
*/

#include <stdio.h> // Standard input and output streams
#include <ctype.h> // bool type

#include "../../adolib/adolib_c/adopic.h"

#define True  1
#define False 0
#define MAX_BUFFER_SIZE  128
#define ASCII_CHAR_TABLE 128 // 128 Printable characters in the ASCII table

bool check_permutation(const char* lString, const char* buffer2); // Are permutations

int main(int argc, char** argv){
    printf("\n\n%s executing\n\n", argv[0]);

    printf("///////////////////////////\n");
    printf("// 1.2 Check Permutation //\n");
    printf("///////////////////////////\n");

    bool isStreamAtEOF            = False;
    char buffer[MAX_BUFFER_SIZE]  = {0};
    char buffer2[MAX_BUFFER_SIZE] = {0};
    FILE* fileStream = fopen(argv[1], "r");

    if(fileStream == NULL){
        printf("\n %s WAS NOT FOUND.\n", argv[1]);
        exit(0);
    }

    while(isStreamAtEOF != True){
        isStreamAtEOF = write_to_buffer(fileStream, buffer, MAX_BUFFER_SIZE, NULL, ".");
        if(isStreamAtEOF == True) break; // Stop test

        isStreamAtEOF = write_to_buffer(fileStream, buffer2, MAX_BUFFER_SIZE, NULL, ".");
        if(isStreamAtEOF == True) break; // Stop test

        if(check_permutation(buffer, buffer2)){
            printf("Valid Permutation.\n\n");
        }else{
            printf("Invalid Permutation.\n\n");
        }

        set_string_to_null(buffer, MAX_BUFFER_SIZE);
        set_string_to_null(buffer2, MAX_BUFFER_SIZE);
    }

    fclose(fileStream);

    printf("\n\n%s executed\n\n", argv[0]);
    return 0;
}

bool check_permutation(const char* lString, const char* rString){
/*
Time O(n + m), Space O(n + m); where n is the length of lString and m is the length
of rString.

Checks if either string is a permutation of the other. Returns True on first proof.

Input:
    char* lString: Used to check if a permutation is possible.
    char* rString: Used to check if a permutation is possible.

Output:
    bool check_permutation:
        True if rString is found to be a permutation of lString

Example Usage:

bool boolean_result            = False;
char stringA[MAX_BUFFER_SIZE] = "\0";
char stringB[MAX_BUFFER_SIZE] = "\0";
// Write something into stringA
// Write something into stringB
boolean_result = check_permutation(stringA, stringB);
*/
    unsigned short frequency[ASCII_CHAR_TABLE] = {0};  // Count frequency of char
    bool isPermutation                         = True; // Assume True
    unsigned short lookUp                      = 0;    // Step both frequency arr
    unsigned int lSize = length_of_string(lString);    // Size of lString
    unsigned int rSize = length_of_string(rString);    // Size of rString

    printf("%s\n", lString);
    printf("%s\n", rString);

    if(lSize != rSize) return False; // If the strings are not same size, return

    // Count the frequency of each char in lString
    for(lookUp = 0; lookUp < lSize; lookUp++){
        frequency[(int) lString[lookUp]]++; // Account for ASCII char's frequency
    }

    // Count the frequency of each char in rString
    for(lookUp = 0; lookUp < lSize; lookUp++){

        if(frequency[(int) rString[lookUp]] <= 0){ // If we use more than we have,
            isPermutation = False;                 // Cannot be a permutation
            break;                                 // Stop search
        }
        frequency[(int) rString[lookUp]]--; // Consume count lString freq arr
    }

    return isPermutation;
}
