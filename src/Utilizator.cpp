
Utilizator::Utilizator(std::string nume, int id) : nume(nume), id(id) {}

void Utilizator::imprumutaCarte(std::shared_ptr<Publicatie> p) {
    cartiImprumutate.push_back(p);
}

void Utilizator::returneazaCarte(const std::string& isbn) {
    for (auto it = cartiImprumutate.begin(); it != cartiImprumutate.end(); ++it) {
        if ((*it)->getISBN() == isbn) {
            cartiImprumutate.erase(it);
            return;
        }
    }
}

int Utilizator::getId() const { return id; }

std::ostream& operator<<(std::ostream& out, const Utilizator& u) {
    out << "Utilizator: " << u.nume << " (ID: " << u.id << ")\nImprumuturi:\n";
    for (const auto& p : u.cartiImprumutate) {
        out << "  - " << *p << "\n";
    }
    return out;
}