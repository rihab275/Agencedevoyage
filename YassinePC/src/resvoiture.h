#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
typedef struct vol vol;
struct vol{
char id[30];
char depart[30];
char destination[30];
//char companie[30];
char date_depart[30];
char date_retour[30];
//int nbVols;
int prix;
};

typedef struct hotel hotel;
struct hotel{
char nom[30];
char typeChambre[30];
char dateAdmission[30];
char dateSortie[30];
int nbChambre;
int prix;
};
int i,j;

GtkWidget *acceuil;
  GtkWidget *gestion_Hotel;
  GtkWidget *gestio_Vol;
  GtkWidget *catalogue;



void ajouter_vol( vol v);
int exist_vol(char*id);
void supprimer_vol(char*id);
