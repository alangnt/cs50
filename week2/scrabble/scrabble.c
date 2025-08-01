#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int get_word_score_value(string word);
string get_word_to_uppercase(string word);
int get_letter_value(char letter);
void get_winner(int score_value1, int score_value2);

int main(void)
{
    // Asks for the two words
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Make them Uppercase
    string upper_case_word1 = get_word_to_uppercase(word1);
    string upper_case_word2 = get_word_to_uppercase(word2);

    // Get their score value
    int score_value_word1 = get_word_score_value(upper_case_word1);
    int score_value_word2 = get_word_score_value(upper_case_word2);

    // Finally, calls the get_winner function to return the results
    get_winner(score_value_word1, score_value_word2);
}

// Get the total score value of the word
int get_word_score_value(string word)
{
    // Declare Total score value at 0
    int total_score_value = 0;

    // Iterates through the word and calls get_score_value to get
    // the value of each letter and sum them into total_score_value
    for (int i = 0, length = strlen(word); i < length; i++)
    {
        int score = get_letter_value(word[i]);
        total_score_value += score;
    }

    // Then returns the total score value
    return total_score_value;
}

// Converts a String to UpperCase
string get_word_to_uppercase(string word)
{
    // Iterates through the word to make it Uppercase using the  strlen function from ctypes
    for (int i = 0, length = strlen(word); i < length; i++)
    {
        word[i] = toupper(word[i]);
    }

    // Then, return the Uppercased word
    return word;
}

// Returns the value of the letter
int get_letter_value(char letter)
{
    // Declare Letter value at 1 since it can't go below
    int letter_value = 0;

    // If other than A to Z, returns 0
    if (letter >= 'A' && letter <= 'Z')
    {
        letter_value += 1;
    }
    else
    {
        return 0;
    }

    // Then, based on the letter, add the appropriate value to the letter value
    if (letter == 'D' || letter == 'G')
    {
        letter_value += 1;
    }
    else if (letter == 'B' || letter == 'C' || letter == 'M' || letter == 'P')
    {
        letter_value += 2;
    }
    else if (letter == 'F' || letter == 'H' || letter == 'V' || letter == 'W' || letter == 'Y')
    {
        letter_value += 3;
    }
    else if (letter == 'K')
    {
        letter_value += 4;
    }
    else if (letter == 'J' || letter == 'X')
    {
        letter_value += 7;
    }
    else if (letter == 'Q' || letter == 'Z')
    {
        letter_value += 9;
    }

    // Finally, returns it
    return letter_value;
}

// Compare the two score values and return the winner (or tie)
void get_winner(int score_value1, int score_value2)
{
    // Player 1 wins
    if (score_value1 > score_value2)
    {
        printf("Player 1 wins!\n");
    }
    // Player 2 wins
    else if (score_value1 < score_value2)
    {
        printf("Player 2 wins!\n");
    }
    // Tie
    else
    {
        printf("Tie!\n");
    }
}
