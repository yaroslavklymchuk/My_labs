//TODO with classes for heroes
//problems with other types of platforms
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include "Heroes.h"
#include "Map.h"
#include "View.h"
#include "Menu.h"

using namespace sf;
int main()
{
	//Making platforms
	struct plato {
		int x;
		int y;
	};

	struct plato platforms[100];
	struct plato crush_platforms[100];
	struct plato power_platforms[100];

	srand(time(0));

	//Set coordinates to platforms
	for (int i = 0; i < 15; i++) {
		platforms[i].x = rand() % 700;
		platforms[i].y = rand() % 780;
	}
	for (int i = 0; i < 5; i++) {
		crush_platforms[i].x = rand() % 700;
		crush_platforms[i].y = rand() % 780;
	}
	for (int i = 0; i < 3; i++) {
		power_platforms[i].x = rand() % 700;
		power_platforms[i].y = rand() % 780;
	}

	RenderWindow window(VideoMode(700, 780), "Doodle_Game");
	menu(window);
	

	//Downoload images from file
	Image background, platform, doodle_fire, start_backgr, crush_platf, power_plat, enemy1_im;
	background.loadFromFile("f:/C++SFML/SFML_WIN/images/background_fone.jpg");
	enemy1_im.loadFromFile("f:/C++SFML/SFML_WIN/images/enemy_3_.png");
	platform.loadFromFile("f:/C++SFML/SFML_WIN/images/Doodle_Platform_green.png");
	crush_platf.loadFromFile("f:/C++SFML/SFML_WIN/images/Doodle_Platform_crush.png");
	power_plat.loadFromFile("f:/C++SFML/SFML_WIN/images/Doodle_Platform_power.png");
	start_backgr.loadFromFile("f:/C++SFML/SFML_WIN/images/background_fone.jpg");
	platform.createMaskFromColor(Color::White);
	enemy1_im.createMaskFromColor(Color::White);
	crush_platf.createMaskFromColor(Color::White);
	power_plat.createMaskFromColor(Color::White);

	//Making textures from images
	Texture background_tex, platform_tex, start_bacg_tex, crush_pl_tex, power_pl_tex, enemy1_tex;
	background_tex.loadFromImage(background);
	enemy1_tex.loadFromImage(enemy1_im);
	platform_tex.loadFromImage(platform);
	crush_pl_tex.loadFromImage(crush_platf);
	power_pl_tex.loadFromImage(power_plat);
	start_bacg_tex.loadFromImage(start_backgr);

	//Making sprites
	Sprite background_sprite, platform_sprite, start_backg_sprite, crush_pl_sprite, power_pl_sprite, enemy1_sprite;
	background_sprite.setTexture(background_tex);
	platform_sprite.setTexture(platform_tex);
	enemy1_sprite.setTexture(enemy1_tex);
	crush_pl_sprite.setTexture(crush_pl_tex);
	power_pl_sprite.setTexture(power_pl_tex);
	start_backg_sprite.setTexture(start_bacg_tex);
	

	Doodle doodle1("Doodler_1.png", 5, 5, 120, 120, 100, 100);// creating an object of class Doodle
	

	//Enemies enemy = Enemies(10, 10, 200, 190, 300, 300);
	
	
	int x = 100, y = 100, h = 200;
	float dx = 0, dy = 0;


	//TODO problem with SFML_time
//	Clock clock;

	//Main SFML loop for main window
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			/*float time = clock.getElapsedTime().asMicroseconds();
			clock.restart();
			time = time / 800;*/
			if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			x += 15;
			doodle1.doodle_sprite.setTextureRect(IntRect(5, 5, 120, 120));
		}
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			x -= 15;
			doodle1.doodle_sprite.setTextureRect(IntRect(125, 5, -120, 120));
		}

		//moving upstairs
		dy += 0.25;
		y += dy;

		if (y > 720) {
			dy = -10; //the high of a doodle's jump
		}
		//Very good for making speedy platforms!!!		
		/*if (y > 700) {
			dy = -20;
		}*/

		//moving camera
		if (y < h) {
			for (int i = 0; i < 15; i++) {
				y = h;
				platforms[i].y = platforms[i].y - dy;
				if (platforms[i].y > 788) {
					platforms[i].y = 0;
					platforms[i].x = rand() % 700;
				}
			}
		}

/*		if (y < h) {
			for (int i = 0; i < 5; i++) {
				y = h;
				crush_platforms[i].y = crush_platforms[i].y - dy;
				if (crush_platforms[i].y > 788) {
					crush_platforms[i].y = 0;
					crush_platforms[i].x = rand() % 700;
				}
			}
		}

		if (y < h) {
			for (int i = 0; i < 3; i++) {
				y = h;
				power_platforms[i].y = power_platforms[i].y - dy;
				if (power_platforms[i].y > 788) {
					power_platforms[i].y = 0;
					power_platforms[i].x = rand() % 700;
				}
			}
		}
		*/
		//jumping over the platforms
		for (int i = 0; i < 15; i++) {
			if ((x + 50 > platforms[i].x) && (x + 20 < platforms[i].x + 68) && (y + 70 > platforms[i].y) && (y + 70 < platforms[i].y + 14) && (dy > 0)) {
				dy = -10;
			}
		}

		/*for (int i = 0; i < 3; i++) {
			if ((x + 50 > power_platforms[i].x) && (x + 20 < power_platforms[i].x + 68) && (y + 70 > power_platforms[i].y) && (y + 70 < power_platforms[i].y + 14) && (dy > 0)) {
				dy = -10;
			}
		}

		for (int i = 0; i < 5; i++) {
			if ((x + 50 > crush_platforms[i].x) && (x + 20 < crush_platforms[i].x + 68) && (y + 70 > crush_platforms[i].y) && (y + 70 < crush_platforms[i].y + 14) && (dy > 0)) {
				dy = -10;
			}
		}*/

		doodle1.doodle_sprite.setPosition(x, y);

		window.clear();
		//window.setView(view);
	
		//Making a background to play
		for (int i = 0; i < MAP_HEIGHT; i++) {
			for (int j = 0; j < MAP_WIDTH; j++){
				if (TileMap[i][j] == " ") {
					background_sprite.setTextureRect(IntRect(50, 50, 300, 300));
				}
				/*if (TileMap[i][j] == "s") {
					enemy1_sprite.setTextureRect(IntRect(5, 5, 80, 80));
				}*/
				background_sprite.setPosition(j * 32, i * 32);
				//enemy1_sprite.setPosition(i * 32, j * 32);
				window.draw(background_sprite);
				//window.draw(enemy1_sprite);
			}
		}
		window.draw(doodle1.doodle_sprite);
		for (int i = 0; i < 15; i++) {
			platform_sprite.setPosition(platforms[i].x, platforms[i].y);
			window.draw(platform_sprite);
		}
		/*for (int i = 0; i < 5; i++) {
			crush_pl_sprite.setPosition(crush_platforms[i].x, crush_platforms[i].y);
			window.draw(crush_pl_sprite);
		}
		for (int i = 0; i < 3; i++) {
			power_pl_sprite.setPosition(power_platforms[i].x, power_platforms[i].y);
			window.draw(power_pl_sprite);
		}*/
		//window.draw(platform_sprite);
	//	window.draw(enemy.enemy_sprite);
		window.display();
	}

	return 0;
}