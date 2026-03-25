#pragma once
#include <iostream>
#include <vector>
#include "Carte.h"

class Utilizator {
private:
    std::string nume;
    int id;
    std::vector<Carte> cartiImprumutate;

public:
    Utilizator(std::string nume, int id);

    void imprumutaCarte(const Carte& c);
    void returneazaCarte(const std::string& isbn);

    int getId() const;

    friend std::ostream& operator<<(std::ostream& out, const Utilizator& u);
};