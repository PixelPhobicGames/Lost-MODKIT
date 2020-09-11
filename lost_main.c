#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "libs/delay.h"
#include "libs/raylib.h"
#include "libs/lost_update_functions.h"
#include "libs/sound.h"
#include "libs/enemy_ai.h"
#include "libs/video.h"
#include "libs/level.h"
#define XBOX360_NAME_ID     "Xbox 360 Controller"
/* Written by Ewan Cole June 2020*/
int main(int argc, char *argv[])
{
	// The Code loads in all of the Textures and Variables here
	int ismoving = false;
	int player_exp = 0;
	int animation_count = 0;
	//This Level_ID Variable controls the scene your currently on
	int Level_ID = 0;
	int player_x = 50;
	int player_y = 300;
	int player_Vel = 2;
	int isitem = 1;
	int isenemy = true;
	int player_direction = 1;
	int projectile_x = player_x;
	int projectile_y = player_y;
	int projectile_count = 0;
	int enemy_x = 50;
	int enemy_y = 400;
	int enemy_y2 = 0;
	int enemy_x2 = 0;
	int enemy_jumpcount = 0;
	int enemy_isjump = false;
	int developer_mode = false;
	int istalking = false;
	int isshoot = false;
	float player_health = 100;
	int player_level = 1;
	int boss_health = 200;
	int enemy_isshoot = false;
	int enemy_projectile_x =0;
	int enemy_projectile_y =0;

	Draw_window();
	Image icon = LoadImage("sprites/icon.png"); 
	Set_Window_icon(icon);
	InitAudioDevice();
	Shader shader = LoadShader(0, FormatText("shaders/shader.fs"));
	Texture2D Chatbubble = LoadTexture("sprites/chat.png");
	Texture2D background_1 = LoadTexture("sprites/title_screen.png");  
	Texture2D player_3 = LoadTexture("sprites/player/player_facing_1.png");
	Texture2D player_3_2 = LoadTexture("sprites/player/player_facing_2.png");
	Texture2D player_3_3 = LoadTexture("sprites/player/player_facing_3.png");

	Texture2D player_2 = LoadTexture("sprites/player/player_right_1.png");
	Texture2D player_2_2 = LoadTexture("sprites/player/player_right_2.png");
	Texture2D player_2_3 = LoadTexture("sprites/player/player_right_3.png");

	Texture2D player_1 = LoadTexture("sprites/player/player_backwards.png");
	Texture2D player_1_2 = LoadTexture("sprites/player/player_backwards_2.png");
	Texture2D player_1_3 = LoadTexture("sprites/player/player_backwards_3.png");

	Texture2D player_4 = LoadTexture("sprites/player/player_left_1.png");
	Texture2D player_4_2 = LoadTexture("sprites/player/player_left_2.png");
	Texture2D player_4_3 = LoadTexture("sprites/player/player_left_3.png");

	Texture2D player_chaticon = LoadTexture("sprites/chaticons/player_chaticon.png");
	Texture2D wooden_bow = LoadTexture("sprites/bow.png");
	Texture2D Alpha_weapon_1 = LoadTexture("sprites/weapons/iron_greatsword_1.png");
	Texture2D optionscreen = LoadTexture("maps/optionscreen.png");
	Texture2D map_1 = LoadTexture("maps/map_1.png");
	Texture2D map_2 = LoadTexture("maps/map_2.png");
	Texture2D map_4 = LoadTexture("maps/map_4.png");
	Texture2D map_5 = LoadTexture("maps/map_5.png");
	Texture2D map_8 = LoadTexture("maps/map_8.png");
	Texture2D map_9 = LoadTexture("maps/map_9.png");
	Texture2D map_10 = LoadTexture("maps/map_10.png");
	Texture2D map_11 = LoadTexture("maps/map_11.png");
	Texture2D map_12= LoadTexture("maps/map_12.png");
	Texture2D map_13= LoadTexture("maps/map_13.png");
	Texture2D map_14 = LoadTexture("maps/map_14.png");
	Texture2D map_15 = LoadTexture("maps/map_15.png");
	Texture2D map_16 = LoadTexture("maps/map_16.png");
	Texture2D map_17 = LoadTexture("maps/map_17.png");
	Texture2D map_18 = LoadTexture("maps/map_18.png");
	Texture2D map_19 = LoadTexture("maps/map_19.png");
	Texture2D map_20 = LoadTexture("maps/map_20.png");
	Texture2D map_21 = LoadTexture("maps/map_21.png");
	Texture2D map_22 = LoadTexture("maps/map_22.png");
	Texture2D map_23 = LoadTexture("maps/map_23.png");
	Texture2D map_24 = LoadTexture("maps/map_24.png");
	Texture2D map_25 = LoadTexture("maps/map_25.png");
	Texture2D map_26 = LoadTexture("maps/map_26.png");
	Texture2D map_27 = LoadTexture("maps/map_27.png");
	Texture2D map_28 = LoadTexture("maps/map_28.png");
	Texture2D BOSS_ROOM_1 = LoadTexture("maps/BOSS_ROOMS/br_1.png");
	Texture2D expbar = LoadTexture("sprites/level.png");
	Texture2D hearts = LoadTexture("sprites/heart.png");
	Music title_music = LoadMusicStream("music/jungle.mp3"); 
	Music castle_music = LoadMusicStream("music/castle.mp3"); 
	Music hit = LoadMusicStream("music/hit.mp3"); 
	Music forest_theme = LoadMusicStream("music/main_forest_theme.mp3"); 
	Music enemy_death = LoadMusicStream("music/death.mp3"); 
	Music cave_boss = LoadMusicStream("music/cave.mp3"); 
	Music levelup = LoadMusicStream("music/levelup.mp3"); 
	Music lava_theme = LoadMusicStream("music/lava_world_theme.mp3"); 
	Texture2D slime_enemy = LoadTexture("sprites/enemys/slime.png");
	Texture2D slime_enemy_red = LoadTexture("sprites/enemys/slime-red.png");
	Texture2D boss_1 = LoadTexture("sprites/byclops.png");
	Texture2D boss_2 = LoadTexture("sprites/byclops_2.png");
	Texture2D boss_3 = LoadTexture("sprites/byclops_3.png");
	Texture2D prince_1 = LoadTexture("sprites/boss/prince/prince_1.png");
	Texture2D mummy_1 = LoadTexture("sprites/enemys/mummy_1.png");
	Texture2D mummy_2 = LoadTexture("sprites/enemys/mummy2.png");
	Texture2D bat = LoadTexture("sprites/enemys/bat_1.png");
	Texture2D cutscene_mountian = LoadTexture("maps/cutscenes/cut_1_opening.png");
	Texture2D sky = LoadTexture("maps/cutscenes/sky.png");
	Texture2D inventory_bar = LoadTexture("sprites/inventory/bar.png");
	Texture2D inventory_defualt_sword = LoadTexture("sprites/inventory/defualt_sword.png");
	Texture2D inventory_blankslot = LoadTexture("sprites/inventory/blank.png");
	Texture2D inventory_weapon = inventory_blankslot;
	Texture2D inventory_bow = inventory_blankslot;
	Texture2D arrow_1 = LoadTexture("sprites/projectiles/arrow_1.png");
	Texture2D arrow_2 = LoadTexture("sprites/projectiles/arrow_2.png");
	Texture2D arrow_3 = LoadTexture("sprites/projectiles/arrow_3.png");
	Texture2D arrow_4 = LoadTexture("sprites/projectiles/arrow_4.png");
	SetTargetFPS(60);
	// The whole level code uses one switch statemant and the Level_ID int 
	// If you change the Level_ID the Whole background and the level behavior will change
	while (!WindowShouldClose())
	{
		// This code Check to see if theres a controller connected if not it binds to a keyboard instead of controller inputs
		if (IsGamepadAvailable(GAMEPAD_PLAYER1)){
			if (IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_FACE_DOWN)){
				player_direction = 3;
				player_y += player_Vel;
				ismoving = true;
			}
			if (IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_FACE_UP)){
				ismoving = true;
				player_direction = 1;
				player_y -= player_Vel;
			}
			if (IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_FACE_LEFT)){
				player_direction = 4;
				player_x -= player_Vel;
				ismoving = true;
			}
			if (IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_FACE_RIGHT)){
				player_direction = 2;
				player_x += player_Vel;
				ismoving = true;
			}
			if (IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_FACE_DOWN) == false &&  IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_FACE_UP) == false &&  IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_FACE_LEFT) == false && IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_FACE_RIGHT) == false){
				ismoving = false;
			}

		}
		else{
			if (IsKeyDown(KEY_LEFT) == true && IsKeyDown(KEY_RIGHT) == false && IsKeyDown(KEY_UP) == false &&IsKeyDown(KEY_DOWN) == false && isshoot == false) {
				player_direction = 4;
				player_x -= player_Vel;
				ismoving = true;
			}

			if (IsKeyDown(KEY_RIGHT) == true && IsKeyDown(KEY_LEFT) == false && IsKeyDown(KEY_UP) == false &&IsKeyDown(KEY_DOWN) == false && isshoot == false){
				player_direction = 2;
				player_x += player_Vel;
				ismoving = true;
			}

			if (IsKeyDown(KEY_UP) == true && IsKeyDown(KEY_RIGHT) == false && IsKeyDown(KEY_LEFT) == false &&IsKeyDown(KEY_DOWN) == false && isshoot == false){
				ismoving = true;
				player_direction = 1;
				player_y -= player_Vel;
			}

			if (IsKeyDown(KEY_DOWN) == true && IsKeyDown(KEY_RIGHT) == false && IsKeyDown(KEY_UP) == false &&IsKeyDown(KEY_LEFT) == false && isshoot == false){
				player_direction = 3;
				player_y += player_Vel;
				ismoving = true;
			}
			// If ismoving is false it wont play an animation 
			if (IsKeyDown(KEY_DOWN) == false && IsKeyDown(KEY_UP) == false && IsKeyDown(KEY_LEFT) == false && IsKeyDown(KEY_RIGHT) == false){
				ismoving = false;
			}
			
			if (IsKeyDown(KEY_S) && isshoot == false){
				switch (player_direction)
				{
					case 1:
						projectile_x = player_x + 20;
						projectile_y = player_y - 15;
						break;
					case 2:
						projectile_x = player_x + 15;
						projectile_y = player_y;
						break;
					case 3:
						projectile_x = player_x +20;
						projectile_y = player_y + 15;
						break;
					case 4:
						projectile_x = player_x - 15;
						projectile_y = player_y ;
						break;
	
				}
				isshoot = true;
			}

		}
		BeginDrawing();
		ClearBackground(RAYWHITE);
		if (Level_ID == 0){
				Set_Level_Music(title_music);
				DrawTexture(background_1,0,0,WHITE);
				if (IsKeyDown(KEY_O)){ Level_ID = 100;}	
				if (IsGamepadAvailable(GAMEPAD_PLAYER1)){
					if (IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
						Level_ID = Set_Level_ID(1 , Level_ID);;
					}
				}
				else{if (IsKeyDown(KEY_SPACE)){ Level_ID = 1;}}	
				if (player_health <= 0){
					animation_count = 0;
					player_x = 50;
					player_y = 300;
					isitem = 1;
					isenemy = true;
					player_direction = 1;
					projectile_x = player_x;
					projectile_y = 0;
					projectile_count = 0;
					enemy_x = 50;
					enemy_y = 400;
					isshoot = true;
					player_health = 100;
				}
		}
		else {

			switch (Level_ID)
			{
				
				case 100:
					DrawTexture(optionscreen,0,0,WHITE);
					break;
				case 1:
					/* this is where the level code takes place */
					Set_Level_Music(forest_theme);
					DRAW_MAP(map_1);
					if (isitem == 1){
						DrawTexture(Alpha_weapon_1,370,340,WHITE);
					}
					else {
						inventory_weapon = inventory_defualt_sword;
					}

					if (player_x - 370 <= 50 && player_x - 370 >= 0 && player_y - 340 >= -50){isitem = 0;}

					// This is a Collision Box It just check to See if your X and Y are in a centain area and subtracts or
					// Adds depending on your players direction
					if (player_x >= 220 && player_x <= 290 && player_y <= 300 && player_y >= 200){
						if (player_direction == 1){player_y +=2;}
						if (player_direction == 4){player_x +=2;}
						if (player_direction == 2){player_x -= 2;}
						if (player_direction == 3){player_y -= 2;}
					}
					//    ^
					//    |

					if (player_y <= 150){
						player_y += 2;
					}
					if (player_x >= 550){
						player_x = 0;
						Level_ID = Set_Level_ID(13 , Level_ID);
					}
					if (player_x <= -50){
						player_x = 500;
						Level_ID = Set_Level_ID(2 , Level_ID); 
					}
					
					break;
				case 2:
					Set_Level_Music(forest_theme);
					DRAW_MAP(map_2);


					// This is all enemy code
					if (IsGamepadAvailable(GAMEPAD_PLAYER1)){
						if (IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN) == true && isitem == 0){
							DrawTexture(player_1,player_x,player_y,WHITE);
							if (player_x - enemy_x <= 50 && player_x - enemy_x >= 0 && player_y - enemy_y >= -50 && player_y - enemy_y <= 0){
								PlayMusicStream(enemy_death);
								UpdateMusicStream(enemy_death); 
								isenemy = false;
								if (isenemy == true){player_exp += 1;}
							}
						}
					}
					else{
						if (IsKeyDown(KEY_A) && isitem == 0){
							DrawTexture(player_1,player_x,player_y,WHITE);
							if (player_x - enemy_x <= 50 && player_x - enemy_x >= 0 && player_y - enemy_y >= -50 && player_y - enemy_y <= 0){
								PlayMusicStream(enemy_death);
								UpdateMusicStream(enemy_death); 
								isenemy = false;
								if (isenemy == true){player_exp += 1;}
							}
						}
						if (projectile_x - enemy_x <= 50 && projectile_x  - enemy_x >= 0 && projectile_y - enemy_y >= -50 && projectile_y - enemy_y <= 0){
								PlayMusicStream(enemy_death);
								UpdateMusicStream(enemy_death); 
								isenemy = false;
								if (isenemy == true){player_exp += 1;}
						}
					}
					if (isenemy == true){
						DrawTexture(slime_enemy,enemy_x,enemy_y,WHITE);
						if (enemy_isjump == false){
							enemy_isjump = true;
						}
						enemy_x = enemy_follow_player_x(player_x,enemy_x);
						enemy_y = enemy_follow_player_y(player_y,enemy_y);
						if (player_x - enemy_x <= 50 && player_x - enemy_x >= 0 && player_y - enemy_y >= -50 && player_y - enemy_y <= 0){
							PlayMusicStream(hit);
							UpdateMusicStream(hit); 
							player_health -= .5;
						}
						if (player_health == 0){
							Level_ID =  Set_Level_ID(0 , Level_ID); 
						}

					}
					//              ^
					// all of this |
					if (player_x >= 550){
						player_x = 0;
						Level_ID =  Set_Level_ID(1 , Level_ID); 
					}
					if (player_y <= -25){
						player_y = 475;
						Level_ID =  Set_Level_ID(4 , Level_ID); 
					}

					if (player_x >= 75 && player_x <= 125 && player_y <= 115 && player_y >= 35){
						if (player_direction == 1){player_y +=2;}
						if (player_direction == 4){player_x +=2;}
						if (player_direction == 2){player_x -= 2;}
						if (player_direction == 3){player_y -= 2;}
					}

					if (player_x >= 325 && player_x <= 375 && player_y <= 115 && player_y >= 35){
						if (player_direction == 1){player_y +=2;}
						if (player_direction == 4){player_x +=2;}
						if (player_direction == 2){player_x -= 2;}
						if (player_direction == 3){player_y -= 2;}
					}
					if (enemy_isjump == true){
						if (enemy_jumpcount >= -10){
							enemy_y -= (enemy_jumpcount * abs(enemy_jumpcount)) * .2;
							enemy_jumpcount -= 1;
						}
						else{
							enemy_jumpcount = 10;
							enemy_isjump = false;
						}
					}
					if (player_x <= -50){
						player_x = 500;
						if (isenemy == false){
							isenemy = true;
						}
						enemy_x = 100;
						enemy_y = 250;
						Level_ID =  Set_Level_ID(26 , Level_ID); 
					}
					break;
				case 4:
					Set_Level_Music(forest_theme);
					DRAW_MAP(map_4);
					if (player_x <= 0){
						player_x += 2;

					}

					if (player_x >= 125 && player_x <= 300 && player_y <= 150){
						player_y = 475;
						enemy_x = 150;
						enemy_y = 150;
						isenemy = true;
						Level_ID =  Set_Level_ID(5 , Level_ID); 
					}
					if (player_y >= 500){
						player_y = 35;
						Level_ID = 2;
					}
					if (player_x >= 550){
						player_x = 0;
						Level_ID = Set_Level_ID(14 , Level_ID);
					}
					break;
				case 5:
					DRAW_MAP(map_5);
					if (boss_health <= 0 && isenemy == true){
						isenemy = false;
					}
					if (player_y <= 0){
						isenemy = true;
						enemy_x = 250;
						enemy_y = 250;
						player_y = 490;
						Level_ID =  Set_Level_ID(6 , Level_ID); 
					}
					if (isenemy == true){
						PlayMusicStream(cave_boss);
						UpdateMusicStream(cave_boss); 
						if (animation_count >= 0 && animation_count <= 33){
							DrawTexture(boss_1,enemy_x,enemy_y,WHITE);
						}
						if (animation_count >= 33 && animation_count <= 66){
							DrawTexture(boss_2,enemy_x,enemy_y,WHITE);
						}
						if (animation_count >= 66 && animation_count <= 99){
							DrawTexture(boss_3,enemy_x,enemy_y,WHITE);
						}
						enemy_x = enemy_follow_player_x(player_x,enemy_x);
						enemy_y = enemy_follow_player_y(player_y,enemy_y);
						if (player_x - enemy_x <= 50 && player_x - enemy_x >= 0 && player_y - enemy_y >= -50 && player_y - enemy_y <= 0){
							PlayMusicStream(hit);
							UpdateMusicStream(hit); 
							player_health -= .75;
						}
						if (player_health <= 0){
							Level_ID =  Set_Level_ID(0 , Level_ID); 
						}
					if (IsGamepadAvailable(GAMEPAD_PLAYER1)){
						if (IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN) == true && isitem == 0){
							DrawTexture(player_1,player_x,player_y,WHITE);
							if (player_x - enemy_x <= 50 && player_x - enemy_x >= 0 && player_y - enemy_y >= -50 && player_y - enemy_y <= 0){
								PlayMusicStream(enemy_death);
								UpdateMusicStream(enemy_death); 
								boss_health -= 20;
								player_exp += 50;
							}
						}
					}
					else{
						if (IsKeyDown(KEY_A) && isitem == 0){
							DrawTexture(player_1,player_x,player_y,WHITE);
							if (player_x - enemy_x <= 50 && player_x - enemy_x >= 0 && player_y - enemy_y >= -50 && player_y - enemy_y <= 0){
								PlayMusicStream(enemy_death);
								UpdateMusicStream(enemy_death); 
								boss_health -= 20;
								player_exp += 50;
							}
						}
						if (projectile_x - enemy_x <= 50 && projectile_x  - enemy_x >= 0 && projectile_y - enemy_y >= -50 && projectile_y - enemy_y <= 0){
							PlayMusicStream(enemy_death);
							UpdateMusicStream(enemy_death); 
							boss_health -= 20;
						}
					}
					break;
				case 6:
					Set_Level_Music(forest_theme);
					DRAW_MAP(map_8);
					if (player_y <= 0){
						player_y = 475;
						Level_ID =  Set_Level_ID(8 , Level_ID); 
					}
					if (player_x >= 525){
						player_x = 20;
						Level_ID =  Set_Level_ID(7 , Level_ID); 
					}
					if (player_x >= 0 && player_x <= 140 && player_y <= 360 && player_y >= 120){
						if (player_direction == 1){player_y +=2;}
						if (player_direction == 4){player_x +=2;}
						if (player_direction == 2){player_x -= 2;}
						if (player_direction == 3){player_y -= 2;}
					}

					if (IsGamepadAvailable(GAMEPAD_PLAYER1)){
						if (IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN) == true && isitem == 0){
							DrawTexture(player_1,player_x,player_y,WHITE);
							if (player_x - enemy_x <= 50 && player_x - enemy_x >= 0 && player_y - enemy_y >= -50 && player_y - enemy_y <= 0){
								PlayMusicStream(enemy_death);
								UpdateMusicStream(enemy_death); 
								isenemy = false;
								if (isenemy == true){player_exp += 1;}
							}
						}
					}
					else{
						if (IsKeyDown(KEY_A) && isitem == 0){
							DrawTexture(player_1,player_x,player_y,WHITE);
							if (player_x - enemy_x <= 50 && player_x - enemy_x >= 0 && player_y - enemy_y >= -50 && player_y - enemy_y <= 0){
								PlayMusicStream(enemy_death);
								UpdateMusicStream(enemy_death); 
								isenemy = false;
								if (isenemy == true){player_exp += 1;}
							}
							if (projectile_x - enemy_x <= 50 && projectile_x  - enemy_x >= 0 && projectile_y - enemy_y >= -50 && projectile_y - enemy_y <= 0){
								PlayMusicStream(enemy_death);
								UpdateMusicStream(enemy_death); 
								isenemy = false;
								if (isenemy == true){player_exp += 1;}
							}
						}

					}
					if (isenemy == true){
						if (animation_count <= 50){
							DrawTexture(mummy_1,enemy_x,enemy_y,WHITE);
						}
						else{
							DrawTexture(mummy_2,enemy_x,enemy_y,WHITE);
						}
						enemy_x = enemy_follow_player_x(player_x,enemy_x);
						enemy_y = enemy_follow_player_y(player_y,enemy_y);
						if (player_x - enemy_x <= 50 && player_x - enemy_x >= 0 && player_y - enemy_y >= -50 && player_y - enemy_y <= 0){
							PlayMusicStream(hit);
							UpdateMusicStream(hit); 
							player_health -= .5;
						}
						if (player_health == 0){
							Level_ID =  Set_Level_ID(0 , Level_ID); 
						}

					}
					break;
				case 7:
					Set_Level_Music(forest_theme);
					DRAW_MAP(map_15);
					if (player_x <= -50){
						player_x = 500;
						Level_ID =  Set_Level_ID(6 , Level_ID); 
					}
					if (player_y <= -25){
						player_y = 475;
						Level_ID =  Set_Level_ID(9 , Level_ID); 
					}
					break ;
				case 8:
					Set_Level_Music(forest_theme);
					DRAW_MAP(map_9);
					if (player_x >= 550){
						player_x = 0;
						Level_ID =  Set_Level_ID(9 , Level_ID); 
					}
					if (player_x <= -50){
						player_x = 500;
						Level_ID =  Set_Level_ID(12 , Level_ID); 
					}
					if (player_x >= 0 && player_x <= 500 && player_y <= 220 && player_y >= 90){
						if (player_direction == 1){player_y +=2;}
						if (player_direction == 4){player_x +=2;}
						if (player_direction == 2){player_x -= 2;}
						if (player_direction == 3){player_y -= 2;}
					}
					if (player_y >= 500){
						player_y = 35;
						Level_ID =  Set_Level_ID(6 , Level_ID); 
					}
					break;
				case 9:
					Set_Level_Music(forest_theme);
					DRAW_MAP(map_10);						
					if (player_x <= -50){
						player_x = 500;
						Level_ID =  Set_Level_ID(8 , Level_ID); 
					}
					if (player_x >= 0 && player_x <= 200 && player_y <= 220 && player_y >= 90){
						if (player_direction == 1){player_y +=2;}
						if (player_direction == 4){player_x +=2;}
						if (player_direction == 2){player_x -= 2;}
						if (player_direction == 3){player_y -= 2;}
					}
					if (player_x >= 240 && player_x <= 500 && player_y <= 220 && player_y >= 90){
						if (player_direction == 1){player_y +=2;}
						if (player_direction == 4){player_x +=2;}
						if (player_direction == 2){player_x -= 2;}
						if (player_direction == 3){player_y -= 2;}
					}

					if (player_x >= 550){
						player_x = 0;
						Level_ID =  Set_Level_ID(10 , Level_ID); 
					}
					if (player_y <= -25){
						player_y = 475;
						Level_ID =  Set_Level_ID(15 , Level_ID); 
					}
					if (player_y >= 500){
						player_y = 35;
						Level_ID =  Set_Level_ID(7 , Level_ID); 
					}
					
					break;
				case 10:
					Set_Level_Music(forest_theme);
					DRAW_MAP(map_11);
					if (player_x <= -25){
						player_x = 524;
						Level_ID =  Set_Level_ID(9 , Level_ID); 
					}
					if (player_x >= 525){
						player_x -=2;
					}
					if (player_x >= 0 && player_x <= 170 && player_y <= 220 && player_y >= 90){
						if (player_direction == 1){player_y +=2;}
						if (player_direction == 4){player_x +=2;}
						if (player_direction == 2){player_x -= 2;}
						if (player_direction == 3){player_y -= 2;}
					}

					break;
				case 12:		
					Set_Level_Music(forest_theme);				
					DRAW_MAP(map_12);
					if (player_x >= 550){
						player_x = 0;
						Level_ID =  Set_Level_ID(8 , Level_ID); 
					}
					if (IsKeyDown(KEY_D) && IsKeyDown(KEY_E) && IsKeyDown(KEY_V)){
						developer_mode = true;
					}
					if (player_x >= 268 && player_x <= 500 && player_y <= 220 && player_y >= 90){
						if (player_direction == 1){player_y +=2;}
						if (player_direction == 4){player_x +=2;}
						if (player_direction == 2){player_x -= 2;}
						if (player_direction == 3){player_y -= 2;}
					}
		
					break;
				case 13:
					Set_Level_Music(forest_theme);
					DRAW_MAP(map_13);
					if (player_y <= -25){
						player_y = 475;
						Level_ID =  Set_Level_ID(14 , Level_ID); 
					}
					if (player_x <= -25){
						player_x = 524;
						Level_ID =  Set_Level_ID(1 , Level_ID); 
					}
					break;
				case 14:
					Set_Level_Music(forest_theme);
					DRAW_MAP(map_14);
					if (player_y <= -25){
						player_y = 475;
						Level_ID =  Set_Level_ID(7 , Level_ID); 
					}

					if (player_x <= -50){
						player_x = 500;
						Level_ID =  Set_Level_ID(4 , Level_ID); 
					}
					break;
				case 15:
				    Set_Level_Music(forest_theme);
					DRAW_MAP(map_16);
					if (player_x <= -50){
						player_x = 500;
						Level_ID =  Set_Level_ID(16 , Level_ID); 
					}
					if (player_y >= 500){
						player_y = 35;
						Level_ID =  Set_Level_ID(9 , Level_ID); 
					}
					if (player_x >= 22 && player_x <= 176 && player_y <= 307 && player_y >= 15){
						if (player_direction == 1){player_y +=2;}
						if (player_direction == 4){player_x +=2;}
						if (player_direction == 2){player_x -= 2;}
						if (player_direction == 3){player_y -= 2;}
					}
					if (player_x >= 236 && player_x <= 430 && player_y <= 307 && player_y >= 15){
						if (player_direction == 1){player_y +=2;}
						if (player_direction == 4){player_x +=2;}
						if (player_direction == 2){player_x -= 2;}
						if (player_direction == 3){player_y -= 2;}
					}
					if (player_x >= 176 && player_x <= 236 && player_y <= 280 && player_y >= 15){
						player_y = 490;
						Level_ID =  Set_Level_ID(18 , Level_ID); 
					}
					break;
				case 16:
					Set_Level_Music(forest_theme);
					DRAW_MAP(map_17);
					if (player_x >= 550){
						player_x = 0;
						Level_ID =  Set_Level_ID(15 , Level_ID); 
					}
					break;
				case 18:
					Set_Level_Music(castle_music);
					DRAW_MAP(map_18);
					if (player_x <= -50){
						player_x = 500;
						Level_ID =  Set_Level_ID(19 , Level_ID); 
					}
					if (player_x >= 550){
						player_x = 0;
						isenemy = true;
						Level_ID =  Set_Level_ID(23 , Level_ID); 
					}
					if (player_x >= 0 && player_x <= 125 && player_y <= 50 && player_y >= 0){
						DrawTexture(Chatbubble,0,400,WHITE);
						DrawTexture(player_chaticon,5,400,WHITE);
						DrawText("Thats a Bookself.... Nothing usful here",55,410,15,BLACK);
					}
					if (player_x >= 180 && player_x <= 250 && player_y <= 50 && player_y >= 0){
						DrawTexture(Chatbubble,0,400,WHITE);
						DrawTexture(player_chaticon,5,400,WHITE);
						DrawText("Theres Something In there......",55,410,15,BLACK);
					}
					if (player_y <= -25){
						player_y = 475;
						isenemy = true;
						enemy_x = 150;
						enemy_y = 100;
						Level_ID =  Set_Level_ID(24 , Level_ID); 
					}
					break;

				case 19:
					Set_Level_Music(castle_music);
					DRAW_MAP(map_19);
					if (player_y >= 500){
						player_y = 35;
						Level_ID =  Set_Level_ID(20 , Level_ID); 
					}
					if (player_y <= -25){
						player_y = 525;
						Level_ID = Set_Level_ID(22, Level_ID); 
					}
					if (player_x >= 525){
						player_x = 24;
						Level_ID =  Set_Level_ID(18 , Level_ID); 
					}
					if (player_x >= 0 && player_x <= 5 && player_y <= 500 && player_y >= 0){
						if (player_direction == 1){player_y +=2;}
						if (player_direction == 4){player_x +=2;}
						if (player_direction == 2){player_x -= 2;}
						if (player_direction == 3){player_y -= 2;}
					}
					break;
				case 20:
					Set_Level_Music(castle_music);
					DRAW_MAP(map_20);
					if (player_y >= 500){
						player_y = 35;
						Level_ID =  Set_Level_ID(21 , Level_ID); 
					}
					if (player_y <= -25){
						player_y = 475;
						Level_ID =  Set_Level_ID(19, Level_ID); 
					}
					break;
				case 21:
					Set_Level_Music(castle_music);
					DRAW_MAP(map_21);
					if (player_y <= -25){
						player_y = 475;
						Level_ID =  Set_Level_ID(20 , Level_ID); 
					}
					if (player_x >= 0 && player_x <= 500 && player_y <= 500 && player_y >= 450){
						if (player_direction == 1){player_y +=2;}
						if (player_direction == 4){player_x +=2;}
						if (player_direction == 2){player_x -= 2;}
						if (player_direction == 3){player_y -= 2;}
					}
					break;
				case 22:
					Set_Level_Music(castle_music);
					DRAW_MAP(map_22);
					if (player_y >= 525){
						player_y = 35;
						Level_ID =  Set_Level_ID(19 , Level_ID); 
					}
					break;
				case 23:
					Set_Level_Music(castle_music);
					DRAW_MAP(map_23);
					if (IsGamepadAvailable(GAMEPAD_PLAYER1)){
						if (IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN) == true && isitem == 0){
							DrawTexture(player_1,player_x,player_y,WHITE);
							if (player_x - enemy_x <= 50 && player_x - enemy_x >= 0 && player_y - enemy_y >= -50 && player_y - enemy_y <= 0){
								PlayMusicStream(enemy_death);
								UpdateMusicStream(enemy_death); 

								isenemy = false;
								if (isenemy == true){player_exp += 1;}
							}
						}
					}
					else{
						if (IsKeyDown(KEY_A) && isitem == 0){
							DrawTexture(player_1,player_x,player_y,WHITE);
							if (player_x - enemy_x <= 50 && player_x - enemy_x >= 0 && player_y - enemy_y >= -50 && player_y - enemy_y <= 0){
								PlayMusicStream(enemy_death);
								UpdateMusicStream(enemy_death); 
								isenemy = false;
								if (isenemy == true){player_exp += 1;}
							}
						}
						if (projectile_x - enemy_x <= 50 && projectile_x  - enemy_x >= 0 && projectile_y - enemy_y >= -50 && projectile_y - enemy_y <= 0){
							PlayMusicStream(enemy_death);
							UpdateMusicStream(enemy_death); 
							isenemy = false;
							if (isenemy == true){player_exp += 1;}
						}
					}
					if (isenemy == true){
						DrawTexture(bat,enemy_x,enemy_y,WHITE);
						enemy_y -= 20;
						enemy_x = enemy_follow_player_x(player_x,enemy_x);
						enemy_y = enemy_follow_player_y(player_y,enemy_y);
						if (player_x - enemy_x <= 50 && player_x - enemy_x >= 0 && player_y - enemy_y >= -50 && player_y - enemy_y <= 0){
							PlayMusicStream(hit);
							UpdateMusicStream(hit); 
							player_health -= .5;
						}
						if (player_health == 0){
							Level_ID = Set_Level_ID(0, Level_ID); 
						}
						enemy_y += 20;
					}
					if (player_x <= -50){
						player_x = 500;
						Level_ID =  Set_Level_ID(18 , Level_ID); 
					}
					if (player_x >= 550){
						player_x = 0;
						Level_ID =  Set_Level_ID(25 , Level_ID); 
					}
					break;
				case 24: 
					DRAW_MAP(BOSS_ROOM_1);
					if (IsGamepadAvailable(GAMEPAD_PLAYER1)){
						if (IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN) == true && isitem == 0){
							DrawTexture(player_1,player_x,player_y,WHITE);
							if (player_x - enemy_x <= 50 && player_x - enemy_x >= 0 && player_y - enemy_y >= -50 && player_y - enemy_y <= 0){
								PlayMusicStream(enemy_death);
								UpdateMusicStream(enemy_death); 
								isenemy = false;
								if (isenemy == true){player_exp += 1;}
							}
						}
					}
					else{
						if (IsKeyDown(KEY_A) && isitem == 0){
							DrawTexture(player_1,player_x,player_y,WHITE);
							if (player_x - enemy_x <= 50 && player_x - enemy_x >= 0 && player_y - enemy_y >= -50 && player_y - enemy_y <= 0){
								PlayMusicStream(enemy_death);
								UpdateMusicStream(enemy_death); 
								isenemy = false;
								if (isenemy == true){player_exp += 1;}
							}
						}
						if (projectile_x - enemy_x <= 50 && projectile_x  - enemy_x >= 0 && projectile_y - enemy_y >= -50 && projectile_y - enemy_y <= 0){
							PlayMusicStream(enemy_death);
							UpdateMusicStream(enemy_death); 
							isenemy = false;
							if (isenemy == true){player_exp += 1;}
						}
					}
					if (isenemy == true){
						DrawTexture(prince_1,enemy_x,enemy_y,WHITE);
						enemy_x = enemy_follow_player_x(player_x,enemy_x);
						enemy_y = enemy_follow_player_y(player_y,enemy_y);
						if (player_x - enemy_x <= 50 && player_x - enemy_x >= 0 && player_y - enemy_y >= -50 && player_y - enemy_y <= 0){
							PlayMusicStream(hit);
							UpdateMusicStream(hit); 
							player_health -= .5;
						}
						if (player_health == 0){
							Level_ID = Set_Level_ID(0 , Level_ID); 
						}

					}
					break;
				case 25:
					Set_Level_Music(castle_music);
					DRAW_MAP(map_24);
					if (player_x <= -50){
						player_x = 500;
						Level_ID = Set_Level_ID(23 , Level_ID); 
					}
					if (player_x >= 495 && player_x <= 500 && player_y <= 500 && player_y >= 0){
						if (player_direction == 1){player_y +=2;}
						if (player_direction == 4){player_x +=2;}
						if (player_direction == 2){player_x -= 2;}
						if (player_direction == 3){player_y -= 2;} 
					}
					if (IsGamepadAvailable(GAMEPAD_PLAYER1)){
						if (IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN) == true && isitem == 0){
							DrawTexture(player_1,player_x,player_y,WHITE);
							if (player_x - enemy_x <= 50 && player_x - enemy_x >= 0 && player_y - enemy_y >= -50 && player_y - enemy_y <= 0){
								PlayMusicStream(enemy_death);
								UpdateMusicStream(enemy_death); 
								isenemy = false;
								if (isenemy == true){player_exp += 1;}
							}
						}
					}
					else{
						if (IsKeyDown(KEY_A) && isitem == 0){
							DrawTexture(player_1,player_x,player_y,WHITE);
							if (player_x - enemy_x <= 50 && player_x - enemy_x >= 0 && player_y - enemy_y >= -50 && player_y - enemy_y <= 0){
								PlayMusicStream(enemy_death);
								UpdateMusicStream(enemy_death); 
								isenemy = false;
								if (isenemy == true){player_exp += 1;}
							}
						}
						if (projectile_x - enemy_x <= 50 && projectile_x  - enemy_x >= 0 && projectile_y - enemy_y >= -50 && projectile_y - enemy_y <= 0){
							PlayMusicStream(enemy_death);
							UpdateMusicStream(enemy_death); 
							isenemy = false;
							if (isenemy == true){player_exp += 1;}
						}
					}
					if (isenemy == true){
						DrawTexture(mummy_1,enemy_x,enemy_y,WHITE);
						enemy_x = enemy_follow_player_x(player_x,enemy_x);
						enemy_y = enemy_follow_player_y(player_y,enemy_y);
						if (player_x - enemy_x <= 50 && player_x - enemy_x >= 0 && player_y - enemy_y >= -50 && player_y - enemy_y <= 0){
							PlayMusicStream(hit);
							UpdateMusicStream(hit); 
							player_health -= .5;

						}
						if (player_health == 0){
							Level_ID = 0;
						}
						if (enemy_isshoot == false){enemy_isshoot = true;enemy_projectile_x = enemy_x;enemy_projectile_y = enemy_y;}

						if (enemy_isshoot == true){
							DrawTexture(arrow_1,enemy_projectile_x,enemy_projectile_y,WHITE);
							projectile_y = enemy_follow_player_y(player_y,enemy_projectile_y);
							projectile_x = enemy_follow_player_x(player_x,enemy_projectile_x);
						}
						
					}
				case 26:
					Set_Level_Music(forest_theme);
					DRAW_MAP(map_25);
					if (player_x >= 550){
						player_x = 0;
						Level_ID =  Set_Level_ID(2 , Level_ID); 
					}
					if (IsGamepadAvailable(GAMEPAD_PLAYER1)){
						if (IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN) == true && isitem == 0){
							DrawTexture(player_1,player_x,player_y,WHITE);
							if (player_x - enemy_x <= 50 && player_x - enemy_x >= 0 && player_y - enemy_y >= -50 && player_y - enemy_y <= 0){
								PlayMusicStream(enemy_death);
								UpdateMusicStream(enemy_death); 
								isenemy = false;
								if (isenemy == true){player_exp += 1;}
							}
						}
					}
					else{
						if (IsKeyDown(KEY_A) && isitem == 0){
							DrawTexture(player_1,player_x,player_y,WHITE);
							if (player_x - enemy_x <= 50 && player_x - enemy_x >= 0 && player_y - enemy_y >= -50 && player_y - enemy_y <= 0){
								PlayMusicStream(enemy_death);
								UpdateMusicStream(enemy_death); 
								isenemy = false;
								if (isenemy == true){player_exp += 1;}
							}
						}
						if (projectile_x - enemy_x <= 50 && projectile_x  - enemy_x >= 0 && projectile_y - enemy_y >= -50 && projectile_y - enemy_y <= 0){
								PlayMusicStream(enemy_death);
								UpdateMusicStream(enemy_death); 
								isenemy = false;
								if (isenemy == true){player_exp += 1;}
						}
					}
					if (isenemy == true){
						DrawTexture(slime_enemy_red,enemy_x,enemy_y,WHITE);
						if (enemy_isjump == false){
							enemy_isjump = true;
						}
						enemy_x = enemy_follow_player_x(player_x,enemy_x);
						enemy_y = enemy_follow_player_y(player_y,enemy_y);
						if (player_x - enemy_x <= 50 && player_x - enemy_x >= 0 && player_y - enemy_y >= -50 && player_y - enemy_y <= 0){
							PlayMusicStream(hit);
							UpdateMusicStream(hit); 
							player_health -= .5;
						}
						if (player_health == 0){
							Level_ID =  Set_Level_ID(0 , Level_ID); 
						}
						if (enemy_isjump == true){
							if (enemy_jumpcount >= -10){
								enemy_y -= (enemy_jumpcount * abs(enemy_jumpcount)) * .2;
								enemy_jumpcount -= 1;
							}
							else{
								enemy_jumpcount = 10;
								enemy_isjump = false;
							}
						}

					}
					if (player_x <= -50){
						player_x = 500;
						Level_ID =  Set_Level_ID(27 , Level_ID); 
					}
					break;
				case 27:
					Set_Level_Music(lava_theme);
					DRAW_MAP(map_26);
					if (player_x >= 550){
						player_x = 0;
						Level_ID =  Set_Level_ID(26 , Level_ID); 
					}
					if (player_x <= -50){
						player_x = 500;
						Level_ID = Set_Level_ID(28 , Level_ID); 
					}
					break;
				case 28:
					Set_Level_Music(lava_theme);
					DRAW_MAP(map_27);
					if (player_x >= 550){
						player_x = 0;
						Level_ID = Set_Level_ID(27 , Level_ID); 
					}
					if (player_x <= -50){
						player_x = 500;
						Level_ID = Set_Level_ID(29 , Level_ID); 
					}
					break;
				case 29:
					Set_Level_Music(lava_theme);
					DRAW_MAP(map_28);
					if (player_x >= 550){
						player_x = 0;
						Level_ID =  Set_Level_ID(28 , Level_ID); 
					}
					break;
				}

				
			}
			draw_level(player_level); /* Update Level*/
		}
		if (IsKeyDown(KEY_F3)){
			DrawFPS(50,50);
		}
		if (Level_ID >= 1 && Level_ID != 100 ){
			update_player(player_direction, player_x, player_y ,player_1, player_1_2 ,player_1_3, player_2 ,player_2_2,player_2_3,player_3,player_3_2,player_3_3,player_4, player_4_2, player_4_3,shader,ismoving , animation_count);
			update_hearts(player_health, hearts);
			update_exp(player_exp,expbar);
			update_inventory(inventory_weapon,inventory_bar);
		}
		// This is the Arrow code 
		if (isshoot == true){
			switch (player_direction)
			{
				case 1:
					DrawTexture(arrow_1, projectile_x, projectile_y,WHITE);
					projectile_y -= 8;
					if (projectile_y <= -50){
						isshoot = false;
					}
					break;
				case 2:
					DrawTexture(arrow_2, projectile_x, projectile_y,WHITE);
					projectile_x += 8;
					if (projectile_x >= 550){
						isshoot = false;
					}
					break;
				case 3:
					DrawTexture(arrow_3, projectile_x, projectile_y,WHITE);
					projectile_y += 8;
					if (projectile_y >= 550){
						isshoot = false;
					}
					break;
				case 4:
					DrawTexture(arrow_4, projectile_x, projectile_y,WHITE);
					projectile_x -= 8;
					if (projectile_x <= -50){
						isshoot = false;
					}
					break;
			}
		}
		EndDrawing();
		// This updates EXP and LEVEL
		animation_count += 3;
		if (animation_count >= 100){
			animation_count = 0;
		}
		if (player_exp >= 100){
			player_exp = 0;
			PlayMusicStream(levelup);
			UpdateMusicStream(levelup); 
			player_level += 1;
		}
	}
	CloseWindow();
	return 0;
}
