#include "Game.h"
#include <iostream>


void Game::initVariables()
{
	this->window = nullptr;
    points = 0;
    enemySpawnTimer = 0.f;
    enemySpawnTimerMax = 100.f;
    maxEnemies = 5;
    
}

void Game::initWindow()
{
	videoMode = sf::VideoMode(800, 600); 

	this->window = new sf::RenderWindow(videoMode, "SFML Game", sf::Style::Titlebar | sf::Style::Close);

    this->window->setFramerateLimit(60); 

}

void Game::initEnemies()
{

	enemy.setSize(sf::Vector2f(50.f, 50.f));
    enemy.setFillColor(sf::Color(
        rand() % 256, // Random red value
        rand() % 256, // Random green value
        rand() % 256  // Random blue value
    ));
	enemy.setOutlineColor(sf::Color::Green);
	enemy.setOutlineThickness(5.f);


    enemy.setPosition(
        static_cast<float>(rand() % (static_cast<int>(window->getSize().x - enemy.getSize().x))),
        0

    );
    enemies.push_back(enemy);



    

}

Game::Game()
{
	srand(static_cast<unsigned>(time(0))); // Seed for random number generation
	initVariables();
	initWindow();
	initEnemies();
}

Game::~Game()
{
	delete window;
}



//Functions
void Game::run()
{
    while (running())
    {
        update();
        render();
    }

}
//Accessor Functions

const bool Game::running() const
{
	return window->isOpen(); 
}


void Game::spawnEnemy() {
    //@return void
    // This function creates a new enemy rectangle shape, sets its random position and color, and adds it to the enemies vector.
  
}

void Game::updateEnemies()
{

    
    // Updating the timer for enemy spawning
    if (enemies.size() < maxEnemies) {
        if (enemySpawnTimer >= enemySpawnTimerMax) {
            //spawn the enemy and reset the timer
			initEnemies();
            enemySpawnTimer = 0.f;
        }
        else {
            enemySpawnTimer += 1.f; // Increment the timer
        }
    }
    //Move the enemies

    for (auto& e : enemies)
    {
        e.move(0.f, 5.f);
    }

}



void Game::renderEnemies()
{

    for (auto& e : enemies)
    {
        window->draw(e);
    }

}

void Game::pollEvents()
{
    while (window->pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window->close();
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape)
            {
               window->close();
            }
            break;
        }
    }
}

void Game::updateMousePositions()
{
    /*
        @return void
        // Updates the mouse position relative to the window
    */
	mousePosWindow = sf::Mouse::getPosition(*window);
}

void Game::update()
{
    pollEvents();
    updateMousePositions();
    updateEnemies();
}

void Game::render()
{ 

    /*
		@return void
        //Clear old frame
	    // render objects
        // display frame in window
        // Renders the game objects
    */
	window->clear(sf::Color::Black);

	//Draw game objects here
    renderEnemies();

	window->display();
}
