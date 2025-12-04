#include <iostream>
#include <string>
#include <vector>
#include <array>

#define DEBUG false
#define BEUTEL std::vector<std::array<std::string, 2>>


class Fisch
{
private:
    double gramm_gewicht;

public:

    int get_gramm_gewicht() const {
        return gramm_gewicht;
    }

    void set_gramm_gewicht(int gg){
        if(gg > 0){
            gramm_gewicht = gg;
        }
        else{
            std::cout << "Gewicht muss über 0 sein!\n";
        }
    }

    virtual std::string get_sorte() const = 0;

    virtual bool lebt_im_suesswasser() const  = 0;

    Fisch(){
        std::string gewicht;

        while(gramm_gewicht <= 0){
            std::cout << "Geben Sie ein Gewicht in gramm an: ";
            std::getline(std::cin, gewicht);

            gramm_gewicht = std::stoi(gewicht);
        }
    }

    Fisch(int gg){
        set_gramm_gewicht(gg);
    };

    ~Fisch(){
        if(DEBUG) std::cout << "Fisch objekt zerstört: " << this << std::endl;
    }
};


class Lachs : public Fisch{

    private:
        
    public:

    std::string get_sorte() const override {
        return "Lachs";
    }

    bool lebt_im_suesswasser() const override {
        return true;
    }

    Lachs(int gg) : Fisch(gg) {};
    ~Lachs(){
        if(DEBUG) std::cout << "Lachs objekt zerstört: " << this << std::endl;
    }
};


class Thunfisch : public Fisch{

    private:
        
    public:

    std::string get_sorte() const override {
        return "Thunfisch";
    }

    bool lebt_im_suesswasser() const override {
        return false;
    }

    Thunfisch(int gg) : Fisch(gg) {};
    ~Thunfisch(){
        if(DEBUG) std::cout << "Thunfisch objekt zerstört: " << this << std::endl;
    }
};

bool operator<(Fisch& f1, Fisch& f2){
    return f1.get_gramm_gewicht() < f2.get_gramm_gewicht();
}

bool operator>(Fisch& f1, Fisch& f2){
    return f1.get_gramm_gewicht() > f2.get_gramm_gewicht();
}

BEUTEL angeln(){
    BEUTEL beutel;
    bool running = true;
    std::string antwort;
    std::string fischtyp;
    std::string strgewicht;

    while(running){

        std::cout << "Haben Sie einen Fisch gefangen? (Y/N)\n";
        std::getline(std::cin, antwort);

        if(!(antwort == "Y" || antwort == "y")){
            running = false;
            break;
        }

        std::cout << "Handelt es sich um einen Lachs (L) oder um einen Thunfisch(T)?\n";
        std::getline(std::cin, antwort);
        
        if(antwort == "T" || antwort == "t"){
            fischtyp = "Thunfisch";
        }
        else if(antwort == "L" || antwort == "l"){
            fischtyp = "Lachs";
        }
        else{
            std::cout << "Das ist kein valider Fisch!\n";
            return beutel;
        }

        std::cout << "Wie viel hat der "<< fischtyp << " gewogen?\n";
        std::getline(std::cin, strgewicht);

        std::cout << "Sehr schöner fang.\n\n";
        beutel.push_back({fischtyp, strgewicht});
    }

    return beutel;
}

void info(const Fisch& fang){
    std::cout << fang.get_sorte() << ": " << fang.get_gramm_gewicht() / 1000 << "kg\n";
}

void fischen_im_see(BEUTEL beutel){

    for(const auto& eintrag : beutel) {
        if(eintrag[0] == "Lachs"){
            info(Lachs(std::stod(eintrag[1])));
        }
        else{
            std::cout << "Lügner\n";
        }
    }

}


int main(){


    BEUTEL beutel = angeln();
    
    for(const auto& eintrag : beutel) {
        std::cout << eintrag[0] << ": " << eintrag[1] << "kg\n";
    }

    fischen_im_see(beutel);


    return 0;
}
