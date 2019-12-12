#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "callbacks.h"
#include<string.h>

/***************************************************** hotels *******************************/
void ajout( hotel h){
FILE*f=NULL;
f=fopen("hotels.txt","a+");
fprintf(f,"%s %s %s %s %d %d\n",h.nom,h.typeChambre,h.dateAdmission,h.dateSortie,h.nbChambre,h.prix);
fclose(f);

}

int exist(char*nom){
FILE*f=NULL;
 hotel h;
f=fopen("hotels.txt","r");
while(fscanf(f,"%s %s %s %s %d %d\n",h.nom,h.typeChambre,h.dateAdmission,h.dateSortie,&h.nbChambre,&h.prix)!=EOF){
if(strcmp(h.nom,nom)==0)return 1;
}
fclose(f);
return 0;
}


void supp(char*nom){
FILE*f=NULL;
FILE*f1=NULL;
 hotel h;
f=fopen("hotels.txt","r");

f1=fopen("ancien.txt","w+");
while(fscanf(f,"%s %s %s %s %d %d\n",h.nom,h.typeChambre,h.dateAdmission,h.dateSortie,&h.nbChambre,&h.prix)!=EOF){
if(strcmp(nom,h.nom)!=0)fprintf(f1,"%s %s %s %s %d %d\n",h.nom,h.typeChambre,h.dateAdmission,h.dateSortie,h.nbChambre,h.prix);
}
fclose(f);
fclose(f1);
remove("agents.txt");
rename("ancien.txt","hotels.txt");
}
/***************************************************** vols *******************************/
void ajouter_vol( vol v){
FILE*f=NULL;
f=fopen("vols.txt","a+");
fprintf(f,"%s %s %s %s %s %s %d %d\n",v.id,v.depart,v.destination,v.companie,v.date_depart,v.date_retour,v.nbVols,v.prix);
fclose(f);

}

int exist_vol(char*id){
FILE*f=NULL;
 vol v;
f=fopen("vols.txt","r");
while(fscanf(f,"%s %s %s %s %s %s %d %d\n",v.id,v.depart,v.destination,v.companie,v.date_depart,v.date_retour,&v.nbVols,&v.prix)!=EOF)
{
if(strcmp(id,v.id)==0)return 1;
}
fclose(f);
return 0;
}


void supprimer_vol(char*id){
FILE*f=NULL;
FILE*f1=NULL;
 vol v;
f=fopen("vols.txt","r");

f1=fopen("ancien.txt","w+");
while(fscanf(f,"%s %s %s %s %s %s %d %d\n",v.id,v.depart,v.destination,v.companie,v.date_depart,v.date_retour,&v.nbVols,&v.prix)!=EOF)
{
if(strcmp(id,v.id)!=0)fprintf(f1,"%s %s %s %s %s %s %d %d\n",v.id,v.depart,v.destination,v.companie,v.date_depart,v.date_retour,v.nbVols,v.prix);
}
fclose(f);
fclose(f1);
remove("vols.txt");
rename("ancien.txt","vols.txt");
}


