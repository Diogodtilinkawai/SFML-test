#include "Grid.hpp"

Grid::Grid(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
    for (int i = 0; i < rows; i++)
    {
        this->grid.push_back({});
        for (int j = 0; j < cols; j++)
        {
            this->grid[i].push_back(0);
        }
    }
    this->next = vector<vector<int>>(rows, vector<int>(cols, 0));
}

void Grid::drawTo(RenderWindow &window)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            /*
            crear un cuadrado RectangleSahpe
            le damos un borde Setoutlinecolor
            fijamos su posicion al lugar correspondiente
            */
            RectangleShape rect(Vector2f(sizeX, sizeY));
            rect.setOutlineColor(Color::White);
            if (grid[j][i] == 0)
            {
                rect.setFillColor(Color(05, 04, 24));
            }
            else
            {
                rect.setFillColor(Color::White);
            }
            rect.setOutlineThickness(1);
            rect.setPosition(Vector2f(j * rect.getSize().x, i * rect.getSize().y));
            // rect.setPosition(Vector2f(j*40,i*40));
            window.draw(rect);
        }
    }
}
Grid::Grid(int rows, int cols, int width, int height)
{
    this->rows = rows;
    this->cols = cols;
    this->sizeX = width / cols;
    this->sizeY = height / rows;
    for (int i = 0; i < rows; i++)
    {
        this->grid.push_back({});
        for (int j = 0; j < cols; j++)
        {
            this->grid[i].push_back(0);
        }
    }
    this->next = vector<vector<int>>(rows, vector<int>(cols, 0));
}
void Grid::click(int x, int y)
{
    int indexX = x / this->sizeX;
    int indexY = y / this->sizeY;
    grid[indexX][indexY] = (grid[indexX][indexY] + 1) % 2;
}
void Grid::update()
{
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            int vecinos = this->contarVecinos(i, j);
            if (grid[i][j] == 0) // muerta
            {
                if (vecinos == 3)
                {
                    next[i][j] = 1; // nace
                }
                else
                {
                    next[i][j] = 0;
                }
            }
            else // viva
            {
                if (vecinos > 3)
                {
                    next[i][j] = 0; // muere sobrepobalcion
                }
                if (vecinos < 2)
                {
                    next[i][j] = 0; // muere solo
                }
                if (2 <= vecinos && vecinos <= 3)
                {
                    next[i][j] = 1; // sigue viva
                }
            }
        }
    }
    this->grid = this->next;
}
int Grid::contarVecinos(int i, int j)
{
    int c = 0;
    if (j > 1 && i < cols - 2 && grid[i + 1][j - 1])
    {

        c++;
    }
    if (i != cols - 1 && grid[i + 1][j])
    {

        c++;
    }
    if (j != rows - 1 && i != cols - 1 && grid[i + 1][j + 1])
    {

        c++;
    }
    if (j != rows - 1 && grid[i][j + 1])
    {

        c++;
    }
    if (i != 0 && grid[i - 1][j])
    {

        c++;
    }
    if (i != 0 && j != 0 && grid[i - 1][j - 1])
    {

        c++;
    }
    if (j != 0 && grid[i][j - 1])
    {

        c++;
    }
    if (i != 0 && j != rows - 1 && grid[i - 1][j + 1])
    {

        c++;
    }
    return c;
}
