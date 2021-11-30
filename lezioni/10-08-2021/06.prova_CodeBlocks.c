#include <stdio.h>
#define LUNG_STRINGA 5
#define LUNG_ARRAY_VITTIMA 50

int main()
{
    char InputUtenteChar;
    /* contiene un carattere inserito dall'utente */
    char InputUtenteStringa[LUNG_STRINGA];
    /* contiene una stringa inserita dall'utente del programma */
    char ArrayVittima[LUNG_ARRAY_VITTIMA] = "012345678901234567890123456789";
    /* usato per illustrare i danni che scanf può produrre se usata (male) per leggere stringhe:
       se durante la lettura di InputUtenteStringa l'utente inserisce un numero di caratteri
       superiore a quello che l'array InputUtenteStringa è in grado di contenere, scanf sovrascrive
       la parte iniziale di ArrayVittima con i caratteri in eccesso */

    printf("\nProva della lettura di singoli caratteri con scanf:\nil programma chiede caratteri all'utente e li stampa, fino a che riceve '#'.\n\n");
    do
    {
        scanf("%c%*c", &InputUtenteChar);
        printf("E' stato inserito '%c'\n\n", InputUtenteChar);
    } while ('#' != InputUtenteChar);

    printf("\nIn questo momento la variabile ArrayVittima vale \n\"%s\".", ArrayVittima);

    printf("\n\nProva della lettura di stringhe con scanf:\nil programma chiede all'utente di inserire una stringa, poi la stampa.\n\n");
    printf("Inserire una stringa composta al massimo da %d caratteri: ", LUNG_STRINGA-1);
    scanf("%s", InputUtenteStringa);

    printf("\nLa stringa inserita è \"%s\"", InputUtenteStringa);

    printf("\n\nIn questo momento la variabilee ArrayVittima vale \n\"%s\".\n\n", ArrayVittima);

    return 0;
}
