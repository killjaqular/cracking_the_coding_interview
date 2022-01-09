"""
Adonay Pichardo, adonaypichardo@gmail.com
github.com/killjaqular

@file
CH1_Arrays_and_Strings.py

@usage
user@host:some/directory$: python3 <path to this file> <path to ch1.test>

@description
Cracking the Coding Interview:
Chapter 1 Problems

1.1 Is Unique:
    Implement an algorithm to determine if a string has all unique characters. What if
    you cannot use additional data structures?

1.2 Check Permutation:
    Given two strings, write a method to decide if one is a permutation of the other.

1.3 URLify:
    Write a method to replace all spaces in a string with "%20". You may assume that
    the string has sufficient space at the end to hold the additional charcters, and
    that you are given the "true" length of the string. (Note: If implementing in Java,
    please use a character array so that you  can perform this operation in place.)

    Example:
                Input:  "Mr John Smith    ", 13
                Output: "Mr%20John%20Smith"

1.4 Palindrome Permutation:
    Given a string, write a function to check if it is a permutation of a plindrome.
    A palindrome is a word or phrase that is the same forwards and backwards. A
    permutation is a rearrangement of letters. The palindrome does not need to be
    limited to just dictionary words.

    Example:
        Input:  Tact Coa
        Output: True
        Permutations: "taco cat", "atco cta", etc...

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
    For example, the string aabcccccaaa would become a2b1c5a3. If the "compressed"
    string would not become smaller than the original string, your method should return
    the original string. You can assume the string has only uppercase and lowercase
    letters (a-z).

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

"""
# STANDARD LIBRARIES
from sys import argv, stdin, stdout

# CLASSES
class Matrix:
    def __init__(self):
        self.matrix = list(list())

    def insert_row(self, new_row):
        self.matrix.append(new_row)

    def __str__(self):
        str_rep = "" + "\n"

        for row in self.matrix:
            for cell in row:
                str_rep += f'{cell}'
            str_rep += "\n"

        return str_rep

# FUNCTIONS
def is_unique(string):
    """
    is_unique: Checks if every char occurs no more than once.
    INPUT:     string - string, The string to check.
    OUTPUT:    True if all chars occur no more than once, otherwise False.
    """
    stdout.write(f'\n{string}\n')

    for every_char in string:
        if string.count(every_char) > 1:
            return False

    return True
def check_permutation(left_string, right_string):
    """
    check_permutation: Checks if left and right string can be permutations of each
                       other.
    INPUT:             left_string  - string, A string to compare.
                       right_string - string, A string to compare.
    OUTPUT:            True if strings are permutations, otherwise False.
    """
    stdout.write(f'\n{left_string}\n{right_string}\n')

    if (len(left_string) != len(right_string)): return False

    table = []

    for every_element in left_string:
        table.append(every_element)

    for every_element in right_string:
        if right_string.count(every_element) != table.count(every_element):
            return False

    return True
def URLify(string):
    """
    URLify: Replaces all spaces with %20.
    INPUT:  string - string, The string to augment.
    OUTPUT: string - stirng, The augmented string.
    """
    stdout.write(f'\n{string}\n')

    string = string.split(",")[0].split(".")[0][1:]
    string = '"' + string.replace(" ", "%20") + '."'

    return string
def palindrome_permutation(string):
    """
    palindrome_permutation: Checks if a string can be permutated into a palindrome.
    INPUT:                  string - string, The string to check.
    OUTPUT:                 True if string can be permutated to be a palindrome.
    """
    stdout.write(f'\n{string}\n')

    table = {}
    first_one = False

    for every_char in string:
        if every_char not in table.keys():
            table[every_char] = 1
        else:
            table[every_char] = 0

    for every_char in table.keys():
        if table[every_char] >= 1 and not first_one:
            first_one = True
        elif table[every_char] >= 1 and first_one:
            return False

    return True
def one_away(left_string, right_string):
    """
    one_away: Checks if the two strings are at most 1 change away from being the same.
    INPUT:    left_string - string,  A string to compare.
    OUTPUT:   right_string - string, A string to compare.
    """
    stdout.write(f'\n{left_string}\n{right_string}\n')

    one_difference = False

    if (abs(len(left_string) - len(right_string)) > 1): return False

    if len(left_string) == len(right_string):
        for index in range(len(left_string)):
            if left_string[index] != right_string[index] and not one_difference:
                one_difference = True
            elif left_string[index] != right_string[index] and one_difference:
                return False

    else:
        short_string = min(len(left_string), len(right_string))
        if len(left_string) == short_string:
            short_string = left_string
            long_string  = right_string
        else:
            short_string = right_string
            long_string  = left_string

        long_index = 0
        for short_index in range(len(short_string)):
            if short_string[short_index] != long_string[long_index] and not \
               one_difference:
                one_difference = True
                long_index += 1

            elif short_string[short_index] != long_string[long_index] and \
            one_difference:
                return False

            long_index += 1

    return True
def string_compression(string):
    """
    string_compression: Frequency compression of a string.
    INPUT:              string - string, String to compress.
    OUTPUT:             compressed_string - string, Final compressed string.
    """
    stdout.write(f'\n{string}\n')

    char_count = []
    max_length = len(string)

    index = 0
    while index < len(string):
        counter = 0
        current_char = string[index]
        while current_char == string[index]:
            counter += 1
            index  += 1
            if index >= len(string): break

        char_count.append((current_char, counter))

    compressed_string = ""
    for every_char in char_count:
        compressed_string += every_char[0] + str(every_char[1])
        if len(compressed_string) >= len(string):
            return string

    return compressed_string
def rotate_matrix(matrix, depth):
    """
    rotate_matrix: Takes a square matrix and rotates all elements 90 degrees clock wise.
    INPUT:         matrix - matrix, The matrix to rotate.
                   depth  - int,    The domain of the matrix.
    OUTPUT:        final_matrix - matrix, The final matrix.
    """
    stdout.write(f'\n{matrix}\n')

    if depth < 0:
        return final_matrix

    return True
def zero_matrix(matrix):
    """
    zero_matrix: Takes a square matrix and sets the row and column of a zero cell to
                 zeros.
    INPUT:       matrix - matrix, The matrix to scan.
    OUTPUT:      final_matrix - matrix, The final matrix.
    """
    stdout.write(f'\n{matrix}\n')

    original_zeros = []

    for y, _ in enumerate(matrix.matrix):
        for x, _ in enumerate(matrix.matrix):
            if matrix.matrix[y][x] == 0:
                original_zeros.append((y, x))

    for every_zero in original_zeros:
        # Zero row
        for row in range(len(matrix.matrix)):
            matrix.matrix[every_zero[0]][row] = 0
        # Zero column
        for column in range(len(matrix.matrix)):
            matrix.matrix[column][every_zero[1]] = 0

    return matrix
def string_rotation(string):
    """
    string_rotation: 
    INPUT:           string - string, 
    OUTPUT:          True if , else False
    """
    stdout.write(f'\n{string}\n')



    return True
def main():
    stdout.write(f"\n{argv[0]} executing\n")

    all_tests = open(argv[1], "r")
    test_home = argv[1].split("/")[0]

    for every_test in all_tests.readlines():
        every_test = every_test.rstrip()

        if (every_test == "is_unique.in"):
            ################################
            # 1.1 Is Unique
            stdout.write(f"#################\n")
            stdout.write(f"# 1.1 Is Unique #\n")
            stdout.write(f"#################\n")
            ################################

            current_test = open(test_home + "/" + every_test, "r")

            for every_line in current_test.readlines():
                every_line = every_line.rstrip()

                # Skip empty lines
                if len(every_line) == 0: continue

                if (is_unique(every_line)):
                    stdout.write(f"All unique characters.\n")
                else:
                    stdout.write(f"Not unique characters.\n")

        if (every_test == "check_permutation.in"):
            ################################
            # 1.2 Check Permutation
            stdout.write(f"#########################\n")
            stdout.write(f"# 1.2 Check Permutation #\n")
            stdout.write(f"#########################\n")
            ################################

            current_test = open(test_home + "/" + every_test, "r")
            current_test = current_test.readlines()

            for index in range(0, len(current_test), 3):
                if index + 3 >= len(current_test): break
                if len(current_test) == 0: continue

                left_string  = current_test[index].rstrip()
                right_string = current_test[index + 1].rstrip()

                if (check_permutation(left_string, right_string)):
                    stdout.write(f"Valid Permutation.\n")
                else:
                    stdout.write(f"Invalid Permutation.\n")

        if (every_test == "URLify.in"):
            ################################
            # 1.3 URLify
            stdout.write(f"##############\n")
            stdout.write(f"# 1.3 URLify #\n")
            stdout.write(f"##############\n")
            ################################

            current_test = open(test_home + "/" + every_test, "r")

            for every_line in current_test.readlines():
                every_line = every_line.rstrip()
                stdout.write(f'{URLify(every_line)}\n')

        if (every_test == "palindrome_permutation.in"):
            ################################
            # 1.4 Palindrome Permutation
            stdout.write(f"##############################\n")
            stdout.write(f"# 1.4 Palindrome Permutation #\n")
            stdout.write(f"##############################\n")
            ################################

            current_test = open(test_home + "/" + every_test, "r")

            for every_line in current_test.readlines():
                every_line = every_line.rstrip()

                if (palindrome_permutation(every_line)):
                    stdout.write(f"Palindrome Permutations possible.\n")
                else:
                    stdout.write(f"Palindrome Permutations impossible.\n")

        if (every_test == "one_away.in"):
            ################################
            # 1.5 One Away
            stdout.write(f"################\n")
            stdout.write(f"# 1.5 One Away #\n")
            stdout.write(f"################\n")
            ################################

            current_test = open(test_home + "/" + every_test, "r")

            for every_line in current_test.readlines():
                every_line = every_line.rstrip()
                left_string, right_string = every_line.split()

                if (one_away(left_string, right_string)):
                    stdout.write(f"True.\n")
                else:
                    stdout.write(f"False.\n")

        if (every_test == "string_compression.in"):
            ################################
            # 1.6 String Compression
            stdout.write(f"##########################\n")
            stdout.write(f"# 1.6 String Compression #\n")
            stdout.write(f"##########################\n")
            ################################

            current_test = open(test_home + "/" + every_test, "r")

            for every_line in current_test.readlines():
                every_line = every_line.rstrip()
                stdout.write(f'{string_compression(every_line)}\n')

        if (every_test == "rotate_matrix.in"):
            ################################
            # 1.7 Rotate Matrix
            stdout.write(f"#####################\n")
            stdout.write(f"# 1.7 Rotate Matrix #\n") # TODO: Finish this functionality
            stdout.write(f"#####################\n")
            ################################

            current_test = open(test_home + "/" + every_test, "r")
            all_rows = []

            current_matrix = Matrix()
            for row in current_test.readlines():
                row = row.rstrip()

                current_matrix.insert_row(row)

            stdout.write(f'\ncurrent_test\n{current_matrix}\n')

        if (every_test == "zero_matrix.in"):
            ################################
            # 1.8 zero Matrix
            stdout.write(f"###################\n")
            stdout.write(f"# 1.8 Zero Matrix #\n")
            stdout.write(f"###################\n")
            ################################

            current_test = open(test_home + "/" + every_test, "r")
            all_rows = []

            current_matrix = Matrix()
            for row in current_test.readlines():
                row = [int(cell) for cell in row.rstrip()]

                current_matrix.insert_row(row)

            stdout.write(f'{zero_matrix(current_matrix)}\n')

        if (every_test == "string_rotation.in"):
            ################################
            # 1.9 String Rotation
            stdout.write(f"#######################\n")
            stdout.write(f"# 1.9 String Rotation #\n") # TODO: Finish this functionality
            stdout.write(f"#######################\n")
            ################################

            current_test = open(test_home + "/" + every_test, "r")

            for every_line in current_test.readlines():
                every_line = every_line.rstrip()
                stdout.write(f'{string_rotation(every_line)}\n')

    stdout.write(f"\n{argv[0]} executed\n")

if __name__ == "__main__":
    main()
