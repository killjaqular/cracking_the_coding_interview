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

1.3

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

int main(int argc, char** argv){
    printf("\n\n%s executing\n\n", argv[0]);

    // LOCAL MEMORY
    bool successful = False;

    // DYNAMIC MEMORY
    // None

    ////////////////////////////////////////////////////////////////
    // 1.1 Is Unique
    printf("//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("// 1.1 Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures? //\n");
    printf("//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    ////////////////////////////////////////////////////////////////
    FILE* file_stream            = NULL;  // The input file
    int file_reader              = 0;     // Steps through the input file
    char delimiter[2]            = ".\0"; // Used to splice the input file
    char as_char[2]              = "\0";  // Used to cast the read int as a char for comparison
    char buffer[MAX_BUFFER_SIZE] = "\0";  // The buffer used to read in the input file
    unsigned short buffer_insert   = 0;   // Used to step through the buffer
    bool boolean_result          = False; // Used to flag if all chars in a string are unique
    bool new_line                = False; // Used to flag if one or more newlines were encountered reading file_stream

    file_stream = verify_file_stream_pointer(argv[1]); // Open the input file
    if(file_stream != NULL) successful = True;         // Verify the file stream is valid

    if(successful){
        putchar('\n');
        while(file_reader != EOF){           // If we haven't reached the end of the file,
            file_reader = getc(file_stream); // Get a char from the stream
            as_char[0] = (char)file_reader;  // Cast it as a char to use as a comparison with another char

            // Ignore newlines
            new_line = False;                    // Reset the flag
            while(strcmp(as_char, "\n") == 0){   // While we read newlines,
                file_reader = getc(file_stream); // Get a char from the stream
                as_char[0] = (char)file_reader;  // Cast it as a char to use as a comparison with another char
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
                buffer[buffer_insert] = '\0';                // Manually insert the null char at the end of the string
                boolean_result = is_unique(buffer);
                set_string_to_null(buffer, MAX_BUFFER_SIZE); // Reset the buffer after using it
                if(boolean_result == True){
                    printf("All unique characters.\n\n");
                }else{
                    printf("Not unique characters.\n\n");
                }
                boolean_result = False;                      // Reset flag
                buffer_insert = 0;                           // Reset the buffer_insert to start writing to the buffer from index 0
            }
        }
    }
    fclose(file_stream);

    ////////////////////////////////////////////////////////////////
    // 1.2 Check Permutation
    printf("//////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("// 1.2 Check Permutation: Given two strings, write a method to decide if one is a permutation of the other. //\n");
    printf("//////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    ////////////////////////////////////////////////////////////////
    char right_string[MAX_BUFFER_SIZE] = {0};   // Another buffer used to read the second string
    unsigned short permutation_insert  = 0;     // Used to insert into the right_string buffer

    file_reader    = 0;       // Steps through the input file
    buffer_insert  = 0;       // Used to step through the buffer
    boolean_result = False;   // Used to flag if all chars in a string are unique

    file_stream = verify_file_stream_pointer(argv[2]); // Open the input file
    if(file_stream != NULL) successful = True;         // Verify the file stream is valid

    if(successful){
        putchar('\n');
        while(file_reader != EOF){               // If we haven't reached the end of the file,
            file_reader = getc(file_stream);     // Get a char from the stream
            as_char[0] = (char)file_reader;      // Cast it as a char to use as a comparison with another char

            // Consume all newlines and throw them away
            while(strcmp(as_char, "\n") == 0){   // While we read newlines,
                file_reader = getc(file_stream); // Get a char from the stream
                as_char[0] = (char)file_reader;  // Cast it as a char to use as a comparison with another char
            }

            buffer[buffer_insert] = file_reader; // Write the new char into the buffer
            buffer_insert++;                     // Advance the inserter

            if((strcmp(as_char, delimiter) == 0)){ // If we read in a '.',
                // Process buffer
                buffer[buffer_insert] = '\0';      // Manually insert the null char at the end of the string

                while(file_reader != EOF){               // If we haven't reached the end of the file,
                    file_reader = getc(file_stream);     // Get a char from the stream
                    as_char[0] = (char)file_reader;      // Cast it as a char to use as a comparison with another char

                    // Consume all newlines and throw them away
                    while(strcmp(as_char, "\n") == 0){   // While we read newlines,
                        file_reader = getc(file_stream); // Get a char from the stream
                        as_char[0] = (char)file_reader;  // Cast it as a char to use as a comparison with another char
                    }

                    right_string[permutation_insert] = file_reader; // Write the new char into the buffer
                    permutation_insert++;                           // Advance the inserter

                    if((strcmp(as_char, delimiter) == 0)){ // If we read in a '.',
                        // Process buffer
                        buffer[buffer_insert] = '\0';                      // Manually insert the null char at the end of the string
                        boolean_result = check_permutation(buffer, right_string);
                        set_string_to_null(right_string, MAX_BUFFER_SIZE); // Clear right_string
                        set_string_to_null(buffer, MAX_BUFFER_SIZE);       // Clear buffer

                        if(boolean_result == True){
                            printf("Valid Permutation.\n\n");
                        }else{
                            printf("Invalid Permutation.\n\n");
                        }

                        boolean_result = False; // Reset flag
                        permutation_insert = 0; // Reset the buffer_insert to start writing to right_string from index 0
                    }
                }
                buffer_insert = 0;              // Reset the buffer_insert to start writing to the buffer from index 0
            }
        }
    }
    fclose(file_stream);

    printf("\n\n%s executed\n\n", argv[0]);
    return 0;
}// END main

// DEFINITIONS
bool is_unique(char* string){
/*
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

    if(length_of_string(left_string) < 1) return False;  // If left_string is less than 1 char
    if(length_of_string(right_string) < 1) return False; // If right_string is less than 1 char

    // LOCAL MEMORY
    unsigned short left_frequency[94]  = {0};          // Used to count the frequency of printable ASCII characters
    unsigned short right_frequency[94] = {0};          // Used to count the frequency of printable ASCII characters
    bool  is_permutation               = True;         // Assume True
    char* right_reader                 = left_string;  // Begin at the first character
    char* left_reader                  = right_string; // Begin at the first character
    unsigned short look_up             = 0;            // Used to step through both char frequency arrays

    printf("%s\n", left_string);
    while(strcmp(right_reader, "\0") != 0){   // While we have not reached the end of the string,
        left_frequency[*right_reader - 32]++; // Account for the frequency
        right_reader++;                       // Advance the pointer
    }

    printf("%s\n", right_string);
    while(strcmp(left_reader, "\0") != 0){     // While we have not reached the end of the string,
        right_frequency[*right_reader - 32]++; // Account for the frequency
        left_reader++;                         // Advance the pointer
    }

    //TODO: Step through both frequency arrays and determine if either string has enough chars to create the other

    return check_permutation;
}
