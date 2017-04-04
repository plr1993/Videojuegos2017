
#ifndef BALA_H
#define BALA_H

#include <SFML/Graphics.hpp>
#include "Arma.h"

class Bala : public sf::Sprite{
public:
    Bala();
private:
    float demage=0.f;
    sf::Texture textura_bala;
    const float vel_Bala=0.f;
    float ang_Bala=0;
};

#endif /* BALA_H */

