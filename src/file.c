#include <stdlib.h>
#include <stdio.h>
#include<string.h>

#include "file.h"
enum{TYPE2,IDENTIFIANT2,MARQUE,DATE2,QUANTITE2,COLUMNS2};
enum{TYPEC,IDENTIFIANTC,MARQUEC,QUANTITEC,COLUMNSC};

void affichage(GtkWidget* treeview11)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
STOCK c;char Date[100];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(treeview11);
if (store==NULL)
{
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Type", renderer, "text",TYPE2, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview11), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Identifiant", renderer, "text",IDENTIFIANT2, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview11), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Marque", renderer, "text",MARQUE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview11), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Date d'éxpiration", renderer, "text",DATE2, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview11), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Quantité", renderer, "text",QUANTITE2, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview11), column);}

store=gtk_list_store_new(COLUMNS2,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("stock.bin","rb");
if(f==NULL)
{return;}
else
{f=fopen("stock.bin","ab+");
while(fread(&c,sizeof(STOCK),1,f))
{sprintf(Date,"%d/%d/%d",c.date.jour,c.date.mois,c.date.annee);
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,TYPE2,c.type,IDENTIFIANT2,c.identifiant,MARQUE,c.marque,DATE2,Date,QUANTITE2,c.quantite,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(treeview11),GTK_TREE_MODEL (store));
g_object_unref(store);}}



void ajout (STOCK c){
FILE*f=NULL; 
f=fopen("stock.bin","ab+");
fwrite(&c,sizeof(STOCK),1,f);  
fclose(f);
 
}


void suppression(char id[30],STOCK c){
FILE*f;
FILE*g;
f=fopen("stock.bin","rb+");
g=fopen("tmp.bin","wb+");
if(g!=NULL){
while(fread(&c,sizeof(STOCK),1,f))
{
if (strcmp(c.identifiant,id)!=0){
fwrite(&c,sizeof(STOCK),1,g);

}
}
}fclose(f);
fclose(g);
remove("stock.bin");
rename("tmp.bin","stock.bin");
}



void modification(char id[30],STOCK c)
{

	suppression(id,c);
	ajout(c);

}

void recherche(GtkWidget* treeview11)
{
GtkCellRenderer *renderer;
 GtkTreeViewColumn *column;
 GtkTreeIter iter;
 GtkListStore *store;

store=NULL;STOCK c;
 FILE *f2;char Date[100]; 
 store=gtk_tree_view_get_model(treeview11);
 if (store==NULL)
{

   renderer=gtk_cell_renderer_text_new();
   column= gtk_tree_view_column_new_with_attributes("Type",renderer, "text",TYPE2,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(treeview11), column);
 
   renderer=gtk_cell_renderer_text_new();
   column= gtk_tree_view_column_new_with_attributes("Identifiant",renderer, "text",IDENTIFIANT2,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(treeview11), column);
  
   renderer=gtk_cell_renderer_text_new();
   column= gtk_tree_view_column_new_with_attributes("Marque",renderer, "text",MARQUE,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(treeview11), column);
   
   renderer=gtk_cell_renderer_text_new();
   column= gtk_tree_view_column_new_with_attributes("Date d'éxpiration",renderer, "text",DATE2,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(treeview11), column);
   
   renderer=gtk_cell_renderer_text_new();
   column= gtk_tree_view_column_new_with_attributes("Quantité",renderer, "text",QUANTITE2,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(treeview11), column);}
  
store=gtk_list_store_new(COLUMNS2, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f2=fopen("recherche.bin", "rb");
if(f2==NULL)
{
 return;
}
else 
{ f2=fopen("recherche.bin", "ab+");
    while(fread(&c,sizeof(STOCK),1,f2))
     {sprintf(Date,"%d/%d/%d",c.date.jour,c.date.mois,c.date.annee);
gtk_list_store_append (store,&iter);
gtk_list_store_set (store,&iter,TYPE2,c.type,IDENTIFIANT2,c.identifiant,MARQUE,c.marque,DATE2,Date,QUANTITE2,c.quantite, -1);
}
fclose(f2);
gtk_tree_view_set_model (GTK_TREE_VIEW (treeview11), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}
int verifid(char id[30])
{
   STOCK c;
   int res = 1;
   FILE *f;
   f = fopen("stock.bin", "ab+");
   if (f != NULL)
   {
      while (fread(&c,sizeof(STOCK),1,f))
      {
         if (strcmp(id,c.identifiant) == 0)
         {
            res = 0;
         }
         else
         {
            res = 1;
         }
      }
   }
   fclose(f);
   return res;
}
int veriff(char x[])
{
   int i=0;
   if (strcmp(x, "")==0)
   {
      i=0;
   }
   else
   {
      i=1;
   }
   return i;
}



void affichagestat(GtkWidget* treeview12)
{

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
STOCK c;char Date[100];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(treeview12);
if (store==NULL)
{
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Type", renderer, "text",TYPEC, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview12), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Identifiant", renderer, "text",IDENTIFIANTC, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview12), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Marque", renderer, "text",MARQUEC, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview12), column);

renderer=gtk_cell_renderer_text_new();
   column= gtk_tree_view_column_new_with_attributes("Quantité",renderer, "text",QUANTITEC,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(treeview12), column);}

store=gtk_list_store_new(COLUMNSC,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("stock.bin","rb");
if(f==NULL)
{return;}
else
{f=fopen("stock.bin","ab+");
while(fread(&c,sizeof(STOCK),1,f))
{
if( ((strcmp(c.type,"produit1")==0)&& (atoi(c.quantite)==0))||((strcmp(c.type,"produit2")==0)&& (atoi(c.quantite)==0)) ||((strcmp(c.type,"produit3")==0)&& (atoi(c.quantite)==0)) )
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,TYPEC,c.type,IDENTIFIANTC,c.identifiant,MARQUEC,c.marque,QUANTITEC,c.quantite,-1);
}}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(treeview12),GTK_TREE_MODEL (store));
g_object_unref(store);}}



