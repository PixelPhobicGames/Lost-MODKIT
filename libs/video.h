#include "raylib.h"
int DRAW_MAP(Texture2D map){
    DrawTexture(map,0,0,WHITE);
}

int draw_level(int level){
	DrawText(FormatText("Level: %i", level), 10, 470, 20, BLACK);
}

int Draw_window(){
    InitWindow(500,500,"Lost..");
}

int Set_Window_icon(Image icon){ 
	SetWindowIcon(icon);
}

