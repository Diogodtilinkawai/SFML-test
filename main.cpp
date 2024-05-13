#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;
int main()
{
    RenderWindow window(VideoMode(800, 400), "SFML works!");
    window.setFramerateLimit(60);
    Texture yoshiTexture;

    if(!yoshiTexture.loadFromFile("assets/yoshinobg.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    yoshiTexture.setRepeated(true);

    Sprite yoshi;
    yoshi.setTexture(yoshiTexture);
    yoshi.setTextureRect(IntRect(0,0,800,181));
    int opacidad = 0;
    
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear(Color(51,51,51));
        window.draw(yoshi);
        yoshi.setColor(Color(255,255,255, opacidad % 256));
        window.display();
        opacidad++;
    }

    return 0;
}