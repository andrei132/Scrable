# Scrabble
## Girnet Andrei
---

## Descriere
Proiectul se bazeaza pe o forma a jocului de Scrabble. Programul este in stare sa ruleze 2 participanti (programul impotriva checker-ului) joaca alternativ si sa se determina un castigator.

Initial tabla de joc e goala si are marimea de 15x15

In fisierul scrabble.h se afla un vector de cuvinte pe care le va folosi programul

## Compilare
```bash
make build
```

## Rulare
```bash
./scrabble
```
Pe prima linie e numarul taskului(descrise mai jos)
```
1
N
Y1 X1 D1 WORD1
Y2 X2 D2 WORD2
…
N -> numar de cuvinte primite
Yi -> indicele pe verticala unde va fi plasat cuvantul (linia in matrice)
Xi -> indicele pe orizontala unde va fi plasat cuvantul (coloana in matrice)
Di -> directia in care este scris cuvantul: 
* Daca D == 0: cuvantul e scris pe orizontala, de la (Yi, Xi) spre dreapta
* Daca D == 1: cuvantul e scris pe verticala, de la (Yi, Xi) in jos
Yi - indicele liniei unde este plasata prima litera din cuvant 
Xi - indicele coloanei unde este plasata prima litera din cuvant
(Yi, Xi) - pozitia de unde incepe cuvantul, de la
```

## Punctarea literelor
```
A, E, I, L, N, O, R, S, T, U - 1 Punct
D, G - 2 Puncte
B, C, M, P - 3 Puncte
F, H, V, W, Y - 4 Puncte
K - 5 Puncte
J, X - 8 Puncte
Q, Z - 10 Puncte
```

## Taskuri

* Task 1
    + Citeste numarul intreg N urmat de N linii continand coordonatele unui cuvant si cuvantul respectiv. Dupa are loc aranjarea cuvintelor corespunzatoare in matricea de joc. Cuvantul va fi pastrat caracter cu caracter in matrice incepand cu coordonatele date.

    + Dupa ce sa salvat toate cele N cuvinte se poate sa afisa matricea apeland functia de afisare in felul urmator:
```
print_board(game_board)
```

* Task 2
    + Calcularea punctajului de catre 2 jucatori

* Task 3
    + Calcularea punctajelor cu aplicarea bonusurilor

    + Inputul e de forma 
```
3
XX
YY
N
Y1 X1 D1 WORD1
Y2 X2 D2 WORD2
…
Unde:

XX este substringul pentru bonusul primit pentru casutele marcate cu 1. 
YY este substringul pentru bonusurile primite pentru casutele marcate cu 2.
N este numarul de cunvinte
Xi, Yi, WORDi sunt coordonatele pentru cuvantul WORDi
Di este directia in care este scris cuvantul
```

* Task 4

    + Aticiparea urmatorului cuvant pentru player 2

* Task 5

    + Incercarea aducerii unui castig intr-un meci

* Task 6
    + Jocul cu checkerul

## Rularea checker-ului
```bash
./check
```

Drepturile de autor fata de crearea checkerului, conditiei apartin echipei de Programare a Calculatoarelor 2020

Codul sursa pentru joc apartine Girnet Andrei