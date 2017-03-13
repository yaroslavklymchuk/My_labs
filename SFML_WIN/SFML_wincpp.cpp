//TODO with classes for heroes
#include <SFML/Graphics.hpp>
#include <time.h>
#include "Heroes.h"
#include "Map.h"
#include "View.h"

using namespace sf;
int main()
{
	//Making platforms
	struct plato {
		int x;
		int y;
	};

	struct plato platforms[100];

	srand(time(0));

	//Set coordinates to platforms
	for (int i = 0; i < 10; i++) {
		platforms[i].x = rand() % 500;
		platforms[i].y = rand() % 500;
	}

	RenderWindow window(VideoMode(500, 500), "SFMLworks");
	view.reset(FloatRect(0, 0, 500, 500));
	//window.setFramerateLimit(1500);

	//Downoload images from file
	Image background, platform, doodle_fire;
	background.loadFromFile("f:/C++SFML/SFML_WIN/images/background_fone.jpg");
	platform.loadFromFile("f:/C++SFML/SFML_WIN/images/Doodle_Platform_green.png");
	platform.createMaskFromColor(Color::White);

	//Making textures from images
	Texture background_tex, platform_tex;
	background_tex.loadFromImage(background);
	platform_tex.loadFromImage(platform);

	//Making sprites
	Sprite background_sprite, platform_sprite;
	background_sprite.setTexture(background_tex);
	platform_sprite.setTexture(platform_tex);
	

	Doodle doodle1("Doodler.png", 15, 15, 193, 180, 100,100);// creating an object of class Doodle
	/*for (int i = 0; i < 10; i++) {
		platform_sprite.setPosition(platforms[i].x, platforms[i].y);
	}*/

	//Enemies enemy = Enemies(10, 10, 200, 190, platforms[3].x, platforms[3].y + 150);
	
	/*int x = 100, y = 100, h = 200;
	float dx = 0, dy = 0;*/
	
	//TODO problem with SFML_time
	Clock clock;
//	float time = clock.getElapsedTime().asMicroseconds();
	
	//Main SFML loop
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			float time = clock.getElapsedTime().asMicroseconds();
			clock.restart();
			time = time / 800;
			if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
				window.close();
		}

		//Moving by pushing the keybord
		if ((Keyboard::isKeyPressed(Keyboard::Right)) || (Keyboard::isKeyPressed(Keyboard::D))) {
			doodle1.doodle_sprite.setTextureRect(IntRect(15, 15, 193, 180));
			doodle1.doodle_sprite.move(9.5, 0);
			GetCoordForPlayer(100, 100);
		}
		if ((Keyboard::isKeyPressed(Keyboard::Left)) || (Keyboard::isKeyPressed(Keyboard::A))) {
			doodle1.doodle_sprite.setTextureRect(IntRect(208, 15, -193, 180));
			doodle1.doodle_sprite.move(-9.5, 0);
			GetCoordForPlayer(100, 100);
		}
		if ((Keyboard::isKeyPressed(Keyboard::Up)) || (Keyboard::isKeyPressed(Keyboard::W))) {
			doodle1.doodle_sprite.move(0, -9.5);
			GetCoordForPlayer(100, 100);
		}
		if ((Keyboard::isKeyPressed(Keyboard::Down)) || (Keyboard::isKeyPressed(Keyboard::S))) {
			doodle1.doodle_sprite.move(0, 9.5);
			GetCoordForPlayer(100, 100);
		}
		//GetCoordForPlayer(100, 100);
		/*if (Keyboard::isKeyPressed(Keyboard::Right)) {
			x += 3;
		}
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			x -= 3;
		}

		//moving upstairs
		dy += 0.25;
		y += dy;

		if (y > 500) {
			dy = -10;
		}


		//jumpling over the platforms
		for (int i = 0; i < 10; i++) {
			if ((x + 50 > platforms[i].x) && (x + 20 < platforms[i].x + 68) && (y + 70 > platforms[i].y) && (y + 70 < platforms[i].y + 14) && (dy > 0)) {
				dy = -10;
			}
		}*/

		//moving camera
		/*if (y < h) {
			for (int i = 0; i < 10; i++) {
				y = h;
				platforms[i].y = platforms[i].y = -dy;
				if (platforms[i].y > 533) {
					platforms[i].y = 0;
					platforms[i].x = rand() % 500;
				}
			}
		}*/


		//doodle1.doodle_sprite.setPosition(x, y);


		window.clear();
		window.setView(view);

		//Making a background
		for (int i = 0; i < MAP_HEIGHT; i++) {
			for (int j = 0; j < MAP_WIDTH; j++){
				if (TileMap[i][j] == " ") {
					background_sprite.setTextureRect(IntRect(50, 50, 300, 300));
				}
				background_sprite.setPosition(j * 32, i * 32);
				window.draw(background_sprite);
			}
		}
		window.draw(doodle1.doodle_sprite);
		for (int i = 0; i < 10; i++) {
			platform_sprite.setPosition(platforms[i].x, platforms[i].y);
			window.draw(platform_sprite);
		}
		window.draw(platform_sprite);
		//window.draw(enemy.enemy_sprite);
		window.display();
	}

	return 0;
}