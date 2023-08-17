#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include "visibility.hpp"
#include "primitives.hpp"
#include "vector2.hpp"
#include "SDL2_gfxPrimitives.h"

int main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
	IMG_Init(IMG_INIT_PNG);

	float width = 1080;
	float height = 720;

	SDL_Window* window = SDL_CreateWindow("2D Light", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_Surface* map_sur = IMG_Load("map.png");
	SDL_Surface* light_sur = IMG_Load("light.png");

	SDL_Rect rectMap{ (width - map_sur->w)/2.f, (height - map_sur->h) / 2.f, map_sur->w, map_sur->h };
	SDL_Rect rectLight{ 0, 0, light_sur->w, light_sur->h };
	SDL_Texture* map_tex = SDL_CreateTextureFromSurface(renderer, map_sur);
	SDL_Texture* light_tex = SDL_CreateTextureFromSurface(renderer, light_sur);
	SDL_SetTextureBlendMode(light_tex, SDL_BLENDMODE_ADD);

	SDL_Texture *rendertex_light = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);
	SDL_SetTextureBlendMode(rendertex_light, SDL_BLENDMODE_MOD);

	SDL_Texture *rendertex = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);
	SDL_SetTextureBlendMode(rendertex, SDL_BLENDMODE_MOD);

	SDL_FreeSurface(map_sur);
	SDL_FreeSurface(light_sur);

	std::vector<geometry::line_segment<geometry::vec2>> segments;
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 114, rectMap.y + 60), geometry::vec2(rectMap.x + 114, rectMap.y + 372)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 114, rectMap.y + 372), geometry::vec2(rectMap.x + 147, rectMap.y + 372)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 147, rectMap.y + 372), geometry::vec2(rectMap.x + 148, rectMap.y + 382)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 148, rectMap.y + 382), geometry::vec2(rectMap.x + 22, rectMap.y + 383)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 22, rectMap.y + 383), geometry::vec2(rectMap.x + 20, rectMap.y + 648)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 20, rectMap.y + 648), geometry::vec2(rectMap.x + 379, rectMap.y + 648)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 379, rectMap.y + 648), geometry::vec2(rectMap.x + 380, rectMap.y + 464)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 380, rectMap.y + 464), geometry::vec2(rectMap.x + 391, rectMap.y + 464)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 391, rectMap.y + 464), geometry::vec2(rectMap.x + 390, rectMap.y + 509)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 391, rectMap.y + 509), geometry::vec2(rectMap.x + 561, rectMap.y + 513)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 561, rectMap.y + 513), geometry::vec2(rectMap.x + 563, rectMap.y + 521)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 563, rectMap.y + 521), geometry::vec2(rectMap.x + 390, rectMap.y + 521)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 390, rectMap.y + 521), geometry::vec2(rectMap.x + 391, rectMap.y + 647)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 391, rectMap.y + 647), geometry::vec2(rectMap.x + 697, rectMap.y + 649)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 697, rectMap.y + 649), geometry::vec2(rectMap.x + 700, rectMap.y + 523)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 700, rectMap.y + 523), geometry::vec2(rectMap.x + 610, rectMap.y + 520)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 610, rectMap.y + 520), geometry::vec2(rectMap.x + 610, rectMap.y + 511)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 610, rectMap.y + 511), geometry::vec2(rectMap.x + 793, rectMap.y + 513)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 793, rectMap.y + 513), geometry::vec2(rectMap.x + 795, rectMap.y + 387)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 795, rectMap.y + 387), geometry::vec2(rectMap.x + 703, rectMap.y + 387)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 703, rectMap.y + 387), geometry::vec2(rectMap.x + 704, rectMap.y + 250)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 704, rectMap.y + 250), geometry::vec2(rectMap.x + 612, rectMap.y + 247)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 612, rectMap.y + 247), geometry::vec2(rectMap.x + 611, rectMap.y + 238)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 611, rectMap.y + 238), geometry::vec2(rectMap.x + 712, rectMap.y + 239)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 712, rectMap.y + 239), geometry::vec2(rectMap.x + 714, rectMap.y + 378)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 714, rectMap.y + 378), geometry::vec2(rectMap.x + 795, rectMap.y + 375)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 795, rectMap.y + 375), geometry::vec2(rectMap.x + 794, rectMap.y + 156)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 794, rectMap.y + 156), geometry::vec2(rectMap.x + 612, rectMap.y + 156)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 612, rectMap.y + 156), geometry::vec2(rectMap.x + 613, rectMap.y + 64)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 613, rectMap.y + 64), geometry::vec2(rectMap.x + 393, rectMap.y + 63)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 393, rectMap.y + 63), geometry::vec2(rectMap.x + 392, rectMap.y + 98)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 392, rectMap.y + 98), geometry::vec2(rectMap.x + 382, rectMap.y + 97)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 382, rectMap.y + 97), geometry::vec2(rectMap.x + 381, rectMap.y + 62)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 381, rectMap.y + 62), geometry::vec2(rectMap.x + 114, rectMap.y + 60)));

	//Wall
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 381, rectMap.y + 145), geometry::vec2(rectMap.x + 381, rectMap.y + 190)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 381, rectMap.y + 190), geometry::vec2(rectMap.x + 288, rectMap.y + 190)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 288, rectMap.y + 190), geometry::vec2(rectMap.x + 287, rectMap.y + 372)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 287, rectMap.y + 372), geometry::vec2(rectMap.x + 195, rectMap.y + 372)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 195, rectMap.y + 372), geometry::vec2(rectMap.x + 195, rectMap.y + 381)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 195, rectMap.y + 381), geometry::vec2(rectMap.x + 298, rectMap.y + 383)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 298, rectMap.y + 383), geometry::vec2(rectMap.x + 299, rectMap.y + 200)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 299, rectMap.y + 200), geometry::vec2(rectMap.x + 390, rectMap.y + 201)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 390, rectMap.y + 201), geometry::vec2(rectMap.x + 391, rectMap.y + 144)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 391, rectMap.y + 144), geometry::vec2(rectMap.x + 381, rectMap.y + 145)));

	//Wall
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 473, rectMap.y + 238), geometry::vec2(rectMap.x + 472, rectMap.y + 373)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 472, rectMap.y + 373), geometry::vec2(rectMap.x + 380, rectMap.y + 373)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 380, rectMap.y + 373), geometry::vec2(rectMap.x + 380, rectMap.y + 416)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 380, rectMap.y + 416), geometry::vec2(rectMap.x + 389, rectMap.y + 416)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 389, rectMap.y + 416), geometry::vec2(rectMap.x + 389, rectMap.y + 382)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 389, rectMap.y + 382), geometry::vec2(rectMap.x + 482, rectMap.y + 382)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 482, rectMap.y + 382), geometry::vec2(rectMap.x + 483, rectMap.y + 247)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 483, rectMap.y + 247), geometry::vec2(rectMap.x + 563, rectMap.y + 248)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 563, rectMap.y + 248), geometry::vec2(rectMap.x + 563, rectMap.y + 238)));
	segments.push_back(geometry::line_segment<geometry::vec2>(geometry::vec2(rectMap.x + 563, rectMap.y + 238), geometry::vec2(rectMap.x + 473, rectMap.y + 238)));

	int cur_posX = 0;
	int cur_posY = 0;

	rectLight.x = cur_posX - 360;
	rectLight.y = cur_posY - 360;

	std::vector<geometry::vec2> result = geometry::visibility_polygon(geometry::vec2(cur_posX, cur_posY), segments.begin(), segments.end());
	std::vector<Sint16> vx, vy;

	SDL_ShowCursor(0);

	while (true) {
		SDL_Event e;
		if (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				break;
			}

			if (e.type == SDL_MOUSEMOTION) {
				cur_posX = e.motion.x;
				cur_posY = e.motion.y;

				rectLight.x = cur_posX - 360;
				rectLight.y = cur_posY - 360;

				result.clear();
				result = geometry::visibility_polygon(geometry::vec2(cur_posX, cur_posY), segments.begin(), segments.end());
			}
		}

		// Reset the default color after filledPolygonRGBA
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

		//Render light on the texture
		SDL_SetRenderTarget(renderer, rendertex_light);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, light_tex, NULL, &rectLight); 

		// Render visibility polygon on the texture
		SDL_SetRenderTarget(renderer, rendertex);
		SDL_RenderClear(renderer);

		vx.reserve(result.size());
		vy.reserve(result.size());

		for (size_t i = 0; i < result.size(); i++) {
			vx[i] = result[i].x;
			vy[i] = result[i].y;
		}

		filledPolygonRGBA(renderer, &vx[0], &vy[0], result.size(), 255, 255, 255, 255);

		// Render on the screen
		SDL_SetRenderTarget(renderer, NULL);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, map_tex, NULL, &rectMap);
		SDL_RenderCopy(renderer, rendertex, NULL, NULL);
		SDL_RenderCopy(renderer, rendertex_light, NULL, NULL);

		SDL_RenderDrawPoint(renderer, cur_posX, cur_posY);
		SDL_RenderPresent(renderer);

		vx.clear();
		vy.clear();
	}

	SDL_DestroyTexture(rendertex);
	SDL_DestroyTexture(rendertex_light);
	SDL_DestroyTexture(light_tex);
	SDL_DestroyTexture(map_tex);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();

	return 0;
}