#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    // User starts program with 1 command-line argument
    // This command-line argument (argv[1]) will be "key". 1 positive int.
    // If not, print error message and return 1
    if (argc == 2)
    {
        bool valid_digit = only_digits(argv[1]);
        if (valid_digit == true)
        {
            // Turn "key" string into an int
            int key = atoi(argv[1]);

            // Prompt for plaintext
            string plaintext = get_string("plaintext:  ");

            // Encrypt plaintext
            printf("ciphertext: ");

            int i;
            int n;
            for (i = 0, n = strlen(plaintext); i < n; i++)
            {
                // Rotate characters to fit the key
                char cipher = rotate(plaintext[i], key);
                // Output ciphertext
                printf("%c", cipher);
            }
            // Newline + return 0 (program worked)
            printf("\n");
            return 0;
        }

        else
            // If key is not a valid digit
        {
            printf("Feed me a lovely integer. But just one. I'm on a diet.\n");
            return 1;
        }
    }
    else
        // If more than 2 command-line arguments (argc!=2)
    {
        printf("Feed me a lovely integer. But just one. I'm on a diet.\n");
        return 1;
    }
}


// Function to make sure the key is a number
bool only_digits(string s)
{
    int i;
    int n;
    for (i = 0, n = strlen(s); i < n; i++)
    {
        if (isdigit(s[i]))
        {
            
        }
        else
        {
            return false;
        }
    }
    return true;
}


// Function to encrypt
// We subtract the value of 'A' or 'a' from the char at hand to do the math
// Then we add it again
// (How exactly is this giving me only alpha chars?)
char rotate(char c, int n)
{
    if (isalpha(c))
    {
        if (isupper(c))
        {
            c = c - 'A';
            c += n;
            c = c % 26;
            c = c + 'A';
        }
        else if (islower(c))
        {
            c = c - 'a';
            c += n;
            c = c % 26;
            c = c + 'a';
        }
        return c;
    }

    else
    {
        return c;
    }
}