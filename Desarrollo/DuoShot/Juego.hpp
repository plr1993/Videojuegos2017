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
private:
    Render * _window;

};

#endif /* JUEGO_HPP */

