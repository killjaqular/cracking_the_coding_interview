/*
Adonay Pichardo, adonaypichardo@gmail.com

@file
template.java

@description
Template file for all Java source files.

*/

// STANDARD LIBRARIES
import java.util.LinkedList;

// NON-STANDARD LIBRARIES
// NONE

class template{
    public static void main(String[] args) {
        // printf("\n\n%s executing\n\n", argv[0]);
        System.out.println("\n\ntemplate executing\n");

        Integer element_value = 0;
        LinkedList<Integer> list = new LinkedList<Integer>();

        list.add(1337);
        element_value = list.get(0);
        System.out.println("element value = " + element_value + "\n");
        System.out.println(list);
        list.remove();
        System.out.println(list);

        System.out.println("\n\ntemplate executed\n");
        return;
    }
// METHODS
// NONE
}
