#define NULL __DARWIN_NULL
#define TAILLEINITIALE 100

typedef struct Tableau { 
    int*elt; //tableau 
    int size; //taille du tableau
    int eltsCount; //nbre d'entiers du tableau
} TABLEAU;

TABLEAU newArray( );

int incrementArraySize( TABLEAU * tab , int incrementValue);

int setElement(TABLEAU * tab, int pos, int element );

int displayElements(TABLEAU *tab, int startPos, int endPos );

int deleteElements(TABLEAU *tab, int startPos, int endPos );