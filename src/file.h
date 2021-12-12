#include <gtk/gtk.h>
typedef struct
{
int jour;
int mois;
int annee;
}Datee;

typedef struct

{
char type[30];
char identifiant[30];
char marque[30];
char quantite[30];
Datee date;
}STOCK;

void ajout(STOCK c);
void recherche(GtkWidget* treeview11);
void suppression(char id[30], STOCK c);
void affichage(GtkWidget* treeview11);
void modification(char id[30],STOCK c);
void affichagestat(GtkWidget* treeview12);
int verifid(char id[30]);
int veriff(char x[]);



