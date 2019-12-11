#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"


void
on_button5_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button4_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button6_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button7_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button10_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button12_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button8_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ajouter_gestion_client_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowgestionclient;
GtkWidget *windowAjouterclient;
windowAjouterclient=create_windowAjouterclient();
gtk_widget_show(windowAjouterclient);
windowgestionclient=lookup_widget(objet,"windowgestionclient");
gtk_widget_destroy(windowgestionclient);
}


void
on_modifier_gestion_client_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *modifiergestionclient;
modifiergestionclient=create_windowModifierclient();
gtk_widget_show(modifiergestionclient);
}


void
on_supprimer_gestion_client_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_retour_gestion_client_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_retour_ajouter_client_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
/*GtkWidget *windowgestionclient , *windowAjouterclient;
windowAjouterclient=lookup_widget(GObject,"windowAjouterclient");
gtk_widget_destroy(windowAjouterclient);
windowgestionclient=create_windowgestionclient ();
gtk_widget_show(windowgestionclient);*/
GtkWidget *retourajouterclient;
retourajouterclient=create_windowgestionclient();
gtk_widget_show(retourajouterclient);
}


void
on_ajouter_ajouter_client_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_modifier_modifier_client_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_retour_modifier_client_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *retourmodifierclient;
retourmodifierclient=create_windowgestionclient();
gtk_widget_show(retourmodifierclient);
}


void
on_reserver_reserver_excursion_a_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_supprimer_reserver_excursion_a_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_Ajouter_reserver_excursion_a_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_retour_reserver_excursion_a_clicked (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_retour_reserver_excursion_c_clicked (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_reserver_reserver_excursion_c_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}

