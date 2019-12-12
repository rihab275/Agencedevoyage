#include <gtk/gtk.h>



void
on_YasstreeviewRec_columns_changed     (GtkTreeView     *treeview,
                                        gpointer         user_data);

void
on_buttonAjouter_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonRepondre_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_repondreRecAA_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonClientEnvoyerRec_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonAjoutResVoit_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_YassbuttonLogin_clicked             (GtkWidget       *objet_graphic,
                                        gpointer         user_data);

void
on_buttonCancelY_clicked               (GtkWidget       *objet_graphic,
                                        gpointer         user_data);


void
on_YassbuttonInscri_clicked            (GtkWidget       *objet_graphic,
                                        gpointer         user_data);


/*void
on_YassbuttonInscri_clicked            (GtkButton       *button,
                                        gpointer         user_data);

*/

/*void
on_YassbuttonCatNA_clicked             (GtkButton       *button,
                                        gpointer         user_data);

*/


void on_YassbuttonCatNA_clicked(GtkWidget *objet_graphic, gpointer user_data);


void
on_YasstreeviewCatHtl_columns_changed  (GtkTreeView     *treeview,
                                        gpointer         user_data);

void
on_YasstreeviewCatVols_columns_changed (GtkTreeView     *treeview,
                                        gpointer         user_data);

void
on_YasstreeviewCatVoit_columns_changed (GtkTreeView     *treeview,
                                        gpointer         user_data);

void
on_YasstreeviewCatEx_columns_changed   (GtkTreeView     *treeview,
                                        gpointer         user_data);

/*
void
on_Y_button_inscription_V_clicked      (GtkButton       *button,
                                        gpointer         user_data);
*/


void
on_Y_button_inscription_V_clicked      (GtkWidget       *objetGraphic,
                                        gpointer         user_data);

void
on_button_quit_fromCR_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_retour_from_CR_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void on_YassbuttonRepondreRec_clicked(GtkWidget  *objet_graphic,
                                        gpointer         user_data);

/*void
on_YassbuttonRepRecAA_clicked          (GtkButton       *button,
                                        gpointer         user_data);
*/
void
on_YassbuttonRepRecAA_clicked          (GtkWidget       *objet_graphic,
                                        gpointer         user_data);


void
on_Y_button_quit_fromCRrec_clicked     (GtkWidget       *objet_graphic,
                                        gpointer         user_data);

void
on_Y_button_retour_from_CRec_clicked   (GtkWidget       *objet_graphic,
                                        gpointer         user_data);

void
on_Y_buttonRetour_fromRepRec_clicked   (GtkWidget       *objet_graphic,
                                        gpointer         user_data);



void
on_Yass_buttonQuit_fromMainW_clicked   (GtkWidget       *objet_graphic,
                                        gpointer         user_data);

void
on_y_button_backtoMainWind_clicked     (GtkWidget       *objet_graphic,
                                        gpointer         user_data);

void
on_YassbuttonAvezVousRec_clicked       (GtkWidget       *objet_graphic,
                                        gpointer         user_data);

void
on_YassbuttonClientEnvoyerRec_clicked  (GtkWidget       *objet_graphic,
                                        gpointer         user_data);

void
on_yass_button_affichRecClient_clicked (GtkWidget       *objet_graphic,
                                        gpointer         user_data);



void
on_button_Retour_VosRec__EspaceResC_clicked
                                        (GtkWidget       *objet_graphic,
                                        gpointer         user_data);

void
on_Y_button_EspaceRecAdmin_clicked     (GtkWidget       *objet_graphic,
                                        gpointer         user_data);

void
on_Y_button_EspaceRecAgent_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_Y_button_AjouterRecClient_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_Y_button_affichRecClient_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_Y_button_Retour_fromRecClient_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_Y_button_ValiderRecEspaceC_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_Yassbutton_Modif_VosRec_clicked     (GtkWidget       *objet_graphic,
                                        gpointer         user_data);

void
on_Yassbutton_Supp_VosRec_clicked      (GtkWidget       *objet_graphic,
                                        gpointer         user_data);

void
on_Yasstreeview_VosRec_row_activated (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);


void
on_Yasstreeview_VosRec_columns_changed   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);	


void
on_ybutton_modifier_car_clicked        (GtkWidget       *objet_graphic,
                                        gpointer         user_data);

void
on_ybutton_suppcar_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_y_button_rechcar_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_ybutton_ajoutercar_clicked          (GtkButton       *button,
                                        gpointer         user_data);


void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_YassbuttonVoit_GestWind_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_Yassbotn_CheckId_UpdateRec_clicked  (GtkWidget       *objet_graphic,
                                        gpointer         user_data);

void
on_yassbuttonmodifvoit_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_yassbuttonsupprimervoiture_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_ybuttonretour54_clicked             (GtkButton       *button,
                                        gpointer         user_data);
