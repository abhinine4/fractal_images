#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include <cstdint>
#include <string>
#include <memory>
#include <vector>
#include "Zoom.h"
#include "Bitmap.cpp"
#include "Mandelbrot.cpp"
#include "ZoomList.cpp"
#include "RGB.h"

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

        vector<int> m_ranges;
        vector<RGB> m_colors;
        vector<int> m_rangeTotals;

        bool m_bGotFirstRange{false};

    private:
        void calculateIteration();
        void calculateTotalIterations();
        void calculateRangeTotals();
        void drawFractal();
        void writeBitmap(string name);
        int getRange(int iterations) const;

    public:
        FractalCreator(int width, int height);
        virtual ~FractalCreator();
        void addRange(double rangeEnd, const RGB& rgb);
        void addZoom(const Zoom& zoom);
        void run(string name);

};
}

#endif