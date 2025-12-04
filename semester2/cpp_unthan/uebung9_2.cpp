#include <iostream>
#include <string>

#define DEBUG false


class Person{

    private:
    std::string nachname = "";
    std::string vorname = "";

    public:

    std::string get_nachname() const {
        return nachname;
    }
    std::string get_vorname() const {
        return vorname;
    }

    void set_nachname(std::string n){
        nachname = n;
    }
    void set_vorname(std::string v){
        vorname = v;
    }

    Person(){

        std::string n;
        std::string v;

        std::cout << "Geben Sie einen Vornamen ein: ";
        std::getline(std::cin, n);

        std::cout << "Geben Sie einen Nachnamen ein: ";
        std::getline(std::cin, v);
    }

    ~Person(){
        if(DEBUG) std::cout << "Person objekt zerstört." << std::endl;
    }
};

class Student: virtual public Person{
    
    private:
    int matrikelnummer;

    public:

    void print_mat() const {
        std::cout << matrikelnummer;
    }

    Student(){
        std::string m;

        while(matrikelnummer < 1000000){
            std::cout << "Geben Sie ihre Matrikelnummer an: ";
            std::getline(std::cin, m);
            matrikelnummer = std::stoi(m);

            if(matrikelnummer < 1000000){
                std::cout << "Die Matrikelnummer muss mindestens 7 Stellen haben!\n";
            }
        }
    }
};


class Adresse: virtual public Person{
    private:
    std::string strasse;
    int plz;
    std::string ort;
    
    public:
    
    void print_adresse() const {
        std::cout << strasse << ", " << plz << " " << ort << std::endl;
    }


    void set_strasse(std::string st){
        strasse = st;
    }

    void set_plz(int p){
        plz = p;
    }

    void set_ort(std::string o){
        ort = o;
    }

    Adresse(){
        std::string p;

        std::cout << "Geben Sie ihre Straße an: ";
        std::getline(std::cin, strasse);

        std::cout << "Geben Sie ihre PLZ an: ";
        std::getline(std::cin, p);
        plz = std::stoi(p);

        std::cout << "Geben Sie ihren Ortsnamen an: ";
        std::getline(std::cin, ort);
    }

};

class StudiDaten: public Adresse, Student {
    private:

    public:

    void print_alles() const {
        std::cout << "Student mit der Matriklenummer ";
        print_mat();
        std::cout << " wohnt in der ";
        print_adresse();
    }

    StudiDaten() : Person(), Student(), Adresse() {};
};





int main(){

    StudiDaten s;
    s.print_alles();

    return 0;
}