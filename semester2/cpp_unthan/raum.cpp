#include <iostream>
#include <string>

#define DEBUG false


class Boden{

    private:

    int breite;
    int laenge;
    std::string bodenbelag;

    public:

    int get_laenge() const {
        return laenge;
    }

    int get_breite() const {
        return breite;
    }

    std::string get_bodenbelag() const {
        return bodenbelag;
    }

    void einlesen(){

        breite = -1;
        laenge = -1;
        
        std::string b;
        std::string l;

        while (breite < 0)
        {
            std::cout << "Geben Sie eine Breite an: ";
            std::getline(std::cin, b);
            breite = std::stoi(b);

            if(breite < 0){
                std::cout << "Die Breite muss postiv sein!";
            }
        }

        while (laenge < 0)
        {
            std::cout << "Geben Sie eine Länge an: ";
            std::getline(std::cin, l);
            laenge = std::stoi(l);
            
            if(laenge < 0){
                std::cout << "Die Länge muss postiv sein!";
            }
        }
        

        std::cout << "Geben Sie einen Bodenbelag an: ";
        std::getline(std::cin, bodenbelag);

    }

    Boden() : breite(2), laenge(2), bodenbelag("Laminat") {};

    Boden(int b, int l) : breite(b), laenge(l), bodenbelag("Laminat") {};

    Boden(int b, int l, std::string belag) : breite(b), laenge(l), bodenbelag(belag) {};

    ~Boden(){
        if(DEBUG) std::cout << "Boden Objekt zerstört: " << this << std::endl;
    }

};



class Raum: public Boden{
    private:

    int hoehe;

    public:

    int get_hoehe() const {
        return hoehe;
    };

    void einlesen(){
        hoehe = -1;
        
        Boden::einlesen();

        std::string h;

        while (hoehe <= 1)
        {
            std::cout << "Geben Sie eine Höhe an: ";
            std::getline(std::cin, h);
            hoehe = std::stoi(h);

            if(hoehe < 0){
                std::cout << "Die Höhe muss postiv sein!";
            }
        }
    }

    Raum() : Boden(2, 2, "Laminat"), hoehe(2) {};

    Raum(int b, int l, int h) : Boden(b, l, "Laminat"), hoehe(h) {};

    Raum(int b, int l, int h, std::string belag) : Boden(b, l, belag), hoehe(h) {};

    ~Raum(){
        if(DEBUG) std::cout << "Raum Objekt zerstört: " << this << std::endl;
    }
};

class Quader: public Raum{

    private:

    public:

    int get_volumen() const {
        return get_wohnflaeche() * this -> get_hoehe();
    }

    int get_wohnflaeche() const {
        int area = this -> get_breite() * this -> get_laenge();
        if(this -> get_hoehe() > 2){
            return area;
        }
        else{
            return area / 2;
        }
    }

    Quader(): Raum() {};
    Quader(int b, int l, int h): Raum(b, l, h) {};
    Quader(int b, int l, int h, std::string belag): Raum(b, l, h, belag) {};

    ~Quader() {
        if(DEBUG) std::cout << "Quader Objekt zerstört: " << this << std::endl;
    }

};


std::ostream& operator<<(std::ostream& ausgabe, Quader quad){

    ausgabe << "Volumen: " << quad.get_volumen() << std::endl;

    return ausgabe;
}



class Schraege: public Raum{

    private:

    public:

    int get_volumen() const {
        return (get_wohnflaeche() * this -> get_hoehe()) / 2;
    }

    int get_wohnflaeche() const {
        int l = this -> get_laenge();
        int b = this -> get_breite();
        int h = this -> get_hoehe();

        return b * (l - 2 *(l / h));
    }

    Schraege(): Raum() {};
    Schraege(int b, int l, int h): Raum(b, l, h) {};
    Schraege(int b, int l, int h, std::string belag): Raum(b, l, h, belag) {};

    ~Schraege() {
        if(DEBUG) std::cout << "Schraege Objekt zerstört: " << this << std::endl;
    }

    bool operator<(Schraege second){
        return this -> get_volumen() < second.get_volumen();
    }

    bool operator>(Schraege second){
        return this -> get_volumen() > second.get_volumen();
    }


};


int main() {
    

    Quader q(5,5,5);

    std::cout << q;


    return 0;
}
