//Déclaration des prototypes des fonctions

#define TAB2SIZE 100
#define NULL __DARWIN_NULL
#define TAILLEAJOUT 20

int initTab( int * tab, int size);

int afficheTab(int *tab, int size, int nbElts);

int ajoutElementDansTableau( int *tab, int *size, int *nbElts, int element);