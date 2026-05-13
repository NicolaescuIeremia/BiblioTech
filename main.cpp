#include "Biblioteca.h"
#include "Publicatii.h"
#include "Erori.h"
#include <iostream>

int main() {
    try {
        Biblioteca b;

        b.adaugaPublicatie(std::make_shared<Carte>("1984", "George Orwell", "111"));
        b.adaugaPublicatie(std::make_shared<Revista>("Stiinta Azi", "Grup Ed.", "222", 45));
        b.adaugaPublicatie(std::make_shared<AudioBook>("Dune", "Frank Herbert", "333", 1200));

        Utilizator u1("Ana", 1);
        b.adaugaUtilizator(u1);

        std::cout << "--- Inainte de imprumut ---\n";
        b.afiseazaPublicatii();

        b.imprumuta(1, "222"); // Ana imprumuta revista
        
        std::cout << "\n--- Dupa imprumut ---\n" << b << "\n";

        // Testare exceptie: utilizator inexistent
        // b.imprumuta(99, "111"); 

        // Testare exceptie: carte deja imprumutata
        // b.imprumuta(1, "222");

    } catch (const EroareBiblioteca& e) {
        std::cerr << "Eroare prinsa in main: " << e.what() << "\n";
    }

    return 0;
}