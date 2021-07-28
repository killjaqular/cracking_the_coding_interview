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
//STRING MAINTENANCE//STRING MAINTENANCE//STRING MAINTENANCE//STRING MAINTENANCE//STRING MAINTENANCE//STRING MAINTENANC
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
*/

    // LOCAL MEMORY
    bool result = False;

    if((string == NULL) || (*string == EOF) || (*string == '\0') || (*string == '\n')) result = True;

    return result;
}

unsigned int length_of_string(char *string){
/*
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

//VERIFY ARGV//VERIFY ARGV//VERIFY ARGV//VERIFY ARGV//VERIFY ARGV//VERIFY ARGV//VERIFY ARGV//VERIFY ARGV//VERIFY ARGV//
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
