#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include "ahmed_voiture.h"

enum
{
	Identifiant,
	Marque,
	Modele,
	Carrosserie,
	Etat,
	Prix,
	Reduction,
	
	COLUMNS
};




void ahmed_ajouter_voiture(voiture v)
{
	FILE *f;
	f=fopen("ahmed_voiture.txt","a+");
	if(f!=NULL)
	{
		fprintf(f,"%s %s %s %s %s %s %s\n ",v.id,v.marque,v.modele,v.carrosserie,v.etat,v.prix,v.reduction);
		fclose(f);
	}
}





void ahmed_afficher_voiture(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	char id[15];
	char marque[15];
	char modele[15];
	char carrosserie[15];
	char etat[15];
	char prix[15];
	char reduction[15];
	 

	store=NULL;

	FILE *f;

	store=gtk_tree_view_get_model(liste);

	if(store==NULL)
	{
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" id", renderer,"text",Identifiant,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" marque", renderer, "text",Marque,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer=gtk_cell_renderer_text_new ();
		column=gtk_tree_view_column_new_with_attributes(" modele", renderer,"text",Modele,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer=gtk_cell_renderer_text_new ();
		column=gtk_tree_view_column_new_with_attributes(" carrosserie", renderer,"text",Carrosserie,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer=gtk_cell_renderer_text_new ();
		column=gtk_tree_view_column_new_with_attributes(" etat", renderer,"text",Etat,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer=gtk_cell_renderer_text_new ();
		column=gtk_tree_view_column_new_with_attributes(" Prix", renderer,"text",Prix,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer=gtk_cell_renderer_text_new ();
		column=gtk_tree_view_column_new_with_attributes(" reduction", renderer,"text",Reduction,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
		
		store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
		f=fopen("ahmed_voiture.txt","r");

		if(f==NULL)
		{
			return;
		}
		else
		{
			f=fopen("/home/ahmed/Projects/Ahmed_final2/src/ahmed_voiture.txt","a+");
			while(fscanf(f,"%s %s %s %s %s %s %s \n",id,marque,modele,carrosserie,etat,prix,reduction)!=EOF)
				{
					gtk_list_store_append(store,&iter);
					gtk_list_store_set(store,&iter,Identifiant,id,Marque,marque,Modele,modele,Carrosserie,carrosserie,Etat,etat,Prix,prix,Reduction,reduction,-1);
				}
			fclose(f);
			gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
			g_object_unref(store);
		}

		
	}
}

void ahmed_supprimer_voiture_menu(char id1[15])
{
	voiture v;	
	FILE *f;
	FILE *f1;
	f=fopen("/home/ahmed/Projects/Ahmed_final2/src/ahmed_voiture.txt","r");
	f1=fopen("/home/ahmed/Projects/Ahmed_final2/src/tempo.txt","a+");
	while(fscanf(f,"%s %s %s %s %s %s %s",v.id,v.marque,v.modele,v.carrosserie,v.etat,v.prix,v.reduction)!=EOF)
		{
			if(strcmp(id1,v.id)!=0)
				{
					fprintf(f1,"%s %s %s %s %s %s %s",v.id,v.marque,v.modele,v.carrosserie,v.etat,v.prix,v.reduction);
				}
		}
	fclose(f);
	fclose(f1);
	remove("/home/ahmed/Projects/Ahmed_final2/src/ahmed_voiture.txt");
	rename("/home/ahmed/Projects/Ahmed_final2/src/tempo.txt","/home/ahmed/Projects/Ahmed_final2/src/ahmed_voiture.txt");
}

voiture ahmed_modifier_voiture_menu(voiture v)
{
	voiture v1;
	FILE *f;
	FILE *f1;

	f=fopen("/home/ahmed/Projects/Ahmed_final2/src/ahmed_voiture.txt","r");
	f1=fopen("/home/ahmed/Projects/Ahmed_final2/src/ahmed_tmp.txt","a+");
	while(fscanf(f,"%s %s %s %s %s %s %s\n",v1.id,v1.marque,v1.modele,v1.carrosserie,v1.etat,v1.prix,v1.reduction)!=EOF)
		{
			if(strcmp(v.id,v1.id)!=0)
				{
				     fprintf(f1,"%s %s %s %s %s %s %s\n",v1.id,v1.marque,v1.modele,v1.carrosserie,v1.etat,v1.prix,v1.reduction);
					
				}
		}
	fclose(f);
	fclose(f1);
	remove("/home/ahmed/Projects/Ahmed_final2/src/ahmed_voiture.txt");
	rename("/home/ahmed/Projects/Ahmed_final2/src/ahmed_tmp.txt","/home/ahmed/Projects/Ahmed_final2/src/ahmed_voiture.txt");

	f=fopen("/home/ahmed/Projects/Ahmed_final2/src/ahmed_voiture.txt","r");
	while(fscanf("%s %s %s %s %s %s %s\n",v1.id,v1.marque,v1.modele,v1.carrosserie,v1.etat,v1.prix,v1.reduction)!=EOF)
		{
			if(strcmp(v.id,v1.id)==0)
				{
					return v;	
				}
		}
	fclose(f);

}

void ahmed_ajouter_voiture_catalogue()
{
	voiture v1;
	FILE *f;
	FILE *f1;

	f=fopen("/home/ahmed/Projects/Ahmed_final2/src/ahmed_voiture.txt","r");
	f1=fopen("/home/ahmed/Projects/Ahmed_final2/src/ahmed_catalogue_voiture.txt","a+");
	if(f!=NULL)
	{
		if(f1!=NULL)
		{
			while(fscanf(f,"%s %s %s %s %s %s %s\n",v1.id,v1.marque,v1.modele,v1.carrosserie,v1.etat,v1.prix,v1.reduction)!=EOF)
			{
				if(v1.reduction!="0")
			 	 {
					fprintf(f1,"%s %s %s %s %s %s %s\n",v1.id,v1.marque,v1.modele,v1.carrosserie,v1.etat,v1.prix,v1.reduction);
				 }
			}
		}
	}
	
}



