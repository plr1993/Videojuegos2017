/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Estado.hpp
 * Author: sergio
 *
 * Created on 26 de abril de 2017, 19:17
 */

#ifndef ESTADO_HPP
#define ESTADO_HPP

class Estado {
public:
    Estado();
    Estado(const Estado& orig);
    virtual ~Estado();
    int * getEstado();
    void setEstado(int i);
    int * getMapa();
    void setMapa(int i);
private:
    int * _estado, *_mapa;
};

#endif /* ESTADO_HPP */

