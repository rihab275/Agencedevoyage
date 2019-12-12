#include "resvoiture.h"

void ajouter_vol( vol v){
FILE*f=NULL;
f=fopen("/home/yass/Projects/YassinePC/db.txt","a+");
fprintf(f,"%s %s %s %s %s %d\n",v.id,v.depart,v.destination,v.date_depart,v.date_retour,v.prix);
fclose(f);

}

int exist_vol(char*id){
FILE*f=NULL;
 vol v;
f=fopen("/home/yass/Projects/YassinePC/db.txt","r");
while(fscanf(f,"%s %s %s %s %s %d\n",v.id,v.depart,v.destination,v.date_depart,v.date_retour,&v.prix)!=EOF)
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
f=fopen("/home/yass/Projects/YassinePC/db.txt","r");

f1=fopen("/home/yass/Projects/YassinePC/db.txt","w+");
while(fscanf(f,"%s %s %s %s %s %d\n",v.id,v.depart,v.destination,v.date_depart,v.date_retour,&v.prix)!=EOF)
{
if(strcmp(id,v.id)!=0)fprintf(f1,"%s %s %s %s %s %d\n",v.id,v.depart,v.destination,v.date_depart,v.date_retour,v.prix);
}
fclose(f);
fclose(f1);
remove("/home/yass/Projects/YassinePC/db.txt");
rename("/home/yass/Projects/YassinePC/db.txt","/home/yass/Projects/YassinePC/db.txt");
}

































/*
void ajouter_vol( vol v){
FILE*f=NULL;
f=fopen("/home/yass/Projects/YassinePC/db.txt","a+");
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

*/
