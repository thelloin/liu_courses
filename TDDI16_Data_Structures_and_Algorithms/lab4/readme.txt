/**********************************************************************
 *  Mönsterigenkänning readme.txt
 **********************************************************************/

 Ungefärligt antal timmar spenderade på labben (valfritt):

/**********************************************************************
 *  Empirisk    Fyll i tabellen nedan med riktiga körtider i sekunder
 *  analys      när det känns vettigt att vänta på hela beräkningen.
 *              Ge uppskattningar av körtiden i övriga fall.
 *
 **********************************************************************/
    
      N       brute       sortering
 ----------------------------------
    150		48		10
    200		96		20
    300		314		39
    400		741		65
    800		5783		215
   1600		46672		913
   3200		364041*		3862
   6400		2839524*	16820
  12800		22148290*	70950

  * Uppskattade tider, ökar med en faktor ~7.8


/**********************************************************************
 *  Teoretisk   Ge ordo-uttryck för värstafallstiden för programmen som
 *  analys      en funktion av N. Ge en kort motivering.
 *
 **********************************************************************/

Brute: n^3 eller n^4

Sortering: n^2*log^2(n)
stable_sort utför upp till n*log^2(n) jämförelser och detta kommer utföras n gånger
