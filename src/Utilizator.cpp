#include "../include/Utilizator.h"

Utilizator::Utilizator(std::string nume, int id) : nume(nume), id(id) {}

void Utilizator::imprumutaCarte(const Carte& c) {
    cartiImprumutate.push_back(c);
}

void Utilizator::returneazaCarte(const std::string& isbn) {
    for (auto it = cartiImprumutate.begin(); it != cartiImprumutate.end(); ++it) {
        if (it->getISBN() == isbn) {
            cartiImprumutate.erase(it);
            return;
        }
    }
}

int Utilizator::getId() const { return id; }

std::ostream& operator<<(std::ostream& out, const Utilizator& u) {
    out << "Utilizator: " << u.nume << " (ID: " << u.id << ")\nCarti imprumutate:\n";
    for (const auto& c : u.cartiImprumutate) {
        out << "  - " << c << "\n";
    }
    return out;
}