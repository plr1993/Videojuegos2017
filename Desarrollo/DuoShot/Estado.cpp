/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Estado.cpp
 * Author: sergio
 * 
 * Created on 26 de abril de 2017, 19:17
 */

#include "Estado.hpp"

Estado::Estado() {
    /* ESTADO
     0 -> Pantalla de inicio
     1 -> Pantalla de seleccionar mapa
     2 -> Pantalla de controles
     3 -> Juego
     */
    
    /*
     1 -> Mapa de agua
     2 -> Mapa de fuego
     3 -> Mapa de ciudad
     */
    _estado = new int(0); 
    _mapa = new int(0);
}

Estado::Estado(const Estado& orig) {
}

Estado::~Estado() {
    delete _estado;
    delete _mapa;
}

int * Estado::getEstado() {
    return _estado;
}

void Estado::setEstado(int i) {
    *_estado = i;
}

int* Estado::getMapa() {
    return _mapa;
}

void Estado::setMapa(int i) {
    if(i == 21){
        *_mapa = 1;
    }else if(i == 22){
        *_mapa = 2;
    }else if(i == 23){
        *_mapa = 3;
    }
   
}


