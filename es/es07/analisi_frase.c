/* 
 * Corso di Fondamenti di Informatica
 * Esercizio:
 * esempio di uso di liste sequenziali
 */

/* Scrivere un programma C che:
 *
 **1. Definisce un array di caratteri Frase, di 60 elementi; in Frase va 
 * inserita, a partire dal primo carattere, una frase a piacere di lunghezza
 * minore o uguale della capienza massima di Frase.
 * La frase deve contenere da 1 a 10 parole, separate da (singoli) spazi, e
 * va terminata con il carattere '.' (punto) non preceduto da spazio. Il
 * primo carattere non può essere uno spazio. Ogni parola della frase può
 * avere una lunghezza compresa tra 1 e 15 caratteri. Se necessario, gli spazi
 * possono essere sostituiti da un opportuno carattere non alfabetico.
 **2. Legge da tastiera una frase (che soddisfa le condizioni sopra indicate) e
 * la inserisce in Frase.
 **3. Crea una LISTA SEQUENZIALE, ElencoParole, i cui elementi vanno usati per
 * descrivere le singole parole presenti in Frase. Ciascuno di tali elementi
 * comprende: (1) un array di caratteri che serve a memorizzare la parola, 
 * TERMINATA DAL CARATTERE '\0' (carattere di fine stringa); (2) la lunghezza
 * della parola (numero delle lettere che la compongono, escluso il '\0').
 **4. Esamina Frase e memorizza in ElencoParole i dati sulle singole parole
 * della frase ivi contenuta.
 **5. Stampa su righe separate le parole di ElencoParole, con a fianco le
 * relative lunghezze.
 *
 * Nota: un modo molto semplice per leggere da tastiera [stampare] una stringa
 * terminata con '\0' consiste nell'utilizzare scanf [printf] con la stringa di
 * controllo "%s". Nel caso di scanf, il '\0' viene inserito automaticamente in
 * coda ai caratteri inseriti da tastiera.
 * In realtà, per ragioni di sicurezza che vedremo in seguito nel corso, l'uso
 * di scanf per leggere stringhe è DA EVITARE: utilizzare invece la funzione
 * fgets. Inoltre la stringa non deve contenere spazi, che scanf interpreta
 * (al pari del carattere '\n' inserito dalla pressione del tasto <enter>) come
 * segnale che l'input e' terminato. 
 */

/*
ESERCIZIO:
Modificare il programma in modo da consentire la presenza di più di uno
spazio tra le parole, nonchè la presenza di spazi tra inizio della frase e
prima parola e/o tra ultima parola e punto.
*/

#include <stdio.h>

#define LUNG_MAX_FRASE 60
#define LUNG_MAX_PAROLA 15
#define NUM_MAX_PAROLE 10

#define TERMINATORE_FRASE '.'

#define TERMINATORE_PAROLE '_'

int main()
{
  int i;
  char frase[LUNG_MAX_FRASE];

  typedef struct
  {
    char string[LUNG_MAX_PAROLA];
    int N;
  } Parola;

  struct
  {
    Parola arr[NUM_MAX_PAROLE];
    int N;
  } elencoParole;

  scanf("%s", frase);
  printf("Frase inserita: %s\n", frase);

  elencoParole.N = 0;                     // Imposta dimensione lista parole a 0
  elencoParole.arr[elencoParole.N].N = 0; // Imposta dimensione prima parola a 0
  i = 0;
  while (frase[i] != TERMINATORE_FRASE)
  {
    if (frase[i] != TERMINATORE_PAROLE)
    {
      elencoParole.arr[elencoParole.N].string[elencoParole.arr[elencoParole.N].N] = frase[i]; // Aggiungi carattere a ultima parola
      elencoParole.arr[elencoParole.N].N++;                                                   // Incrementa dimensione ultima parola
    }
    else if (i != 0 && frase[i - 1] != TERMINATORE_PAROLE) // La parola è terminata
    {
      elencoParole.arr[elencoParole.N].string[elencoParole.arr[elencoParole.N].N] = '\0'; // Imposta ultimo carattere della parola a '\0'
      elencoParole.N++;                                                                   // Incrementa dimensione lista parole
      elencoParole.arr[elencoParole.N].N = 0;                                             // Imposta dimensione della prossima parola a 0
    }
    i++;
  }

  if (frase[i - 1] != TERMINATORE_PAROLE)
  {
    elencoParole.arr[elencoParole.N].string[elencoParole.arr[elencoParole.N].N] = '\0'; // Imposta ultimo carattere della parola a '\0'
    elencoParole.N++;                                                                   // Incrementa dimensione lista parole
  }

  /* Stampa parole separate da \n*/
  for (i = 0; i < elencoParole.N; i++)
  {
    printf("%s\n", elencoParole.arr[i].string);
  }
}