#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


// prototype
bool digits(string s);
char cryptosystem(char letter, int key);


// main
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string d = argv[1];
    bool check = digits(d);

    if (check == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        int k = atoi(d);
        string plaintext = get_string("plaintext: ");
        printf("ciphertext: ");

        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            char new = cryptosystem(plaintext[i], k);
            printf("%c", new);
        }
        printf("\n");
    }
    return 0;
}


// define function
// function digits
bool digits(string s)
{
    for (int i = 0, n  = strlen(s); i < n; i++)
    {
        if (!isdigit(s[i]))
        {
            return 0;
        }
    }
    return 1;
}

// function cryptosystem
char cryptosystem(char letter, int key)
{
    char new = letter;
    if (isupper(letter))
    {
        letter -= 65;
    }
    else if (islower(letter))
    {
        letter -= 97;
    }

    if (!isalpha(new))
    {
        return new;
    }

    char cipher = (letter + key) % 26;
    if (isalpha(new))
    {
        if (isupper(new))
        {
            cipher += 65;
        }
        else if (islower(new))
        {
            cipher += 97;
        }
    }
    return cipher;
}