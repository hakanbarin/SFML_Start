#pragma once

#include <iostream>
#include <vector>
#include <ctime>
#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>



class Game
{
private:

	//Variables
	
	//Window
	sf::RenderWindow* window;
	sf::Event event;
	sf::VideoMode videoMode;

	sf::Vector2i mousePosWindow;
	
	// Game Logic
	int points ;
	float enemySpawnTimer;
	float enemySpawnTimerMax ;
	int maxEnemies ;

	// Game Objects
	std::vector<sf::RectangleShape> enemies;
	sf::RectangleShape enemy;


	// Private Functions
	void initVariables();
	void initWindow();
	void initEnemies();
	

public:
	// Constructor and Destructor
		Game();
		virtual ~Game();
		void run();
	
		//Accessor Functions

		const bool running() const;


		//Functions
		void spawnEnemy();
		void pollEvents();
		void updateEnemies();
		void renderEnemies();
		void updateMousePositions();
		void update();
		void render();
};

