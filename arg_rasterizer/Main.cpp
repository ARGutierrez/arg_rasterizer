#include "Renderer.h"
#include <iostream>
#include <SDL.h>

int main(int argc, char* argv[])
{
	const char* title = "arg_rasterizer";
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Surface* surface;
	
	Renderer myRenderer;

	//Main loop flag
	bool quit = false;
	bool mouseDown = false;
	int scene = 0;

	//Event handler
	SDL_Event e;

	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
	if (window == NULL)
	{
		return 0;
	}

	surface = SDL_GetWindowSurface(window);
	if (surface == NULL)
	{
		return 0;
	}

	renderer = SDL_CreateSoftwareRenderer(surface);
	if (renderer == NULL)
	{
		return 0;
	}
	
	myRenderer.SetFrameBuffer((u32*)surface->pixels, 800, 600);

	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			if (e.type == SDL_KEYDOWN)
			{
				if (e.key.keysym.sym == SDLK_UP)
				{
					scene++;
					scene = scene % 2;
				}
				if (e.key.keysym.sym == SDLK_DOWN)
				{
					scene++;
					scene = scene % 2;
				}
			}
		}

		// clear framebuffer
		SDL_LockSurface(surface);
		myRenderer.Clear();

		int x, y;
		u32 mouseState = SDL_GetMouseState(&x, &y);
		if (mouseState & SDL_BUTTON(SDL_BUTTON_LEFT)) mouseDown = true;

		Color* color;
		if (mouseDown)
		{
			color = new Color(1.0f, 1.0f, 1.0f);
		}
		else
		{
			color = new Color(1.0f, 0.0f, 0.0f);
		}

		// Mouse Tether
		if (scene == 0)
		{
			if (mouseDown)
				myRenderer.DrawLine(*color, x, y, 400, 300);
			else
				myRenderer.DrawLine(*color, x, y, 400, 300);
		}
		// Draw Grid
		else if (scene == 1)
		{
			for (int x = 0; x < 800; x = x + 10)
			{
				myRenderer.DrawLine(*color, x, 0, x, 599);
			}
			for (int y = 0; y < 600; y += 10)
			{
				myRenderer.DrawLine(*color, 0, y, 799, y);
			}
		}
		SDL_UnlockSurface(surface);
		SDL_UpdateWindowSurface(window);
		mouseDown = false;
	}

	return 0;
}