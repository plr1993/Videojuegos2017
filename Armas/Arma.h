#ifndef ARMA_H
#define ARMA_H
#include <SFML/Graphics.hpp>

class Arma : public sf::Sprite{
public:
    Arma();
    void cambiarArma(int num);
    int getArma();

private:
    //{pistola,escopeta,metralleta,rayo}
    sf::Texture textura_arma;
    int armaSeleccionada;
    float vel_Bala;
    float ang_Bala;
};

#endif /* ARMA1_H */

