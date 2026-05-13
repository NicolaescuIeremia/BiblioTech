#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "Publicatii.h"

class Utilizator {
private:
    std::string nume;
    int id;
    std::vector<std::shared_ptr<Publicatie>> cartiImprumutate;

public:
    Utilizator(std::string nume, int id);

    void imprumutaCarte(std::shared_ptr<Publicatie> p);
    void returneazaCarte(const std::string& isbn);

    int getId() const;

    friend std::ostream& operator<<(std::ostream& out, const Utilizator& u);
};