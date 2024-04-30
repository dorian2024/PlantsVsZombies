
//backup main
#include <SFML/Graphics.hpp>
#include <ctime>
//#include "../SFML/Images"

using namespace sf;
using namespace std;
const int xResolution = 1900;
const int yResolution = 1000;
const int boxPixels = 50;
//const int grassPixelsX = 250;
const int xRows = xResolution / boxPixels;
const int yRows = yResolution / boxPixels;
int gameRows[xRows][yRows] = {};

struct coordinates {
	int x;
	int y;
};
void moveLawnmower(coordinates lawnmower_coor[], sf::Clock& clock);

int main()
{
	//Drawing the background
	//DayBackground
	Image day_image;
	day_image.loadFromFile("../SFML/Images/background.png");
	Texture day;
	day.loadFromImage(day_image);
	Sprite s_day;
	s_day.setTexture(day);
	s_day.setPosition(0, 0);

	//NightBackground
	Image night_image;
	night_image.loadFromFile("../SFML/Images/nightbackground.png");
	Texture night;
	night.loadFromImage(night_image);
	Sprite s_night;
	s_night.setTexture(night);
	s_night.setPosition(0, 0);

	//startScreen
	Image start_screen;
	start_screen.loadFromFile("../SFML/Images/start.png");
	Texture start;
	start.loadFromImage(start_screen);
	Sprite s_start;
	s_start.setTexture(start);
	s_start.setPosition(0, 0);

	//fogScreen
	Image fog_image;
	fog_image.loadFromFile("../SFML/Images/fog2.png");
	Texture fog;
	fog.loadFromImage(fog_image);
	Sprite s_fog;
	s_fog.setTexture(fog);
	s_fog.setPosition(0, 0);
	sf::Color color = s_fog.getColor();
	color.a = 220;
	s_fog.setColor(color);

	//pauseScreen
	Image pause_image;
	pause_image.loadFromFile("../SFML/Images/pause.png");
	Texture pause;
	pause.loadFromImage(pause_image);
	Sprite s_pause;
	s_pause.setTexture(pause);
	s_pause.setPosition(0, 0);

	//Icons
		//peashooter
	Texture peaShooterIcon;
	peaShooterIcon.loadFromFile("../SFML/Images/img1.png");
	Sprite s_peaShooterIcon;
	s_peaShooterIcon.setTexture(peaShooterIcon);
	s_peaShooterIcon.setPosition(3 * boxPixels, 2 * boxPixels);

	//cabbagePult
	Texture cabbagePult;
	cabbagePult.loadFromFile("../SFML/Images/img3.png");
	Sprite s_cabbagePult;
	s_cabbagePult.setTexture(cabbagePult);
	s_cabbagePult.setPosition(3 * boxPixels, 4 * boxPixels);

	//wallnut
	Texture wallnut;
	wallnut.loadFromFile("../SFML/Images/img6.png");
	Sprite s_wallnut;
	s_wallnut.setTexture(wallnut);
	s_wallnut.setPosition(3 * boxPixels, 6 * boxPixels);

	//sunflower
	Texture sunflower;
	sunflower.loadFromFile("../SFML/Images/img2.png");
	Sprite s_sunflower;
	s_sunflower.setTexture(sunflower);
	s_sunflower.setPosition(3 * boxPixels, 8 * boxPixels);

	//lawnmower
	Texture lawnmower;
	lawnmower.loadFromFile("../SFML/Images/lawnmower.png");
	Sprite s_lawnmower;
	s_lawnmower.setTexture(lawnmower);
	
	//zombie
	Texture zombie;
	zombie.loadFromFile("../SFML/Images/zombie.png");
	Sprite s_zombie;
	s_zombie.setTexture(zombie);

	//menu icon
	Texture menu;
	menu.loadFromFile("../SFML/Images/menuicon.png");
	Sprite s_menu;
	s_menu.setTexture(menu);
	s_menu.setPosition(32 * boxPixels, boxPixels);

	//initialising window
	sf::RenderWindow window(sf::VideoMode(xResolution, yResolution), "PlantsVsZombies", sf::Style::Close | sf::Style::Titlebar);
	window.setSize(sf::Vector2u(xResolution, yResolution));
	window.setPosition(sf::Vector2i(0, 0));

	Clock timeMoney;
	Clock clock;
	bool gameStarted = false;
	bool gamePause = false;
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		float moneyTime = timeMoney.getElapsedTime().asSeconds();
		

		clock.restart();
		time = time / 800;
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		//Create a background
		if (gameStarted == false && gamePause == false) {
			window.draw(s_start);
		}
		else if (gamePause == true) {
			window.draw(s_pause);
		}
		else {
			window.draw(s_day);
			//window.draw(s_fog);
			window.draw(s_peaShooterIcon);
			window.draw(s_cabbagePult);
			window.draw(s_wallnut);
			window.draw(s_sunflower);
			coordinates* lawnmower_coor;
			window.draw(s_lawnmower);

			lawnmower_coor = new coordinates[6];
			for (int i = 0; i < 5; i++) {
				lawnmower_coor[i].x = 9 * boxPixels;
				lawnmower_coor[i].y = (5 + 3 * i) * boxPixels;
				s_lawnmower.setPosition(lawnmower_coor[i].x, lawnmower_coor[i].y);

				window.draw(s_lawnmower);
			}
			window.draw(s_fog);

			window.draw(s_menu);
			window.draw(s_zombie);
			
			//moveLawnmower(lawnmower_coor, clock);
		


			//window.draw(s_fog);
			Mouse mouse;
			if (mouse.isButtonPressed(mouse.Button::Left)) {
				int mousePositionX = mouse.getPosition(window).x;
				int mousePositionY = mouse.getPosition(window).y;
				if (mousePositionX >= 32 * boxPixels && mousePositionX <= 36 * boxPixels && mousePositionY >= boxPixels && mousePositionY <= 2 * boxPixels) {
					gamePause = true;
				}
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			gameStarted = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
			gamePause = false;
		}
		window.setSize(sf::Vector2u(xResolution, yResolution));
		window.display();
	}
	
	//delete lawnmower_coor; //fix to acommodate file handling
	return 0;
}


void moveLawnmower(coordinates lawnmower_coor[], sf::Clock& clock)
{


	/*if (clock.getElapsedTime().asMilliseconds() < 12)
		return 0;
	clock.restart();*/

	lawnmower_coor[0].x -= 50;

	if (lawnmower_coor[0].x == 37*boxPixels)
	{
		return;
	}
	
}

//void drawLawnmower(sf::RenderWindow& window, float bullet[], sf::Sprite& bulletSprite)
//{
//
//	bulletSprite.setPosition(bullet[x], bullet[y]);
//	window.draw(bulletSprite);
//}