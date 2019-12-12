#include <gtk/gtk.h>

typedef struct
{
char id[15];
char marque[15];
char modele[15];
char carrosserie[15];
char etat[15];
char prix[15];
char reduction[15];
}voiture;





void ahmed_ajouter_voiture(voiture v);
void ahmed_afficher_voiture(GtkWidget *liste);
void ahmed_supprimer_voiture_menu(char id1[]);
voiture ahmed_modifier_voiture_menu(voiture v);

