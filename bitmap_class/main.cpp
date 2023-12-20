#include <iostream>
#include "Bitmap.cpp"

using namespace std;
using namespace ab_bitmap;

int main() {
    int const WIDTH = 800;
    int const HEIGHT = 600;

	Bitmap bitmap(WIDTH, HEIGHT);

    // bitmap.setPixel(WIDTH/2, HEIGHT/2, 255, 255, 255);

    // for(int y=0; y < WIDTH; y++){
    //     for(int x=0; x < HEIGHT; x++){
    //         bitmap.setPixel(y, x, 255, 0, 0);
    //     }
    // }

	bitmap.write("test.bmp");

	cout << "Finished." << endl;
	return 0;
}