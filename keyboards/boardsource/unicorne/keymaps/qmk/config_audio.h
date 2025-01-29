// config_audio.h
#pragma once

#if defined(AUDIO_ENABLE)
#include "user_song_list.h"

#undef STARTUP_SONG
#define STARTUP_SONG SONG(MEGALOVANIA_SHORT)

#define SENDSTRING_BELL

#undef BELL_SOUND
#define BELL_SOUND SONG(ZELDA_PUZZLE)

#endif
