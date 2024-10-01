#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct contact {
    char nom[30];
    char numero[15];
    char email[100];

} CONTACT;

struct contact carnet[MAX];

void ajouter();
void afficher();
void rechercher();
void modifier();
void supprimer();


int n =0;


int main(){

    int choix;
        
        do
        {
        
            printf("\n  Systeme de Gestion de contacts \n");
            printf("1. Ajouter un contact\n");
            printf("2. Afficher tous les contacts\n");
            printf("3. Rechercher un contact\n");
            printf("4. Modifier un contact\n");
            printf("5. Supprimer un contact\n");
            printf("0. Quitter\n");
            printf("Choisissez une option : ");
            scanf("%d", &choix);
            getchar();

            switch (choix)
            {
            case 1:
                ajouter( );
                break;
            case 2:
                afficher();
                break;
            case 3:
                rechercher();
                break;
            case 4:
                modifier();
                break;
            case 5:
                supprimer();
                break;
            case 0:
                
                break;
    
            default:
            printf("-choix invalide \n");
            
            }


        } while (choix != 0);
}



void ajouter(){
    if (n >= MAX) {
        printf("Le carnet de contacts est plein !\n");
        return;
    }

    printf("Nom du contact : ");
    fgets(carnet[n].nom, sizeof(carnet[n].nom), stdin);
    carnet[n].nom[strcspn(carnet[n].nom, "\n")] = 0;

    printf("Numero du contact : ");
    fgets(carnet[n].numero, sizeof(carnet[n].numero), stdin);
    carnet[n].numero[strcspn(carnet[n].numero, "\n")] = 0;

      printf("Email du contact : ");
    fgets(carnet[n].email, sizeof(carnet[n].email), stdin);
    carnet[n].email[strcspn(carnet[n].email, "\n")] = 0;

    n++;
    printf("Contact ajoute avec succes.\n");
    
}



void afficher(){
    if (n == 0) {
        printf("Le carnet de contacts est vide !\n");
        return;
    }

    for (int i = 0; i < n; i++){
        printf("\nContact %d:\n", i + 1);
        printf(" Nom: %s\n", carnet[i].nom);
        printf(" Telephone: %s\n", carnet[i].numero);
        printf(" Email: %s\n", carnet[i].email);
    }
}



void rechercher(){

    if (n == 0) {
        printf("Le carnet de contacts est vide !\n");
        return;
    }
    char recherche[30];
    printf("Nom du contact a rechercher : ");
    fgets(recherche, sizeof(recherche), stdin);
    recherche[strcspn(recherche,"\n")] = 0;
    
    int found = 0;
    for (int i = 0; i < n; i++){
        if (strcmp(carnet[i].nom, recherche) == 0){
            printf("\nContact %d:\n", i + 1);
            printf(" Nom: %s\n", carnet[i].nom);
            printf(" Telephone: %s\n", carnet[i].numero);
            printf(" Email: %s\n", carnet[i].email);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact non trouve.\n");
    }

}



void modifier(){
     if (n == 0) {
        printf("Le carnet de contacts est vide !\n");
        return;
    }
    char recherche[30];
    printf("Nom du contact à rechercher : ");
    fgets(recherche, sizeof(recherche), stdin);
    recherche[strcspn(recherche,"\n")] = 0;

    for(int i = 0; i < n; i++){
        
        if (strcmp(carnet[i].nom, recherche) == 0) {

            printf("Nouveau numero de telephone : ");
            fgets(carnet[i].numero,sizeof(carnet[i].numero), stdin);
            carnet[i].numero[strcspn(carnet[i].numero,"\n")] = 0;

            printf("Nouvelle adresse email : ");
            fgets(carnet[i].email, sizeof(carnet[i].email), stdin);
            carnet[i].email[strcspn(carnet[i].email, "\n")] = 0;

            printf("Contact modifié avec succès.\n");
            return;
        }
    }
    printf("Contact non trouve.\n");
    
}



void supprimer(){

     if (n == 0) {
        printf("Le carnet de contacts est vide !\n");
        return;
    }
    char recherche[30];
    printf("Nom du contact à rechercher : ");
    fgets(recherche, sizeof(recherche), stdin);
    recherche[strcspn(recherche,"\n")] = 0;

    for(int i = 0; i < n; i++){
        if (strcmp(carnet[i].nom, recherche) == 0){
            for (int j = i; j < n -1; j++) {
                carnet[j] = carnet[j + 1];
                
            }
            n--; 
            printf("Contact supprime avec succes.\n");
            return;
        }
        
        


}
}