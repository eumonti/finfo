/* 
 * Corso di Fondamenti di Informatica
 * Esercizio:
 * programma dimostrativo che illustra l'utilizzo di RAM dovuto all'uso di
 * allocazione dinamica, e i concetti di "garbage" (spazzatura) e "dangling
 * reference" (riferimento fluttuante) */

#include <stdio.h>
#include <stdlib.h>

#include <string.h>

/* #define DEBUG */
/* definire questo parametro fa sì che le istruzioni di debug vengano 
 * eseguite */

/* #define GENERA_GARBAGE */
/* ****************************** ATTENZIONE ******************************
 * definire la label GENERA_GARBAGE provoca la creazione di "garbage" (memoria
 * dinamica non deallocata quando si cessa di utilizzarla). La generazione di
 * "garbage" e' un gravissimo errore di programmazione poiche' mantiene
 * riservata per uso del programma (e quindi non disponibile per il sistema)
 * memoria che in realta' non e' piu' utilizzata effettivamente
 * ************************************************************************ */
 
#define DIM 999984
/* dimensione del campo array dell'elemento della lista dinamica:
 * aumentando DIM si aumenta la dimensione del singolo elemento della lista,
 * dunque la RAM viene riempita piu' velocemente all'aumentare di dimensioni
 * della lista */
 
#define POS_TEST 100
/* posizione dell'elemento della lista usato per dimostrare il concetto di
 * riferimento fluttuante (dangling reference) */
 
#define BYTE_IN_MBYTE 1000000.0
/* numero di byte in 1 megabyte: notare che deve essere espresso in formato
 * float, ovvero con .0 in coda, per evitare che la divisione eseguita usando
 * questo parametro diventi una divisione intera. 
 * Notare che usare come fattore di conversione 1000*1000 = 10^6 è una
 * convenzione utilizzata solo dai venditoridi memorie di massa (che in questo
 * modo sembrano più capienti): in informatica di solito si utilizza invece il
 * fattore 1024*1024 = 2^20. */

typedef char TipoPayload[DIM];
/* tipo di dato usato per definire la dimensione in byte dell'elemento della
 * lista */

typedef struct E
{
  int Posizione;
  /* questo campo contiene la posizione dell'elemento nella lista */
  TipoPayload Payload;
  /* questo campo serve ad aumentare la dimensione dell'elemento */
  struct E *Prossimo;
} ElemLista;
/* elemento della lista dinamica */

typedef enum {false, true} boolean;

void StampaLista(ElemLista *TestaLista);
/* stampa il contenuto della lista con testa TestaLista; usata solo per debugging */

int main()
{
  ElemLista *Testa;
  /* testa della lista */
  ElemLista *Nuovo;
  /* punta a un nuovo elemento da aggiungere alla lista */
  ElemLista *DaDeallocare;
  /* punta a un elemento della lista da deallocare */
  int Aggiunti;
  /* numero di elementi aggiunti alla lista; se negativo, numero di elementi
   * eliminati dalla lista */
  unsigned long NumByte;
  /* numero di byte di RAM aggiunti o sottratti alla RAM utilizzata; il valore
   * di NumByte e' sempre nullo o positivo */
  int DaAggiungere;
  /* numero di elementi da aggiungere alla lista; se negativo, numero di
   * elementi da eliminare dalla lista */
  int Totali;
  /* numero di elementi contenuti nella lista */
  ElemLista *ElementoTest;
  /* punta ad un elemento specifico della lista, quello in posizione
   * POS_TEST all'interno della lista; qualora tale elemento sia stato
   * successivamente deallocato, ElementoTest rappresenta un "dangling
   * reference" (riferimento fluttuante): un puntatore che punta ad un dato
   * che nel frattempo e' stato distrutto (ovvero: il programma non utilizza
   * piu' la zona di memoria che conteneva il dato e l'ha rimessa a
   * disposizione del sistema */
  char Risposta;
  /* risposta dell'utente ad una richiesta del programma */
  TipoPayload ArrayDiProva;
  /* array di caratteri da inserire in ogni elemento della lista; limitarsi ad
   * allocare l'elemento lasciando l'array vuoto, infatti, non produce il
   * consumo di memoria previsto a causa delle ottimizzazioni nella gestione
   * della RAM eseguite da compilatore e/o sistema operativo. Per questa 
   * ragione questo array viene riempito di caratteri "utili" (asterischi) e
   * verra' copiato in ogni nuovo elemento della lista dinamica. */
   int ScorriArray;
   /* usato per esplorare ArrayDiProva */
   float Mbytes;
   /* valore in Mbytes corrispondente a un valore in byte */
   boolean GeneraGarbage;
   /* se vale true le operazioni (necessarie) di deallocazione della memoria
    * all'atto della eliminazione di un elemento dalla lista dinamica vengono
    * disabilitate per illustrare il meccanismo di creazione di "garbage".
    * USARE CON CAUTELA! Se la quantità di "garbage" generata è sufficiente a
    * riempire la RAM, il calcolatore si blocca. */

  printf("\n\nQuesto programma illustra l'uso della memoria dinamica.");
  printf("\nVuoi abilitare la generazione di \"garbage\"? [s/n] (Usare con cautela!) ");
  scanf("%c", &Risposta);
  if ('s' == Risposta)
  {
    GeneraGarbage = true;
  }
  else
  {
    GeneraGarbage = false;
  }

  for (ScorriArray = 0; ScorriArray < DIM; ++ScorriArray)
  {
    ArrayDiProva[ScorriArray] = '*';
  }

  Totali = 0;
  Testa = NULL;
  printf("\n\nLa lista e' vuota.");
  printf("\n\nIl campo Posizione occupa %lu byte.", sizeof(int));
  printf("\nIl campo Payload occupa %lu byte.", sizeof(TipoPayload));
  printf("\nIl campo Prossimo occupa %lu byte.", sizeof(struct E*));
  Mbytes = sizeof(ElemLista)/BYTE_IN_MBYTE;
  printf("\nCiascun elemento aggiunto alla lista occupera' %lu byte, ovvero %.1f Mbyte", sizeof(ElemLista), Mbytes);
  /* nota: sizeof restituisce un long unsigned int: il codice di conversione
   * corrispondente nella stringa di formattazione di printf è "%lu" */
  ElementoTest = NULL;
  
  do
  {
    printf("\n\nQuanti elementi vuoi aggiungere alla lista? (<0 elimina elementi)  ");
    scanf("%d", &DaAggiungere);
    
    if (DaAggiungere >= 0)
    {
      /*** aggiunge elementi in testa alla lista ***/
      NumByte = 0;
      
      for (Aggiunti = 1; Aggiunti <= DaAggiungere; ++Aggiunti)
      {
        /*** inserimento di un nuovo elemento in testa alla lista ***/
        Nuovo = malloc(sizeof(ElemLista));
        printf("\n<<Eseguita chiamata a malloc>>");
        NumByte = NumByte + sizeof(ElemLista);
        Nuovo-> Posizione = Totali + 1;
        strcpy(Nuovo->Payload, ArrayDiProva);
        Nuovo->Prossimo = Testa;
        Testa = Nuovo;
        ++Totali;
        printf(" Aggiunto elemento %d di %d.", Aggiunti, DaAggiungere);
        
        if (POS_TEST == Totali)
        {
          ElementoTest = Nuovo;
          printf(" Individuato %d-esimo elemento della lista.", POS_TEST);
        }
      }
      Mbytes = NumByte/BYTE_IN_MBYTE;
      printf("\n\nUsati %lu byte di memoria RAM, ovvero %.1f Mbyte.", NumByte, Mbytes);
      Mbytes = Totali*sizeof(ElemLista)/BYTE_IN_MBYTE;
      printf("\nOra la lista ha %d elementi e occupa %lu byte di RAM, ovvero %.1f Mbyte.", Totali, Totali*sizeof(ElemLista), Mbytes);
      
      #ifdef DEBUG      
      StampaLista(Testa);
      #endif
    }
    else
    {
      /*** elimina elementi dalla testa della lista ***/
      NumByte = 0;

      for (Aggiunti = -1; Aggiunti >= DaAggiungere; --Aggiunti)
      {
        /*** elimina il primo elemento della lista ***/
        DaDeallocare = Testa;
        if (NULL != DaDeallocare)
        /* se la lista contiene almeno un elemento */
        {
          Testa = Testa->Prossimo;
          --Totali;
          NumByte = NumByte + sizeof(ElemLista);

          printf("\nElemento %d di %d rimosso dalla lista.", -1*Aggiunti, -1*DaAggiungere); 
          if (true != GeneraGarbage)
          {
            free(DaDeallocare);
            printf(" <<Eseguita chiamata a free>>");
          }
          /* ************************* ATTENZIONE *************************
           * Se non eseguita, la chiamata a free non dealloca gli elementi
           * eliminati dalla lista. Cio' significa che questi elementi, ora
           * diventati inaccessibili (infatti si accedeva ad essi tramite
           * la lista), rimangono in memoria RAM fino alla chiusura del 
           * programma e ne occupano inutilmente una parte.
           * Questi elementi non deallocati sono un esempio di "garbage".
           *****************************************************************/

        }
      }
      Mbytes = NumByte/BYTE_IN_MBYTE;
      printf("\n\n(se eseguite) Le deallocazioni hanno liberato %lu byte di memoria RAM, ovvero %.1f Mbyte.", NumByte, Mbytes);
      printf("\nOra la lista ha %d elementi e occupa %lu byte di RAM, ovvero %lu Mbyte.", Totali, Totali*sizeof(ElemLista), Totali*sizeof(ElemLista)/(1024*1024));

      #ifdef DEBUG      
      StampaLista(Testa);
      #endif
    }
    
  } while (Totali > 0);
  
  printf("\n\nLa lista e' vuota.");
    
  printf("\n\nVuoi leggere il campo Posizione dell'elemento in posizione %d? [s/n]  ", POS_TEST);
  scanf("%*c%c", &Risposta);
  if ('s' == Risposta)
  {
    printf("\nIl campo Posizione dell'elemento vale %d.", ElementoTest->Posizione);
    /* ************************* ATTENZIONE *************************
     * Quando l'elemento puntato da ElementoTest e' stato deallocato, 
     * ElementoTest risulta essere un "dangling reference". In questo caso
     * la lettura del dato puntato dalla variabile ElementoTest provoca
     * errori. In genere questi assumono la forma di un blocco del programma
     * con un errore di "segmentation fault", ovvero accesso indebito ad aree
     * di memoria non assegnate al programma.
     * In generale, è possibile che nell'area puntata da un "dangling reference"
     * siano nel frattempo stati allocati altri dati di proprieta' del programma
     * stesso (allocati dinamicamente con malloc). In questo caso andando a
     * leggere il dato puntato dal riferimento fluttuante non si ottiene un
     * errore di "segmentation fault" ma il valore letto risulta anomalo
     * perché sovrascritto da dati scorrelati da quello originale. 
     *****************************************************************/
  }
  
  printf("\n\n");
  return 0;
}


void StampaLista(ElemLista *TestaLista)
{
  ElemLista *Corrente;

  printf("\n\nCampo Posizione degli elementi attualmente nella lista:\n{ ");
  
  Corrente = TestaLista;
  
  while (NULL != Corrente)
  {
    printf("%d ", Corrente->Posizione);
    Corrente = Corrente->Prossimo;
  }
  
  printf("}");
}
