/*
Scrivere un programma C che legge da tastiera il raggio di un cerchio,
calcola circonferenza ed area del cerchio, e stampa i due valori a video.
Definire  = 3.14159  come parametro costante (con una dichiarazione const o
una direttiva #define).Nota: C = 2 r,  A = r2  se  r, C ed A sono rispettivamente
raggio, circonferenza e area del cerchio.Esempio di esecuzione (in rosso i
dati inseriti dall'utente):
Inserisci il raggio: 10.0
Circonferenza = 62,831840
Area = 314,159200
Si scriva, compili, esegua e corregga il programma.
Una volta che esso funziona correttamente, lo si modifichi in modo che
continui a chiedere nuovi valori di raggio all'utente (e a fornire risultati)
finché l'utente non inserisce un valore negativo.
*/

#include <stdio.h>

#define PI 3.14159

int main()
{
  float raggio;
  printf("Inserisci il raggio: ");
  scanf("%f", &raggio);
  printf("Circonferenza = %f\nArea = %f\n", 2 * PI * raggio, PI * raggio * raggio);
  return 0;
}