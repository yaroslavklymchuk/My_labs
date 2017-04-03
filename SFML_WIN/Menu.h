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
	Texture StartButtonTexture, StartButtonBlueText, diraTexture, ExitTexture, Enemy1Texture, NameTexture, HelpInfoTexture, AboutDeveloperTexture, menuBackground, DoodleTexture, start_bacg_tex, SettingsButtonTexture, AboutButton_tex, tarelka_tex, HelpButtonTexture, PlatformTexture;
	
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
	tarelka_tex.loadFromImage(tarelkaIm);
	SettingsButtonTexture.loadFromImage(SettingsButtonImage);
	start_bacg_tex.loadFromImage(start_backgr);
	menuBackground.loadFromFile("f:/C++SFML/SFML_WIN/images/background_d.png");
	AboutButton_tex.loadFromFile("f:/C++SFML/SFML_WIN/images/aboutButton1.png");

	//loading sprites
	Sprite StartButtonSprite(StartButtonTexture), HelpInfoSprite(HelpInfoTexture), StartButtonBluespr(StartButtonBlueText), NameSprite(NameTexture), ExitSprite(ExitTexture), Enemy1Sprite(Enemy1Texture), diraSprite(diraTexture), AboutDeveloperSprite(AboutDeveloperTexture), DoodleSprite(DoodleTexture), PlatformSprite(PlatformTexture), HelpButtonSprite(HelpButtonTexture), menuBg(menuBackground), AboutButtonSprite(AboutButton_tex), tarelka_sprite(tarelka_tex), start_backg_sprite(start_bacg_tex), SettingsButtonSprite(SettingsButtonTexture);
	
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
	music.setLoop(true);

	bool isMenu = 1;
	int menuNum = 0;

	while (isMenu)
	{
		//StartButtonSprite.setColor(Color::White);
		menuNum = 0;
		window.clear(Color::White);

		if (IntRect(100, 30, 150, 90).contains(Mouse::getPosition(window))) { /*window.draw(StartButtonBluespr); window.display();*/ menuNum = 1; }
		if (IntRect(170, 490, 220, 520).contains(Mouse::getPosition(window))) {menuNum = 2; }
		if (IntRect(100, 600, 200, 670).contains(Mouse::getPosition(window))) { menuNum = 3; }
		if (IntRect(20, 350, 70, 410).contains(Mouse::getPosition(window))) { menuNum = 4; }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) isMenu = false;//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 2) { window.draw(AboutDeveloperSprite); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); }
			if (menuNum == 3) { window.close(); isMenu = false; }
			if (menuNum == 4) { window.draw(HelpInfoSprite); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape));}
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