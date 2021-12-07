#include <myPrintf.h>

int main(void)
{
    char *Prenom = "Gebril";
    int age = 29 ;
    int age2 = 30 ;

    int nbr1 = 2 ;
    int nbr2 = 10 ;

    int *p_age = &age ;
    char lettre = 'A' ;
    double db = 89.89;
    double db2 = 1423.99 ;
    double nbNegatif = -178.569 ;
    int result ;
    Myprintf("Test Prenom : %s , Test age : %d, Test pointeur : %p, Test modulo %%, Test char : %c\n",Prenom,age,p_age,lettre);
    Myprintf("Test calcul 1 + 1 : %d\n",1+1);
    Myprintf("Affichage de double : %f\n",db);
    Myprintf("Affichade db2 : %f\n",db2);
    Myprintf("Affichage Float nombre négatif : %f\n",nbNegatif);
    Myprintf("%d\n",nbr2*nbr1);
    return(0);
}
