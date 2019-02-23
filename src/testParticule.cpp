#include <SFML/Graphics.hpp>
#include "ParticleSystem.h"



int main()
{
	// on cr�e la fen�tre
	sf::RenderWindow window(sf::VideoMode(512, 256), "Particles");

	// on cr�e un syst�me de 1000 particules
	ParticleSystem particles(1000);

	// on cr�e un chrono pour mesurer le temps �coul�
	sf::Clock clock;

	// on fait tourner la boucle principale
	while (window.isOpen())
	{
		// on g�re les �v�nements
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// on fait en sorte que l'�metteur des particules suive la souris
		sf::Vector2i mouse = sf::Mouse::getPosition(window);
		particles.setEmitter(window.mapPixelToCoords(mouse));

		// on met � jour le syst�me de particules
		sf::Time elapsed = clock.restart();
		particles.update(elapsed);

		// on le dessine
		window.clear();
		window.draw(particles);
		window.display();
	}

	return 0;
}