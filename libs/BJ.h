#include "raylib.h"
int SET_COLLISION_POINT(int player_x, int player_y ,int player_direction, int obj_x , int obj_y){
    if (player_x >= obj_x && player_x <= obj_x+50 && player_y <= obj_y && player_y >= obj_y - 50){
        if (player_direction == 1){player_y +=2;}
		if (player_direction == 4){player_x +=2;}
		if (player_direction == 2){player_x -= 2;}
        if (player_direction == 3){player_y -= 2;}
	}
}
int DRAW_MAP(Texture2D map){
    DrawTexture(map,0,0,WHITE);
}

int SET_EDGE_COLLISION(int edge,int player_x,int player_y){
		if (player_y <=20 && edge == 1)
		{
			return player_y - 2;
		}

		if (player_x >= 520 && edge == 2)
		{
			return player_x - 2;
		}


		if (player_y == 520 && edge == 3)
		{
			return player_y - 2;
		}
		if (player_x <= 20 && edge == 4)
		{
			return player_x - 2;
		}
}

int update_exp(int player_exp, Texture2D EXPBAR){
	DrawTexture(EXPBAR, 175,10,WHITE);
	DrawLine(184, 28, 184 + player_exp, 28, GREEN); 
	DrawLine(184, 29, 184 + player_exp, 29, GREEN); 
	DrawLine(184, 30, 184 + player_exp, 30, GREEN); 
	DrawLine(184, 31, 184 + player_exp, 31, GREEN); 
	DrawLine(184, 32, 184 + player_exp, 32, GREEN); 
	DrawLine(184, 33, 184 + player_exp, 33, GREEN); 
	DrawLine(184, 34, 184 + player_exp, 34, GREEN); 
	DrawLine(184, 35, 184 + player_exp, 35, GREEN); 
	DrawLine(184, 36, 184 + player_exp, 36, GREEN); 
	DrawLine(184, 37, 184 + player_exp, 37, GREEN); 
	DrawLine(184, 38, 184 + player_exp, 38, GREEN); 
	DrawLine(184, 39, 184 + player_exp, 39, GREEN); 
	DrawLine(184, 40, 184 + player_exp, 40, GREEN); 
	DrawLine(184, 41, 184 + player_exp, 41, GREEN); 
	DrawLine(184, 42, 184 + player_exp, 42, GREEN); 
	DrawLine(184, 43, 184 + player_exp, 43, GREEN); 
	DrawLine(184, 44, 184 + player_exp, 44, GREEN); 
	DrawLine(184, 45, 184 + player_exp, 45, GREEN); 
	DrawLine(184, 46, 184 + player_exp, 46, GREEN); 
	DrawLine(184, 47, 184 + player_exp, 47, GREEN); 
	DrawLine(184, 48, 184 + player_exp, 48, GREEN); 
	DrawLine(184, 49, 184 + player_exp, 49, GREEN);
}

int update_player(int player_direction, int player_x, int player_y , Texture2D player_1,Texture2D player_1_2 ,Texture2D player_1_3,Texture2D player_2 ,Texture2D player_2_2,Texture2D player_2_3,Texture2D player_3, Texture2D player_3_2,Texture2D player_3_3,Texture2D player_4, Texture2D player_4_2,Texture2D player_4_3,Shader shader, int ismoving , int animation_count){
	switch (player_direction){
		case 1:
			if (ismoving == false){
				DrawTexture(player_1,player_x,player_y,WHITE);
			}
			if (ismoving == true){
				if (animation_count >= 50){
					DrawTexture(player_1_2,player_x,player_y,WHITE);
				}
				else {
					DrawTexture(player_1_3,player_x,player_y,WHITE);
				}
			}
			break;
		case 2:
			if (ismoving == false){
				DrawTexture(player_2,player_x,player_y,WHITE);
			}
			if (ismoving == true){
				if (animation_count >= 50){
					DrawTexture(player_2_2,player_x,player_y,WHITE);
				}
				else {
					DrawTexture(player_2_3,player_x,player_y,WHITE);
				}
			}
			break;
		case 3:
			if (ismoving == false){
				DrawTexture(player_3,player_x,player_y,WHITE);
			}
			if (ismoving == true){
				if (animation_count >= 50){
					DrawTexture(player_3_2,player_x,player_y,WHITE);
				}
				else {
					DrawTexture(player_3_3,player_x,player_y,WHITE);
				}
			}
			break;
		case 4:
			if (ismoving == false){
				DrawTexture(player_4,player_x,player_y,WHITE);
			}
			if (ismoving == true){
				if (animation_count >= 50){
					DrawTexture(player_4_2,player_x,player_y,WHITE);
				}
				else {
					DrawTexture(player_4_3,player_x,player_y,WHITE);
				}
			}
			break;
	}
}
int update_hearts(float health,Texture2D hearts){
	if (health >= 33 ){
		DrawTexture(hearts,380,5,RED);
	}
	if (health >= 66){
		DrawTexture(hearts,416,5,RED);
	}
	if (health >= 99){
		DrawTexture(hearts,452,5,RED);
	}

}

int say(char dialog, Texture2D texture){
	DrawTexture(texture,0,400,WHITE);
	DrawText(dialog,10,410,15,BLACK);
	
}

int update_inventory(Texture2D weapon,Texture2D bar){
	DrawTexture(bar,125,450,WHITE);
	DrawText("A",132,456,6,BLACK);
	DrawTexture(weapon,128,452,WHITE);
}


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

int play_hit_sound(Music sound){
	PlayMusicStream(sound);
	UpdateMusicStream(sound); 
}

int draw_level(int level){
	DrawText(FormatText("Level: %i", level), 10, 470, 20, BLACK);
}

int Set_Level_Music(Music music){
	PlayMusicStream(music);
	UpdateMusicStream(music); 
}