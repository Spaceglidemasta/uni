#ifndef DATUM_H
#define DATUM_H

#include <iostream>

class Datum {
private:
    int tag;
    int monat;
    int jahr;

public:
    Datum(int t = 1, int m = 1, int j = 1970);

    void set_tag(int t);
    void set_monat(int m);
    void set_jahr(int j);
    void set_datum(int t, int m, int j);

    int get_tag() const;
    int get_monat() const;
    int get_jahr() const;

    void anzeigen() const;
};

#endif // DATUM_H