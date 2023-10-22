# include <stdio.h>

void main()
{
    int t[10] = {4, 5, 3, 1, 7, 5, 9, 2, 4, 6};
    int p_min, aux, i, j, k;
    for (i = 0; i < 10; i++)
    {
        // recherche de la position de la valeur minimale dans la suite du tableau
        p_min = i;
        for (j = i + 1; j < 10; j++)
        {
            if (t[j] <= t[p_min])
            {
                p_min = j;
            }
        }
        // Permutation
        if (p_min != i)
        {
            aux = t[i];
            t[i] = t[p_min];
            t[p_min] = aux;  
        }         
    }
// Affichage
    for (int k =0; k< 10; k++)
    {
        printf ("%d, ", t[k]);
    }

}