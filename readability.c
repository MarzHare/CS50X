#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt user for text
    string text = get_string("Text: ");

    // Get # of letters, words & sentences
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Coleman-Liau index & grade assignments
    // They are floats for further accuracy. Then turned to ints and rounded.
    // L = average # letters per 100 words. S = average # sentences per 100 words.
    float L = (float)letters / (float)words * 100;
    float S = (float)sentences / (float)words * 100;
    float grade = 0.0588 * L - 0.296 * S - 15.8;
    if (grade >= 1 && grade <= 16)
    {
        printf("Grade %i\n", (int)round(grade));
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }

}

int count_letters(string text)
// Add a letter to the counter per each alphabetical (isalpha)
{
    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
// Add a word to the counter per each space (isspace), starting from 1
{
    int words = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isspace(text[i]))
        {
            words++;
        }
    }
    return words;
}

int count_sentences(string text)
// Add a sentence to the counter per each '.', '!', or '?'
// Unfortunately, it isn't sensitive to things like Mr. or Dr.
{
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}