#pragma once
#include <iostream>
#include <string>

class Carte {
private:
    std::string titlu;
    std::string autor;
    std::string isbn;
    bool disponibil;

public:
    Carte(std::string titlu, std::string autor, std::string isbn, bool disponibil = true);

    std::string getTitlu() const;
    std::string getISBN() const;
    bool esteDisponibila() const;

    void imprumuta();
    void returneaza();

    friend std::ostream& operator<<(std::ostream& out, const Carte& c);
};