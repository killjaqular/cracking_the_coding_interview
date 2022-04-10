/*
Adonay Pichardo, adonaypichardo@gmail.com

@description
Template file for all C source files.

*/

// STANDARD LIBRARIES
#include <stdio.h>
#include <stdlib.h>

// NON-STANDARD LIBRARIES
// NONE

// MACROS
#define True  1
#define False 0

// GLOBAL VARIABLES
// Place global variables here

// STRUCTURES
typedef struct some_structure{
    // Description of the structure
    int element;//Note what this element is for
}SOME_STRUCTURE_t;

// PROTOTYPES
SOME_STRUCTURE_t* SOME_STRUCTURE_ini();//Initialize memory for a some_structure
int  SOME_STRUCTURE_get(SOME_STRUCTURE_t*);//Get element from object
void SOME_STRUCTURE_set(SOME_STRUCTURE_t*, int);//Set element in objec
void SOME_STRUCTURE_pri(SOME_STRUCTURE_t*);//Print element in object
void SOME_STRUCTURE_del(SOME_STRUCTURE_t*);//Delete entire object

int main(int argc, char** argv){
    printf("\n\n%s executing\n\n", argv[0]);

    // STACK MEMORY
    // Stack memory used in main()
    int element_value = 0;
    SOME_STRUCTURE_t* structure = SOME_STRUCTURE_ini();

    // HEAP MEMORY
    // Heap memory used in main()

    SOME_STRUCTURE_set(structure, 1337);
    element_value = SOME_STRUCTURE_get(structure);
    printf("element_value = %d\n", element_value);
    SOME_STRUCTURE_pri(structure);
    SOME_STRUCTURE_del(structure);

    if(structure != NULL){
        printf("structure = %x\n", structure->element);
    }

    printf("\n\n%s executed\n\n", argv[0]);
    return 0;
}

// DEFINITIONS
//SOME_STRUCTURE_t//SOME_STRUCTURE_t//SOME_STRUCTURE_t//SOME_STRUCTURE_t//SOME_STRUCTURE_
SOME_STRUCTURE_t* SOME_STRUCTURE_ini(void){
/*
SOME_STRUCTURE_ini: malloc memory, set all fields 0 or NULL.
Input: void.
Output: new_some_structure - A new malloced struct with all fields set
        to 0 or NULL..
Example Usage:
SOME_STRUCTURE_t* some_structure = SOME_STRUCTURE_init();
*/
    // STACK MEMORY
    // Stack memory used in SOME_STRUCTURE_ini()

    // HEAP MEMORY
    SOME_STRUCTURE_t* new_some_structure = (SOME_STRUCTURE_t*) malloc(sizeof(SOME_STRUCTURE_t));

    // Set all fields to 0 or NULL;
    new_some_structure->element = 0;

    return new_some_structure;
}
int SOME_STRUCTURE_get(SOME_STRUCTURE_t* object){
/*
SOME_STRUCTURE_get: Get get element of object.
Input: object - The stucture from which to get the value of an element.
Output: element_value - The value.
Example Usage:
int value = SOME_STRUCTURE_get(object);
*/
    // STACK MEMORY
    int element_value = 0;

    // HEAP MEMORY
    // Heap memory used in SOME_STRUCTURE_get()

    element_value = object->element;

    return element_value;
}
void SOME_STRUCTURE_set(SOME_STRUCTURE_t* object, int new_element){
/*
SOME_STRUCTURE_set: Get set element of object.
Input: object     - The stucture for which to set the value of an element.
       new_elment - The new value to set.
Output: void.
Example Usage:
SOME_STRUCTURE_set(object, 1337);
*/
    // STACK MEMORY
    // Stack memory used in SOME_STRUCTURE_set()

    // HEAP MEMORY
    // Heap memory used in SOME_STRUCTURE_set()

    object->element = new_element;

    return;
}
void SOME_STRUCTURE_pri(SOME_STRUCTURE_t* object){
/*
SOME_STRUCTURE_pri: Prints a field of object.
Input: object - The structure from which to print.
Output: void.
Example Usage:
SOME_STRUCTURE_pri(object);
*/
    // STACK MEMORY
    // Stack memory used in SOME_STRUCTURE_pri()

    // HEAP MEMORY
    // Heap memory used in SOME_STRUCTURE_pri()

    printf("object->element = %d\n", object->element);

    return;
}
void SOME_STRUCTURE_del(SOME_STRUCTURE_t* object){
/*
SOME_STRUCTURE_del: Sets all elements to 0 or NULL, NULLs the pointer and frees memory.
Input: object - The structure to free.
Output: void.
Example Usage:
SOME_STRUCTURE_del(object);
*/
    // STACK MEMORY
    // Stack memory used in SOME_STRUCTURE_del()

    // HEAP MEMORY
    // Heap memory used in SOME_STRUCTURE_del()

    // Set all fields to 0 or NULL
    object->element = 0;

    // Free and NULL pointer to avoid Use-After-Free
    object = NULL;
    free(object);

    return;
}