/*
Adonay Pichardo, adonaypichardo@gmail.com

@file
CH1_Arrays_and_Strings.c

@description
Cracking the Coding Interview:
Chapter 1 Problems

1.1 Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you cannot use
    additional data structures?

1.2 Check Permutation: Given two strings, write a method to decide if one is a permutation of the other.

1.3 URLify: Write a method to replace all spaces in a string with '%20'. You may assume that the string has
            sufficient space at the end to hold the additional charcters, and that you are given the "true"
            length of the string. (Note: If implementing in Java, please use a character array so that you 
            can perform this operation in place.)
            Example: 
                Input:  "Mr John Smith    ", 13
                Output: "Mr%20John%20Smith"

1.4

1.5

1.6

1.7

1.8

1.9

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
bool is_unique(char* string); // Checks if all chars in string are unique
bool check_permutation(char* left_string, char* right_string); // Checks if either string can be a permutation of the other
void replace_space_with_string(char string[], unsigned int size, char* target_char, char* new_chars); // Replaces chars in a string

int main(int argc, char** argv){
    printf("\n\n%s executing\n\n", argv[0]);

    // LOCAL MEMORY
    bool successful = False;

    // DYNAMIC MEMORY
    // None

    ////////////////////////////////////////////////////////////////
    // 1.1 Is Unique
    printf("///////////////////\n");
    printf("// 1.1 Is Unique //\n");
    printf("///////////////////\n");
    ////////////////////////////////////////////////////////////////
    FILE* file_stream            = NULL;  // The input file
    char buffer[MAX_BUFFER_SIZE] = {0};   // The buffer used to read in the input file
    bool boolean_result          = False; // Used to flag if all chars in a string are unique
    bool is_stream_at_EOF        = False; // Tracks if input has reached end

    file_stream = verify_file_stream_pointer(argv[1]); // Open the input file
    if(file_stream != NULL) successful = True;         // Verify the file stream is valid

    if(successful){
        putchar('\n');
        // If we haven't reached the end of the file,
        while(is_stream_at_EOF != True){ // Read from file, write to buffer
            is_stream_at_EOF = write_to_string(file_stream, buffer, MAX_BUFFER_SIZE, NULL, ".");
            if(is_stream_at_EOF == True) break; // Stop test

            boolean_result = is_unique(buffer);

            set_string_to_null(buffer, MAX_BUFFER_SIZE); // Reset the buffer after using it
            if(boolean_result == True){
                printf("All unique characters.\n\n");
            }else{
                printf("Not unique characters.\n\n");
            }
            boolean_result = False; // Reset flag
        }
    }
    fclose(file_stream);

    ////////////////////////////////////////////////////////////////
    // 1.2 Check Permutation
    printf("///////////////////////////\n");
    printf("// 1.2 Check Permutation //\n");
    printf("///////////////////////////\n");
    ////////////////////////////////////////////////////////////////
    char right_string[MAX_BUFFER_SIZE] = {0}; // Another buffer used to read the second string

    boolean_result   = False; // Used to flag if all chars in a string are unique
    is_stream_at_EOF = False; // Tracks if input has reached end

    file_stream = verify_file_stream_pointer(argv[2]); // Open the input file
    if(file_stream != NULL) successful = True;         // Verify the file stream is valid

    if(successful){
        putchar('\n');
        // If we haven't reached the end of the file,
        while(is_stream_at_EOF != True){ // Read from file, write to buffer
            is_stream_at_EOF = write_to_string(file_stream, buffer, MAX_BUFFER_SIZE, NULL, ".");
            if(is_stream_at_EOF == True) break; // Stop test
            is_stream_at_EOF = write_to_string(file_stream, right_string, MAX_BUFFER_SIZE, NULL, ".");
            if(is_stream_at_EOF == True) break; // Stop test

            boolean_result = check_permutation(buffer, right_string);

            set_string_to_null(buffer, MAX_BUFFER_SIZE);       // Clear buffer
            set_string_to_null(right_string, MAX_BUFFER_SIZE); // Clear right_string

            if(boolean_result == True){
                printf("Valid Permutation.\n\n");
            }else{
                printf("Invalid Permutation.\n\n");
            }
        }
    }
    fclose(file_stream);

    ////////////////////////////////////////////////////////////////
    // 1.3 Check Permutation
    printf("////////////////\n");
    printf("// 1.3 URLify //\n");
    printf("////////////////\n");
    ////////////////////////////////////////////////////////////////
    unsigned int string_size     = 0;   // Used to measure buffer

    boolean_result   = False; // Used to flag if all chars in a string are unique
    is_stream_at_EOF = False; // Tracks if input has reached end

    file_stream = verify_file_stream_pointer(argv[3]); // Open the input file
    if(file_stream != NULL) successful = True;         // Verify the file stream is valid

    if(successful){
        putchar('\n');
        // If we haven't reached the end of the file,
        while(is_stream_at_EOF != True){ // Read from file, write to buffer
            is_stream_at_EOF = write_to_string(file_stream, buffer, MAX_BUFFER_SIZE, "\"", "\"");
            string_size = length_of_string(buffer);
            if(is_stream_at_EOF == True) break; // Stop test

            replace_space_with_string(buffer, string_size, " ", "%20");
            printf("%s\n", buffer);

            set_string_to_null(buffer, MAX_BUFFER_SIZE); // Clear buffer

            printf("%s\n\n", buffer);
        }
    }
    fclose(file_stream);

    printf("\n\n%s executed\n\n", argv[0]);
    return 0;
}// END main

// DEFINITIONS
bool is_unique(char* string){
/*
ASSUMPTION: string has a '\0' char in it to stop the while loops.
void is_unique: Time O(n^2), Space O(n); Where n is the length of string.
    Prints all unique chars in string by comparing each char with all others and printing out char if no duplicate was
    found.

Input:
    char* string:
        The string to read for unique chars.

Output:
    bool all_unique:
        

Example Usage:

bool boolean_result = False;
char buffer[MAX_BUFFER_SIZE] = "\0";
// Write something into buffer
boolean_result = is_unique(buffer);

*/

    if(is_string_empty(string) == True) return False; // If string is empty
    if(length_of_string(string) < 1) return False;    // If string is less than 1 char

    // LOCAL MEMORY
    bool  all_unique    = True;   // Assume we have not found a duplicate
    char* string_reader = string; // Begin at the first character
    char* char_reader   = string; // Begin at the first character

    printf("%s\n", string);

    while(strcmp(string_reader, "\0") != 0){ // While we have not reached the end of the string,
        if(isspace(*string_reader)){         // If we found a space char
            string_reader++;                 // Advance pointer
            continue;                        // Restart search
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

bool check_permutation(char* left_string, char* right_string){
/*
bool check_permutation: Time O(n + m), Space O(n + m); where n is the length of left_string and m is the length of right_string.
    Checks if either string is a permutation of the other. Returns True on first proof.

Input:
    char* left_string:
        Used to check if a permutation is possible.
    char* right_string:
        Used to check if a permutation is possible.

Output:
    bool check_permutation:
        True if right_string is found to be a permutation of left_string

Example Usage:

bool boolean_result            = False;
char string_a[MAX_BUFFER_SIZE] = "\0";
char string_b[MAX_BUFFER_SIZE] = "\0";
// Write something into string_a
// Write something into string_b
boolean_result = check_permutation(string_a, string_b);

*/

    printf("%s\n", left_string);
    printf("%s\n", right_string);

    // LOCAL MEMORY
    unsigned short frequency[128]       = {0};                 // Used to count the frequency of printable ASCII characters
    bool  is_permutation                = True;                // Assume True
    unsigned short look_up              = 0;                   // Used to step through both char frequency arrays
    unsigned int left_size   = length_of_string(left_string);  // Get size of left_string
    unsigned int right_size  = length_of_string(right_string); // Get size of right_string

    if(left_size != right_size) return False; // If the strings are not same size, can't be permutation

    // Count the frequency of each char in left_string
    for(look_up = 0; look_up < left_size; look_up++){
        frequency[left_string[look_up]]++; // Account for the current ASCII char's frequency
    }

    // Count the frequency of each char in right_string
    for(look_up = 0; look_up < left_size; look_up++){
        if(frequency[right_string[look_up]] <= 0){ // If we ever use more than we have,
            is_permutation = False;                // Cannot be a permutation
            break;                                 // Stop search
        }
        frequency[right_string[look_up]]--; // Consume a char from the frequency of left_string
    }

    return is_permutation;
}

void replace_space_with_string(char string[], unsigned int size, char* target_char, char* new_chars){
/*
ASSUMPTION: string must have enough space to contain all new_chars being inserted for every space.
            This also assumes that string has a "\0" to terminate.
void replace_space_with_string:
    Replaces all instances a space in string with new_chars.

Input:
    char string[]:
        The string to read and write into.
    unsigned int size:
        The size of string. It is assumed to be the length of string + (length of new_chars * however many target_char there are in string)
    char* target_char:
        The char in string to be replaced.
    char* new_chars:
        The char to used to replace target_char.

Output: None

Example Usage:



*/

    // LOCAL MEMORY
    unsigned int master = 0;          // Used to keep track where in the string we are reading
    unsigned int pull = 0;            // Used to rewrite chars farther to the right when inserting a new_chars replacement
    unsigned int new_chars_size = 0;  // Size of the new string to replace spaces
    unsigned int new_char_insert = 0; // Used to insert into string
    char* new_char_reader;            // Used to read the new_chars string
    unsigned int temp = 0;            // Used to shift each char new_chars_size spaces to the right

    if(size < 1) return; // Nothing to do if the string is size 0
    if((target_char == NULL) || (new_chars == NULL)) return; // If nothing is to be replaced

    new_chars_size = length_of_string(new_chars);

    printf("%s\n", string);

    for(master = 0; master < size; master++){
        if(string[master] == 32){ // 32 is " " (blank space) in the ASCII table
            // Move all chars to avoid overwritting
            for(temp = 1; temp < new_chars_size; temp++){
                for(pull = size - 2; pull > master + 1; pull--){
                    string[pull] = string[pull - 1];
                }
            }

            // Insert new_chars
            new_char_reader = new_chars; // Set the reader at the beginning
            new_char_insert = master;    // Start where the space was found
            while(strcmp(new_char_reader, "\0") != 0){                // While we read each char in new_chars,
                string[new_char_insert] = *new_char_reader; // Write into string
                new_char_reader++;                          // Advance pointer
                new_char_insert++;
            }
        }
    }

    return;
}
