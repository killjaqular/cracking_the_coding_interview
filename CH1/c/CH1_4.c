/*
Adonay Pichardo, adonaypichardo@gmail.com
github.com/killjaqular

@description
Cracking the Coding Interview:
Chapter 1 Problems

1.4 Palindrome Permutation:
    Given a string, write a function to check if it is a permutation of a plindrome.
    A palindrome is a word or phrase that is the same forwards and backwards. A
    permutation is a rearrangement of letters. The palindrome does not need to be limited
    to just dictionary words.

    Example:
        Input:  Tact Coa
        Output: True
        Permutations: "taco cat", "atco cta", etc...
*/

#include <stdio.h> // Standard input and output streams
#include <ctype.h> // bool type

#include "../../adolib/adolib_c/adopic.h"

#define True  1
#define False 0
#define MAX_BUFFER_SIZE  128

bool palindromePermutation(const char* lString, const char* rString); // Can palindrome

int main(int argc, char** argv){
    printf("\n\n%s executing\n\n", argv[0]);

    printf("////////////////////////////////\n");
    printf("// 1.4 Palindrome Permutation //\n");
    printf("////////////////////////////////\n");

    bool isStreamAtEOF            = False;
    char buffer[MAX_BUFFER_SIZE]  = {0};
    unsigned int stringSize       = 0;
    FILE* fileStream = fopen(argv[1], "r");

    if(fileStream == NULL){
        printf("\n %s WAS NOT FOUND.\n", argv[1]);
        exit(0);
    }

    while(isStreamAtEOF != True){
        isStreamAtEOF = write_to_buffer(fileStream, buffer, MAX_BUFFER_SIZE, NULL, "\n");

        if(isStreamAtEOF == True) break;

        if(palindromePermutation(buffer)){
            printf("Palindrome Permutations possible.\n\n");
        }else{
            printf("Palindrome Permutations impossible.\n\n");
        }

        set_string_to_null(buffer, MAX_BUFFER_SIZE);
    }

    fclose(fileStream);

    printf("\n\n%s executed\n\n", argv[0]);
    return 0;
}

bool palindromePermutation(const char* string){
/*
ASSUMPTION: string has a '\0' char in it to stop the while loops.

Checks if string can be permutated into any palindrome. The permutated palindrome does
not have to be a valid English phrase.

Input:
    char* string:
        The string to test.

Output:
    bool result:
        Returns True if the input can be used to generate palindrome permutations.

Example Usage:

unsigned int MAX_SIZE  = 100;
char* buffer[MAX_SIZE] = {0};
// Write into buffer
bool boolean_result = palindromePermutation(buffer);
if(boolean_result == True){
    printf("Palindrome Permutations possible.\n\n");
}else{
    printf("Palindrome Permutations impossible.\n\n");
}
*/
    if(string == NULL) return False; // If no string was given, return

    bool result                   = True;   // Assume palindrome permutation is possible
    const char* stringReader     = string; // Read string from start
    unsigned short frequency[ASCII_CHAR_TABLE] = {0}; // Count frequency of ASCII chars
    unsigned int counter          = 0;      // Step through the frequency table
    bool evenChars               = True;   // Checks even number of chars, assume True
    unsigned int stringLength    = 0;      // How many chars in string
    bool singleFrequency         = False;  // Flag if single frequency char found

    printf("%s\n", string);

    // Build frequency table
    while(strcmp(stringReader, "\0") != 0){
        if(isspace(*stringReader)){ // Do not count spaces
            stringReader++;
            continue;
        }
        if(frequency[(int) *stringReader] < 1){
            frequency[(int) *stringReader]++; // Count frequency of that char
        }else{
            frequency[(int) *stringReader]--; // Consume that count
        }
        stringReader++;                 // Advance pointer
        stringLength++;                 // Increase the length of the string
    }

    if(stringLength % 2 == 0) evenChars = False; // If there are odd total chars

    ////////////////////////////////////////////////////////////////
    // We have assumed that string has valid palindrome permutations.
    // There are two cases we must check to refute that.
    ////////////////////////////////////////////////////////////////
    for(counter = 0; counter < ASCII_CHAR_TABLE; counter++){
        if((frequency[counter] == 1) && (singleFrequency == False)){
            singleFrequency = True;
            continue;
        }

        // We cannot have a char with a frequency of 1 if there are even chars in string
        if((frequency[counter] == 1) && (evenChars == True)){
            result = False;
            break;
        }

        // We cannot find more than 1 char to be a frequency of 1 in odd strings
        if((frequency[counter] == 1) && (singleFrequency == True)){
            result = False;
            break;
        }
    }

    return result;
}
