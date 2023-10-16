#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>

#include "scene.hpp"
#include "spriteObject.hpp"
#include "sceneHandler.hpp"

std::string _headSprite = "Assets/Sprites/head.png";
std::string _headHurtSprite = "Assets/Sprites/head_hurt.png";

int main() {
    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML with Scenes!");
    Scene scene1("scene01");

    SpriteObject sprite1("soldierSprite", _headSprite);
    sprite1.setPosition(sf::Vector2f(70.0f, 70.0f));
    sprite1.setScale(sf::Vector2f(5.0f, 5.0f));
    scene1.addGameObject(sprite1);

  

    SceneHandler handler;
    handler.addScene(scene1);

    while (window.isOpen()) {

        sf::Event event;
        
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        
        window.clear();
        handler.update();
        handler.render(window);
        window.display();
    }

    return 0;
}





