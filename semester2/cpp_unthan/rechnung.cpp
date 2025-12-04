#include "uebungsaufg.hpp"
#include <vector>
#include <memory>
#include <iostream>


typedef std::vector<std::shared_ptr<Kleidung>> PAKET_TYPE;


double rechnung(PAKET_TYPE& paket){
    std::cout << "|---------------Rechnung----------------\n";
    double gesamtpreis = 0;

    for(auto piece : paket){
        gesamtpreis += piece -> get_preis();
        std::cout << "| " << piece -> get_type() << ": " << piece -> get_material() << ", " << piece -> get_farbe() << " -> " << piece -> get_preis() << "$\n";
    }

    std::cout << "|---------------------------------------" << std::endl << "-->> Gesamtpreis: " << gesamtpreis << "$\n";

    return gesamtpreis;
}