#include<stdio.h>
#include<stdlib.h>
#include "ArrNdMat.h"


// cette fonction cree une matrice de taille N
int ** create_matrix(int N)
{
    int i=0,j=0, **M;

    M=(int **)malloc(N*sizeof(int *));
    if (M==NULL)
    {
        printf("no memory for Mat");
        return NULL ;
    }
    for (i=0;i<N;i++)
    {
        *(M+i)=(int *)malloc(N*sizeof(int));
        if (*(M+i)==NULL)
        {
            printf("no memory for row + %d",i);
            return NULL ;
        }
    }

    for (i=0;i<N;i++)
    {
        for (j=0;j<N;j++)
        {
            M[i][j]=0;
        }
    }

    return M ;
}

// cette fonction affiche la matrice
void display_matrix(int **M, int size)
{

    int i=0,j=0;
    for (i=0;i<size;i++)
    {
        for (j=0;j<size;j++)
        {
            printf("%d   ",M[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}


//cette fonction annulle la matrice
void zero_matrix(int ** M, int size)
{
    int i=0,j=0 ;

    for (i=0;i<size;i++)
    {
        for (j=0;j<size;j++)
        {
            M[i][j]=0;
        }
    }
}


// cette fonction ajoute a une liste chainee un noeud et renvoie l'adresse
couple * add_couple(couple *head, int value1, int value2)
{
    couple *now;

    now=(couple *)malloc(sizeof(couple));
    now->next=head;
    now->i=value1;
    now->j=value2;
    return now;

}






// cette fonction detruit la liste .. free les elements
void destroy_list(couple * head)
{
    couple *nexthead;
    while(head!=NULL)
    {
        nexthead=head->next;
        free(head);
        head=nexthead;
    }
}



// cette fonction calcule le nobre de voisins d'une cellule donnee

int nbr_voisins(int **M,int i, int j,int size)
{
    int s=0;
    // les 8 cas particuliers (les coins et les cotes )
    if ((i==0)||(i==size-1)||(j==0)||(j==size-1))
    {
        if (i==0)
        {
            if (j==0)
            {
                s=M[i][j+1]+M[i+1][j]+M[i+1][j+1];
                return s;
            }
            else
            {
                if (j==size-1)
                {
                    s=M[i][j-1]+M[i+1][j-1]+M[i+1][j];
                    return s;
                }

                else
                    {
                        s=M[i][j-1]+M[i][j+1]+M[i+1][j-1]+M[i+1][j]+M[i+1][j+1];
                        return s;
                    }

            }
        }
        else
        {
            if (i==size-1)
            {
                if (j==0)
                {
                    s=M[i-1][j]+M[i-1][j+1]+M[i][j+1];
                    return s;
                }
                else
                {
                    if (j==size-1)
                    {
                        s=M[i-1][j-1]+M[i-1][j]+M[i][j-1];
                        return s;
                    }
                    else
                    {
                        s=M[i-1][j-1]+M[i-1][j]+M[i-1][j+1]+M[i][j-1]+M[i][j+1];
                        return s ;
                    }


                }
            }
            else
            {
                if (j==0)
                {
                    s=M[i-1][j]+M[i-1][j+1]+M[i][j+1]+M[i+1][j]+M[i+1][j+1];
                    return s ;
                }
                else
                {
                    s=M[i-1][j-1]+M[i-1][j]+M[i][j-1]+M[i+1][j-1]+M[i+1][j];
                    return s;
                }

            }
        }
    }
    // l'autre cas au milieu de la matrice
    else
    {
       s=M[i-1][j-1]+M[i-1][j]+M[i-1][j+1]+M[i][j-1]+M[i][j+1]+M[i+1][j-1]+M[i+1][j]+M[i+1][j+1];
       return s;
    }
}



// cette fonction recoit une msatrice et renvoit une liste chainee comportant les cellules vivantes dans la prochaine generation
couple * detecter_les_vivants(int ** M,int N)
{
    couple *head=NULL;

    int i=0,j=0;

    for (i=0;i<N;i++)
    {
        for (j=0;j<N;j++)
        {
            // les deux regles

            if (M[i][j]==1) // cellule vivante
            {
              //cellule vivante dont le nombre des voisins est 2 ou 3
                if ((nbr_voisins(M,i,j,N)==3)||(nbr_voisins(M,i,j,N)==2)) //
                {
                   
                    {
                        head=add_couple(head,i, j);

                    }

                }

            }
            else // cellule morte
            // cellule morte ayant 3 voisins vivant

                if (nbr_voisins(M,i,j,N)==3)
                {
                    head=add_couple(head,i, j);
                }


        }
    }
    return head ;
}



//cette fontion recoit une matrice  et une liste chainee qui comporte les coordonnees, elle affecte a ses coords la val 1
void  new_generation(int ** M,couple * head )
{
    if (head==NULL)
    {
        printf("everyone is dead or smth is wrong");
    }
    else
    {


    while (head!= NULL)
    {
        M[head->i][head->j]=1;
        head=head->next;
    }
    }
}
