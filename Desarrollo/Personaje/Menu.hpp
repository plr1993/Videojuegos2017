/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Menu.hpp
 * Author: sergio
 *
 * Created on 26 de abril de 2017, 19:19
 */

#ifndef MENU_HPP
#define MENU_HPP
#include "Estado.hpp"
#include "Motor/Render.hpp"
#include <iostream>
#include <sstream>
using namespace std;

class Menu {
public:
    Menu();
    Menu(const Menu& orig);
    virtual ~Menu();
    void drawMenu(Render * window, Estado * estado);
    void updateMenu(Render * window, sf::Sprite * objective, Estado * estado);
    void drawLetrasInicio(Render * window);
    void drawSelecMapa(Render * window);
    void drawControles(Render * window);
    int colisionMenu(sf::Sprite * objective);
    int colisionSelecMapa(sf::Sprite * objective);
    int colisionesControles(sf::Sprite * objective);
private:
    sf::Sprite *_fondo, *_logo, *_cuadrado, *_cuadrado2, *_cuadrado3, *_mapaAgua, *_mapaFuego, *_mapaCiudad, *_botonJugar, *_botonVolver, *_controles;
    sf::Texture *_texFondo, *_texLogo, *_texCuadrado, *_texCuadrado2, *_texMapaAgua, *_texMapaFuego, *_texMapaCiudad, *_texMapaAguaHover, *_texMapaFuegoHover, *_texMapaCiudadHover, *_texBotonJugar, *_texBotonJugarHover, *_texControles;
    sf::Font *_font;
    sf::Text *_textInicio, *_textCargar, *_textOpcion, *_textJugar, *_textSeleccionar, *_textVolver;
    bool _mapaSeleccionado;
};

#endif /* MENU_HPP */

