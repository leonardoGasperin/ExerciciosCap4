#include<iostream>
#include<vector>
#include "Cap4.h"
#include<time.h>
#include<string>

using namespace std;
//this codes is the solution the exercice of chapter 4 from the book programming principles and practice using cpp
int main()
{
	int opc = 0;
	double temp = 0;
	double aux2 = 0;
	double median = 0;
	int aux3 = 0;
	int num = 0;
	int trys = 0;
	char ope;
	bool Exit = false;
	string ch;
	vector<double> temps; //temperture
	vector<string> numbers = { "zero","one","two","three","four","five","six","seven","eigth","nine" };
	vector<string> operations = { "plus","min","mult","div" };

	while (!Exit)
	{
		cout << "Choosen your exercice:\n1)Fix program from section 4.6.3 to show median.\n2)Distance between two cities\n3)what number I think?\n4)A simple Calculator\n5)write or digit a number\n6)other calculator\n7)Chess lend calculation??\n8)Jo-Ken-Po\n0)Exit\n";
		cin >> opc;
		
		switch (opc)
		{
		case 1:
			cout << "First write how much days you wanna check:\n";
			cin >> aux3;
			cout << "Write the week extimative temperature:\n";

			for (int aux = 0; aux < aux3; aux++)
			{
				cin >> temp;
				temps.push_back(temp);
			}

			temp = 0;

			for (int aux = 0; aux < aux3; aux++)
			{
				for (int i = aux + 1; i < aux3; i++)
				{
					if (temps[aux] > temps[i])
					{
						temp = temps[aux];
						temps[aux] = temps[i];
						temps[i] = temp;
					}
				}
			}

			for (int aux = 0; aux < aux3; aux++)
			{
				cout << "[" << temps[aux] << "] ";
			}

			if (aux3 % 2 != 0)
			{
				temp = aux3 / 2;
				cout << "the median is " << temps[temp] << endl;
			}
			else
			{
				aux3 /= 2;
				median = (temps[aux3] + temps[aux3 - 1]) / 2;
				cout << "the median is " << median << endl;
			}

			break;

		case 2:
			cout << "Write the distance of your city to another two cities:\n";

			for (int aux = 0; aux < 2; aux++)
			{
				cin >> temp;
				temps.push_back(temp);

				if (aux == 1)
				{
					if (temps[aux] < temps[aux - 1])
						aux2 = temps[aux];
					else
						aux2 = temps[aux - 1];
				}
			}

			temp = 0;

			for (int aux = 0; aux < 2; aux++)
			{
				temp += temps[aux];
			}

			cout << "The sum of two distance is " << temp << " and the smallest distance is " << aux2 << "\nFinaly the median of distance is " << temp / 2 << endl;
			break;

		case 3:
			srand(time(NULL));
			num = rand() % 100 + 1;
			cout << "Hello Guess\nIt's me your computer... I wanna play one game with you\nYou have 7 chance to win\nWhat number I thinking?\n";
			cout << "\n estou pensndo em um numero de 1 a 100\n voce tera 7 chances de acerta-lo\n";
			aux3 = 0;
			while (aux3 != 7)
			{
				cin >> trys;
				if (trys >= (num - 10) && trys < num)
				{
					cout << "WoW Boss you are close more little high\n";
					aux3++;
				}
				else if (trys <= (num + 10) && trys > num)
				{
					cout << "WoW Boss you are close more little low\n";
					aux3++;
				}
				else if (trys > num)
				{
					cout << "is much high number\n";
					aux3++;
				}
				else if (trys < num)
				{
					cout << "is much low\n";
					aux3++;
				}

				if (trys == num)
				{
					cout << "Wwweee you thinking like me! Gratz you're so much intellingent\n";
					break;
				}
			}

			if (aux3 == 7 && trys != num)
				cout << "\nSo bad you lose =(";
			break;

		case 4:
			cout << "Write a Interger/Float number:\n";
			cin >> temp;
			cout << "Choose a operator (+ - * /):\n";
			cin >> ope;
			cout << "Another number please:\n";
			cin >> median;

			if (ope == '+')
			{
				aux2 += (temp + median);
				cout << "\nThe Sum of " << temp << " more " << median << " is " << aux2 << endl;
			}
			else if (ope == '-')
			{
				aux2 += (temp - median);
				cout << "\nThe Sub of " << temp << " less " << median << " is " << aux2 << endl;
			}
			else if (ope == '*')
			{
				aux2 += (temp * median);
				cout << "\nThe Mult of " << temp << " by " << median << " is " << aux2 << endl;
			}
			else if (ope == '/')
			{
				aux2 += (temp / median);
				cout << "\nThe Did of " << temp << " by " << median << " is " << aux2 << endl;
			}

			break;

		case 5:
			cout << "Write or digit a Interger of 0 to 9" << endl;
			cin >> ch;
			for (int i = 0; i < numbers.size(); i++)
			{
				if (ch == numbers[i])
				{
					cout << numbers[i] << endl;
					break;
				}
				else if (ch.size() == 1)
				{
					if (stoi(ch) == i)
					{
						cout << i << endl;
						break;
					}
				}
				else
				{
					if (i == 9)
						cout << ch << " don't exist." << endl;
					//break;
				}
			}
			break;
		
		case 6:
			do {
				cout << "Write a Interger/Float number:\n";
				cin >> temp;
				if (temp < 10000000)
					cout << "do again\n";
			} while (temp < 10000000);
				cout << "Choose a operator (+ - * /):\n";
				cin >> ch;
				do {
					cout << "Write a Interger/Float number:\n";
					cin >> median;
					if (median < 10000)
						cout << "do again\n";
				} while (median < 10000);
			
			for (int i = 0; i < operations.size(); i++)
			{
				if (ch == operations[0] || ch == "+")
				{
					aux2 += (temp + median);
					cout << "\nThe Sum of " << temp << " more " << median << " is " << (long int)aux2 << endl;
					break;
				}
				else if (ch == operations[1] || ch == "-")
				{
					aux2 += (temp - median);
					cout << "\nThe Sub of " << temp << " less " << median << " is " << (long int)aux2 << endl;
					break;
				}
				else if (ch == operations[2] || ch == "*")
				{
					aux2 += (temp * median);
					cout << "\nThe Mult of " << temp << " by " << median << " is " << (long int)aux2 << endl;
					break;
				}
				else if (ch == operations[3] || ch == "/")
				{
					aux2 += (temp / median);
					cout << "\nThe Did of " << temp << " by " << median << " is " << (long int)aux2 << endl;
					break;
				}
				else
				{
					cout << ch << " Donot exist" << endl;
					break;
				}
			}
			aux2 = 0;
			break;
		case 7:
			median = 2;
			cout << "The king was a big chess enthusiast and had the habit of challenging wise visitors to a game of chess.\nOne day a traveling sage was challenged by the king. To motivate his opponent the king offered any reward that the sage could name.\nThe sage modestly asked just for a few grains of rice in the following manner:\nthe king was to put a single grain of rice on the first chess square and double it on every consequent one." << endl << "\nHaving lost the game and being a man of his word the king ordered a bag of rice to be brought to the chess board.\nThen he started placing rice grains according to the arrangement:\n1 grain on the first square, 2 on the second,\n4 on the third, 8 on the fourth and so on" << endl << endl;
			cout << "\nAnd on final the guess woned " << pow(median, 64) << " grains of rices.";
			cout << endl << endl << "and if the first grain of rice is 10?\n";
			cout << "\nOn final the guess woned " << pow((median*10), 64) << " grains of rices.";
			cout << endl << endl << "Or 100?\n";
			cout << "\nOn final the guess woned " << pow((median * 100), 64) << " grains of rices.";
			cout << endl << endl << "Or 1000?\n";
			cout << "\nOn final the guess woned " << pow((median * 1000), 64) << " grains of rices.";
			break;
		case 8:
			/*srand(time(NULL));
			num = rand() % 3;

			cout << "Hello Guess\n let's play:\n" << endl;*/
			BunraKo();

			break;
		case 0:
			cout << "Bye-Bye" << endl;
			break;
		default:
			cout << "Missing valor!\nEnjoy\n";
			BunraKo();
			break;
		}

		if (opc != 0)
		{
			cout << "Do you wanna exit?\n1. Yes\n0. No\n" << endl;
			cin >> Exit;
			opc = 0;
		}
		else
			Exit = true;
	}
}

void BunraKo()
{
	int num;
	int aux;
	int aux2 = 0;
	int myCredit = 1000;
	int bet = 0;
	int pcCredit = 1000;
	int pot = 0;
	bool leave = false;
	bool rules;
	bool oddPair;
	bool pOddPair = NULL;
	bool AIOddPair;
	bool playerTurn;
	bool highBet;
	bool checkBet = false;
	bool playerHavedBet = true;
	string name;

	srand(time(NULL));
	num = rand() % 6 + 1;
	aux = rand() % 6 + 1;

	cout << "Hi Guess! Please enter with your nick:\n";
	cin >> name;
	cout << "Hello " << name << " do you know how to play Bon-ha Ko?(1.yes / 0.no)" << endl;
	cin >> rules;
	if (!rules)
		cout << endl << "Bon-ha Ko is a oldest joponeses game played on Tokugawa age played with dices and bet\nThe game have only two rules:\nFirst all do a bet with any valor the player want\ndoes not matter how much anyone bet, it's only one bet for each turn of dice\nthe bets is for the roll of two dices and the players need choosen odd or pair\nIt's only this good luck!" << endl << endl;
	cout << "Ok " << name << " it's only me and you... do your bet" << endl;

	do
	{
		if (bet != 0 || bet != NULL)
			bet = 0;
		playerTurn = true;
		cout << "Ok it's your turn" << endl << "your Credits: " << myCredit << endl;
		
		while (!checkBet) 
		{
			cin >> bet;
			if (bet > myCredit || bet < 0)
			{
				if (bet > 0)
					cout << "HEY Fella you don't have so much! Try again:\nbet:  ";
				else
					cout << "You can't\nbet:  ;";
			}
			if (bet <= myCredit)
				checkBet = 1;

			if (bet == 0)
			{
				playerHavedBet = 0;
				checkBet = 1;
			}
			else
				cout << "Something goes wrong O.x" << endl;
		}
		pot += bet;
		myCredit -= bet;
		bet = 0;
		playerTurn = 0;

		if (playerHavedBet) 
		{
			cout << endl << "your Credits: " << myCredit << endl << "Total on pot: " << pot << endl << "choose 1.odd or 0.pair" << endl;
			cin >> pOddPair;
		}

		cout << "Ok now is my turn" << endl;

		//AI
		if (!playerTurn)
		{
			bet = rand() % (pot + 75) + 1;
			pot += bet;
			pcCredit -= bet;
			cout << "PC bet: " << bet << endl << "Total on pot: " << pot << endl;
			bet = 0;
			AIOddPair = rand() % 1;
			cout << "PC choose " << AIOddPair;
		}

		cout << endl << "Do you want see the result or leave?(0.yes/1.leave):" << endl;
		cin >> leave;

		if (num == 0)
			num += 1;
		if (aux == 0)
			aux += 1;

		cout << endl << "Dice roll: [" << num << "] [" << aux << "]" << endl;

		aux2 = num + aux;

		if (aux2 % 2 == 0)
			oddPair = 0;
		else
			oddPair = 1;

		if (pOddPair != NULL || (oddPair == pOddPair && oddPair != AIOddPair))
		{
			myCredit += pot;
			if (pOddPair)
				cout << "BON-KO! " << aux2 << " " << name << " WON! " << pot << " credits" << endl;
			else
				cout << "BON-HA! " << aux2 << " " << name << " WON!" << pot << " credits" << endl;
		}
		else if (pOddPair == NULL || (oddPair == AIOddPair && oddPair != pOddPair))
		{
			pcCredit += pot;
			if (AIOddPair || !playerHavedBet)
				cout << "BON-KO! " << aux2 << " " << " PC WON!" << endl << " " << pot << endl;
			else
				cout << "BON-HA! " << aux2 << " " << " PC WON!" << endl << " " << pot << endl;
		}
		else if (((oddPair == pOddPair && oddPair == AIOddPair) && playerHavedBet) || ((oddPair != pOddPair && oddPair != AIOddPair) && playerHavedBet))
		{
			myCredit += (pot / 2);
			pcCredit += (pot / 2);
			if (AIOddPair && pOddPair)
				cout << "BON-KO! " << aux2 << " " << " we WON! " << pot / 2 << endl;
			else
				cout << "BON-HA! " << aux2 << " " << " we WON!" << pot / 2 << endl;
		}
		else
			cout << "Something going wrong!" << endl;

		pot = 0;
		aux2 = 0;
		num = 0;
		aux = 0;
		pOddPair = NULL;
		AIOddPair = NULL;
		checkBet = false;
		playerHavedBet = true;

		if (myCredit <= 0 || pcCredit <= 0)
		{
			if (myCredit == 0)
			{
				cout << "You lose! more luck next time!" << endl;
			}
			else if (pcCredit == 0)
			{
				cout << "You Won! less luck next time!" << endl;
			}
			else
				cout << "Come thing goes wrong!" << endl;

			leave = true;
		}
		
		if (!leave)
		{
			cout << "Do you wanna leave?(1.yes/0.not)" << endl;
			cin >> leave;
		}

	} while (!leave);
}
