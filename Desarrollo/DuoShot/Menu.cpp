/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Menu.cpp
 * Author: sergio
 * 
 * Created on 26 de abril de 2017, 19:19
 */

#include "Menu.hpp"

Menu::Menu() {
    //Creo el fondo
    _fondo = new sf::Sprite();
    _texFondo = new sf::Texture();
    _texFondo->loadFromFile("resources/fondo.jpg");
    _fondo->setTexture(*_texFondo);
    _fondo->setPosition(0, 0);
    //Creo el logo
    _logo = new sf::Sprite();
    _texLogo = new sf::Texture();
    _texLogo->loadFromFile("resources/logo.png");
    _logo->setTexture(*_texLogo);
    _logo->setPosition(0, 0);
    
    //Cargamos las letras de iniciar partida, etc.
    _cuadrado = new sf::Sprite();
    _cuadrado2 = new sf::Sprite();
    _cuadrado3 = new sf::Sprite();
    _texCuadrado = new sf::Texture();
    _texCuadrado->loadFromFile("resources/cuadrado.png");
    _texCuadrado2 = new sf::Texture();
    _texCuadrado2->loadFromFile("resources/cuadrado_hover.png");
    _cuadrado->setTexture(*_texCuadrado);
    _cuadrado2->setTexture(*_texCuadrado);
    _cuadrado3->setTexture(*_texCuadrado);
    _cuadrado->setPosition(1250, 200);
    _cuadrado2->setPosition(1250, 400);
    _cuadrado3->setPosition(1250, 600);
    
    _font = new sf::Font;
    _font->loadFromFile("resources/gameplay.ttf");
    _textInicio = new sf::Text("Iniciar Partida", *_font);
    _textCargar = new sf::Text("Cargar Partida", *_font);
    _textOpcion = new sf::Text("Opciones", *_font);
    _textInicio->setColor(sf::Color::White);
    _textInicio->setCharacterSize(50);
    _textInicio->setPosition(1350, 250);
    _textCargar->setColor(sf::Color::White);
    _textCargar->setCharacterSize(50);
    _textCargar->setPosition(1325, 450);
    _textOpcion->setColor(sf::Color::White);
    _textOpcion->setCharacterSize(50);
    _textOpcion->setPosition(1400, 650);
    
    //Cargamos los sprites de seleccionar mapa
    _mapaAgua = new sf::Sprite;
    _texMapaAgua = new sf::Texture;
    _texMapaAgua->loadFromFile("resources/mapa-agua.png");
    _texMapaAguaHover = new sf::Texture;
    _texMapaAguaHover->loadFromFile("resources/mapa-agua-hover.png");
    _mapaAgua->setTexture(*_texMapaAgua);
    _mapaAgua->setPosition(50, 450);
    _mapaAgua->scale(0.95, 0.95);
    
    _mapaFuego = new sf::Sprite;
    _texMapaFuego = new sf::Texture;
    _texMapaFuego->loadFromFile("resources/mapa-fuego.png");
    _texMapaFuegoHover = new sf::Texture;
    _texMapaFuegoHover->loadFromFile("resources/mapa-fuego-hover.png");
    _mapaFuego->setTexture(*_texMapaFuego);
    _mapaFuego->setPosition(680, 450);
    _mapaFuego->scale(0.95, 0.95);

    
    _mapaCiudad = new sf::Sprite;
    _texMapaCiudad = new sf::Texture;
    _texMapaCiudad->loadFromFile("resources/mapa-ciudad.png");
    _texMapaCiudadHover = new sf::Texture;
    _texMapaCiudadHover->loadFromFile("resources/mapa-ciudad-hover.png");
    _mapaCiudad->setTexture(*_texMapaCiudad);
    _mapaCiudad->setPosition(1310, 450);
    _mapaCiudad->scale(0.95, 0.95);


    _botonJugar = new sf::Sprite;
    _texBotonJugar = new sf::Texture;
    _texBotonJugar->loadFromFile("resources/boton-jugar.png");
    _texBotonJugarHover = new sf::Texture;
    _texBotonJugarHover->loadFromFile("resources/boton-jugar-hover.png");
    _botonJugar->setTexture(*_texBotonJugar);
    _botonJugar->setPosition(600, 880);
    
    _textJugar = new sf::Text("Jugar", *_font);
    _textJugar->setColor(sf::Color::White);
    _textJugar->setCharacterSize(70);
    _textJugar->setPosition(800, 920);
    
    _textSeleccionar = new sf::Text("Selecciona un mapa", *_font);
    _textSeleccionar->setColor(sf::Color::White);
    _textSeleccionar->setCharacterSize(70);
    _textSeleccionar->setPosition(500, 980);
    
    _botonVolver = new sf::Sprite;
    _botonVolver->setTexture(*_texCuadrado);
    _botonVolver->scale(0.7, 0.7);
    _botonVolver->setPosition(1350, 30);
    
    _textVolver = new sf::Text("Menu principal", *_font);
    _textVolver->setColor(sf::Color::White);
    _textVolver->setCharacterSize(30);
    _textVolver->setPosition(1430, 70);
    
    //Cargamos el menu de los controles
    _controles = new sf::Sprite;
    _texControles = new sf::Texture;
    _texControles->loadFromFile("resources/controles.png");
    _controles->setTexture(*_texControles);
    _controles->setPosition(50, 50);
}

Menu::Menu(const Menu& orig) {
}

Menu::~Menu() {
    delete _fondo;
    delete _texFondo;
    delete _logo;
    delete _texLogo;
    delete _cuadrado;
    delete _cuadrado2;
    delete _cuadrado3;
    delete _texCuadrado;
    delete _texCuadrado2;
    delete _font;
    delete _textInicio;
    delete _textCargar;
    delete _textOpcion;
    delete _mapaAgua;
    delete _mapaCiudad;
    delete _mapaFuego;
    delete _texMapaAgua;
    delete _texMapaFuego;
    delete _texMapaCiudad;
    delete _texMapaAguaHover;
    delete _texMapaFuegoHover;
    delete _texMapaCiudadHover;
    delete _botonJugar;
    delete _texBotonJugar;
    delete _textJugar;
    delete _textSeleccionar;
    delete _botonVolver;
    delete _textVolver;
    delete _controles;
    delete _texControles;
    delete _texBotonJugarHover;
}

void Menu::drawMenu(Render* window, Estado * estado) {
    //Pintamos las letras de inicio
    
    window->getWindow()->draw(*_fondo);
    window->getWindow()->draw(*_logo);
    if(*estado->getEstado() == 0){
         drawLetrasInicio(window);
    }else if(*estado->getEstado() == 1){
        drawSelecMapa(window);
    }else if(*estado->getEstado() == 2){
        drawControles(window);
    }
   

}

void Menu::updateMenu(Render * window, sf::Sprite * objective, Estado * estado) {
    if(*estado->getEstado() == 0){
        colisionMenu(objective);
    }else if(*estado->getEstado() == 1){
        colisionSelecMapa(objective);
    }else if(*estado->getEstado() == 2){
        colisionesControles(objective);
    }

}

void Menu::drawLetrasInicio(Render * window) {
    window->getWindow()->draw(*_cuadrado);
    window->getWindow()->draw(*_cuadrado2);
    window->getWindow()->draw(*_cuadrado3);
    window->getWindow()->draw(*_textInicio);
    window->getWindow()->draw(*_textCargar);
    window->getWindow()->draw(*_textOpcion);
}

void Menu::drawSelecMapa(Render* window) {
    window->getWindow()->draw(*_mapaAgua);
    window->getWindow()->draw(*_mapaFuego);
    window->getWindow()->draw(*_mapaCiudad);
    window->getWindow()->draw(*_textSeleccionar);
    window->getWindow()->draw(*_botonVolver);
    window->getWindow()->draw(*_textVolver);
}

void Menu::drawControles(Render* window) {
    window->getWindow()->draw(*_controles);
    window->getWindow()->draw(*_botonJugar);
    window->getWindow()->draw(*_textJugar);
}





//Metodo que comprueba la colision del puntero con las opciones del menu
int Menu::colisionMenu(sf::Sprite * objective) {
    int num = -1;
    if(objective->getGlobalBounds().intersects(_cuadrado->getGlobalBounds())){
        sf::Color naranja(225, 128, 28);
        _cuadrado->setTexture(*_texCuadrado2);
        _textInicio->setColor(naranja);
        num = 1;
    }else{
        _cuadrado->setTexture(*_texCuadrado);
        _textInicio->setColor(sf::Color::White);
    }
    
    if(objective->getGlobalBounds().intersects(_cuadrado2->getGlobalBounds())){
        sf::Color naranja(225, 128, 28);
        _cuadrado2->setTexture(*_texCuadrado2);
        _textCargar->setColor(naranja);
    }else{
        _cuadrado2->setTexture(*_texCuadrado);
        _textCargar->setColor(sf::Color::White);
    }
    
    if(objective->getGlobalBounds().intersects(_cuadrado3->getGlobalBounds())){
        sf::Color naranja(225, 128, 28);
        _cuadrado3->setTexture(*_texCuadrado2);
        _textOpcion->setColor(naranja);
    }else{
        _cuadrado3->setTexture(*_texCuadrado);
        _textOpcion->setColor(sf::Color::White);
    }
    return num;
}

int Menu::colisionSelecMapa(sf::Sprite* objective) {
    int num = -1;
    if(objective->getGlobalBounds().intersects(_mapaAgua->getGlobalBounds())){
        _mapaAgua->setTexture(*_texMapaAguaHover);
        num = 2;
    }else{
        _mapaAgua->setTexture(*_texMapaAgua);
    }
            
    if(objective->getGlobalBounds().intersects(_mapaFuego->getGlobalBounds())){
        _mapaFuego->setTexture(*_texMapaFuegoHover);
        num = 2;
    }else{
        _mapaFuego->setTexture(*_texMapaFuego);
    }
            
    if(objective->getGlobalBounds().intersects(_mapaCiudad->getGlobalBounds())){
        _mapaCiudad->setTexture(*_texMapaCiudadHover);
         num = 2;
    }else{
        _mapaCiudad->setTexture(*_texMapaCiudad);
    }
    
    if(objective->getGlobalBounds().intersects(_botonVolver->getGlobalBounds())){
        _botonVolver->setTexture(*_texCuadrado2);
        sf::Color naranja(225, 128, 28);
        _textVolver->setColor(naranja);
        num = 0;
    }else{
        _botonVolver->setTexture(*_texCuadrado);
    }
    return num;
}

int Menu::colisionesControles(sf::Sprite* objective) {
    int num = -1;
    if(objective->getGlobalBounds().intersects(_botonJugar->getGlobalBounds())){
        _botonJugar->setTexture(*_texBotonJugarHover);
        num = 3;
    }else{
        _botonJugar->setTexture(*_texBotonJugar);
    }
    
    return num;
}





