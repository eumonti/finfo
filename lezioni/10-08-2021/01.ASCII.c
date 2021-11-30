#include <stdio.h>

/* programma che illustra la corrispondenza tra i valori interi associati ai
 * dati di tipo char e il codice ASCII */

int main()
{
  char ContaCaratteri;
  
  for (ContaCaratteri = 'A'; ContaCaratteri <= 'Z'; ++ContaCaratteri)
  {
    printf("\nAl carattere '%c' corrisponde il valore intero %d", ContaCaratteri, ContaCaratteri);
  }

  printf("\n");

  for (ContaCaratteri = 'a'; ContaCaratteri <= 'z'; ++ContaCaratteri)
  {
    printf("\nAl carattere '%c' corrisponde il valore intero %d", ContaCaratteri, ContaCaratteri);
  }

  printf("\n\nAl carattere '\\n' (newline) corrisponde il valore intero %d", '\n');
  printf("\n\nAl carattere '\\0' (terminatore di stringa) corrisponde il valore intero %d", '\0');
  
  printf("\n");

  return 0;
}


/* log di esecuzione:

Al carattere 'A' corrisponde il valore intero 65
Al carattere 'B' corrisponde il valore intero 66
Al carattere 'C' corrisponde il valore intero 67
Al carattere 'D' corrisponde il valore intero 68
Al carattere 'E' corrisponde il valore intero 69
Al carattere 'F' corrisponde il valore intero 70
Al carattere 'G' corrisponde il valore intero 71
Al carattere 'H' corrisponde il valore intero 72
Al carattere 'I' corrisponde il valore intero 73
Al carattere 'J' corrisponde il valore intero 74
Al carattere 'K' corrisponde il valore intero 75
Al carattere 'L' corrisponde il valore intero 76
Al carattere 'M' corrisponde il valore intero 77
Al carattere 'N' corrisponde il valore intero 78
Al carattere 'O' corrisponde il valore intero 79
Al carattere 'P' corrisponde il valore intero 80
Al carattere 'Q' corrisponde il valore intero 81
Al carattere 'R' corrisponde il valore intero 82
Al carattere 'S' corrisponde il valore intero 83
Al carattere 'T' corrisponde il valore intero 84
Al carattere 'U' corrisponde il valore intero 85
Al carattere 'V' corrisponde il valore intero 86
Al carattere 'W' corrisponde il valore intero 87
Al carattere 'X' corrisponde il valore intero 88
Al carattere 'Y' corrisponde il valore intero 89
Al carattere 'Z' corrisponde il valore intero 90

Al carattere 'a' corrisponde il valore intero 97
Al carattere 'b' corrisponde il valore intero 98
Al carattere 'c' corrisponde il valore intero 99
Al carattere 'd' corrisponde il valore intero 100
Al carattere 'e' corrisponde il valore intero 101
Al carattere 'f' corrisponde il valore intero 102
Al carattere 'g' corrisponde il valore intero 103
Al carattere 'h' corrisponde il valore intero 104
Al carattere 'i' corrisponde il valore intero 105
Al carattere 'j' corrisponde il valore intero 106
Al carattere 'k' corrisponde il valore intero 107
Al carattere 'l' corrisponde il valore intero 108
Al carattere 'm' corrisponde il valore intero 109
Al carattere 'n' corrisponde il valore intero 110
Al carattere 'o' corrisponde il valore intero 111
Al carattere 'p' corrisponde il valore intero 112
Al carattere 'q' corrisponde il valore intero 113
Al carattere 'r' corrisponde il valore intero 114
Al carattere 's' corrisponde il valore intero 115
Al carattere 't' corrisponde il valore intero 116
Al carattere 'u' corrisponde il valore intero 117
Al carattere 'v' corrisponde il valore intero 118
Al carattere 'w' corrisponde il valore intero 119
Al carattere 'x' corrisponde il valore intero 120
Al carattere 'y' corrisponde il valore intero 121
Al carattere 'z' corrisponde il valore intero 122

Al carattere '\n' (newline) corrisponde il valore intero 10

Al carattere '\0' (terminatore di stringa) corrisponde il valore intero 0

*/
