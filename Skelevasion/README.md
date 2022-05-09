Szükséges modellek és textúrák: https://drive.google.com/file/d/1TDDFtikOJkp0YqawvWr-yj6doGsxwjca/view?usp=sharing

 Program leírása: egy "Skelevasion" nevű fps játékot készítettem el, amiben meg kell ölni N darab csontvázat, hogy nyerjünk. A csontvázak kergetik a játékost, véletlenszerűen spawn-olnak és forognak a saját tengelyük körül ezzel egy amolyan "tornádó" effektust elérve. Ehhez van egy fegyverünk amiből golyókat tudunk lőni, ha eltalál egy csontvázat akkor meghal és a golyó eltűnik. A golyók a szoba falaíról visszapattan (az N-edik pattanásnál eltűnik), és emiatt saját magunkat is le tudjuk lőni és ezzel a játéknak vége. Minden modell textúrázva van. Vereség eseten "defeat", győzelem esetén pedig "victory" kép jelenik meg.

Irányítás: Mozogni a szokásos "WASD" gombokkal tudunk, a nezétetet pedig az egérrel. Lőni a bal egér gomb lenyomásával lehet. "F" betű lenyomásával elő vehetünk egy zseblámpát amelynek a fényerejét az "I" és "O" betűkkel állíthatjuk (a feladat leírásában "-" és "+" szerepel, viszont nekem TKL billentyűzetem van ezért nincsenek ilyen gombjaim). A "H" betűvel pedig egy help menüt tudunk megjeleníteni.

Ismert hibák:
Ha több mint 100 golyót lövünk vagy több mint 25 csontvázat idézünk akkor a program lefagy.
Ha legyőzzük az ötödik csontvázat, akkor megjelenik a "victory" kép, viszont ha maradt még csontváz és az elkap minket akkor átvált a "defeat" képre.
A csontvázak spawnolása random, ezért néha igazságtalanul a játékoshoz túl közel spawnol és egyből kikap.
