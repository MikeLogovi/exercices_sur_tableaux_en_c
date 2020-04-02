#include "bibliotheques.h"
#include "prototypes.h"
int main(){
    //Déclarations
    int taille,taille1,taille2,i,nbElemAChercher;
    int somme,maxi,mini,pos,val;
    do{
        printf("Veuillez saisir la taille(>=1) du tableau\n");
        scanf("%d",&taille);
    }while(taille<1);
    int* t=malloc(sizeof(int)*(taille));//tableau dynamique
    //Saisir les elements du tableau
    for(i=0;i<taille;i++){
        printf("Saisir la valeur numero %d du tableau \n",i+1);
        scanf("%d",&t[i]);
    }
   
    //Somme des elements
    somme=sommeElements(t,taille);
    printf("Somme=%d\n",somme);
    //Maximum ou minimum
    maxi=maxOuMin(t,taille,'m');
    mini=maxOuMin(t,taille,'n');
    printf("Maxi=%d\n",maxi);
    printf("Mini=%d\n",mini);
    //Recherche d'une donnée*/
    printf("Veuillez saisir le nombre d'element a chercher\n");
    scanf("%d",&nbElemAChercher);
    int valeursAChercher[nbElemAChercher];
    for(i=0;i<nbElemAChercher;i++){
        printf("Veuillez saisir la valeur a chercher numero %d\n",i+1);
        scanf("%d",&valeursAChercher[i]);
    }
    chercherPlusieursValeurs(t,taille,valeursAChercher,nbElemAChercher);

    //Obtenir la liste des nombres premiers
    //1 ne sera pas considere comme nombre premier
    int* res;
    res=obtenirNombresPremiers(t,taille);
    int nbPremier=res[0];
    printf("Les nombres premiers sont\n");
    for(i=1;i<=nbPremier;i++)
        printf("%d ",res[i]);
    printf("\n");
    //Trouver la liste des nombres palindromes
    
    res=obtenirNombresPalindrome(t,taille);
    int nbPalindrome=res[0];
    printf("Les nombres palindromes sont\n");
    for(i=1;i<=nbPalindrome;i++)
        printf("%d ",res[i]);
    printf("\n");

    //Mise à jour d'une donnée
    printf("Veuillez donner la donnee et la poisiton de mise a jour\n");
    scanf("%d%d",&pos,&val);
    mettre_a_jour(t,taille,pos,val);
    affichage(t,taille);
    //Insertion de donnee avec doublons
    for(i=0;i<3;i++){
        printf("Veuillez donner la position et la valeur a inserer \n");
        scanf("%d%d",&pos,&val);
        //Insertion d'une donnée
        taille=inserer(t,taille,val,pos);
        affichage(t,taille);
    }
     //Insertion de donnee sans doublons
    for(i=0;i<3;i++){
        printf("Veuillez donner la position et la valeur a inserer \n");
        scanf("%d%d",&pos,&val);
        //Insertion d'une donnée
        taille=insererSansDoublon(t,taille,val,pos);
        affichage(t,taille);
    }
    
    //Suppression d'une donnée sans supprimer les doublons
    for(i=0;i<3;i++){
        printf("Veuillez donner  la valeur a supprimer \n");
        scanf("%d",&val);
        taille=supprimer(t,taille,val);
        affichage(t,taille);
    }
    //Suppression d'une donnée en  supprimant les doublons
    for(i=0;i<3;i++){
        printf("Veuillez donner  la valeur a supprimer \n");
        scanf("%d",&val);
        taille=supprimerTousLesDoublons(t,taille,val);
        affichage(t,taille);
    }
    //Tri du tableau
    //Tri croissant
    tri(t,taille,'c');
    affichage(t,taille);
    //Tri decroissant
    tri(t,taille,'d');
    affichage(t,taille);

    //Fusion de 2 tableaux
    int* t3;
    do{
        printf("Veuillez saisir la taille1(>=1) du premier tableau\n");
        scanf("%d",&taille1);
    }while(taille1<1);
    int* t1=malloc(sizeof(int)*(taille1));//tableau dynamique
    //Saisir les elements du tableau
    for(i=0;i<taille1;i++){
        printf("Saisir la valeur numero %d du tableau numero 1\n",i+1);
        scanf("%d",&t1[i]);
    }
    do{
        printf("Veuillez saisir la taille(>=1) du deuxieme tableau\n");
        scanf("%d",&taille2);
    }while(taille2<1);
    int* t2=malloc(sizeof(int)*(taille2));//tableau dynamique
    //Saisir les elements du tableau
    for(i=0;i<taille2;i++){
        printf("Saisir la valeur numero %d du tableau numero 2\n",i+1);
        scanf("%d",&t2[i]);
    }
    t3=fusionTriee(t1,taille1,t2,taille2);
    for(i=1;i<t3[0];i++)
        printf("%d ",t3[i]);
    printf("\n");
   
    //Fusion de n tableaux
    int nbTab;
    printf("Veuillez saisir le nombre de tableaux a fusionner\n");
    scanf("%d",&nbTab);
    res=NULL;
    int j;
    taille=0;
    int tailleTab;
    for(i=0;i<nbTab;i++){
        printf("Veuillez saisir la taille du tableau numero %d\n",i+1);
        scanf("%d",&tailleTab);
        int t[tailleTab];
        printf("Veuillez saisir les valeurs du tableau numero %d\n",i+1);
        for(j=0;j<tailleTab;j++)
                scanf("%d",&t[j]);
        res=fusionTriee(res,taille,t,tailleTab);
        taille=res[0];
    }
    for(i=1;i<res[0];i++)
        printf("%d ",res[i]);
    printf("\n");
    //Conversion d'un nombre de la base 10 vers une autre entre 2 et 16
    int base;
    for(i=0;i<10;i++){
        printf("Veuillez saisir le nombre ainsi que la base\n");
        scanf("%d%d",&val,&base);
        char* res;
        res=convert(val,base);
        puts(res);

    }
}