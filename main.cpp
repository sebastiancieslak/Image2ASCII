//Written by
//Sebastian Cieslak
//09.2017

#include <iostream>
#include <fstream>
#include <cmath>
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
    string input;

    cout << "Input the name of image: " << endl;
    cin >> input;
    cout << endl;

    sf::Image img;
    if(!img.loadFromFile(input)) return 1;
    else cout << "Image loaded..." << endl;

    ofstream result("result.txt");

    char tab[] = " .,:;ox%#@";

    sf::Vector2u size_img;
    size_img = img.getSize();

    sf::Color pixel;
    int gray = 0;
    int num = 0;

    for(int i = 0; i < size_img.y; i++)
    {
        for(int j = 0; j < size_img.x; j++)
        {
            pixel = img.getPixel(j, i);
            gray = 0.2989 * pixel.r + 0.5870 * pixel.g + 0.1140 * pixel.b;
            num = floor(gray/25.6);
            result.put(tab[9 - num]);
        }
        result.put('\n');
    }

    result.close();

    cout << "Done." << endl;
    cout << endl;

    return 0;
}
