#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>

using namespace sf;


class Doodle
{
public:
	Sprite doodle_sprite;
	/*int player_score = 0;
	bool isLife = true;*/
	Doodle(String, float, float, float, float, float, float, bool, float);
	inline float GetPositionX() {
		return positionX;
	}
	inline float GetPositionY() {
		return positionY;
	}
	float GetScore() {
		return player_score;
	}
	Doodle & SetScore(float a) {
		player_score = a;
		return *this;
	}
	bool IsLife() {
		return isLife;
	}
	Doodle & SetLife(bool a) {
		isLife = a;
		return *this;
	}
	~Doodle();

private:
	float x_l, y_l, x_r, y_r, positionX, positionY;
	int player_score = 0;
	bool isLife = true;
	String file_name;
	Image doodle_im;
	Texture doodle_tex;
};

Doodle::Doodle(String file, float x_left, float y_left, float x_right, float y_right, float x_, float y_, bool islife = 1, float player_score = 0){
	doodle_im.loadFromFile("f:/C++SFML/SFML_WIN/images/" + file);
	doodle_im.createMaskFromColor(Color::White);
	doodle_tex.loadFromImage(doodle_im);
	doodle_sprite.setTexture(doodle_tex);
	x_l = x_left;
	y_l = y_left;
	x_r = x_right;
	y_r = y_right;
	positionX = x_;
	positionY = y_;
	doodle_sprite.setTextureRect(IntRect(x_l, y_l, x_r, y_r));
	doodle_sprite.setPosition(positionX, positionY);
}

Doodle::~Doodle(){

}

class Enemies{

public:
	Sprite enemy_sprite;
	Enemies(float, float, float, float, float, float);
	~Enemies();

private:
	float x_l, y_l, x_r, y_r, positionX, positionY;
	//String file_names [20];
	Image enemy_im;
	Texture enemy_tex;
};

Enemies::Enemies(float x_left, float y_left, float x_right, float y_right, float x_, float y_) {
	String file[5];
	file[0] = "enemy_1.png";
	file[1] = "enemy_2.png";
	file[2] = "enemy_3_.png";
	file[3] = "enemy_4.png";
	file[4] = "enemy_5.png";
	
	srand(time(0));
	int i = 0;
	i = rand() % 5;
	enemy_im.loadFromFile("f:/C++SFML/SFML_WIN/images/" + file[i]);
	enemy_im.createMaskFromColor(Color::White);
	enemy_tex.loadFromImage(enemy_im);
	enemy_sprite.setTexture(enemy_tex);
	x_l = x_left;
	y_l = y_left;
	x_r = x_right;
	y_r = y_right;
	positionX = x_;
	positionY = y_;
	enemy_sprite.setTextureRect(IntRect(x_l, y_l, x_r, y_r));
	enemy_sprite.setPosition(positionX, positionY);
}

Enemies::~Enemies(){

}