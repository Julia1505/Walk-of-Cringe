#ifndef WAR_OF_CRINGE_RADIANS_H
#define WAR_OF_CRINGE_RADIANS_H

// #define _USE_MATH_DEFINES
#include <cmath>
#include <SFML/Window.hpp>

inline double from_rad_to_deg(double rad) { // Преобразование радиан в градусы
    return (rad * 180.0) / acos(-1);
}

inline double from_deg_to_rad(double deg) { // Преобразование градусов в радианы
    return (deg * acos(-1)) / 180.0;
}

inline void closed_program(sf::RenderWindow &window, sf::Event event) { //  при нажатии Esc закрывается программа
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) { 
                window.close();
            }
        }
    }
}


#endif //WAR_OF_CRINGE_RADIANS_H
