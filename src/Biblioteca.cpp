#include "../include/Biblioteca.h"
#include "../include/Erori.h"
#include <iostream>

Biblioteca::Biblioteca(const Biblioteca& other) : utilizatori(other.utilizatori) {
    for (const auto& p : other.publicatii) {
        publicatii.push_back(p->clone()); // Deep copy folosind constructorul virtual
    }
}

void swap(Biblioteca& first, Biblioteca& second) noexcept {
    using std::swap;
    swap(first.publicatii, second.publicatii);
    swap(first.utilizatori, second.utilizatori);
}

Biblioteca& Biblioteca::operator=(Biblioteca other) {
    swap(*this, other);
    return *this;
}

void Biblioteca::adaugaPublicatie(const std::shared_ptr<Publicatie>& p) {
    publicatii.push_back(p);
}

void Biblioteca::adaugaUtilizator(const Utilizator& u) {
    utilizatori.push_back(u);
}

void Biblioteca::imprumuta(int userId, const std::string& isbn) {
    Utilizator* userGasit = nullptr;
    for (auto& u : utilizatori) {
        if (u.getId() == userId) userGasit = &u;
    }
    if (!userGasit) throw EroareUtilizatorInexistent(std::to_string(userId));

    for (auto& p : publicatii) {
        if (p->getISBN() == isbn) {
            if (!p->esteDisponibila()) throw EroarePublicatieIndisponibila(isbn);
            //daca nu gasim cartea 
            p->imprumuta();
            userGasit->imprumutaCarte(p);
            return;
        }
    }
    throw EroarePublicatieInexistenta(isbn);
}

void Biblioteca::returneaza(int userId, const std::string& isbn) {
    for (auto& u : utilizatori) {
        if (u.getId() == userId) {
            u.returneazaCarte(isbn);
            for (auto& p : publicatii) {
                if (p->getISBN() == isbn) {
                    p->returneaza();
                    return;
                }
            }
        }
    }
}

void Biblioteca::afiseazaPublicatii() const {
    for (const auto& p : publicatii) {
        // Downcast cu sens folosind dynamic_pointer_cast
        //verifica daca elementul e o revista la runtime si printeaza
        //
        if (auto rev = std::dynamic_pointer_cast<Revista>(p)) {
            std::cout << "[INFO SPECIAL] Revista editia " << rev->getNumarEditie() << " este in sistem.\n";
        }
        std::cout << *p << "\n";
    }
}

std::ostream& operator<<(std::ostream& out, const Biblioteca& b) {
    out << "=== Biblioteca ===\nPublicatii (Total: " << Publicatie::getNrTotal() << "):\n";
    for (const auto& p : b.publicatii) out << *p << "\n";
    out << "\nUtilizatori:\n";
    for (const auto& u : b.utilizatori) out << u << "\n";
    return out;
}