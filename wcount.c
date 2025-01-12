// C program to count the number of words in a file

#include <stdio.h>
#include <ctype.h>

// Function prototypes
int countWords(FILE *file_pointer);
int isWhitespace(char character);

// Main function
int main(int argc, char *argv[]) 
{
    // Check if the file path is provided as a command line argument
    if (argc != 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    // Open the file using fopen() for reading
    FILE *file_pointer = fopen(argv[1], "r");

    // Check if the file is opened successfully
    if (file_pointer == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Call the function to count words
    int number_of_words = countWords(file_pointer);

    // Close the file
    fclose(file_pointer);

    // Print the number of words
    printf("There are %d word(s).\n", number_of_words);

    return 0;
}

// Function to count the number of words in a file
int countWords(FILE *file_pointer)
{
    int total_words = 0;
    char character;
    int inWord = 0;  // Flag to track whether currently inside a word

    // Read characters from the file until the end of file is reached
    while (fscanf(file_pointer, "%c", &character) != EOF) {
        // Check if the character is a whitespace character
        if (isWhitespace(character) || character == '\n') {
            // If previously in a word, increment the word count and set the flag to 0
            if (inWord) {
                total_words++;
                inWord = 0;
            }
        } else {
            // Set the flag to 1 to indicate that we are inside a word
            inWord = 1;
        }
    }

    // If the last word extends to the end of the file, increment the word count
    if (inWord) {
        total_words++;
    }

    // Return the total number of words
    return total_words;
}

int isWhitespace(char character) 
{
    return isspace((unsigned char)character);
}