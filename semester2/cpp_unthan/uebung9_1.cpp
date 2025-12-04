#include <iostream>
#include <string>



//abstract
class Tier{

    private:
    int alter;
    std::string name;

    public:

    Tier(){
        std::string n;
        std::string a;

        std::cout << "Geben Sie den Namen des Tieres ein: ";
        std::getline(std::cin, n);

        while(alter <= 0){
            std::cout << "Geben Sie das Alter des Tieres ein: ";
            std::getline(std::cin, a);
            alter = std::stoi(a);

            if(alter <= 0){
                std::cout << "Ungültiges alter!\n";
            }
        }
    }

    Tier(std::string n, int a){
        name = n;

        if(alter < 1) alter = 1;
        alter = a;
    }

    virtual int getBeine() = 0;

    virtual std::string getArt() = 0;

    std::string getName(){
        return name;
    }

    int getAlter(){
        return alter;
    }

};

class Spinne: public Tier {

    private:

    public:

    int getBeine() override {
        return 8;
    }

    std::string getArt() override {
        return "Spinne";
    }

    Spinne() : Tier() {};
    Spinne(std::string n, int a) : Tier(n, a) {};

};

class Schlange: public Tier {

    private:

    public:

    int getBeine() override {
        return 0;
    }

    std::string getArt() override {
        return "Schlange";
    }


    Schlange() : Tier() {};
    Schlange(std::string n, int a) : Tier(n, a) {};

};

class Katze: public Tier {

    private:

    public:

    int getBeine() override {
        return 4;
    }

    std::string getArt() override {
        return "Katze";
    }

    Katze() : Tier() {};
    Katze(std::string n, int a) : Tier(n, a) {};
};

class Moewe: public Tier {

    private:

    public:

    int getBeine() override {
        return 2;
    }

    std::string getArt() override {
        return "Moewe";
    }

    Moewe() : Tier() {};
    Moewe(std::string n, int a) : Tier(n, a) {};

};


void identify(Tier& vieh){
    std::cout << vieh.getName() << " ist eine " << vieh.getArt() << ", hat " << vieh.getBeine() << " Beine und ist " << vieh.getAlter() << " Jahre alt." << std::endl;
}



int main(){

    Spinne s("Berndt", 3);
    Schlange sch("Peter", 5);
    Moewe m("Rudi", 11);
    Katze k("Levi", 7);

    identify(s);
    identify(sch);
    identify(m);
    identify(k);

    return 0;
}