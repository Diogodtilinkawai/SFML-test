#ifndef grid_h
#define grid_h
#include <SFML/Graphics.hpp>
#include <Vector>
using namespace sf;
using namespace std;
class Grid{
    vector<vector<int>> grid;
    int rows,cols;
    int sizeX, sizeY;
    public:
    Grid(int rows,int cols);
    Grid(int rows,int cols, int width, int height);
    void drawTo(RenderWindow &window);
    void click(int x, int y);
};
#endif