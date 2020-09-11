#include "raylib.h"
int enemy_follow_player_y(int player_y,int enemy_y){
	if (player_y >= enemy_y){
		return enemy_y + 1;
	}
	if (player_y <= enemy_y){
		return enemy_y - 1;
	}
}

int enemy_follow_player_x(int player_x,int enemy_x){
	if (player_x >= enemy_x){
		return enemy_x + 1;
	}
	if (player_x <= enemy_x){
		return enemy_x - 1;
	}
}