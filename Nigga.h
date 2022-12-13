
#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"
void initBat(sf::RectangleShape& bat, const sf::Color batColor, const sf::Vector2f batPosition)
{
	bat.setSize(batsize);
	bat.setFillColor(batColor);
	bat.setPosition(batPosition);
}
void initball(sf::CircleShape& ball,const sf::Color ballcolor, const sf::Vector2f ballPosition) {
	ball.setRadius(ballradius);
	ball.setFillColor(ballColor);
	ball.setPosition(ballPosition);
}