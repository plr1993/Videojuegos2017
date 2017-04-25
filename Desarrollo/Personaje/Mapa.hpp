/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mapa.hpp
 * Author: sergio
 *
 * Created on 27 de marzo de 2017, 11:46
 */

#ifndef MAPA_HPP
#define MAPA_HPP

#include <SFML/Graphics/Sprite.hpp>
#include "Motor/Render.hpp"
#include <math.h>       /* atan2 */
#include <iostream>
#include <sstream>
using namespace std;

class Mapa {
public:
    Mapa();
    Mapa(const Mapa& orig);
    virtual ~Mapa();
    void drawMapa(Render * window);
    void updateMapa();
    sf::Sprite * getBarril();
    sf::Sprite * getBarril2();
    
private:
    sf::Sprite * _barril, * _barril2;
    sf::Texture * _textBarril;
    sf::Clock * _reloj;
    void moverBarril();
};

#endif /* MAPA_HPP */

