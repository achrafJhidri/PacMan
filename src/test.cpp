#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>

using namespace std; 
// j'ai envever le fichier jpeg.lib
int main()
{
	sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!", sf::Style::Default);
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	//glEnable(GL_TEXTURE_2D);


	sf::Texture texture; 
	if (!texture.loadFromFile("frog_1.png",sf::IntRect(0,0,100,100)))
	{
		cout << "merde alors " << endl;
	}
	texture.setSmooth(true);
	//texture.setRepeated(true);

	sf::Sprite sprite;
	sprite.setTexture(texture);
	//sprite.setColor(sf::Color::Red);
	
	//sprite.setOrigin(sf::Vector2f(25.f, 25.f));
	
	sprite.move(sf::Vector2f(100.f, 100.f));

	sf::FloatRect boundingBox = sprite.getGlobalBounds();

	//sprite.setOrigin(sf::Vector2f(30.f, 30.f));
	//sprite.rotate(-90.f);
	//sprite.setRotation(90.f);

	//sprite.setScale(1.5f, 1.5);
	//sprite.scale(1.5f, 1.5);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			
		}

		window.clear();
		//sprite.move(sf::Vector2f(10, 0));
		
		window.draw(sprite);
		window.display();
	}

	return 0;
}