//TODO with classes for heroes
//problems with camera, menu
#include <SFML/Graphics.hpp>
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

	srand(time(0));

	//Set coordinates to platforms
	for (int i = 0; i < 10; i++) {
		platforms[i].x = rand() % 500;
		platforms[i].y = rand() % 500;
	}

	RenderWindow window(VideoMode(700, 780), "Doodle_Game");
	//RenderWindow window1(VideoMode(500, 500), "Doodle_Game", Style::Titlebar);
	menu(window);
	view.reset(FloatRect(0, 0, 700, 680));
	Font font;
	font.loadFromFile("f:/C++SFML/SFML_WIN/Shrifts/CyrilicOld.ttf");
	Text text("", font, 50);
	text.setFillColor(Color::Red);
	text.setStyle(Text::Bold | Text::Underlined);
	//window.setFramerateLimit(1500);

	//Downoload images from file
	Image background, platform, doodle_fire, start_backgr;
	background.loadFromFile("f:/C++SFML/SFML_WIN/images/background_fone.jpg");
	platform.loadFromFile("f:/C++SFML/SFML_WIN/images/Doodle_Platform_green.png");
	start_backgr.loadFromFile("f:/C++SFML/SFML_WIN/images/background_fone.jpg");
	platform.createMaskFromColor(Color::White);

	//Making textures from images
	Texture background_tex, platform_tex, start_bacg_tex;
	background_tex.loadFromImage(background);
	platform_tex.loadFromImage(platform);
	start_bacg_tex.loadFromImage(start_backgr);

	//Making sprites
	Sprite background_sprite, platform_sprite, start_backg_sprite;
	background_sprite.setTexture(background_tex);
	platform_sprite.setTexture(platform_tex);
	start_backg_sprite.setTexture(start_bacg_tex);
	

	Doodle doodle1("Doodler.png", 5, 5, 170, 150, 100, 100);// creating an object of class Doodle
	/*for (int i = 0; i < 10; i++) {
		platform_sprite.setPosition(platforms[i].x, platforms[i].y);
	}*/

	//Enemies enemy = Enemies(10, 10, 200, 190, platforms[3].x, platforms[3].y + 150);

	
	//Making a starting background with another window 
	/*while (window1.isOpen())
	{
		Event ev;
		while (window1.pollEvent(ev)) {
			if (Keyboard::isKeyPressed(Keyboard::Space)) {
				window1.close();
			}

			window1.clear();
			for (int i = 0; i < MAP_HEIGHT; i++) {
				for (int j = 0; j < MAP_WIDTH; j++) {
					if (FirstTileMap[i][j] == " ") {
						start_backg_sprite.setTextureRect(IntRect(50, 50, 100, 100));
					}
					start_backg_sprite.setPosition(j * 32, i * 32);
					window1.draw(start_backg_sprite);
				}
			}
		}
		//text.setString("Начать игру");
		//text.setPosition(100, 100);
	//	window1.draw(text);
		window1.display();
	}*/

	int x = 100, y = 100, h = 200;
	float dx = 0, dy = 0;


	//TODO problem with SFML_time
	Clock clock;
	//	float time = clock.getElapsedTime().asMicroseconds();

	//Main SFML loop for main window
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
		/*if ((Keyboard::isKeyPressed(Keyboard::Right)) || (Keyboard::isKeyPressed(Keyboard::D))) {
			doodle1.doodle_sprite.setTextureRect(IntRect(15, 15, 193, 180));
			doodle1.doodle_sprite.move(9.5, 0);
			//GetCoordForPlayer(100, 100);
		}
		if ((Keyboard::isKeyPressed(Keyboard::Left)) || (Keyboard::isKeyPressed(Keyboard::A))) {
			doodle1.doodle_sprite.setTextureRect(IntRect(208, 15, -193, 180));
			doodle1.doodle_sprite.move(-9.5, 0);
			//GetCoordForPlayer(100, 100);
		}
		if ((Keyboard::isKeyPressed(Keyboard::Up)) || (Keyboard::isKeyPressed(Keyboard::W))) {
			doodle1.doodle_sprite.move(0, -9.5);
			//GetCoordForPlayer(100, 100);
		}
		if ((Keyboard::isKeyPressed(Keyboard::Down)) || (Keyboard::isKeyPressed(Keyboard::S))) {
			doodle1.doodle_sprite.move(0, 9.5);
			//GetCoordForPlayer(100, 100);//for scrolling
		}*/
		//GetCoordForPlayer(doodle1.GetPositionX(), doodle1.GetPositionY());//for moving camera with hero
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			x += 10;
			doodle1.doodle_sprite.setTextureRect(IntRect(5, 5, 170, 150));
		}
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			x -= 10;
			doodle1.doodle_sprite.setTextureRect(IntRect(175, 15, -170, 150));
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
		}

		//TODO
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
	
		doodle1.doodle_sprite.setPosition(x, y);

		window.clear();
		//window.setView(view);
	
		//Making a background to play
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
		//window.draw(platform_sprite);
		//window.draw(enemy.enemy_sprite);
		window.display();
	}

	return 0;
}