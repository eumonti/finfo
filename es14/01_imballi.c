/* 
 * Corso di Fondamenti di Informatica
 * Esercizio:
 * tema d'esame
 */

/*
Si definisca il tipo Imballo, il cui scopo e' descrivere uno dei colli in giacenza in un ufficio postale. Imballo e' una struttura con due campi: un array di 20 caratteri Descrizione (che indica il contenuto dell'imballo; un '\0' indica la fine della stringa) ed un campo float Peso.
Si scriva una funzione, ClassificaImballi, legge da disco il file binario Input, contenente uno o più dati di tipo Imballo, e produce due nuovi file binari chiamati Pesanti e Leggeri, anch'essi contenenti dati di tipo Imballo. Ciascun dato letto da Input va copiato in Pesanti oppure in Leggeri a seconda che il suo campo Peso sia maggiore, oppure minore o uguale, di un valore Soglia, fornito alla funzione tramite un parametro di ingresso. ClassificaImballi crea anche un file di testo, Rapporto.txt, che contiene una riga con la forma "[ D, P ]" per ciascun dato letto da Input, dove D e' il contenuto del campo Descrizione e P e' il contenuto del campo Peso.
La funzione ClassificaImballi restituisce il numero di dati letti da Input, oppure EOF se risulta impossibile aprire il file Input; altri tipi di errore non vanno gestiti. Non e' necessario occuparsi della creazione del file Input.
*/

#define LUNGHEZZA_DESCRIZIONE 20

typedef struct
{
  char descrizione[LUNGHEZZA_DESCRIZIONE];
  float peso;
} Imballo;