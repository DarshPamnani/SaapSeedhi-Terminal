#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

//Players
struct Player{
    int position;
	string name;
};

Player List_of_Players[4];
int size = 0;	//size => no. of players in the game

Player Winners[3];
int rank = 0; 

//Functions
bool add_to(Player array[], int &size, int capacity, Player P){
	if(size >= 0 && size<capacity){									//size itself is the index of the next empty space in the array
		array[size] = P;
		size++;

		// cout <<"added_ " << array[size-1].name << "to "<< array <<",\t";
		return true;
	}
	cout<<"ERROR adding\n";
	return false;
}

bool remove_from(Player array[], int &size, int index){
	if(index >= 0 && index < size){
		for(int i = index; i < size-1; i++){
			array[i] = array[i+1];
		}
	
		size--;
		return true;
	}

	cout<<"ERROR removing\n";
	return false;
}

bool display(Player array[], int size, string msg){
		cout <<"\n" << msg << "/" << size << '\n';
		if(size == 0){cout << ".............";}

		for(int i=0; i < size; i++){
			cout <<" " << array[i].name << " @" << array[i].position <<"\t" << string((array[i].position / 5), '|');
			if (array[i].position >= 90) cout << '*';
			cout<<'\n';
		}

		cout << "\n";
	return true;
}

//Dice
void Animation(string info)
    {
        string spin = "|/-\\";
    	for(int rotations = 0; rotations<1; rotations++){
			for(char ch : spin){
			    cout<<'\r'<< info << " ROLL! "<<ch;
			    this_thread::sleep_for(chrono::milliseconds(100));
			}
    	}
    }

int on_roll;
int dice_roll(string playerName){
    cout<<'\r'<< playerName << " ROLL! ";
    cin.get();
    cout << "\033[1A\r\033[2K"; // Move cursor up and clear line
    Animation(playerName);

    int value = (rand() % 6) + 1;
    cout << "\b" << value << "\n";
    return value;
} 

//Board

void update(Player &player){
	
	player.position = player.position +::on_roll;

	int ladder_start[5] = {5, 15, 77, 85, 43};
	int ladder_end[5] = {45, 24, 88, 91, 99};
	
	for(int i=0; i < 5; i++){
		if(player.position == ladder_start[i]){
			cout <<'('<< player.position <<')'<< " LaDDer!"<<'\n';
			cout << "#\n#\n#\n";
			player.position = ladder_end[i];
		}
	}

	int snake_start[5] = {17, 34, 72, 48, 93};
	int snake_end[5] = {7, 14, 40, 61, 81};
	
	for(int i=0; i < 5; i++){
		if(player.position == snake_start[i]){
			cout <<'('<< player.position <<')'<< " SnAkE!"<<'\n';
			cout << "S\nS\nS\n";
			player.position = snake_end[i];
		}
	}

	cout << player.name <<" @" << player.position << "\n";
}
	
	
int main()
{
	srand((unsigned int)time(NULL));


	//PLAYERS PUTTING
	int n = 2;  //No. of players

	for(int i=0; i<n; i++){
		Player P = {0, "Player" + to_string(i + 1)};
		add_to(List_of_Players, ::size, 4, P);

	}
	
	//PLAYERS CONFIRMING
	display(List_of_Players, ::size, "GET READY! ");
	
	int turn_count = 0;

	//MAIN LOOP
	while (::rank <= n-1 && ::size > 1){
		
		for(int i = 0; i<::size; i++){
			
			on_roll = dice_roll(List_of_Players[i].name);
			update(List_of_Players[i]);

			//WINNER CONDITION
			if(List_of_Players[i].position >= 100){
				Player winner = List_of_Players[i];
				cout << "\n\t::::" << winner.name << "::::Reached\n";
				remove_from(List_of_Players, ::size, i);
				i--;
				add_to(Winners, ::rank, 3, winner);
			}
			
			display(List_of_Players, ::size, "GAME: ");

			// display(List_of_Players, ::size, "PLAYERS: ");
			// display(Winners, ::rank, "WINNERS: ");
		}

		turn_count++;
		cout << "\n___________________________________Turn:" << turn_count <<  "\n";

		};
		
		add_to(Winners, ::rank, 3, List_of_Players[0]); 			//The last player is added to the winners list as it is the last one remaining in the game.
		
		cout << "RANKINGS:\n";
		for(int i=0; i< ::rank; i++){
			cout << i+1 << ": " << Winners[i].name << "\n";
		}

		return 0;
}