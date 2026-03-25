#include "../include/Biblioteca.h"
#include <iostream>

Biblioteca::Biblioteca(const Biblioteca& other)
    : carti(other.carti), utilizatori(other.utilizatori) {}

Biblioteca& Biblioteca::operator=(const Biblioteca& other) {
    if (this != &other) {
        carti = other.carti;
        utilizatori = other.utilizatori;
    }
    return *this;
}

void Biblioteca::adaugaCarte(const Carte& c) {
    carti.push_back(c);
}

void Biblioteca::adaugaUtilizator(const Utilizator& u) {
    utilizatori.push_back(u);
}

void Biblioteca::imprumutaCarte(int userId, const std::string& isbn) {
    for (auto& c : carti) {
        if (c.getISBN() == isbn && c.esteDisponibila()) {
            for (auto& u : utilizatori) {
                if (u.getId() == userId) {
                    c.imprumuta();
                    u.imprumutaCarte(c);
                    return;
                }
            }
        }
    }
}

void Biblioteca::returneazaCarte(int userId, const std::string& isbn) {
    for (auto& u : utilizatori) {
        if (u.getId() == userId) {
            u.returneazaCarte(isbn);
            for (auto& c : carti) {
                if (c.getISBN() == isbn) {
                    c.returneaza();
                    return;
                }
            }
        }
    }
}

void Biblioteca::afiseazaCarti() const {
    for (const auto& c : carti) {
        std::cout << c << "\n";
    }
}

void Biblioteca::afiseazaUtilizatori() const {
    for (const auto& u : utilizatori) {
        std::cout << u << "\n";
    }
}

std::ostream& operator<<(std::ostream& out, const Biblioteca& b) {
    out << "=== Biblioteca ===\nCarti:\n";
    for (const auto& c : b.carti)
        out << c << "\n";

    out << "\nUtilizatori:\n";
    for (const auto& u : b.utilizatori)
        out << u << "\n";

    return out;
}