//Luca De Simone 1592157
#include <iostream>
#include "uebungsaufg.hpp"
#include "rechnung.cpp"
#include <vector>
#include <memory>


void Kleidung::set_preis(double p){
    preis = p;
}


int main()
{

    Jeans baggy(59.99, "Blau");
    Jeans cargo(12.3, "Schwarz");

    cargo.set_preis(49.99);

    Shirt bluse(105, "pink");


    PAKET_TYPE paket;
    paket.push_back(std::make_shared<Jeans>(baggy));
    paket.push_back(std::make_shared<Jeans>(cargo));
    paket.push_back(std::make_shared<Shirt>(bluse));
    paket.push_back(std::make_shared<Shirt>(29.99, "Schwarz"));
    paket.push_back(std::make_shared<Jeans>(125.00, "on the Whoose"));

    rechnung(paket);

    return 0;
}
