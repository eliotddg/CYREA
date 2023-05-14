#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define  MAX_LIGNE 10
#define  MAX_COLONE 10
#define MIN_SYMBOLE 4
#define MAX_SYMBOLE 6

// Fonction pour générer un entier aléatoire entre min et max (inclus)
int aleatoire(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Fonction pour générer la grille avec les conditions requises
void generer_grille(int M, int N) {
    char grille[MAX_LIGNE][MAX_COLONE];// adam: j ai changé le grid par grille
    int i, j;

    // Demander à l'utilisateur de saisir les symboles
    char tableau_symbole[MAX_SYMBOLE]; //creation d'un tableau avec 6 cases
    int nombre_symbole;  // initalisation de la variable qui dit le nombre de symbole qu'il y aura dans le jeu

    
  do{
      printf("Combien de symboles différents souhaitez-vous utiliser (entre %d et %d) ? ", MIN_SYMBOLE, MAX_SYMBOLE);
      scanf("%d", &nombre_symbole);  //utilisateur ecrit le nombre de symbole qu'il veut
    }while(nombre_symbole>6 || nombre_symbole<4);
    

    printf("Saisissez les symboles voulu :\n");
    for (i = 0; i < nombre_symbole; i++) {
      
        printf("Symbole %d : ", i + 1);      
        scanf(" %c", &tableau_symbole[i]);     // c'est ici que l'utilisateur va inscrire toutes les symboles

    }

  
    // Génération de la grille
    for (i = 0; i < M; i++) {  //ligne
        for (j = 0; j < N; j++) {      //colone
            // Vérification des symboles voisins
            char symbole; // declaration d'une variable charactere
            do {
                symbole = tableau_symbole[aleatoire(0, nombre_symbole - 1)]; // tableau qui utilise la fonction aleatoire pour se definir
            } while ((i > 1 && grille[i-1][j] == symbole && grille[i-2][j] == symbole) ||
                     (j > 1 && grille[i][j-1] == symbole && grille[i][j-2] == symbole));

            // Placement du symbole dans la grille
            grille[i][j] = symbole;
        }
    }

    // Affichage de la grille générée
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            printf("%c ", grille[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int M, N;

    srand(time(NULL));

    do{
      printf("Entrez le nombre de lignes (M) inférieur  à  10 : ");
      scanf("%d", &M);
    }while(M>10);
    do{
      printf("Entrez le nombre de colonnes (N) inférieur   à 10 : ");
      scanf("%d", &N);
    }while(N>10);
    

    generer_grille(M, N);

    return 0;
}