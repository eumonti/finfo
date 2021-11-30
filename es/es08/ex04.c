/*
Definire il tipo di dato tentativo_esame mediante una struttura contenente il nome di un esame (array di 20 caratteri) e un esito di tipo float: l'esito coincide con il voto ottenuto (se non inferiore a 18.0) oppure, nel caso di tentativo fallito, con -1.0. Definire il tipo di dato sequenza-tentativi mediante una lista sequenziale di strutture di tipo tentativo_esame: la lista sequenziale deve contenere, oltre all'indicazione del numero dei tentativi, la sequenza -in ordine cronologico- dei tentativi effettuati da uno studente di superare gli esami del suo piano di studi.

Scrivere le dichiarazioni e le istruzioni di un frammento di programma che stampa in sequenza i nomi degli esami superati con il voto positivo ottenuto, e la media tra i soli voti positivi. 
N.B Non è necessario codificare la lettura della struttura; si trascuri l'eventuale lode.
*/

#include <stdio.h>

#define MAX_SIZE 40

typedef struct
{
  char nome[20];
  float esito;
} tentativo_esame;

typedef struct
{
  int N;
  tentativo_esame arr[MAX_SIZE];
} sequenza_tentativi;

int main()
{
  sequenza_tentativi sq;
  int i;
  float media;
  printf("Nome esame:\tEsito:\n");
  for (i = 0; i < sq.N; i++)
  {
    if (sq.arr[i].esito > 0)
      printf("%s\t%d\n", sq.arr[i].nome, sq.arr[i].esito);
  }
  
}