#include <SFML/Graphics.hpp>

int main()
{
    // 800x600 boyutunda bir pencere oluþtur
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Basit Test");

    // Yarýçapý 100 olan bir daire oluþtur
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(300, 200); // (opsiyonel) pencere içinde konumunu ayarladýk

    // Oyun döngüsü
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Kapatma tuþuna basýlýrsa pencereyi kapat
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();           // Ekraný temizle
        window.draw(shape);       // Daireyi çiz
        window.display();         // Ekraný güncelle
    }

    return 0;
}
