#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;
int main()
{
	//Making platforms
	struct plato {
		int x;
		int y;
	};

	struct plato platforms[100];

	//задаем рандомные координаты платформам
	for (int i = 0; i < 10; i++) {
		platforms[i].x = rand() % 500;
		platforms[i].y = rand() % 500;
	}

	srand(time(0));

	RenderWindow window(VideoMode(500, 500), "SFMLworks", Style::Fullscreen);
	
	Image doodle, background, platform, doodle_fire;
	doodle.loadFromFile("f:/C++SFML/SFML_WIN/images/Doodler.png");
	background.loadFromFile("f:/C++SFML/SFML_WIN/images/background_fone.jpg");
	platform.loadFromFile("f:/C++SFML/SFML_WIN/images/Doodle_Platform_green.png");
	platform.createMaskFromColor(Color::White);
	//doodle_im1.createMaskFromColor(Color(0, 0, 0));

	Texture doodle_tex, background_tex, platform_tex;
	doodle_tex.loadFromImage(doodle);
	background_tex.loadFromImage(background);
	platform_tex.loadFromImage(platform);

	Sprite doodle_sprite, background_sprite, platform_sprite;
	doodle_sprite.setTexture(doodle_tex);
	background_sprite.setTexture(background_tex);
	platform_sprite.setTexture(platform_tex);
	doodle_sprite.setTextureRect(IntRect(15, 15, 193, 180));
	background_sprite.setTextureRect(IntRect(0, 0, 300, 300));
	doodle_sprite.setPosition(500,500);
	
	


	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
				window.close();
		}

		if ((Keyboard::isKeyPressed(Keyboard::Right)) || (Keyboard::isKeyPressed(Keyboard::D))) {
			doodle_sprite.setTextureRect(IntRect(15, 15, 193, 180));
			doodle_sprite.move(0.1, 0);
		}
		if ((Keyboard::isKeyPressed(Keyboard::Left)) || (Keyboard::isKeyPressed(Keyboard::A))) {
			doodle_sprite.setTextureRect(IntRect(208, 15, -193, 180));
			doodle_sprite.move(-0.1, 0);
		}
		if ((Keyboard::isKeyPressed(Keyboard::Up)) || (Keyboard::isKeyPressed(Keyboard::W))) {
			doodle_sprite.move(0, -0.1);
		}
		if ((Keyboard::isKeyPressed(Keyboard::Down)) || (Keyboard::isKeyPressed(Keyboard::S))) {
			doodle_sprite.move(0, 0.1);
		}

		window.clear();
		window.draw(doodle_sprite);
		window.draw(background_sprite);
		for (int i = 0; i < 10; i++) {
			platform_sprite.setPosition(platforms[i].x, platforms[i].y);
			window.draw(platform_sprite);
		}

		//window.draw(platform_sprite);
		window.display();
	}

	return 0;
}