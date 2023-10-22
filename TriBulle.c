# include <stdio.h>

void main()
{
    int t[10] = {4, 5, 3, 1, 7, 5, 9, 2, 4, 6};
    int test = 0, aux = 0;
    
    while (!test)
    {
        test = 1;
        for(int i = 0; i < 9; i++)
        {
            if (t[i] > t[i+1])
            {
                aux = t[i];
                t[i] = t[i+1];
                t[i+1] = aux;
                test = 0;  // s'il y a une permutation
            }
        }
    }
// Affichage
    for (int i =0; i< 10; i++)
    {
        printf ("%d, ", t[i]);
    }

    
}