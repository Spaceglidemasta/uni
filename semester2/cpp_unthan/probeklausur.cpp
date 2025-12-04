#include <iostream>
#include <string>
#include "probeklausur.hpp"
#include <vector>
#include <memory>



void Uhrzeit::set_uhrzeit(int h, int m){
    stunde = h;
    minute = m;
    if(!control()){
        std::cout << "Stunden- und Minutenzahl zurück auf 0 gesetzt!\n";
    }
}


bool Uhrzeit::control(){
    if(minute  == 60){
        stunde++;
        minute = 0;
        stunde %= 24;
    }
    else if(stunde > 23 || stunde < 0){
        stunde = 0;
        std::cout << "Stundenanzahl nicht valide!\n";
        return false;
    }
    else if(minute < 0 || minute > 59){
        minute = 0;
        std::cout << "Minutenanzahl nicht valide!\n";
        return false;
    }
    return true;
}

void Uhrzeit::print_uhrzeit() const {
    std::cout << stunde << ":" << minute << std::endl;
}


Uhrzeit::Uhrzeit(){

}

Uhrzeit::Uhrzeit(int h, int m){
    set_uhrzeit(h, m);
}

Uhrzeit::~Uhrzeit(){
}

std::istream& operator>>(std::istream& in, Uhrzeit& zeit){
    std::string h;
    std::string m;

    std::cout << "Geben Sie die Stundenanzahl an: ";
    in >> h;

    std::cout << "Geben Sie die Minutenanzahl an: ";
    in >> m;

    zeit.set_uhrzeit(std::stoi(h), std::stoi(m));

    return in;
}

    
std::ostream& operator<<(std::ostream& out, Uhrzeit& zeit){
    out << zeit.get_h() << ":" << zeit.get_m() << std::endl;
    return out;
} 

bool operator<(Uhrzeit first, Uhrzeit sec){
    double firstgesamt = first.get_h() + double(first.get_m()) / 60;
    double secgesamt = sec.get_h() + double(sec.get_m()) / 60;

    return (firstgesamt < secgesamt);
}

Uhrzeit& operator++(Uhrzeit& zeit){
    zeit.set_uhrzeit(zeit.get_h(), zeit.get_m() + 1);
    return zeit;
}

Uhrzeit& operator++(Uhrzeit& zeit, int){
    zeit.set_uhrzeit(zeit.get_h(), zeit.get_m() + 1);
    return zeit;
}

class Wetter
{
    private:
    int temperatur = 0;
    Uhrzeit zeitpunkt;

    public:

    int get_temperatur() const {
        return temperatur;
    }

    Uhrzeit get_zeitpunkt() const {
        return zeitpunkt;
    }

    virtual std::string get_type() const {
        return "unbekannt";
    }

    virtual void info() const {
        std::cout << "Wetter bei " << temperatur <<"° um ";
        zeitpunkt.print_uhrzeit();
    }

    
    Wetter();
    Wetter(int t, Uhrzeit z);
    ~Wetter();
};
typedef std::vector<std::shared_ptr<Wetter>> WETTER_CONTAINER;

Wetter::Wetter(): zeitpunkt(Uhrzeit(0,0)){};

Wetter::Wetter(int t, Uhrzeit z) : temperatur(t), zeitpunkt(z) {};

Wetter::~Wetter(){
}

class Sonnig : virtual public Wetter
{
    private:
    int sonnencreme = 0;

    public:

    std::string get_type() const override {
        return "Sonnig";
    }

    void info() const override {
        std::cout << "Sonniges Wetter bei " << get_temperatur() << "° um ";
        get_zeitpunkt().print_uhrzeit();
        std::cout << "Wir empfelen Sonnencreme vom Schutzfaktor " << sonnencreme << std::endl;
    }

    Sonnig();
    Sonnig(int t, Uhrzeit z, int sc);
    ~Sonnig();
};

Sonnig::Sonnig() : Wetter() {};

Sonnig::Sonnig(int t, Uhrzeit z, int sc): Wetter(t,z), sonnencreme(sc) {}

Sonnig::~Sonnig()
{
}

class Bewoelkt : virtual public Wetter
{
    private:
    double regen = 0.0;

    public:

    std::string get_type() const override {
        return "Bewoelkt";
    }

    void info() const override {
        std::cout << "Bewölktes Wetter bei " << get_temperatur() << "° um ";
        get_zeitpunkt().print_uhrzeit();
        std::cout << "Wir warnen vor " << regen << "%" << " Niederschlag." << std::endl;
    }

    Bewoelkt();
    Bewoelkt(int t, Uhrzeit z, double r);
    ~Bewoelkt();
};

Bewoelkt::Bewoelkt() : Wetter() {};

Bewoelkt::Bewoelkt(int t, Uhrzeit z, double r) : Wetter(t, z), regen(r) {};

Bewoelkt::~Bewoelkt()
{
}



void add_weather(WETTER_CONTAINER* aw){
    Uhrzeit z;
    std::string t;
    std::string w_type;
    std::string r;
    std::string sc;

    std::cout << "\n#---------Neues Wetter anlegen: --------#\n";
    std::cin >> z;

    std::cout << "Geben Sie die Temperatur an: ";
    std::cin >> t;

    std::cout << "Geben Sie an, ob es Sonnig(0), oder Bewoelkt(1) ist: ";
    std::cin >> w_type;

    if(w_type == "0"){
        std::cout << "Geben Sie den Sonnencremeschutzfaktor an: ";
        std::cin >> sc;
        aw -> push_back(std::make_shared<Sonnig>(std::stoi(t), z, std::stoi(sc)));
    }
    else if(w_type == "1"){
        std::cout << "Geben Sie den Niederschlag an: ";
        std::cin >> r;
        aw -> push_back(std::make_shared<Bewoelkt>(std::stoi(t), z, std::stod(r)));
    }
    else{
        aw -> push_back(std::make_shared<Wetter>(std::stoi(t), z));
    }
    std::cout << std::endl;
}

void wettervorhersage(WETTER_CONTAINER aw){

    for(const auto& wetter : aw){
        wetter -> info();
    }
}



int main(){

    Sonnig s(34, Uhrzeit(15,22), 24);

    s.info();


    Bewoelkt b(12, Uhrzeit(15,22), 94.4);

    b.info();

    WETTER_CONTAINER alle_wetter;

    add_weather(&alle_wetter);
    add_weather(&alle_wetter);


    wettervorhersage(alle_wetter);

    return 0;
}
