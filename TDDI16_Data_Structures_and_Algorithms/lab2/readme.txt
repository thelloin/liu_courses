/**********************************************************************
 *  Knäcka lösenord readme.txt
 **********************************************************************/

 Ungefärligt antal timmar spenderade på labben (valfritt): 13 timmar

/**********************************************************************
 *  Ge en högnivåbeskrivning av ditt program decrypt.c.
 **********************************************************************/

Programmet delar den givna tabellen i två delar och beräknar sedan alla
möjliga delsummor av dessa som sedan sparas i varsin unordered_map.
En av hashtabellerna itereras där det kontrolleras om det krypterade
lösenordet minus aktuell nyckel finns som nyckel i den andra hashtabellen.
Skulle det vara så har vi en möjlig lösning.


/**********************************************************************
 *  Beskriv symboltabellen du använt för decrypt.c.
 **********************************************************************/

Som nyckel använder vi klassen Key där värdet är en lista av listor med heltal
där heltalen representerar index i tabellen som ska summeras för att få Key.

/**********************************************************************
 *  Ge de dekrypterade versionerna av alla lösenord med 8 och 10
 *  bokstäver i uppgiften du lyckades knäca med DIN kod.
 **********************************************************************/


8 bokstäver         10 bokstäver
-----------         ------------
congrats		completely
youfound		unbreakabl
theright		cryptogram
solution		ormaybenot

/****************************************************************************
 *  Hur lång tid använder brute.c för att knäcka lösenord av en viss storlek?
 *  Ge en uppskattning markerad med en asterisk om det tar längre tid än vad
 *  du orkar vänta. Ge en kort motivering för dina uppskattningar.
 ***************************************************************************/


Char     Brute     
--------------
 4	0 sekunder
 5	25 sekunder
 6	1091 sekunder
 8	*, 2017259 uppskattad tid, ökar med en faktor 43


/******************************************************************************
 *  Hur lång tid använder decrypt.c för att knäcka lösenord av en viss storlek?
 *  Hur mycket minne använder programmet?
 *  Ge en uppskattning markerad med en asterisk om det tar längre tid än vad
 *  du orkar vänta. Ge en kort motivering för dina uppskattningar.
 ******************************************************************************/

Char    Tid (sekunder)    Minne (bytes)
----------------------------------------
6	0		* 11000
8	19		410000
10	806		15840909 
12	*, 39000	* 569G

* uppskattad tid, ökar med en faktor 7

/*************************************************************************
 * Hur många operationer använder brute.c för ett N-bitars lösenord?
 * Hur många operationer använder din decrypt.c för ett N-bitars lösenord?
 * Använd ordo-notation.
 *************************************************************************/

brute.c		--> O(2^N)
decrypt.c 	--> O(2^(N/2))
