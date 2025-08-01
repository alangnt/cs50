#include <cs50.h>
#include <stdio.h>
#include <string.h>

// AMEX : 15-long - Start with 34-37
// MASTERCARD : 16-long - Start with 51 to 55
// VISA: 13-16-long - Start with 4

void is_card_valid(long card_number);
void card_type(long card_number, int card_length);
long power_of_ten_minus_two(int card_length);

int main(void)
{
    // First, verifies if a valid credit card number
    long card_number = get_long("Number: ");
    is_card_valid(card_number);
}

// Luhn's Algorithm - First Validation
void is_card_valid(long card_number)
{
    int card_length = 0;
    int first_two_digts = 0;

    long new_card_number = card_number;
    long division_size = 10;
    int last_digit;

    int last_digits_sum = 0;
    int last_non_multiplied_digits = 0;

    bool add_number = false;

    // While new_card_number isn't 0, keeps doing
    do
    {
        // Takes the last digit of new_card_number
        last_digit = new_card_number % 10;

        // If add number is true
        if (add_number)
        {
            // Multiplies the last digit by 2
            int mult = last_digit * 2;

            // If it gives a number higher than 9, splits in two
            if (mult >= 10)
            {
                last_digits_sum += mult % 10;
                last_digits_sum += mult / 10;
            }
            // Otherwise just adds it to the last_digits_sum
            else
            {
                last_digits_sum += mult;
            }
        }
        // Otherwise
        else
        {
            // If not true, adds the last_digit to the last_non_multiplied_digits
            last_non_multiplied_digits += last_digit;
        }

        // Switch add number between true and false
        add_number = !add_number;

        // For each step, divide card number by the division size
        // The Do loop can stop because of this part
        new_card_number = card_number / division_size;
        // Then makes the division size a power of 10 higher
        division_size = division_size * 10;

        // And then adds 1 to the card length
        card_length++;
    }
    while (new_card_number != 0);

    // Finally, addds the last digits sum to the last non multiplied digits
    int final_sum = 0;
    final_sum = last_digits_sum + last_non_multiplied_digits;

    // Verifies that the last digit is 0
    if (final_sum % 10 == 0)
    {
        // If it is, checks the Type of the Card
        card_type(card_number, card_length);
    }
    else
    {
        // Otherwise don't bother and immediately print INVALID
        printf("INVALID\n");
    }
}

// Acts as the second validation
void card_type(long card_number, int card_length)
{
    long power_of_ten = power_of_ten_minus_two(card_length);
    long first_two_digits = card_number / power_of_ten;

    // Checks if Digits correspond to any Card Type and if there's a corresponding lenght as well
    if ((first_two_digits == 34 || first_two_digits == 37) && card_length == 15)
    {
        printf("AMEX\n");
    }
    else if (first_two_digits >= 51 && first_two_digits <= 55 && card_length == 16)
    {
        printf("MASTERCARD\n");
    }
    else if (first_two_digits >= 40 && first_two_digits < 50 &&
             (card_length == 13 || card_length == 16))
    {
        printf("VISA\n");
    }
    // If none is correct, prints INVALID
    else
    {
        printf("INVALID\n");
    }
}

long power_of_ten_minus_two(int card_length)
{
    // Initialize the For Loop at 2, to get the power of ten required
    // to only get the first two digits of the card number
    long power_of_ten = 1;
    for (int i = 2; i < card_length; i++)
    {
        power_of_ten *= 10;
    }
    return power_of_ten;
}
