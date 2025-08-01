#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool check_if_all_alpha(string key);
bool check_if_all_unique(string key);
string get_cipher_text(string key);
long get_key_index(char character);

const string Alphabet = "abcdefghijklmnopqrstuvwxyz";

int main(int argc, string argv[])
{
    // Check if a key is provided
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Initialize a var Key because we'll be reusing it
    // Only after verifying that it exists
    string key = argv[1];

    // Check if key is 26 chars long
    if (strlen(key) != 26)
    {
        printf("They key must contain 26 characters.\n");
        return 1;
    }

    // Check if key only contains alphabetical chars
    bool is_all_alpha = check_if_all_alpha(key);
    if (is_all_alpha == false)
    {
        printf("The key must only contain alphabetical characters.\n");
        return 1;
    }

    // Check if key only contains unique chars
    bool is_all_unique = check_if_all_unique(key);
    if (is_all_unique == false)
    {
        printf("They key must only contain unique characters.\n");
        return 1;
    }

    // If all the conditions are checked, we can get our cipher text
    string cipher_text = get_cipher_text(key);

    // And print it
    printf("ciphertext: %s\n", cipher_text);

    // Then return 0 to show everything went smoothly
    return 0;
}

// Check if key only contains alphabetical chars
bool check_if_all_alpha(string key)
{
    for (int i = 0, length = strlen(key); i < length; i++)
    {
        bool is_alpha = isalpha(key[i]);
        if (is_alpha == false)
        {
            return false;
        }
    }
    return true;
}

// Check if key only contains unique chars
bool check_if_all_unique(string key)
{
    // Initialize an Array of 26 zeros
    int seen_count[26] = {0};

    // For each character in the key, checks if already seen
    for (int i = 0, length = strlen(key); i < length; i++)
    {
        // This way index will always be equals to the corresponding index
        // since we're using 'a's ASCII number
        int index = tolower(key[i]) - 'a';

        // If it's equal to 1, it means it's a duplicate
        if (seen_count[index] == 1)
        {
            return false;
        }
        // Else, we haven't seen it already so we increment it
        else
        {
            seen_count[index] = 1;
        }
    }

    return true;
}

// Only triggers if all validated
// Prompt user for a text and ciphers it using the key
string get_cipher_text(string key)
{
    // First prompt the user for a string
    string plain_text = get_string("plaintext: ");

    // For each char of the text, replaces it with the corresponding key index
    for (int i = 0, length = strlen(plain_text); i < length; i++)
    {
        // Check if alphabetical otherwise leave as is
        if (isalpha(plain_text[i]))
        {
            // First we get the index from the Alphabet to get the corresponding key index to use
            int index = get_key_index(plain_text[i]);

            // Then we check if they are lower or upper
            // Since it should be insensitive
            // If text char is 'a' to 'z', make key tolower
            if (islower(plain_text[i]))
            {
                plain_text[i] = tolower(key[index]);
            }
            // If text char is 'A' to 'Z', make key toupper
            else
            {
                plain_text[i] = toupper(key[index]);
            }
        }
    }

    // Finally, return the new ciphered text
    return plain_text;
}

// Iterates through the Alphabet const string to find the corresponding char index
// No default return because a prior validation has been done
// and this function is only called if character is alphabetical
long get_key_index(char character)
{
    int index = 0;

    // While character is not equals to the current alphabet index
    // increment it by 1
    while (tolower(character) != Alphabet[index])
    {
        index++;
    }

    return index;
}
