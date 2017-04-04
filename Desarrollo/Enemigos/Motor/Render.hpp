/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   eRender.hpp
 * Author: sergio
 *
 * Created on 14 de marzo de 2017, 14:12
 */

#ifndef RENDER_HPP
#define RENDER_HPP
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Render {
public:
    Render(float x, float y);
    Render(const Render& orig);
    virtual ~Render();
    sf::RenderWindow * getWindow();
    void setWindow(float x, float y);

private:
    sf::RenderWindow * window;

};

#endif /* ERENDER_HPP */

