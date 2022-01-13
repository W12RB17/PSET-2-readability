//this program gives the grade of a text based on Coleman-Liau index

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    float letters = 0;
    int i = 0; 
    float words = 0;
    float sentences = 0;

    string text = get_string("\nText: ");

    for (int i = 0; i < strlen(text); i++) 
    {
        if (isalpha(text[i]))  
        letters++;  
    }
    //printf("%f letters\n", letters); 
    for (i = 0; text[i] != '\0'; i++)
    {
        if((text[i] != ' ' && text[i+1]==' ')||(text[i+1] == '\0' && text[i] != ' '))
        {
            words++;
        }    
    }
    //printf("%f words\n", words );
    for (i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    float L = (letters / words) * 100;
    float S = ((sentences * 100) / words);
    float grade = (0.0588 * L )-( 0.296 * S) - 15.8;
    //printf("%f sentences\n", sentences );
    //printf("L = %f, S = %f, grade = %.f", L, S, grade);
    if (grade > 16)
    {
        printf("\nGrade: 16+\n\n");
    }
    else
    {
        printf("\nGrade: %.f\n\n", round(grade));
    }
}