#pragma once
#include <iostream>
#include <string>
#include <memory>

class Publicatie {
protected:
    std::string titlu;
    std::string autor;
    std::string isbn;
    bool disponibil;
    static int nrTotalPublicatii; // atribut static

public:
    Publicatie(std::string titlu, std::string autor, std::string isbn, bool disponibil = true);
    virtual ~Publicatie() = default;

    virtual std::unique_ptr<Publicatie> clone() const = 0; // constructor virtual
    virtual void afisareDetalii(std::ostream& out) const = 0; // metoda virtuala pura

    std::string getISBN() const;
    bool esteDisponibila() const;
    void imprumuta();
    void returneaza();

    static int getNrTotal(); // functie statica

    // Interfata non-virtuala
    friend std::ostream& operator<<(std::ostream& out, const Publicatie& p);
};

class Carte : public Publicatie {
public:
    Carte(std::string titlu, std::string autor, std::string isbn, bool disponibil = true);
    std::unique_ptr<Publicatie> clone() const override;
    void afisareDetalii(std::ostream& out) const override;
};

class Revista : public Publicatie {
private:
    int numarEditie;
public:
    Revista(std::string titlu, std::string autor, std::string isbn, int numarEditie, bool disponibil = true);
    std::unique_ptr<Publicatie> clone() const override;
    void afisareDetalii(std::ostream& out) const override;
    int getNumarEditie() const;
};

class AudioBook : public Publicatie {
private:
    int durataMinute;
public:
    AudioBook(std::string titlu, std::string autor, std::string isbn, int durataMinute, bool disponibil = true);
    std::unique_ptr<Publicatie> clone() const override;
    void afisareDetalii(std::ostream& out) const override;
};

class Brosura : public Publicatie {
private:
    int numarPagini;
public:
    Brosura(std::string titlu, std::string autor, std::string isbn, int numarPagini, bool disponibil = true);
    std::unique_ptr<Publicatie> clone() const override;
    void afisareDetalii(std::ostream& out) const override;
};