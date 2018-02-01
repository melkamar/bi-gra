# Sheldon, Amy a K�en

Kolega z MIT Jerry Roommann (potomek nejslavn�j��ho �esk�ho v�dce, um�lce a sportovce) n�s po��dal o pomoc s organizac� n�v�t�vy dvou americk�ch v�dc�. Sheldon Cooper pl�nuje nav�t�vit fin�le sout�e "Nejchyt�ej�� �ech", kde hodl� formou z�bavn�ch ot�zek a nar�ek zpochybnit v�sledek cel� sout�e. Amy Farrah Fowlerov� by r�da nav�t�vila kongres patolog�, kter� se letos kon� v Praze pod t�matem "Vliv zdrav�ho �ivotn�ho stylu na pracovn� krizi v oboru". Po skon�en� obou akc� by Jerry r�d napl�noval setk�n� obou americk�ch v�dc� s p�edn�m �esk�m sexuologem Prof. Radimem K�enem, kter� se dlouhodob� zab�v� neobvykl�mi partnersk�mi vztahy. Na��m c�lem je navrhnout algoritmus, kter� by umo�nil nal�zt vhodn� m�sto v Praze pro setk�n� obou americk�ch v�dc� s p�edn�m �esk�m l�ka�em.

Sheldon v�ak nem� r�d metro a autobus, tedy p�esun po Praze je mo�n� pouze tramvaj�. Soustava se skl�d� z tras a zast�vek, ka�d� zast�vka je spojena s dal�� zast�vkou nejv��e jednou trasou v jednom sm�ru tj. mezi zast�vkami mohou b�t nejv�ce dv� trasy, ale v opa�n�m sm�ru. Ka�d� trasa obsahuje �daj o dob�, za kterou se tramvaj p�esune z jedn� zast�vky do zast�vky n�sleduj�c� (ve sm�ru orientace trasy). Zast�vka u �esk� televize je startovn� m�sto Sheldona, zast�vka u kongresov�ho centra je startovn� m�sto Amy. Prof. K�en vyr�� od 2. l�ka�sk� fakulty. V�ichni v�dci se v�dy na zast�vky dopravuj� nejkrat�� mo�nou trasou. D�ky jarn�m v�luk�m, nen� zaru�ena dostupnost v�ech zast�vek.

Va��m �kolem je pomoci naj�t Jerrymu vhodnou zast�vku �i zast�vky pro setk�n� v�ech ��astn�k� za n�sleduj�c�ch podm�nek:

Ka�d� ��astn�k m��e vyrazit v jin� �as.
Ka�d� ��astn�k se v�dy pohybuje do c�lov� zast�vky po nejkrat�� trase.
Sheldon odm�t� setk�n� na zast�vk�ch s idetifik�torem, kter� je d�liteln� 5.
Amy by nem�la na nikoho �ekat.
Pr�m�rn� �ekac� �as obou p�n� mus� b�t co nejmen��.
��astn�c� se mus� setkat je�t� ten sam� den, co vyraz�.
V p��pad� v�ce zast�vek se stejnou pr�m�rnou �ekac� dobou, bude up�ednostn�na ta, na kter� se ��astn�c� sejdou d��ve.
Pokud existuje v�ce �e�en� spl�uj�c� body 1 a� 7, vyp�� se v�echna v po�ad� identifik�tor� zast�vek.
Form�t v�stupn�ho proudu je n�sleduj�c�: id_zastavky::ucastnik1:hh:mm, ucastnik2:hh:mm, ucastnik3:hh:mm,
kde po�ad� ��astn�k� Sheldon, Amy a K�en je podle �asu jejich p��jezdu, v p��pad� stejn�ho �asu bude po�ad� Sheldon, K�en a Amy
�as p��jezdu je v hodin�ch a minut�ch od p�lnoci dan�ho dne,
v p��pad� existence v�ce �e�en� je ka�d� �e�en� na nov�m ��dku.

# Uk�zkov� p��klad

![Uk�zkov� p��klad](img.png "Uk�zkov� p��klad")

Sheldon vyr�� ze zast�vky 1 v �ase 40 minut po p�lnoci, Amy ze zast�vky 3 v �ase 20 a K�en ze zast�vky 9 v �ase 0.

�e�en�:
4::Sheldon:01:10, Kren:01:13, Amy:01:49

�e�en� realizujte formou funkce meeting s n�e uveden�m rozhran�m. Funkce m� jako parametr strukturu, ve kter� je ulo�ena tramvajov� soustava a reference na v�stupn� stream. Funkce �te vstupn� strukturu a zapisuje nalezen� m�sta setk�n� do c�lov�ho souboru. N�vratovou hodnotou funkce je TRUE v p��pad� �sp�n�ho nalezen� zast�vky �i zast�vek setk�n� a FALSE v p��pad� nenalezen� (nejsou spln�na krit�ria).

# Rozhran� testovac�ho prost�ed�
 
```c++
#ifndef __PROGTEST__ 
#include <iostream> 
#include <iomanip> 
#include <string> 
#include <sstream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
#include <cctype> 
#include <cmath> 
#include <vector> 
#include <queue> 
#include <stack> 
#include <map> 
#include <set> 
#include <list> 
#include <algorithm> 
#include <ctime> 
 
#endif /* __PROGTEST__ */ 
 
 
bool meeting(const CGraph& g, ostream& os) 
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
 
g je reference na strukturu CGraph s definic� grafu.
g je reference na v�stupn� stream, do kter�ho je zapisov�n v�sledek.
funkce vrac� TRUE, pokud je �e�en� nalezeno, jinak vrac� FALSE

## T��da CIndexException
T��da CIndexException je v prost�ed� PROGTEST ji� implementov�na a m� rozhran� podle deklarace n�e:

```c++ 
  class CIndexException 
  { 
    public: 
      CIndexException(int row); 
      friend ostream& operator<<(ostream& os, const CIndexException & e ); 
  };
```
 
## Struktury t_node a t_edge
Struktury t_node a t_edge jsou v prost�ed� PROGTEST ji� implementov�ny a m� rozhran� podle deklarace n�e:

```c++ 
struct t_edge 
{ 
  int sourceIndex; 
  int destinationIndex; 
  int value; 
}; 
 
struct t_node 
{ 
  int characterid; 
  long startTime; 
}; 
```
 
sourceIndex je index po��te�n�ho uzlu.
destinationIndex je index koncov�ho uzlu.
value je ohodnocen� hrany tj. �as p�esunu v minut�ch
characterid je identifik�tor startovn�ho m�sta ��ast�k�. 1 m� Sheldon, 2 m� Amy a 3 K�en. Jinak je 0
startTime je �as startu ��astn�ka v minut�ch od p�lnoci.


## T��da CGraph
T��da CGraph je v prost�ed� PROGTEST ji� implementov�na a m� rozhran� podle deklarace n�e:


```c++ 
class CGraph 
{ 
  public: 
    bool isOG() const; 
    int getEdgeCounter() const; 
    t_edge& getEdge(const int index) const; 
    int getNodeCounter() const; 
    t_node& getNode(const int index) const; 
};
``` 
Metoda isOG vrac� true pokud je graf orientovan�
Metoda getEdgeCounter vrac� po�et hran v grafu.
Metoda getEdge vrac� strukturu t_edge hrany dle indexu. Hrany jsou indexovan� od 1.
Metoda getNodeCounter vrac� po�et uzl� v grafu.
Metoda getNode vrac� strukturu t_node uzlu dle indexu. Uzly jsou indexovan� od 1.