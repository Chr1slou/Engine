#pragma once

struct SDL_Texture* Texture;


/// <summary>
/// struct to associate a texture with its id
/// </summary>
struct Texture
{
public:
	int ID;
	SDL_Texture* Texture;
};