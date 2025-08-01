#include <cs50.h>
#include <stdio.h>

void pyramid(int number_of_rows);
void row(int number_of_rows, int items_per_row);
void items(int items_per_row);

int main(void)
{
    // While height is not between 1 and 8, prompts the user again
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    pyramid(height);
}

// Prints out the entire pyramid
void pyramid(int number_of_rows)
{
    // Could've used a for loop as well but I wanted to
    // be sure I truly understood the do loop

    // For each row, calls the "row" function with the
    // number of rows and the items per row
    int items_per_row = 0;
    do
    {
        row(number_of_rows, items_per_row + 1); // + 1 avoids sending an items per row value at 0
        items_per_row++;
    }
    while (items_per_row < number_of_rows); // This allows me to not having to put "<="
}

// Prints out the number or items per row
void row(int number_of_rows, int items_per_row)
{
    // For each row, takes value of the sub of numbers of rows and items per row
    // The calculated value corresponds to the missing space between the bricks
    for (int space = 0; space < number_of_rows - items_per_row; space++)
    {
        printf(" ");
    }
    // Then calls the items function that simply takes for input the number of
    // items per row and print its value in bricks
    items(items_per_row);

    // Then prints out the spaces
    printf("  ");

    // Calls the items function once again for the second part of the pyramid
    items(items_per_row);

    // Goes to next line to allow a good indent on the rows of the pyramid
    printf("\n");
}

// Simply prints out the actual number of bricks
void items(int items_per_row)
{
    for (int col = 0; col < items_per_row; col++)
    {
        printf("#");
    }
}