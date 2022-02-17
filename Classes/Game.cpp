#include "Game.h"
// Construct/Destruct
Game::Game()
{
    this->initWindow();
    this->player = new Player;
}

Game::~Game()
{
    delete this->player;
    delete this->window;
}

/**
* privates methods 
*/

void Game::initWindow()
{
    sf::VideoMode videoMode(800, 600);
    this->window = new sf::RenderWindow(videoMode, this->nameGame, sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(60);
    this->window->setVerticalSyncEnabled(false);
}

/**
 * @brief Poll Event is a NO-REAL-TIME 
 */
void Game::poolEvent()
{
    sf::Event e;
    while (this->window->pollEvent(e))
    {
        if ((e.type == sf::Event::Closed) || (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape))
        {
            this->window->close();
        }
    }
    //this->proccessEvents();
}

// Manage all the inputs events from user
void Game::proccessEvents()
{
    this->player->processEvents();
}

// update the game logic
void Game::update(sf::Time deltaTime)
{
    this->player->update(deltaTime);
}

void Game::render()
{
    this->window->clear();

    // drawing objects
    this->player->draw(*this->window);

    this->window->display();
}

/**
* Public Methods
*/

// Running
void Game::run(int minimum_frame_per_seconds)
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate;
    sf::Time timePerFrame = sf::seconds(1.f / minimum_frame_per_seconds);

    while (this->window->isOpen())
    {
        this->proccessEvents();
        this->poolEvent();
        timeSinceLastUpdate = clock.restart();
        while (timeSinceLastUpdate > timePerFrame)
        {
            timeSinceLastUpdate -= timePerFrame;
            this->update(timePerFrame);
        }
        this->update(timeSinceLastUpdate);
        this->render();
    }
}
