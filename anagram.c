#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Print the anagram
void anagram_function() {
    // Word variables, counter variables, and length of strings
    char fiest_word[20] = {0};
    char second_word[20] = {0};
    int counter_for_first_word[26] = {0};
    int counter_for_second_word[26] = {0};
    int length_of_first_string, length_of_second_string;

    // Enter the first word
    printf("Please enter the first word: ");
    scanf("%s", fiest_word);

    // Enter the second word
    printf("\nPlease enter the second word: ");
    scanf("%s", second_word);

    // Establish and duplicate the word strings with capital letters because we will lowercase them later on
    char new_first_word[20] = {0};
    char new_second_word[20] = {0};

    strcpy(new_first_word, fiest_word);
    strcpy(new_second_word, second_word);

    // Convert input strings to lowercase
    for (int i = 0; fiest_word[i] != '\0'; i++) {
        fiest_word[i] = tolower(fiest_word[i]);
    }

    for (int i = 0; second_word[i] != '\0'; i++) {
        second_word[i] = tolower(second_word[i]);
    }

    // Take the length of both strings
    length_of_first_string = strlen(fiest_word);
    length_of_second_string = strlen(second_word);

    // Get the counters
    for (int i = 0; i < length_of_first_string; i++) {
        counter_for_first_word[fiest_word[i] - 'a']++;
    }

    for (int i = 0; i < length_of_second_string; i++) {
        counter_for_second_word[second_word[i] - 'a']++;
    }

    // Compare sorted arrays of counters
    for (int i = 0; i < 26; i++) {
        if (counter_for_first_word[i] != counter_for_second_word[i]) {
            printf("\n%s is NOT an anagram of %s\n", new_first_word, new_second_word);
            return;
        }
    }

    printf("\n%s is an anagram of %s\n", new_first_word, new_second_word);
}

// Main fucntion to run the program
int main() {
    anagram_function();
    return 0;
}