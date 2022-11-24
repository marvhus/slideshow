#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

#include "slideshow.hpp"

int main()
{
	Slideshow instance;
	if (instance.Construct(1920, 1080, 1, 1))
	    instance.Start();

	return 0;
}
