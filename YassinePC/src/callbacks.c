#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"

#include "ylogin.h"
#include "reclamationclient.h"
#include "resvoiture.h"

void
on_YasstreeviewRec_columns_changed     (GtkTreeView     *treeview,
                                        gpointer         user_data)
{


	/*gchar *id;
	gchar service;
	gchar type;
	gchar description;
	gchar date_service;
	gchar date_rec;
	gchar etat;
	gchar reponse;
	gchar date_rep;

        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* YassRecEspaceAAWind;
	GtkWidget *p=lookup_widget(YassRecEspaceAAWind,"YasstreeviewRec");
        GtkTreeSelection *selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {
                gtk_tree_model_get (model,&iter,0,&id,1,service,2,type,3, description,4,date_service,5,date_rec,6,etat,7,reponse,8, date_rep,-1);//recuperer les information de la ligne selectionneé


                gtk_widget_show(lookup_widget(YassRecEspaceAAWind,"YassbuttonRepondreRec"));//afficher le bouton modifier
        GtkWidget* msg1=lookup_widget(YassRecEspaceAAWind,"yasslabel_repondre"); 
        gtk_widget_hide(msg1);//cacher "cacher reponse envoyé"


}*/
}



void
on_Yasstreeview_VosRec_columns_changed   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{


 	gchar *id;
	gchar *service;
	gchar *type;
	gchar *description ;
	gchar *date_service;

        int x1=0,x2=0;
	GtkWidget* YassentryClientAjoutRec;
	GtkWidget* YassRecEspaceCWind;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget *p=lookup_widget(create_YassAfficherVosRecWind(),"Yasstreeview_VosRec");
        GtkTreeSelection *selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {
		
                gtk_tree_model_get (model,&iter,0,id,1,service,2,type,3,description ,4,date_service,-1);//recuperer les information de la ligne selectionneé

		//YassentryClientAjoutRec=create_YassentryClientAjoutRec();
		
                if(strcmp(service,"Hotels")==0)	x1=0;		
                if(strcmp(service,"Vols")==0) x1=1;                
                if(strcmp(service,"Voitures")==0)  x1=2 ;     
                if(strcmp(service,"Excursions")==0)  x1=3 ;            

                if(strcmp(type,"Services")==0) x2=0;                 
                if(strcmp(type,"Prix")==0)     x2=1;                
                if(strcmp(type,"Confort")==0)  x2=2; 
                if(strcmp(type,"Retard")==0)   x2=3; 
                if(strcmp(type,"autres")==0)   x2=4; 

		gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(YassRecEspaceCWind,"Y_combobox_ServiceReclamee")),x1);
		gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(YassRecEspaceCWind,"Y_combobox_type_rec")),x2);



                gtk_entry_set_text(GTK_ENTRY(lookup_widget(YassRecEspaceCWind,"YassentryClientAjoutRec")),description);
                
		GtkWidget* msg=lookup_widget(YassRecEspaceCWind,"Y_label_selectionner_modifier");
                gtk_widget_hide(msg);
		


                gtk_widget_show(lookup_widget(create_YassAfficherVosRecWind(),"Yassbutton_Modif_VosRec"));//afficher le bouton modifier
        GtkWidget* msg1=lookup_widget(create_YassAfficherVosRecWind(),"Y_label_selectionner_modifier");
        gtk_widget_hide(msg1);

}


}



void
on_buttonAjouter_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonClientEnvoyerRec_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonAjoutResVoit_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_YassbuttonLogin_clicked             (GtkWidget       *objet_graphic,
                                        gpointer         user_data)
{
        GtkWidget *YassSkytravelMainWind;
	

	GtkWidget *YasswindowGestion;//wind espace client

  	GtkWidget *YassEspaceAdminWind ;//wind espace admin 
	GtkWidget *YassEspaceAgentWind ;//wind espace agent
	
	GtkWidget *YassentryLogin      ;//input de login
	GtkWidget *YassentryMdp        ;//input de passwd
	

	GtkWidget *Yass_label_main_page_error;	//output msg error


	char login[20];
 	char password[20];
 	char erreur1[50];
 	char erreur2[50];
 	int s;
	strcpy(erreur1,"vous n'avez aucun espace !!! ");
	strcpy(erreur2,"erreur d'authentification" );
	

	YassentryLogin=lookup_widget(objet_graphic,"YassentryLogin");
	YassentryMdp=lookup_widget(objet_graphic,"YassentryMdp");
	

	strcpy(login,gtk_entry_get_text(GTK_ENTRY(YassentryLogin)));
	strcpy(password,gtk_entry_get_text(GTK_ENTRY(YassentryMdp)));
        
	//output
	Yass_label_main_page_error=lookup_widget(objet_graphic,"Yass_label_main_page_error");	
	

	s=verifier(login,password);
	if (s==-1)
		gtk_label_set_text(GTK_LABEL(Yass_label_main_page_error),erreur1);
	else
	  {switch (s)
		{case 1 : {
			YassSkytravelMainWind = lookup_widget(objet_graphic,"YassSkytravelMainWind");
		   	gtk_widget_hide(YassSkytravelMainWind);
		   	YassEspaceAdminWind=create_YassEspaceAdminWind();
		   	gtk_widget_show (YassEspaceAdminWind);
		  	}break;
		 case 2 : {
			YassSkytravelMainWind = lookup_widget(objet_graphic,"YassSkytravelMainWind");
		   	gtk_widget_hide(YassSkytravelMainWind);
		   	YassEspaceAgentWind =create_YassEspaceAgentWind();
		   	gtk_widget_show (YassEspaceAgentWind);
		   	break;
		  	}
		 case 3 : {
			YassSkytravelMainWind = lookup_widget(objet_graphic,"YassSkytravelMainWind");
		   	gtk_widget_hide(YassSkytravelMainWind);
		   	YasswindowGestion = create_YasswindowGestion ();
			gtk_widget_show (YasswindowGestion);
			break;
		  	}

		default :gtk_label_set_text(GTK_LABEL(Yass_label_main_page_error),erreur2);
		}  
	}	

	

}


void
on_buttonCancelY_clicked               (GtkWidget       *objet_graphic,
                                        gpointer         user_data)
{

}


void
on_YassbuttonInscri_clicked            (GtkWidget       *objet_graphic,
                                        gpointer         user_data)
{
  

	GtkWidget *YassSkytravelMainWind;
	GtkWidget *YassInscriWind;
  

	YassInscriWind = create_YassInscriWind ();
	gtk_widget_show (YassInscriWind);
  
	YassSkytravelMainWind = lookup_widget(objet_graphic,"YassSkytravelMainWind");
	gtk_widget_destroy (YassSkytravelMainWind);





}


void on_YassbuttonCatNA_clicked(GtkWidget *objet_graphic, gpointer user_data)
{

GtkWidget *YassSkytravelMainWind;
GtkWidget *YassCatWind;
  

YassCatWind = create_YassCatWind ();
gtk_widget_show (YassCatWind);
  
YassSkytravelMainWind = lookup_widget(objet_graphic,"YassSkytravelMainWind");
gtk_widget_destroy (YassSkytravelMainWind);


}


void
on_YasstreeviewCatHtl_columns_changed  (GtkTreeView     *treeview,
                                        gpointer         user_data)
{

}


void
on_YasstreeviewCatVols_columns_changed (GtkTreeView     *treeview,
                                        gpointer         user_data)
{

}


void
on_YasstreeviewCatVoit_columns_changed (GtkTreeView     *treeview,
                                        gpointer         user_data)
{

}


void
on_YasstreeviewCatEx_columns_changed   (GtkTreeView     *treeview,
                                        gpointer         user_data)
{

}


void
on_Y_button_inscription_V_clicked      (GtkWidget       *objet_graphic,
                                        gpointer         user_data)
{

	GtkWidget *YassSkytravelMainWind;
	GtkWidget *YassInscriWind;
  

	YassInscriWind =lookup_widget(objet_graphic,"YassInscriWind"); 
	gtk_widget_destroy (YassInscriWind);
  
	YassSkytravelMainWind = create_YassSkytravelMainWind ();
	gtk_widget_show (YassSkytravelMainWind);

}



void on_YassbuttonRepondreRec_clicked(GtkWidget  *objet_graphic,
			              gpointer    user_data)
{      
        GtkWidget *YassRecEspaceAAWind;
	GtkWidget *YassRepondreRecWind;
  	

	YassRepondreRecWind = create_YassRepondreRecWind ();
	gtk_widget_show (YassRepondreRecWind);
  
	YassRecEspaceAAWind =lookup_widget(objet_graphic,"YassRecEspaceAAWind");
	gtk_widget_destroy (YassRecEspaceAAWind);
	
}


void
on_YassbuttonRepRecAA_clicked          (GtkWidget       *objet_graphic,
                                        gpointer         user_data)
{
        GtkWidget *YassRecEspaceAAWind;
	GtkWidget *YassRepondreRecWind;
  	

	YassRecEspaceAAWind = create_YassRecEspaceAAWind ();
	gtk_widget_show (YassRecEspaceAAWind);
  
	YassRepondreRecWind =lookup_widget(objet_graphic,"YassRepondreRecWind");
	gtk_widget_destroy (YassRepondreRecWind);
	
}


void
on_Y_button_quit_fromCRrec_clicked     (GtkWidget       *objet_graphic,
                                        gpointer         user_data)
{
        GtkWidget *YassRecEspaceCWind;
        GtkWidget *YassSkytravelMainWind;
  	

	YassSkytravelMainWind = create_YassSkytravelMainWind ();
	gtk_widget_show (YassSkytravelMainWind);
  
	YassRecEspaceCWind =lookup_widget(objet_graphic,"YassRecEspaceCWind");
	gtk_widget_destroy (YassRecEspaceCWind);

}

///////////000000000000000000
void
on_Y_button_retour_from_CRec_clicked   (GtkWidget       *objet_graphic,
                                        gpointer         user_data)
{
        GtkWidget *YassRecEspaceCWind;
        GtkWidget *YasswindowGestion;
  	

	YasswindowGestion = create_YasswindowGestion ();
	gtk_widget_show (YasswindowGestion);
  
	YassRecEspaceCWind =lookup_widget(objet_graphic,"YassRecEspaceCWind");
	gtk_widget_destroy (YassRecEspaceCWind);
}


void
on_Y_buttonRetour_fromRepRec_clicked   (GtkWidget       *objet_graphic,
                                        gpointer         user_data)
{       GtkWidget *YassRecEspaceAAWind;
	GtkWidget *YassRepondreRecWind;
  	

	YassRecEspaceAAWind = create_YassRecEspaceAAWind ();
	gtk_widget_show (YassRecEspaceAAWind);
  
	YassRepondreRecWind =lookup_widget(objet_graphic,"YassRepondreRecWind");
	gtk_widget_destroy (YassRepondreRecWind);

}


void
on_Yass_buttonQuit_fromMainW_clicked   (GtkWidget       *objet_graphic,
                                        gpointer         user_data)
{

GtkWidget *YassSkytravelMainWind;
YassSkytravelMainWind = lookup_widget(objet_graphic,"YassSkytravelMainWind");


gtk_widget_destroy(YassSkytravelMainWind);

}


void
on_y_button_backtoMainWind_clicked     (GtkWidget       *objet_graphic,
                                        gpointer         user_data)
{


GtkWidget *YassSkytravelMainWind;
GtkWidget *YasswindowGestion;
  	

	YassSkytravelMainWind = create_YassSkytravelMainWind ();
	gtk_widget_show (YassSkytravelMainWind);
  
	YasswindowGestion =lookup_widget(objet_graphic,"YasswindowGestion");
	gtk_widget_destroy (YasswindowGestion);
	
}


void
on_YassbuttonAvezVousRec_clicked       (GtkWidget       *objet_graphic,
                                        gpointer         user_data)
{
GtkWidget *YassRecEspaceCWind;
GtkWidget *YasswindowGestion;
  	

	YassRecEspaceCWind = create_YassRecEspaceCWind ();
	gtk_widget_show (YassRecEspaceCWind);
  
	YasswindowGestion =lookup_widget(objet_graphic,"YasswindowGestion");
	gtk_widget_destroy (YasswindowGestion);
	

}








/*************************************************************/
void
on_YassbuttonClientEnvoyerRec_clicked  (GtkWidget       *objet_graphic,
                                        gpointer         user_data)
{
Reclamation rec; //ad

rec.id=rand();
char str[30];
/*
sprintf(str, "%d", i);
if(if_exist_reclamation(str)==1) {

             printf("hecccfhd");

}*/


GtkWidget *Y_combobox_ServiceReclamee; // combobox de service a reclamer 
GtkWidget *Y_combobox_type_rec ; //combobox type reclamation

							//date de fin de service forme jj mm aaaa
GtkWidget *Yassspinbutton_date_fin_service_jour;
GtkWidget *Yassspinbutton_date_fin_service_mois;
GtkWidget *Yassspinbutton_date_fin_service_annee;


GtkWidget *YassentryClientAjoutRec;// input descriptif reclamation 


GtkWidget *Yass_label_outputAjouterRec; //output if error controle de saisie      


Y_combobox_ServiceReclamee=lookup_widget(objet_graphic,"Y_combobox_ServiceReclamee");
Y_combobox_type_rec=lookup_widget(objet_graphic,"Y_combobox_type_rec");

YassentryClientAjoutRec=lookup_widget(objet_graphic,"YassentryClientAjoutRec");
Yass_label_outputAjouterRec=lookup_widget(objet_graphic,"Yass_label_outputAjouterRec");

strcpy(rec.service, gtk_combo_box_get_active_text(GTK_COMBO_BOX(Y_combobox_ServiceReclamee)));
strcpy(rec.type, gtk_combo_box_get_active_text(GTK_COMBO_BOX(Y_combobox_type_rec)));

strcpy(rec.description,gtk_entry_get_text(GTK_ENTRY(YassentryClientAjoutRec)));

											//lookup spinbutton
Yassspinbutton_date_fin_service_jour=lookup_widget(objet_graphic,"Yassspinbutton_date_fin_service_jour");
Yassspinbutton_date_fin_service_mois=lookup_widget(objet_graphic,"Yassspinbutton_date_fin_service_mois");
Yassspinbutton_date_fin_service_annee=lookup_widget(objet_graphic,"Yassspinbutton_date_fin_service_annee");


//cette partie genial d'obtention de date systeme


		int hours, minutes, seconds, day, month, year;

		// time_t is arithmetic time type
		time_t now;

		// Obtain current time
		// time() returns the current time of the system as a time_t value
		time(&now);

		// Convert to local time format and print to stdout
		printf("Today is : %s", ctime(&now));
		
		// localtime converts a time_t value to calendar time and returns a pointer
		// to a tm structure with its members filled with the corresponding values
		struct tm *local = localtime(&now);
		
		hours = local->tm_hour; // get hours since midnight (0-23)
		minutes = local->tm_min; // get minutes passed after the hour (0-59)
		seconds = local->tm_sec; // get seconds passed after the minute (0-59)

		day = local->tm_mday; // get day of month (1 to 31)
		month = local->tm_mon + 1; // get month of year (0 to 11)
		year = local->tm_year + 1900; // get year since 1900

		// print local time
		if (hours < 12) // before midday
		printf("Time is : %02d:%02d:%02d am\n", hours, minutes, seconds);
		else // after midday
		printf("Time is : %02d:%02d:%02d pm\n", hours - 12, minutes, seconds);
		
		// print current date
		printf("Date is : %02d/%02d/%d\n", day, month, year);
		
sprintf(rec.date_rec,"%02d/%02d/%d", day, month, year);


rec.date_service.jour = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Yassspinbutton_date_fin_service_jour));
rec.date_service.mois = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Yassspinbutton_date_fin_service_mois));
rec.date_service.annee = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Yassspinbutton_date_fin_service_annee));

strcpy(rec.etat ,"EnAttente") ;
strcpy(rec.reponse,"Patienter") ;  
strcpy(rec.date_rep,"--/--/----")  ;


int jour_service;
int mois_service;
int ann_service;
jour_service = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Yassspinbutton_date_fin_service_jour));
mois_service = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Yassspinbutton_date_fin_service_mois));
ann_service = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Yassspinbutton_date_fin_service_annee));

char erreur1[500];
char erreur2[500];
strcpy(erreur1,"Reclamation Bien envoyé ! merci de patienter votre reponse ! ");
strcpy(erreur2,"Désolé vous avez depasser les delais de 30 jours " );










 if ( year < ann_service )
	{
	ajouter_Reclamation(rec);
	gtk_label_set_text(GTK_LABEL(Yass_label_outputAjouterRec),erreur1);
	}		
else if ((year == ann_service )  ) 
	{
	if  (month < mois_service)
		{
		ajouter_Reclamation(rec);
		gtk_label_set_text(GTK_LABEL(Yass_label_outputAjouterRec),erreur1);}
	else if (month== mois_service)
		{
		
		ajouter_Reclamation(rec);
		gtk_label_set_text(GTK_LABEL(Yass_label_outputAjouterRec),erreur1);
		}
	else 	gtk_label_set_text(GTK_LABEL(Yass_label_outputAjouterRec),erreur2);	
	}
else 	{
	gtk_label_set_text(GTK_LABEL(Yass_label_outputAjouterRec),erreur2);
	}    

//ajouter_Reclamation(rec);



}                                                                                   

     




/*boutton afficher reclamation de interface client yass_button_affichRecClient */
void
on_yass_button_affichRecClient_clicked (GtkWidget       *objet_graphic,
                                        gpointer         user_data)
{
      
GtkWidget *old;
GtkWidget *new;
GtkWidget *treeview;

old=lookup_widget(objet_graphic,"YassRecEspaceCWind");
new=create_YassAfficherVosRecWind();

gtk_widget_show(new);
treeview=lookup_widget(new,"Yasstreeview_VosRec");



afficher_Reclamation(treeview);
gtk_widget_destroy(old);



}




void
on_button_Retour_VosRec__EspaceResC_clicked
                                        (GtkWidget       *objet_graphic,
                                        gpointer         user_data)
{


/*GtkWidget *old;
GtkWidget *new;


old=lookup_widget(objet_graphic,"YassAfficherVosRecWind");
new=create_YassRecEspaceCWind();

gtk_widget_show(new);


gtk_widget_destroy(old);*/



        GtkWidget *YassRecEspaceCWind;
        GtkWidget *YassAfficherVosRecWind;
  	

	YassRecEspaceCWind = create_YassRecEspaceCWind ();
	gtk_widget_show (YassRecEspaceCWind);
  
	YassAfficherVosRecWind =lookup_widget(objet_graphic,"YassAfficherVosRecWind");
	gtk_widget_destroy (YassAfficherVosRecWind);

}


void
on_Y_button_EspaceRecAdmin_clicked     (GtkWidget       *objet_graphic,
                                        gpointer         user_data)
{
	GtkWidget *YassEspaceAdminWind;
        GtkWidget *YassAfficherVosRecWind;
  	

	YassAfficherVosRecWind = create_YassAfficherVosRecWind ();
	gtk_widget_show (YassAfficherVosRecWind);
  
	YassEspaceAdminWind =lookup_widget(objet_graphic,"YassEspaceAdminWind");
	gtk_widget_destroy (YassEspaceAdminWind);
}


void
on_Y_button_EspaceRecAgent_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_Y_button_AjouterRecClient_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_Y_button_affichRecClient_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_Y_button_Retour_fromRecClient_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}

//////////*****************************************************
void
on_Y_button_ValiderRecEspaceC_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_Yassbutton_Modif_VosRec_clicked     (GtkWidget       *objet_graphic,
                                        gpointer         user_data)
{
	/*GtkWidget *Yasstreeview_VosRec;
	GtkWidget *YassUpdateRecWind;
	GtkTreeModel *model;
	GtkTreeSelection *selection;
	GtkTreeIter iter;
	
	GtkWidget *YassRecEspaceCWind;
	GtkWidget *YassAfficherVosRecWind;
  	
	gchar *id;
	gchar *service;
	gchar *type;
	gchar *description;
	gchar *date_service;
	gchar *date_rec;
	gchar *etat;
	gchar *reponse;
	gchar *date_rep;

	YassAfficherVosRecWind =lookup_widget(objet_graphic,"YassAfficherVosRecWind"); 
	Yasstreeview_VosRec =lookup_widget(objet_graphic,"Yasstreeview_VosRec");

	selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(Yasstreeview_VosRec));
	if (gtk_tree_selection_get_selected(selection, &model, &iter))//test sur la ligne selectionnée
        {  gtk_tree_model_get (model,&iter,0,&id,1, &service, 2, &type, 3, &description , 4 ,&date_service, 5, &date_rec, 6, &etat, 7, &reponse, 8,&date_rep, -1);

	
	gtk_entry_set_text(GTK_ENTRY(lookup_widget(YassRecEspaceCWind,"YassentryClientAjoutRec")),description);
	/*gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(YassRecEspaceCWind,"Y_combobox_ServiceReclamee")),service);
	gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(YassRecEspaceCWind,"Y_combobox_type_rec")),type);
*/

         
/*
	GtkWidget *YassUpdateRecWind;
	GtkWidget *YassAfficherVosRecWind;

	//YassUpdateRecWind = create_YassUpdateRecWind ();
	//gtk_widget_show (YassUpdateRecWind);
  
	YassAfficherVosRecWind =lookup_widget(objet_graphic,"YassAfficherVosRecWind");
	gtk_widget_destroy (YassAfficherVosRecWind);*/
}
/*

	Reclamation rec;

	GtkWidget *YassentryClientAjoutRec, 

	GtkWidget *YassRecEspaceCWind;
	GtkWidget *YassAfficherVosRecWind;

	YassAfficherVosRecWind=lookup_widget(objet_graphic,"YassAfficherVosRecWind");

	YassentryClientAjoutRec=lookup_widget(objet_graphic,"description");



	strcpy(rec.description,gtk_entry_get_text(GTK_ENTRY(YassentryClientAjoutRec)));

	strcpy(rec.service,gtk_combo_box_get_active_text(GTK_COMBO_BOX(lookup_widget(YassRecEspaceCWind,"Y_combobox_ServiceReclamee"))));
	strcpy(rec.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(lookup_widget(YassRecEspaceCWind,"Y_combobox_type_rec"))));

        rec.date_service->jour =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(YassRecEspaceCWind,"Yassspinbutton_date_fin_service_jour")));
        rec.date_service->mois =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(YassRecEspaceCWind,"Yassspinbutton_date_fin_service_mois")));
        rec.date_service->annee =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(YassRecEspaceCWind,"Yassspinbutton_date_fin_service_annee")));






modifier_Reclamation(Reclamation rec);


YassAfficherVosRecWind=lookup_widget(objet_graphic,"YassAfficherVosRecWind");

gtk_widget_destroy(YassAfficherVosRecWind);
YassRecEspaceCWind=create_YassRecEspaceCWind();
gtk_widget_show(YassRecEspaceCWind);
};
}


*/




void
on_Yassbutton_Supp_VosRec_clicked      (GtkWidget       *objet_graphic,
                                        gpointer         user_data)
{
	/*GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* p;
        GtkWidget *label;
        gchar* description;
        p=lookup_widget(create_YassAfficherVosRecWind,"Yasstreeview_VosRec");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&description,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

           supprimer_Reclamation(description);// supprimer la ligne du fichier

           
        }
*/


        GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* Yasstreeview_VosRec;
        GtkWidget *YassAfficherVosRecWind;  //page elli feha treeview
        gchar* id;//gchar* type gtk ==> chaine en c car la fonction gtk_tree_model_get naccepte que gchar*

        YassAfficherVosRecWind=lookup_widget(objet_graphic,"YassAfficherVosRecWind");
        Yasstreeview_VosRec=lookup_widget(YassAfficherVosRecWind,"Yasstreeview_VosRec");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(Yasstreeview_VosRec));

        if (gtk_tree_selection_get_selected(selection, &model, &iter))//test sur la ligne selectionnée
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

           supprimer_Reclamation(id);// supprimer la ligne du fichier

         }


















}

/******
void
on_Yasstreeview_VosRec_row_activated (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data) 
{
 	/*gchar *id;
	gchar *service;
	gchar *type;
	gchar *description;
	gchar *date_service;
	gchar *etat;
	gchar *reponse;
	gchar *date_rep;
	gchar *date_rec;

        int x;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget *p=lookup_widget(YassRecEspaceCWind,"Yasstreeview_VosRec");
        GtkTreeSelection *selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {
                gtk_tree_model_get (model,&iter,0,&id,1,&service,2,&type,3,&description,4,&date_service,5,&etat,6,&reponse,7,date_rep,8,date_rec,-1);//recuperer les information de la ligne selectionneé

                gtk_entry_set_text(GTK_ENTRY(lookup_widget(YassRecEspaceCWind,"YassentryClientAjoutRec")),description);


                gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(YassRecEspaceCWind,"Yassspinbutton_date_fin_service")),date_service.jour);
                gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(YassRecEspaceCWind,"Yassspinbutton_date_fin_service")),date_service.mois);
		gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(YassRecEspaceCWind,"Yassspinbutton_date_fin_service")),date_service.annee);


               // if(strcmp(typeChambre,"Simple")==0) x=0;
               // if(strcmp(typeChambre,"Double")==0) x=1;




                gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(YassRecEspaceCWind,"Y_combobox_ServiceReclamee")),x);
		/*GtkWidget* msg=lookup_widget(YassRecEspaceCWind,"label25");
                gtk_label_set_text(GTK_LABEL(msg),nom);*/

	/*	gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(YassRecEspaceCWind,"Y_combobox_type_rec")),x);
		


        gtk_widget_show(lookup_widget(YassRecEspaceCWind,"button7"));//afficher le bouton modifier
        GtkWidget* msg1=lookup_widget(YassRecEspaceCWind,"label27");
        gtk_widget_hide(msg1);

}



}
*/




void
on_ybutton_modifier_car_clicked        (GtkWidget       *objet_graphic,
                                        gpointer         user_data)
{/*
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


*/
}


void
on_ybutton_suppcar_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{/*

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
*/
}
void
on_y_button_rechcar_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{

/*




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

nb=ChercherVolTree(p1,"vols.txt",companie);     */


/* afficher le nombre de resultats obtenue par la recherche */
/*
sprintf(chnb,"%d",nb);
nbResultat=lookup_widget(gestio_Vol,"label71");
message=lookup_widget(gestio_Vol,"label72");
gtk_label_set_text(GTK_LABEL(nbResultat),chnb);

gtk_widget_show (nbResultat);
gtk_widget_show (message);


*/

}


void
on_ybutton_ajoutercar_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
/*
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
else	{
           gtk_widget_hide (labelExist);

f=fopen("vols.txt","a+");
fprintf(f,"%s %s %s %s %d/%d/%d %d/%d/%d %d %d\n",v.id,v.depart,v.destination,v.companie,jj1,mm1+1,aa1,jj2,mm2+1,aa2,v.nbVols,v.prix);
fclose(f);
                gtk_widget_show (labelsuccess);


//mise a jour du treeView
GtkWidget *p;
p=lookup_widget(gestio_Vol,"treeview2");
Voltree(p,"vols.txt");



}*/

}


void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
/*
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


*/

}



void
on_YassbuttonVoit_GestWind_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{

}

/*
void
on_Yassbotn_CheckId_UpdateRec_clicked  (GtkWidget       *objet_graphic,
                                        gpointer         user_data)
{
	GtkWidget *YassRecEspaceCWind;
	GtkWidget *YassAfficherVosRecWind;
	GtkWidget *output1 , *output2 , *output3,*output4,*output5;
	GtkWidget *input1;
	Reclamation rc;
	char idd[30];
	FILE *f;

	input1=lookup_widget(objet_graphic,"Yassentry_CheckId_UpdateRec");

	strcpy (idd,gtk_entry_get_text(GTK_ENTRY(input1)));

	f=fopen("/home/yass/Projects/YassinePC/db/Liste_reclamation_client.txt","r"); 
	   if (f!=NULL)
	   {
	    while (fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s \n"rc.id,rc.service,rc.type, rc.description, rc.date_service, rc.date_rec,rc.etat,rc.reponse,rc.date_rep);)!=EOF)
		{
	   if ((strcmp(rc.id,idd)==0))

{  	
	Yassentry_CheckId_UpdateRec=lookup_widget(objet_graphic,"Yassentry_CheckId_UpdateRec");
	gtk_widget_destroy(Yassentry_CheckId_UpdateRec);
	YassRecEspaceCWind=create_YassRecEspaceCWind();
	gtk_widget_show(YassRecEspaceCWind);

	output1=lookup_widget(RmodifV,"YassentryClientAjoutRec");
	output4=lookup_widget(RmodifV,"Rspinbutton25");
	output5=lookup_widget(RmodifV,"Rspinbutton21");
	output6=lookup_widget(RmodifV,"Rspinbutton20");
	output7=lookup_widget(RmodifV,"RspinbutYassentryClientAjoutRecton19");
	output8=lookup_widget(RmodifV,"Rspinbutton22");
	output9=lookup_widget(RmodifV,"Rspinbutton23");
	output10=lookup_widget(RmodifV,"Rspinbutton24");
	output11=lookup_widget(RmodifV,"Rentry15");

	gtk_entry_set_text(GTK_ENTRY(output1),rv.id);
	gtk_entry_set_text(GTK_ENTRY(output2),rv.depart);
	gtk_entry_set_text(GTK_ENTRY(output3),rv.arrive);
	gtk_entry_set_text(GTK_ENTRY(output4),rv.nb_pass);
	gtk_entry_set_text(GTK_ENTRY(output5),rv.de_jour);
	gtk_entry_set_text(GTK_ENTRY(output6),rv.de_mois);
	gtk_entry_set_text(GTK_ENTRY(output7),rv.de_an);
	gtk_entry_set_text(GTK_ENTRY(output8),rv.a_jour);
	gtk_entry_set_text(GTK_ENTRY(output9),rv.a_mois);
	gtk_entry_set_text(GTK_ENTRY(output10),rv.a_an);
	gtk_entry_set_text(GTK_ENTRY(output11),rv.prix);
		}
	}	
   }
    fclose(f);
}












  	

	YassRecEspaceCWind = create_YassRecEspaceCWind ();
	gtk_widget_show (YassRecEspaceCWind);
  
	YassAfficherVosRecWind =lookup_widget(objet_graphic,"YassAfficherVosRecWind");
	gtk_widget_destroy (YassAfficherVosRecWind);
}*/


void
on_yassbuttonmodifvoit_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_yassbuttonsupprimervoiture_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ybuttonretour54_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

}

