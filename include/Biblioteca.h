#pragma once
#include <vector>
#include <memory>
#include "Publicatii.h"
#include "Utilizator.h"

class Biblioteca {
private:
    std::vector<std::shared_ptr<Publicatie>> publicatii;
    std::vector<Utilizator> utilizatori;

public:
    Biblioteca() = default;

    // CC si op= (Copy and Swap)
    Biblioteca(const Biblioteca& other);
    Biblioteca& operator=(Biblioteca other);
    friend void swap(Biblioteca& first, Biblioteca& second) noexcept;

    void adaugaPublicatie(const std::shared_ptr<Publicatie>& p);
    void adaugaUtilizator(const Utilizator& u);

    void imprumuta(int userId, const std::string& isbn);
    void returneaza(int userId, const std::string& isbn);

    void afiseazaPublicatii() const;

    friend std::ostream& operator<<(std::ostream& out, const Biblioteca& b);
};