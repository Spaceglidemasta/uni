//Luca De Simone 1592157
#include <iostream>
#include <vector>
#include <memory>

#ifndef PROBEPENIS_HPP
#define PROBEPENIS_HPP


class Uhrzeit{

    private:
    int stunde = 0;
    int minute = 0;

    public:
    Uhrzeit();
    Uhrzeit(int h, int m);
    ~Uhrzeit();

    int get_stunde();
    int get_minute();

    void set_uhrzeit(int h, int m);
    void print_uhrzeit() const ;
    void control();

};

class Wetter{
    private:
    int temperatur = 0;
    Uhrzeit zeitpunkt;

    public:
    Wetter() : zeitpunkt(Uhrzeit()) {};
    Wetter(int temp, Uhrzeit chr) : temperatur(temp), zeitpunkt(chr) {};
    ~Wetter(){};

    inline int get_temperatur() const {return temperatur;}
    inline Uhrzeit get_zeitpunkt() const {return zeitpunkt;}

    inline virtual std::string get_type() const {return "Undefiniert";}

    virtual void info() const;

};

typedef std::vector<std::shared_ptr<Wetter>> WETTER_CONTAINER;

class Sonnig : virtual public Wetter{

    private:
    int sonnencreme  = 0;

    public:
    Sonnig() : Wetter(), sonnencreme(0) {};
    Sonnig(int temp, Uhrzeit chr, int creme) : Wetter(temp, chr), sonnencreme(creme) {};
    ~Sonnig() {};

    inline std::string get_type() const override {return "Sonnig";}

    void info() const override;

};

class Bewoelkt : virtual public Wetter{
    private:
    double regen = 0.0;
    public:
    Bewoelkt() : Wetter(), regen(0.0) {};
    Bewoelkt(int temp, Uhrzeit chr, double rain) : Wetter(temp, chr), regen(rain) {};
    ~Bewoelkt() {};

    inline std::string get_type() const override {return "Bewölkt";}

    void info() const override;
};










#endif