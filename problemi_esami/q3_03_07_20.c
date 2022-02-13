/*
Un testo è rappresentato come una stringa di di al più 1000 caratteri compreso il carattere di terminazione.
Si scriva un sottoprogramma ricorsivo che riceve un testo e una breve stringa di al più 10 caratteri
(compreso il carattere di terminazione) distinti tra loro, e restituisce 1 se ciascun carattere della stringa è
presente nel testo (non necessariamente nello stesso ordine), 0 altrimenti.
Attenzione: il sottoprogramma deve operare scorrendo il testo una sola volta, senza ricominciare dall'inizio
del testo la ricerca di un nuovo carattere della stringa.
*/

#include <stdio.h>

#define LEN_TESTO 1000
#define LEN_STRINGA 10

int chiCercaTrova(char *testo, char *stringa)
{
  int i;
  char tmp;

  if (*stringa == '\0')
    return 1;
  if (*testo == '\0')
    return 0;

  i = 0;
  while (stringa[i] != '\0')
  {
    if (stringa[i] == *testo)
    {
      // Considero altro elemento della stringa, non mi interessa più di questo.
      // Metto questo elemento in testa
      tmp = stringa[i];
      stringa[i] = *stringa;
      *stringa = stringa[i];
      return chiCercaTrova(testo + 1, stringa + 1);
    }
    i++;
  }
  return chiCercaTrova(testo + 1, stringa);
}

int TuttiPresenti(char *T, char *S)
{
  int i;
  char temp;

  if (*S == '\0')
    return 1;
  if (*T == '\0')
    return 0;

  i = 0;
  while (S[i] != '\0' && S[i] != *T)
    i++;
  if (S[i] == *T)
  {
    temp = S[i];
    S[i] = *S;
    *S = temp;
    return TuttiPresenti(T + 1, S + 1);
  }
  else
    return TuttiPresenti(T + 1, S);
}

int cerca2(char *testo, char *stringa)
{
  int i;
  char tmp;

  if (*stringa == '\0')
    return 1;
  if (*testo == '\0')
    return 0;
  i = 0;
  while (stringa[i] != '\0' && stringa[i] != *testo)
    i++;
  if (stringa[i] == *testo)
  {
    tmp = stringa[i];
    stringa[i] = *stringa;
    *stringa = tmp;
    return cerca2(testo + 1, stringa + 1);
  }
  return cerca2(testo + 1, stringa);
}

int cerca(char testo[1000], char stringa[10])
{
  int i;
  if (*stringa == '\0')
    return 1;

  i = 0;
  while (testo[i] != '\0')
  {
    if (*stringa == testo[i])
      return cerca(testo, stringa + 1);
    i++;
  }
  return 0;
}

int main()
{
  char testo[LEN_TESTO] = "aabbcceesukaeddd";
  // char testo[LEN_TESTO], stringa[LEN_STRINGA];
  // testo = "aabbcceeeddd"; // Così non funziona perchè diventa una string literal non modificabile
  char stringa[LEN_STRINGA] = "acdeb";
  // stringa = "abcde";
  printf("%d\n", chiCercaTrova(testo, stringa));
}