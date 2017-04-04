
#include "Juego.h"
#include <iostream>
//#include <string>
//#include <sstream>
#include <cmath>
//#include <ctime>
//#include <cstdlib>

Juego::Juego() {
       window.create(sf::VideoMode(1080, 720), "Demo armas",sf::Style::Resize|sf::Style::Close|sf::Style::Titlebar);
}
void Juego::run(){    
      //-----------------SPRITE PISTOLA---------------
    
    //ARMA
    //Cargo la imagen donde reside la textura del sprite
    sf::Texture tex;
    if (!tex.loadFromFile("resources/armas_final.png")){
        std::cerr << "Error cargando la imagen sprites.png";
        exit(0);
    }
    //Sprite para el menu
    sf::Sprite pistola_menu(tex);
    //Cojo el sprite que me interesa por defecto del sheet
    pistola_menu.setTextureRect(sf::IntRect(0, 0*92, 126, 91));
    pistola_menu.setScale(0.8,0.8);
    pistola_menu.setPosition(200, 20);
   
    //BALA
    //Cargo la imagen donde reside la textura del sprite
    sf::Texture tex1;
    if (!tex1.loadFromFile("resources/armas_final.png")){
        std::cerr << "Error cargando la imagen sprites.png";
        exit(0);
    }   
    //Y creo el spritesheet a partir de la imagen anterior
    sf::Sprite bala_prov(tex1);
    //Cojo el sprite que me interesa por defecto del sheet
    bala_prov.setTextureRect(sf::IntRect(512, 856, 100, 16));
    bala_prov.setScale(0.7,0.7);     
    // Lo dispongo en el centro de la pantalla
    bala_prov.setPosition(arma.getPosition().x+5,arma.getPosition().y+ 5);
    
    
    //-----------------SPRITE ESCOPETA---------------
    
    //ARMA
    //Cargo la imagen donde reside la textura del sprite
    sf::Texture tex2;
    if (!tex2.loadFromFile("resources/armas_final.png")){
        std::cerr << "Error cargando la imagen sprites.png";
        exit(0);
    }  
    //Sprite para el menu
    sf::Sprite escopeta_menu(tex2);
    escopeta_menu.setTextureRect(sf::IntRect(0, 4*92, 126, 91));
    escopeta_menu.setScale(0.8,0.8);
    escopeta_menu.setPosition(350, 20);  
    
    
     //-----------------SPRITE METRALLETA---------------
    
    //ARMA
    //Cargo la imagen donde reside la textura del sprite
    sf::Texture tex3;
    if (!tex3.loadFromFile("resources/armas_final.png")){
        std::cerr << "Error cargando la imagen sprites.png";
        exit(0);
    }
    //Sprite para el menu
    sf::Sprite metralleta_menu(tex3); 
    metralleta_menu.setTextureRect(sf::IntRect(0, 2*92, 126, 91));
    metralleta_menu.setScale(0.8,0.8);
    metralleta_menu.setPosition(500, 20);
    

    //-----------------SPRITE LASER---------------
    
    //ARMA
    //Cargo la imagen donde reside la textura del sprite
    sf::Texture tex_las;
    if (!tex_las.loadFromFile("resources/armas_final.png")){
        std::cerr << "Error cargando la imagen sprites.png";
        exit(0);
    }
    //Sprite para el menu
    sf::Sprite laser_menu(tex_las); 
    laser_menu.setTextureRect(sf::IntRect(0, 6*92, 159, 91));
    laser_menu.setScale(0.8,0.8);
    laser_menu.setPosition(650, 20);
   
    //BALA LANZALLAMAS
    //Cargo la imagen donde reside la textura del sprite
    sf::Texture tex_llama;
    if (!tex_llama.loadFromFile("resources/armas_final.png")){
        std::cerr << "Error cargando la imagen sprites.png";
        exit(0);
    }   
    //Y creo el spritesheet a partir de la imagen anterior
    sf::Sprite llama(tex_llama);
    //Cojo el sprite que me interesa por defecto del sheet
    llama.setTextureRect(sf::IntRect(401, 768, 207, 55));
    llama.setScale(1.5,0.7);     
     // Lo dispongo en el centro de la pantalla
    llama.setPosition(arma.getPosition().x+5,arma.getPosition().y+ 5);
    
    //BALA HIELO
    //Cargo la imagen donde reside la textura del sprite
    sf::Texture tex_hielo;
    if (!tex_hielo.loadFromFile("resources/armas_final.png")){
        std::cerr << "Error cargando la imagen sprites.png";
        exit(0);
    }   
    //Y creo el spritesheet a partir de la imagen anterior
    sf::Sprite hielo(tex_hielo);
    //Cojo el sprite que me interesa por defecto del sheet
    hielo.setTextureRect(sf::IntRect(440, 825, 174, 23));
    hielo.setScale(1.8,1.5);
     // Lo dispongo en el centro de la pantalla
    hielo.setPosition(arma.getPosition().x+5,arma.getPosition().y+ 5);
    
    //BALA LASER
    //Cargo la imagen donde reside la textura del sprite
    sf::Texture tex_laser;
    if (!tex_laser.loadFromFile("resources/armas_final.png")){
        std::cerr << "Error cargando la imagen sprites.png";
        exit(0);
    }   
    //Y creo el spritesheet a partir de la imagen anterior
    sf::Sprite laser(tex_laser);
    //Cojo el sprite que me interesa por defecto del sheet
    laser.setTextureRect(sf::IntRect(192, 984, 832, 32));
     // Lo dispongo en el centro de la pantalla
    laser.setPosition(arma.getPosition().x+5,arma.getPosition().y+ 5);
    
    //BALA DUOGUN
    //Cargo la imagen donde reside la textura del sprite
    sf::Texture tex_duogun;
    if (!tex_duogun.loadFromFile("resources/armas_final.png")){
        std::cerr << "Error cargando la imagen sprites.png";
        exit(0);
    }   
    //Y creo el spritesheet a partir de la imagen anterior
    sf::Sprite duogun(tex_duogun);
    //Cojo el sprite que me interesa por defecto del sheet
    duogun.setTextureRect(sf::IntRect(176, 768, 88, 80));
    duogun.setScale(0.5,0.5);
     // Lo dispongo en el centro de la pantalla
    duogun.setPosition(arma.getPosition().x+5,arma.getPosition().y+ 5);
    
    
    //-----------------TEXTO---------------
    
    //FUENTE
    // Load the text font
    sf::Font font;
    font.loadFromFile("resources/ubuntu.regular.ttf");
    
    //MENSAJE INICIAL
    sf::Text mensaje_Pausa;
    mensaje_Pausa.setFont(font);
    mensaje_Pausa.setCharacterSize(40);
    mensaje_Pausa.setPosition(250, 300);
    mensaje_Pausa.setColor(sf::Color::White);
    mensaje_Pausa.setString("DEMO ARMAS\nPulsa E para empezar");
    
    //OPCION 1
    sf::Text one;
    one.setFont(font);
    one.setCharacterSize(20);
    one.setPosition(pistola_menu.getPosition().x+50, 95);
    one.setColor(sf::Color::White);
    one.setString("1");
    
    //OPCION 2
    sf::Text two;
    two.setFont(font);
    two.setCharacterSize(20);
    two.setPosition(400, 95);
    two.setColor(sf::Color::White);
    two.setString("2");
    
    //OPCION 3
    sf::Text three;
    three.setFont(font);
    three.setCharacterSize(20);
    three.setPosition(metralleta_menu.getPosition().x+50, 95);
    three.setColor(sf::Color::White);
    three.setString("3");
    
    //OPCION 4
    sf::Text four;
    four.setFont(font);
    four.setCharacterSize(20);
    four.setPosition(laser_menu.getPosition().x+50, 95);
    four.setColor(sf::Color::White);
    four.setString("4-7");
    
    //INSTRUCCIONES
    sf::Text instrucciones;
    instrucciones.setFont(font);
    instrucciones.setCharacterSize(30);
    instrucciones.setPosition(850, 20);
    instrucciones.setColor(sf::Color::White);
    instrucciones.setString("Espacio\n para disparar");
    

    //-----------------PROPIEDADES---------------
    
    //VELOCIDAD Y ANGULO
    const float vel_Bala=3000.f;
    const float vel_Bala_esc=1200.f;
    const float vel_Bala_met=5000.f;
    const float vel_Bala_duo=5500.f;
    float ang_Bala=0; 
    
    //DESPLAZAMIENTO DE LA BALA RESPECTO AL SPRITE DEL PERSONAJE PARA ESTAR EN EL CAÑON DEL ARMA
    float x_bala_pistola=90;
    float y_bala_pistola=65;
    float x_bala_escopeta=110;
    float y_bala_escopeta=70;
    float x_bala_metralleta=110;
    float y_bala_metralleta=70;
    float x_laser=159;
    float y_laser=32;
    float x_duo=90;
    float y_duo=30;
    
    
    
    //JUEGO
    sf::Clock reloj;
    bool jugando = false;
    bool disparo=false;

    //-----------------BUCLE DE JUEGO---------------
    
    //Bucle del juego
    while (window.isOpen()){
        //Bucle de obtención de eventos
        sf::Event event;
        while (window.pollEvent(event)){   
            switch(event.type){             
                //Si se recibe el evento de cerrar la ventana la cierro
                case sf::Event::Closed:
                    window.close();
                    break;              
                //Si pulso E, empieza el juego
                case sf::Event::KeyPressed:
                    if(event.key.code == sf::Keyboard::E){
                        if (!jugando){
                            
                            //Reiniciar juego
                            jugando=true;
                            reloj.restart(); 
                            
                            if(arma.getArma()==1)
                                bala_prov.setPosition(arma.getPosition().x+x_bala_pistola,arma.getPosition().y+y_bala_pistola);//pìstola
                            else if(arma.getArma()==2)
                                bala_prov.setPosition(arma.getPosition().x+x_bala_escopeta,arma.getPosition().y+ y_bala_escopeta);//escopeta
                            else if(arma.getArma()==3)
                                bala_prov.setPosition(arma.getPosition().x+x_bala_metralleta,arma.getPosition().y+ y_bala_metralleta);//metralleta
                            else if(arma.getArma()==7)
                                 duogun.setPosition(arma.getPosition().x+x_duo,arma.getPosition().y+y_duo);//Duogun
                            
                                llama.setPosition(arma.getPosition().x+x_laser,arma.getPosition().y+y_laser);//Lanzallamas
                                hielo.setPosition(arma.getPosition().x+x_laser,arma.getPosition().y+y_laser);//Hielo
                                laser.setPosition(arma.getPosition().x+x_laser,arma.getPosition().y+y_laser);//Laser

                             //Resetear angulo bala 
                              do{
                                //Angulo inicial
                                 ang_Bala=0;
                              } while (std::abs(std::cos(ang_Bala)) < 0.7f);
                       }
                    }
                    else if(event.key.code == sf::Keyboard::Escape){
                            window.close();
                            break;
                    }
                    else if(event.key.code == sf::Keyboard::Space){
                            disparo=true;
                    }
                    else if(event.key.code == sf::Keyboard::Num1){
                        arma.cambiarArma(1);
                    }
                    else if(event.key.code == sf::Keyboard::Num2){
                        arma.cambiarArma(2);
                    }
                    else if(event.key.code == sf::Keyboard::Num3){
                        arma.cambiarArma(3);
                    }
                    else if(event.key.code == sf::Keyboard::Num4){
                        arma.cambiarArma(4);       
                    }
                    else if(event.key.code == sf::Keyboard::Num5){
                        arma.cambiarArma(5);
                    }
                    else if(event.key.code == sf::Keyboard::Num6){
                        arma.cambiarArma(6);
                    }
                    else if(event.key.code == sf::Keyboard::Num7){
                        arma.cambiarArma(7);
                    }
            }
        }    
        
        //ESTADO JUGANDO
        if(jugando){
            float deltaTime = reloj.restart().asSeconds();
           
            if(disparo){
                switch(arma.getArma()){
                    //Mover Bala pistola
                    case 1: 
                            if(bala_prov.getPosition().x<1080){
                                float factor = vel_Bala * deltaTime;
                                bala_prov.move(std::cos(ang_Bala) * factor, std::sin(ang_Bala) * factor);
                            }
                            if (bala_prov.getPosition().x>=1080){//Si la bala(pistola) sale por la derecha se reinicia el reloj y se vuelve a la posicion incial           
                                jugando=true;
                                disparo=false;
                                reloj.restart();
                                bala_prov.setPosition(arma.getPosition().x+x_bala_pistola,arma.getPosition().y+ y_bala_pistola);               
                            }                    
                            break;
                    //Mover Bala escopeta        
                    case 2: if(bala_prov.getPosition().x<1080){
                                float factor2 = vel_Bala_esc * deltaTime;
                                bala_prov.move(std::cos(ang_Bala) * factor2, std::sin(ang_Bala) * factor2);
                            }
                            if (bala_prov.getPosition().x> 1080){//Si la bala(escopeta) sale por la izquierda contador de mov a 0, quitar una vida y bola al centro            
                                    jugando=true;
                                    disparo=false;
                                    reloj.restart();
                                    bala_prov.setPosition(arma.getPosition().x+x_bala_escopeta,arma.getPosition().y+y_bala_escopeta);
                            }
                            break;
                            
                    case 3: if(bala_prov.getPosition().x<1080){
                                float factor3 = vel_Bala_met * deltaTime;
                                bala_prov.move(std::cos(ang_Bala) * factor3, std::sin(ang_Bala) * factor3);
                            }
                            if (bala_prov.getPosition().x> 1080){//Si la bala(escopeta) sale por la izquierda contador de mov a 0, quitar una vida y bola al centro            
                                    jugando=true;
                                    disparo=false;
                                    reloj.restart();
                                    bala_prov.setPosition(arma.getPosition().x+x_bala_metralleta,arma.getPosition().y+ y_bala_metralleta);
                            }
                            break;
                    
                    case 4: 
                            break;
                    
                    case 5: 
                            break;
                            
                    case 6: 
                            break;
                    
                    case 7:if(duogun.getPosition().x<1080){
                                float factor4 = vel_Bala_duo * deltaTime;
                                duogun.move(std::cos(ang_Bala) * factor4, std::sin(ang_Bala) * factor4);
                            }
                            if (duogun.getPosition().x> 1080){//Si la bala(escopeta) sale por la izquierda contador de mov a 0, quitar una vida y bola al centro            
                                    jugando=true;
                                    disparo=false;
                                    reloj.restart();
                                    duogun.setPosition(arma.getPosition().x+x_duo,arma.getPosition().y+y_duo);
                            }
                            break;  
                }
            }

        }

        //LIMPIAR PANTALLA (COLOR NEGRO))
        window.clear(sf::Color::Black);     
        if (jugando){
            switch(arma.getArma()){
                    case 1: window.draw(arma);
                            if(disparo)
                                window.draw(bala_prov);
                            break;
                    case 2: window.draw(arma);
                            if(disparo)
                                window.draw(bala_prov); 
                            break;
                    case 3: window.draw(arma);
                            if(disparo)
                                window.draw(bala_prov);
                            break;
                    case 4: window.draw(arma);
                            if(disparo)
                                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                                    window.draw(llama);
                            break;
                    case 5: window.draw(arma);
                            if(disparo)
                                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                                    window.draw(hielo);
                            break;
                    case 6: window.draw(arma);
                            if(disparo)
                                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                                    window.draw(laser);
                            break;
                    case 7: window.draw(arma);
                            if(disparo)
                                  window.draw(duogun);
                            break;         
            }
            window.draw(pistola_menu);
            window.draw(one);
            window.draw(escopeta_menu);
            window.draw(two);
            window.draw(metralleta_menu);
            window.draw(three);
            window.draw(laser_menu);
            window.draw(four);
            
            window.draw(instrucciones);
         }
         else//MENSAJE DE PAUSA
           window.draw(mensaje_Pausa);

        //MOSTRAR POR PANTALLA
        window.display();
    }
}

