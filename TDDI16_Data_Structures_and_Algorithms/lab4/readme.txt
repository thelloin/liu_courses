/**********************************************************************
 *  M�nsterigenk�nning readme.txt
 **********************************************************************/

 Ungef�rligt antal timmar spenderade p� labben (valfritt):

/**********************************************************************
 *  Empirisk    Fyll i tabellen nedan med riktiga k�rtider i sekunder
 *  analys      n�r det k�nns vettigt att v�nta p� hela ber�kningen.
 *              Ge uppskattningar av k�rtiden i �vriga fall.
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

  * Uppskattade tider, �kar med en faktor ~7.8


/**********************************************************************
 *  Teoretisk   Ge ordo-uttryck f�r v�rstafallstiden f�r programmen som
 *  analys      en funktion av N. Ge en kort motivering.
 *
 **********************************************************************/

Brute: n^3 eller n^4

Sortering: n^2*log^2(n)
stable_sort utf�r upp till n*log^2(n) j�mf�relser och detta kommer utf�ras n g�nger
