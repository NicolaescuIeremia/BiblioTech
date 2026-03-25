#pragma once
#include <vector>
#include "Carte.h"
#include "Utilizator.h"

class Biblioteca {
private:
    std::vector<Carte> carti;
    std::vector<Utilizator> utilizatori;

public:
    Biblioteca() = default;

    // Copy constructor + operator=
    Biblioteca(const Biblioteca& other);
    Biblioteca& operator=(const Biblioteca& other);

    void adaugaCarte(const Carte& c);
    void adaugaUtilizator(const Utilizator& u);

    void imprumutaCarte(int userId, const std::string& isbn);
    void returneazaCarte(int userId, const std::string& isbn);

    void afiseazaCarti() const;
    void afiseazaUtilizatori() const;

    friend std::ostream& operator<<(std::ostream& out, const Biblioteca& b);
};