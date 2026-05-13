#pragma once
#include <vector>
#include <memory>
#include "Publicatii.h"
#include "Utilizator.h"

class Biblioteca {
private:
    std::vector<std::shared_ptr<Publicatie>> publicatii;
    //apelam p->afisare(out) din pointerul p
    std::vector<Utilizator> utilizatori;

public:
    Biblioteca() = default;

    //Copy and Swap
    // Constructor de copiere: creează o bibliotecă nouă 
    //prin copierea fiecărei publicații
    // Folosește metoda clone() pentru a asigura  copierea obiectelor, nu doar a pointerilor
    Biblioteca(const Biblioteca& other);
    Biblioteca& operator=(Biblioteca other);
    //functia de interschibare muta datele intre doua oviecte de tip biblioteca
    friend void swap(Biblioteca& first, Biblioteca& second) noexcept;

    void adaugaPublicatie(const std::shared_ptr<Publicatie>& p);
    void adaugaUtilizator(const Utilizator& u);

    void imprumuta(int userId, const std::string& isbn);
    void returneaza(int userId, const std::string& isbn);

    void afiseazaPublicatii() const;

    friend std::ostream& operator<<(std::ostream& out, const Biblioteca& b);
};