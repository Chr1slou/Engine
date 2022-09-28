#include "SDLAudio.h"
#include <SDL_mixer.h>

SDLAudio::SDLAudio()
{
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024); //opens mixer
}

SDLAudio::~SDLAudio()
{
	Mix_CloseAudio(); //close mixer
}

// set music cache and load music

size_t SDLAudio::LoadMusic(const std::string& filename)
{
	
	const size_t _musicId = std::hash<std::string>()(filename);
	if (m_MusicMapCache.count(_musicId) != 0)
	{
		return _musicId;
	}
	Mix_Music* _music = Mix_LoadMUS(filename.c_str());
	
	if (_music != nullptr)
	{
		m_MusicMapCache[_musicId] = _music;
		return _musicId;
	}
	return -1;
}

// set sound cache and load sound
size_t SDLAudio::LoadSound(const std::string& filename)
{
	const size_t _soundId = std::hash<std::string>()(filename);
	if (m_SoundMapCache.count(_soundId) != 0)
	{
		return _soundId;
	}
	Mix_Chunk* _sample = Mix_LoadWAV(filename.c_str());

	if (_sample != nullptr)
	{
		m_SoundMapCache[_soundId] = _sample;
		return _soundId;
	}
	return -1;
}

/// <summary>
/// Play a music
/// </summary>
/// -1 means infinite loop
/// <param name="id">the music to be played </param>
void SDLAudio::PlayMusic(size_t id)
{
	PlayMusic(id, -1);
}


/// <summary>
/// Play a music
/// Mix_PlayMusic(Mix_Music *music, int loops)
/// </summary>
/// <param name="id"> the music to be played</param>
/// <param name="loop"> number of loops desired</param>
void SDLAudio::PlayMusic(size_t id, int loop)
{
	Mix_PlayMusic(m_MusicMapCache[id], loop);
}

/// <summary>
/// Play sound with no loops
/// </summary>
/// <param name="id"> the sound to be played </param>
void SDLAudio::PlaySFX(size_t id)
{
	PlaySFX(id, 0);
}

/// <summary>
/// Play a sound
/// Mix_PlayChannel(int channel, Mix_Chunk* chunk, int loops);
/// 
/// </summary>
/// <param name="channel"> If the specified channel is -1, play on the first free channel</param>
/// <param name="chunk"> the sound to be played </param>
/// <param name="loops"> number of loops desired </param>
//If the specified channel is -1, play on the first free channel
void SDLAudio::PlaySFX(size_t id, int loop)
{
	Mix_PlayChannel(-1, m_SoundMapCache[id], 0);
}


/// <summary>
/// Pause the music stream
/// </summary>
void SDLAudio::PauseMusic()
{
	Mix_PauseMusic();
}

/// <summary>
/// Halt playing of the music stream
/// </summary>
void SDLAudio::StopMusic()
{
	Mix_HaltMusic();
}

/// <summary>
/// Resume the music stream
/// </summary>
void SDLAudio::ResumeMusic()
{
	Mix_ResumeMusic();
}

/// <summary>
/// Set the volume for the music channel.
/// </summary>
/// <param name="volume">the new volume, between 0 and MIX_MAX_VOLUME,
///  or -1 to query.</param>
void SDLAudio::SetVolume(int volume)
{
	Mix_VolumeMusic(volume);
}


/// <summary>
/// Set the volume for a specific chunk
/// Mix_VolumeChunk(Mix_Chunk *chunk, int volume);
/// </summary>
/// <param name="soundId"> the sound to set the volume </param>
/// <param name="volume">the new volume, between 0 and MIX_MAX_VOLUME,
///  or -1 to query.</param>
void SDLAudio::SetVolume(size_t soundId, int volume)
{
	Mix_VolumeChunk(m_SoundMapCache[soundId], volume);
}
