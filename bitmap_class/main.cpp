#include <iostream>
#include "FractalCreator.cpp"
#include "RGB.cpp"

using namespace std;
using namespace ab_bitmap;

int main() {
    FractalCreator fractalCreator(800, 600);

    fractalCreator.addRange(0.0, RGB(0, 0, 255));
	fractalCreator.addRange(0.05, RGB(128, 99, 71));
	fractalCreator.addRange(0.08, RGB(225, 215, 0));
	fractalCreator.addRange(1.0, RGB(255, 255, 255));

    fractalCreator.addZoom(Zoom(295, 202, 0.1));
	fractalCreator.addZoom(Zoom(312, 304, 0.1));

    fractalCreator.run("test.bmp");
    cout << "Finished." << endl;

    return 0;
}