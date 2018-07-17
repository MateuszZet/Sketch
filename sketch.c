/**
Program do rysowania na gameboya z menu. Nauka gbdk, Napisane przy pomocy tutorialu:
https://www.youtube.com/watch?v=JhmbRf7bovo&t=116s

Nie działa gotxy();
Inacej zrobiłem czyszczenie: za pomocą rysowania białego prostokąta w funkcji erase.
Dodałem rysowanie na szaro.
Mateusz Ząbczyk

**/


#include <stdio.h>
#include <gb/gb.h>
#include <ctype.h>
#include <gb/console.h>
#include <gb/drawing.h>

UINT8 x, y;
UINT8 drawing_control = 1;
void print_title();
void sketch();
void print_label();
void erase();
void print_label2();


void main(){
	
	
	print_title();
	print_label2();
	waitpad(J_START);
	erase();
	print_label();
	sketch();
	
	
}



void sketch(){
	
	x=30, y=30;
	while(1){
		
		if(joypad() == J_UP){
			y--;
		}
		
		if(joypad() == J_DOWN){
			y++;
		}
		
		if(joypad() == J_LEFT){
			x--;
		}
		
		if(joypad() == J_RIGHT){
			x++;
		}
		
		if(joypad() == J_SELECT){
			erase();
			print_label2();
			print_title();
			waitpad(J_START);
			erase();
			print_label();
			sketch();
		}
			
		if(joypad() == J_START){
			
			
		}
		
		if(joypad() == J_A){
			if(drawing_control == 1){
				drawing_control = 0;
				color(WHITE, WHITE, SOLID);
			}else{drawing_control = 1;
			color(BLACK, WHITE, SOLID);
			
			}
		}
		
		if(joypad() == J_B){
			if(drawing_control == 1){
				drawing_control = 0;
				color(WHITE, WHITE, SOLID);
			}else{drawing_control = 1;
				color(LTGREY, WHITE, SOLID);
			}
		}
		
		plot_point(x, y);
		delay(20);
	}
}


void print_title(){
	gotogxy(5,2);
	gprintf("-SKETCH-");
	gotogxy(1,4);
	gprintf("Controls:");
	gotogxy(2,5);
	gprintf("A - white/black");
	gotogxy(2,6);
	gprintf("B - white/grey");
	gotogxy(2,7);
	gprintf("SELECT - reset");
	gotogxy(3,9);
	gprintf("<PRESS START>");
	gotogxy(8,12);
	gprintf("2017");
	gotogxy(2,13);
	gprintf("Mateusz Zabczyk");
}

void print_label(){
	color(BLACK, WHITE, SOLID);
	box(156,140,2,2,M_NOFILL);
	box(155,139,3,3,M_NOFILL);
	box(153,137,5,5,M_NOFILL);
	box(152,136,6,6,M_NOFILL);
}

void print_label2(){
	color(BLACK, WHITE, SOLID);
	box(156,140,2,2,M_NOFILL);
	box(154,138,4,4,M_NOFILL);
	box(152,136,6,6,M_NOFILL);
}

void erase(){
	color(WHITE, WHITE, SOLID);
	box(156,140,2,2,M_FILL);
}



