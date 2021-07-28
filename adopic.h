// adonay_pichardo_library
// adopic.h contains custom structures and functions

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define DEFAULT_BUFFER 65 //used as a DEFAULT_buffer for reading string input from stdin
#define TRUE 1 //used as a boolean true value
#define FALSE 0 //used as a boolean false value

//STRUCTURES
// the following structures contain single pointer nodes for all of C's primite data types:
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
    struct char_single_Node *next;
}CHAR_SINGLE_NODE_t;

typedef struct signed_char_single_Node{
    // Of the same size as char, but guaranteed to be signed. Capable of containing at least the [−127, +127] range

    signed char element;
    struct signed_char_single_Node *next;
}SIGNED_CHAR_NODE_t;

typedef struct unsigned_char_single_Node{
    // Of the same size as char, but guaranteed to be unsigned. Contains at least the [0, 255] range.

    unsigned char element;
    struct unsigned_char_single_Node *next;
}UNSIGNED_CHAR_NODE_t;

typedef struct short_Node{
    // Short signed integer type. Capable of containing at least the [−32,767, +32,767] range.
    // Thus, it is at least 16 bits in size. The negative value is −32767 (not −32768) due to the
    // one's-complement and sign-magnitude representations allowed by the standard, though the
    // two's-complement representation is much more common.

    short element;
    struct short_single_Node *next;
}SHORT_SINGLE_NODE_t;

typedef struct short_int_single_Node{
    // Short signed integer type. Capable of containing at least the [−32,767, +32,767] range.
    // Thus, it is at least 16 bits in size. The negative value is −32767 (not −32768) due to the
    // one's-complement and sign-magnitude representations allowed by the standard, though the
    // two's-complement representation is much more common.

    short int element;
    struct short_int_single_Node *next;
}SHORT_INT_SINGLE_NODE_t;

typedef struct signed_short_single_Node{
    // Short signed integer type. Capable of containing at least the [−32,767, +32,767] range.
    // Thus, it is at least 16 bits in size. The negative value is −32767 (not −32768) due to the
    // one's-complement and sign-magnitude representations allowed by the standard, though the
    // two's-complement representation is much more common.

    signed short element;
    struct signed_short_single_Node *next;
}SIGNED_SHORT_SINGLE_NODE_t;

typedef struct signed_short_int_single_Node{
    // Short signed integer type. Capable of containing at least the [−32,767, +32,767] range.
    // Thus, it is at least 16 bits in size. The negative value is −32767 (not −32768) due to the
    // one's-complement and sign-magnitude representations allowed by the standard, though the
    // two's-complement representation is much more common.

    signed short int element;
    struct signed_short_int_single_Node *next;
}SIGNED_SHORT_INT_SINGLE_NODE_t;

typedef struct unsigned_short_single_Node{
    // Short unsigned integer type. Contains at least the [0, 65,535] range.

    unsigned short element;
    struct unsigned_short_single_Node *next;
}UNSIGNED_SHORT_SINGLE_NODE_t;

typedef struct unsigned_short_int_single_Node{
    // Short unsigned integer type. Contains at least the [0, 65,535] range.

    unsigned short int element;
    struct unsigned_short_int_single_Node *next;
}UNSIGNED_SHORT_INT_SINGLE_NODE_t;

typedef struct int_single_Node{
    // Basic signed integer type. Capable of containing at least the [−32,767, +32,767] range;
    // thus, it is at least 16 bits in size.

    int element;
    struct int_single_Node *next;
}INT_SINGLE_NODE_t;

typedef struct signed_single_Node{
    // Basic signed integer type. Capable of containing at least the [−32,767, +32,767] range;
    // thus, it is at least 16 bits in size.

    signed element;
    struct signed_single_Node *next;
}SIGNED_SINGLE_NODE_t;

typedef struct signed_int_single_Node{
    // Basic signed integer type. Capable of containing at least the [−32,767, +32,767] range;
    // thus, it is at least 16 bits in size.

    signed int element;
    struct signed_int_single_Node *next;
}SIGNED_INT_NODE_t;

typedef struct unsigned_single_Node{
    // Basic unsigned integer type. Contains at least the [0, 65,535] range;

    unsigned element;
    struct unsigned_single_Node *next;
}UNSIGNED_SINGLE_NODE_t;

typedef struct unsigned_int_single_Node{
    // Basic unsigned integer type. Contains at least the [0, 65,535] range;

    unsigned int element;
    struct unsigned_int_single_Node *next;
}UNSIGNED_INT_SINGLE_NODE_t;

typedef struct long_single_Node{
    // Long signed integer type. Capable of containing at least the [−2,147,483,647,
    // +2,147,483,647] range; thus, it is at least 32 bits in size.

    long element;
    struct long_single_Node *next;
}LONG_SINGLE_NODE_t;

typedef struct long_int_single_Node{
    // Long signed integer type. Capable of containing at least the [−2,147,483,647,
    // +2,147,483,647] range; thus, it is at least 32 bits in size.

    long int element;
    struct long_int_single_Node *next;
}LONG_INT_SINGLE_NODE_t;

typedef struct signed_long_single_Node{
    // Long signed integer type. Capable of containing at least the [−2,147,483,647,
    // +2,147,483,647] range; thus, it is at least 32 bits in size.

    signed long element;
    struct signed_long_single_Node *next;
}SIGNED_LONG_SINGLE_NODE_t;

typedef struct signed_long_int_single_Node{
    // Long signed integer type. Capable of containing at least the [−2,147,483,647,
    // +2,147,483,647] range; thus, it is at least 32 bits in size.

    signed long int element;
    struct signed_long_int_single_Node *next;
}SIGNED_LONG_INT_SINGLE_NODE_t;

typedef struct unsigned_long_single_Node{
    // Long unsigned integer type. Capable of containing at least the [0, 4,294,967,295] range;

    unsigned long element;
    struct unsigned_long_single_Node *next;
}UNSIGNED_LONG_SINGLE_NODE_t;

typedef struct unsigned_long_int_single_Node{
    // Long unsigned integer type. Capable of containing at least the [0, 4,294,967,295] range;

    unsigned long int element;
    struct unsigned_long_int_single_Node *next;
}UNSIGNED_LONG_INT_SINGLE_NODE_t;

typedef struct long_long_single_Node{
    // Long long signed integer type. Capable of containing at least the [−9,223,372,036,854,775,807,
    // +9,223,372,036,854,775,807] range; thus, it is at least 64 bits in size. Specified
    // since the C99 version of the standard.

    long long element;
    struct long_long_single_Node *next;
}LONG_LONG_SINGLE_NODE_t;

typedef struct long_long_int_single_Node{
    // Long long signed integer type. Capable of containing at least the [−9,223,372,036,854,775,807,
    // +9,223,372,036,854,775,807] range; thus, it is at least 64 bits in size. Specified
    // since the C99 version of the standard.

    long long int element;
    struct long_long_int_single_Node *next;
}LONG_LONG_INT_SINGLE_NODE_t;

typedef struct signed_long_long_single_Node{
    // Long long signed integer type. Capable of containing at least the [−9,223,372,036,854,775,807,
    // +9,223,372,036,854,775,807] range; thus, it is at least 64 bits in size. Specified
    // since the C99 version of the standard.

    signed long long element;
    struct signed_long_long_single_Node *next;
}SIGNED_LONG_LONG_SINGLE_NODE_t;

typedef struct signed_long_long_int_single_Node{
    // Long long signed integer type. Capable of containing at least the [−9,223,372,036,854,775,807,
    // +9,223,372,036,854,775,807] range; thus, it is at least 64 bits in size. Specified
    // since the C99 version of the standard.

    signed long long int element;
    struct signed_long_long_int_single_Node *next;
}SIGNED_LONG_LONG_INT_SINGLE_NODE_t;

typedef struct unsigned_long_long_single_Node{
    // Long long unsigned integer type. Contains at least the [0, +18,446,744,073,709,551,615] range;
    // Specified since the C99 version of the standard.

    unsigned long long element;
    struct unsigned_long_long_single_Node *next;
}UNSIGNED_LONG_LONG_SINGLE_NODE_t;

typedef struct unsigned_long_long_int_single_Node{
    // Long long unsigned integer type. Contains at least the [0, +18,446,744,073,709,551,615] range;
    // Specified since the C99 version of the standard.

    unsigned long long int element;
    struct unsigned_long_long_int_single_Node *next;
}UNSIGNED_LONG_LONG_INT_SINGLE_NODE_t;

typedef struct float_single_Node{
    // Real floating-point type, usually referred to as a single-precision floating-point type.
    // Actual properties unspecified (except minimum limits), however on most systems this is
    // the IEEE 754 single-precision binary floating-point format (32 bits). This format is required
    // by the optional Annex F "IEC 60559 floating-point arithmetic".

    float element;
    struct float_single_Node *next;
}FLOAT_SINGLE_NODE_t;

typedef struct double_single_Node{
    // Real floating-point type, usually referred to as a double-precision floating-point type.
    // Actual properties unspecified (except minimum limits), however on most systems this is
    // the IEEE 754 double-precision binary floating-point format (64 bits). This format is required
    // by the optional Annex F "IEC 60559 floating-point arithmetic".

    double element;
    struct double_single_Node *next;
}DOUBLE_SINGLE_NODE_t;

typedef struct long_double_single_Node{
    // Real floating-point type, usually mapped to an extended precision floating-point number format.
    // Actual properties unspecified. It can be either x86 extended-precision floating-point format
    // (80 bits, but typically 96 bits or 128 bits in memory with padding bytes), the non-IEEE "double-double"
    // (128 bits), IEEE 754 quadruple-precision floating-point format (128 bits), or the same as double.
    // See the article on long double for details.

    long double element;
    struct long_double_single_Node *next;
}LONG_DOUBLE_SINGLE_NODE_t;

// STRING MAINTENANCE // STRING MAINTENANCE // STRING MAINTENANCE // STRING MAINTENANCE // STRING MAINTENANCE // STRING MAINTENANCE
bool IsStringEmpty(char *string){
//Input: *string
//Output: 1 if *string is NULL, 0 otherwise
//checks if *string is empty

    if((string == NULL) || (*string == EOF)) return 1;

    return 0;
}//END IsStringEmpty

int SizeOfString(char *string){
//Input: *string to be changed
//Output: size contains count of total chars in *string
//counts all chars in *string until first '\0' or '\n'

    if(IsStringEmpty(string)) return 0;

    char *original_string_reader = string;
    int size = 1;

    do{ //while original_string_reader hasnt reached the end of *string OR '\n' character,
        ++size;
        ++original_string_reader; //advance the original_string_reader
    }while((*original_string_reader != '\0') && (*original_string_reader != '\n'));

    return size;
}//END SizeOfString

bool FindChar(char *string, char target_char){
//Input: *string to be searched, target_char char to be found or not
//Output: 1 if target_char is in *string, 0 otherwise
//searches for target_char in *string

    char *original_string_reader = string; //pointer used to read string
    while(*original_string_reader != '\0'){ //while original_string_reader is no at the end of string
        if(*original_string_reader == target_char){ //if original_string_reader == target_char
            return 1; //target_char is in the given string
        }else{
            ++original_string_reader; //advance the original_string_reader
        }
    }

    return 0;
}//END FindChar

char *InsertNullChar(char *string){
//Input: *string to be searched and copied
//Output: *new_string
//inserts '\0' at the end of *string

    if(IsStringEmpty(string)) return NULL; //if *string is empty, return NULL

    char *new_string = (char*) malloc(sizeof(char) * DEFAULT_BUFFER); //reserve memory for new_string
    strcpy(new_string, string);

    char *string_reader = string;
    char *new_string_reader = new_string;

    while((*string_reader != '\0') && (*string_reader != '\n') && (*string_reader != '\r') && (*string_reader != EOF)){ //while the string has valid chars
        ++string_reader; //advance pointer
        ++new_string_reader; //advance pointer
    }

    *new_string_reader = '\0'; //insert '\0' char

    return new_string;
}//END InsertNullChar

char *CopyFirstWord(char *string){
//Input: *string to be cleaned
//Output: *new_string
//copies all chars in *string until first ' ' is found

    if(IsStringEmpty(string)) return NULL; //if *string is empty, return NULL

    char *new_string = (char*) malloc(sizeof(char) * DEFAULT_BUFFER); //reserve memory for new_string
    char *original_string_reader = string; //used to read the original string
    char *new_string_reader = new_string; //used to insert into the new_string

    while((*original_string_reader != ' ') && (original_string_reader != NULL) && (*original_string_reader != '\0')){ //while there are chars to read from the original string,
        *new_string_reader = *original_string_reader; //insert into new_string the char of string
        ++original_string_reader; //advance the reader
        ++new_string_reader; //advance the inserter
    }

    *new_string_reader = '\0';

    return new_string;
}//END CopyFirstWord

char *ConvertStringToLowerCase(char *string){
//Input: *string to be changed to lowercase
//Output: *new_string
//converts all chars in *string to lowercase

    if(IsStringEmpty(string)) return NULL; //if *string is empty, return NULL

    char *new_string = (char*) malloc(sizeof(char) * DEFAULT_BUFFER); //reserve memory for new_string
    char *original_string_reader = string; //used to read the original string
    char *new_string_reader = new_string; //used to insert into the new_string

    while((original_string_reader != NULL) && (original_string_reader != '\0')){ //while there are chars to read from the original string,
        *new_string_reader = tolower(*original_string_reader); //insert into new_string the lowercase char of string
        ++original_string_reader; //advance the reader
        ++new_string_reader; //advance the inserter
    }

    return new_string;
}//END ConvertStringToLowerCase
// VERIFY ARGV // VERIFY ARGV // VERIFY ARGV // VERIFY ARGV // VERIFY ARGV // VERIFY ARGV // VERIFY ARGV // VERIFY ARGV
bool VerifyArgc(char argc, char *argv[]){
// Input: argc
// Output: true if argc is greater than 1, false otherwise
// checks if argc has more than one argument, the first argument is always the name of the program

    if(!(argc > 1)){
        printf("\nERROR:_> FROM:_> VerifyArgc:_> PLEASE PROVIDE AN INPUT FILE VIA argv, FOR EXAMPLE 'USER$ <%s> FIRST_INPUT_file.txt'. EXITING PROGRAM.\n", argv[0]);
        exit(-1); //exit the program
    }

    return 1;
}// END VerifyArgc

void VerifyArgv(char *argv[]){
//Input: *argv
//Output: void
//ensures argv has values

    if(argv == NULL){ //if argv is empty,
        printf("\nERROR:_> FROM:_> VerifyArgv:_> PLEASE PROVIDE AN INPUT FILE VIA argv, FOR EXAMPLE 'USER$ <%s> FIRST_INPUT_file.txt'. EXITING PROGRAM.\n", argv[0]);
        exit(-1); //exit the program
    }

    return;
}//END VerifyArgv

FILE *VerifyFileStreamPointer(char *argv){
//Input: *argv
//Output: FILE_STREAM
//checks if file stream pointer exists, returns the file if it does, exits the program otherwise

    FILE *FILE_STREAM = fopen(argv, "r"); //opens a file to only read and returns a pointer to that file, otherwise returns NULL pointer

    if(FILE_STREAM == NULL){ //if FILE_STREAM is NULL,
        printf("\nERROR:_> FROM:_> VerifyFileStreamPointer:_> <%s> WAS NOT FOUND IN THE CURRENT WORKING DIRECTORY. EXITING PROGRAM.\n", argv);
        fclose(FILE_STREAM); //close FILE_STREAM stream
        exit(-1); //exit the program
    }else if(getc(FILE_STREAM) == EOF){ //if FILE_STREAM is empty
        printf("\nERROR:_> FROM:_> VerifyFileStreamPointer:_> <%s> IS EMPTY. EXITING PROGRAM.\n", argv);
        fclose(FILE_STREAM); //close FILE_STREAM stream
        exit(-1); //exit the program
    }else{ //otherwise,
        rewind(FILE_STREAM); //place DEFAULT_buffer to the beginning of FILE_STREAM pointer
    }

    return FILE_STREAM; //return an existent and non-empty FILE *pointer
}//END VerifyFileStreamPointer
