#include "raylib.h"
int update_exp(int player_exp, Texture2D EXPBAR){
	DrawTexture(EXPBAR, 175,10,WHITE);
	DrawRectangle(184, 28, player_exp,28, RED);
	
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

int update_inventory(Texture2D weapon,Texture2D bar){
	DrawTexture(bar,125,450,WHITE);
	DrawText("A",132,456,6,BLACK);
	DrawTexture(weapon,128,452,WHITE);
}

int update_particle_animation(Texture2D leaf_1,Texture2D leaf_2,Texture2D leaf_3,Texture2D leaf_4, int leaf_x , int leaf_y,int animation_count,int particle_random){
	if (animation_count >= 0 && animation_count <= 25 ){
		DrawTexture(leaf_1 , leaf_x , leaf_y,GREEN);
		return particle_random = 35;
	}
	if (animation_count >= 25 && animation_count <= 50 ){
		DrawTexture(leaf_2 , leaf_x , leaf_y,GREEN);
		return particle_random = 25;
	}
	if (animation_count >= 50 && animation_count <= 75 ){
		DrawTexture(leaf_3 , leaf_x , leaf_y,GREEN);
		return particle_random = 15;
	}
	if (animation_count >= 75 && animation_count <= 100 ){
		DrawTexture(leaf_4, leaf_x , leaf_y,GREEN);
		return particle_random = 45;
	}
}