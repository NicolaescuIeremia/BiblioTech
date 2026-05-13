#pragma once
#include <exception>
#include <string>

class EroareBiblioteca : public std::exception {
protected:
    std::string mesaj;
public:
    explicit EroareBiblioteca(const std::string& msg);
    const char* what() const noexcept override;
};

class EroarePublicatieIndisponibila : public EroareBiblioteca {
public:
    explicit EroarePublicatieIndisponibila(const std::string& msg);
};

class EroarePublicatieInexistenta : public EroareBiblioteca {
public:
    explicit EroarePublicatieInexistenta(const std::string& msg);
};

class EroareUtilizatorInexistent : public EroareBiblioteca {
public:
    explicit EroareUtilizatorInexistent(const std::string& msg);
};