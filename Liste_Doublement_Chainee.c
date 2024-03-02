#include <stdio.h>
#include <stdlib.h>

typedef struct noued
{
    char date[20];
    float temp;
    struct noued *next;
    struct noued *prev;
} noeud;

void ajouteElement(noeud **debut)
{
    // allouer un espace memoire au nouveau element
    noeud *elt = (noeud *)malloc(sizeof(noeud));
    if (elt == NULL)
    {
        printf("Erreur lors de l'allocation de mémoire");
        exit(0);
    }

    // Saisie de la date et de la température
    printf("Saisir la date: ");
    fflush(stdin);
    gets(elt->date);
    fflush(stdout);

    printf("Saisir la temperature: ");
    scanf("%f", &elt->temp);

    // insersion
    elt->next = NULL;
    elt->prev = NULL;
    elt->next = *debut;
    if (*debut != NULL) // liste initialement non vide
        (*debut)->prev = elt;
    *debut = elt;
}

void affichage(noeud *debut)
{
    noeud *ptr = debut;
    while (ptr != NULL)
    {
        printf("date: %s / temp: %.2f\n", ptr->date, ptr->temp);
        ptr = ptr->next;
    }
}

void freeListe(noeud *debut)
{
    while (debut != NULL)
    {
        noeud *ptr = debut->next;
        debut->next = NULL;
        debut->prev = NULL;
        free(debut);
        debut = ptr;
    }
    exit(1);
}
void supprimeEltX(noeud **debut, float tempX)
{
    if (*debut != NULL) // la liste est non vide
    {
        noeud *ptr = *debut;
        while (ptr->temp != tempX && ptr->next != NULL)
        {
            ptr = ptr->next;
            if (ptr->temp == tempX)
            {
                if (ptr->prev != NULL) // n'est pas le premier element
                    ptr->prev->next = ptr->next;
                else
                    *debut = ptr->next;
                if (ptr->next != NULL) // n'est pas le dernier element
                    ptr->next->prev = ptr->prev;
                free(ptr);
            }
        }
    }
}

int main()
{
    noeud *liste = NULL;
    float tempX;
    ajouteElement(&liste);
    ajouteElement(&liste);
    ajouteElement(&liste);
    affichage(liste);
    printf("____________\n");
    printf("donner la valeur a supprimer: ");
    scanf("%f", &tempX);
    supprimeEltX(&liste, tempX);
    affichage(liste);
    freeListe(liste);
    return 0;
}