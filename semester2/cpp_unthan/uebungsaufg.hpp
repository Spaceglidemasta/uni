//Luca De Simone 1592157
#include <iostream>

#ifndef UEBUNGSAUFG_HPP
#define UEBUNGSAUFG_HPP

class Kleidung
{
    private:
    double preis = 0.0;
    std::string farbe = "Weiss";

    public:
    Kleidung(){};
    Kleidung(double p, std::string col) : preis(p), farbe(col) {};
    virtual ~Kleidung() = default;

    inline double get_preis() const {return preis;}
    inline std::string get_farbe() const {return farbe;}

    inline virtual std::string get_material() const  = 0;
    inline virtual std::string get_type() const = 0;

    void set_preis(double p);
};

class Shirt : public Kleidung
{
    private:
    
    public:
    Shirt() : Kleidung() {};
    Shirt(double p, std::string col) : Kleidung(p, col) {};
    ~Shirt() override {};

    inline std::string get_material() const override {return "Cotton";}
    inline std::string get_type() const override {return "Shirt";}
};


class Jeans : public Kleidung
{
    private:
        
    public:
    Jeans() : Kleidung() {};
    Jeans(double p, std::string col) : Kleidung(p, col) {};
    ~Jeans() override {};

    inline std::string get_material() const override {return "Denim";}
    inline std::string get_type() const override {return "Jeans";}
};






#endif