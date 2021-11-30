/*
 * Corso di Fondamenti di Informatica
 * Esercizio:
 * elaborazione di polinomi rappresentati tramite array
 */

/******************************************************************************
Scrivere un programma C che esegue la somma ed il prodotto tra due polinomi A
e B nella variabile x. Il grado (si veda la Nota 0) massimo che A e B possono
avere è definito da due parametri del programma, chiamati GRADO_MAX_A e
GRADO_MAX_B, mentre il grado effettivo dei polinomi è inserito dall'utente.
Per contenere i coefficienti dei polinomi utilizzare TRE array PoliA, PoliB e
PoliRis (quest'ultimo usato prima per la somma e poi per il prodotto)
aventi dimensioni minime possibili.
Il programma deve:
1. gestire l'inserimento da tastiera del grado dei polinomi A e B;
2. gestire l'inserimento da tastiera dei coefficienti di A e B;
3. inserire la somma in PoliRis e stampare il risultato (si veda la Nota 1);
4. inserire il prodotto in PoliRis e stampare il risultato (si veda la Nota 1);

Nota 0: il grado di un monomio in una variabile e' l'esponente al quale la
variabile e' elevata. Il grado di un polinomio e' il grado del suo monomio di
grado massimo. Il termine noto di un polinomio corrisponde al suo monomio di
grado 0.
Nota 1: ai punti 2 e 3 con l'espressione "stampare il risultato" si intende la
stampa dei coefficienti dei termini del polinomio risultante (inclusi gli
eventuali coefficienti nulli), in ordine di grado decrescente.
Nota 2: la somma di due polinomi ha grado pari al maggiore tra quelli dei
polinomi addendi; il prodotto di due polinomi ha grado pari alla somma di
quelli dei polinomi fattori.

Esempio di somma e prodotto tra polinomi con gradi 3 e 2:

           3     2                      2
     ( 4.3x  +  x  - 2.9x + 0.7 ) + ( -x  + 1.3 ) =

           3
     = 4.3x  - 2.9x + 2.0


           3     2                    2
     ( 4.3x  +  x  - 2.9x + 0.7 ) ( -x  + 1.3 ) =

            5    4        3       2
     = -4.3x  - x  + 8.49x  + 0.6x  - 3.77x + 0.91
******************************************************************************/


#include <stdio.h>

#define GRADO_MAX_AB 10
/* massimo grado ammesso per i polinomi A e B */
#define GRADO_MAX_RIS (GRADO_MAX_AB+GRADO_MAX_AB)
/* massimo grado che il polinomio risultato può assumere, dati i gradi dei due
 * polinomi addendi o fattori. Notare che il grado così definito è quello
 * del polinomio prodotto, ma è anche sicuramente maggiore o uguale a grado del
 * polinomio somma. In definitiva, un array in grado di rappresentare un
 * polinomio di grado GRADO_MAX_RIS è adatto per contenere sia il prodotto che
 * la somma dei polinomi A e B */

int main()
{
  float PoliA[GRADO_MAX_AB+1];
  /* polinomio A: l'elemento dell'array di indice i rappresenta il
   * coefficiente del termine di grado i. Solo gli elementi dell'array aventi
   * indice compreso tra 0 e il grado del polinomio vengono effettivamente
   * utilizzati. */
  float PoliB[GRADO_MAX_AB+1];
  /* polinomio B: l'elemento dell'array di indice i rappresenta il
   * coefficiente del termine di grado i. Solo gli elementi dell'array aventi
   * indice compreso tra 0 e il grado del polinomio vengono effettivamente
   * utilizzati. */
  float PoliRis[GRADO_MAX_RIS+1];
  /* polinomio risultato della somma o del prodotto: l'elemento dell'array di
   * indice i rappresenta il coefficiente del termine di grado i. Solo gli
   * elementi dell'array aventi indice compreso tra 0 e il grado del polinomio
   * vengono effettivamente utilizzati. */
  int GradoA, GradoB, GradoRis;
  /* gradi effettivi dei polinomi A e B (inseriti dall'utente) e grado
   * effettivo del polinomio risultante dal prodotto tra A e B */
  int GradoCorrA, GradoCorrB, GradoCorrRis;
  /* contatori usati per scorrere gli array (il terzo non è necessario, ma
   * introdurlo chiarifica il programma) */

  /* ------------inizializzazione dei polinomi A e B:------------ */
  printf("\nInserisci il grado del polinomio A:\n");
  scanf("%d", &GradoA);
  printf("\nInserisci il grado del polinomio B:\n");
  scanf("%d", &GradoB);

  GradoRis = GradoA + GradoB;
  /* per le regole del prodotto tra polinomi */

  printf("\nInserisci i coefficienti del polinomio A:\n");
  GradoCorrA = GradoA;
  while (GradoCorrA >= 0)
  {
    printf("\nA%d (coeff. di x^%d): ", GradoCorrA, GradoCorrA);
    scanf("%f", &PoliA[GradoCorrA]);
    --GradoCorrA;
  }

  printf("\nInserisci i coefficienti del polinomio B:\n");
  GradoCorrB = GradoB;
  while (GradoCorrB >= 0)
  {
    printf("\nB%d (coeff. di x^%d): ", GradoCorrB, GradoCorrB);
    scanf("%f", &PoliB[GradoCorrB]);
    --GradoCorrB;
  }

  /* ------------stampa dei coefficienti dei polinomi A e B:------------ */
  printf("\n\nA:\n");
  GradoCorrA = GradoRis;
  while (GradoCorrA >=0)
  {
    if (GradoA >= GradoCorrA )
  	/* se il polinomio possiede un termine di grado GradoCorrA */
    {
  	  printf("%+.3f x^%d\t", PoliA[GradoCorrA], GradoCorrA);
      /* Nota: lo specificatore ".3" prima di "%f" serve a limitare a 3 il
       * numero di cifre dopo la virgola che vengono stampate; il segno + e'
       * un indicatore che richiede a printf di indicare sempre il segno del
       * numero stampato, anche quando e' positivo. */
  	}
    else
  	{
      printf("\t\t");
  	}
  	--GradoCorrA;
  }

  printf("\n\nB:\n");
  GradoCorrB = GradoRis;
  while (GradoCorrB >=0)
  {
    if (GradoB >= GradoCorrB )
  	/* se il polinomio possiede un termine di grado GradoCorrB */
    {
      printf("%+.3f x^%d\t", PoliB[GradoCorrB], GradoCorrB);
  	}
    else
  	{
  	  printf("\t\t");
  	}
  	--GradoCorrB;
  }

  /* ------------calcolo e stampa della somma:------------ */
  GradoCorrRis=0;
  while (GradoCorrRis <= GradoRis)
  {
    if ( (GradoCorrRis > GradoA) && (GradoCorrRis > GradoB) )
  	/* se nessuno dei due polinomi A e B include monomi di grado
  	 * GradoCorrRis */
   	{
  	  PoliRis[GradoCorrRis] = 0.0;
  	}
    else
    /* almeno uno tra i polinomi A e B contiene un monomio di grado
     * GradoCorrRis */
  	{
      if ( GradoCorrRis > GradoA )
	    /* il polinomio A non include un monomio di tale grado (dunque B deve
	     * necessariamente includerlo) */
      {
        PoliRis[GradoCorrRis] = PoliB[GradoCorrRis];
      }
  	  else
  	  /* il polinomio A include un monomio di grado GradoCorrRis */
      {
        if ( GradoCorrRis > GradoB )
    		/* se il polinomio B non include un monomio di grado GradoCorrRis
    		 * (dunque solo A lo contiene) */
    		{
    		  PoliRis[GradoCorrRis] = PoliA[GradoCorrRis];
    		}
        else
    		/* entrambi i polinomi A e B includono monomi di grado
    		 * GradoCorrRis */
    		{
    		  PoliRis[GradoCorrRis] = PoliA[GradoCorrRis] +
    	                            PoliB[GradoCorrRis];
	      }
  	  }
	  }
	  ++GradoCorrRis;
  }

  printf("\n\nA+B:\n");
  GradoCorrRis = GradoRis;
  while (GradoCorrRis >=0)
  {
    if ( (GradoB >= GradoCorrRis) || (GradoA >= GradoCorrRis) )
  	/* se il polinomio possiede un termine di grado GradoCorrB */
  	{
  	  printf("%+.3f x^%d\t", PoliRis[GradoCorrRis], GradoCorrRis);
  	}
    else
  	{
    printf("\t\t");
  	}
  	--GradoCorrRis;
  }

  /* ------------calcolo e stampa del prodotto:------------ */
  GradoCorrRis = 0;
  while (GradoCorrRis <= GradoRis)
  {
    /* azzeramento di tutti i coefficienti del risultato */
    PoliRis[GradoCorrRis] = 0.0;
    ++GradoCorrRis;
  }

  GradoCorrA = 0;
  while (GradoCorrA <= GradoA)
  {
    GradoCorrB = 0;
    while (GradoCorrB <= GradoB)
  	{
  	  PoliRis[GradoCorrA+GradoCorrB] = PoliRis[GradoCorrA+GradoCorrB] +
                                       PoliA[GradoCorrA] * PoliB[GradoCorrB];

      ++GradoCorrB;
  	}
  	++GradoCorrA;
  }

  printf("\n\nA*B:\n");
  GradoCorrRis = GradoRis;
  while (GradoCorrRis >=0)
  {
    printf("%+.3f x^%d\t", PoliRis[GradoCorrRis], GradoCorrRis);
    --GradoCorrRis;
  }

  printf("\n\n");

  return(0);
}

/* ESERCIZIO A
 * In questo programma, il codice relativo alla somma di polinomi e' piuttosto
 * complicato, il che rende piu' probabili gli errori di programmazione e piu'
 * difficile il debugging. Si modifichi il programma in modo da semplificare
 * tale codice.
 * [Suggerimento: il problema e' causato dal fatto che gli elementi non
 *  utilizzati degli array PoliA e PoliB vengono lasciati non
 *  inizializzati e dunque occorre ignorarli durante il calcolo.] */

/* ESERCIZIO B (da svolgere non appena a lezione sara' stato trattato
 *              l'argomento delle funzioni C)
 * Questo programma contiene parecchie operazioni ripetute, ovvero
 * identiche nello svolgimento ma applicate a dati diversi. Ad esempio, la
 * lettura dei coefficienti di un polinomio avviene due volte, una per il
 * polinomio A e una per il polinomio B. Anche l'operazione di stampa di un
 * polinomio viene eseguita più volte per polinomi diversi.
 * Modificare il programma per implementare ciascuna di queste operazioni
 * ripetute tramite una opportuna FUNZIONE. */
