#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
class Plants
{
protected:
	int x_coordinate;
	int y_coordinate;
	//Sprite s_plant;
	int lifetime;
	int price;
public:
	Plants();
	//Plants(int x, int y, Sprite&, int life, int price);
	int getx_coordinate() const;
	int gety_coordinate() const;
	int getLifetime() const;
	int getPrice() const;
	void setx_coordinate(int x);
	void sety_coordinate(int y);
	void setLifetime(int life);
	void setPrice(int price);


};

