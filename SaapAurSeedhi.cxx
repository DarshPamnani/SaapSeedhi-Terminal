#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
using namespace std;

//Players
struct Player{
    int position;
	string name;
};

Player List_of_Players[4];
int size = 0;

Player Winners[3];
int rank = 0; 

bool add_to(Player array[], int &size, int capacity, Player P){
	if(size >= 0 && size<capacity){									//size itself is the index of the next empty space in the array
		array[size] = P;
		size++;
		return true;
	}
	cout<<"ERROR adding\n";
	return false;
}

bool remove_from(Player array[], int &size, int index){
	if(index >= 0 && index < size){
		for(int i = index; i < size-1; i++){
			array[i] = array[i+1];
			return true;
		}
	}
	cout<<"ERROR removing\n";
	return false;
}

bool display(Player array[], int size){
		cout << "\t";
		if(size == 0){cout << ".............\n";}
		for(int i=0; i<size; i++){
			cout <<" " << List_of_Players[i].name << ",\t";
		}
	return true;
}

//Dice
int on_roll;
int dice_roll(void){
	int value = (rand() % 6) + 1;
	cout << "->" << value << "\n";
    return value;
}

//Board

void update(Player player){
	
	player.position = player.position +::on_roll;

	int ladder_start[5] = {5, 15, 77, 85, 43};
	int ladder_end[5] = {45, 24, 88, 91, 99};
	
	for(int i=0; i < 5; i++){
		if(player.position == ladder_start[i]){
			cout << "|\n|\n|\n";
			player.position = ladder_end[i];
		}
	}

	cout << player.name <<" @" << player.position << "\n";
}
	
	
int main()
{
	srand((unsigned int)time(NULL));


	//PLAYERS PUTTING
	int n = 4;  //No. of players
	for(int i=0; i<n; i++){
		Player P = {0, "Player " + to_string(i + 1)};
		add_to(List_of_Players, ::size, 4, P);

	}
	
	//PLAYERS CONFIRMING
	//display(List_of_Players, ::size);
	
	int turn_count = 0;

	//MAIN LOOP
	while (::rank <= n-1){
		
		for(int i = 0; i<::size; i++){
			
			on_roll = dice_roll();
			update(List_of_Players[i]);
			
			

			//WINNER CONDITION
			if(List_of_Players[i].position >= 100){
				Player winner = List_of_Players[i];
				remove_from(List_of_Players, ::size, i);
				add_to(Winners, ::rank, 3, winner);
			}
			display(List_of_Players, ::size);
			display(Winners, ::rank);
		
		}

		turn_count++;
		cout << "\n___________________________________Turn:" <<  "\n";

		};
		
		add_to(Winners, ::rank, 3, List_of_Players[0]); 			//The last player is added to the winners list as it is the last one remaining in the game.
		
		cout << "WINNERS:\n";
		for(int i=0; i<= ::rank; i++){
			cout << i+1 << ":" << Winners[i].name << "\n";
		}

		return 0;
}