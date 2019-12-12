#include <gtk/gtk.h>

#include <time.h>

#include "TimeDate.h"//ce bib est specifique pour les dates et temps crees par yassine

/*-------------------structure_Reclamation_client----------------*/



typedef struct
{
int id;
char service[20];
char type[20];
char description[200];
char etat[20];
char reponse[200];
char date_rec[100] ;
char date_rep[100] ;
dateyassin date_service;


}Reclamation;


typedef struct
{
char id;
char service[20];
char type[20];
char description[200];
char etat[20];
char reponse[200];
char date_rec[100] ;
char date_rep[100] ;
dateyassin date_service;


}Reclamation1;

/*--------------Declaration CRUD reclamation ----------------------*/

void ajouter_Reclamation(Reclamation rc);

void afficher_Reclamation(GtkWidget *liste);

void supprimer_Reclamation(char cinn[20]);

void modifier_Reclamation(Reclamation rc);

int if_exist_reclamation(char*idrec);


