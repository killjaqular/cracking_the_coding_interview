/*
Adonay Pichardo, adonaypichardo@gmail.com

@file
adopic.h

@description
Custom structures and functions

*/

// STANDARD LIBRARIES
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// MACROS
#define DEFAULT_BUFFER 128 //used as a DEFAULT_buffer for reading string input from stdin
#define True 1 //used as a boolean True value
#define False 0 //used as a boolean False value

// GLOBAL VARIABLES
// none

//STRUCTURES
// the following structures contain single pointer nodes for all of C's primitive data types:
// char
// signed char
// unsigned char
// short
// short int
// signed short
// signed short int
// int
// signed
// signed int
// unsigned
// unsigned int
// long
// long int
// signed long
// signed long int
// unsigned long
// unsigned long int
// long long
// long long int
// signed long long
// signed long long int
// unsigned long long
// unsigned long long int
// float
// double
// long double

typedef struct char_single_Node{
    // Smallest addressable unit of the machine that can contain basic character set.
    // It is an integer type. Actual type can be either signed or unsigned. It contains CHAR_BIT bits.

    char element;
    struct char_single_Node *previous;
    struct char_single_Node *next;
}CHAR_SINGLE_NODE_t;

typedef struct signed_char_single_Node{
    // Of the same size as char, but guaranteed to be signed. Capable of containing at least the [−127, +127] range

    signed char element;
    struct signed_char_single_Node *previous;
    struct signed_char_single_Node *next;
}SIGNED_CHAR_NODE_t;

typedef struct unsigned_char_single_Node{
    // Of the same size as char, but guaranteed to be unsigned. Contains at least the [0, 255] range.

    unsigned char element;
    struct unsigned_char_single_Node *previous;
    struct unsigned_char_single_Node *next;
}UNSIGNED_CHAR_NODE_t;

typedef struct short_Node{
    // Short signed integer type. Capable of containing at least the [−32,767, +32,767] range.
    // Thus, it is at least 16 bits in size. The negative value is −32767 (not −32768) due to the
    // one's-complement and sign-magnitude representations allowed by the standard, though the
    // two's-complement representation is much more common.

    short element;
    struct short_single_Node *previous;
    struct short_single_Node *next;
}SHORT_SINGLE_NODE_t;

typedef struct short_int_single_Node{
    // Short signed integer type. Capable of containing at least the [−32,767, +32,767] range.
    // Thus, it is at least 16 bits in size. The negative value is −32767 (not −32768) due to the
    // one's-complement and sign-magnitude representations allowed by the standard, though the
    // two's-complement representation is much more common.

    short int element;
    struct short_int_single_Node *previous;
    struct short_int_single_Node *next;
}SHORT_INT_SINGLE_NODE_t;

typedef struct signed_short_single_Node{
    // Short signed integer type. Capable of containing at least the [−32,767, +32,767] range.
    // Thus, it is at least 16 bits in size. The negative value is −32767 (not −32768) due to the
    // one's-complement and sign-magnitude representations allowed by the standard, though the
    // two's-complement representation is much more common.

    signed short element;
    struct signed_short_single_Node *previous;
    struct signed_short_single_Node *next;
}SIGNED_SHORT_SINGLE_NODE_t;

typedef struct signed_short_int_single_Node{
    // Short signed integer type. Capable of containing at least the [−32,767, +32,767] range.
    // Thus, it is at least 16 bits in size. The negative value is −32767 (not −32768) due to the
    // one's-complement and sign-magnitude representations allowed by the standard, though the
    // two's-complement representation is much more common.

    signed short int element;
    struct signed_short_int_single_Node *previous;
    struct signed_short_int_single_Node *next;
}SIGNED_SHORT_INT_SINGLE_NODE_t;

typedef struct unsigned_short_single_Node{
    // Short unsigned integer type. Contains at least the [0, 65,535] range.

    unsigned short element;
    struct unsigned_short_single_Node *previous;
    struct unsigned_short_single_Node *next;
}UNSIGNED_SHORT_SINGLE_NODE_t;

typedef struct unsigned_short_int_single_Node{
    // Short unsigned integer type. Contains at least the [0, 65,535] range.

    unsigned short int element;
    struct unsigned_short_int_single_Node *previous;
    struct unsigned_short_int_single_Node *next;
}UNSIGNED_SHORT_INT_SINGLE_NODE_t;

typedef struct int_single_Node{
    // Basic signed integer type. Capable of containing at least the [−32,767, +32,767] range;
    // thus, it is at least 16 bits in size.

    int element;
    struct int_single_Node *previous;
    struct int_single_Node *next;
}INT_SINGLE_NODE_t;

typedef struct signed_single_Node{
    // Basic signed integer type. Capable of containing at least the [−32,767, +32,767] range;
    // thus, it is at least 16 bits in size.

    signed element;
    struct signed_single_Node *previous;
    struct signed_single_Node *next;
}SIGNED_SINGLE_NODE_t;

typedef struct signed_int_single_Node{
    // Basic signed integer type. Capable of containing at least the [−32,767, +32,767] range;
    // thus, it is at least 16 bits in size.

    signed int element;
    struct signed_int_single_Node *previous;
    struct signed_int_single_Node *next;
}SIGNED_INT_NODE_t;

typedef struct unsigned_single_Node{
    // Basic unsigned integer type. Contains at least the [0, 65,535] range;

    unsigned element;
    struct unsigned_single_Node *previous;
    struct unsigned_single_Node *next;
}UNSIGNED_SINGLE_NODE_t;

typedef struct unsigned_int_single_Node{
    // Basic unsigned integer type. Contains at least the [0, 65,535] range;

    unsigned int element;
    struct unsigned_int_single_Node *previous;
    struct unsigned_int_single_Node *next;
}UNSIGNED_INT_SINGLE_NODE_t;

typedef struct long_single_Node{
    // Long signed integer type. Capable of containing at least the [−2,147,483,647,
    // +2,147,483,647] range; thus, it is at least 32 bits in size.

    long element;
    struct long_single_Node *previous;
    struct long_single_Node *next;
}LONG_SINGLE_NODE_t;

typedef struct long_int_single_Node{
    // Long signed integer type. Capable of containing at least the [−2,147,483,647,
    // +2,147,483,647] range; thus, it is at least 32 bits in size.

    long int element;
    struct long_int_single_Node *previous;
    struct long_int_single_Node *next;
}LONG_INT_SINGLE_NODE_t;

typedef struct signed_long_single_Node{
    // Long signed integer type. Capable of containing at least the [−2,147,483,647,
    // +2,147,483,647] range; thus, it is at least 32 bits in size.

    signed long element;
    struct signed_long_single_Node *previous;
    struct signed_long_single_Node *next;
}SIGNED_LONG_SINGLE_NODE_t;

typedef struct signed_long_int_single_Node{
    // Long signed integer type. Capable of containing at least the [−2,147,483,647,
    // +2,147,483,647] range; thus, it is at least 32 bits in size.

    signed long int element;
    struct signed_long_int_single_Node *previous;
    struct signed_long_int_single_Node *next;
}SIGNED_LONG_INT_SINGLE_NODE_t;

typedef struct unsigned_long_single_Node{
    // Long unsigned integer type. Capable of containing at least the [0, 4,294,967,295] range;

    unsigned long element;
    struct unsigned_long_single_Node *previous;
    struct unsigned_long_single_Node *next;
}UNSIGNED_LONG_SINGLE_NODE_t;

typedef struct unsigned_long_int_single_Node{
    // Long unsigned integer type. Capable of containing at least the [0, 4,294,967,295] range;

    unsigned long int element;
    struct unsigned_long_int_single_Node *previous;
    struct unsigned_long_int_single_Node *next;
}UNSIGNED_LONG_INT_SINGLE_NODE_t;

typedef struct long_long_single_Node{
    // Long long signed integer type. Capable of containing at least the [−9,223,372,036,854,775,807,
    // +9,223,372,036,854,775,807] range; thus, it is at least 64 bits in size. Specified
    // since the C99 version of the standard.

    long long element;
    struct long_long_single_Node *previous;
    struct long_long_single_Node *next;
}LONG_LONG_SINGLE_NODE_t;

typedef struct long_long_int_single_Node{
    // Long long signed integer type. Capable of containing at least the [−9,223,372,036,854,775,807,
    // +9,223,372,036,854,775,807] range; thus, it is at least 64 bits in size. Specified
    // since the C99 version of the standard.

    long long int element;
    struct long_long_int_single_Node *previous;
    struct long_long_int_single_Node *next;
}LONG_LONG_INT_SINGLE_NODE_t;

typedef struct signed_long_long_single_Node{
    // Long long signed integer type. Capable of containing at least the [−9,223,372,036,854,775,807,
    // +9,223,372,036,854,775,807] range; thus, it is at least 64 bits in size. Specified
    // since the C99 version of the standard.

    signed long long element;
    struct signed_long_long_single_Node *previous;
    struct signed_long_long_single_Node *next;
}SIGNED_LONG_LONG_SINGLE_NODE_t;

typedef struct signed_long_long_int_single_Node{
    // Long long signed integer type. Capable of containing at least the [−9,223,372,036,854,775,807,
    // +9,223,372,036,854,775,807] range; thus, it is at least 64 bits in size. Specified
    // since the C99 version of the standard.

    signed long long int element;
    struct signed_long_long_int_single_Node *previous;
    struct signed_long_long_int_single_Node *next;
}SIGNED_LONG_LONG_INT_SINGLE_NODE_t;

typedef struct unsigned_long_long_single_Node{
    // Long long unsigned integer type. Contains at least the [0, +18,446,744,073,709,551,615] range;
    // Specified since the C99 version of the standard.

    unsigned long long element;
    struct unsigned_long_long_single_Node *previous;
    struct unsigned_long_long_single_Node *next;
}UNSIGNED_LONG_LONG_SINGLE_NODE_t;

typedef struct unsigned_long_long_int_single_Node{
    // Long long unsigned integer type. Contains at least the [0, +18,446,744,073,709,551,615] range;
    // Specified since the C99 version of the standard.

    unsigned long long int element;
    struct unsigned_long_long_int_single_Node *previous;
    struct unsigned_long_long_int_single_Node *next;
}UNSIGNED_LONG_LONG_INT_SINGLE_NODE_t;

typedef struct float_single_Node{
    // Real floating-point type, usually referred to as a single-precision floating-point type.
    // Actual properties unspecified (except minimum limits), however on most systems this is
    // the IEEE 754 single-precision binary floating-point format (32 bits). This format is required
    // by the optional Annex F "IEC 60559 floating-point arithmetic".

    float element;
    struct float_single_Node *previous;
    struct float_single_Node *next;
}FLOAT_SINGLE_NODE_t;

typedef struct double_single_Node{
    // Real floating-point type, usually referred to as a double-precision floating-point type.
    // Actual properties unspecified (except minimum limits), however on most systems this is
    // the IEEE 754 double-precision binary floating-point format (64 bits). This format is required
    // by the optional Annex F "IEC 60559 floating-point arithmetic".

    double element;
    struct double_single_Node *previous;
    struct double_single_Node *next;
}DOUBLE_SINGLE_NODE_t;

typedef struct long_double_single_Node{
    // Real floating-point type, usually mapped to an extended precision floating-point number format.
    // Actual properties unspecified. It can be either x86 extended-precision floating-point format
    // (80 bits, but typically 96 bits or 128 bits in memory with padding bytes), the non-IEEE "double-double"
    // (128 bits), IEEE 754 quadruple-precision floating-point format (128 bits), or the same as double.
    // See the article on long double for details.

    long double element;
    struct long_double_single_Node *previous;
    struct long_double_single_Node *next;
}LONG_DOUBLE_SINGLE_NODE_t;

// DEFINITIONS

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//STRING MANAGEMENT
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool is_string_empty(char* string){
/*
bool is_string_empty:
    Checks if string is empty.

Input:
    char* string:
        The string to be checked.

Output:
    bool result:
        True if string is empty, False otherwise.

Example Usage:

bool is_empty = False;
is_string_empty = is_string_empty(some_string_pointer);

*/

    // LOCAL MEMORY
    bool result = False;

    if((string == NULL) || (*string == EOF) || (*string == '\0') || (*string == '\n')) result = True;

    return result;
}

unsigned int length_of_string(char *string){
/*
ASSUMPTION: string has a '\0' char in it to stop the while loops.
unsigned int length_of_string:
    Returns the total number of chars in string before '\0' or '\n'

Input:
    char* string:
        The string to be measured.

Output:
    unsigned int size:
        The size of string.

Example Usage:

char buffer[256] = "\0";
// Write something into buffer
unsigned int size_of_string = length_of_string(buffer);

*/

    if(is_string_empty(string)) return 0;

    // LOCAL MEMORY
    char *original_string_reader = string;
    unsigned int size = 0;

    while((*original_string_reader != '\0') && (*original_string_reader != '\n')){
        ++size;
        ++original_string_reader; // Advance the original_string_reader
    }

    return size;
}

bool find_char(char *string, char target_char){
/*
bool find_char:
    Checks if target_char is in string.

Input:
    char* string:
        The string to be read.

    char target_char:
        The char to search for.

Output:
    bool result:
        True if target_char is found in string, else False.

Example Usage:

bool char_found = False;
char_found = find_char(some_string_pointer, "X");

*/

    // LOCAL MEMORY
    char *original_string_reader = string; // Pointer used to read string
    bool result = False; // Assume target_char is not in string

    while((*original_string_reader != '\0') && (*original_string_reader != '\n')){ // While original_string_reader is no at the end of string
        if(*original_string_reader == target_char){ // If original_string_reader == target_char
            result = True; // Target_char is in the given string
            break; // Break out of the loop, no need to continue to search
        }else{
            ++original_string_reader; // Advance the original_string_reader
        }
    }

    return False;
}

unsigned int find_char_first_index(char* string, char target_char){
/*
unsigned int find_char_first_index:
    Returns -1 if not found or the position of the first instance of target_char.

Input:
    char* string:
        The string to be read.

    char target_char:
        The char to search for.

Output:
    int position:
        The index of the first char found or -1 if not found.
*/

    if(is_string_empty(string) == True) return -1;
    if(find_char(string, target_char) == False) return -1;

    // LOCAL MEMORY
    char *original_string_reader = string;
    int position = 0;

    while((*original_string_reader != '\0') && (*original_string_reader != '\n')){
        if(*original_string_reader == target_char) break; // If we find the target_char, stop search
        ++position;
        ++original_string_reader; // Advance the original_string_reader
    }

    return position;
}

char* insert_null_char(char* string){
/*
char* insert_null_char:
    Inserts '\0' at the end of string.

Input:
    char* string:
        The string to be read.

Output:
    char* new_string:
        The string with '\0' inserted.

Example Usage:

char buffer[256] = "\0";
// Write something into buffer
char *new_string;
new_string = insert_null_char(buffer);

*/

    if(is_string_empty(string)) return NULL; // If *string is empty, return NULL

    // LOCAL MEMORY
    unsigned int length_of_original = length_of_string(string);
    char *new_string = (char*) malloc(sizeof(char) * length_of_original); // Reserve memory for new_string
    char *string_reader = string;
    char *new_string_reader = new_string;

    strcpy(new_string, string);

    while((*string_reader != '\0') && (*string_reader != '\n') && (*string_reader != '\r') && (*string_reader != EOF)){ // While the string has valid chars
        ++string_reader; // Advance pointer
        ++new_string_reader; // Advance pointer
    }

    *new_string_reader = '\0'; // Insert '\0' char

    return new_string;
}

char* copy_first_word(char* string){
/*
char* copy_first_word:
    Copies all chars in string until first ' ', NULL, or '\0' char is found.

Input:
    char* string:
        The string to be read.

Output:
    char* new_string:
        The string converted to lowercase.

Example Usage:

char *new_string;
// Write something into new_string
char *first_word;
first_word = copy_first_word(new_string);

*/

    if(is_string_empty(string) == True) return NULL; // If *string is empty, return NULL

    // LOCAL MEMORY
    int length_of_original = length_of_string(string);
    char target_char[2];
    strcpy(target_char, " ");
    unsigned int position_of_first_space = find_char_first_index(string, target_char[0]);
    char *new_string = (char*) malloc(sizeof(char) * (position_of_first_space + 1)); // Reserve memory for new_string
    char *original_string_reader = string; // Used to read the original string
    char *new_string_reader = new_string; // Used to insert into the new_string

    while((*original_string_reader != ' ') && (original_string_reader != NULL) && (*original_string_reader != '\0')){ // While there are chars to read from the original string,
        *new_string_reader = *original_string_reader; // Insert into new_string the char of string
        ++original_string_reader; // Advance the reader
        ++new_string_reader; // Advance the inserter
    }

    *new_string_reader = '\0'; // Insert NULL char at end

    return new_string;
}

char* string_to_lowercase(char* string){
/*
char* string_to_lowercase:
    Converts all chars in string to lowercase

Input:
    char* string:
        The string to be changed to lowercase.

Output:
    char* new_string:
        The string converted to lowercase.

Example Usage:

char *new_string;
// Write something into new_string
char *lowercase;
lowercase = string_to_lowercase(new_string);

*/

    if(is_string_empty(string)) return NULL; // If *string is empty, return NULL

    // LOCAL MEMORY
    int length_of_original = length_of_string(string);
    char *new_string = (char*) malloc(sizeof(char) * length_of_original); // Reserve memory for new_string
    char *original_string_reader = string; // Used to read the original string
    char *new_string_reader = new_string; // Used to insert into the new_string

    while((original_string_reader != NULL) && (*original_string_reader != '\0')){ // While there are chars to read from the original string,
        *new_string_reader = tolower(*original_string_reader); // Insert into new_string the lowercase char of string
        ++original_string_reader; // Advance the reader
        ++new_string_reader; // Advance the inserter
    }

    return new_string;
}

char* string_to_uppercase(char* string){
/*
char* string_to_uppercase:
    Converts all chars in string to uppercase

Input:
    char* string:
        The string to be changed to uppercase.

Output:
    char* new_string:
        The string converted to uppercase.

Example Usage:

char *new_string;
// Write something into new_string
char *uppercase;
uppercase = string_to_uppercase(new_string);

*/

    if(is_string_empty(string)) return NULL; // If *string is empty, return NULL

    // LOCAL MEMORY
    int length_of_original = length_of_string(string);
    char *new_string = (char*) malloc(sizeof(char) * length_of_original); // Reserve memory for new_string
    char *original_string_reader = string; // Used to read the original string
    char *new_string_reader = new_string; // Used to insert into the new_string

    while((original_string_reader != NULL) && (*original_string_reader != '\0')){ // While there are chars to read from the original string,
        *new_string_reader = toupper(*original_string_reader); // Insert into new_string the lowercase char of string
        ++original_string_reader; // Advance the reader
        ++new_string_reader; // Advance the inserter
    }

    return new_string;
}

void set_string_to_null(char string[], unsigned int size){
/*
void set_string_to_null:
    Set all chars in string to NULL.

Input:
    char string[]:
        The string to set to NULL.
    unsigned int size:
        The size of string.

Output: None

Example Usage:

unsigned int SIZE = 100;
char string[STRING_SIZE];
// Write something into new_string
string_to_uppercase(string, STRING_SIZE);

*/

    unsigned int counter; // Used to step through string
    for(counter = 0;counter < size; counter++){
        string[counter] = 0;
    }

    return;
}

bool write_to_string(FILE* input, char buffer[], unsigned int size, char *start_delimiter, char *end_delimiter){
/*
bool write_to_string:
    Reads from input file pointer and writes into buffer from the start of input until the first of these are found:
        end_delimiter, reached maximum size of buffer, EOF.

Input:
    FILE* input:
        The current position of the file pointer to read from.
    char buffer[]:
        The string to write into.
    unsigned int size:
        The maximum size of buffer.
    char start_delimiter:
        Used to start writing into buffer.
    char end_delimiter:
        Used to stop writing into buffer.

Output:
    bool reached_EOF:
        True if input is ever at EOF.

Example Usage:

bool is_stream_at_EOF  = False;
unsigned int SIZE      = 100;
char char_array[SIZE]  = {0};
char delimiter[2]      = '"\0'; // Used to splice the input file
FILE* input = fopen("somefile.txt", "r");

while(is_stream_at_EOF == False){
    is_stream_at_EOF = write_to_string(input, char_array, SIZE, delimiter, delimiter);
    printf("%s\n", char_array);   
}

*/

    // LOCAL MEMORY
    int reader          = 0;     // Steps through the input file
    char as_char[2]     = {0};   // Used to cast the read int as a char for comparison
    unsigned int insert = 0;     // Used to insert into buffer
    bool read_newline   = False; // Flag for reading newlines
    bool reached_EOF    = False; // Flag to determine if EOF was reached reading input

    if(input == NULL) return True; // If input stream is empty, return True

    ////////////////////////////////////////////////////////////////
    // If we were given a start_delimiter, search for it and advance input to the start_delimiter
    ////////////////////////////////////////////////////////////////
    if(start_delimiter != NULL){       // Advance stream to the first start_delimiter found
        while((strcmp(as_char, start_delimiter) != 0) && (reader != EOF)){
            reader = getc(input);      // Grab a new char from stream
            as_char[0] = (char)reader; // Change it into a char for comparison
        }

        if(reader == EOF) return True; // No start_delimiter found, do not write anything

        buffer[insert] = reader; // Write the start_delimiter into buffer
        insert++;                // Increment inserter
    }

    ////////////////////////////////////////////////////////////////
    // If we were NOT given an end_delimiter, read every char available into buffer with respect to its size
    ////////////////////////////////////////////////////////////////
    if(end_delimiter == NULL){         // If we were not given an explicit end_delimiter,
        while((reader != EOF) && (insert < size)){
            reader = getc(input);      // Grab a new char from stream
            as_char[0] = (char)reader; // Change it into a char for comparison

            // Ignore all newlines if end_delimiter is not explicitly "\n"
            if(strcmp(as_char, "\n") == 0){
                while((strcmp(as_char, "\n") == 0) && (reader != EOF)){
                    reader = getc(input);      // Grab a new char from stream
                    as_char[0] = (char)reader; // Change it into a char for comparison
                }

                if(reader == EOF) return True; // If we reached EOF

                if(insert != 0){
                    strcpy(&buffer[insert], " "); // Write into buffer
                    insert++;                     // Increment inserter
                }
            }
        }

        if(reader == EOF) return True;   // If we reached EOF
        if(insert >= size) return False; // If we maxed out buffer
    }

    ////////////////////////////////////////////////////////////////
    // Read everything else into buffer with respect to EOF and buffer's size
    // We will stop one short of the last char in buffer, that last position will be overwritten with a "\0" if we 
    // write size chars into buffer. In any other case, we will write a "\0" after the last char is inserted into
    // buffer.
    ////////////////////////////////////////////////////////////////
    while((reader != EOF) && (insert < size - 1)){ // While we haven't reached end of file or size of buffer
        reader = getc(input);                      // Grab a new char from stream
        as_char[0] = (char)reader;                 // Cast it into a char for comparison

        // Ignore all newlines if end_delimiter is not explicitly "\n"
        if((strcmp(as_char, "\n") == 0) && (strcmp(end_delimiter, "\n") != 0)){
            while((strcmp(as_char, "\n") == 0) && (reader != EOF)){
                reader = getc(input);      // Grab a new char from stream
                as_char[0] = (char)reader; // Change it into a char for comparison
            }

            if(reader == EOF){
                reached_EOF = True; // Flip flag
                break;              // No start_delimiter found, do not write anything
            }

            if(insert != 0){
                strcpy(&buffer[insert], " "); // Write into buffer
                insert++;                     // Increment inserter
            }
        }

        if(end_delimiter != NULL){
            if(strcmp(as_char, end_delimiter) == 0){
                if(strcmp(end_delimiter, "\n") != 0){
                    buffer[insert] = reader; // Write into buffer
                    insert++;                // Increment inserter
                }
                break;                       // Stop reading and writing
            }
        }else if(insert + 1 == size){// If we have filled the buffer
            break;                   // Stop reading and writting
        }

        buffer[insert] = reader; // Write into buffer
        insert++;                // Increment inserter
    }

    buffer[insert] = 0;

    if(reader == EOF) reached_EOF = True; // If we reached EOF

    return reached_EOF;
}

// TODO: Finish this function
void replace_char_new_string(char* original_string, char* target_char, char new_string[], unsigned int new_string_size, char* new_char){
/*
void replace_char_new_string:
    Replaces all instances of target_char in original_string with new_char making new_string

Input:
    char* original_string:
        The original string.
        ASSUMPTION: This string must be terminated with '\0'.
    char* target_char:
        The char to replace in original_string.
    char new_string[]:
        A new string with target_char replaced with new_char.
    unsigned int new_string_size:
        The size of new_string.
    char* new_char:
        The char to replace target_char in new_string.

Output: None

Example Usage:

unsigned int SIZE = 100;
unsigned int NEW_SIZE = 200;
char old_string[SIZE] = {0};
char new_string[NEW_SIZE] = {0};
// Write into old_string
// Write into new_string
char target_char[2] = " \0";

*/

    // LOCAL MEMORY
    unsigned int insert;

    // TODO: finish this boi

    return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//COMMAND LINE ARGUMENT MANAGEMENT
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct program_arguments{
    // Used to contain information about the arguments passed to the program
    unsigned int argument_total_count;
    char **arguments;
}PROGRAM_ARGUMENTS_t;

bool verify_argc(char argc, char *argv[]){
/*
bool verify_argc:
    Checks if argc has more than one argument, the first argument is always the name of the program

Input:
    char argc:
        The total count of arguments passed.

    char *argv[]:
        Used to print the name of the calling program.

Output:
    bool result:
        True or False.

Example Usage:
int main(int argc, char** argv){

    bool successful = False;
    successful = verify_argc(argc, argv);

    return 0;
}
*/

    // LOCAL MEMORY
    bool result = True;

    if(argc == 1){
        printf("\nERROR:_> FROM:_> verify_argc:_> PLEASE PROVIDE AN INPUT FILE VIA argv, FOR EXAMPLE 'USER$ %s FIRST_INPUT_file.txt'.\n", argv[0]);
        result = False;
    }

    return result;
}

bool verify_argv(char *argv[]){
/*
bool verify_argv:
    Checks if argv is NULL

Input:
    char *argv[]:
        The pointer to a program's arguments.

Output:
    bool result:
        True or False.

Example Usage:
int main(int argc, char** argv){

    bool successful = False;
    successful = verify_argv(argv);

    return 0;
}
*/

    // LOCAL MEMORY
    bool result = True;

    if(argv == NULL){ //if argv is empty,
        printf("\nERROR:_> FROM:_> verify_argv:_> PLEASE PROVIDE AN INPUT FILE VIA argv, FOR EXAMPLE 'USER$ %s FIRST_INPUT_file.txt'. EXITING PROGRAM.\n", argv[0]);
        result = False;
    }

    return result;
}

FILE* verify_file_stream_pointer(char *file_name){
/*
FILE* verify_file_stream_pointer:
    checks if file stream pointer exists, returns a file pointer if it does, exits the program otherwise

Input:
    char *file_name:
        The name of the file to be opened.
Output:
    FILE* FILE_STREAM:
        The file stream that was successfully opened.

Example Usage:
int main(int argc, char** argv){

    FILE* file_stream = NULL;
    file_stream = verify_file_stream_pointer(argv[1]);
    if(file_stream != NULL) successful = True;
    int reader;
    char buffer[256] = "\0";
    unsigned int counter = 0;
    if(successful){
        while((reader = getc(file_stream)) != EOF){
            putchar(reader);
            buffer[counter] = reader;
            counter++;
        }
    }
    fclose(file_stream);

    return 0;
}
*/

    // LOCAL MEMORY
    // None

    FILE *FILE_STREAM = fopen(file_name, "r"); // Opens a file in read only and returns a pointer to that file, otherwise returns NULL pointer

    if(FILE_STREAM == NULL){ // If FILE_STREAM is NULL,
        printf("\nERROR:_> FROM:_> verify_file_stream_pointer:_> %s WAS NOT FOUND.\n", file_name);
        fclose(FILE_STREAM); // Close FILE_STREAM stream
    }else if(getc(FILE_STREAM) == EOF){ // If FILE_STREAM is empty
        printf("\nERROR:_> FROM:_> verify_file_stream_pointer:_> %s IS EMPTY.\n", file_name);
        fclose(FILE_STREAM); // Close FILE_STREAM stream
    }else{ //otherwise,
        rewind(FILE_STREAM); // Place DEFAULT_buffer to the beginning of FILE_STREAM pointer
    }

    return FILE_STREAM;
}

bool print_all_argv(PROGRAM_ARGUMENTS_t* given_program_arguments){
/*
bool print_all_argv:
    Prints all arguments passed to program.

Input:
    PROGRAM_ARGUMENTS_t* given_program_arguments:
        Contains all arguments passed to program.

Output:
    bool True:
        Returns 1 if execution was successful.

Example Usage:
int main(int argc, char** argv){

    // DYNAMIC MEMORY
    PROGRAM_ARGUMENTS_t* program_arguments;
    program_arguments = init_PROGRAM_ARGUMENTS();

    set_PROGRAM_ARGUMENTS(program_arguments, argc, argv);
    successful = print_all_argv(program_arguments);
    if(successful){
        printf("print_all_argv executed successfully.\n");
    }
    successful = False;

    return 0;
}
*/

    // LOCAL MEMORY
    unsigned int arg_counter;

    printf("Arguments passed to %s\n", given_program_arguments->arguments[0]);

    for(arg_counter = 1; arg_counter < given_program_arguments->argument_total_count; arg_counter++){
        printf("%s \n", given_program_arguments->arguments[arg_counter]);
    }
    printf("\n");

    return True;
}

PROGRAM_ARGUMENTS_t* init_PROGRAM_ARGUMENTS(){
/*
PROGRAM_ARGUMENTS_t* init_PROGRAM_ARGUMENTS:
    Initializes a PROGRAM_ARGUMENTS_t structure.

Input: void

Output:
    PROGRAM_ARGUMENTS_t* new_PROGRAM_ARGUMENTS:
        A malloced PROGRAM_ARGUMENTS_t structure.

Example Usage:
int main(int argc, char** argv){

    // DYNAMIC MEMORY
    PROGRAM_ARGUMENTS_t* program_arguments;
    program_arguments = init_PROGRAM_ARGUMENTS();

    return 0;
}
*/

    // LOCAL MEMORY
    // None

    PROGRAM_ARGUMENTS_t* new_PROGRAM_ARGUMENTS = (PROGRAM_ARGUMENTS_t*) malloc(sizeof(PROGRAM_ARGUMENTS_t));

    return new_PROGRAM_ARGUMENTS;
}

void set_PROGRAM_ARGUMENTS(PROGRAM_ARGUMENTS_t* program_arguments, unsigned int argc, char** argv){
/*
void set_PROGRAM_ARGUMENTS:
    Uses argc and argv to set the values in program_arguments

Input:
    PROGRAM_ARGUMENTS_t* program_arguments:
        Will contain argc and argv values.
    unsigned int argc:
        Total number of arguments passed to the program.
    char** argv:
        The arguments passed to the program.

Output: PROGRAM_ARGUMENTS_t* new_PROGRAM_ARGUMENTS:
        A malloced PROGRAM_ARGUMENTS_t structure.

Example Usage:
int main(int argc, char** argv){

    // DYNAMIC MEMORY
    PROGRAM_ARGUMENTS_t* program_arguments;
    program_arguments = init_PROGRAM_ARGUMENTS();

    set_PROGRAM_ARGUMENTS(program_arguments, argc, argv);

    return 0;
}
*/

    // LOCAL MEMORY
    // None

    program_arguments->argument_total_count = argc;
    program_arguments->arguments = argv;

    return;
}

bool free_PROGRAM_ARGUMENTS(PROGRAM_ARGUMENTS_t** program_arguments){
/*
bool free_PROGRAM_ARGUMENTS:
    Frees memory reserved by program_arguments and sets to NULL for safety.

Input:
    PROGRAM_ARGUMENTS_t* program_arguments:
        The PROGRAM_ARGUMENTS_t structure to delete.

Output:
    bool True:
        Returns 1 if execution was successful.

Example Usage:
int main(int argc, char** argv){

    // LOCAL MEMORY
    bool successful = False;

    // DYNAMIC MEMORY
    PROGRAM_ARGUMENTS_t* program_arguments;
    program_arguments = init_PROGRAM_ARGUMENTS();

    successful = free_PROGRAM_ARGUMENTS(&program_arguments);
    if(program_arguments == NULL && successful == True){
        printf("Freed a PROGRAM_ARGUMENTS_t structure.\n");
    }

    return 0;
}
*/

    // LOCAL MEMORY
    // None

    (*program_arguments)->argument_total_count = 0;
    (*program_arguments)->arguments = 0;
    (*program_arguments) = NULL;
    free((*program_arguments));

    return True;
}
