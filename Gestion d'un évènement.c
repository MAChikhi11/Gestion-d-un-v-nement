#include<stdio.h> 
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>
#include<ctype.h>
#include<math.h>
#include <stdbool.h>


// ================ DECLARATION DES STRUCTURES ================ 
 
    // ===================================================


typedef struct{
   char nom[20];
   char prenom[20];
   int id;
 }
travailleur;

typedef struct{
   char nom[20];
   char prenom[20];
   int tour;
   int id;
 }
participant;

typedef struct{ 
   char nom[20];
   char prenom[20];
   int id;
 }
invite;

typedef struct personne_travailleur personne_travailleur;

struct personne_travailleur{
   travailleur travailleur;
   personne_travailleur *suivant;
};

typedef struct personne_participant personne_participant;

struct personne_participant{
   participant participant;
   personne_participant *suivant;
};

typedef struct personne_invite personne_invite;

struct personne_invite{
   invite invite;
   personne_invite *suivant;
};

typedef struct Liste_travailleur Liste_travailleur;

struct Liste_travailleur{
    personne_travailleur *premier;
 };

typedef struct Liste_participant Liste_participant;

struct Liste_participant{
    personne_participant *premier;
 };

typedef struct Liste_invite Liste_invite;

struct Liste_invite{
    personne_invite *premier;
 };


 /*Declaration of Functions*/
 
    // ===================================================
    
    // declaration de fonction Titre 
    
void Title(void);    

    // declaration de fonction welcome et main menu
    
    void WelcomeScreen(void);
void MainMenu(void);
void menuList(void);

    //fonction de saisie
    
    void saisie_nom();
    void saisie_prenom();
    int saisie_tour();
    int saisie_id(Liste_travailleur *listetravailleur,Liste_participant *listeparticipant,Liste_invite *listeinvite);
    int saisie_idd();
    
    //fontion d'insertion
    
    void insertion_t(Liste_travailleur *liste, travailleur travailleur);
    void insertion_p(Liste_participant *liste, participant participant);
    void insertion_i(Liste_invite *liste, invite invite);
    
    //fonction d'affichage
    
    void afficherListe_t(Liste_travailleur *liste);
    void afficherListe_p(Liste_participant *liste);
    void afficherListe_i(Liste_invite *liste);
    
    bool nbr_invite(Liste_invite *liste);//fonction nombre invite
    void supprimer(Liste_travailleur *listetravailleur,Liste_participant *listeparticipant,Liste_invite *listeinvite,int id);//fonction supprime
    
    //fonction fichier
    
    void fichier_t(Liste_travailleur *liste);    
    void fichier_p(Liste_participant *liste);
    void fichier_i(Liste_invite *liste);
    
    //fonction debut fichier
    
    void debut_f_t(Liste_travailleur *liste,int nbr);
    void debut_f_p(Liste_participant *liste,int nbr);
    void debut_f_i(Liste_invite *liste,int nbr);
    
//fonction nombre de t-p-i

    int nbr_t();
    int nbr_p();
    int nbr_i();
    
    
     // ===================================================
     

// definir les fonction

/* ************************************************* Welcome Screen ********************************************* */


//function for welcome screen


void WelcomeScreen(void) {

printf("\n\n\n\n\t\t\t\t#########################################");
printf("\n\t\t\t\t#\t\t EVENEMENT");
printf("\n\t\t\t\t#\t        MANAGEMENT     ");
printf("\n\t\t\t\t#########################################");
printf("\n\n\n\n\n Press any key to continue......\n");
getch();
system("cls");

}


/* ************************************************* Title Screen ********************************************* */


//function for title screen


void Title(void){


 
printf("\n\n\t\t----------------------------------------------------------------------------------");
printf("\n\t\t\t\t       EvenementManagement       ");
printf("\n\t\t----------------------------------------------------------------------------------\n");
}


void saisie_nom(){
    printf("\n\t\tEntrez le Nom :\n\t\t");
    
}

void saisie_prenom(){
    printf("\n\t\tEntrez le prenom :\n\t\t");
}

int saisie_tour(){    
    
   int tour;
   printf("\n\t\tEnter the position (TOUR) :\n\t\t");
   scanf("%d",&tour);

   return tour;
}
int saisie_idd(){
    
   int id;
   do{
       printf("\n\t\tEntrez le code\n\t\t :");
       scanf("%d",&id);
       
   }while(id < 10000 || id >= 39999);
   
   return id;
}
int saisie_id(Liste_travailleur *listetravailleur,Liste_participant *listeparticipant,Liste_invite *listeinvite){


     
           printf(" \n\t\t\t\t\t\t******ADDING A PERSON****** \n");
           printf("   \t\t\t     ============================================= \n");
printf("\n\t\t Tapez 1 si vous voulez generer un code aleatoire \n");
printf("\n\t\t Tapez 2 si vous voulez ajoutez un code   \n"); 
printf("\n\t\tEntrez votre choix :  \n");

                  int id;
          bool a = false;
                              int choice;
   
                              scanf("%d",&choice);
       
                              switch(choice){
  
       
           case 1:
            
                  do{
       bool error = false;
       srand(time(NULL));   
                                                   id = rand();
       personne_travailleur *actuelt = listetravailleur->premier;
       personne_participant *actuelp = listeparticipant->premier;
       personne_invite *actueli = listeinvite->premier;
       if(actuelt == NULL && actuelp == NULL && actueli == NULL){
               
       }else{
           do{
               
               if(actuelt != NULL){
                   if(actuelt->travailleur.id == id){
                       error = true;
                   }
               }
               
               if(actuelp != NULL){
                   if(actuelp->participant.id == id){
                       error = true;
                   }
               }
               
               if(actueli != NULL){
                   if(actueli->invite.id == id){
                       error = true;
                   }
               }
               
               if(actuelt != NULL){
                       actuelt = actuelt->suivant;
               }
               
               if(actuelp != NULL){
                       actuelp = actuelp->suivant;
               }

               if(actueli != NULL){
                       actueli = actueli->suivant;
               }

           }while (actuelt != NULL || actuelp != NULL || actueli != NULL);
       }
       if(error == true){
           a = true;
       }else{
           a = false;
       }
   }while(id < 10000 || id > 39999 || a == true);
   
   return id;
  
   
               break;
       
           case 2:
            
                  do{
       bool error = false;
       printf("\n\t\tEntrez le code :\n\t\t");
       scanf("%d",&id);        
       personne_travailleur *actuelt = listetravailleur->premier;
       personne_participant *actuelp = listeparticipant->premier;
       personne_invite *actueli = listeinvite->premier;
       if(actuelt == NULL && actuelp == NULL && actueli == NULL){
               
       }else{
           do{
               
               if(actuelt != NULL){
                   if(actuelt->travailleur.id == id){
                       error = true;
                   }
               }
               
               if(actuelp != NULL){
                   if(actuelp->participant.id == id){
                       error = true;
                   }
               }
               
               if(actueli != NULL){
                   if(actueli->invite.id == id){
                       error = true;
                   }
               }
               
               if(actuelt != NULL){
                       actuelt = actuelt->suivant;
               }
               
               if(actuelp != NULL){
                       actuelp = actuelp->suivant;
               }

               if(actueli != NULL){
                       actueli = actueli->suivant;
               }

           }while (actuelt != NULL || actuelp != NULL || actueli != NULL);
       }
       if(error == true){
           a = true;
       }else{
           a = false;
       }
   }while(id < 10000 || id > 39999 || a == true);
   
   return id;
  
               
               break;
               
           
                
           default:
 printf("\n\t\tInvalid Choice! System Exit\n");
 getch();
 MainMenu();
    
        }}


Liste_travailleur *initialisation_t(){

   Liste_travailleur *liste = malloc(sizeof(*liste));

   if (liste == NULL )
   {
       exit(EXIT_FAILURE);
   }
   
   liste->premier = NULL;

   return liste;
  }

Liste_participant *initialisation_p() {

   Liste_participant *liste = malloc(sizeof(*liste));

   if (liste == NULL)
   {
       exit(EXIT_FAILURE);
   }

   liste->premier = NULL;
   return liste;
}

Liste_invite *initialisation_i(){

   Liste_invite *liste = malloc(sizeof(*liste));

   if (liste == NULL)
   {
       exit(EXIT_FAILURE);
   }

   liste->premier = NULL;

   return liste;
  }

void insertion_t(Liste_travailleur *liste, travailleur travailleur){

   personne_travailleur *nouveau = malloc(sizeof(*nouveau));
   if (liste == NULL || nouveau == NULL)
   {
       exit(EXIT_FAILURE);
   }
   nouveau->travailleur = travailleur;

   nouveau->suivant = liste->premier;
   liste->premier = nouveau;
}

void insertion_p(Liste_participant *liste, participant participant){

   personne_participant *nouveau = malloc(sizeof(*nouveau));
   if (liste == NULL || nouveau == NULL)
   {
       exit(EXIT_FAILURE);
   }
   nouveau->participant = participant;

   nouveau->suivant = liste->premier;
   liste->premier = nouveau;
}

void insertion_i(Liste_invite *liste, invite invite){

   personne_invite *nouveau = malloc(sizeof(*nouveau));
   if (liste == NULL || nouveau == NULL)
   {
       exit(EXIT_FAILURE);
   }
   nouveau-> invite = invite;

   nouveau-> suivant = liste->premier;
   
   liste-> premier = nouveau;
  }

void afficherListe_t(Liste_travailleur *liste){

   if (liste == NULL)
   {
       
       exit(EXIT_FAILURE);
   }

   personne_travailleur *actuel = liste->premier;
   
   while (actuel != NULL)
   {
    printf("\n\t________________________________________");
       printf("\n\t| %-12s | %-12s | 00%-5d |", actuel->travailleur.nom,actuel->travailleur.prenom,actuel->travailleur.id);
      
       actuel = actuel->suivant;
   }
   printf("\n\t\t.\n\t\t");
   getch();
}

void afficherListe_p(Liste_participant *liste){

   if (liste == NULL)
   {
       exit(EXIT_FAILURE);
   }

   personne_participant *actuel = liste->premier;

   while (actuel != NULL)
   {
    printf("\n\t________________________________________________");
       printf("\n\t| %-12s | %-12s | 00%-5d | %-5d |", actuel->participant.nom,actuel->participant.prenom,actuel->participant.id,actuel->participant.tour);
       
       actuel = actuel->suivant;
   }
   printf("\n\t\t.\n\t\t");
   getch();
}

void afficherListe_i(Liste_invite *liste){

   if (liste == NULL)
   {
       exit(EXIT_FAILURE);
   }

   personne_invite *actuel = liste->premier;

   while (actuel != NULL)
   {
    printf("\n\t________________________________________");
       printf("\n\t| %-12s | %-12s | 00%-5d |", actuel->invite.nom,actuel->invite.prenom,actuel->invite.id);
       
       actuel = actuel->suivant;
   }
   printf("\n\t\t.\n\t\t");
   getch();
}

bool nbr_invite(Liste_invite *liste){

   int i = 0;
   personne_invite *actuel = liste->premier;

   while (actuel != NULL)
   {
       i += 1;
       actuel = actuel->suivant;
   }
   if(i < 2){
       return false;
   }else{
       return true;
   }
  }

void supprimer(Liste_travailleur *listetravailleur,Liste_participant *listeparticipant,Liste_invite *listeinvite,int id){

   int uid = id;
   do{
       uid = uid/10;     //       uid=/10
   }while(uid > 3);
   bool found;
   switch (uid)
   {
   case 1 :;
       personne_travailleur *actuelt = listetravailleur->premier;       
       if(actuelt-> travailleur.id == id){
           personne_travailleur *aSupprimer = listetravailleur->premier;
           listetravailleur->premier = listetravailleur->premier->suivant;
           free(aSupprimer);
       }else{
           personne_travailleur *suivant = actuelt->suivant;
           while(suivant != NULL && found == false){
               if(id == suivant->travailleur.id){
                   found = true;
                   personne_travailleur *aSupprimer = suivant;
                   actuelt->suivant = actuelt->suivant->suivant;
                   free(aSupprimer);
               }else{
                   found = false;
                   suivant = suivant->suivant;
               }
           }   
       }
       break;
   case 2 :;
       personne_participant *actuelp = listeparticipant->premier;       
       if(actuelp->participant.id == id){
           personne_participant *aSupprimer = listeparticipant->premier;
           listeparticipant->premier = listeparticipant->premier->suivant;
           free(aSupprimer);
       }else{
           personne_participant *suivant = actuelp->suivant;
           while(suivant != NULL && found == false){
               if(id == suivant->participant.id){
                   found = true;
                   personne_participant *aSupprimer = suivant;
                   actuelp->suivant = actuelp->suivant->suivant;
                   free(aSupprimer);
               }else{
                   found = false;
                   suivant = suivant->suivant;
               }
           }
       }
       break;
   case 3 :;
       personne_invite *actueli = listeinvite->premier;       
       if(actueli->invite.id == id){
           personne_invite *aSupprimer = listeinvite->premier;
           listeinvite->premier = listeinvite->premier->suivant;
           free(aSupprimer);
       }else{
           personne_invite *suivant = actueli->suivant;
           while(suivant != NULL && found == false){
               if(id == suivant->invite.id){
                   found = true;
                   personne_invite *aSupprimer = suivant;
                   actueli->suivant = actueli->suivant->suivant;
                   free(aSupprimer);
               }else{
                   found = false;
                   suivant = suivant->suivant;
               }
           }
       }
       break;
   }
 }

void fichier_t(Liste_travailleur *liste){

   FILE* fichierr = NULL;
   fichierr = fopen("travailleurs.txt", "w");

   fclose(fichierr);
   FILE* fichier = NULL;
   fichier = fopen("travailleurs.txt", "a");

   personne_travailleur *actuel = liste->premier;
   
   while (actuel != NULL)
   {
       fprintf(fichier, "%s %s 00%d\n", actuel->travailleur.nom,actuel->travailleur.prenom,actuel->travailleur.id);
       actuel = actuel->suivant;
   }
   fprintf(fichier, "NULL");
   fclose(fichier);

 }

void fichier_p(Liste_participant *liste){

   FILE* fichierr = NULL;
   fichierr = fopen("participants.txt", "w");
 
   fclose(fichierr);
   FILE* fichier = NULL;
   fichier = fopen("participants.txt", "a");

   personne_participant *actuel = liste->premier;
   
   while (actuel != NULL)
   {
       fprintf(fichier, "%s %s 00%d %d\n", actuel->participant.nom,actuel->participant.prenom,actuel->participant.id,actuel->participant.tour);
       actuel = actuel->suivant;
   }
   fprintf(fichier, "NULL");
   fclose(fichier);
 }

void fichier_i(Liste_invite *liste){

   FILE* fichierr = NULL;
   fichierr = fopen("invites.txt", "w");

   fclose(fichierr);
   FILE* fichier = NULL;
   fichier = fopen("invites.txt", "a");

   personne_invite *actuel = liste->premier;
   
   while (actuel != NULL)
   {
       fprintf(fichier, "%s %s 00%d\n", actuel->invite.nom,actuel->invite.prenom,actuel->invite.id);
       actuel = actuel->suivant;
   }
   fprintf(fichier, "NULL");
   fclose(fichier);
 }

void debut_f_t(Liste_travailleur *liste,int nbr){

   travailleur t;
   char nom[20];
   char prenom[20];
   char str[20];
   char test[20];
   int id;
   int i,j;

   FILE* fichier = NULL;
   fichier = fopen("travailleurs.txt", "r");
   
   if (fichier != NULL) {
       fseek (fichier, 0, SEEK_END);
       long size = ftell(fichier);
       fseek (fichier, 0, SEEK_SET);
       if (0 != size) {
           for(i=0;i<nbr;i++){
               long position1 = ftell(fichier);
               fscanf(fichier,"%s ",&test);
               long position2 = ftell(fichier);
               fseek (fichier, position1, 0);
               if(test != "NULL"){
                   fscanf(fichier, "%s %s %s\n", &nom, &prenom, &str);
                   id = atoi(str);
                   for(j=0;j<20;j++){
                       t.nom[j] = nom[j];
                   }
                   for(j=0;j<20;j++){
                       t.prenom[j] = prenom[j];
                   }
                   t.id = id;
                   insertion_t(liste,t);
               }
           }
       }
   }
   fclose(fichier);
 }

void debut_f_p(Liste_participant *liste,int nbr){

   participant participant;
   char nom[20];
   char prenom[20];
   char str[20];
   char strr[3];
   char test[20];
   int id,tour;
   int i,j;

   FILE* fichier = NULL;
   fichier = fopen("participants.txt", "r");
   
   if (fichier != NULL) {
       fseek (fichier, 0, SEEK_END);
       long size = ftell(fichier);
       fseek (fichier, 0, SEEK_SET);
       if (0 != size) {
               for(i=0;i<nbr;i++){
               long position1 = ftell(fichier);
               fscanf(fichier,"%s ",&test);
               long position2 = ftell(fichier);
               fseek (fichier, position1, 0);
               if(test != "NULL"){
                   fscanf(fichier, "%s %s %s %s\n", &nom, &prenom, &str,&strr);
                   id = atoi(str);
                   tour = atoi(strr);
                   for(j=0;j<20;j++){
                       participant.nom[j] = nom[j];
                   }
                   for(j=0;j<20;j++){
                       participant.prenom[j] = prenom[j];
                   }
                   participant.id = id;
                   participant.tour = tour;
                   insertion_p(liste,participant);
               }
           }
       }
   }
   fclose(fichier);
 }

void debut_f_i(Liste_invite *liste,int nbr){

   invite i;
   char nom[20];
   char prenom[20];
   char str[20];
   char test[20];
   int id;
   int m,j;

   FILE* fichier = NULL;
   fichier = fopen("invites.txt", "r");
   
   if (fichier != NULL) {
       fseek (fichier, 0, SEEK_END);
       long size = ftell(fichier);
       fseek (fichier, 0, SEEK_SET);
       if (0 != size) {
           for(m=0;m<nbr;m++){
               long position1 = ftell(fichier);
               fscanf(fichier,"%s ",&test);
               long position2 = ftell(fichier);
               fseek (fichier, position1, 0);
               if(test != "NULL"){
                   fscanf(fichier, "%s %s %s\n", &nom, &prenom, &str);
                   id = atoi(str);
                   for(j=0;j<20;j++){
                       i.nom[j] = nom[j];
                   }
                   for(j=0;j<20;j++){
                       i.prenom[j] = prenom[j];
                   }
                   i.id = id;
                   insertion_i(liste,i);
               }
           }
       }
   }
   fclose(fichier);
 }

int nbr_t(){

   FILE* fichier = NULL;
   int caractereActuel = 0;
   int nbr = 0;
   fichier = fopen("travailleurs.txt", "r");

   if (fichier != NULL)
   {
       
       do
       {
           caractereActuel = fgetc(fichier); 
           if(caractereActuel == '\n'){
               nbr += 1;
           } 
       } while (caractereActuel != EOF); 

       fclose(fichier);
   }
   return nbr;
  }

int nbr_p(){

   FILE* fichier = NULL;
   int caractereActuel = 0;
   int nbr = 0;
   fichier = fopen("participants.txt", "r");

   if (fichier != NULL)
   {
       
       do
       {
           caractereActuel = fgetc(fichier); 
           if(caractereActuel == '\n'){
               nbr += 1;
           } 
       } while (caractereActuel != EOF); 

       fclose(fichier);
   }
   return nbr;
  }

int nbr_i(){

   FILE* fichier = NULL;
   int caractereActuel = 0;
   int nbr = 0;
   fichier = fopen("invites.txt", "r");

   if (fichier != NULL)
   {
       
       do
       {
           caractereActuel = fgetc(fichier); 
           if(caractereActuel == '\n'){
               nbr += 1;
           } 
       } while (caractereActuel != EOF); 

       fclose(fichier);
   }
   return nbr;
}


// ===================================================

 void MainMenu(){
   int choix;
   
   Liste_travailleur *liste_travailleur = initialisation_t();
   Liste_participant *liste_participant = initialisation_p();
   Liste_invite *liste_invite = initialisation_i();
   
   debut_f_t(liste_travailleur,nbr_t());
   debut_f_p(liste_participant,nbr_p());
   debut_f_i(liste_invite,nbr_i());
   
   do{
       
       printf(" \n\t\t\t\t\t\t******MENU****** \n");
printf("   \t\t\t       ============================================= \n");
printf("\n\t\t Tapez 1 pour ajouter une personne\n");
printf("\n\t\t Tapez 2 pour afficher les listes\n");
printf("\n\t\t tapez 3 pour supprimer une personne\n");
printf("\n\t\t Tapez 4 pour fermer le programme\n");
printf(" \n \t\t\t       ============================================= \n\n");
printf("\n\t\tchoisissez de 1 a 4 :");
printf("\n\t");
       scanf("%d",&choix);
       switch(choix){
        
           case 1 :;
           system("cls");
           Title();
               int id = saisie_id(liste_travailleur,liste_participant,liste_invite);
               int uid = id;
               do{
                   uid /= 10;
               }while(uid > 3);
               switch (uid){
               case 1 :;                
               system("cls");
Title();
                   travailleur new;
                   saisie_nom();
                   scanf("%s",new.nom);
                   new.id = id;
                   saisie_prenom();
                   scanf("%s",new.prenom);
                   insertion_t(liste_travailleur, new);
                   break;
               case 2 :;
               system("cls");
               Title();
                   participant new1;
                   new1.id = id;
                   saisie_nom();
                   scanf("%s",new1.nom);
                   saisie_prenom();
                   scanf("%s",new1.prenom);
                   new1.tour = saisie_tour();
                   insertion_p(liste_participant, new1);
                   break;
               case 3 :
                system("cls");Title();
                   if(nbr_invite(liste_invite) == true){
                       printf("Its currently full :( :(\n");
                       break;
                   }else{
                    
                       invite new2;
                       new2.id = id;
                       saisie_nom();
                       scanf("%s",new2.nom);
                       saisie_prenom();
                       scanf("%s",new2.prenom);
                       insertion_i(liste_invite, new2);
                       break;      
                   }
                   
               }break;
           case 2 :;
           system("cls");
           Title();
           int li;
           do{
            
            
            
               
               printf(" \n\t\t\t\t\t\t******MENU DES LISTES****** \n");
printf("   \t\t\t       ============================================= \n");
printf("\n\t\t Entrez 1 pour afficher la liste travailleurs\n");
printf("\n\t\t Entrez 2 pour afficher la liste des participants\n");
printf("\n\t\t Entrez 3 pour afficher la liste des invites\n");
printf("\n\t\t Entrez 4 pour afficher les listes disponible\n");
printf("\n\t\t Entrez 5 pour sauvegarder et revenir au menu\n");
printf(" \n \t\t\t       ============================================= \n\n");
printf("\n\t\tEntrez votre choix  [1-5]:");
printf("\n\t");
               scanf("%d",&li);
               switch(li){
                
                   case 1 : 
                   system("cls");
                   Title();
                       printf(" \n\t\t\t\t\t\t******LISTES DES TRAVAILLEURS****** \n");
       printf("\n\t________________________________________");
       printf("\n\t| Nom          | Prenom       | Code    |");
       
                       afficherListe_t(liste_travailleur);
                       system("cls");
                       break;
                   case 2 : 
                   system("cls");
                   Title();
                    printf(" \n\t\t\t\t\t\t******LISTE DES PARTICIPANTS****** \n");
    printf("\n\t________________________________________________");
       printf("\n\t| Nom          | Prenom       | Code    | Tour  |");
       
                       afficherListe_p(liste_participant);
                       system("cls");
                       break;
                   case 4 : 
                   system("cls");
                   Title();
                    printf("\n\t");
                    printf(" \n\t\t\t\t\t\t******LISTE DES TRAVAILLEURS****** \n");
       printf("\n\t________________________________________");
       printf("\n\t| Nom          | Prenom       | Code    |");
       
                       afficherListe_t(liste_travailleur);
                       printf("\n\t");
                       printf(" \n\t\t\t\t\t\t******LISTE DES PARTICIPANTS****** \n");
    printf("\n\t________________________________________________");
       printf("\n\t| Nom          | Prenom       | Code    | Tour  |");
       
                       afficherListe_p(liste_participant);
                       printf("\n\t");
                       printf(" \n\t\t\t\t\t\t******LISTE DES INVITÉS****** \n");
    printf("\n\t________________________________________");
       printf("\n\t| Nom          | Prenom       | Code    |");
       
                       afficherListe_i(liste_invite);
                       printf("\n\t");      
                       system("cls");
                       break;    
                   case 3 : 
                   system("cls");
                   Title();
                    printf(" \n\t\t\t\t\t\t******LISTES DES INVITÉS****** \n");
    printf("\n\t________________________________________");
       printf("\n\t| Nom          | Prenom       | Code    |");
       
                       afficherListe_i(liste_invite);
                       system("cls");
                       break;
                   case 5 : 
                      system("cls");                       
                       MainMenu();
                       break;    
               }}
          while(li != 5);
         

  
           case 3 :;
           system("cls");
           Title();
               int idd = saisie_idd();
               supprimer(liste_travailleur,liste_participant,liste_invite,idd);
               
               break;
       }
   }
while(choix != 4);
system("cls");

system("COLOR bf");

Title();

printf("\n\n\n\n\n\t\t\tMAERCI POUR VOTRE VISITE ;)");

getch();

   fichier_t(liste_travailleur);
   fichier_p(liste_participant);
   fichier_i(liste_invite);
   
}

void main(void){ 
    
   time_t t = time(NULL);
   struct tm tm = *localtime(&t);
   printf("\n\n\n\n\n\t\t\t\tDate and time: %d-%02d-%02d %02d:%02d:%02d\n",tm.tm_mday, tm.tm_mon + 1,tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
   system("COLOR BF");
   WelcomeScreen();
Title();
MainMenu();
   }
   
