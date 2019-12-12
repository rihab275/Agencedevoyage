#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <gtk/gtk.h>

#include "reclamationclient.h"

/*
enum
{
	ID,
	SERVICE,	
	TYPE,
	DESCRIPTION,
	DATEFINSERVICE,
	ETAT,
	REPONSE,
	DATEREP,
	DATEREC,
	COLUMNS
};*/






enum
{
	ID,
	SERVICE,	
	TYPE,
	DESCRIPTION,
	DATEFINSERVICE,
	DATEREC,
	ETAT,
	REPONSE,
	DATEREP,
	COLUMNS
};






/*------------------------ajouter_reclamations----------------------*/

void ajouter_Reclamation(Reclamation rec)
{

  FILE *f;
  f=fopen("/home/yass/Projects/YassinePC/db/Liste_reclamation_client.txt","a+");
  if(f!=NULL) 
  {
  /*fprintf(f,"%s %s %s %s %02s/%02s/%04s \n",rec.id,rec.service,rec.type,rec.description , rec.fs_jour, rec.fs_mois, rec.fs_an, rec.etat, rec.reponse, rec.date_rec);
  fclose(f);*/

  fprintf(f,"%d %s %s %s %02d/%02d/%d %s %s %s %s\n",rec.id,rec.service,rec.type,rec.description , rec.date_service.jour,rec.date_service.mois,rec.date_service.annee,rec.date_rec,rec.etat,rec.reponse,rec.date_rep);
  fclose(f);

  }

}

 /*,rec.etat,rec.reponse,rec.date_rec*/

/*---------------------afficher_Vos_reclamation-----------------------*/



void afficher_Reclamation(GtkWidget *liste)
{
        GtkCellRenderer *renderer; //afficheur de cellule (cellule contient un text, image, case à cocher; dans notre expl on adu text
	
        GtkTreeViewColumn *column; //visualisation des colonnes
	
	GtkTreeIter    iter; /*la premiere etape de l'insertion consiste a creer une nouvelle entrée (ligne)  à la liste . Pour cela, nous 					allons utiliser l'objet GtkTreeIter. Cet objet permet de savoir à quel endroit nous nous positionnons dans la 					liste. La création d'une nouvelle ligne va donner une nouvelle position dont nous avons besoin pour entrer les 					données. */
	
	GtkListStore *store; //creation du modele de type liste


	char id[20];
	char service[20];
	char type[20];
	char description[200];
	char date_service[20];
	char etat[20];
	char reponse[200];
	char date_rec[100] ;
	char date_rep[100] ;
	
        store=NULL;

        FILE *f;
	
	store=gtk_tree_view_get_model(liste);	//warning not detected
	if (store==NULL)
	{

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" id", renderer, "text",ID, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" service", renderer, "text",SERVICE, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

                renderer = gtk_cell_renderer_text_new ();// cellule contenant du texte 
		column = gtk_tree_view_column_new_with_attributes(" type", renderer, "text",TYPE, NULL); //création d'une colonne avec de texte
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column); //associer la colonne à l'afficheur (GtkTreeView)

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" description", renderer, "text",DESCRIPTION, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	
	

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" date_service", renderer, "text",DATEFINSERVICE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" date_rec", renderer, "text",DATEREC, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" etat", renderer, "text",ETAT, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" reponse", renderer, "text",REPONSE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

       
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" date_rep", renderer, "text",DATEREP, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	}	
         

//~~~~~~~~~~~La liste Contient 9 colonnes de type char		
         	
	
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING);

	f = fopen("/home/yass/Projects/YassinePC/db/Liste_reclamation_client.txt", "r");
	
	if(f==NULL)
	{

		return;
	}		
	else 

	{ f = fopen("/home/yass/Projects/YassinePC/db/Liste_reclamation_client.txt", "a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s\n",id,service,type,description ,date_service,date_rec,etat,reponse,date_rep )!=EOF)

								
		
		{
	gtk_list_store_append (store, &iter); //est l'itérateur parent. Il est utilisé pour ajouter une ligne enfant à une ligne d'un GtkTreeStore 
	
	
	gtk_list_store_set (store, &iter, ID, id, SERVICE, service, TYPE, type, DESCRIPTION, description , DATEFINSERVICE ,date_service, DATEREC, date_rec, ETAT, etat, REPONSE, reponse, DATEREP, date_rep, -1);

		/*, DATEREP, date_rep, DATEREC, date_rec*/
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}



/* ------supprimer_reclamation------juste au niveau de fichier ------ */

void supprimer_Reclamation(char cinn[20])
{
	char id[20];
	char service[20];
	char type[20];
	char description[200];
	char date_service[20];
	char date_rec[100];
	char etat[20];
	char reponse[200];
	char date_rep[100];
/*rec.date_service.jour,rec.date_service.mois,rec.date_service.annee 
rec.id ,rec.service,rec.type,rec.description,rec.date_service,rec.date_rec,rec.etat,rec.reponse,rec.date_rep  */
	
	//Reclamation(rec);

	FILE *l;
	FILE *t;
	l=fopen("/home/yass/Projects/YassinePC/db/Liste_reclamation_client.txt","r");
	t=fopen("/home/yass/Projects/YassinePC/db/Liste_reclamation_client.tmp","a+");
	while (fscanf(l,"%s %s %s %s %s %s %s %s %s\n",id ,service,type,description,date_service,date_rec,etat,reponse,date_rep )!=EOF) //lecture a partir du fichier temporaire
	{
		if (strcmp(cinn,id)!=0)
		{
			fprintf(t,"%s %s %s %s %s %s %s %s %s \n ",id, service,type,description,date_service,date_rec, etat,reponse,date_rep );
		}
	}
	fclose(l);
	fclose(t);
	remove("/home/yass/Projects/YassinePC/db/Liste_reclamation_client.txt");
	rename("/home/yass/Projects/YassinePC/db/Liste_reclamation_client.tmp","/home/yass/Projects/YassinePC/db/Liste_reclamation_client.txt");

}

/*--------------MOdifier Reclamation --------------------------*/
void modifier_Reclamation(Reclamation rc)
{
	Reclamation recm;
	FILE *f;
	FILE *f1;


	f=fopen("/home/yass/Projects/YassinePC/db/Liste_reclamation_client.txt","r");
	f1=fopen("/home/yass/Projects/YassinePC/db/Liste_reclamation_client.tmp","a+");
	while (fscanf(f,"%s %s %s %s %s %s %s %s %s\n",recm.id,recm.service,recm.type,recm.description,recm.date_service, recm.date_rec,recm.etat,recm.reponse,recm.date_rep )!=EOF)
	{
		if (strcmp(rc.id,recm.id)!=0)
		{
			fprintf(f1,"%d %s %s %s %s %s %s %s %s\n",recm.id ,recm.service,recm. type, recm.description,recm.date_service, recm.date_rec, recm.etat,recm.reponse,recm.date_rep);
		}
		else 
		{
			fprintf(f1,"%d %s %s %s %s %s %s %s %s\n",rc.id,rc.service,rc.type, rc.description, rc.date_service, rc.date_rec,rc.etat,rc.reponse,rc.date_rep);
		} 
	}
fclose(f);
fclose(f1);

remove("/home/yass/Projects/YassinePC/db/Liste_reclamation_client.txt") ;
rename("/home/yass/Projects/YassinePC/db/Liste_reclamation_client.tmp" , "/home/yass/Projects/YassinePC/db/Liste_reclamation_client.txt");
}






/*
int if_exist_reclamation(char*idrec){

FILE*f=NULL;
 Reclamation1 rec;
f = fopen("/home/yass/Projects/YassinePC/db/Liste_reclamation_client.txt", "r");

while(fscanf(f,"%s %s %s %s %s %s %s %s %s\n",rec.id,rec.service,rec.type,rec.description ,rec.date_service,rec.date_rec,rec.etat,rec.reponse,rec.date_rep )!=EOF)
{
if(strcmp(idrec,rec.id)==0)return 1;
}
fclose(f);
return 0;
}

*/
