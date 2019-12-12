#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include <string.h>
#include "ahmed_voiture.h"


void
on_ahmed_button_afficher_voiture_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{ 
	GtkWidget *old;
	GtkWidget *new;
	GtkWidget *treeview;

	old=lookup_widget(objet,"ahmed_windowajoutervoitureprestation");
	new=create_ahmed_windowmenuvoitureprestation();

	gtk_widget_show(new);
	treeview=lookup_widget(new,"ahmed_treeview_main_voiture");
	ahmed_afficher_voiture(treeview);
	gtk_widget_destroy(old);

}


void
on_ahmed_button_valider_voiture_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	voiture v;		
	GtkWidget *Ahmed_entryid;	
	GtkWidget *comboboxentrymarque_voiture;
	GtkWidget *comboboxentrymodele_voiture;
	GtkWidget *comboboxentrycarrosserie_voiture;
	GtkWidget *comboboxentryetat_voiture;
	GtkWidget *Ahmed_entryprix;
	GtkWidget *ahmed_entryreductionvoiture;

	GtkWidget *ahmed_windowajoutervoitureprestation;	
	ahmed_windowajoutervoitureprestation=lookup_widget(objet,"ahmed_windowajoutervoitureprestation");

	Ahmed_entryid=lookup_widget(objet,"Ahmed_entryid");	
	comboboxentrymarque_voiture=lookup_widget(objet,"comboboxentrymarque_voiture");
	comboboxentrymodele_voiture=lookup_widget(objet,"comboboxentrymodele_voiture");
	comboboxentrycarrosserie_voiture=lookup_widget(objet,"comboboxentrycarrosserie_voiture");
	comboboxentryetat_voiture=lookup_widget(objet,"comboboxentryetat_voiture");
	Ahmed_entryprix=lookup_widget(objet,"Ahmed_entryprix");
	ahmed_entryreductionvoiture=lookup_widget(objet,"ahmed_entryreductionvoiture");

	strcpy(v.id,gtk_entry_get_text(GTK_ENTRY(Ahmed_entryid)));	
	strcpy(v.marque,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentrymarque_voiture)));
	strcpy(v.modele,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentrymodele_voiture)));
	strcpy(v.carrosserie,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentrycarrosserie_voiture)));
	strcpy(v.etat,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentryetat_voiture)));
	strcpy(v.prix,gtk_entry_get_text(GTK_ENTRY(Ahmed_entryprix)));
	strcpy(v.reduction,gtk_entry_get_text(GTK_ENTRY(ahmed_entryreductionvoiture)));
	

	ahmed_ajouter_voiture(v);	



}


void
on_ahmed_button_retour_ajouter_voiture_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *old;
	GtkWidget *new;
	GtkWidget *treeview;

	old=lookup_widget(objet,"ahmed_windowajoutervoitureprestation");
	new=create_ahmed_windowmenuvoitureprestation();

	gtk_widget_show(new);
	treeview=lookup_widget(new,"ahmed_treeview_main_voiture");
	ahmed_afficher_voiture(treeview);
	gtk_widget_destroy(old);


}


void
on_ahmed_button_afficher_excursion_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	/*GtkWidget *old;
	GtkWidget *new;
	GtkWidget *treeview;

	old=lookup_widget(objet,"ahmed_treeviewmenuexcursion");
	new=create_ahmed_windowmenuexcursionprestation();

	gtk_widget_show(new);
	treeview=lookup_widget(new,"ahmed_treeviewmenuexcursion");
	ahmed_afficher_voiture(treeview);
	gtk_widget_destroy(old);
*/
}


void
on_ahmed_button_valider_excursion_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_ahmed_button_retour_ajouter_excursion_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_ahmed_button_modifier_main_voiture_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{

	/*GtkWidget *old;
	GtkWidget *new;
	GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
	GtkWidget *ahmed_treeview_main_voiture;
	GtkWidget *ahmed_windowmenuvoitureprestation;
        gchar *id;

        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
	{
		gtk_tree_model_get (model,&iter,0,&id,-1);*/



	/*voiture v;	
	GtkWidget *old;
	GtkWidget *new;	
	GtkWidget *Ahmed_modifierentryid;	
	GtkWidget *comboboxentrymodifiermarque_voiture;
	GtkWidget *comboboxentrymodifiermodele_voiture;
	GtkWidget *comboboxentrymodifiercarrosserie_voiture;
	GtkWidget *comboboxentrymodifieretat_voiture;
	GtkWidget *Ahmed_modifierentryprix;
	GtkWidget *ahmed_entrymodifierreductionvoiture;
	

	
	GtkWidget *ahmed_windowmodifiervoitureprestation;	
	ahmed_windowmodifiervoitureprestation=lookup_widget(objet,"ahmed_windowmodifiervoitureprestation");
	
	old=lookup_widget(objet,"ahmed_windowmenuvoitureprestation");
        new=create_ahmed_windowmodifiervoitureprestation();
	
	
	gtk_widget_show(new);
	gtk_widget_destroy(old);


	Ahmed_modifierentryid=lookup_widget(objet,Ahmed_modifierentryid);	
	comboboxentrymodifiermarque_voiture=lookup_widget(objet,comboboxentrymodifiermarque_voiture);
	comboboxentrymodifiermodele_voiture=lookup_widget(objet,comboboxentrymodifiermodele_voiture);
	comboboxentrymodifiercarrosserie_voiture=lookup_widget(objet,comboboxentrymodifiercarrosserie_voiture);
	comboboxentrymodifieretat_voiture=lookup_widget(objet,comboboxentrymodifieretat_voiture);
	Ahmed_modifierentryprix=lookup_widget(objet,Ahmed_modifierentryprix);  
			//strcpy(comboboxentrymodifieretat_voiture,v.etat);
	ahmed_entrymodifierreductionvoiture=lookup_widget(objet,ahmed_entrymodifierreductionvoiture);

	
	v=ahmed_modifier_voiture_menu(v);
		{
			strcpy(gtk_entry_get_text(GTK_ENTRY(Ahmed_modifierentryid)),v.id);
			strcpy(gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentrymodifiermarque_voiture)),v.marque);
			strcpy(gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentrymodifiermodele_voiture)),v.modele);
			strcpy(gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentrymodifiercarrosserie_voiture)),v.carrosserie);
			strcpy(gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentrymodifieretat_voiture)),v.etat);
			strcpy(gtk_entry_get_text(GTK_ENTRY(Ahmed_modifierentryprix)),v.prix);
			strcpy(gtk_entry_get_text(GTK_ENTRY(ahmed_entrymodifierreductionvoiture)),v.reduction);
		}*/
        

	GtkWidget *old;
	GtkWidget *new;

	old=lookup_widget(objet,"ahmed_windowmenuvoitureprestation");
        new=create_ahmed_IDmodifiervoiture();
	
	
	gtk_widget_show(new);
	gtk_widget_destroy(old);

	

}


void
on_ahmed_button_supprimer_main_voiture_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget *ahmed_treeview_main_voiture;
	GtkWidget *ahmed_windowmenuvoitureprestation;
        gchar* id;

	ahmed_windowmenuvoitureprestation=lookup_widget(objet,"ahmed_windowmenuvoitureprestation");	
	ahmed_treeview_main_voiture=lookup_widget(ahmed_windowmenuvoitureprestation,"ahmed_treeview_main_voiture");
	selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(ahmed_treeview_main_voiture));

	if (gtk_tree_selection_get_selected(selection, &model, &iter))
	{
		 gtk_tree_model_get (model,&iter,0,&id,-1);
           	 gtk_list_store_remove(GTK_LIST_STORE(model),&iter);
		 ahmed_supprimer_voiture_menu(id);
	}
}


void
on_ahmed_button_retour_main_voiture_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)

{
	GtkWidget *old;
	GtkWidget *new;

	old=lookup_widget(objet,"ahmed_windowmenuvoitureprestation");
	new=create_ahmed_windowcataloguevoiture();

	gtk_widget_show(new);
	gtk_widget_destroy(old);
}


void
on_ahmed_ajouter_main_voiture_clicked  (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *old;
	GtkWidget *new;

	old=lookup_widget(objet,"ahmed_windowmenuvoitureprestation");
	new=create_ahmed_windowajoutervoitureprestation();

	gtk_widget_show(new);
	gtk_widget_destroy(old);

	
}


void
on_ahmed_button_modifier_main_excursion_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_ahmed_button_supprimer_excursion_clicked
                                         (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_ahmed_button_ajouter_main_excursion_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	/*GtkWidget *old;
	GtkWidget *new;

	old=lookup_widget(objet,"ahmed_treeviewmenuexcursion");
	new=create_ahmed_ahmed_windowajoutexcursionprestation();

	gtk_widget_show(new);
	gtk_widget_destroy(old);*/


}


void
on_ahmed_button_retour_main_excursion_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{

}



void
on_ahmed_button_retour_catalogue_voiture_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_ahmed_button_modifier_catalogue_voiture_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_ahmed_button_supprimer_voiture_catalogue_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{


}


void
on_ahmed_button_retour_modifier_voiture_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *old;
	GtkWidget *new;
	


	old=lookup_widget(objet,"ahmed_windowmodifiervoitureprestation");
	new=create_ahmed_IDmodifiervoiture();

	gtk_widget_show(new);
	gtk_widget_destroy(old);

	


}




void
on_ahmed_button_chercher_voiture_prestation_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *ahmed_windowmenuvoitureprestation;
	GtkWidget *entry;
	//GtkWidget *;
	char id[15];

}


void
on_ahmed_button_chercher_voiture_catalogue_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_ahmed_button_continuer_modifier_voiture_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{


	GtkWidget *ahmed_IDmodifiervoiture;
	GtkWidget *ahmed_windowmodifiervoitureprestation;
	GtkWidget *Ahmed_modifierentryid ;
	GtkWidget *ahmed_entryidmodifiervoiture, *Ahmed_entrymodifierprix , *ahmed_entrymodifierreductionvoiture,*comboboxentrymarque_voiture;;
	voiture v;
	char idd[15];
	FILE *f;

	ahmed_entryidmodifiervoiture=lookup_widget(objet,"ahmed_entryidmodifiervoiture");

	strcpy (idd,gtk_entry_get_text(GTK_ENTRY(ahmed_entryidmodifiervoiture)));
	f=fopen("/home/ahmed/Projects/Ahmed_final2/src/ahmed_voiture.txt","r");
        if (f!=NULL)
	   {
	    while (fscanf(f,"%s %s %s %s %s %s %s\n ",v.id,v.marque,v.modele,v.carrosserie,v.etat,v.prix,v.reduction)!=EOF)
		{
			if (strcmp(v.id,idd)==0)
			   {
				ahmed_IDmodifiervoiture=lookup_widget(objet,"ahmed_IDmodifiervoiture");
				ahmed_windowmodifiervoitureprestation=create_ahmed_windowmodifiervoitureprestation();
				gtk_widget_show(ahmed_windowmodifiervoitureprestation);
				gtk_widget_destroy(ahmed_IDmodifiervoiture);
				ahmed_entryidmodifiervoiture=lookup_widget(ahmed_windowmodifiervoitureprestation,"ahmed_entryidmodifiervoiture");
				Ahmed_entrymodifierprix=lookup_widget(ahmed_windowmodifiervoitureprestation,"Ahmed_entrymodifierprix");
				ahmed_entrymodifierreductionvoiture=lookup_widget(ahmed_windowmodifiervoitureprestation,"ahmed_entrymodifierreductionvoiture");
				gtk_entry_set_text(GTK_ENTRY(ahmed_entryidmodifiervoiture),v.id);
				gtk_entry_set_text(GTK_ENTRY(Ahmed_entrymodifierprix),v.prix);
				gtk_entry_set_text(GTK_ENTRY(ahmed_entrymodifierreductionvoiture),v.reduction);				
			   }
		}
          }
	fclose(f);
}


void
on_ahmed_button_retour_modifier_ID_voiture_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *old;
	GtkWidget *new;
	GtkWidget *treeview;


	old=lookup_widget(objet,"ahmed_IDmodifiervoiture");
	new=create_ahmed_windowmenuvoitureprestation();

	gtk_widget_show(new);
	treeview=lookup_widget(new,"ahmed_treeview_main_voiture");
	ahmed_afficher_voiture(treeview);
	gtk_widget_destroy(old);

}


void
on_ahmed_button_valider_modifier_voiture_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	voiture v;		
	GtkWidget *Ahmed_entryid;	
	GtkWidget *comboboxentrymarque_voiture;
	GtkWidget *comboboxentrymodele_voiture;
	GtkWidget *comboboxentrycarrosserie_voiture;
	GtkWidget *comboboxentryetat_voiture;
	GtkWidget *Ahmed_entryprix;
	GtkWidget *ahmed_entryreductionvoiture;

	

	GtkWidget *ahmed_windowmodifiervoitureprestation;	
	ahmed_windowmodifiervoitureprestation=lookup_widget(objet,"ahmed_windowmodifiervoitureprestation");

	Ahmed_entryid=lookup_widget(objet,"Ahmed_entryid");	
	comboboxentrymarque_voiture=lookup_widget(objet,"comboboxentrymarque_voiture");
	comboboxentrymodele_voiture=lookup_widget(objet,"comboboxentrymodele_voiture");
	comboboxentrycarrosserie_voiture=lookup_widget(objet,"comboboxentrycarrosserie_voiture");
	comboboxentryetat_voiture=lookup_widget(objet,"comboboxentryetat_voiture");
	Ahmed_entryprix=lookup_widget(objet,"Ahmed_entryprix");
	ahmed_entryreductionvoiture=lookup_widget(objet,"ahmed_entryreductionvoiture");

	strcpy(v.id,gtk_entry_get_text(GTK_ENTRY(Ahmed_entryid)));	
	strcpy(v.marque,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentrymarque_voiture)));
	strcpy(v.modele,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentrymodele_voiture)));
	strcpy(v.carrosserie,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentrycarrosserie_voiture)));
	strcpy(v.etat,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentryetat_voiture)));
	strcpy(v.prix,gtk_entry_get_text(GTK_ENTRY(Ahmed_entryprix)));
	strcpy(v.reduction,gtk_entry_get_text(GTK_ENTRY(ahmed_entryreductionvoiture)));

	ahmed_modifier_voiture_menu(v);

	GtkWidget *old;
	GtkWidget *new;
	GtkWidget *treeview;

	old=lookup_widget(objet,ahmed_windowmodifiervoitureprestation);
	new=create_ahmed_windowmenuvoitureprestation();
	
}


void
on_ahmed_button_afficher_modification_voiture_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *old;
	GtkWidget *new;
	GtkWidget *treeview;

	old=lookup_widget(objet,"ahmed_windowmodifiervoitureprestation");
	new=create_ahmed_windowmenuvoitureprestation();

	gtk_widget_show(new);
	treeview=lookup_widget(new,"ahmed_treeview_main_voiture");
	ahmed_afficher_voiture(treeview);
	gtk_widget_destroy(old);

}








void
on_ahmed_button_plus_de_voiture_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{

	GtkWidget *old;
	GtkWidget *new;
	GtkWidget *treeview;

	old=lookup_widget(objet,"ahmed_windowcataloguevoiture");
	new=create_ahmed_windowmenuvoitureprestation();

	gtk_widget_show(new);
	treeview=lookup_widget(new,"ahmed_treeview_main_voiture");
	ahmed_afficher_voiture(treeview);
	gtk_widget_destroy(old);

}

