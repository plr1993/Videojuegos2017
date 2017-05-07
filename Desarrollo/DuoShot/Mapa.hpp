
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mapa.hpp
 * Author: lazaro
 *
 * Created on April 10, 2017, 3:10 PM
 */

#ifndef MAPA_HPP
#define MAPA_HPP

#include <string>
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Motor/Render.hpp"
#ifndef MAPA_H
#define MAPA_H



class mapa {
public:
    mapa();
    mapa(const mapa& orig);
    virtual ~mapa();  
    void CargarMapa(int nivel);
    void dibuja(Render * window);
    int _width;
    int _height;
    int _tileWidth;
    int _tileHeight;
    
private:

    int ***_tilemap;
    int _numLayers;
    int _numObject;
   
    sf::Sprite ****_tilemapSprite;
    sf::Sprite *_tilesetSprite;
    sf::Sprite te;
    
    sf::Texture _tilesetTexture;
    sf::Texture m_tileset;
     
    sf::VertexArray m_vertices;
};

#endif /* MAPA_H */


#endif /* MAPA_HPP */
