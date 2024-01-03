#include <iostream>
#include <cstdint>
#include "Bitmap.cpp"
#include "Mandelbrot.cpp"
#include "ZoomList.cpp"

using namespace std;
using namespace ab_bitmap;

int main() {
    int const WIDTH = 800;
    int const HEIGHT = 600;

	Bitmap bitmap(WIDTH, HEIGHT);

    // bitmap.setPixel(WIDTH/2, HEIGHT/2, 255, 255, 255);

    double min = 999999;
    double max = -999999;

    ZoomList zoomList(WIDTH, HEIGHT);

    zoomList.add(Zoom(WIDTH/2, HEIGHT/2, 4.0/WIDTH));
    zoomList.add(Zoom(295, HEIGHT - 202, 0.1));
    zoomList.add(Zoom(312, HEIGHT - 304, 0.1));

    unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS]{0});
    unique_ptr<int[]> fractal(new int[WIDTH*HEIGHT]{0});

    // fill(histogram.get(), histogram.get() + Mandelbrot::MAX_ITERATIONS, 0);
	// fill(fractal.get(), fractal.get() + WIDTH*HEIGHT, 0);

    // saving values in [], histograms and iterations
    for(int y=0; y < HEIGHT; y++){
        for(int x=0; x < WIDTH; x++){
            // double xFractal = (x - WIDTH/2 - 200) * 2.0/HEIGHT;
            // double yFractal = (y - HEIGHT/2) * 2.0/HEIGHT;

            pair<double, double> coords = zoomList.doZoom(x, y);

            int iterations = Mandelbrot::getIterations(coords.first, coords.second);

            fractal[y*WIDTH+x] = iterations;

            if (iterations != Mandelbrot::MAX_ITERATIONS){
                histogram[iterations]++;
            }
        }
    }

    
    int total = 0;
    for(int i=0; i <= Mandelbrot::MAX_ITERATIONS; i++){
        total += histogram[i];
    }

    for(int y=0; y < HEIGHT; y++){
        for(int x=0; x < WIDTH; x++){

            uint8_t red = 0;
            uint8_t green = 0;
            uint8_t blue = 0;

            int iterations = fractal[y * WIDTH + x];

            if(iterations != Mandelbrot::MAX_ITERATIONS){

            double hue = 0.0;

            for(int i=0; i<= iterations; i++){
                hue += ((double)histogram[i])/total;
            }

            green = pow(255, hue);
            }

            bitmap.setPixel(x, y, red, green, blue);
        }
    }
  

	bitmap.write("test.bmp");

	std::cout << "Finished." << endl;

	return 0;
}