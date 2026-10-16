#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

void add_to(Player array[], int size, int index, Player P){
	if(size >= 0 && size<index){
		array[size] = P;
		size++;
	}
}


//Players
struct Player{
    int position;
};

Player List_of_Players[4];
int size = 0;

Player Winners[4];
int rank = 0; 

//Dice
int dice_roll(void){
    return (rand() % 6) + 1;
}

//Board

void update(int *p){
	
	int ladder_start[5] = {5, 15, 77, 85, 43};
	int ladder_end[5] = {45, 24, 88, 91, 99};
	
	for(int i=0; i < 5; i++){
		if(*p == ladder_start[i]){
			if(*p == p1)
			{
				printf("|\n|\n|\n");
				*p = ladder_end[i];
			}
			else
			{
				printf("\t|\n\t|\n\t|\n");
				*p = ladder_end[i];
			}
		}
	}
	
	printf("\n1@ %d\t 2@ %d", p1,p2);
}
	
	
int main()
{
	int n = 2;
	for(int i=0; i<n; i++){
		Player P = {0};
		add_to(List_of_Players, size, i, P);

	}
	
	for(int i=0; i<n; i++){
		cout << ""
	}
	srand((unsigned int)time(NULL));
	
	int on_roll;
	int count = 0;

	while (p1 < 100 && p2 < 100){
		count++;
		
		for(int i = 1; i<=n; i++){
			switch(i){

				case 1:
				p1+=on_roll;
				update(&p1);
				break;

				case 2:
				p2+=on_roll;
				update(&p2);
				break;
			}
		}
		// on_roll = dice_roll();
		// printf("\nDice value 1- %d\n", on_roll);
		// p1 = p1 + on_roll;
		// update(&p1);
		
		// on_roll = dice_roll();
		// printf("\nDice value 2- %d\n", on_roll);
		// p2 += on_roll;
		// update(&p2);
		
		printf("\n___________________Turn:%d\n", count);
		};
		
		
		
		return 0;
}