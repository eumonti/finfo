/* 
 * Corso di Fondamenti di Informatica
 * Esercizio:
 * calcolo della velocita' media nelle varie tappe di un viaggio
 */

/* Programma per calcolare le velocita' medie tenute nelle varie tappe di un
 * viaggio e nell'intero viaggio. Vengono chieste all'utente le distanze tra le
 * tappe e i tempi di percorrenza relativi; il programma calcola le velocita'
 * medie e fa un controllo sulla consistenza dei dati, eventualmente segnalando
 * valori sospetti. */

#include <stdio.h>

#define MAX_NUM_TAPPE 100
/* massimo numero di tappe ammesse per il viaggio, inclusi partenza e arrivo */
#define MIN_VELOCITA_MEDIA 1
#define MAX_VELOCITA_MEDIA 50
/* massima e minima velocita' [in km/h] ammesse per tappa: se una delle 
 * velocita'calcolate non e' compresa nell'intervallo tra di esse, viene
 * segnalato un probabile errore nei dati sulle tappe */

int main(void)
{
	int LunghezzaTappe[MAX_NUM_TAPPE];
	/* l'elemento di indice N di LunghezzaTappe rappresenta la lunghezza [in km]
	 * della tappa (N+1)-esima, ovvero la distanza tra il punto di sosta N-esimo
	 * ed il punto di sosta (N+1)-esimo */
	int DurataTappe[MAX_NUM_TAPPE];
	/* l'elemento di indice N di DurataTappe rappresenta la durata [in minuti]
	 * della tappa (N+1)-esima, ovvero il tempo impiegato per viaggiare dal punto
	 * di sosta N-esimo al punto di sosta (N+1)-esimo */
	int NumeroTappe;
	/* numero di tappe di cui si compone effettivamente il viaggio (dunque il 
	 * numero di punti di sosta e' pari a NumeroTappe+1) */
	int TappaCorrente;
	/* usato per scorrere gli array */
	int Ore, Minuti;
	/* contengono la durata di una tappa, espressa in ore e minuti */
	float VelocitaMediaTappa;
	/* velocita' media [in km/h] calcolata per una data tappa del viaggio */
	float VelocitaMediaViaggio;
	/* velocita' media [in km/h] calcolata per l'intero viaggio */
	 
	/*** input dei dati sul viaggio: ***/
	printf("\nInserisci i dati sul tuo viaggio.\nNumero delle tappe (min 1, max MAX_NUM_TAPPE)?  ");
	scanf("%d",	&NumeroTappe);
	
	TappaCorrente=0;
	while (TappaCorrente < NumeroTappe)
	/* fino a che ci sono nuove tappe da memorizzare */
	{
		printf("Lunghezza della tappa n.%d [km]?  ", TappaCorrente+1);
		scanf("%d", &LunghezzaTappe[TappaCorrente]);
		
		printf("Durata della tappa n.%d [ore:minuti]?  ", TappaCorrente+1);
		scanf("%d:%d", &Ore, &Minuti);
		DurataTappe[TappaCorrente] = Minuti + 60*Ore;
		
		++TappaCorrente;
	}

	/*** calcolo e di output delle velocita' medie ***/
	VelocitaMediaViaggio = 0;
	TappaCorrente=0;

	while (TappaCorrente < NumeroTappe)
	/* fino a che ci sono nuove tappe da analizzare */
	{
		VelocitaMediaTappa =
		60*LunghezzaTappe[TappaCorrente]/DurataTappe[TappaCorrente];

		printf("\nLa velocita' media nella tappa n.%d e' stata di %f km/h", TappaCorrente+1,
		VelocitaMediaTappa);

		if ((VelocitaMediaTappa > MAX_VELOCITA_MEDIA) ||
        (VelocitaMediaTappa < MIN_VELOCITA_MEDIA))
		{
			printf("\n*************** ATTENZIONE: ****************");
			printf("\n*******velocita' fuori range ammesso********");
			printf("\n******* controllare i dati inseriti *******");
		}			
		
		VelocitaMediaViaggio = VelocitaMediaViaggio +
		VelocitaMediaTappa/NumeroTappe;
			
		++TappaCorrente;
	}
	
	printf("\nLa velocita' media nell'intero viaggio e' stata di %f km/h\n\n",
	VelocitaMediaViaggio);

	return (0); 
 }
 
 
/* ESERCIZIO.
 * In questo programma viene usato un metodo molto elementare (e per niente
 * corretto) per calcolare la velocita' media nell'intero viaggio: viene
 * infatti usata la media aritmetica tra le velocita' medie nelle singole
 * tappe. Il metodo corretto prevede di calcolare la velocita' media come 
 * rapporto tra la lunghezza totale del viaggio e la durata totale del viaggio.
 * Modificare il programma per implementare questo nuovo metodo di calcolo. */
 
