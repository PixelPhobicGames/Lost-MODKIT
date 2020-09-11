#include "raylib.h"
int play_hit_sound(Music sound){
	PlayMusicStream(sound);
	UpdateMusicStream(sound); 
}

int Set_Level_Music(Music music){
	PlayMusicStream(music);
	UpdateMusicStream(music); 
}