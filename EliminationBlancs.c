#include <stdio.h>
#include <string.h>

void main()
{
    char ch[100];

    printf("donner une chaine:");
    gets(ch);
    //exemple:  "Hello \n\n     \t   .      Nice\n\n to\t\n    meet          you\t."

    char ch1[100];
    ch1[0] = ch[0];
    int j = 1;
    
    for (int i = 1; ch[i] != '\0' ; i++)
    {
        if (ch[i] == ' ' || ch[i] == '\t' || ch[i] == '\n')
        {
            if (ch[i-1] == ' ' || ch[i-1] == '\t' || ch[i-1] == '\n')   // elimine les blancs consecutifs
            {
                continue;
            }
            else
            {
                ch1[j] = ch[i];
            }
        }
        else  //le caractere n'est pas un blanc
        {
            ch1[j] = ch[i];
        }
        j++;

    }
    printf("La chaine modifiee: %s", ch1);
}