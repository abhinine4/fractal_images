#include "FractalCreator.h"

namespace ab_bitmap{
FractalCreator::FractalCreator(int width, int height) : m_width(width), m_height(height), 
                        m_histogram(new int[Mandelbrot::MAX_ITERATIONS]{0}),
                        m_fractal(new int[m_width * m_height]{0}),
                        m_bitmap(m_width, m_height),
                        m_zoomList(m_width, m_height){

        m_zoomList.add(Zoom(m_width/2, m_height/2, 4.0/m_width));
    }

};