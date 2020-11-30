#include <stdio.h>
#include <stdlib.h>
#include "exercice2.h"

TABLEAU newArray() {                                        //création d'un nouveau TABLEAU en allouant une taille initiale pour les données
    TABLEAU tableau;
    tableau.elt = (int*)malloc(TAILLEINITIALE*sizeof(int));                           //allocation de la mémoire
    tableau.size = TAILLEINITIALE;                                               //taille initialisé à TAILLEINITIALE
    tableau.eltsCount = 0;                                                      //le champ eltsCount initialisé à zéro
    for (int i =0; i<TAILLEINITIALE;i++) {
        tableau.elt[i] = 0;                                                //tous les éléments du tableau sont initialisés à 0
    }
    if (tableau.elt==NULL) {
        printf("L'allocation a échoué");
        return(tableau);
    }
    return(tableau);
}

int incrementArraySize( TABLEAU * tab , int incrementValue) {                  //modification de la taille du tableau
    tab->elt = (int*)realloc(tab->elt, (tab->size + incrementValue) * sizeof(int)); 
    for (int i = 0; i<tab->size; i++) {                                          //on initialise le tableau à zéro
        *(tab->elt+i) = 0;
    }
    tab->size = tab->size+incrementValue; 
    if (tab->elt==NULL) {
        printf("L'allocation a échoué"); 
        return(-1);                                                            //renvoie -1 car problème d'allocation
    }
    return(tab->elt);                                                          //renvoie les éléments du tableau
}

int setElement(TABLEAU * tab, int pos, int element) {                //écriture d'un élément à une position donnée sans insertion
    if (tab->elt == NULL) {
        return(0);
    }
    else {
        if (pos>tab->size) {                                   //si le tableau n'est pas suffisamment grand pour contenir tous les éléments
            incrementArraySize(tab,pos-tab->size);
        }
        if (*(tab->elt + pos - 1) == 0){                                //si l'élément inséré se trouve après le dernier élément
            tab->eltsCount=tab->eltsCount+1;                                         //on ne remplace pas de 0
        }
        *(tab->elt + pos - 1) = element;                                        //on insère l'élément à la position pos-1
        return(pos);
    }
}

int displayElements(TABLEAU *tab, int startPos, int endPos ) {     //afficher une portion du tableau de l’indice début à l’indice fin
    if (tab->elt == NULL) {
        return(-1);
    }
    else {
        int i;
		if (startPos > endPos) {                             //si l'élément de l'indice début est plus grand que lélément de l'indice fin
			i = startPos;                                       //on permute l'élément de l'indice début avec l'élément de l'indice fin
			startPos = endPos;
			endPos = i;
		}
        for (i = startPos-1; i < endPos; i++) {  
            printf("%d ",*(tab->elt+i));                                      //on affiche la portion du tableau
        }
        return(0);
    }
}

int deleteElements(TABLEAU *tab, int startPos, int endPos ) {          //suppression des éléments avec compactage du tableau
    if (tab->elt == NULL) {
        return(-1);
    }
    else {
        int i;
        if (startPos >= endPos){                        //si l'élément de l'indice début est plus grand ou égal que lélément de l'indice fin
            i = startPos;
			startPos = endPos;                                //on permute l'élément de l'indice début avec l'élément de l'indice fin
			endPos = i;
		}
		for (i = 0; i<tab->size - endPos; i++) {
			*(tab->elt + startPos - 1 + i) = *(tab->elt + endPos + i); 
		}
		tab->elt = (int*)realloc(tab->elt, (tab->size - endPos + startPos) * sizeof(int)); //on réajuste le tableau
		tab->size = tab->size - endPos + startPos;                                   //on réajuste la taille du tableau
		return(tab->size);
    }
}

int main() {                                                                                //fonction principale

    TABLEAU tableau;
    tableau=newArray();
    printf("\nCréation d'un nouveau TABLEAU en allouant une taille initiale pour les données : on initialise les éléments à '0'\n");
    displayElements(&tableau,1,TAILLEINITIALE);

    printf("\nModification de la taille du tableau : on incrémente de 3\n");
    incrementArraySize(&tableau,3);
    displayElements(&tableau,1,TAILLEINITIALE+3);

    printf("\néÉriture de l'élément 10 à la position 2\n");
    setElement(&tableau, 2, 10);
    displayElements(&tableau,1,TAILLEINITIALE);

    printf("\nSuppression des éléments 4 à 5 avec compactage du tableau\n");
    deleteElements(&tableau,4,5);
    displayElements(&tableau,1,TAILLEINITIALE);

    free(tableau.elt);

}