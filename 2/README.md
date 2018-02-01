# Sheldon, Amy a Køen

Kolega z MIT Jerry Roommann (potomek nejslavnìjšího èeského vìdce, umìlce a sportovce) nás požádal o pomoc s organizací návštìvy dvou amerických vìdcù. Sheldon Cooper plánuje navštívit finále soutìže "Nejchytøejší Èech", kde hodlá formou zábavných otázek a narážek zpochybnit výsledek celé soutìže. Amy Farrah Fowlerová by ráda navštívila kongres patologù, který se letos koná v Praze pod tématem "Vliv zdravého životního stylu na pracovní krizi v oboru". Po skonèení obou akcí by Jerry rád naplánoval setkání obou amerických vìdcù s pøedním èeským sexuologem Prof. Radimem Køenem, který se dlouhodobì zabývá neobvyklými partnerskými vztahy. Naším cílem je navrhnout algoritmus, který by umožnil nalézt vhodné místo v Praze pro setkání obou amerických vìdcù s pøedním èeským lékaøem.

Sheldon však nemá rád metro a autobus, tedy pøesun po Praze je možný pouze tramvají. Soustava se skládá z tras a zastávek, každá zastávka je spojena s další zastávkou nejvýše jednou trasou v jednom smìru tj. mezi zastávkami mohou být nejvíce dvì trasy, ale v opaèném smìru. Každá trasa obsahuje údaj o dobì, za kterou se tramvaj pøesune z jedné zastávky do zastávky následující (ve smìru orientace trasy). Zastávka u Èeské televize je startovní místo Sheldona, zastávka u kongresového centra je startovní místo Amy. Prof. Køen vyráží od 2. lékaøské fakulty. Všichni vìdci se vždy na zastávky dopravují nejkratší možnou trasou. Díky jarním výlukám, není zaruèena dostupnost všech zastávek.

Vaším úkolem je pomoci najít Jerrymu vhodnou zastávku èi zastávky pro setkání všech úèastníkù za následujících podmínek:

Každý úèastník mùže vyrazit v jiný èas.
Každý úèastník se vždy pohybuje do cílové zastávky po nejkratší trase.
Sheldon odmítá setkání na zastávkách s idetifikátorem, který je dìlitelný 5.
Amy by nemìla na nikoho èekat.
Prùmìrný èekací èas obou pánù musí být co nejmenší.
Úèastnící se musí setkat ještì ten samý den, co vyrazí.
V pøípadì více zastávek se stejnou prùmìrnou èekací dobou, bude upøednostnìna ta, na které se úèastnící sejdou døíve.
Pokud existuje více øešení splòující body 1 až 7, vypíší se všechna v poøadí identifikátorù zastávek.
Formát výstupního proudu je následující: id_zastavky::ucastnik1:hh:mm, ucastnik2:hh:mm, ucastnik3:hh:mm,
kde poøadí úèastníkù Sheldon, Amy a Køen je podle èasu jejich pøíjezdu, v pøípadì stejného èasu bude poøadí Sheldon, Køen a Amy
èas pøíjezdu je v hodinách a minutách od pùlnoci daného dne,
v pøípadì existence více øešení je každé øešení na novém øádku.

# Ukázkový pøíklad

![Ukázkový pøíklad](img.png "Ukázkový pøíklad")

Sheldon vyráží ze zastávky 1 v èase 40 minut po pùlnoci, Amy ze zastávky 3 v èase 20 a Køen ze zastávky 9 v èase 0.

Øešení:
4::Sheldon:01:10, Kren:01:13, Amy:01:49

Øešení realizujte formou funkce meeting s níže uvedeným rozhraním. Funkce má jako parametr strukturu, ve které je uložena tramvajová soustava a reference na výstupní stream. Funkce ète vstupní strukturu a zapisuje nalezená místa setkání do cílového souboru. Návratovou hodnotou funkce je TRUE v pøípadì úspìšného nalezení zastávky èi zastávek setkání a FALSE v pøípadì nenalezení (nejsou splnìna kritéria).

# Rozhraní testovacího prostøedí
 
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
 
g je reference na strukturu CGraph s definicí grafu.
g je reference na výstupní stream, do kterého je zapisován výsledek.
funkce vrací TRUE, pokud je øešení nalezeno, jinak vrací FALSE

## Tøída CIndexException
Tøída CIndexException je v prostøedí PROGTEST již implementována a má rozhraní podle deklarace níže:

```c++ 
  class CIndexException 
  { 
    public: 
      CIndexException(int row); 
      friend ostream& operator<<(ostream& os, const CIndexException & e ); 
  };
```
 
## Struktury t_node a t_edge
Struktury t_node a t_edge jsou v prostøedí PROGTEST již implementovány a má rozhraní podle deklarace níže:

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
 
sourceIndex je index poèáteèního uzlu.
destinationIndex je index koncového uzlu.
value je ohodnocení hrany tj. èas pøesunu v minutách
characterid je identifikátor startovního místa úèastíkù. 1 má Sheldon, 2 má Amy a 3 Køen. Jinak je 0
startTime je èas startu úèastníka v minutách od pùlnoci.


## Tøída CGraph
Tøída CGraph je v prostøedí PROGTEST již implementována a má rozhraní podle deklarace níže:


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
Metoda isOG vrací true pokud je graf orientovaný
Metoda getEdgeCounter vrací poèet hran v grafu.
Metoda getEdge vrací strukturu t_edge hrany dle indexu. Hrany jsou indexované od 1.
Metoda getNodeCounter vrací poèet uzlù v grafu.
Metoda getNode vrací strukturu t_node uzlu dle indexu. Uzly jsou indexované od 1.