/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** gameplay
*/

#include "src/Gameplay/Gameplay.hpp"

Gameplay::Gameplay(std::shared_ptr<Window> _window) : _window(_window), _map(Map(10, 10)), _currentCharacterId(0), _currentCharacterIndex(0)
{
    this->initPlayer({1 * 4.0f, (float)1.1, 8 * 4.0f}, 1, 2, 1, "Team1");
}

void Gameplay::initPlayer(Vector3 pos, std::size_t level, std::size_t orientation, std::size_t id, std::string teamname)

{
    Character player(0, 0, pos, level, orientation, teamname);

    this->_characters.insert(std::pair<std::size_t, Character>(id, player));
}

void Gameplay::runPlayers(void)
{
    for (auto &character : this->_characters) {
        character.second.run();
    }
}

void Gameplay::drawTextOnScreen(std::string text, int fontSize, int posX, int posY, Color color)
{
    this->_rayWindow.endMode3D();
    this->_rayText.drawText(text, posX, posY, fontSize, color);
    this->_rayWindow.beginMode3D(this->_window->getCamera());
}

void Gameplay::run(void)
{
    this->_map.run();
    this->drawMap();
    this->drawTextOnScreen("F1:  Camera 1", 20, this->_window->getScreenHeight() - 150, 10, BLACK);
    this->drawTextOnScreen("F2: Camera 2", 20, this->_window->getScreenHeight() - 150, 60, BLACK);
    this->drawTextOnScreen("F3: Camera 3", 20, this->_window->getScreenHeight() - 150, 110, BLACK);
    this->handleInput();
    this->startAnimation();
    this->runPlayers();
}

void Gameplay::setCurrentCharacter()
{
    if (this->_currentCharacterId >= this->_characters.size())
        this->_currentCharacterId = 0;
    for (std::size_t i = 0; i < this->_characters.size(); i++) {
        if (this->_currentCharacterId == i) {
            this->_currentCharacter = this->_characters[i];
            this->_currentCharacterId++;
            break;
        }
    }
}

void Gameplay::handleInput(void)
{
    if (this->_rayWindow.isKeyDown(KEY_ESCAPE))
        this->_window->setExit(true);
    if (this->_rayWindow.isKeyReleased(KEY_F1)) {
        this->setCurrentCharacter();
        this->_window->setCamera({_currentCharacter.getPosition().x, _currentCharacter.getPosition().y + (float)2.0, _currentCharacter.getPosition().z - (float)0.5}, { 10.0f, 2.0f, 10.0f }, { 0.0f, 1.0f, 0.0f }, 45.0f, CAMERA_PERSPECTIVE);
    }
    if (this->_rayWindow.isKeyReleased(KEY_F2)) {
        this->setCurrentCharacter();
        this->_window->setCamera({_currentCharacter.getPosition().x, _currentCharacter.getPosition().y + (float)3.5, _currentCharacter.getPosition().z - (float)3.5}, { 0.6f, -4.5f, 10.0f }, { 0.0f, 1.0f, 0.0f }, 45.0f, CAMERA_PERSPECTIVE);
    }
    if (this->_rayWindow.isKeyReleased(KEY_F3))
        this->_window->setDefaultCamera();
    if (this->_rayWindow.isKeyReleased(KEY_N))
        this->_characters[1].setPos(this->_characters[1].getPosition().x, this->_characters[1].getPosition().z + 1, RIGHT_DIR);
    if (this->_rayWindow.isKeyReleased(KEY_G))
        this->_characters[1].setPos(this->_characters[1].getPosition().x + 1, this->_characters[1].getPosition().z, TOP_DIR);
    if (this->_rayWindow.isKeyReleased(KEY_B))
        this->_characters[1].setPos(this->_characters[1].getPosition().x - 1, this->_characters[1].getPosition().z, DOWN_DIR);
    if (this->_rayWindow.isKeyReleased(KEY_V))
        this->_characters[1].setPos(this->_characters[1].getPosition().x, this->_characters[1].getPosition().z - 1, LEFT_DIR);
    
}

void Gameplay::drawMap(void)
{
    float _x = 0.0f;
    float _y = 0.0f;

    for (std::size_t y = 0; y < this->_map.getheight(); y++) {
        for (std::size_t x = 0; x < this->_map.getwidth(); x++) {
            this->_map.setcubePosition({ _x, -0.45f, _y });
            this->_map.draw(this->_map.getmodel(), this->_map.getcubePosition(), 2.0f);
            this->_map.draw(this->_map.getmodelPlatform(), {this->_map.getcubePosition().x, this->_map.getcubePosition().y + (float)1.6, this->_map.getcubePosition().z}, 0.02f);
        _x += 4.0f;
        }
        _x = 0.0f;
        _y += 4.0f;
    }
    this->_map.drawMineral(this->_map.getmodelBanana());
}

void Gameplay::startAnimation(void)
{
    if (this->_rayWindow.isKeyReleased(KEY_KP_1))
        this->_characters[0].setCurrentlyAnimation(SPAWN);
    if (this->_rayWindow.isKeyReleased(KEY_KP_2))
        this->_characters[0].setCurrentlyAnimation(DYING);
    if (this->_rayWindow.isKeyReleased(KEY_KP_3))
        this->_characters[0].setCurrentlyAnimation(WALKING);
    if (this->_rayWindow.isKeyReleased(KEY_KP_4))
        this->_characters[0].setCurrentlyAnimation(RIGHT_TURN);
    if (this->_rayWindow.isKeyReleased(KEY_KP_5))
        this->_characters[0].setCurrentlyAnimation(LEFT_TURN);
}
