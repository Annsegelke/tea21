#ifndef WORKSPACE_TEA21_EXERCISE_004_BMP_H
#define WORKSPACE_TEA21_EXERCISE_004_BMP_H

#include <string>

class BMP {
    bool read(const std::string& filename);
    bool write(const std::string& filename);
}
private:
    struct BitmapFileHeader {
        char bfType[2] = {'X', 'X'};
        uint32_t bfSize =0;
        uint32_t bfReserved = 0;
        uint32_t bfOffBits = 0;
        void print();
    }
    struct BitmapInfoHeader {
        unint32_
    }
    struct RGBA {
        uint8_t red =0;
        uint8_t green =0;
        uint8_t blue =0;
        
    }

#endif