#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "file.h"

char id[30],idrech[30];
int l=0,j=0,m=0;
GtkWidget *windowgestion;


void
on_button_cnx_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonmenucp_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
	

}


void
on_buttonrecherchrer_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
STOCK c;
GtkWidget *entryid;
GtkWidget *treeview11;
FILE*f;
FILE*f2;


windowgestion=lookup_widget(button,"windowgestion");
entryid=lookup_widget(button,"entryid");
strcpy(idrech,gtk_entry_get_text(GTK_ENTRY(entryid)));
f=fopen("stock.bin","rb");

 if(f!=NULL)
 {
  while(fread(&c,sizeof(STOCK),1,f))
     {
       f2=fopen("recherche.bin","ab+");
       if  (f2!=NULL)
   {  
     
     if (((strcmp(c.identifiant,idrech)==0))||((strcmp(c.type,idrech)==0))||((strcmp(c.marque,idrech)==0)))
     { 
     fwrite(&c,sizeof(STOCK),1,f2);
     }
   
     treeview11=lookup_widget(windowgestion,"treeview11");
     recherche(treeview11);
    
        fclose(f2);
    }

 }
 fclose(f);
}
remove("recherche.bin");
}


void
on_treeview11_row_activated            (GtkTreeView     *treeview11,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* identifiant;
	GtkTreeModel *Model = gtk_tree_view_get_model(treeview11);

		if (gtk_tree_model_get_iter(Model, &iter, path)){
				gtk_tree_model_get(GTK_LIST_STORE(Model),&iter,1,&identifiant, -1);
				strcpy(id,identifiant);}
}


void
on_buttonsupprimer_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
STOCK c;
	    GtkWidget *treeview11;
	    windowgestion=lookup_widget(button,"windowgestion");
	    treeview11=lookup_widget(windowgestion,"treeview11");
	    suppression(id,c);
            affichage(treeview11);
}


void
on_buttonmodifier_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
		gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(windowgestion,"notebook6")));
                gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(windowgestion,"notebook6")));
}


void
on_buttonactualiser_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview11;
windowgestion=lookup_widget(button,"windowgestion");
treeview11=lookup_widget(windowgestion,"treeview11");
affichage(treeview11);
}


void
on_buttonboard_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
		gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(windowgestion,"notebook6")));
                gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(windowgestion,"notebook6")));
		gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(windowgestion,"notebook6")));
}


void
on_buttonajouter_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
		gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(windowgestion,"notebook6")));
}


void
on_buttonajout_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
char Type[30];char Marque[30];char x[30];
STOCK c;
GtkWidget *entryajoutidentifiant;
GtkWidget *comboboxajoutmarque;
GtkWidget *entryajoutquantite;
GtkWidget *spinbuttonajoutjour;
GtkWidget *spinbuttonajoutmois;
GtkWidget *spinbuttonajoutannee;
GtkWidget *comboboxajouttype;
GtkWidget *sortiea;
GtkWidget *radiobutton1;
GtkWidget *radiobutton2;

spinbuttonajoutjour=lookup_widget(button, "spinbuttonajoutjour");
spinbuttonajoutmois=lookup_widget(button, "spinbuttonajoutmois");
spinbuttonajoutannee=lookup_widget(button, "spinbuttonajoutannee");
comboboxajouttype=lookup_widget(button, "comboboxajouttype");
radiobutton1=lookup_widget(button, "radiobutton1");
radiobutton2=lookup_widget(button, "radiobutton2");
entryajoutidentifiant=lookup_widget(button,"entryajoutidentifiant");
comboboxajoutmarque=lookup_widget(button,"comboboxajoutmarque");
entryajoutquantite=lookup_widget(button,"entryajoutquantite");
sortiea=lookup_widget(button, "labelajoutreus");

strcpy(x,gtk_entry_get_text(GTK_ENTRY(entryajoutidentifiant)));
if (veriff(x)==0){gtk_label_set_text(GTK_LABEL(sortiea),"ajoutez un identifiant svp!");}
else if (veriff(x)==1){
	if(verifid(x)==0){gtk_label_set_text(GTK_LABEL(sortiea),"identifiant existe déja !");}

else if((verifid(x)==1)&&(l==1)){


strcpy(c.identifiant,gtk_entry_get_text(GTK_ENTRY(entryajoutidentifiant)));
strcpy(c.quantite,gtk_entry_get_text(GTK_ENTRY(entryajoutquantite)));
c.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonajoutjour));
c.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonajoutmois));
c.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonajoutannee));
if (m==1)
{strcpy(Marque,"marque2");}
else if (m==2)
{strcpy(Marque,"marque1");}

strcpy(Type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxajouttype)));
//strcpy(Marque,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxajoutmarque)));
strcpy(c.type,Type);
strcpy(c.marque,Marque);
ajout(c);
gtk_label_set_text(GTK_LABEL(sortiea),"ajout effectué avec succés");
}}}


void
on_buttonmodif_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
STOCK c;char Type[30];char Marque[30];char x[30];
GtkWidget *comboboxmodiftype;
//GtkWidget *entrymodifidentifiant;
GtkWidget *comboboxmodifmarque;
GtkWidget *spinbuttonmodifjour;
GtkWidget *spinbuttonmodifmois;
GtkWidget *spinbuttonmodifannee;
GtkWidget *entrymodifquantite;
GtkWidget *sortiem;    
	
spinbuttonmodifjour=lookup_widget(button, "spinbuttonmodifjour");
spinbuttonmodifmois=lookup_widget(button, "spinbuttonmodifmois");
spinbuttonmodifannee=lookup_widget(button, "spinbuttonmodifannee");
comboboxmodiftype=lookup_widget(button, "comboboxmodiftype");
//entrymodifidentifiant=lookup_widget(button,"entrymodifidentifiant");
comboboxmodifmarque=lookup_widget(button,"comboboxmodifmarque");
entrymodifquantite=lookup_widget(button,"entrymodifquantite");
sortiem=lookup_widget(button, "labelmodifreus");
if (j==1){
strcpy(c.identifiant,id);
strcpy(c.quantite,gtk_entry_get_text(GTK_ENTRY(entrymodifquantite)));
c.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonmodifjour));
c.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonmodifmois));
c.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonmodifannee));
strcpy(Type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxmodiftype)));
strcpy(Marque,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxmodifmarque)));
strcpy(c.type,Type);
strcpy(c.marque,Marque);

modification(id,c);
gtk_label_set_text(GTK_LABEL(sortiem),"Modification effectué avec succés");
}}


void
on_buttonaffichboard_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

STOCK c;

GtkWidget *treeview12;


treeview12=lookup_widget(windowgestion,"treeview12");
affichagestat(treeview12);
}


void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
l=1;}

}


void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
j=1;}

}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
m=1;}
}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
m=2;}
}

