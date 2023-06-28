#ifndef WAR_OF_CRINGE_CAMERA_H
#define WAR_OF_CRINGE_CAMERA_H

#include <SFML/Graphics.hpp>

class Camera { 
    
    private:

    sf::View camera;
    Player person;
    Map maps;
    double dirX, dirY; //начальный вектор направления
    friend class Player;

    public:

    Camera(sf::RenderWindow &window, Player c_person, Map c_maps, unsigned int width_screen, unsigned int height_screen, unsigned int  size_pixel_block);
};

#endif  // WAR_OF_CRINGE_CAMERA_H
