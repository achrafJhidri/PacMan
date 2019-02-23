#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;


int main() {



	sf::Texture texture;
	if (!texture.loadFromFile("frog_0.png"))
	{
		// erreur...
	}


	sf::RenderWindow  window(sf::VideoMode(800, 600), "Exo1");

	/*sf::CircleShape circle(110);
	circle.move(sf::Vector2f(50, 50));
	circle.setFillColor(sf::Color::Red);
	circle.setOutlineThickness(15);
	circle.setOutlineColor(sf::Color::Green);
	circle.setPointCount(550);
	circle.setPosition(sf::Vector2f(200, 200));
	circle.setRadius(55);
	circle.setScale(sf::Vector2f(2.5, 2.5));
	circle.setRotation(30);
	circle.setOrigin(circle.getOrigin());

	circle.setTexture(&texture, true);*/


	sf::VertexArray truc(sf::PrimitiveType::TrianglesStrip);
	Vector2f pA(30.0, 20.0);
	Vector2f pB(110.0, 100.0);
	Vector2f pC(150.0, 200.0);
	Color couleurA = Color::Yellow;
	Color couleurB = Color::Red;
	Color couleurC = Color::Blue;
	Vertex A(pA, couleurA);
	Vertex B(pB, couleurB);
	Vertex C(pC, couleurC);
	truc.append(A);
	truc.append(B);
	truc.append(C);
	

	while (window.isOpen()) {


		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			//if (event.type == sf::Event::MouseButtonPressed)
			//{
			//	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			//	{
			//		sf::Vector2i globalPosition = sf::Mouse::getPosition();
			//		cout << "position de la souris (" << globalPosition.x << "," << globalPosition.y << ")" << endl;
			//	}
			//	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
			//	{
			//		
			//		cout << "Right Button Clicked" << endl;
			//	}
			//	if (sf::Mouse::isButtonPressed(sf::Mouse::Middle))
			//	{

			//		cout << "Middle Button Clicked" << endl;
			//	}
			//	if (sf::Mouse::isButtonPressed(sf::Mouse::XButton1))
			//	{

			//		cout << "extra1 Button Clicked" << endl;
			//	}
			//	if (sf::Mouse::isButtonPressed(sf::Mouse::XButton2))
			//	{

			//		cout << "extra2 Button Clicked" << endl;
			//	}
			//}

			//if (event.type == sf::Event::KeyPressed) {
			//	if (event.key.code == sf::Keyboard::Left)
			//	{
			//		circle.setPosition(sf::Vector2f(circle.getPosition().x - 5, circle.getPosition().y ));
			//	}
			//	if (event.key.code == sf::Keyboard::Right)
			//	{
			//		circle.setPosition(sf::Vector2f(circle.getPosition().x + 5, circle.getPosition().y));
			//	}
			//	if (event.key.code == sf::Keyboard::Up)
			//	{
			//		circle.setPosition(sf::Vector2f(circle.getPosition().x , circle.getPosition().y-5));
			//	}
			//	if (event.key.code == sf::Keyboard::Down)
			//	{
			//		circle.setPosition(sf::Vector2f(circle.getPosition().x, circle.getPosition().y + 5));
			//	}

			//	sf::Event::KeyEvent touche = event.key;
			//	sf::Keyboard::Key code = touche.code;
			//	bool shiftEstAppuye = touche.shift;
			//	cout << "touche enfoncée = " << (int)code << ", " << (char)code << endl;

			//	if (code == sf::Keyboard::Key::Num5) cout << "touche 5 principale enfoncée" << endl;
			//	if (code == sf::Keyboard::Key::Numpad5) cout << "touche 5 pavé numérique enfoncée" << endl;
			//}

		}
		window.clear();
		//window.draw(circle);
		window.draw(truc);
		window.display();
		

	}




}