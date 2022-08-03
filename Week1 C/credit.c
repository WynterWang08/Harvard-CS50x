#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long creditnum;

    // check creditnum is correct
    do
    {
        creditnum = get_long("Number: ");
    }
    while (creditnum <= 0);

    // calculate second-to-last digit
    long newnum = creditnum / 10;
    int sumdigits = 0;
    while (newnum > 0)
    {
        int remainder = newnum % 10 * 2;
        if (remainder < 10)
        {
            sumdigits += remainder;
        }
        else
        {
            sumdigits += remainder % 10;
            remainder /= 10;
            sumdigits += remainder;
        }
        newnum /= 100;
    }

    // calculate first-to-last digit
    newnum = creditnum;
    while (newnum > 0)
    {
        sumdigits += newnum % 10;
        newnum /= 100;
    }

    // validity test
    if (sumdigits % 10 != 0)
    {
        printf("INVALID\n");
    }

    // calculate creditnum's length
    else
    {
        int length = 2;
        while (creditnum >= 100)
        {
            creditnum /= 10;
            length++;
        }

        // print results by judgment
        if ((creditnum == 34 || creditnum == 37) && length == 15)
        {
            printf("AMEX\n");
        }
        else if (creditnum >= 51 && creditnum <= 55 && length == 16)
        {
            printf("MASTERCARD\n");
        }
        else if (creditnum >= 40 && creditnum <= 49 && (length == 13 || length == 16))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
}