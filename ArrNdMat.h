#ifndef ARRNDMAT_H_INCLUDED
#define ARRNDMAT_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>

int ** create_matrix(int N);
void display_matrix(int **M, int size);
int nbr_voisins(int **M,int i, int j,int size);

typedef struct couple couple ;
struct couple
{
    int i;
    int j;
    couple *next;
};

couple * add_couple(couple *head, int i, int j);
couple * detecter_les_vivants(int ** M,int N);
void display_list(couple *head);
void zero_matrix(int ** M, int size);
void  new_generation(int ** M,couple * head );
void freehead(couple * head);
void display_list2(couple *head);

#endif // ARRNDMAT_H_INCLUDED
