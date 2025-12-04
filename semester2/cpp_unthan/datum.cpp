#include "datum.h"

Datum::Datum(int t, int m, int j) : tag(1), monat(1), jahr(1970) {
    set_datum(t, m, j);
}

void Datum::set_tag(int t) {
    if (t > 0) {
        tag = t;
    } else {
        std::cerr << "Ungültiger Eintrag, Tag muss positiv sein.\n";
    }
}

void Datum::set_monat(int m) {
    if (m > 0) {
        monat = m;
    } else {
        std::cerr << "Ungültiger Eintrag, Monat muss positiv sein.\n";
    }
}

void Datum::set_jahr(int j) {
    if (j > 0) {
        jahr = j;
    } else {
        std::cerr << "Ungültiger Eintrag, Jahr muss positiv sein.\n";
    }
}

void Datum::set_datum(int t, int m, int j) {
    if (t > 0 && m > 0 && j > 0) {
        tag = t;
        monat = m;
        jahr = j;
    } else {
        std::cerr << "Ungültiger Eintrag, Tag, Monat und Jahr müssen positiv sein.\n";
    }
}

int Datum::get_tag() const {
    return tag;
}

int Datum::get_monat() const {
    return monat;
}

int Datum::get_jahr() const {
    return jahr;
}

void Datum::anzeigen() const {
    std::cout << tag << "." << monat << "." << jahr << std::endl;
}