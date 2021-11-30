/* 
 * Corso di Fondamenti di Informatica
 * Esercizio:
 * programma che propone un confronto tra 
 * 1) il ciclo a condizione iniziale while;
 * 2) il ciclo a conteggio for;
 * 3) il ciclo a condizione finale do...while.
 *
 * Differenze:
 * > rispetto al ciclo while, il ciclo for ha solo una differente forma,
 *   raccogliendo tutti gli elementi chiave in un'unica istruzione;
 * > rispetto ai cicli while e for, il cui corpo non viene mai eseguito se la
 *   condizione di esecuzione è falsa fin dall'inizio, nel caso del ciclo 
 *   do...while il corpo del ciclo viene sempre eseguito ALMENO 1 VOLTA:
 *   infatti la prima verifica della condizione avviene solo dopo la prima
 *   iterazione.
 *
 * In ogni caso, le differenze tra i tre tipi di ciclo sono esclusivamente
 * formali. E' possibile modificare il tipo dei cicli contenuti in un programma
 * C (ad es. trasformando alcuni dei cicli for in do...while) senza alterare il 
 * funzionamento del programma, purché questo sia modificato opportunamente. Il
 * fatto che siano disponibili diversi tipi di ciclo risponde solo alla volontà
 * di consentire al programmatore di scegliere di volta in volta il tipo di 
 * ciclo che rende il programma più chiaro.
 *
 * In effetti, ciascuno dei tre tipi di ciclo è caratterizzato dall'uso di
 * opportune "variabili di controllo" usate per controllare quando è il
 * momento di terminare l'esecuzione ciclica, nonché dai seguenti tre
 * elementi chiave:
 *
 * 1) inizializzazione della/delle variabili di controllo (qualora essa sia
 *    necessaria);
 * 2) condizione per la continuazione dell'esecuzione del ciclo, che
 *    coinvolge i valori delle variabili di controllo;
 * 3) istruzioni di aggiornamento delle variabili di controllo durante
 *    l'iterazione (in genere alla fine della stessa);
 *
 * Passando da un tipo di ciclo all'altro, cambia solo il MODO in cui questi
 * tre elementi sono gestiti, ma non la loro identità.
 *
 * Il programma seguente chiede all'utente un numero reale e ne fornisce il
 * quadrato; esso termina alla terza richiesta oppure se l'utente inserisce un
 * numero negativo. Sono fornite tre versioni del programma, aventi il medesimo
 * comportamento, basate sui tre tipi di ciclo.
 */


#include <stdio.h>
#define MAX_QUADRATI 3
/* numero massimo di operazioni di calcolo del quadrato svolte dal programma */

int main(void)
{
  float Input;
  /* ultimo valore inserito dall'utente */
  int NumeroQuadrati;
  /* numero di quadrati già calcolati dal programma */


  /****** versione a condizione iniziale con ciclo while ******/
  printf("\n\nVersione del programma con ciclo while:");
  printf("\nInserisci un numero reale (se negativo termina): ");
  scanf ("%f", &Input);
  
  NumeroQuadrati = 0;
  while ( (Input >= 0) && (NumeroQuadrati < MAX_QUADRATI) )
  {
    printf("Il quadrato di %f e' %f.", Input, Input*Input);
    ++NumeroQuadrati;
    
    if (NumeroQuadrati < MAX_QUADRATI)
    {
      printf("\nInserisci un numero reale (se negativo termina): ");
      scanf ("%f", &Input);
    }
  }

  printf("\nTermine della versione del programma con ciclo while.\n");


  /****** versione a condizione iniziale con ciclo for ******/
  printf("\n\nVersione del programma con ciclo for:");
  printf("\nInserisci un numero reale (se negativo termina): ");
  scanf ("%f", &Input);
  
  for (NumeroQuadrati = 0; (Input >= 0) && (NumeroQuadrati < MAX_QUADRATI);
       ++NumeroQuadrati)  
  {
    printf("Il quadrato di %f e' %f.", Input, Input*Input);
    
    if (NumeroQuadrati < MAX_QUADRATI - 1)
    /* attenzione: il "-1" è necessario perché NumeroQuadrati non è stato
     * ancora incrementato, dato che ciò avviene al termine dell'iterazione */
    {
      printf("\nInserisci un numero reale (se negativo termina): ");
      scanf ("%f", &Input);
    }
  }

  printf("\nTermine della versione del programma con ciclo for.\n");



  /****** versione a condizione finale ******/
  printf("\n\nVersione del programma con ciclo do...while:");
  NumeroQuadrati = 0;
  do
  {
    printf("\nInserisci un numero reale (se negativo termina): ");
    scanf ("%f", &Input);

    if ( Input >= 0 )
    /* questa istruzione condizionale e' necessaria per evitare che
     * venga stampato il quadrato se l'utente inserisce un numero
     * negativo come primo valore in input */
  	{
      printf("Il quadrato di %f e' %f.", Input, Input*Input);
      ++NumeroQuadrati;
  	}
  } while ( (Input >= 0) && (NumeroQuadrati < MAX_QUADRATI) );

  printf("\nTermine della versione del programma con ciclo do...while.\n\n");

  return(0);
}
