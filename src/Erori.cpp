#include "../include/Erori.h"

EroareBiblioteca::EroareBiblioteca(const std::string& mesaj) : std::runtime_error(mesaj) {}

EroareLipsaStoc::EroareLipsaStoc(const std::string& titlu) : EroareBiblioteca("Stoc epuizat pentru: " + titlu) {}

EroareObiectInexistent::EroareObiectInexistent(const std::string& id) : EroareBiblioteca("Nu s-a gasit: " + id) {}

EroareFormatInvalid::EroareFormatInvalid(const std::string& detaliu) : EroareBiblioteca("Format invalid la: " + detaliu) {}