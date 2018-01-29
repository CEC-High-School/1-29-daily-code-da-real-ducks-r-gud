#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include<iostream>
using namespace std;
#define BONES NULL

int main() {

	int age = 0;

	ALLEGRO_DISPLAY *display = BONES;

	if (!al_init()) {
		fprintf(stderr, "Allegro failed initialization!\n");
		system("pause");
		return -1;
	}
	if (!al_init_font_addon()) {
		fprintf(stderr, "Allegro Font Addon failed initialization!\n");
		system("pause");
		return -1;
	}
	if (!al_init_ttf_addon()) {
		fprintf(stderr, "Allegro TTF Addon failed initialization!\n");
		system("pause");
		return -1;
	}
	display = al_create_display(800, 800);
	if (!display) {
		fprintf(stderr, "Allegro display failed to initialize!");
		system("pause");
		return -1;
	}
	
	ALLEGRO_FONT *sans = al_load_font("b.ttf", 72, 0);
	al_clear_to_color(al_map_rgb(255, 255, 255));
	al_draw_text(sans, al_map_rgb(0, 0, 0), 400, 300, ALLEGRO_ALIGN_CENTER, "Enter your age!");
	al_flip_display();

	cout << "Age: ";
	cin >> age;

	al_clear_to_color(al_map_rgb(255, 255, 255));
	al_draw_textf(sans, al_map_rgb(0, 0, 0), 400, 300, ALLEGRO_ALIGN_CENTER, "Happy %dth birthday!", age);
	al_flip_display();
	al_rest(5);
	al_destroy_display(display);

}

