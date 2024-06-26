#ifndef grid_h
#define grid_h
#include <SFML/Graphics.hpp>
#include <Vector>
using namespace sf;
using namespace std;
class Grid{
    vector<vector<int>> grid;
    vector<vector<int>> next;
    int rows,cols;
    int sizeX, sizeY;
    public:
    Grid(int rows,int cols);
    Grid(int rows,int cols, int width, int height);

    void update();
    void drawTo(RenderWindow &window);
    void click(int x, int y);
    int contarVecinos(int i, int j);
};
#endif