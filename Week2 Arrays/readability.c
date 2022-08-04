#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

// prototype
int letters(string text);
int words(string text);
int sentences(string text);


//main
int main(void)
{
    string text = get_string("Text: ");
    int l = letters(text);
    int s = sentences(text);
    int w = words(text);

    float L = ((float)l / (float)w) * 100;
    float S = ((float)s / (float)w) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index * 1);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }
}


// define function
// function_letters
int letters(string text)
{
    int letter = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isupper(text[i]) || islower(text[i]))
        {
            letter++;
        }
    }
    return letter;
}

// function_sentences
int sentences(string text)
{
    int sentence = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence++;
        }
    }
    return sentence;
}

// function_words
int words(string text)
{
    int word = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]))
        {
            word++;
        }
    }
    return word + 1;
}