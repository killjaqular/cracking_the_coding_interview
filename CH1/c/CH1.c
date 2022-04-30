/*
Adonay Pichardo, adonaypichardo@gmail.com
github.com/killjaqular

@description
Cracking the Coding Interview:
Chapter 1 Problems

1.5 One Away:
    There are three type of edits that can be performed on strings: insert a character,
    remove a character, or replace a character. Given two strings, write a function to
    check if they are one edit (or zero edits) away.

    Example:
        pale, ple   -> true
        pales, pale -> true
        pale, bale  -> true
        pale, bake  -> true

1.6 String Compression:
    Implement a method to perform basic string using the counts of repeated characters.
    For example, the string aabcccccaaa would become a2b1c5a3. If the "compressed" string
    would not become smaller than the original string, your method should return the
    original string. You can assume the string has only uppercase and lowercase letters
    (a-z).

1.7 Rotate Matrix:
    Given an image represented by an NxN matric, where each pixel in the image is 4
    bytes, write a method to rotate the image by 90 degrees. Can you do this in place?

1.8 Zero Matrix:
    Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
    column are set to 0.

1.9 String Rotation:
    Assume you have a method isSubstring which checks if one word is a substring of
    another. Given two strings, s1 and s2, write code to check if s2 is a rotation of s1
    using only one call to isSubstring(e.g., "waterbottle" is a rotation of
    "erbottlewat").

*/

// STANDARD LIBRARIES
#include <stdio.h>
#include <ctype.h>

// NON-STANDARD LIBRARIES
#include "../../adolib/adolib_c/adopic.h"

// MACROS
#define True  1
#define False 0
#define MAX_BUFFER_SIZE  128
#define ASCII_CHAR_TABLE 128 // 128 Printable characters in the ASCII table

// GLOBAL VARIABLES
// None

// STRUCTURES
// None

// PROTOTYPES
bool check_permutation(const char* left_string, const char* right_string); // Checks if strings are mutual permutations
bool palindrome_permutation(const char* string); // Checks if a palindrome permutation is possible
bool one_away(const char* original, const char* string); // Checks if string is no more than 1 edit away from original
char* string_compression(char* string); // Creates a string of each char with their frequency
void rotate_matrix(char* matrix); // Rotates matrix 90* CW
void zero_matrix(char** char_2d_matrix); //
void string_rotation(char* string1, char* string2); //

int main(int argc, char** argv){
    printf("\n\n%s executing\n\n", argv[0]);

    // LOCAL MEMORY
    bool is_stream_at_EOF              = False; // Tracks if input has reached end
    bool boolean_result                = False; // Used to capture boolean results from functions
    char right_string[MAX_BUFFER_SIZE] = {0};   // Another buffer used to read the second string
    char buffer[MAX_BUFFER_SIZE]       = {0};   // The buffer used to read in the input file
    char* compressed_string            = NULL;  // Compressed string
    char* char_2d_matrix               = NULL;  // 2D matrix of chars
    unsigned int string_size           = 0;     // Used to measure buffer

    FILE* all_tests                    = NULL;  // File with all test cases
    FILE* current_test_input           = NULL;  // The current test case

    // DYNAMIC MEMORY
    // None

    all_tests = verify_file_stream_pointer(argv[1]); // Open the input file

    if(all_tests != NULL){
        while(is_stream_at_EOF != True){

            is_stream_at_EOF = write_to_buffer(all_tests, buffer, MAX_BUFFER_SIZE, NULL,
            "\n"); // Name of test case
            if(is_stream_at_EOF == True){ // If we have read all test cases,
                break;
            }

            current_test_input = verify_file_stream_pointer(buffer); // Open input file

            if(current_test_input == NULL){
                printf("Missing test case: %s\n", buffer);
                break;
            }

            printf("<%s>\n", buffer);

            if(strcmp(buffer, "one_away.in") == 0){
                ////////////////////////////////////////////////////////////////
                // 1.5 One Away
                printf("//////////////////\n");
                printf("// 1.5 One Away //\n");
                printf("//////////////////\n");
                ////////////////////////////////////////////////////////////////

                while(is_stream_at_EOF != True){ // Read from file, write to buffer
                    is_stream_at_EOF = write_to_buffer(current_test_input, buffer,
                        MAX_BUFFER_SIZE, NULL, " ");
                    if(is_stream_at_EOF == True) break; // Stop test
                    is_stream_at_EOF = write_to_buffer(current_test_input, right_string,
                        MAX_BUFFER_SIZE, NULL, " ");
                    if(is_stream_at_EOF == True) break; // Stop test

                    boolean_result = one_away(buffer, right_string);

                    set_string_to_null(buffer, MAX_BUFFER_SIZE);
                    set_string_to_null(right_string, MAX_BUFFER_SIZE);

                    if(boolean_result == True){
                        printf("True.\n\n");
                    }else{
                        printf("False.\n\n");
                    }
                }
            }

            if(strcmp(buffer, "string_compression.in") == 0){
                ////////////////////////////////////////////////////////////////
                // 1.6 String Compression
                printf("////////////////////////////\n");
                printf("// 1.6 String Compression //\n");
                printf("////////////////////////////\n");
                ////////////////////////////////////////////////////////////////

                while(is_stream_at_EOF != True){ // Read from file, write to buffer
                    is_stream_at_EOF = write_to_buffer(current_test_input, buffer,
                        MAX_BUFFER_SIZE, NULL, "\n");
                    if(is_stream_at_EOF == True) break; // Stop test

                    compressed_string = string_compression(buffer);

                    if(compressed_string != NULL){
                        printf("%s\n\n", compressed_string);
                    }else{
                        printf("%s\n\n", buffer);
                    }

                    set_string_to_null(buffer, MAX_BUFFER_SIZE);
                    compressed_string = NULL;
                    free(compressed_string);
                }
            }

            if(strcmp(buffer, "rotate_matrix.in") == 0){
                ////////////////////////////////////////////////////////////////
                // 1.7 Rotate Matrix
                printf("///////////////////////\n");
                printf("// 1.7 Rotate Matrix //\n");
                printf("///////////////////////\n");
                ////////////////////////////////////////////////////////////////

                char_2d_matrix = create_char_2d_square_matrix(current_test_input);
                printf("back to main\n");
                // rotate_matrix(char_2d_matrix);
            }

            fclose(current_test_input); // Close file
            // Reset reusable variables
            boolean_result   = False; // Used to flag if all chars in a string are unique
            is_stream_at_EOF = False; // Tracks if input has reached end
        }

    fclose(all_tests); // Close file
    }

    printf("\n\n%s executed\n\n", argv[0]);
    return 0;
}

bool one_away(const char* original, const char* string){
/*
ASSUMPTION: original and string has a '\0' char in it to stop the while loops.
bool one_away:
    Checks if string is one or less edits away from original.

Input:
    char* original:
        The original string.
    char* string:
        The string to test against original.

Output:
    bool result:
        Returns True if string is one or less edits away from being original.

Example Usage:

is_stream_at_EOF = write_to_buffer(current_test_input, buffer, MAX_BUFFER_SIZE, NULL,
" ");
is_stream_at_EOF = write_to_buffer(current_test_input, right_string, MAX_BUFFER_SIZE,
NULL, " ");
if(is_stream_at_EOF == True) break; // Stop test

boolean_result = one_away(buffer, right_string);

set_string_to_null(buffer, MAX_BUFFER_SIZE); // Clear buffer
set_string_to_null(right_string, MAX_BUFFER_SIZE); // Clear buffer

if(boolean_result == True){
    printf("True.\n\n");
}else{
    printf("False.\n\n");
}

*/

    // LOCAL MEMORY
    unsigned int original_length                = length_of_string(original);
    unsigned int string_length                  = length_of_string(string);
    unsigned int original_reader                = 0;     // Indexing original
    unsigned int string_reader                  = 0;     // Indexing string
    bool one_difference_found                   = False; // If at least one diff found
    bool result                                 = True;  // Assumed to be True

    // CHECKS
    if(original_length - string_length > 1) return False; // If either is longer

    printf("%s %s\n", original, string);

    if(original_length - string_length == 1){ // Check if we are inserting
        for(original_reader = 0, string_reader = 0; string_reader < string_length;
            original_reader++, string_reader++){
            if((one_difference_found == True) && (original[original_reader] !=
                string[string_reader]))
                return False; // If we find more than one difference

            if((one_difference_found == False) && (original[original_reader] !=
                string[string_reader])){
                original_reader++;
                one_difference_found = True;
            }
        }
    }else if(original_length - string_length == -1){ // Check if we are removing
        for(original_reader = 0, string_reader = 0; original_reader < original_length;
            original_reader++, string_reader++){
            if((one_difference_found == True) && (original[original_reader] !=
                string[string_reader]))
                return False; // If we find more than one difference

            if((one_difference_found == False) && (original[original_reader] !=
                string[string_reader])){
                string_reader++;
                one_difference_found = True;
            }
        }
    }else if(original_length == string_length){ // Check if we are replacing
        for(original_reader = 0, string_reader = 0; string_reader < string_length;
            original_reader++, string_reader++){
            if((one_difference_found == True) && (original[original_reader] !=
                string[string_reader]))
                return False; // If we find more than one difference

            if((one_difference_found == False) && (original[original_reader] !=
                string[string_reader])){
                one_difference_found = True;
            }
        }
    }

    return result;
}

char* string_compression(char* string){
/*
ASSUMPTION: string has a '\0' char in it to stop the while loops.
char* string_compression:
    Writes a char and the number of its occurances into a new string.

Input:
    const char* string:
        The given string.

Output:
    char* compressed_string:
        The compressed string if it is shorter than the original.
    char* string:
        The original string if compression is longer than the original.

Example Usage:

FILE* current_test_input = fopen("some_file.txt", "r");
unsigned int MAX_BUFFER = 256;
char buffer[MAX_BUFFER] = {0};
write_to_buffer(current_test_input, buffer, MAX_BUFFER_SIZE, NULL, "\n");
compressed_string = string_compression(buffer);
if(compressed_string != NULL){
    printf("%s\n\n", compressed_string);
}else{
    printf("%s\n\n", buffer);
}

}

*/

    // CHECKS
    if(is_string_empty(string)) return NULL; // If string is empty, return nothing

    // LOCAL MEMORY
    unsigned int string_length             = length_of_string(string); // String length
    unsigned int insert                    = 0;   // Insert into the compressed string
    unsigned int reader                    = 0;   // Step through string
    unsigned int frequency                 = 0;   // Tracks the frequency of a char
    unsigned int int_length                = 0;   // Lenght of the integer as a string
    unsigned int int_counter               = 0;   // Steps through the string
    char int_as_string[MAX_BUFFER_SIZE]    = {0}; // String representation of an int

    // DYNAMIC MEMORY
    char* compressed_string = (char*) malloc(sizeof(char) * string_length);
    set_string_to_null(compressed_string, sizeof(char) * string_length);

    printf("%s\n", string);

    for(reader = 0; reader < string_length;){
        frequency = 0; // Reset frequency
        compressed_string[insert] = string[reader];

        while(compressed_string[insert] == string[reader]){
            reader++;
            frequency++;
        }
        insert++;
        int_to_string(frequency, int_as_string);
        int_length = length_of_string(int_as_string);
        strcat(compressed_string, int_as_string);

        for(int_counter = 0; int_counter < int_length; int_counter++){ // Advance insert
            insert++;
            // If the compressed string will be longer, return original string
            if(insert > string_length){
                compressed_string = NULL;
                free(compressed_string);
                return string;
            }
        }
        set_string_to_null(int_as_string, MAX_BUFFER_SIZE); // Reset int_as_string
    }

    return compressed_string;
}

void rotate_matrix(char* matrix){
/*
void rotate_matrix: Time O(n), Space O(n), where n is the number of elements in matrix
    Rotates all elements 90 degrees clockwise.

Input:
    const char matrix[][]:
        The matrix to rotate.

Output: None

Example Usage:



*/
    // CHECKS
    // None

    // LOCAL MEMORY
    unsigned int row    = 0; // Steps through the rows
    unsigned int column = 0; // Steps through the columns
    unsigned int total_range = strlen(matrix) / sizeof(matrix[0]);

    for(row = 0; row < total_range * total_range; row += total_range){
        for(column = 0; column < total_range; column++){
            printf("%c", matrix[row + column]);
        }
    }

    return;
}
