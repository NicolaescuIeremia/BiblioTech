#include <iostream>
#include "include/Book.h"

int main() {
    // 1. Creăm un obiect de tip Book folosind constructorul cu parametri
    Book carte1(1, "Morometii", "Marin Preda", "978-123456", 1955);

    // 2. Afișăm detaliile cărții folosind metoda creată de noi
    std::cout << "--- Testare Clasa Book ---" << std::endl;
    carte1.afisareDetalii();

    // 3. Testăm un getter
    std::cout << "Titlul cartii este: " << carte1.getTitlu() << std::endl;

    return 0;
}