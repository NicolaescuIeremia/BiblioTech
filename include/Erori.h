#pragma once
#include <stdexcept>
#include <string>
/// Baza EroareBiblioteca moștenește std::runtime_error.
/// Avem 3 derivate distincte: EroareLipsaStoc, EroareObiectInexistent, EroareFormatInvalid
class EroareBiblioteca : public std::runtime_error {
public:
    explicit EroareBiblioteca(const std::string& mesaj);
};

class EroareLipsaStoc : public EroareBiblioteca {
public:
    explicit EroareLipsaStoc(const std::string& titlu);
};

class EroareObiectInexistent : public EroareBiblioteca {
public:
    explicit EroareObiectInexistent(const std::string& id);
};

class EroareFormatInvalid : public EroareBiblioteca {
public:
    explicit EroareFormatInvalid(const std::string& detaliu);
};