#pragma once
#include <iostream>
#include <map>
#include <Engine.h>
#include<SDL_mixer.h>
using namespace SkyEngine;
using namespace std;

//struct Mix_Chunk;
//typedef struct _Mix_Music Mix_Music;

class SDLAudio final : public sky::IAudio
{
public:

	SDLAudio();
	virtual ~SDLAudio();
	virtual size_t LoadMusic(const std::string & filename) override;
	virtual size_t LoadSound(const std::string & filename) override;
	virtual void PlayMusic(size_t id) override;
	virtual void PlayMusic(size_t id, int loop) override;
	virtual void PlaySFX(size_t id) override;
	virtual void PlaySFX(size_t id, int loop) override;
	virtual void PauseMusic() override;
	virtual void StopMusic() override;
	virtual void ResumeMusic() override;
	virtual void SetVolume(int volume) override;
	virtual void SetVolume(size_t soundId, int volume) override;

private:
	map<size_t, Mix_Music*> m_MusicMapCache;
	map<size_t, Mix_Chunk*> m_SoundMapCache;
};
