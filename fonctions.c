#include "bibliotheques.h"
void affichage(int t[],int taille){
    int i;
    for(i=0;i<taille;i++)
        printf("%d ",t[i]);
    printf("\n");
}
int sommeElements(int t[],int taille){
    int s=0,i;
    for(i=0;i<taille;i++){
        s+=t[i];
    }
    return s;
}
int maxOuMin(int t[],int taille,char type){
    int i,maxi,mini;
    switch(type){
        case 'm':
                 maxi=t[0];
                 for(i=0;i<taille;i++){
                     if(maxi<t[i])
                            maxi=t[i];
                 }
                 return maxi;
        case 'n':
                 mini=t[0];
                  for(i=0;i<taille;i++){
                     if(mini>t[i])
                            mini=t[i];
                 }
                 return mini;
        default: return 0;
    }
}
bool chercher(int t[],int taille,int valeur){
    int i=0;
    bool existe=false;
    while(!existe && i<taille){
        if(t[i]==valeur)
             existe=true;
        i++;//Continue de chercher dans le tableau
    }
    if(existe)
        return true;
    
    return false;
}
void chercherPlusieursValeurs(int t[],int taille,int vals[],int nb){
   int i;
   for(i=0;i<nb;i++){
       if(chercher(t,taille,vals[i]))
          printf("Oui, %d existe\n",vals[i]);
       else  
          printf("Non, %d n'existe pas\n",vals[i]);
  
   }
}
bool estPremier(int a){
    int i;
    for(i=2;i<=sqrt(a);i++){
        if(a%i==0)
            return false;
    }
    if(a==1)
        return false;
    return  true;
}
int * obtenirNombresPremiers(int t[],int taille){
   int* res=malloc(sizeof(int)*(taille+1));
   int i,cpt=0;
   for(i=0;i<taille;i++){
        if(estPremier(t[i])){
            cpt++;
            res[cpt]=t[i];
        }
   }
   res[0]=cpt;
   return res;
} 
int nbChiffre(int a){
    int res=0;
    if(a==0){
        return 1;
    }
    while(a!=0){
        a/=10;
        res+=1;
    }
    return res;
}
bool estPalindrome(int a){
    int nb_chiffre=nbChiffre(a);
    int nombre[nb_chiffre];
    int i=nb_chiffre-1;
    while(i>=0){
        nombre[i]=a%10;
        a/=10;
        i--;
    }
    for(i=0;i<nb_chiffre/2;i++){
         if(nombre[i]!=nombre[nb_chiffre-i-1])
            return false;
    }
    return true;
}
int * obtenirNombresPalindrome(int t[],int taille){
   int* res=malloc(sizeof(int)*(taille+1));
   int i,cpt=0;
   for(i=0;i<taille;i++){
        if(estPalindrome(t[i])){
            cpt++;
            res[cpt]=t[i];
        }
   }
   res[0]=cpt;
   return res;
} 
void mettre_a_jour(int t[],int taille,int pos,int val){
    if(pos<0 || pos>=taille)
        printf("Position invalide\n");
    else
        t[pos]=val;
}
int inserer(int t[],int taille,int val,int pos){
    if(pos<0 || pos>taille){
        printf("Position invalide\n");
        return taille;
    }
    else{
        t=realloc(t,taille+1);//realloc fait une reallocation dynamique
        int i=taille;
        while(i>pos){
            t[i]=t[i-1];
            i--;
        }
        t[pos]=val;
        return taille+1;
    }

}

int insererSansDoublon(int t[],int taille,int val,int pos){
    if(chercher(t,taille,val)){
        printf("La valeur %d existe deja dans le tableau\n",val);
        return taille;
    }
    return inserer(t,taille,val,pos);
}
int supprimer(int t[],int taille,int val){
    if(taille<=0){
        printf("Tableau vide,impossible de supprimer\n");
        return 0;
    }
    if(chercher(t,taille,val)){
        int i=0;
        while(i<taille && t[i]!=val)
            i++;
        while(i<taille-1){
            t[i]=t[i+1];
            i++;
        }
        return taille-1;
    }
    else{
        printf("%d n'existe pas dans le tableau\n",val);
        return taille;
    }
}
int supprimerTousLesDoublons(int t[],int taille,int val){
    while(chercher(t,taille,val)){
        taille=supprimer(t,taille,val);
    }
    return taille;
}
void tri(int t[],int taille,char type){
    int i,j,posMin,posMax,temp;
    switch(type){
        case 'c':  for(i=0;i<taille-1;i++){
                        posMin=i;
                        for(j=i+1;j<taille;j++){
                            if(t[j]<t[posMin]){
                                posMin=j;
                            }
                        }
                        //permutation
                        temp=t[i];
                        t[i]=t[posMin];
                        t[posMin]=temp;
                    }
                    break;
        case 'd':for(i=0;i<taille-1;i++){
                        posMax=i;
                        for(j=i+1;j<taille;j++){
                            if(t[j]>t[posMax]){
                                posMax=j;
                            }
                        }
                        //permutation
                        temp=t[i];
                        t[i]=t[posMax];
                        t[posMax]=temp;
                    }
                break;
        default: printf("Il y a rien a faire\n");
    }
}
int* fusion(int t1[],int taille1,int t2[],int taille2){
    int* t3=malloc(sizeof(int)*(taille1+taille2));
    int i;
    for(i=0;i<taille1;i++)
        t3[i]=t1[i];
    int j=0;
    while(i<taille1+taille2)
        t3[i++]=t2[j++];
    return t3;
}
int* fusionTriee(int t1[],int taille1,int t2[],int taille2){
    int* t3=malloc(sizeof(int)*(taille1+taille2));
    tri(t1,taille1,'c');
    tri(t2,taille2,'c');
    int i=0,j=0,k=1;
    while(i<taille1 && j<taille2){
        if(t1[i]<t2[j])
            t3[k++]=t1[i++];
        else if(t2[j]<t1[i])
            t3[k++]=t2[j++];
        else{
            t3[k++]=t2[j++];
            i++;
        }
    }
    while(i<taille1)
        t3[k++]=t1[i++];
    while(j<taille2)
        t3[k++]=t2[j++];
    t3[0]=k;
    return t3;
    
}
char* convert(int val,int base){
    char t[]={'0','1','2','3','4','5','6','7','8','9','A',
                'B','C','D','E','F'};
    int nbChiffre=ceil(log(val+1)/log(base));
    char* res=malloc(sizeof(char)*nbChiffre);
    int i=nbChiffre-1;
    while(i>=0){
        res[i--]=t[val%base];
        val/=base;
    }
    return res;
}