#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>


using namespace sf;

View view;
View GetCoordForPlayer(float x, float y) {
	view.setCenter(x + 100, y + 100);
	return view;
}


