/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Juego.hpp
 * Author: sergio
 *
 * Created on 14 de marzo de 2017, 13:45
 */
#include "Motor/Render.hpp"
#include "Motor/Camera.hpp"
#include "Personaje.hpp"
#include "Companyero.hpp"
#include "Mapa.hpp"
#include "Menu.hpp"
#include "Estado.hpp"
#include "Enemigo.hpp"
#ifndef JUEGO_HPP
#define JUEGO_HPP

class Juego {
public:
    Juego();
    Juego(const Juego& orig);
    virtual ~Juego();
    Render * getWindow();
    void teclado();
    void draw();
    void update();
    void updateIA();
    void controlarCamera();
private:
    void comprobarColisiones();
    Render * _window;
    Camera *_camera;
    Personaje * _personaje;
    Companyero * _companyero;
    mapa * _mapa;
    Menu *_menu;
    Estado *_estado;
    sf::Sprite *_objective, *_barraSuperior;
    sf::Texture *_textObj, *_textBarra;
    Enemigo *_enemigos[10];

};

#endif /* JUEGO_HPP */

