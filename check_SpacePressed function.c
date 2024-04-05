#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <time.h>
#include <stdbool.h>

#define PS2_BASE ((volatile long *) 0xFF200100)
bool check_SpacePressed();

int main(void) {
	
	check_SpacePressed();
	printf("GAME START"); 
}

bool check_SpacePressed(){
	volatile int * PS2_ptr = (int *)PS2_BASE;
	int PS2_data, RVALID;
	bool gameStart = false; 
	*(PS2_ptr) = 0xFF;
	while (!gameStart) {
		PS2_data = *(PS2_ptr);
		RVALID = PS2_data & 0x8000;
		if (RVALID && PS2_data == 32809) { //32809 is num stored in PS2_data if space is pressed
			gameStart = true; 
		}
	}		
}