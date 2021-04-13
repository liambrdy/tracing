#include <stdio.h>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>

#include <vector>
#include <cstdint>

struct Pixel
{
    uint32_t r, g, b, a;
};

int main()
{
    std::vector<Pixel> pixels(256 * 256);

    for (uint32_t y = 0; y < 256; ++y)
    {
        for (uint32_t x = 0; x < 256; ++x)
        {
            float r = (float)x / 256.0f;
            float g = (float)y / 256.0f;
            float b = 0.0f;

            uint32_t ir = (uint32_t)(255.0f * r);
            uint32_t ig = (uint32_t)(255.0f * g);
            uint32_t ib = (uint32_t)(255.0f * b);

            pixels[y * 256 + x] = { ir, ig, ib, 255 };
        }
    }

    stbi_write_png("../output.png", 256, 256, 4, pixels.data(), 256 * 4);
    
    return 0;
}