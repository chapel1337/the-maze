#ifdef __linux__
#include <unistd.h>

cout << "your operating system is incompatible with this program!\n";

sleep(2);
exit(1);

#elif _WIN32
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <windows.h>
#endif

using std::cout; using std::cin; using std::string; using std::vector;

/*
* written by chapel1337
* started on 10/30/2022
* unfinished, currently 10:12pm!!

* refined a ton, currently 10/31/2022
* currently 9:26pm, was working on this whilst giving out candy
* best constume i saw was a box (my actual favorite was a scarecrow)
* might add map loading
* 
* finished on 11/1/2022
* adding final touches and finishing making maps
* this took much longer than it should've to make, i've unfortunately been pretty busy
* finished, currently 6:23pm
*/

vector<vector<char>> map1
{
	// craze
	{ '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',  },
	{ '#', '#', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '#', '#', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '#', '#',  },
	{ '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',  },
	{ '#', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', ' ', ' ', ' ', '#', '#', '#', '#', '#', ' ', ' ', ' ', '#', '#', '#', '#', '#', ' ', ' ', ' ', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', ' ', ' ', ' ', '#', '#', '#', '#', '#', ' ', ' ', ' ', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', '#',  },
	{ '#', ' ', ' ', ' ', '#', ' ', ' ', '#', '#', '#', ' ', ' ', '#', ' ', ' ', '#', '#', '#', ' ', ' ', '#', ' ', ' ', '#', '#', '#', ' ', ' ', '#', ' ', ' ', '#', '#', '#', ' ', ' ', '#', ' ', ' ', ' ', '#', '#', '#', ' ', ' ', '#', ' ', ' ', '#', '#', '#', ' ', ' ', '#', ' ', ' ', '#', '#', '#', ' ', ' ', '#', ' ', ' ', ' ', '#',  },
	{ '#', ' ', ' ', '#', '#', '#', ' ', ' ', '#', ' ', ' ', '#', '#', '#', ' ', ' ', '#', ' ', ' ', '#', '#', '#', ' ', ' ', '#', ' ', ' ', '#', '#', '#', ' ', ' ', '#', ' ', ' ', '#', '#', '#', ' ', ' ', ' ', '#', ' ', ' ', '#', '#', '#', ' ', ' ', '#', ' ', ' ', '#', '#', '#', ' ', ' ', '#', ' ', ' ', '#', '#', '#', ' ', ' ', '#',  },
	{ '#', ' ', '#', '#', '#', '#', '#', ' ', ' ', ' ', '#', '#', '#', '#', '#', ' ', ' ', ' ', '#', '#', '#', '#', '#', ' ', ' ', ' ', '#', '#', '#', '#', '#', ' ', ' ', ' ', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', ' ', ' ', ' ', '#', '#', '#', '#', '#', ' ', ' ', ' ', '#', '#', '#', '#', '#', '@', '#',  },
	{ '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',  },
	{ '#', '#', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '#', '#', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '#', '#',  },
	{ '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',  },
};

vector<vector<char>> map2
{
	{ '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',  },
	{ '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#',  },
	{ '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#',  },
	{ '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#',  },
	{ '#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', '@', '#',  },
	{ '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',  },
};

vector<vector<char>> map3
{
	{ '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',  },
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',  },
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'H', 'A', 'P', 'P', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',  },
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'H', 'A', 'L', 'L', 'O', 'W', 'E', 'E', 'N', '!', ' ', ' ', ' ', ' ', ' ', ' ', '#',  },
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',  },
	{ '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',  },
};

vector<vector<char>> currentMap { map1 };

vector<vector<vector<char>>> mapList{ map1, map2, map3 }; // scary
int currentMapInt{};

// probably should use maps for this
vector<int> playerPositionsX{ 1, 1, 1 };
vector<int> playerPositionsY{ 6, 4, 4 };

unsigned int mapX{ currentMap[currentMapInt].size() };
unsigned int mapY{ currentMap.size() };

int playerX{ playerPositionsX[0] };
int playerY{ playerPositionsY[0] };

int character{ 1 };

bool wDisabled{ false };
bool aDisabled{ false };
bool sDisabled{ false };
bool dDisabled{ false };
bool statisticsEnabled{ false };

enum Color
{
	black,
	blue,
	green,
	cyan,
	red,
	purple,
	yellow,
	white,
	grey,
	brightBlue,
	brightGreen,
	brightCyan,
	brightPink,
	brightPurple,
	brightYellow,
	brightWhite
};

// ------- \\

void goTo(string function);

void setTextColor(Color color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void resetTextColor()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void clear()
{
	system("cls");
}

void sleep(int time)
{
	Sleep(time * 1000);
}

void invalidInput(string message, string function)
{
	clear();

	cout << "invalid input: " << message << "\n\n";

	sleep(2);
	goTo(function);
}

// ------- \\

void reset()
{
	playerX = playerPositionsX[0];
	playerY = playerPositionsY[0];

	currentMapInt = 0;
	currentMap.clear();
}

void youLose()
{
	clear();
	reset();

	setTextColor(red);

	cout << "you lose!\n\n";

	resetTextColor();

	cin.get();
	cin.ignore();

	goTo("menu");
}

void youWin()
{
	clear();
	reset();

	setTextColor(green);

	cout << "you win!\n\n";

	resetTextColor();

	cin.get();
	cin.ignore();

	goTo("menu");
}

// ------- \\

void refresh()
{
	goTo("setPlayerPosition");
	clear();

	if (statisticsEnabled)
	{
		cout << "w: " << wDisabled << '\n';
		cout << "a: " << aDisabled << '\n';
		cout << "s: " << sDisabled << '\n';
		cout << "d: " << dDisabled << '\n';
		cout << "player: " << playerX << ", " << playerY << '\n';
		cout << "map: " << mapX << ", " << mapY << "\n\n";
	}

	for (int i{ 0 }; i < currentMap.size(); ++i)
	{
		for (int o{ 0 }; o < currentMap[i].size(); ++o)
		{
			if (currentMap[i][o] == '@')
			{
				setTextColor(green);

				cout << currentMap[i][o];

				resetTextColor();
			}
			/*
			else if (currentMap[i][o] == '#')
			{
				setTextColor(grey);

				cout << currentMap[i][o];

				resetTextColor();
			}
			*/
			else if (currentMap[i][o] == static_cast<char>(character))
			{
				setTextColor(yellow);

				cout << currentMap[i][o];

				resetTextColor();
			}
			else
			{
				cout << currentMap[i][o];
			}
		}

		cout << '\n';
	}

	goTo("getInput");
}

void nextMap()
{
	if (mapList.size() - 1 == currentMapInt)
	{
		youWin();
	}
	else
	{
		currentMap = mapList[currentMapInt];
		currentMapInt++;

		mapX = mapList[currentMapInt][0].size();
		mapY = mapList[currentMapInt].size();


		playerX = playerPositionsX[currentMapInt];
		playerY = playerPositionsY[currentMapInt];
	}

	refresh();
}

void setPlayerPosition()
{
	// finally got it working!!
	currentMap.clear();
	currentMap = mapList[currentMapInt];

	for (int i{ 0 }; i < currentMap.size(); ++i)
	{
		for (int o{ 0 }; o < currentMap[i].size(); ++o)
		{
			if (currentMap[playerY][playerX] == '^' || currentMap[playerY][playerX] == '>' || currentMap[playerY][playerX] == '<' || currentMap[playerY][playerX] == 'v')
			{
				youLose();
			}
			else if (currentMap[playerY][playerX] == '@')
			{
				playerY++;

				nextMap();
			}

			// there is probably a better way to do this
			if (currentMap[playerY - 1][playerX] == '#')
			{
				wDisabled = true;
			}
			else
			{
				wDisabled = false;
			}

			if (currentMap[playerY + 1][playerX] == '#')
			{
				sDisabled = true;
			}
			else
			{
				sDisabled = false;
			}

			if (currentMap[playerY][playerX + 1] == '#')
			{
				dDisabled = true;
			}
			else
			{
				dDisabled = false;
			}

			if (currentMap[playerY][playerX - 1] == '#')
			{
				aDisabled = true;
			}
			else
			{
				aDisabled = false;
			}
		}

		cout << '\n';
	}

	currentMap[playerY][playerX] = static_cast<char>(character);
}

// ------- \\

void moveBlock(string direction)
{
	/*
	// to prevent substring errors
	if (playerY == 0 && direction == "up")
	{
		refresh();
	}
	else if (playerY == mapY - 1 && direction == "down")
	{
		refresh();
	}
	else if (playerX == 0 && direction == "left")
	{
		refresh();
	}
	else if (playerX == mapX - 1 && direction == "right")
	{
		refresh();
	}
	*/

	if (direction == "up")
	{
		playerY--;
	}
	else if (direction == "down")
	{
		playerY++;
	}

	else if (direction == "right")
	{
		playerX++;
	}
	else if (direction == "left")
	{
		playerX--;
	}

	refresh();
}

void getInput()
{
	int input{ _getch() };

	switch (input)
	{
	case 'w':
		if (!wDisabled) moveBlock("up"); // scary one line if statements (it's halloween)
		break;

	case 's':
		if (!sDisabled) moveBlock("down");
		break;

	case 'd':
		if (!dDisabled) moveBlock("right");
		break;

	case 'a':
		if (!aDisabled) moveBlock("left");
		break;

	case 27:
		goTo("menu");
		break;
	}

	getInput();
}

// ------- \\

void chooseCharacter()
{
	clear();

	cout << "1. " << static_cast<char>(1) << '\n';
	cout << "2. " << static_cast<char>(2) << "\n\n";

	cout << "choose your character: \n\n";

	cout << "> ";
	cin >> character;

	if (character != 1 && character != 2)
	{
		invalidInput("please specify 1, or 2", "chooseCharacter");
	}

	clear();

	cout << "changed character to: " << static_cast<char>(character) << "\n\n";
	cout << "> ";

	sleep(2);
	goTo("menu");
}

void toggleStatistics()
{
	clear();

	if (statisticsEnabled)
	{
		statisticsEnabled = false;

		cout << "statistics disabled\n\n";
	}
	else
	{
		statisticsEnabled = true;

		cout << "statistics enabled\n\n";
	}

	cout << "> ";

	sleep(2);
	goTo("menu");
}

void menu()
{
	clear();

	char response{};

	cout << "the maze\n\n";

	cout << "1. start\n";
	cout << "2. choose character\n";
	cout << "3. enable statistics\n\n";

	cout << "> ";
	cin >> response;

	switch (response)
	{
	case '1':
		refresh();
		break;

	case '2':
		chooseCharacter();
		break;

	case '3':
		toggleStatistics();
		break;

	default:
		invalidInput("please specify 1 or 2", "menu");
		break;
	}
}

// ------- \\

void goTo(string function)
{
	if (function == "getInput")
	{
		getInput();
	}
	else if (function == "menu")
	{
		menu();
	}
	else if (function == "setPlayerPosition")
	{
		setPlayerPosition();
	}
	else if (function == "chooseCharacter")
	{
		chooseCharacter();
	}
}

int main()
{
	menu();
}

// ------- \\