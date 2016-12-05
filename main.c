#include <stdio.h>
#include <stdlib.h>
#include "ArrNdMat.h"


int main()
{
    int **M,N=0,nombre=0,i=0,x=0,y=0,k=0;
    couple *head=NULL , *nexthead;

    printf("entrer la taille de la matrice ");
    scanf("%d",&N);

    M=create_matrix(N);


    // saisit des cellules vivantes

    printf("entrer le nombre de cellules vivantes ");
    scanf("%d",&nombre);
    printf("entrer le nombre de cellules vivantes ");
    scanf("%d",&nombre);
    
    for (i=0;i<nombre;i++)
    {   do
    {
        printf("entrez le coord x de la cellules %d \n",i );
        scanf("%d",&x);
    } while (x<N&&x>=0);
         do
    {
        printf("entrez le coord y de la cellules %d \n",i );
        scanf("%d",&y);
    } while (y<N&&y>=0);

        M[x][y]=1;
    }

    // nombre des generations

    printf("entrer le nombre de generation ");
    scanf("%d",&k);
    printf("\n");


    // traitement


    for (i=0;i<k;i++)
    {

    printf("generation %d\n\n",i+1);

    display_matrix(M,N);

    head=detecter_les_vivants(M,N);

    if (head==NULL)
        break ;

    zero_matrix(M,N);

    new_generation(M,head);

    while(head!=NULL)    // free de la chaine
    {
        nexthead=head->next;
        free(head);
        head=nexthead;
    }
    head=NULL;

    }

    // free de la matrice

    for (i=0;i<N;i++)
    {
        free(*(M+i));
    }
    free(M);





    return 0;
}
