#include <stdio.h>
#include <stdlib.h>
#include "tab.h"

int initTab( int * tab, int size) {                //initialisation du tableau avec des 0
    if (tab==NULL || size<0){
        return(-1);
    }
    else {
        for (int i = 0; i<10; i++) { 
            *(tab+i)=0;
        }
        return(size);
    }
}

int afficheTab(int *tab, int size, int nbElts) {  //affiche les nbElts premièrs éléments du tableau tab sur une ligne de la console 
    if (tab==NULL || size<0 || size<nbElts){
        return(-1);
    }
    else {
        for (int i = 0; i < nbElts; i++) {
            printf("%d ",*(tab+i));
        }
        return(0);
    }
}

int ajoutElementDansTableau( int *tab, int *size, int *nbElts, int element) {               //ajoute un ou des élements dans le tableau tab
    if (tab==NULL || size<0) {
        return(-1);
    }
    else {
        if (nbElts>=size) {                                                   //si le tableau n'est pas suffisamment grand pour contenir tous les éléments
            int* test_tab=tab;
            tab = (int*)realloc(tab, (*size + TAILLEAJOUT) * sizeof(int)); //on ajoute TAILLEAJOUT cases au tableau (opérations d'allocation coûteuses donc on anticipe)
            if (test_tab==NULL) {                                                             //si l'agrandissement du tableau a échoué
                tab = test_tab;
                return(-1);
            }
            for (int i = 0; i < TAILLEAJOUT; i++) {                                        //on agrandit le tableau de TAILLEAJOUT éléments           
				*(tab + *size + i) = 0;
			}
			*size = *size+TAILLEAJOUT; 
        }
        *(tab + *nbElts) = element;                                                        //au rang nbElts du tableau, on place l'élément
		*nbElts = *nbElts+1;                                                              //il y a donc un élément de plus dans le tableau
		return(*nbElts);                                                      //on retourne le pointeur qui correspond à la position modifiée du tableau
    }
}

int main() {                                                     //fonction principale
    int MyTab[10];
    int *MyTab2 = NULL; 
    int nbElts = 20;
    int size = TAB2SIZE;
    MyTab2 = (int*)malloc(100 * sizeof(int));           //création d'un tableau MyTab2 de manière dynamique
    initTab(MyTab2,TAB2SIZE);                               //initialisation du tableau MyTab2                 
    if (MyTab2=NULL) {
        return(-1);
    }
    else {
        for (int i = 0; i < 20; i++) {    //20 premières valeurs du tableau prennent à la suite les nombres de 1 à 20 comme valeur
            MyTab2[i]=i+1;
        }
    }
    afficheTab(MyTab2, size, 40);                          //on affiche les 40 premières valeurs

	nbElts = 110;                                        //On change le nombre d'éléments à ajouter
	ajoutElementDansTableau(MyTab2, &size, &nbElts, 33);   //on ajoute l'élément 33 au rang 110
    printf("%d",afficheTab(MyTab2, size, 120));  

    free(MyTab2);                                         //restitution de la mémoire au système
}