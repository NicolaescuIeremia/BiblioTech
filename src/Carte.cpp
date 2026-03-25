#include "../include/Carte.h"

Carte::Carte(std::string titlu, std::string autor, std::string isbn, bool disponibil)
    : titlu(titlu), autor(autor), isbn(isbn), disponibil(disponibil) {}

std::string Carte::getTitlu() const { return titlu; }
std::string Carte::getISBN() const { return isbn; }
bool Carte::esteDisponibila() const { return disponibil; }

void Carte::imprumuta() { disponibil = false; }
void Carte::returneaza() { disponibil = true; }

std::ostream& operator<<(std::ostream& out, const Carte& c) {
    out << "Titlu: " << c.titlu << ", Autor: " << c.autor
        << ", ISBN: " << c.isbn
        << ", Disponibila: " << (c.disponibil ? "Da" : "Nu");
    return out;
}