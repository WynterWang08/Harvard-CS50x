#include <cs50.h>
#include <stdio.h>

// prototype
void spaces(int n);
void hashes(int n);


// main
int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    for (int i = 1; i <= height; i++)
    {
        spaces(height - i);
        hashes(i);
        printf("\n");
    }
}


// define function
// function spaces
void spaces(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }
}

// function hashes
void hashes(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
}