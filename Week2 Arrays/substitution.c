#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


// prototype
int validate(string key);
string cryptosystem(string keyword, string text);


// main
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    string key = argv[1];
    int check = validate(key);

    if (check == 1)
    {
        return 1;
    }

    if (check == 0)
    {
        string plaintext = get_string("plaintext: ");
        string new = cryptosystem(key, plaintext);
        printf("ciphertext: %s\n", new);
    }

    return 0;
}


// define function
// function validate
int validate(string key)
{
    int n = strlen(key);

    if (n != 26)
    {
        printf("Key must contain 26 letters.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (key[i] == key[j])
            {
                printf("Alphabets cannot repeat\n");
                return 1;
            }
        }
    }
    return 0;
}

// function cryptosystem
string cryptosystem(string keyword, string text)
{
    int n = strlen(text);
    for (int i = 0; i < n; i++)
    {
        if (islower(text[i]))
        {
            text[i] = tolower(keyword[text[i] - 97]);
        }
        else if (isupper(text[i]))
        {
            text[i] = toupper(keyword[text[i] - 65]);
        }
    }
    return text;
}