
#include<string.h>

 struct commende {
	char gateau[5];
	int quantite;
};
struct date{
    int jour,mois,annee;
};
struct info{
	char NomPrenom[50], adresse[100];
	int num;
};
struct client {
    struct date DateDeReservation,DateDeSoumission;
	struct commende commende[5];
	struct info infocl;

};
struct client *client;

FILE* FichierClient;

void NouveauClient(void);
void AnnulerUneCommende(void);
void ModifierUneCommende(void);
void AfficherLalisteDeClients(void);
void AfficherUneCommendeDunClient(void);
void LaCommendation(void);
void AfficherLaQuantiteTotaleDUnGateau(void);

void NouveauClient(){
int numcl;
int tr=0;
FichierClient=fopen("ListeDeClient.text","at+");
if(FichierClient==NULL){
    printf("Impossible d'ouvrir le fichier \n");
    exit(1);
}
printf("Donnez le num de client:\n");
scanf("%d",&numcl);
while(!feof(FichierClient)){
    fscanf(FichierClient,"%s   %d   %s   %s   %d   %d/%d/%d\n",client->infocl.NomPrenom,
           &client->infocl.num,client->infocl.adresse,
           client->commende->gateau,&client->commende->quantite,
           &client->DateDeSoumission.jour,&client->DateDeSoumission.mois,&client->DateDeSoumission.annee);
   if(client->infocl.num==numcl){
    tr=1;
    break;
   }
}
if(tr==1){
    printf("Client existe deja.\n");
}
else{
        client->infocl.num=numcl;
    /*printf("Donnez le num :\n");
    scanf("%d",&client->infocl.num);*/
    printf("Donnez le nom et le prenom (sous forme de : NomPrenom) :\n");
    scanf("%s",client->infocl.NomPrenom);
    printf("Donnez l'adresse (remplacer les espaces par les tirees):\n");
    scanf("%s",client->infocl.adresse);
    printf("Donnez la date de soumission :\n");
    scanf("%d %d %d",&client->DateDeSoumission.jour,&client->DateDeSoumission.mois,&client->DateDeSoumission.annee);
    LaCommendation();
    fprintf(FichierClient,"%s   %d   %s   %s   %d   %d/%d/%d\n",client->infocl.NomPrenom,
            client->infocl.num,client->infocl.adresse,
           client->commende->gateau,client->commende->quantite,
           client->DateDeSoumission.jour,client->DateDeSoumission.mois,client->DateDeSoumission.annee);
    }
fclose(FichierClient);

}

void AfficherUneCommendeDunClient(){
int numcl;/*numéro de téléphone de client qu'on veut afficher*/
int tr=0;/* tr prend la valeur 0 ou 1*/
FichierClient=fopen("ListeDeClient.text","rt");
if(FichierClient==NULL){
    printf("Impossible d'ouvrir le fichier \n");
    exit(1);
}
printf("Donnez le num de client:\n");
scanf("%d",&numcl);
while(!feof(FichierClient))/* Pour assurer qu’on n’a pas atteindre la fin du fichier */
{
    fscanf(FichierClient,"%s   %d   %s   %s   %d   %d/%d/%d",client->infocl.NomPrenom,&client->infocl.num,
           client->infocl.adresse,
           client->commende->gateau,&client->commende->quantite,
           &client->DateDeSoumission.jour,&client->DateDeSoumission.mois,&client->DateDeSoumission.annee);
   if(client->infocl.num==numcl){
    tr=1;
        /* l'affichage les  champs de la structure client */
    printf("Le nom et le prenom du client : %s \n",client->infocl.NomPrenom);
    printf("Le numero de telephone du client : %d \n", client->infocl.num);
    printf("L'adresse  du client : %s \n", client->infocl.adresse);
    printf("La commende du client : %d de %s \n",client->commende->quantite,client->commende->gateau);
    printf("La date de soumission de la commende du client :  %d/%d/%d \n",client->DateDeSoumission.jour,
           client->DateDeSoumission.mois,
           client->DateDeSoumission.annee);break;
   }}
if(tr==0)
    printf("Le client n'exite pas.\n");
fclose(FichierClient);
}

void ModifierUneCommende(){
    int numcl,tr=0;/*numéro de téléphone de client qu'on veut afficher  et  tr prend la valeur 0 ou 1*/
    FILE* temp;
    FichierClient=fopen("ListeDeClient.text","rt");
if(FichierClient==NULL){
    printf("Impossible d'ouvrir le fichier \n");
    exit(1);
}
temp=fopen("temp.text","wt");
if(FichierClient==NULL){
    printf("Impossible d'ouvrir le fichier \n");
    exit(1);
}printf("Donnez le num de client:\n");
scanf("%d",&numcl);
    while(!feof(FichierClient)){

                fscanf(FichierClient,"%s   %d   %s   %s   %d   %d/%d/%d",client->infocl.NomPrenom,
                       &client->infocl.num,client->infocl.adresse,
           client->commende->gateau,&client->commende->quantite,
           &client->DateDeSoumission.jour,&client->DateDeSoumission.mois,&client->DateDeSoumission.annee);
          if(client->infocl.num==numcl){
            tr=1;
            LaCommendation();/*break;*/
          }
          fprintf(temp,"%s   %d   %s   %s   %d   %d/%d/%d\n",client->infocl.NomPrenom,
                  client->infocl.num,client->infocl.adresse,
           client->commende->gateau,client->commende->quantite,
           client->DateDeSoumission.jour,client->DateDeSoumission.mois,client->DateDeSoumission.annee);
           },: j ;;
           fclose(FichierClient);fclose(temp);
           remove("ListeDeClient.text");/*supprimer FichierClient*/
           rename("temp.text","ListeDeClient.text");/*renomer le fichier temp*/
           if(tr==0)
            printf("Le client n'existe pas.\n");
           else
            printf("La commende est modifiee.\n");
}

void AnnulerUneCommende(){
    int numcl,tr=0;/*numéro de téléphone de client qu'on veut afficher  et  tr prend la valeur 0 ou 1*/
    FILE* temp;
    FichierClient=fopen("ListeDeClient.text","rt");
 if(FichierClient==NULL){
    printf("Impossible d'ouvrir le fichier \n");
    exit(1);
}
     temp=fopen("temp.text","wt");
if(FichierClient==NULL){
    printf("Impossible d'ouvrir le fichier \n");
    exit(1);
}
   printf("Donnez le num de client annulee:\n");
 scanf("%d",&numcl);
     while(!feof(FichierClient))
     {
        fscanf(FichierClient,"%s   %d   %s   %s   %d   %d/%d/%d",client->infocl.NomPrenom,&client->infocl.num,
               client->infocl.adresse,
           client->commende->gateau,&client->commende->quantite,
           &client->DateDeSoumission.jour,&client->DateDeSoumission.mois,&client->DateDeSoumission.annee);
          if(client->infocl.num!=numcl){
          fprintf(temp,"%s   %d   %s   %s   %d   %d/%d/%d\n",client->infocl.NomPrenom,client->infocl.num,
                  client->infocl.adresse,
           client->commende->gateau,client->commende->quantite,
           client->DateDeSoumission.jour,client->DateDeSoumission.mois,client->DateDeSoumission.annee);
           }
          else
            tr=1;
          }
           fclose(FichierClient);fclose(temp);
           remove("ListeDeClient.text");
           rename("temp.text","ListeDeClient.text");
           if(tr==0)
            printf("La commende n'existe pas.\n");
           else
            printf("La commende est annulee.\n");

}

void AfficherLalisteDeClients(){
int moisl,anneecl,tr;/*numéro de téléphone de client qu'on veut afficher  et  tr prend la valeur 0 ou 1*/
    FichierClient=fopen("ListeDeClient.text","rt");
if(FichierClient==NULL){
    printf("Impossible d'ouvrir le fichier \n");
    exit(1);
}
printf("Donnez la date de soumission :\n");
printf("Le mois : \n");
scanf("%d",&moisl);
printf("L'annee :\n");
scanf("%d",&anneecl);
while(!feof(FichierClient)){
    fscanf(FichierClient,"%s   %d   %s   %s   %d   %d/%d/%d",client->infocl.NomPrenom,&client->infocl.num,
           client->infocl.adresse,
           client->commende->gateau,&client->commende->quantite,
           &client->DateDeSoumission.jour,&client->DateDeSoumission.mois,&client->DateDeSoumission.annee);

     if(client->DateDeSoumission.mois==moisl && client->DateDeSoumission.annee==anneecl)
        {/*L'affichage des champs de la structure client*/
    tr=1;
    puts("\n              **************************************************");
    printf("Le nom et le prenom du client : %s \n",client->infocl.NomPrenom);
    printf("Le numero de telephone du client : %d \n", client->infocl.num);
    printf("L'adresse  du client : %s \n", client->infocl.adresse);
    printf("La commende du client : %d de %s \n",client->commende->quantite,client->commende->gateau);
    printf("La date de soumission de la commende du client :  %d/%d/%d \n",client->DateDeSoumission.jour,
           client->DateDeSoumission.mois,
           client->DateDeSoumission.annee);
    puts("\n              **************************************************");
   }
}
if(tr==0)
    printf("Le client n'existe pas\n");


fclose(FichierClient);


}

void AfficherLaQuantiteTotaleDUnGateau(){
int tr=0,quantite=0;
char gateaucl[5];
    FichierClient=fopen("ListeDeClient.text","rt");
if(FichierClient==NULL){
    printf("Impossible d'ouvrir le fichier \n");
    exit(1);
}

    printf("Saisir le nom du gateau : \n");
    scanf("%s",gateaucl);

while(!feof(FichierClient)){
    fscanf(FichierClient,"%s   %d   %s   %s   %d   %d/%d/%d",client->infocl.NomPrenom,&client->infocl.num,
           client->infocl.adresse,
           client->commende->gateau,&client->commende->quantite,
           &client->DateDeSoumission.jour,&client->DateDeSoumission.mois,&client->DateDeSoumission.annee);
           if(strcmp(client->commende->gateau,gateaucl)==0){
    tr=1;
     quantite = quantite + client->commende->quantite;
   }}
if(tr==0)
    printf("0000000");
else
    printf("la quantite totale est : %d",quantite);

fclose(FichierClient);
 v v
}

void LaCommendation(void){
int nbrcom,i;
            puts("\n\n    ================================= MENU ================================   \n ");
            printf("    =                                 = ");        printf(" =                                =\n  ");
        	printf("  =   * Kaeb Alghazal : 120DH/kg    =  ");      	printf("=    *  Albriwate : 60DH/kg      =\n  ");
            printf("  =                                 =  ");       	printf("=                                =\n  ");
            printf("  =   *  Alghariba    : 100DH/kg    =  ");       	printf("=    *   Chabakia : 50DH/kg      =\n  ");
            printf("  =                                 =  ");        printf("=                                =\n  ");
            printf("  =   *    Faqas      : 70DH/kg     =  ");        printf("=    *   Cookies  : 30DH/kg      =\n  ");
            printf("  =                                 =  ");        printf("=                                =\n\n  ");
            puts("  =======================================================================  ");
            /*system("cls");*/
            do{
            printf("Le nombre de commende : \n"); /*la taille de tableau commende*/
        	scanf("%d",&nbrcom);
            if(nbrcom>6||nbrcom<1)
        puts("votre choix doit etre entre 1 et 6.");
     }while(nbrcom>6||nbrcom<1);

           for(i=0;i<nbrcom;i++) {    /*boucle pour remplir le tableau commende[nbrcom] de type commende(structure)*/
            	printf("Pouvez-vous entrer votre commende ici :  ");
            	scanf("%s",client->commende[i].gateau);
            	printf("\nCombien de kg voulez-vous ? \n");
            	scanf("%d",&client->commende[i].quantite);

}

}


