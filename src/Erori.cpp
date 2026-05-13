#include "../include/Erori.h"

EroareBiblioteca::EroareBiblioteca(const std::string& msg) : mesaj(msg) {}
const char* EroareBiblioteca::what() const noexcept { return mesaj.c_str(); }

EroarePublicatieIndisponibila::EroarePublicatieIndisponibila(const std::string& msg) : EroareBiblioteca("Indisponibil: " + msg) {}
EroarePublicatieInexistenta::EroarePublicatieInexistenta(const std::string& msg) : EroareBiblioteca("Lipsa publicatie: " + msg) {}
EroareUtilizatorInexistent::EroareUtilizatorInexistent(const std::string& msg) : EroareBiblioteca("Lipsa utilizator: " + msg) {}