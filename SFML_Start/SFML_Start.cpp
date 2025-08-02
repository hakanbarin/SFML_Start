#include <SFML/Graphics.hpp>

int main()
{
    // 800x600 boyutunda bir pencere olu�tur
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Basit Test");

    // Yar��ap� 100 olan bir daire olu�tur
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(300, 200); // (opsiyonel) pencere i�inde konumunu ayarlad�k

    // Oyun d�ng�s�
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Kapatma tu�una bas�l�rsa pencereyi kapat
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();           // Ekran� temizle
        window.draw(shape);       // Daireyi �iz
        window.display();         // Ekran� g�ncelle
    }

    return 0;
}
