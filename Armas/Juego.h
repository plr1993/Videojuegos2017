
#ifndef JUEGO_H
#define JUEGO_H
#include <SFML/Graphics.hpp>
#include "Arma.h"
#include "Bala.h"
class Juego {
public:
    Juego();
    void run();
private:
    Arma arma;
    Bala bala;
    sf::RenderWindow window;
};

#endif /* JUEGO_H */

