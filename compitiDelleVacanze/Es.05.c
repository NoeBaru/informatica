#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LUNG 256

/*
Author: Noemi Baruffolo
date: 28/06/2023
es. 5
text: Raddoppiare le occorrenze delle vocali in una stringa (ciao→ciiaaoo)
*/

void raddoppiaV(char s[]) {
	char tmp[LUNG];
	int j = 0;

	for(int k = 0; s[k] != '\0'; k++) {
	
		if(s[k] == 'a' || s[k] == 'A' || s[k] == 'e' || s[k] == 'E' || s[k] == 'i' || s[k] == 'I' || s[k] == 'o' || s[k] == 'o' || s[k] == 'u' || s[k] == 'U') { //controlla la presenza dei caratteri 
			tmp[j] = s[k];
			
			j++;		
			
		}
		tmp[j] = s[k];
		
		j++;
	}

	tmp[j] = '\0'; //tappo della stirnga

	strcpy(s, tmp);
}

int main() {
	char str[LUNG];

	printf("Inserisci una frase: ");
	fgets(str, LUNG/2, stdin);
	
	raddoppiaV(str);
	
	printf("%s", str);	

	return 0;
}