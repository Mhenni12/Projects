# include <stdio.h>
# include <string.h>

void main()
{
    char ch[100];
    char mots[20][20];  // tableau de chaines
    int occ[20];
    int i_ch = 0, j_mot = 0, k_tab = 0, comp = 0;

    printf("donner une chaine: ");
    gets(ch);

    
    // split
    for(i_ch = 0; i_ch <= strlen(ch); i_ch++)
    {
        if (ch[i_ch] == ' ' || ch[i_ch] == '\0')
        {
            // declare la fin d'un mot
            mots[k_tab][j_mot] = '\0';
            k_tab++;
            j_mot = 0;
        }  
        else
        {
            // ajout d'un caractere alphabetique
            mots[k_tab][j_mot] = ch[i_ch];
            j_mot++;
        }      
    }

    //occurence
    for(int i = 0; i < k_tab; i++)
    {
        comp = 0;
        for (int j = 0; j < k_tab; j++)
        {
            if (strcmp(mots[j], mots[i]) == 0)
            {
                comp++;
            }
        }
        occ[i] = comp;
    }

    // suppression des cases repetees
    for(int i = 0 ; i < k_tab-1 ; i++)
    {
        for(int j = i+1 ; j < k_tab ; j++)
        {
            while(strcmp(mots[j], mots[i]) == 0)
            {
                for(int k = j ; k < k_tab ; k++)
                {
                    strcpy(mots[k], mots[k+1]);
                    occ[k] = occ[k+1];
                }
                k_tab--;
            }
        }
    }
    
    // afficher les mots repetes et combien de fois ils ont ete repetes
    for (int l = 0; l < k_tab; l++)
    {
        if (occ[l] > 1)
        printf("%s-%d\n", mots[l], occ[l]);
    }

}
