/*
Adonay Pichardo, adonaypichardo@gmail.com
github.com/killjaqular

@file
CH1_Arrays_and_Strings.c

@description
Cracking the Coding Interview:
Chapter 1 Problems

1.1 Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you cannot use
               additional data structures?

1.2 Check Permutation: Given two strings, write a method to decide if one is a permutation of the other.

1.3 URLify: Write a method to replace all spaces in a string with '%20'. You may assume that the string has sufficient
            space at the end to hold the additional charcters, and that you are given the "true" length of the string.
            (Note: If implementing in Java, please use a character array so that you  can perform this operation in
            place.)
            Example: 
                Input:  "Mr John Smith    ", 13
                Output: "Mr%20John%20Smith"

1.4 Palindrome Permutation: Given a string, write a function to check if it is a permutation of a plindrome.
                            A palindrome is a word or phrase that is the same forwards and backwards. A permutation
                            is a rearrangement of letters. The palindrome does not need to be limited to just
                            dictionary words.
            Example:
                Input:  Tact Coa
                Output: True
                Permutations: "taco cat", "atco cta", etc...

1.5 One Away: There are three type of edits that can be performed on strings: insert a character, remove a character,
              or replace a character. Given two strings, write a function to check if they are one edit (or zero edits)
              away.
            Example:
                pale, ple   -> true
                pales, pale -> true
                pale, bale  -> true
                pale, bake  -> true

1.6 String Compression: Implement a method to perform basic string using the counts of repeated characters. For
                        example, the string aabcccccaaa would become a2b1c5a3. If the "compressed" string would not
                        become smaller than the original string, your method should return the original string. You can
                        assume the string has only uppercase and lowercase letters (a-z).

1.7 Rotate Matrix: Given an image represented by an NxN matric, where each pixel in the image is 4 bytes, write a
                   method to rotate the image by 90 degrees. Can you do this in place?

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
#define MAX_BUFFER_SIZE 100
#define CHAR_TABLE      128 // 128 Printable characters in the ASCII table

// GLOBAL VARIABLES
// None

// STRUCTURES
// None

// PROTOTYPES
bool is_unique(char* string); // Checks if all chars in string are unique
bool check_permutation(const char* left_string, const char* right_string); // Checks if strings are mutual permutations
void URLify(char string[], unsigned int size, const char* new_chars); // Replaces spaces in a string
bool palindrome_permutation(const char* string); // Checks if a palindrome permutation is possible
bool one_away(const char* original, const char* string); // Checks if string is no more than 1 edit away from original
char* string_compression(char* string); // Creates a string of each char with their frequency
void rotate_matrix(char* matrix); // Rotates matrix 90* CW

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

            is_stream_at_EOF = write_to_buffer(all_tests, buffer, MAX_BUFFER_SIZE, NULL, "\n"); // Name of test case
            if(is_stream_at_EOF == True){ // If we have read all test cases,
                break;
            }
            current_test_input = verify_file_stream_pointer(buffer); // Open the input file
            if(current_test_input == NULL){
                printf("Missing test case: %s\n", buffer);
                break;
            }

            if(strcmp(buffer, "is_unique.in") == 0){
                ////////////////////////////////////////////////////////////////
                // 1.1 Is Unique
                printf("///////////////////\n");
                printf("// 1.1 Is Unique //\n");
                printf("///////////////////\n");
                ////////////////////////////////////////////////////////////////

                if(current_test_input != NULL){
                    // If we haven't reached the end of the file,
                    while(is_stream_at_EOF != True){ // Read from file, write to buffer
                        is_stream_at_EOF = write_to_buffer(current_test_input, buffer, MAX_BUFFER_SIZE, NULL, ".");
                        if(is_stream_at_EOF == True) break; // Stop test

                        boolean_result = is_unique(buffer);

                        set_string_to_null(buffer, MAX_BUFFER_SIZE); // Reset the buffer after using it
                        if(boolean_result == True){
                            printf("All unique characters.\n\n");
                        }else{
                            printf("Not unique characters.\n\n");
                        }
                    }
                }
            }

            if(strcmp(buffer, "check_permutation.in") == 0){
                ////////////////////////////////////////////////////////////////
                // 1.2 Check Permutation
                printf("///////////////////////////\n");
                printf("// 1.2 Check Permutation //\n");
                printf("///////////////////////////\n");
                ////////////////////////////////////////////////////////////////

                while(is_stream_at_EOF != True){ // Read from file, write to buffer
                    is_stream_at_EOF = write_to_buffer(current_test_input, buffer, MAX_BUFFER_SIZE, NULL, ".");
                    if(is_stream_at_EOF == True) break; // Stop test
                    is_stream_at_EOF = write_to_buffer(current_test_input, right_string, MAX_BUFFER_SIZE, NULL, ".");
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

            if(strcmp(buffer, "URLify.in") == 0){
                ////////////////////////////////////////////////////////////////
                // 1.3 URLify
                printf("////////////////\n");
                printf("// 1.3 URLify //\n");
                printf("////////////////\n");
                ////////////////////////////////////////////////////////////////

                // If we haven't reached the end of the file,
                while(is_stream_at_EOF != True){ // Read from file, write to buffer
                    is_stream_at_EOF = write_to_buffer(current_test_input, buffer, MAX_BUFFER_SIZE, "\"", "\"");
                    string_size = length_of_string(buffer);
                    if(is_stream_at_EOF == True) break; // Stop test

                    URLify(buffer, string_size, "%20");
                    printf("%s\n", buffer);

                    set_string_to_null(buffer, MAX_BUFFER_SIZE); // Clear buffer

                    printf("%s\n", buffer);
                }
            }

            if(strcmp(buffer, "palindrome_permutation.in") == 0){
                ////////////////////////////////////////////////////////////////
                // 1.4 Palindrome Permutation
                printf("////////////////////////////////\n");
                printf("// 1.4 Palindrome Permutation //\n");
                printf("////////////////////////////////\n");
                ////////////////////////////////////////////////////////////////

                while(is_stream_at_EOF != True){ // Read from file, write to buffer
                    is_stream_at_EOF = write_to_buffer(current_test_input, buffer, MAX_BUFFER_SIZE, NULL, "\n");
                    if(is_stream_at_EOF == True) break; // Stop test

                    boolean_result = palindrome_permutation(buffer);

                    set_string_to_null(buffer, MAX_BUFFER_SIZE); // Clear buffer

                    if(boolean_result == True){
                        printf("Palindrome Permutations possible.\n\n");
                    }else{
                        printf("Palindrome Permutations impossible.\n\n");
                    }
                }
            }

            if(strcmp(buffer, "one_away.in") == 0){
                ////////////////////////////////////////////////////////////////
                // 1.5 One Away
                printf("//////////////////\n");
                printf("// 1.5 One Away //\n");
                printf("//////////////////\n");
                ////////////////////////////////////////////////////////////////

                while(is_stream_at_EOF != True){ // Read from file, write to buffer
                    is_stream_at_EOF = write_to_buffer(current_test_input, buffer, MAX_BUFFER_SIZE, NULL, " ");
                    if(is_stream_at_EOF == True) break; // Stop test
                    is_stream_at_EOF = write_to_buffer(current_test_input, right_string, MAX_BUFFER_SIZE, NULL, " ");
                    if(is_stream_at_EOF == True) break; // Stop test

                    boolean_result = one_away(buffer, right_string);

                    set_string_to_null(buffer, MAX_BUFFER_SIZE); // Clear buffer
                    set_string_to_null(right_string, MAX_BUFFER_SIZE); // Clear buffer

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
                    is_stream_at_EOF = write_to_buffer(current_test_input, buffer, MAX_BUFFER_SIZE, NULL, "\n");
                    if(is_stream_at_EOF == True) break; // Stop test

                    compressed_string = string_compression(buffer);

                    if(compressed_string != NULL){
                        printf("%s\n\n", compressed_string);
                    }else{
                        printf("%s\n\n", buffer);
                    }

                    set_string_to_null(buffer, MAX_BUFFER_SIZE); // Clear buffer

                }
            }

            if(strcmp(buffer, "rotate_matrix.in") == 0){
                ////////////////////////////////////////////////////////////////
                // 1.7 Rotate Matrix
                printf("///////////////////////\n");
                printf("// 1.7 Rotate Matrix //\n");
                printf("///////////////////////\n");
                ////////////////////////////////////////////////////////////////

                while(is_stream_at_EOF != True){ // Read from file, write to buffer
                    char_2d_matrix = create_char_2d_square_matrix(current_test_input);
                    rotate_matrix(char_2d_matrix);

                    if(compressed_string != NULL){
                        printf("%s\n\n", compressed_string);
                    }else{
                        printf("%s\n\n", buffer);
                    }

                    

                }
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

    // CHECKS
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

bool check_permutation(const char* left_string, const char* right_string){
/*
bool check_permutation: Time O(n + m), Space O(n + m); where n is the length of left_string and m is the length of
    right_string.
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

    // CHECKS
    // None

    // LOCAL MEMORY
    unsigned short frequency[CHAR_TABLE]       = {0};                 // Used to count the frequency of printable ASCII characters
    bool  is_permutation                = True;                // Assume True
    unsigned short look_up              = 0;                   // Used to step through both char frequency arrays
    unsigned int left_size   = length_of_string(left_string);  // Get size of left_string
    unsigned int right_size  = length_of_string(right_string); // Get size of right_string

    printf("%s\n", left_string);
    printf("%s\n", right_string);

    if(left_size != right_size) return False; // If the strings are not same size, return

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

void URLify(char string[], unsigned int size, const char* new_chars){
/*
ASSUMPTION: string must have enough space to contain all new_chars being inserted for every space.
            This also assumes that string has a "\0" to terminate.
void URLify:
    Replaces all instances a space in string with new_chars.

Input:
    char string[]:
        The string to read and write into.
    unsigned int size:
        The size of string. It is assumed to be the length of string + (length of new_chars * however many target_char
        there are in string)
    char* target_char:
        The char in string to be replaced.
    char* new_chars:
        The char to used to replace target_char.

Output: None

Example Usage:

char buffer[MAX_BUFFER] = {0};
unsigned int string_size = length_of_string(buffer);
URLify(buffer, string_size, "%20");
printf("%s\n", buffer);

*/

    // CHECKS
    if(new_chars == NULL) return; // If nothing is to be replaced, return
    if(size < 1) return;          // Nothing to do if the string is size 0, return

    // LOCAL MEMORY
    unsigned int master = 0;          // Used to keep track where in the string we are reading
    unsigned int pull = 0;            // Used to rewrite chars farther to the right when inserting a new_chars replacement
    unsigned int new_chars_size = 0;  // Size of the new string to replace spaces
    unsigned int new_char_insert = 0; // Used to insert into string
    const char* new_char_reader;      // Used to read the new_chars string
    unsigned int temp = 0;            // Used to shift each char new_chars_size spaces to the right

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
            while(strcmp(new_char_reader, "\0") != 0){      // While we read each char in new_chars,
                string[new_char_insert] = *new_char_reader; // Write into string
                new_char_reader++;                          // Advance pointer
                new_char_insert++;
            }
        }
    }

    return;
}

bool palindrome_permutation(const char* string){
/*
ASSUMPTION: string has a '\0' char in it to stop the while loops.
bool palindrome_permutation:
    Checks if string can be permutated into any palindrome. The permutated palindrome does not have to be a valid
    English phrase.

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
bool boolean_result = palindrome_permutation(buffer);
if(boolean_result == True){
    printf("Palindrome Permutations possible.\n\n");
}else{
    printf("Palindrome Permutations impossible.\n\n");
}

*/

    // CHECKS
    if(string == NULL) return False; // If no string was given, return

    // LOCAL MEMORY
    bool result                   = True;   // Assume we can create a palindrome permutation
    const char* string_reader     = string; // Read string from start
    unsigned short frequency[CHAR_TABLE] = {0};    // Used to count the frequency of printable ASCII characters
    unsigned int counter          = 0;      // Used to step through the frequency table
    bool even_chars               = True;   // Checks if there is an even number of chars in string, assume True
    unsigned int string_length    = 0;      // How many chars in string
    bool single_frequency         = False;  // Used to signal if a char with single frequency was already encountered

    printf("%s\n", string);

    // Build frequency table
    while(strcmp(string_reader, "\0") != 0){
        if(isspace(*string_reader)){ // Do not count spaces
            string_reader++;
            continue;
        }
        if(frequency[*string_reader] < 1){
            frequency[*string_reader]++; // Account for the frequency of that character
        }else{
            frequency[*string_reader]--; // Consume that count
        }
        string_reader++;                 // Advance pointer
        string_length++;                 // Increase the length of the string
    }

    if(string_length % 2 == 0) even_chars = False; // If there are odd total chars

    ////////////////////////////////////////////////////////////////
    // We have assumed that string has valid palindrome permutations.
    // There are two cases we must check to refute that.
    ////////////////////////////////////////////////////////////////
    for(counter = 0; counter < CHAR_TABLE; counter++){
        if((frequency[counter] == 1) && (single_frequency == False)){
            single_frequency = True;
            continue;
        }

        // We cannot have a char with a frequency of 1 if there are even chars in string
        if((frequency[counter] == 1) && (even_chars == True)){
            result = False;
            break;
        }

        // We cannot find more than one char to be a frequency of 1 in odd strings
        if((frequency[counter] == 1) && (single_frequency == True)){
            result = False;
            break;
        }
    }

    return result;
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

is_stream_at_EOF = write_to_buffer(current_test_input, buffer, MAX_BUFFER_SIZE, NULL, " ");
is_stream_at_EOF = write_to_buffer(current_test_input, right_string, MAX_BUFFER_SIZE, NULL, " ");
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
    bool one_difference_found                   = False; // Tracks if at least one difference was found
    bool result                                 = True;  // Assumed to be True

    // CHECKS
    if(abs(original_length - string_length) > 1) return False; // If either string is longer than 1 char than the other

    printf("%s %s\n", original, string);

    if(original_length - string_length == 1){ // Check if we are inserting
        for(original_reader = 0, string_reader = 0; string_reader < string_length; original_reader++, string_reader++){
            if((one_difference_found == True) && (original[original_reader] != string[string_reader]))
                return False; // If we find more than one difference

            if((one_difference_found == False) && (original[original_reader] != string[string_reader])){
                original_reader++;
                one_difference_found = True;
            }
        }
    }else if(original_length - string_length == -1){ // Check if we are removing
        for(original_reader = 0, string_reader = 0; original_reader < original_length; original_reader++, string_reader++){
            if((one_difference_found == True) && (original[original_reader] != string[string_reader]))
                return False; // If we find more than one difference

            if((one_difference_found == False) && (original[original_reader] != string[string_reader])){
                string_reader++;
                one_difference_found = True;
            }
        }
    }else if(original_length == string_length){ // Check if we are replacing
        for(original_reader = 0, string_reader = 0; string_reader < string_length; original_reader++, string_reader++){
            if((one_difference_found == True) && (original[original_reader] != string[string_reader]))
                return False; // If we find more than one difference

            if((one_difference_found == False) && (original[original_reader] != string[string_reader])){
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
    bool too_long                          = False; // Checks if the new string is longer than the original
    unsigned int string_length             = length_of_string(string); // Get the length of the string
    unsigned int insert                    = 0;   // Insert into the compressed string
    unsigned int reader                    = 0;   // Step through string
    unsigned int frequency                 = 0;   // Tracks the frequency of a char
    unsigned int int_length                = 0;   // Lenght of the integer as a string
    unsigned int int_counter               = 0;   // Steps through the length of the int as a string
    char int_as_string[MAX_BUFFER_SIZE]    = {0}; // String representation of an int

    // DYNAMIC MEMORY
    char* compressed_string = (char*) malloc(sizeof(char) * string_length); // Compressed string
    set_string_to_null(compressed_string, sizeof(char) * string_length);

    printf("%s\n", string);

    for(reader; reader < string_length;){
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

        for(int_counter = 0; int_counter < int_length; int_counter++){ // Advance inserter the length of the frequency as a string
            insert++;
            // If in the generation of the compressed string, we discover the new string will be longer, return string
            if(insert > string_length){
                compressed_string = NULL;
                free(compressed_string);
                return string;
            }
        }
        set_string_to_null(int_as_string, MAX_BUFFER_SIZE); // Reset int_as_string to null to reuse
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
    unsigned int total_range = sizeof(matrix[0]);

    for(row = 0; row < total_range; row++){
        for(column = 0; total_range; column++){
            printf("%c", matrix[row + column]);
        }
    }

    return;
}
