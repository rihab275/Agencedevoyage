#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <time.h>

/*--------------  declaration type temps ----------------*/

typedef struct 
{

int hh;
int mm;

} tempyassin ; 



/*--------------  declaration type date ----------------*/

typedef struct 
{

int jour;
int mois;
int annee;
} dateyassin; 




void current_Time ();
void time_now(int *dayr,int *mounthr,int *yearr);
