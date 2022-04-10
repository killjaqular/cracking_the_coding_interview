# <Document_Header Start>
"""
filename : createDirectories.py
description :
Creates a directory structure for a chapter in Cracking The Coding Interview. The
directories isolate the following languages:
NASM, C, C++, Java, and Python.
"""
# <Document_Header End>

# <Standard Imports Start>
from sys import argv
import os
# <Standard Imports End>

# <Internal Imports Start>
# NONE
# <Internal Imports End>

# <External Imports Start>
# NONE
# <External Imports End>

# <Global Objects Start>
ALL_DIRECTORIES = {\
    "assembly" : ".asm",
    "c"        : ".c",
    "c++"      : ".cpp",
    "java"     : ".java",
    "python"   : ".py"
    }
# <Global Objects End>

# <Classes Start>
# NONE
# <Classes End>

# <Functions Start>
################################
# Checks if createDirectories.py is being used correctly
################################
def checkCLI(argv):
    if len(argv) != 3:
            stdout.write(f'USAGE:_> python3 {argv[0]} <name of chapter> <number of test cases>\n\n')
            exit()

def createDirectories(chapterName, totalTests):
    """
    createDirectories: Creates directories and files needed for Cracking the Coding
                       Interview problems.

    INPUT:             chapterName - string, The chapter in Cracking the Coding
                       Interview.
                       totalTests  - int, Number of test cases for this chapter.

    OUTPUT:            NONE
    """
    # Make a top level directory for the new chapter
    os.mkdir(chapterName)

    # Create template description
    templateDescription = ""
    for testNumber in range(1, totalTests + 1):
        templateDescription += f"{chapterName}.{testNumber}:\n\n"

    # Make all other directories that are language specific
    for everyLanguage in ALL_DIRECTORIES.keys():
        os.mkdir(chapterName + "/" + everyLanguage)
        # Create file template
        currentFile = open(chapterName + "/" + everyLanguage + "/" + chapterName + \
                           ALL_DIRECTORIES[everyLanguage], "w")
        currentTemplate = open("adolib/templates/template" + \
                               ALL_DIRECTORIES[everyLanguage])

        # Surround templateDescription in approriate comment block
        if everyLanguage == "assembly":
            asmTemplateDescription = templateDescription.split("\n")
            for everyLine in asmTemplateDescription:
                currentFile.write(f"; {everyLine}\n")

        if everyLanguage == "c":
            currentFile.write(f"/*\n{templateDescription}\n*/\n")

        if everyLanguage == "c++":
            currentFile.write(f"/*\n{templateDescription}\n*/\n")

        if everyLanguage == "java":
            currentFile.write(f"/*\n{templateDescription}\n*/\n")

        if everyLanguage == "python":
            currentFile.write(f'"""\n{templateDescription}\n"""\n')

        currentFile.write(f"{currentTemplate.read()}\n")

        currentFile.close()

    # Make test directory
    os.mkdir(chapterName + "/" + "tests/")

    # Create base test file with all test file names
    testFile = open(chapterName + "/" + "tests/" + chapterName + ".tests", "w")
    # Make every test case
    for testNumber in range(1, totalTests + 1):
        currentFile = open(chapterName + "/" + "tests/" + str(testNumber) + ".in", "w")
        currentFile.close()
        testFile.write(str(testNumber) + ".in\n")

    testFile.close()

def main():
    checkCLI(argv)
    createDirectories(argv[1], int(argv[2]))

# <Functions End>

if __name__ == "__main__":
    main()
