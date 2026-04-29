//Luca De Simone 1592157
#include "probe.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <memory>

#define DEBUG false


Uhrzeit::Uhrzeit(){
    if(DEBUG){
        std::cout << "Uhrzeit objekt " << this << " erschaffen.\n";
    }
};


Uhrzeit::Uhrzeit(int h, int m) : stunde(h), minute(m) {
    if(DEBUG){
        std::cout << "Uhrzeit objekt " << this << " erschaffen.\n";
    }
    control();
};

Uhrzeit::~Uhrzeit(){
    if(DEBUG){
        std::cout << "Uhrzeit objekt " << this << " zerstört.\n";
    }
}

int Uhrzeit::get_minute() {return minute;}
int Uhrzeit::get_stunde() {return stunde;}

void Uhrzeit::control(){
    if(stunde > 23){
        std::cout << "Falsche Eingabe der Stunde!\n";
        stunde = 0;
    }

    if(minute > 59){
        std::cout << "Falsche Eingabe der Minute!\n";
        minute = 0;
    }
}

void Uhrzeit::print_uhrzeit() const {
    std::cout << "Uhrzeit: " << stunde << ":" << minute << std::endl;
}

//control bereits drinne
void Uhrzeit::set_uhrzeit(int h, int m){
    
    stunde = h;
    minute = m;
    control();
}

std::ostream& operator<<(std::ostream& c, Uhrzeit& zeit){
    zeit.print_uhrzeit();
    return c;
}

std::istream& operator>>(std::istream& c, Uhrzeit& zeit){
    std::string h;
    std::string m;

    std::cout << "Geben Sie die Stundenanzahl an: ";
    std::getline(std::cin, h);

    std::cout << "Geben Sie die Minutenanzahl an: ";
    std::getline(std::cin, m);

    zeit.set_uhrzeit(std::stoi(h), std::stoi(m));

    return c;
}

bool operator<(Uhrzeit& z1, Uhrzeit& z2){
    if(z1.get_stunde() == z2.get_stunde()){
        return z1.get_minute() > z2.get_minute();
    }
    else{
        return z1.get_stunde() > z2.get_stunde();
    }
}

void Wetter::info() const {
    Uhrzeit chr = get_zeitpunkt();
    std::cout << "Wir haben " << get_temperatur() << "° Celsius um " << chr.get_stunde() << ":" << chr.get_minute() << std::endl;
    
}

void Sonnig::info() const {
    Uhrzeit chr = get_zeitpunkt();
    std::cout << "Wir haben Sonniges Wetter bei " << get_temperatur() << "° Celsius um " << chr.get_stunde() << ":" << chr.get_minute() << std::endl;
    std::cout << "Es wird eine Sonnencreme mit dem Lichtschutzfaktor von " << sonnencreme << " empfolen.\n";
}

void Bewoelkt::info() const {
    Uhrzeit chr = get_zeitpunkt();
    std::cout << "Wir haben Bewölktes Wetter bei " << get_temperatur() << "° Celsius um " << chr.get_stunde() << ":" << chr.get_minute() << std::endl;
    std::cout << "Es ist ein Niederschlag von  " << regen << " gegeben.\n";
}


void add_weater(WETTER_CONTAINER& container){
    std::string h;
    std::string m;
    std::string temp;
    std::string w_type;
    std::string type_var;

    std::cout << "------- Neues Wetter wird angelegt: ------------\n\n";

    std::cout << "Geben Sie die Stundenanzahl an: ";
    std::getline(std::cin, h);

    std::cout << "Geben Sie die Minutenanzahl an: ";
    std::getline(std::cin, m);

    std::cout << "Geben Sie die Temperatur an: ";
    std::getline(std::cin, temp);

    std::cout << "Ist das Wetter \"sonnig\" oder \"bewoelkt\"? ";
    std::getline(std::cin, w_type);

    if(w_type == "sonnig"){
        std::cout << "Welchen LSF empfehlen Sie? ";
        std::getline(std::cin, type_var);

        container.push_back(std::make_shared<Sonnig>(std::stoi(temp), Uhrzeit(std::stoi(h), std::stoi(m)), std::stoi(type_var)));
    }
    else if(w_type == "bewoelkt"){
        std::cout << "Was ist der Niederschlag? ";
        std::getline(std::cin, type_var);

        container.push_back(std::make_shared<Bewoelkt>(std::stoi(temp), Uhrzeit(std::stoi(h), std::stoi(m)), std::stod(type_var)));
    }
    else{
        container.push_back(std::make_shared<Wetter>(std::stoi(temp), Uhrzeit(std::stoi(h), std::stoi(m))));
    }


}

void wettervorhersage(WETTER_CONTAINER& container){
    std::cout << "------------ Wetterausgabe: ------------\n\n";
    for(auto wet : container){
        wet -> info();
    }
}


int main(){

    Uhrzeit u(12, 21);

    Sonnig w(34, u, 44);
    w.info();

    WETTER_CONTAINER alle_wetter;

    add_weater(alle_wetter);
    add_weater(alle_wetter);
    add_weater(alle_wetter);

    wettervorhersage(alle_wetter);


    return 0;
}