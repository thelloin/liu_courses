/**********************************************************************
 *  Kn�cka l�senord readme.txt
 **********************************************************************/

 Ungef�rligt antal timmar spenderade p� labben (valfritt): 13 timmar

/**********************************************************************
 *  Ge en h�gniv�beskrivning av ditt program decrypt.c.
 **********************************************************************/

Programmet delar den givna tabellen i tv� delar och ber�knar sedan alla
m�jliga delsummor av dessa som sedan sparas i varsin unordered_map.
En av hashtabellerna itereras d�r det kontrolleras om det krypterade
l�senordet minus aktuell nyckel finns som nyckel i den andra hashtabellen.
Skulle det vara s� har vi en m�jlig l�sning.


/**********************************************************************
 *  Beskriv symboltabellen du anv�nt f�r decrypt.c.
 **********************************************************************/

Som nyckel anv�nder vi klassen Key d�r v�rdet �r en lista av listor med heltal
d�r heltalen representerar index i tabellen som ska summeras f�r att f� Key.

/**********************************************************************
 *  Ge de dekrypterade versionerna av alla l�senord med 8 och 10
 *  bokst�ver i uppgiften du lyckades kn�ca med DIN kod.
 **********************************************************************/


8 bokst�ver         10 bokst�ver
-----------         ------------
congrats		completely
youfound		unbreakabl
theright		cryptogram
solution		ormaybenot

/****************************************************************************
 *  Hur l�ng tid anv�nder brute.c f�r att kn�cka l�senord av en viss storlek?
 *  Ge en uppskattning markerad med en asterisk om det tar l�ngre tid �n vad
 *  du orkar v�nta. Ge en kort motivering f�r dina uppskattningar.
 ***************************************************************************/


Char     Brute     
--------------
 4	0 sekunder
 5	25 sekunder
 6	1091 sekunder
 8	*, 2017259 uppskattad tid, �kar med en faktor 43


/******************************************************************************
 *  Hur l�ng tid anv�nder decrypt.c f�r att kn�cka l�senord av en viss storlek?
 *  Hur mycket minne anv�nder programmet?
 *  Ge en uppskattning markerad med en asterisk om det tar l�ngre tid �n vad
 *  du orkar v�nta. Ge en kort motivering f�r dina uppskattningar.
 ******************************************************************************/

Char    Tid (sekunder)    Minne (bytes)
----------------------------------------
6	0		* 11000
8	19		410000
10	806		15840909 
12	*, 39000	* 569G

* uppskattad tid, �kar med en faktor 7

/*************************************************************************
 * Hur m�nga operationer anv�nder brute.c f�r ett N-bitars l�senord?
 * Hur m�nga operationer anv�nder din decrypt.c f�r ett N-bitars l�senord?
 * Anv�nd ordo-notation.
 *************************************************************************/

brute.c		--> O(2^N)
decrypt.c 	--> O(2^(N/2))
