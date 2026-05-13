#pragma once
#include <iostream>
#include <string>
#include <memory>

class Publicatie {
private:
    static int numarTotal; // Cerința: atribut static
protected:
    std::string titlu, autor, isbn;
    bool disponibil;
    // Cerința: afișare virtuală prin NVI
    virtual void afisareDetalii(std::ostream& out) const = 0; 
public:
    std::string getISBN() const;
    bool esteDisponibila() const;
    void imprumuta();
    void returneaza();
    Publicatie(std::string titlu, std::string autor, std::string isbn, bool disponibil = true);
    virtual ~Publicatie() = default;
    virtual std::unique_ptr<Publicatie> clone() const = 0;

    // Cerința: funcție statică
    static int getNumarTotal(); 

    // Cerința: Interfață non-virtuală (NVI) publică ce apelează virtuala protected
    void afisare(std::ostream& out) const { 
        out << "- ";
        afisareDetalii(out);
    }
    
    // ... restul metodelor tale (getters) rămân la fel
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