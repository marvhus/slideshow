#include "../slideshow.hpp"

#include <fstream>
#include <assert.h>
#include <string>

Slideshow::Slideshow()
{
    sAppName = "Slideshow";
}

bool Slideshow::OnUserCreate()
{
    std::ifstream file("slides.txt"); 
    assert(file.good()); // exit if there is no slides.txt file

    std::string line;
    while (std::getline(file, line))
    {
        if (line.length() <= 1) continue;;
        std::cout << "Added slide: " << line << std::endl;
        slides.push_back(std::make_unique<olc::Sprite>(line));
    }

    nSlide = 0;

    return true;
}

bool Slideshow::OnUserUpdate(float fElapsedTime)
{
    Clear(olc::CYAN);

    // Input
    if (GetKey(olc::Key::D).bPressed) nSlide = (nSlide + 1) % slides.size();
    if (GetKey(olc::Key::A).bPressed) nSlide = (nSlide - 1) % slides.size();

    // Display image
    DrawSprite(0, 0, slides[nSlide].get());
    DrawString(
            10, 
            10, 
            "Slide: " 
          + std::to_string(nSlide) 
          + " / " 
          + std::to_string(slides.size() - 1), 
          olc::YELLOW,
          2);
    FillRect(
            0,
            ScreenHeight() - 10, 
            nSlide * (ScreenWidth() / (slides.size() - 1)), 
            10, 
            olc::YELLOW);

    return !GetKey(olc::Key::ESCAPE).bPressed;
}
