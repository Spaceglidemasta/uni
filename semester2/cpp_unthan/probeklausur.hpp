
#ifndef PROBEKLAUSUR_HPP
#define PROBEKLAUSUR_HPP

class Uhrzeit{

    private:

    int stunde = 0;
    int minute = 0;


    public:

    int get_h(){
        return stunde;
    }

    int get_m(){
        return minute;
    }

    //Testet ob die Zeitwerte richtig sind und setzt sie ggf. zurück
    bool control();

    void print_uhrzeit() const;

    void set_uhrzeit(int h, int m);

    Uhrzeit();
    Uhrzeit(int h, int m);
    ~Uhrzeit();
};


#endif