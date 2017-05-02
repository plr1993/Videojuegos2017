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
#include "tinyxml/tinyxml.h"

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
    void cargarMapaXML(int nivel);
    
private:
    sf::Sprite * _barril, * _barril2, *_mapa;
    sf::Texture * _textBarril, *_textMapa;
    sf::Clock * _reloj;
    void moverBarril();
    
    sf::Sprite* p_sprite;
    sf::Texture* p_textura;
    int *_width;
    int *_height;
    int *_tileWidth;
    int *_tileHeight;
    int *_x, *_y, *_oheight, *_owidth, _tamD, _tamI, _tamA, _tamU;
    int **_capaColisiones;
    sf::Sprite ** _spritesMapa;
    sf::RectangleShape *_colisionesIzquierda, *_colisionesDerecha, *_colisionesAbajo, *_colisionesArriba;
    //Anyadir las texturas de nuestro tiled
    sf::Texture *_Agua, *_Ciudad1, * _Ciudad2, *_Ciudad3, * _Ciudad4, *_Fuego1, *_Fuego2, *_Fuego3;
};

#endif /* MAPA_HPP */

