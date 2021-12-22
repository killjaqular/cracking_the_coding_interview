"""
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

1.3 URLify: Write a method to replace all spaces in a string with "%20". You may assume that the string has sufficient
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

"""
# STANDARD LIBRARIES
from sys import argv, stdin, stdout

def main():
    stdout.write(f"\n\n{argv[0]} executing\n\n")

    all_tests = open(argv[1], "r")
    all_tests = all_tests.read()

    for every_test in all_tests:

        if (every_test == "is_unique.in"):
            ################################
            # 1.1 Is Unique
            stdout.write(f"#########\n")
            stdout.write(f"# 1.1 Is Unique #\n")
            stdout.write(f"#########\n")
            ################################

            current_test = open(every_test, "r")

            for every_line in current_test.read():
                if (is_unique(every_line)):
                    stdout.write(f"All unique characters.\n\n")
                else:
                    stdout.write(f"Not unique characters.\n\n")

        if (every_test == "check_permutation.in"):
            ################################
            # 1.2 Check Permutation
            stdout.write(f"#############\n")
            stdout.write(f"# 1.2 Check Permutation #\n")
            stdout.write(f"#############\n")
            ################################

            while(is_stream_at_EOF != True){ # Read from file, write to buffer

                if (check_permutation(left_string, right_string)):
                    stdout.write(f"Valid Permutation.\n\n")
                else:
                    stdout.write(f"Invalid Permutation.\n\n")

        if (every_test == "URLify.in"):
            ################################
            # 1.3 URLify
            stdout.write(f"########\n")
            stdout.write(f"# 1.3 URLify #\n")
            stdout.write(f"########\n")
            ################################

            # If we haven"t reached the end of the file,
            while(is_stream_at_EOF != True){ # Read from file, write to buffer
                is_stream_at_EOF = write_to_buffer(current_test_input, buffer, MAX_BUFFER_SIZE, "\"", "\"")
                string_size = length_of_string(buffer)
                if(is_stream_at_EOF == True) break # Stop test

                URLify(buffer, string_size, "%20")
                stdout.write(f"%s\n", buffer)

                set_string_to_null(buffer, MAX_BUFFER_SIZE) # Clear buffer

                stdout.write(f"%s\n", buffer)
            }
        }

        if (every_test == "palindrome_permutation.in"):
            ################################
            # 1.4 Palindrome Permutation
            stdout.write(f"################\n")
            stdout.write(f"# 1.4 Palindrome Permutation #\n")
            stdout.write(f"################\n")
            ################################

            while(is_stream_at_EOF != True){ # Read from file, write to buffer
                is_stream_at_EOF = write_to_buffer(current_test_input, buffer, MAX_BUFFER_SIZE, NULL, "\n")
                if(is_stream_at_EOF == True) break # Stop test

                boolean_result = palindrome_permutation(buffer)

                set_string_to_null(buffer, MAX_BUFFER_SIZE) # Clear buffer

                if(boolean_result == True){
                    stdout.write(f"Palindrome Permutations possible.\n\n")
                }else{
                    stdout.write(f"Palindrome Permutations impossible.\n\n")
                }
            }
        }

        if (every_test == "one_away.in"):
            ################################
            # 1.5 One Away
            stdout.write(f"#########\n")
            stdout.write(f"# 1.5 One Away #\n")
            stdout.write(f"#########\n")
            ################################

            while(is_stream_at_EOF != True){ # Read from file, write to buffer
                is_stream_at_EOF = write_to_buffer(current_test_input, buffer, MAX_BUFFER_SIZE, NULL, " ")
                if(is_stream_at_EOF == True) break # Stop test
                is_stream_at_EOF = write_to_buffer(current_test_input, right_string, MAX_BUFFER_SIZE, NULL, " ")
                if(is_stream_at_EOF == True) break # Stop test

                boolean_result = one_away(buffer, right_string)

                set_string_to_null(buffer, MAX_BUFFER_SIZE) # Clear buffer
                set_string_to_null(right_string, MAX_BUFFER_SIZE) # Clear buffer

                if(boolean_result == True){
                    stdout.write(f"True.\n\n")
                }else{
                    stdout.write(f"False.\n\n")
                }
            }
        }

        if (every_test == "string_compression.in"):
            ################################
            # 1.6 String Compression
            stdout.write(f"##############\n")
            stdout.write(f"# 1.6 String Compression #\n")
            stdout.write(f"##############\n")
            ################################

            while(is_stream_at_EOF != True){ # Read from file, write to buffer
                is_stream_at_EOF = write_to_buffer(current_test_input, buffer, MAX_BUFFER_SIZE, NULL, "\n")
                if(is_stream_at_EOF == True) break # Stop test

                compressed_string = string_compression(buffer)

                if(compressed_string != NULL){
                    stdout.write(f"%s\n\n", compressed_string)
                }else{
                    stdout.write(f"%s\n\n", buffer)
                }

                set_string_to_null(buffer, MAX_BUFFER_SIZE) # Clear buffer
                compressed_string = NULL
                free(compressed_string)
            }
        }

        if (every_test == "rotate_matrix.in"):
            ################################
            # 1.7 Rotate Matrix
            stdout.write(f"###########\n")
            stdout.write(f"# 1.7 Rotate Matrix #\n")
            stdout.write(f"###########\n")
            ################################

            char_2d_matrix = create_char_2d_square_matrix(current_test_input)
            stdout.write(f"back to main\n")
            # rotate_matrix(char_2d_matrix)
        }

        fclose(current_test_input) # Close file
        # Reset reusable variables
        boolean_result   = False # Used to flag if all chars in a string are unique
        is_stream_at_EOF = False # Tracks if input has reached end
    }

    stdout.write(f"\n\n%s executed\n\n" , argv[0])

if __name__ == "__main__":
    main()
