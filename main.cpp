#include <SFML/Graphics.hpp>
using namespace sf;
#include "grid.hpp"
int width = 800;
int height = 800;
int numCells = 20;
bool play = 0;
Grid grid(numCells, numCells, width, height);
int main()
{
    RenderWindow window(VideoMode(width, height), "SFML works!");
    window.setFramerateLimit(5);
    CircleShape shape(100.f);
    shape.setFillColor(Color::Green);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event ::MouseButtonPressed)
            {
                if (event.mouseButton.button == Mouse::Left)
                {
                    int x = event.mouseButton.x;
                    int y = event.mouseButton.y;
                    grid.click(x, y);
                }
                if (event.mouseButton.button == Mouse::Right)
                {
                    play = !play;
                }
            }
        }

        window.clear(Color(51, 51, 51));
        if (play==1)
        {

        grid.update();
        }
        grid.drawTo(window);
        // window.draw(shape);
        window.display();
    }

    return 0;
}