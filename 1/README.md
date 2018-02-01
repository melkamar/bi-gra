# Jarn� �klid

Ukl�zec� firma Fiala-Ivan-T��ska se chyst� na jarn� �klid cel�ho m�sta. Bohu�el p�edchoz� sez�na a neblah� finan�n� situace se dost podepsala na jejich vozov�m parku a z�stalo jim jen jedin� star� k�ehk� vozidlo, kter� takov� �klid zvl�dne, ne� se tak� rozpadne. Je tedy t�eba vozidlo maxim�ln� �et�it a chovat se k n�mu s l�skou.

M�sto je soustava ulic a k�i�ovatek, ka�d� k�i�ovatka je spojena s dal�� k�i�ovatkou nejv��e jednou ulic�. Vozidlo m��e proj�d�t ulice libovoln�m sm�rem, na vy�i�t�n� mu sta�� jeden pr�jezd.

�kolem je rozvrhnout trasu m�stem tak, aby vozidlo vy�istilo ka�dou ulici m�sta a z�rove� neproj�d�lo ��dnou ulic� v�cekr�t. �klid kon�� ve chv�li, kdy je vy�i�t�na posledn� ulice v m�st�. V�stupem programu je takov� po�ad� k�i�ovatek, v jak�m je m� vozidlo proj�d�t tak, aby projelo ka�dou ulic� pr�v� jednou. Pokud takov� cesta nen� pro zadan� m�sto mo�n�, hled�n� skon�� ne�sp�chem. Pozor na to, �e vozidlo nemus� za��t a skon�it ve stejn� k�i�ovatce.

M�sto ��d� nezodpov�dn� starosta Petr Furtpr��, kter� ob�as uzav�e n�kter� ulice kv�li po��d�n� r�zn�ch akc� a tak nen� zaru�ena dostupnost v�ech ��st� m�sta.

�e�en� realizujte formou funkce trasa s rozhran�m n�e. Funkce m� parametrem dv� jm�na soubor�: zdrojov� a c�lov�. Funkce �te zdrojov� soubor a zapisuje v�slednou trasu do c�lov�ho souboru. N�vratovou hodnotou funkce je TRUE V p��pad� �sp�n�ho nalezen� trasy m�stem a FALSE V p��pad� nenalezen� trasy m�stem.

## Form�t vstupu
K�i�ovatky jsou o��slov�ny p�irozen�mi ��sly od 0 do N-1. Na vstupu dostanete na prvn�m ��dku po�et k�i�ovatek a po�et ulic odd�len� mezerou, n�sledovan� (na dal��ch ��dc�ch) seznamem dvojic k�i�ovatek, mezi kter�mi vede ulice. Ka�d� ��dek seznamu obsahuje 2 ��sla odd�len� mezerou.
```
  N M
    (kde N je po�et k�i�ovatek a M je po�et ulic)
  DVOJICE
    (dvojice index� k�i�ovatek, mezi kter�mi je ulice. Po�et ��dk� s dvojicemi je M)
```    
Pozn�mka: M��ete se spolehnout na to, �e vstup je zad�n korektn�

## Form�t v�stupu
Trasa, po kter� m� vozidlo jet ve form�tu SEZNAM, kde prvn� ��dek obsahuje po�et prvk� v�sledn�ho seznamu. Ka�d� dal�� ��dek obsahuje pr�v� jedno ��slo k�i�ovatky. Pokud takov� trasa nelze vytvo�it, n�vratov� hodnota funkce je FALSE.
```
  N
    (kde N je po�et k�i�ovatek trasy)
  T
    (indexy k�i�ovatek, kudy vede trasa)
```
Pozn�mka: limity - maxim�ln� 20 000 k�i�ovatek, 65 000 cest

## P��klad vstupu a v�stupu
### Vstup:

```
     4 5
     0 1
     1 2
     1 3
     3 2
     3 0
```

```
 V�stup:
     6
     3
     1
     0
     3 
     2
     1
```
     
P�i implementaci m�te k dispozici datov� struktury z STL, viz uk�zka. Struktury z STL pou��t m��ete, ale nemus�te.

```c++
#ifndef __PROGTEST__
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <list>
#include <stdint.h>

using namespace std;
#endif /* __PROGTEST__ */

bool trasa( const char * inFile, const char * outFile )
 {
   // mandatory, todo
 }


#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
 {
   // tests
   return 0;
 }
#endif /* __PROGTEST__ */
```