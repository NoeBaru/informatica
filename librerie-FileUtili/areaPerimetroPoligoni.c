#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define PI  3.14159265358979323846

#include <stdio.h>
#include <math.h>

int main() {
    int scelta;
    printf("Calcolatore di Area e Perimetro di Poligoni\n");
    printf("Scegli il tipo di poligono:\n");
    printf("1. Triangolo\n");
    printf("2. Quadrato\n");
    printf("3. Rettangolo\n");
    printf("4. Pentagono\n");
    printf("5. Rombo\n");
    printf("6. Parallelepipedo\n");
    printf("7. Trapezio\n");
    printf("8. Uscita\n");

    scanf("%d", &scelta);

    switch (scelta) {
        case 1:
            // Triangolo
            {
                float lato1, lato2, lato3;
                printf("Inserisci la lunghezza del primo lato: ");
                scanf("%f", &lato1);
                printf("Inserisci la lunghezza del secondo lato: ");
                scanf("%f", &lato2);
                printf("Inserisci la lunghezza del terzo lato: ");
                scanf("%f", &lato3);

                float semiperimetro = (lato1 + lato2 + lato3) / 2;
                float area = sqrt(semiperimetro * (semiperimetro - lato1) * (semiperimetro - lato2) * (semiperimetro - lato3));
                float perimetro = lato1 + lato2 + lato3;

                printf("L'area del triangolo è: %.2f\n", area);
                printf("Il perimetro del triangolo è: %.2f\n", perimetro);
            }
            break;

        case 2:
            // Quadrato
            {
                float lato;
                printf("Inserisci la lunghezza di un lato: ");
                scanf("%f", &lato);

                float area = lato * lato;
                float perimetro = 4 * lato;

                printf("L'area del quadrato è: %.2f\n", area);
                printf("Il perimetro del quadrato è: %.2f\n", perimetro);
            }
            break;

        case 3:
            // Rettangolo
            {
                float base, altezza;
                printf("Inserisci la lunghezza della base: ");
                scanf("%f", &base);
                printf("Inserisci la lunghezza dell'altezza: ");
                scanf("%f", &altezza);

                float area = base * altezza;
                float perimetro = 2 * (base + altezza);

                printf("L'area del rettangolo è: %.2f\n", area);
                printf("Il perimetro del rettangolo è: %.2f\n", perimetro);
            }
            break;

        case 4:
            // Pentagono
            {
                float lato;
                printf("Inserisci la lunghezza di un lato del pentagono: ");
                scanf("%f", &lato);

                float area = (5 * lato * lato) / (4 * tan(PI / 5));
                float perimetro = 5 * lato;

                printf("L'area del pentagono è: %.2f\n", area);
                printf("Il perimetro del pentagono è: %.2f\n", perimetro);
            }
            break;

        case 5:
            // Rombo
            {
                float diagonaleMaggiore, diagonaleMinore;
                printf("Inserisci la lunghezza della diagonale maggiore: ");
                scanf("%f", &diagonaleMaggiore);
                printf("Inserisci la lunghezza della diagonale minore: ");
                scanf("%f", &diagonaleMinore);

                float area = (diagonaleMaggiore * diagonaleMinore) / 2;
                float perimetro = 4 * sqrt((diagonaleMaggiore * diagonaleMaggiore + diagonaleMinore * diagonaleMinore) / 8);

                printf("L'area del rombo è: %.2f\n", area);
                printf("Il perimetro del rombo è: %.2f\n", perimetro);
            }
            break;

        case 6:
            // Parallelepipedo
            {
                float lunghezza, larghezza, altezza;
                printf("Inserisci la lunghezza: ");
                scanf("%f", &lunghezza);
                printf("Inserisci la larghezza: ");
                scanf("%f", &larghezza);
                printf("Inserisci l'altezza: ");
                scanf("%f", &altezza);

                float area = 2 * (lunghezza * larghezza + larghezza * altezza + altezza * lunghezza);
                float volume = lunghezza * larghezza * altezza;

                printf("L'area del parallelepipedo è: %.2f\n", area);
                printf("Il volume del parallelepipedo è: %.2f\n", volume);
            }
            break;

        case 7:
            // Trapezio
            {
                float baseMaggiore, baseMinore, altezza, lato1, lato2;
                printf("Inserisci la lunghezza della base maggiore: ");
                scanf("%f", &baseMaggiore);
                printf("Inserisci la lunghezza della base minore: ");
                scanf("%f", &baseMinore);
                printf("Inserisci la lunghezza dell'altezza: ");
                scanf("%f", &altezza);
                printf("Inserisci la lunghezza del lato 1: ");
                scanf("%f", &lato1);
                printf("Inserisci la lunghezza del lato 2: ");
                scanf("%f", &lato2);

                float area = ((baseMaggiore + baseMinore) * altezza) / 2;
                float perimetro = baseMaggiore + baseMinore + lato1 + lato2;

                printf("L'area del trapezio è: %.2f\n", area);
                printf("Il perimetro del trapezio è: %.2f\n", perimetro);
            }
            break;

        case 8:
            // Uscita dal programma
            printf("Uscita dal programma. Arrivederci!\n");
            break;

        default:
            printf("Scelta non valida. Riprova.\n");
    }

    return 0;
}
