#pragma once

#include "olcPixelGameEngine.h"

#include <vector>
#include <string>

class Slideshow : public olc::PixelGameEngine
{
public:
    Slideshow();
    bool OnUserCreate() override;
    bool OnUserUpdate(float fElapsedTime) override;
private:
    std::vector<std::unique_ptr<olc::Sprite>> slides;
    int nSlide;
};
