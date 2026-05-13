#include "Publicatii.h"

int Publicatie::nrTotalPublicatii = 0;

Publicatie::Publicatie(std::string titlu, std::string autor, std::string isbn, bool disponibil)
    : titlu(titlu), autor(autor), isbn(isbn), disponibil(disponibil) {
    nrTotalPublicatii++;
}

std::string Publicatie::getISBN() const { return isbn; }
bool Publicatie::esteDisponibila() const { return disponibil; }
void Publicatie::imprumuta() { disponibil = false; }
void Publicatie::returneaza() { disponibil = true; }
int Publicatie::getNrTotal() { return nrTotalPublicatii; }

std::ostream& operator<<(std::ostream& out, const Publicatie& p) {
    p.afisareDetalii(out);
    out << " | ISBN: " << p.isbn << " | Disponibil: " << (p.disponibil ? "Da" : "Nu");
    return out;
}

// ---- Carte ----
Carte::Carte(std::string titlu, std::string autor, std::string isbn, bool disponibil)
    : Publicatie(titlu, autor, isbn, disponibil) {}

std::unique_ptr<Publicatie> Carte::clone() const { return std::make_unique<Carte>(*this); }

void Carte::afisareDetalii(std::ostream& out) const {
    out << "[Carte] Titlu: " << titlu << ", Autor: " << autor;
}

// ---- Revista ----
Revista::Revista(std::string titlu, std::string autor, std::string isbn, int numarEditie, bool disponibil)
    : Publicatie(titlu, autor, isbn, disponibil), numarEditie(numarEditie) {}

std::unique_ptr<Publicatie> Revista::clone() const { return std::make_unique<Revista>(*this); }

void Revista::afisareDetalii(std::ostream& out) const {
    out << "[Revista] Titlu: " << titlu << ", Autor: " << autor << ", Editia: " << numarEditie;
}
int Revista::getNumarEditie() const { return numarEditie; }

// ---- AudioBook ----
AudioBook::AudioBook(std::string titlu, std::string autor, std::string isbn, int durataMinute, bool disponibil)
    : Publicatie(titlu, autor, isbn, disponibil), durataMinute(durataMinute) {}

std::unique_ptr<Publicatie> AudioBook::clone() const { return std::make_unique<AudioBook>(*this); }

void AudioBook::afisareDetalii(std::ostream& out) const {
    out << "[AudioBook] Titlu: " << titlu << ", Autor: " << autor << ", Durata: " << durataMinute << " min";
}