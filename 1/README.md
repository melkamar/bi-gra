# Jarní úklid

Uklízecí firma Fiala-Ivan-Tøíska se chystá na jarní úklid celého mìsta. Bohužel pøedchozí sezóna a neblahá finanèní situace se dost podepsala na jejich vozovém parku a zùstalo jim jen jediné staré køehké vozidlo, které takový úklid zvládne, než se také rozpadne. Je tedy tøeba vozidlo maximálnì šetøit a chovat se k nìmu s láskou.

Mìsto je soustava ulic a køižovatek, každá køižovatka je spojena s další køižovatkou nejvýše jednou ulicí. Vozidlo mùže projíždìt ulice libovolným smìrem, na vyèištìní mu staèí jeden prùjezd.

Úkolem je rozvrhnout trasu mìstem tak, aby vozidlo vyèistilo každou ulici mìsta a zároveò neprojíždìlo žádnou ulicí vícekrát. Úklid konèí ve chvíli, kdy je vyèištìna poslední ulice v mìstì. Výstupem programu je takové poøadí køižovatek, v jakém je má vozidlo projíždìt tak, aby projelo každou ulicí právì jednou. Pokud taková cesta není pro zadané mìsto možná, hledání skonèí neúspìchem. Pozor na to, že vozidlo nemusí zaèít a skonèit ve stejné køižovatce.

Mìsto øídí nezodpovìdný starosta Petr Furtprší, který obèas uzavøe nìkteré ulice kvùli poøádání rùzných akcí a tak není zaruèena dostupnost všech èástí mìsta.

Øešení realizujte formou funkce trasa s rozhraním níže. Funkce má parametrem dvì jména souborù: zdrojový a cílový. Funkce ète zdrojový soubor a zapisuje výslednou trasu do cílového souboru. Návratovou hodnotou funkce je TRUE V pøípadì úspìšného nalezení trasy mìstem a FALSE V pøípadì nenalezení trasy mìstem.

## Formát vstupu
Køižovatky jsou oèíslovány pøirozenými èísly od 0 do N-1. Na vstupu dostanete na prvním øádku poèet køižovatek a poèet ulic oddìlený mezerou, následovaný (na dalších øádcích) seznamem dvojic køižovatek, mezi kterými vede ulice. Každý øádek seznamu obsahuje 2 èísla oddìlená mezerou.
```
  N M
    (kde N je poèet køižovatek a M je poèet ulic)
  DVOJICE
    (dvojice indexù køižovatek, mezi kterými je ulice. Poèet øádkù s dvojicemi je M)
```    
Poznámka: Mùžete se spolehnout na to, že vstup je zadán korektnì

## Formát výstupu
Trasa, po které má vozidlo jet ve formátu SEZNAM, kde první øádek obsahuje poèet prvkù výsledného seznamu. Každý další øádek obsahuje právì jedno èíslo køižovatky. Pokud taková trasa nelze vytvoøit, návratová hodnota funkce je FALSE.
```
  N
    (kde N je poèet køižovatek trasy)
  T
    (indexy køižovatek, kudy vede trasa)
```
Poznámka: limity - maximálnì 20 000 køižovatek, 65 000 cest

## Pøíklad vstupu a výstupu
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
 Výstup:
     6
     3
     1
     0
     3 
     2
     1
```
     
Pøi implementaci máte k dispozici datové struktury z STL, viz ukázka. Struktury z STL použít mùžete, ale nemusíte.

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