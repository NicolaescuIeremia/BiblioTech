#pragma once
#include <iostream>
#include <string>
#include <memory>

class Publicatie {
private:
    static int numarTotal; //atribut static
protected:
    std::string titlu, autor, isbn;
    bool disponibil;
    // Cerința: afișare virtuală prin NVI
    //functia printeaza detaliile fiecarui tip de publicatie 
    virtual void afisareDetalii(std::ostream& out) const = 0; 
public:
    std::string getISBN() const;
    bool esteDisponibila() const;
    void imprumuta();
    void returneaza();
    Publicatie(std::string titlu, std::string autor, std::string isbn, bool disponibil = true);
    virtual ~Publicatie() = default;
    //functia creeaza o copie a obiectului curent si o returneaza peint pointerul de baza publicatie
    virtual std::unique_ptr<Publicatie> clone() const = 0;

    // Cerinta: functie statica
    static int getNumarTotal(); 

    // Cerinta: Interfata non-virtuala (NVI) publica ce apeleaza functia protected virtuala pura afisareDetalii()
    void afisare(std::ostream& out) const { 
        out << "- ";
        afisareDetalii(out);
    }
    
    
};

/// Derivatele clasei de baza
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