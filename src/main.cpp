#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "map.h"
#include "player.h"
#include "utils.h"
#include "camera.h"

int main() {
    const unsigned int width_screen = 1280;
    const unsigned int height_screen = 1024;
    sf::RenderWindow window(sf::VideoMode(width_screen, height_screen), "WAR OF CRINGE");
    // window.setFramerateLimit(60);
    // sf::Clock clock = sf::Clock();
    sf::Clock clock;
    sf::Time fps;
    const unsigned int size_pixel_block = 32;
    Map map(size_pixel_block, size_pixel_block, 0, 0, 0, 70, 189, 90, size_pixel_block);
    Player person("img/person_belka.jpg", map, 400, 400, 1, 1, size_pixel_block);
    Camera camera(window, person, map, width_screen, height_screen, size_pixel_block);
    //window.draw(person.sprite);
    while (window.isOpen()) {
        fps = clock.getElapsedTime();
        float fpsValue = 1000000/fps.asMicroseconds();
        clock.restart();
        // std::cout << "SOME_1" << std::endl;
        sf::Event event;
        // std::cout << "SOME_2" << std::endl;
        closed_program(window, event);
        // std::cout << "SOME_3" << std::endl;
        window.clear();
        // std::cout << "SOME_4" << std::endl;
        // map.update(window);
        // std::cout << "SOME_5" << std::endl;
        // fps = clock.getElapsedTime();
        // std::cout << "SOME_6" << std::endl;
        // double fpsValue = 1000000/fps.asMicroseconds();
        // std::cout << "SOME_7" << std::endl;
        //Camera camera(window, person, map, width_screen, height_screen, size_pixel_block);
        person.action(fps, map);
        Camera camera(window, person, map, width_screen, height_screen, size_pixel_block);

        // std::cout << "SOME_8" << std::endl;
        // camera.Iteract(window, width_screen, height_screen);
        // Camera camera(window, person, map, width_screen, height_screen, size_pixel_block);
        // std::cout << "SOME_9" << std::endl;

        // clock.restart();
        // std::cout << "SOME_10" << std::endl;
        // person.update(fpsValue);
        // std::cout << "SOME_11" << std::endl;
        // window.draw(person.sprite);
        // std::cout << "SOME_12" << std::endl;
        window.display();
    }
    return 0;
}