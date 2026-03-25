#include "../include/Biblioteca.h"
#include <iostream>

int main() {
    Biblioteca b;

    Carte c1("1984", "George Orwell", "123");
    Carte c2("Dune", "Frank Herbert", "456");

    Utilizator u1("Ana", 1);
    Utilizator u2("Ion", 2);

    b.adaugaCarte(c1);
    b.adaugaCarte(c2);

    b.adaugaUtilizator(u1);
    b.adaugaUtilizator(u2);

    b.imprumutaCarte(1, "123");

    std::cout << b << "\n";

    b.returneazaCarte(1, "123");

    std::cout << "\nDupa returnare:\n";
    std::cout << b << "\n";

    return 0;
}