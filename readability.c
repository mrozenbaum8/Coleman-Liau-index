#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text_a);
int count_words(string text_b);
int count_sentences(string text_c);

int main(void)
{
    string text = get_string("Text: ");
    float letters = count_letters(text);
    float words = count_words(text);
    float sentences = count_sentences(text);
    //Calculate letters per 100 words.
    float L = ((letters / words) * 100);
    //Calculate sentences per 100 words.
    float S = ((sentences / words) * 100);
    //Putting it all together.
    float index = (0.0588 * L - 0.296 * S - 15.8);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 1 && index <= 16)
    {
        printf("Grade %i\n", (int) round(index));
    }
    else
    {
        printf("Grade 16+\n");
    }
}

//Calculate how many letters.
int count_letters(string text_a)
{
    int score = 0;

    for (int i = 0, n = strlen(text_a); i < n; i++)
    {
        if (isupper(text_a[i]) || islower(text_a[i]))
        {
            score += 1;
        }
    }
    return score;
}

//Calculate how many words.
int count_words(string text_b)
{
    int score2 = 1;
    for (int i = 0, n = strlen(text_b); i < n; i++)
    {
        if (text_b[i] == ' ')
        {
            score2 += 1;
        }
        else
        {
            score2 += 0;
        }
    }
    return score2;
}

//Calculate how many sentences.
int count_sentences(string text_c)
{
    int score3 = 0;
    for (int i = 0, n = strlen(text_c); i < n; i++)
    {
        if (text_c[i] == '.' || text_c[i] == '!' || text_c[i] == '?')
        {
            score3 += 1;
        }
        else
        {
            score3 += 0;
        }
    }
    return score3;
}