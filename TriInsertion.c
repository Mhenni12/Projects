# include <stdio.h>

void main()
{
    int t[10] = {4, 5, 3, 1, 7, 5, 9, 2, 4, 6};
    int p, x, i, j, k;
    for (i = 1; i < 10; i++)
    {
        if (t[i] < t[i-1])
        {
            // Decalage
            p = i;
            x = t[p];
            while (t[p-1] > x && p > 0)
            {
                t[p] = t[p-1];
                p = p-1;
            }
            t[p] = x;
        }
    }
    //Affichage
    for (int k =0; k< 10; k++)
    {
        printf ("%d, ", t[k]);
    }

}