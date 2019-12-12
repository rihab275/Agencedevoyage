#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include"tree.h"
#include"crud.h"


void
on_AcceuilgestionVol_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
/*preparation du treeView*/
GtkWidget *p;
GtkWidget *p1;
FILE*f1=NULL;
vol v;
gtk_widget_hide (acceuil);
gestio_Vol = create_gestio_Vol ();
p=lookup_widget(gestio_Vol,"treeview2");
p1=lookup_widget(gestio_Vol,"treeview4");


j=0;

Voltree(p,"vols.txt");

j=0;

Voltree(p1,"vols.txt");

gtk_widget_show (gestio_Vol);

}

void
on_AcceuilgestionHotel_clicked         (GtkButton       *button,
                                        gpointer         user_data)

{
/*preparation du treeView*/
GtkWidget *p;
GtkWidget *p1;
FILE*f1=NULL;
hotel h;
gtk_widget_hide (acceuil);
gestion_Hotel = create_gestion_Hotel ();
p=lookup_widget(gestion_Hotel,"treeview1");
p1=lookup_widget(gestion_Hotel,"treeview3");
i=0;
Hoteltree(p,"hotels.txt");

i=0;
Hoteltree(p1,"hotels.txt");

gtk_widget_show (gestion_Hotel);

}



void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{


 	gchar *nom;
        gchar *typeChambre;
        gchar *dateAdmission;
        gchar *dateSortie;
        gint prix;
        gint nbChambre;

        int x;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget *p=lookup_widget(gestion_Hotel,"treeview1");
        GtkTreeSelection *selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {
                gtk_tree_model_get (model,&iter,0,&nom,1,&typeChambre,2,&dateAdmission,3,&dateSortie,4,&nbChambre,5,&prix,-1);//recuperer les information de la ligne selectionneé

                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestion_Hotel,"entry2")),dateAdmission);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestion_Hotel,"entry3")),dateSortie);

                gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(gestion_Hotel,"spinbutton4")),prix);
                gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(gestion_Hotel,"spinbutton3")),nbChambre);

                if(strcmp(typeChambre,"Simple")==0) x=0;
                if(strcmp(typeChambre,"Double")==0) x=1;




                gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(gestion_Hotel,"combobox2")),x);
		GtkWidget* msg=lookup_widget(gestion_Hotel,"label25");
                gtk_label_set_text(GTK_LABEL(msg),nom);
		


                gtk_widget_show(lookup_widget(gestion_Hotel,"button7"));//afficher le bouton modifier
        GtkWidget* msg1=lookup_widget(gestion_Hotel,"label27");
        gtk_widget_hide(msg1);

}



}


void
on_gestionHotel_Acceuil_clicked        (GtkButton       *button,
                                        gpointer         user_data)

{
gtk_widget_show (acceuil);
        gtk_widget_destroy (gestion_Hotel);

}

void
on_AjouterHotel_clicked                (GtkButton       *button,
                                      gpointer         user_data)
{

GtkWidget *cal1;
GtkWidget *cal2;
GtkWidget *combobox;
GtkWidget *labelNom;
GtkWidget *labelsuccess;
GtkWidget *labelCombo;
GtkWidget *labelExist;
FILE*f=NULL;
hotel h;
int jj1,mm1,aa1,jj2,mm2,aa2,b=1;

labelNom=lookup_widget(gestion_Hotel,"label9");
labelCombo=lookup_widget(gestion_Hotel,"label15");
labelExist=lookup_widget(gestion_Hotel,"label8");
labelsuccess=lookup_widget(gestion_Hotel,"label10");
combobox=lookup_widget(gestion_Hotel,"combobox1");
cal1=lookup_widget(gestion_Hotel,"calendar1");
cal2=lookup_widget(gestion_Hotel,"calendar2");
           gtk_widget_hide (labelsuccess);

strcpy(h.nom,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion_Hotel,"entry1"))));
// saisie controlé
if(strcmp(h.nom,"")==0){
                gtk_widget_show (labelNom);
b=0;

}else
{
           gtk_widget_hide (labelNom);
}

if(gtk_combo_box_get_active (GTK_COMBO_BOX(combobox))==-1){
                gtk_widget_show (labelCombo);
b=0;
}
else{

           gtk_widget_hide (labelCombo);
}
if(b==1){

h.nbChambre =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_Hotel,"spinbutton1")));
h.prix =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_Hotel,"spinbutton2")));
strcpy(h.typeChambre,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)));
//recuperer la date du calendrier jour,mois,annee
gtk_calendar_get_date (GTK_CALENDAR(cal1),
                       &aa1,
                       &mm1,
                       &jj1);
gtk_calendar_get_date (GTK_CALENDAR(cal2),
                       &aa2,
                       &mm2,
                       &jj2);
if(exist(h.nom)==1) {

                gtk_widget_show (labelExist);

}
else{
           gtk_widget_hide (labelExist);
f=fopen("hotels.txt","a+");
fprintf(f,"%s %s %d/%d/%d %d/%d/%d %d %d\n",h.nom,h.typeChambre,jj1,mm1+1,aa1,jj2,mm2+1,aa2,h.nbChambre,h.prix);
fclose(f);
                gtk_widget_show (labelsuccess);


/*mise a jour du treeView*/
GtkWidget *p;
p=lookup_widget(gestion_Hotel,"treeview1");
Hoteltree(p,"hotels.txt");



}
}

}

void
on_ModifierHotel_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
hotel h;
        strcpy(h.nom,gtk_label_get_text(GTK_LABEL(lookup_widget(gestion_Hotel,"label25"))));
        strcpy(h.typeChambre,gtk_combo_box_get_active_text(GTK_COMBO_BOX(lookup_widget(gestion_Hotel,"combobox2"))));
        strcpy(h.dateAdmission,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion_Hotel,"entry2"))));
        strcpy(h.dateSortie,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion_Hotel,"entry3"))));
        h.nbChambre =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_Hotel,"spinbutton3")));
        h.prix =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_Hotel,"spinbutton4")));

        supp(h.nom);
        ajout(h);
        Hoteltree(lookup_widget(gestion_Hotel,"treeview1"),"hotels.txt");
        GtkWidget* msg=lookup_widget(gestion_Hotel,"label26");
        gtk_widget_show(msg);


}
void
on_SupprimerHotel_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

 GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* p;
        GtkWidget *label;
        gchar* nom;
        label=lookup_widget(gestion_Hotel,"label27");
        p=lookup_widget(gestion_Hotel,"treeview1");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&nom,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

           supp(nom);// supprimer la ligne du fichier

           gtk_widget_hide (label);}else{
                gtk_widget_show (label);
        }


}
void
on_AjouterVol_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *cal1;
GtkWidget *cal2;
GtkWidget *comboboxDepart;
GtkWidget *comboboxDestination;
GtkWidget *comboboxCompanie;

GtkWidget *labelid;
GtkWidget *labelsuccess;
GtkWidget *labelComboDepart;
GtkWidget *labelComboDestination;
GtkWidget *labelComboCompanie;
GtkWidget *labelExist;
FILE*f=NULL;
vol v;
int jj1,mm1,aa1,jj2,mm2,aa2,b=1;

labelid=lookup_widget(gestio_Vol,"label38");
labelComboDepart=lookup_widget(gestio_Vol,"label40");
labelComboDestination=lookup_widget(gestio_Vol,"label41");
labelComboCompanie=lookup_widget(gestio_Vol,"label43");
labelExist=lookup_widget(gestio_Vol,"label37");
labelsuccess=lookup_widget(gestio_Vol,"label36");



comboboxDepart=lookup_widget(gestio_Vol,"combobox3");
comboboxDestination=lookup_widget(gestio_Vol,"combobox4");
comboboxCompanie=lookup_widget(gestio_Vol,"combobox5");



cal1=lookup_widget(gestio_Vol,"calendar3");
cal2=lookup_widget(gestio_Vol,"calendar4");
           gtk_widget_hide (labelsuccess);

strcpy(v.id,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestio_Vol,"entry4"))));

if(strcmp(v.id,"")==0){
                gtk_widget_show (labelid);
b=0;

}else
{
           gtk_widget_hide (labelid);
}

if(gtk_combo_box_get_active (GTK_COMBO_BOX(comboboxDepart))==-1){
                gtk_widget_show (labelComboDepart);
b=0;
}
else{

           gtk_widget_hide (labelComboDepart);
}

if(gtk_combo_box_get_active (GTK_COMBO_BOX(comboboxDestination))==-1){
                gtk_widget_show (labelComboDestination);
b=0;
}
else{

           gtk_widget_hide (labelComboDestination);
}


if(gtk_combo_box_get_active (GTK_COMBO_BOX(comboboxCompanie))==-1){
                gtk_widget_show (labelComboCompanie);
b=0;
}
else{

           gtk_widget_hide (labelComboCompanie);
}


if(b==1){

v.nbVols =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestio_Vol,"spinbutton5")));
v.prix =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestio_Vol,"spinbutton6")));
strcpy(v.depart,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxDepart)));
strcpy(v.destination,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxDestination)));
strcpy(v.companie,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxCompanie)));
//recuperer la date du calendar
gtk_calendar_get_date (GTK_CALENDAR(cal1),
                       &aa1,
                       &mm1,
                       &jj1);
gtk_calendar_get_date (GTK_CALENDAR(cal2),
                       &aa2,
                       &mm2,
                       &jj2);




if(exist_vol(v.id)==1) {

                gtk_widget_show (labelExist);

}
else{
           gtk_widget_hide (labelExist);

f=fopen("vols.txt","a+");
fprintf(f,"%s %s %s %s %d/%d/%d %d/%d/%d %d %d\n",v.id,v.depart,v.destination,v.companie,jj1,mm1+1,aa1,jj2,mm2+1,aa2,v.nbVols,v.prix);
fclose(f);
                gtk_widget_show (labelsuccess);


//mise a jour du treeView
GtkWidget *p;
p=lookup_widget(gestio_Vol,"treeview2");
Voltree(p,"vols.txt");



}

}





}
void
on_ModifierVol_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
	vol v;
        strcpy(v.id,gtk_label_get_text(GTK_LABEL(lookup_widget(gestio_Vol,"label57"))));
        strcpy(v.depart,gtk_combo_box_get_active_text(GTK_COMBO_BOX(lookup_widget(gestio_Vol,"combobox7"))));
        strcpy(v.destination,gtk_combo_box_get_active_text(GTK_COMBO_BOX(lookup_widget(gestio_Vol,"combobox6"))));
        strcpy(v.companie,gtk_combo_box_get_active_text(GTK_COMBO_BOX(lookup_widget(gestio_Vol,"combobox8"))));
        strcpy(v.date_depart,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestio_Vol,"entry5"))));
        strcpy(v.date_retour,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestio_Vol,"entry6"))));
        v.nbVols =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestio_Vol,"spinbutton7")));
        v.prix =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestio_Vol,"spinbutton8")));

        supprimer_vol(v.id);
        ajouter_vol(v);
        Voltree(lookup_widget(gestio_Vol,"treeview2"),"vols.txt");
        GtkWidget* msg=lookup_widget(gestio_Vol,"label60");
        gtk_widget_show(msg);




}
void
on_SupprimerVol_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* p;
        GtkWidget *label;
        gchar* id;
        label=lookup_widget(gestio_Vol,"label59");
        p=lookup_widget(gestio_Vol,"treeview2");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

           supprimer_vol(id);// supprimer la ligne du fichier

           gtk_widget_hide (label);}else{
                gtk_widget_show (label);
        }





}
void
on_gestionVol_Acceuil_clicked          (GtkButton       *button,
                                        gpointer         user_data)

{
gtk_widget_show (acceuil);
        gtk_widget_destroy (gestio_Vol);

}


void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

gchar *id;
        gchar *depart;
        gchar *destination;
        gchar *companie;
        gchar *date_depart;
        gchar *date_retour;
        gint prix;
        gint nbVols;

        gint x1=0,x2=0,x3;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget *p=lookup_widget(gestio_Vol,"treeview2");
        GtkTreeSelection *selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {
                gtk_tree_model_get (model,&iter,0,&id,1,&depart,2,&destination,3,&companie,4,&date_depart,5,&date_retour,6,&nbVols,7,&prix,-1);//recuperer les information de la ligne selectionneé

                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestio_Vol,"entry5")),date_depart);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestio_Vol,"entry6")),date_retour);

                gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(gestio_Vol,"spinbutton7")),nbVols);
                gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(gestio_Vol,"spinbutton8")),prix);


                if(strcmp(depart,"Tunisie")==0)	x1=0;		
                if(strcmp(depart,"Algerie")==0) x1=1;                
                if(strcmp(depart,"Marroc")==0)  x1=2 ;             

                if(strcmp(destination,"Tunisie")==0) x2=0;                 
                if(strcmp(destination,"Algerie")==0) x2=1;                
                if(strcmp(destination,"Marroc")==0)  x2=2; 

                if(strcmp(destination,"Allemagne")==0) x2=3;                 
                if(strcmp(destination,"Etat-Unis")==0) x2=4;                
                if(strcmp(destination,"Italie")==0)  x2=5;                

                if(strcmp(companie,"Tunisair")==0)  x3=0;              
                if(strcmp(companie,"Nouvelair")==0)       x3=1;        		  






                                 gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(gestio_Vol,"combobox7")),x1);
                                 gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(gestio_Vol,"combobox6")),x2);
                                 gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(gestio_Vol,"combobox8")),x3);





		GtkWidget* msg=lookup_widget(gestio_Vol,"label57");
                gtk_label_set_text(GTK_LABEL(msg),id);
		


                gtk_widget_show(lookup_widget(gestio_Vol,"button12"));//afficher le bouton modifier
        GtkWidget* msg1=lookup_widget(gestio_Vol,"label60"); 
        gtk_widget_hide(msg1);//cacher "vol modifié avec succes"


}







}


void
on_chercherHotel_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *p1;
GtkWidget *entry;
GtkWidget *labelType;
GtkWidget *nbResultat;
GtkWidget *message;
char type[30];
char chnb[30];
int b=0,nb;
entry=lookup_widget(gestion_Hotel,"entry7");
labelType=lookup_widget(gestion_Hotel,"label64");
p1=lookup_widget(gestion_Hotel,"treeview3");

strcpy(type,gtk_entry_get_text(GTK_ENTRY(entry)));
if(strcmp(type,"")==0){
  gtk_widget_show (labelType);b=0;
}else{
b=1;
gtk_widget_hide (labelType);}

if(b==0){return;}else{

nb=ChercherHotelTree(p1,"hotels.txt",type);//type entry ecrie par lutilisateur
/* afficher le nombre de resultats obtenue par la recherche */
sprintf(chnb,"%d",nb);
nbResultat=lookup_widget(gestion_Hotel,"label66");
message=lookup_widget(gestion_Hotel,"label65");
gtk_label_set_text(GTK_LABEL(nbResultat),chnb);//set_text n'accepte que chaine de caractere 

gtk_widget_show (nbResultat);
gtk_widget_show (message);




}

}


void
on_chercherVolclicked                  (GtkButton       *button,
                                        gpointer         user_data)
{



GtkWidget *p1;
GtkWidget *entry;
GtkWidget *labelCompanie;
GtkWidget *nbResultat;
GtkWidget *message;
char companie[30];
char chnb[30];
int b=0,nb;
entry=lookup_widget(gestio_Vol,"entry8");
labelCompanie=lookup_widget(gestio_Vol,"label70");
p1=lookup_widget(gestio_Vol,"treeview4");

strcpy(companie,gtk_entry_get_text(GTK_ENTRY(entry)));
if(strcmp(companie,"")==0){
  gtk_widget_show (labelCompanie);b=0;
}else{
b=1;
gtk_widget_hide (labelCompanie);}

if(b==0){return;}else{

nb=ChercherVolTree(p1,"vols.txt",companie);
/* afficher le nombre de resultats obtenue par la recherche */
sprintf(chnb,"%d",nb);
nbResultat=lookup_widget(gestio_Vol,"label71");
message=lookup_widget(gestio_Vol,"label72");
gtk_label_set_text(GTK_LABEL(nbResultat),chnb);

gtk_widget_show (nbResultat);
gtk_widget_show (message);




}









}


void
on_AcceuiCatalogue_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
/*preparation du treeView*/
GtkWidget *p;
GtkWidget *p1;
FILE*f1=NULL;

gtk_widget_hide (acceuil);
catalogue = create_catalogue ();
p=lookup_widget(catalogue,"treeview5");
p1=lookup_widget(catalogue,"treeview6");


i=0;

Hoteltree(p,"hotels.txt");

j=0;

Voltree(p1,"vols.txt");

gtk_widget_show (catalogue);
}


void
on_catalogue_Acceuil_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_show (acceuil);
 gtk_widget_destroy (catalogue);


}

