# Saap Aur Seedhi

A terminal-based Snake(Saap) and Ladders(Seedhi) game written in C++. 100-square track. Landing on a ladder moves a player forward; landing on a snake moves them backward. The snakes and ladders are hidden! Only the next move can determine whether the square the player lands on is snake or ladder.

## At a glance

| Item | Current implementation |
| --- | --- |
| Language | C++ |
| Max. Players | 4 |
| Starting square | 0 |
| Die | Pseudo-random value from 1 to 6 |
| Track end | 100; reaching or passing it finishes the player |
| Special squares | 5 ladders and 5 snakes |
| Input | Press Enter when prompted to roll |
| Display | Text status lines and a short dice animation |

## Build and run

The source file is [`SaapAurSeedhi.cxx`](./SaapAurSeedhi.cxx). With GCC or MinGW installed, open a terminal in this folder and run:

```sh
g++ -std=c++11 -pthread SaapAurSeedhi.cxx -o SaapAurSeedhi
```

Then start the executable:

```sh
./SaapAurSeedhi
```

On Windows, the executable can be named with an `.exe` extension:

```powershell
g++ -std=c++11 -pthread SaapAurSeedhi.cxx -o SaapAurSeedhi.exe
.\SaapAurSeedhi.exe
```

The program uses `<thread>` and `<chrono>` for the dice animation. The cursor-control escape sequence used to refresh the prompt may not render the same way in every terminal.

## 📌 Inviting to contribute updates

- Implement using vectors in C++, for dynamic array size updation
- Better Snake and Ladder representation. 
Current:

```text
Snake
S
S
S

Ladder
#
#
#
```

## Game Flow
```text
Roll the die
    |
    v
position = position + roll
    |
    +---- position matches a ladder start? ---- yes ---> move to ladder destination
    |
    +---- position matches a snake start? ------ yes ---> move to snake destination
    |
    v
position >= 100?
    |
    +---- yes ---> record finish place and remove from active players
    |
    +---- no ----> player remains active
```


## Logic summary

The game stores active players in one array and finishers in another. On each turn it waits for Enter, rolls a die, advances the current player's position, applies any matching snake or ladder mapping, then checks for a finish. Finished players are recorded and removed from the active array; index adjustment ensures that removing a player does not skip the next player. When play ends, the remaining player is recorded and the winners array is printed as the final ranking.
