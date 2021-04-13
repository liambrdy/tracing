#include <stdio.h>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>

#include <vector>
#include <cstdint>

struct Pixel
{
    uint8_t r, g, b, a;
};

int main()
{
    constexpr int32_t width = 256, height = 256;

    std::vector<Pixel> pixels;

    for (int32_t y = height - 1; y >= 0; --y)
    {
        for (int32_t x = 0; x < width; ++x)
        {
            float r = (float)x / 256.0f;
            float g = (float)y / 256.0f;
            float b = 0.0f;

            Pixel p = {};
            p.r = (uint8_t)(255.0f * r);
            p.g = (uint8_t)(255.0f * g);
            p.b = (uint8_t)(255.0f * b);
            p.a = 255;

            pixels.push_back(p);
        }
    }

    stbi_write_png("../output.png", width, height, 4, pixels.data(), width * 4);
    
    return 0;
}