#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <time.h>
#include "Map.h"

using namespace sf;

void menu(RenderWindow & window) {
	//Loading images
	Image StartButtonImage, start_backgr, SettingsButtonImage, tarelkaIm;
	
	StartButtonImage.loadFromFile("f:/C++SFML/SFML_WIN/images/startButton.png");
	SettingsButtonImage.loadFromFile("f:/C++SFML/SFML_WIN/images/settings1Button.png");
	start_backgr.loadFromFile("f:/C++SFML/SFML_WIN/images/background_fone.jpg");
	tarelkaIm.loadFromFile("f:/C++SFML/SFML_WIN/images/nlo.png");
	//im1.createMaskFromColor(Color::White);
	//StartButtonImage.createMaskFromColor(Color(243, 234, 225));

	//loading textures
	Texture Settings_info_tex, StartButtonTexture, StartButtonBlueText, diraTexture, ExitTexture, Enemy1Texture, NameTexture, HelpInfoTexture, AboutDeveloperTexture, menuBackground, DoodleTexture, start_bacg_tex, SettingsButtonTexture, AboutButton_tex, tarelka_tex, HelpButtonTexture, PlatformTexture;
	
	StartButtonTexture.loadFromImage(StartButtonImage);
	HelpInfoTexture.loadFromFile("f:/C++SFML/SFML_WIN/images/HelpInfo.png");
	StartButtonBlueText.loadFromFile("f:/C++SFML/SFML_WIN/images/StartButton_blue.png");
	Enemy1Texture.loadFromFile("f:/C++SFML/SFML_WIN/images/En1.png");
	NameTexture.loadFromFile("f:/C++SFML/SFML_WIN/images/Name.png");
	diraTexture.loadFromFile("f:/C++SFML/SFML_WIN/images/dira.png");
	ExitTexture.loadFromFile("f:/C++SFML/SFML_WIN/images/ExitButton.png");
	AboutDeveloperTexture.loadFromFile("f:/C++SFML/SFML_WIN/images/aboutButton.png");
	DoodleTexture.loadFromFile("f:/C++SFML/SFML_WIN/images/Doodler.png");
	PlatformTexture.loadFromFile("f:/C++SFML/SFML_WIN/images/Doodle_Platform_green.png");
	HelpButtonTexture.loadFromFile("f:/C++SFML/SFML_WIN/images/HelpButton.png");
	Settings_info_tex.loadFromFile("f:/C++SFML/SFML_WIN/images/Settings_info.png");
	tarelka_tex.loadFromImage(tarelkaIm);
	SettingsButtonTexture.loadFromImage(SettingsButtonImage);
	start_bacg_tex.loadFromImage(start_backgr);
	menuBackground.loadFromFile("f:/C++SFML/SFML_WIN/images/background_d.png");
	AboutButton_tex.loadFromFile("f:/C++SFML/SFML_WIN/images/aboutButton1.png");

	//loading sprites
	Sprite StartButtonSprite(StartButtonTexture), HelpInfoSprite(HelpInfoTexture), Settings_info_sprite(Settings_info_tex), StartButtonBluespr(StartButtonBlueText), NameSprite(NameTexture), ExitSprite(ExitTexture), Enemy1Sprite(Enemy1Texture), diraSprite(diraTexture), AboutDeveloperSprite(AboutDeveloperTexture), DoodleSprite(DoodleTexture), PlatformSprite(PlatformTexture), HelpButtonSprite(HelpButtonTexture), menuBg(menuBackground), AboutButtonSprite(AboutButton_tex), tarelka_sprite(tarelka_tex), start_backg_sprite(start_bacg_tex), SettingsButtonSprite(SettingsButtonTexture);
	
	StartButtonSprite.setTextureRect(IntRect(5, 10, 200, 100));
	//StartButtonBluespr.setTextureRect(IntRect(5, 10, 200, 100));
	NameSprite.setTextureRect(IntRect(5, 10, 270, 100));
	Enemy1Sprite.setTextureRect(IntRect(5, 5, 60, 30));
	ExitSprite.setTextureRect(IntRect(5, 10, 200, 100));
	SettingsButtonSprite.setTextureRect(IntRect(10, 20, 200, 120));
	DoodleSprite.setTextureRect(IntRect(5, 5, 170, 150));
	PlatformSprite.setTextureRect(IntRect(5, 5, 90, 25));
	AboutButtonSprite.setTextureRect(IntRect(10, 20, 200, 120));
	HelpButtonSprite.setTextureRect(IntRect(10, 10, 140, 120));
	diraSprite.setTextureRect(IntRect(5, 5, 80, 70));
	
	StartButtonSprite.setPosition(100, 30);
	//StartButtonBluespr.setPosition(100, 30);
	Enemy1Sprite.setPosition(450, 57);
	NameSprite.setPosition(200, 300);
	ExitSprite.setPosition(100, 600);
	PlatformSprite.setPosition(530,300);
	DoodleSprite.setPosition(520, 120);
	diraSprite.setPosition(500, 500);
	HelpButtonSprite.setPosition(20, 350);
	SettingsButtonSprite.setPosition(200, 200);
	AboutButtonSprite.setPosition(170, 490);
	menuBg.setPosition(100, 300);
	tarelka_sprite.setPosition(50, 120);

	Music music;
	music.openFromFile("f:/C++SFML/SFML_WIN/Music/Menu_music.ogg");
	music.play();
	music.setVolume(50);
	music.setLoop(true);
	
	

	

	bool isMenu = 1;
	int menuNum = 0;

	while (isMenu)
	{
		//StartButtonSprite.setColor(Color::White);
		menuNum = 0;
		window.clear(Color::White);

		if (Keyboard::isKeyPressed(Keyboard::F10)) {
			music.pause();
		}
		if (Keyboard::isKeyPressed(Keyboard::F9)) {
			music.play();
		}
		
		if (Keyboard::isKeyPressed(Keyboard::Subtract)){
			music.setVolume(music.getVolume() - 1);
		}
		if (Keyboard::isKeyPressed(Keyboard::Add)){
			music.setVolume(music.getVolume() + 1);
		}
		

		if (IntRect(100, 30, 150, 90).contains(Mouse::getPosition(window))) { /*window.draw(StartButtonBluespr); window.display();*/ menuNum = 1; }
		if (IntRect(170, 490, 220, 520).contains(Mouse::getPosition(window))) {menuNum = 2; }
		if (IntRect(100, 600, 200, 670).contains(Mouse::getPosition(window))) { menuNum = 3; }
		if (IntRect(20, 350, 70, 410).contains(Mouse::getPosition(window))) { menuNum = 4; }
		if (IntRect(80, 120, 250, 180).contains(Mouse::getPosition(window))) { menuNum = 5; }


		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) isMenu = false; 
			if (menuNum == 2) { window.draw(AboutDeveloperSprite); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); }
			if (menuNum == 3) { window.close(); isMenu = false; }
			if (menuNum == 4) { window.draw(HelpInfoSprite); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape));}
			if (menuNum == 5) {window.draw(Settings_info_sprite); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape));}
		}

		//window.draw(menuBg);
		window.draw(tarelka_sprite);
		window.draw(StartButtonSprite);
		window.draw(SettingsButtonSprite);
		window.draw(AboutButtonSprite);
		window.draw(HelpButtonSprite);
		window.draw(diraSprite);
		window.draw(DoodleSprite);
		window.draw(PlatformSprite);
		window.draw(ExitSprite);
		window.draw(Enemy1Sprite);
		window.draw(NameSprite);

		window.display();

	}

}

void GetStatistic(RenderWindow & window, Doodle obj, float a) {

		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			menu(window);
			//window1.close();
		}
		Image background;
		background.loadFromFile("f:/C++SFML/SFML_WIN/images/background.jpg");

		Texture background_tex;
		background_tex.loadFromImage(background);

		Sprite background_sprite;
		background_sprite.setTexture(background_tex);

		Font font;//шрифт 
		font.loadFromFile("f:/C++SFML/SFML_WIN/Shrifts/AmateurCamcorder.otf");//передаем нашему шрифту файл шрифта
		Text text("", font, 50);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
		text.setStyle(Text::Bold);

		Text text1("", font, 50);
		text1.setStyle(Text::Bold | Text::Underlined);
	

		std::ostringstream PlayerScoreString, PlayerTime;
		PlayerScoreString << obj.GetScore();
		PlayerTime << a;
		text.setPosition(200, 200);
		text1.setPosition(200, 400);
		text.setString("Your Score: " + PlayerScoreString.str() + "\n" + "Time in game: " + PlayerTime.str());
		text1.setString("Press Tab to restart");
		text1.setFillColor(Color::Blue);
		text.setFillColor(Color::Red);

		for (int i = 0; i < MAP_HEIGHT; i++) {
			for (int j = 0; j < MAP_WIDTH; j++) {
				if (TileMap[i][j] == ' ') {
					background_sprite.setTextureRect(IntRect(0, 0, 55, 43));//0,0,55,43
				}
				background_sprite.setPosition(j * 32, i * 32);
				window.draw(background_sprite);
			}
		}
		window.draw(text);
		window.draw(text1);
		//window.display();
	}

bool RestartFunctuion() {

	int max;
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
	window.setVerticalSyncEnabled(true);

	
	//Downoload images from file
	Image background, platform, doodle_fire, start_backgr, crush_platf, power_plat, moving_plat, enemy1_im;
	background.loadFromFile("f:/C++SFML/SFML_WIN/images/background.jpg");
	enemy1_im.loadFromFile("f:/C++SFML/SFML_WIN/images/enemy_3_.png");
	platform.loadFromFile("f:/C++SFML/SFML_WIN/images/Doodle_Platform_green.png");
	crush_platf.loadFromFile("f:/C++SFML/SFML_WIN/images/Doodle_Platform_crush.png");
	moving_plat.loadFromFile("f:/C++SFML/SFML_WIN/images/Doodle_Platforms_moving.png");
	power_plat.loadFromFile("f:/C++SFML/SFML_WIN/images/Doodle_Platform_power.png");
	start_backgr.loadFromFile("f:/C++SFML/SFML_WIN/images/background_fone.jpg");
	platform.createMaskFromColor(Color::White);
	enemy1_im.createMaskFromColor(Color::White);
	crush_platf.createMaskFromColor(Color::White);
	power_plat.createMaskFromColor(Color::White);
	moving_plat.createMaskFromColor(Color::White);

	//Making textures from images
	Texture background_tex, platform_tex, start_bacg_tex, crush_pl_tex, power_pl_tex, moving_pl_tex, enemy1_tex;
	background_tex.loadFromImage(background);
	enemy1_tex.loadFromImage(enemy1_im);
	platform_tex.loadFromImage(platform);
	moving_pl_tex.loadFromImage(moving_plat);
	crush_pl_tex.loadFromImage(crush_platf);
	power_pl_tex.loadFromImage(power_plat);
	start_bacg_tex.loadFromImage(start_backgr);

	//Making sprites
	Sprite background_sprite, platform_sprite, start_backg_sprite, moving_pl_spr, crush_pl_sprite, power_pl_sprite, enemy1_sprite;
	background_sprite.setTexture(background_tex);
	platform_sprite.setTexture(platform_tex);
	moving_pl_spr.setTexture(moving_pl_tex);
	enemy1_sprite.setTexture(enemy1_tex);
	crush_pl_sprite.setTexture(crush_pl_tex);
	power_pl_sprite.setTexture(power_pl_tex);
	start_backg_sprite.setTexture(start_bacg_tex);


	Doodle doodle("Doodler_1.png", 5, 5, 120, 120, 100, 100);// creating an object of class Doodle

	//TODO with Fone_music1.ogg//Menu_music is working
	/*Music music;
	music.openFromFile("f:/C++SFML/SFML_WIN/Music/Menu_music.ogg");
	music.play();
	music.setLoop(true);*/


	//Enemies enemy = Enemies(10, 10, 200, 190, 300, 300);


	int x = 100, y = 100, h = 200;
	float dy = 0;


	Clock clock;
	float TimeInGame = 0;

	//Main SFML loop for main window
	while (window.isOpen())
	{
		if (doodle.IsLife()) {

			float time = clock.getElapsedTime().asMicroseconds();
			float time1 = clock.getElapsedTime().asSeconds();
			clock.restart();
			time = time / 10000;

			TimeInGame += time1;

			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
					window.close();
			}

			if (Keyboard::isKeyPressed(Keyboard::Right)) {
				x += 7 * time;
				doodle.doodle_sprite.setTextureRect(IntRect(5, 5, 120, 120));
			}
			if (Keyboard::isKeyPressed(Keyboard::Left)) {
				x -= 7 * time;
				doodle.doodle_sprite.setTextureRect(IntRect(125, 5, -120, 120));
			}

			//moving upstairs
			dy += 0.25;//частота(скорость) прыжков
			y += dy;


			//making doodle to jump
			if (y > 720) {
				dy = -10;
			}


			if (Keyboard::isKeyPressed(Keyboard::A)) {
				//if (y > 120) {
				dy = -30; //good for flight
						  //}
			}

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
				doodle.SetScore(doodle.GetScore() + 1);//doodle1.player_score += 1;
			}




			/*if (y < h) {
			for (int i = 0; i < 5; i++) {
			y = h;
			crush_platforms[i].y = crush_platforms[i].y - dy;
			if (crush_platforms[i].y > 788) {
			crush_platforms[i].y = 0;
			crush_platforms[i].x = rand() % 700;
			}
			}
			}
			*/
			/*if (y < h) {
			for (int i = 0; i < 3; i++) {
			y = h;
			power_platforms[i].y = power_platforms[i].y - dy;
			if (power_platforms[i].y > 788) {
			power_platforms[i].y = 0;
			power_platforms[i].x = rand() % 700;
			}
			}
			}*/

			//jumping over the platforms

			for (int i = 0; i < 15; i++) {
				if ((x + 50 > platforms[i].x) && (x + 20 < platforms[i].x + 68) && (y + 70 > platforms[i].y) && (y + 70 < platforms[i].y + 14) && (dy > 0)) {
					dy = -10;
				}
			}


			//max = 0;
			int values[16];
			for (int i = 0; i < 15; i++) {
				values[i] = platforms[i].y;
			}

			for (int i = 0; i < 15; i++) {
				for (int j = 1; j < 15 - i; j++) {
					if (values[j] < values[j + 1]) {
						int tmp = values[j];
						values[j] = values[j + 1];
						values[j + 1] = tmp;
						max = values[j + 1];
					}
				}
			}


			/*
			for (int i = 0; i < 3; i++) {
			if ((x + 50 > power_platforms[i].x) && (x + 20 < power_platforms[i].x + 68) && (y + 70 > power_platforms[i].y) && (y + 70 < power_platforms[i].y + 14) && (dy > 0)) {
			dy = -10;
			}
			}
			for (int i = 0; i < 5; i++) {
			if ((x + 50 > crush_platforms[i].x) && (x + 20 < crush_platforms[i].x + 68) && (y + 70 > crush_platforms[i].y) && (y + 70 < crush_platforms[i].y + 14) && (dy > 0)) {
			dy = -10;
			}
			}*/

			doodle.doodle_sprite.setPosition(x, y);

			if (y > max) {
				doodle.SetLife(false);//doodle1.isLife = false;
			}

			window.clear();
			//window.setView(view);


			//Making a background to play
			for (int i = 0; i < MAP_HEIGHT; i++) {
				for (int j = 0; j < MAP_WIDTH; j++) {
					if (TileMap[i][j] == ' ') {
						background_sprite.setTextureRect(IntRect(0, 0, 55, 43));//0,0,55,43
					}
					background_sprite.setPosition(j * 32, i * 32);
					window.draw(background_sprite);
				}
			}
			window.draw(doodle.doodle_sprite);
			for (int i = 0; i < 15; i++) {
				platform_sprite.setPosition(platforms[i].x, platforms[i].y);
				window.draw(platform_sprite);
			}
			/*for (int i = 0; i < 5; i++) {
			crush_pl_sprite.setPosition(crush_platforms[i].x, crush_platforms[i].y);
			window.draw(crush_pl_sprite);
			}*/
			/*for (int i = 0; i < 3; i++) {
			power_pl_sprite.setPosition(power_platforms[i].x, power_platforms[i].y);
			window.draw(power_pl_sprite);
			}*/
			//window.draw(platform_sprite);
			//window.draw(enemy.enemy_sprite);
		}
		else {
			GetStatistic(window, doodle, TimeInGame);
		}

		if(Keyboard::isKeyPressed(Keyboard::Tab)){
			return true;
		}
		window.display();
	}
	//std::cout << doodle1.player_score <<"\n";
	/*std::cout << doodle1.isLife;
	std::cout << "\n";
	std::cout << max;
	std::cout << "\n";
	std::cout << y;*/
	system("pause");
}

void GameRunning() {
	if (RestartFunctuion()) {
		GameRunning();
	}
}