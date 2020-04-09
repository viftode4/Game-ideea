#define PROT 'O'

class Protagonist {
private:
    //coordonatele
    int x = 30, y = 115;
    int health = 3;
public:
    void GetHit() {
        health--;
    }

};
