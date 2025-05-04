# Quick Sort folosind varianta secvențială

Quick Sort este un algoritm de sortare foarte eficient, care funcționează pe principiul „divide et impera”. Ideea de bază este să alegem un element din listă numit pivot, să organizăm elementele astfel încât cele mai mici să fie pe stânga, cele mai mari pe dreapta, și apoi să aplicăm recursiv aceeași metodă pe sublistele rezultate.

## Pașii algoritmului Quick Sort

- Alegerea pivotului – De obicei, se ia ultimul element din listă (dar poate fi și unul aleatoriu).
- Partiționarea listei – Se rearanjează elementele astfel încât toate valorile mai mici decât pivotul să fie în stânga acestuia, iar cele mai mari în dreapta. Pivotul ajunge la poziția finală.
- Recursivitate – Se aplică aceiași pași pe cele două subliste (cea din stânga pivotului și cea din dreapta).


https://docs.google.com/document/d/1oabmIUuzwI7KOORvHO9VgTK1_qxmEeXTu5SbauhcmiU/edit?tab=t.0

## Funcții principale 

- Funcția partition
   - Alege pivotul (ultimul element din interval).
   - Mută elementele mai mici decât pivotul în stânga acestuia.
   - Returnează poziția finală a pivotului.

- Funcția quickSort
   - Sortează recursiv sub-vectorii din stânga și dreapta pivotului.

- Funcția main
   - Citește un vector de la tastatură.
   - Măsoară timpul de execuție al algoritmului folosind chrono::high_resolution_clock.
   - Afișează vectorul sortat și timpul de execuție.
