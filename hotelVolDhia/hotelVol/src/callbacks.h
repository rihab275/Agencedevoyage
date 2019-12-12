#include <gtk/gtk.h>
typedef struct vol vol;
struct vol{
char id[30];
char depart[30];
char destination[30];
char companie[30];
char date_depart[30];
char date_retour[30];
int nbVols;
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




void
on_AcceuilgestionVol_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_AcceuilgestionHotel_clicked         (GtkButton       *button,
                                        gpointer         user_data);


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);
void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_gestionHotel_Acceuil_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_AjouterHotel_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_ModifierHotel_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_SupprimerHotel_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_AjouterVol_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_ModifierVol_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_SupprimerVol_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_gestionVol_Acceuil_clicked          (GtkButton       *button,
                                        gpointer         user_data);


void
on_chercherHotel_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_chercherVolclicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_AcceuiCatalogue_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_catalogue_Acceuil_clicked           (GtkButton       *button,
                                        gpointer         user_data);
