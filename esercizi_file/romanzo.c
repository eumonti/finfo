/* Sia dato un file di testo, "Romanzo.txt", contenente il testo completo di
 * un romanzo. Il romanzo è diviso in capitoli e l'inizio di ogni capitolo
 * (incluso il primo) è segnalato dalla presenza del carattere '@'.
 * Il contenuto di Romanzo.txt va copiato in un secondo file di testo,
 * RomanzoFormattato.txt, aggiungendo all'inizio di ciascun capitolo tre
 * righe vuote, poi la frase "Capitolo N" (dove N è il numero del capitolo
 * corrente) ed infine un'altra riga vuota.
 * Successivamente in RomanzoFormattato va inserito il testo del capitolo,
 * modificandone i caratteri della sola prima parola nel modo seguente:
 * - se il carattere e' una lettera maiuscola, va trasformata in minuscola;
 * - se il carattere e' una lettera minuscola, va trasformata in maiuscola;
 * - se il carattere non e' una lettera esso va lasciato non modificato.
 * E' consentito l'uso della libreria ctype.h.
 * Il programma deve stampare un messaggio di errore ogniqualvolta si
 * verifica un di errore di apertura o di chiusura file.
 */
#include <stdio.h>

int main()
{
  FILE *fOrigine, *fDest;
  char c;
  int firstWord;
  int currChapter;

  fOrigine = fopen("file-romanzo/Romanzo.txt", "r");
  fDest = fopen("file-romanzo/RomanzoFormattato2.txt", "w");

  currChapter = 1;
  c = fgetc(fOrigine);
  while (c != EOF)
  {
    if (c == '@')
    {
      firstWord = 1;
      fprintf(fDest, "\n\n\nCapitolo %d\n\n", currChapter);
    }
    else
    {
      if (firstWord)
      {
        if (c >= 'a' && c <= 'z') // Minuscola
          c = 'A' + (c - 'a');
        else if (c >= 'A' && c <= 'Z') // Maiuscola
          c = 'a' + (c - 'A');
        firstWord = 0;
      }
      else
      {
        fputc(c, fDest);
      }
    }
    c = fgetc(fOrigine);
  }

  fclose(fOrigine);
  fclose(fDest);
}