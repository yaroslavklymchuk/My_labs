//TODO with classes for heroes
#include <SFML/Graphics.hpp>
#include <time.h>
#include "Heroes.h"

using namespace sf;
int main()
{
	//Making platforms
	struct plato {
		int x;
		int y;
	};

	struct plato platforms[100];

	//srand(time(0));

	//Set coordinates to platforms
	for (int i = 0; i < 10; i++) {
		platforms[i].x = rand() % 500;
		platforms[i].y = rand() % 500;
	}

	RenderWindow window(VideoMode(500, 500), "SFMLworks", Style::Fullscreen);
	//window.setFramerateLimit(1500);

	Image background, platform, doodle_fire;
	background.loadFromFile("f:/C++SFML/SFML_WIN/images/background_fone.jpg");
	platform.loadFromFile("f:/C++SFML/SFML_WIN/images/Doodle_Platform_green.png");
	platform.createMaskFromColor(Color::White);

	Texture background_tex, platform_tex;
	background_tex.loadFromImage(background);
	platform_tex.loadFromImage(platform);

	Sprite background_sprite, platform_sprite;
	background_sprite.setTexture(background_tex);
	platform_sprite.setTexture(platform_tex);
	background_sprite.setTextureRect(IntRect(0, 0, 300, 300));

	Doodle doodle1("Doodler.png", 15, 15, 193, 180, 100,100);
	for (int i = 0; i < 10; i++) {
		platform_sprite.setPosition(platforms[i].x, platforms[i].y);
	}

	Enemies enemy = Enemies(10, 10, 200, 190, platforms[3].x, platforms[3].y + 150);
	

	
	//TODO problem with SFML_time
	Clock clock;
//	float time = clock.getElapsedTime().asMicroseconds();
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

		if ((Keyboard::isKeyPressed(Keyboard::Right)) || (Keyboard::isKeyPressed(Keyboard::D))) {
			doodle1.doodle_sprite.setTextureRect(IntRect(15, 15, 193, 180));
			doodle1.doodle_sprite.move(0.1, 0);
		}
		if ((Keyboard::isKeyPressed(Keyboard::Left)) || (Keyboard::isKeyPressed(Keyboard::A))) {
			doodle1.doodle_sprite.setTextureRect(IntRect(208, 15, -193, 180));
			doodle1.doodle_sprite.move(-0.1, 0);
		}
		if ((Keyboard::isKeyPressed(Keyboard::Up)) || (Keyboard::isKeyPressed(Keyboard::W))) {
			doodle1.doodle_sprite.move(0, -0.1);
		}
		if ((Keyboard::isKeyPressed(Keyboard::Down)) || (Keyboard::isKeyPressed(Keyboard::S))) {
			doodle1.doodle_sprite.move(0, 0.1);
		}

		window.clear();
		window.draw(doodle1.doodle_sprite);
	//	window.draw(background_sprite);
		for (int i = 0; i < 10; i++) {
			platform_sprite.setPosition(platforms[i].x, platforms[i].y);
			window.draw(platform_sprite);
		}
		window.draw(platform_sprite);
		window.draw(enemy.enemy_sprite);
		window.display();
	}

	return 0;
}