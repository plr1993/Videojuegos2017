/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Personaje.hpp
 * Author: sergio
 *
 * Created on 14 de marzo de 2017, 13:44
 */

#ifndef PERSONAJE_HPP
#define PERSONAJE_HPP
#include "Motor/Render.hpp"
#include "Mapa.hpp"
#include "Motor/Camera.hpp"
#include <math.h>       /* atan2 */
#include <iostream>
#include <sstream>
using namespace std;

const float PI = 3.14159265;
const float speed = 75.f;
const float speedBala = 2000;

class Personaje {
public:
    Personaje();
    Personaje(const Personaje& orig);
    virtual ~Personaje();
    void tecladoPersonaje();
    void drawPersonaje(Render * window);
    void updatePersonaje(Render * window, Camera * camera);
    void updateBala();
    bool disparo(Render * window);
    void cambiarArma();
    void vida();
    void colisionesMapa(mapa * mapa);
    sf::Sprite * getPersonaje();
private:
    sf::Sprite * _survivor, *_objective, *_bala, *_vida;
    sf::Texture * _textSurvivor, *_textObj, *_textBala, *_textVida;
    sf::Clock * _frameClock, *_clock;
    bool _disparo, _colision;
    int _cantVida, _mouseX, _mouseY, _inicialBalaX, _inicialBalaY;
    float _rotation, _posX, _posY;
};
#endif /* PERSONAJE_HPP */

