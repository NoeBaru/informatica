#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
Author: Noemi Baruffolo
date: 14/09/2023
es. 08
text: Creare la procedura POT2(x) che eleva alla seconda il suo parametro x, cioè se inizialmente x
=3 alla fine x vale 9 (utilizza il passaggio dei parametri opportuno). Creare un main che testi
questa funzione.
*/

void POT2(float *x) {
    *x *= (*x);
}

int main() {
    float x;

	printf("Inserisci il numero che vuoi elevare: ");

    scanf("%f", &x);

    POT2(&x);

    printf("La potenza del numero e': %.2f", x);

    return 0;
}