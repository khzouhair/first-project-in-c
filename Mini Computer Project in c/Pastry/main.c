#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "Fonctions.h"
int main()
{client=(struct client*)malloc(sizeof(struct client));/*Allocation*/
    int choix;
 DEBUT1:      /* Etiquette :  pour retourner au menu*/
      /*L'affichage du menu*/
    puts("\n\n              ********************PATISSERIE********************");
    puts("\n              *                                                *");
    puts("\n              *   1) Nouveau client.                           *");
    puts("\n              *                                                *");
    puts("\n              *   2) Annuler une commende d'un client.         *");
    puts("\n              *                                                *");
    puts("\n              *   3) Modifier une commende d'un client.        *");
    puts("\n              *                                                *");
    puts("\n              *   4) Afficher la commende d'un client.         *");
    puts("\n              *                                                *");
    puts("\n              *   5) Afficher les commendes de la date choisie.*");
    puts("\n              *                                                *");
    puts("\n              *   6) Calculer La quantite totale d'un gateau.  *");
    puts("\n              *                                                *");
    puts("\n              *   7) Quitter le programme.                     *");
    puts("\n              *                                                *");
    puts("\n              **************************************************");
    do{
    puts("donnez votre choix:  ");
    scanf("%d",&choix);
    if(choix>7||choix<1)
        puts("votre choix doit etre entre 1 et 7.");
     }while(choix>7||choix<1);
        switch(choix){
	case 1 :{
	DEBUT2:
		NouveauClient();
        printf("\n\n                <<<<<<<<<<<<<<<<<<********>>>>>>>>>>>>>>>>>> \n\n");
        printf("                <<<   1) Ajouter une nouvelle commende   >>>\n");
        printf("                <<<   2) Terminer la commende            >>>\n\n");
        printf("                <<<<<<<<<<<<<<<<<<********>>>>>>>>>>>>>>>>>> \n\n");
            do{
				printf("Saisir votre choix : \n");
            	scanf("%d",&choix);
            	if(choix>2||choix<1)
            puts("Votre choix doit etre 1 ou 2.");
            } while(choix<1||choix>2);
            switch(choix){
        case 1:{    goto DEBUT2;/*Etiquette : retourner a la fonction NouveauClient()*/
       break;
			}
		default :{

		    goto DEBUT1;/*Etiquette : retourner au menu principal*/

 		}

		break;
	}
	case 2 :{
 DEBUT3:
          AnnulerUneCommende();
          printf("\n\n                <<<<<<<<<<<<<<<<<<********>>>>>>>>>>>>>>>>>> \n\n");
          printf("                <<<   1) Annuler une autre commende      >>>\n");
          printf("                <<<   2) Revenir au depat                >>>\n\n");
          printf("                <<<<<<<<<<<<<<<<<<********>>>>>>>>>>>>>>>>>> \n\n");

          do{
				printf("Saisir votre choix : \n");
            	scanf("%d",&choix);
            	if(choix>2||choix<1)
            puts("Votre choix doit etre 1 ou 2.");
            } while(choix<1||choix>2);
        if(choix==1)
          goto DEBUT3;/*Etiquette : retourner a la fonction  AnnulerUneCommende()*/
          else
          goto DEBUT1;/*Etiquette : retourner au menu principal*/

		break;
	}
	case 3 :{
 DEBUT4:
          ModifierUneCommende();
          printf("\n\n                <<<<<<<<<<<<<<<<<<********>>>>>>>>>>>>>>>>>> \n\n");
        printf("                <<<   1) Modifier une autre commende     >>>\n");
        printf("                <<<   2) Revenir au depat                >>>\n\n");
        printf("                <<<<<<<<<<<<<<<<<<********>>>>>>>>>>>>>>>>>> \n\n");

          do{
				printf("Saisir votre choix : \n");
            	scanf("%d",&choix);
            	if(choix>2||choix<1)
            puts("Votre choix doit etre 1 ou 2.");
            } while(choix<1||choix>2);
        if(choix==1)
          goto DEBUT4;/*Etiquette : retourner a la fonction  ModifierUneCommende()*/
          else
          goto DEBUT1;/*Etiquette : retourner au menu principal*/
		break;
	}
	case 4 :{
 DEBUT5:
            AfficherUneCommendeDunClient();
            printf("\n\n                <<<<<<<<<<<<<<<<<<********>>>>>>>>>>>>>>>>>> \n\n");
            printf("                <<<   1) Afficher une autre commende     >>>\n");
            printf("                <<<   2) Revenir au depat                >>>\n\n");
            printf("                <<<<<<<<<<<<<<<<<<********>>>>>>>>>>>>>>>>>> \n\n");

          do{
            printf("Saisir votre choix : \n");
            scanf("%d",&choix);
            if(choix>2||choix<1)
            puts("Votre choix doit etre 1 ou 2.");
            } while(choix<1||choix>2);
         if(choix==1)
           goto DEBUT5;/*Etiquette : retourner a la fonction  AfficherUneCommendeDunClient() */
           else
           goto DEBUT1;/*Etiquette : retourner au menu principal*/

		break;
	}
	case 5 :{
	    DEBUT6 :
            AfficherLalisteDeClients();
             printf("\n\n                <<<<<<<<<<<<<<<<<<<<<<<<<<*********>>>>>>>>>>>>>>>>>>>>>>>>>> \n\n");
          printf("                <<<   1) Afficher des autres commendes de la date choisie >>>\n");
          printf("                <<<   2) Revenir au depat                                 >>>\n\n");
          printf("                <<<<<<<<<<<<<<<<<<<<<<<<<<*********>>>>>>>>>>>>>>>>>>>>>>>>>> \n\n");

          do{
				printf("Saisir votre choix : \n");
            	scanf("%d",&choix);
            	if(choix>2||choix<1)
            puts("Votre choix doit etre 1 ou 2.");
            } while(choix<1||choix>2);
        if(choix==1)
          goto DEBUT6; /*Etiquette : retourner a la fonction  AfficherLalisteDeClients()  */
          else
          goto DEBUT1;/*Etiquette : retourner au menu principal*/

		break;
	}
	case 6 :{
	    DEBUT7 :
        AfficherLaQuantiteTotaleDUnGateau();
          printf("\n\n                <<<<<<<<<<<<<<<<<<<<<<<<<<*********>>>>>>>>>>>>>>>>>>>>>>>>>> \n\n");
          printf("                <<<   1)  Calculer la quantite d'un autre gateau          >>>\n");
          printf("                <<<   2) Revenir au depat                                 >>>\n\n");
          printf("                <<<<<<<<<<<<<<<<<<<<<<<<<<*********>>>>>>>>>>>>>>>>>>>>>>>>>> \n\n");

          do{
				printf("Saisir votre choix : \n");
            	scanf("%d",&choix);
            	if(choix>2||choix<1)
            puts("Votre choix doit etre 1 ou 2.");
            } while(choix<1||choix>2);
        if(choix==1)
          goto DEBUT7;/*Etiquette : retourner a la fonction  AfficherLaQuantiteTotaleDUnGateau()  */
          else
          goto DEBUT1;/*Etiquette : retourner au menu principal*/
		break;
	}default :{
          printf("La fin du programme.\n");
		break;
	}


}

}

return 0;

}
