#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

void analyze_text(string text);
string get_text_to_lowercase(string text);
void get_grade(long words_count, long sentences_count, long letters_count);

int main(void)
{
    // Get the text from input
    string text = get_string("Text: ");
    // Make it lowercase
    string text_lowercase = get_text_to_lowercase(text);
    // Analyze text to find the Grade
    analyze_text(text_lowercase);
}

// Split all words
void analyze_text(string text)
{
    // Initialize words, sentence and letters counts at 0
    long words_count = 0;
    long sentences_count = 0;
    long letters_count = 0;

    // Iterate through each char of the text
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        // If alphabetical, add 1 to the letters count
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            letters_count++;
        }
        // Else, if last char AND . or ! or ? add 1 to sentences and words count
        else if (i == length - 1 && (text[i] == '.' || text[i] == '!' || text[i] == '?'))
        {
            words_count++;
            sentences_count++;
        }
        // Else, if . or ! or ? add 1 to the sentences count
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences_count++;
        }
        // Else, if SPACE add 1 to the words count
        else if (text[i] == ' ')
        {
            words_count++;
        }
    }

    // Then, calls get_grade to get the grade
    get_grade(words_count, sentences_count, letters_count);
}

string get_text_to_lowercase(string text)
{
    // Iterates through the text to make it Lowercase using the strlen function from ctype
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        text[i] = tolower(text[i]);
    }

    // Then, return the Lowercased text
    return text;
}

void get_grade(long words_count, long sentences_count, long letters_count)
{
    // Transform the values in float to get their average
    float average_letters = (float) letters_count / words_count * 100;
    float average_sentences = (float) sentences_count / words_count * 100;

    // Calculate and Check the Grade value
    long index = round(0.0588 * average_letters - 0.296 * average_sentences - 15.8);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %li\n", index);
    }
}
