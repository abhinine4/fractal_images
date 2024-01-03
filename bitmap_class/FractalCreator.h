#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include <cstdint>
#include <string>
#include <memory>
#include "Zoom.h"
#include "Bitmap.cpp"
#include "Mandelbrot.cpp"
#include "ZoomList.cpp"

using namespace std;

namespace ab_bitmap{
class FractalCreator{
    private:
        int m_width;
        int m_height;
        unique_ptr<int[]> m_histogram;
        unique_ptr<int[]> m_fractal;
        Bitmap m_bitmap;
        ZoomList m_zoomList;
        int m_total{0};

    public:
        FractalCreator(int width, int height);
        virtual ~FractalCreator();

        void calculateIteration();
        void calculateTotalIteration();
        void drawFractal();
        void addZoom(const Zoom& zoom);
        void writeBitmap(string name);

};
}

#endif