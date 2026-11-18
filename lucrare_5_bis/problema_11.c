/*
11. Scrieţi un program care să acţioneze ca un dicţionar electronic. Când utilizatorul introduce un cuvânt în dicţionar, programul să afişeze înţelesul său. Folosiţi un tablou tridimensional de tip char, care să
conţină cuvintele şi înţelesul lor.
*/

#define _CRT_SECURE_NO_WARNINGS  1
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include "array_read_write.h" 
#include "probleme.h"

#define DICTIONARY_SIZE 8

void problema_11()
{
    char dictionary[8][2][MAX_ARRAY] = {
    {
        "Algoritm",
        "Un algoritm este o secventa finita si bine definita de pasi sau reguli care rezolva o problema.El primeste date de intrare, le prelucreaza si produce un rezultat."
    },
    {
        "Variabila",
        "O variabila este o zona de memorie cu un nume simbolic in care un program pastreaza o valoare.Aceasta valoare se poate modifica pe parcursul executiei programului."
    },
    {
        "Compilator",
        "Un compilator este un program care traduce codul sursa scris intr - un limbaj de programare(precum C sau C++) in cod masina.Rezultatul este un fisier executabil pe care procesorul il poate rula direct."
    },
    {
        "Pointer",
        "Un pointer este o variabila speciala care nu stocheaza o valoare obisnuita, ci adresa de memorie a unei alte variabile.Este folosit des in C pentru lucrul cu tablouri si alocare dinamica."
    },
    {
        "Recursivitate",
        "Recursivitatea este o tehnica de programare prin care o functie se apeleaza pe ea insasi pentru a rezolva subprobleme mai mici.Are nevoie obligatoriu de o conditie de oprire pentru a nu rula la infinit."
    },
    {
        "Structura de date",
        "O structura de date este o modalitate de organizare si stocare a datelor in memorie astfel incat sa poata fi accesate si modificate eficient.Exemple comune sunt vectorii, listele, stivele si arborii."
    },
    {
        "Sistem de operare",
        "Un sistem de operare este programul principal care gestioneaza resursele hardware si software ale unui calculator(procesor, memorie, fisiere).Exemple cunoscute sunt Windows, Linux si macOS."
    },
    {
        "Complexitate(timp si spatiu)",
        "Complexitatea masoara cat de eficient este un algoritm in functie de volumul datelor de intrare.Ea arata cat timp dureaza executia si cata memorie ocupa programul."
    }
    };

    char word[MAX_ARRAY];
    
    printf("Dati termenul cautat: ");
    fgets(word, sizeof(word), stdin);
    word[strcspn(word, "\n")] = '\0';

    for (int i = 0; i < DICTIONARY_SIZE; i++)
        if (strcmp(word, dictionary[i][0]) == 0)
        {
            printf("Definitia cuvantului cautate este:\n%s\n", dictionary[i][1]);
            return;
        }
    printf("Cuvantul cautat nu este in dictionar!");
}