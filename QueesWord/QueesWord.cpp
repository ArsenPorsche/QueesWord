#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

using namespace std;

const int Size = 100;

void read(string *words) {
	string path = "list.txt";
	ifstream file;
	file.open(path);
	for (int i = 0; i < Size; i++)
	{
		file >> words[i];
	}
	file.close();
}

int StrLen(string word) {
	int i = 0;
	while (word[i] != '\0') {
		i++;
	}
	return i;
}

void AddLetter(char letter, int num, char* endword) {
	endword[num] = letter;
}

void play(int length, char letter, string &quess, char *&endword, bool& game, int& Try, int &ok, string remember){
	int right;
	bool find = false;
	for (int i = 0; i < length; i++)
	{
		if (letter == quess[i])
		{
			right = i;
			quess[i] = '0';
			find = true;
			break;
		}
	}
	if (find) {
		ok++;
		AddLetter(letter, right, endword);
		cout << "Man, you're right!"<<"\t\t\t\t";
		for (int i = 0; i < length; i++)
		{
			cout << endword[i] << " ";
		}
		cout << endl << endl;
	}
	else {
		cout << "\nOh no, this letter is not in the word)))" << "\t";
		Try--; 
		cout << "You have " << Try << " attempts" << endl;
	}
	if (ok == length) {
		cout << "\t\t\t\t\t\tYou WIN" << endl;
		game = false;
	}
	if(Try==0){
		cout << "\nThis was\t\t\t\t\t" << remember << endl;
		cout << "\n\t\t\t\t\t\tYou LOSE" << endl;
		game = false;
	}
}

int main()
{
	srand(time(NULL));
	string words[Size];
	read(words);
	bool game = true;
	int Try = 6, ok = 0;
	char letter;
	string quess = words[rand() % Size];
	string remember = quess;
	int length = StrLen(quess);
	char* endword = new char[length];
	


	for (int i = 0; i < length; i++)
	{
		endword[i] = '_';
	}
	cout << "Words have " << length << " letters";
	cout << "\t\t\t\t";
	for (int i = 0; i < length; i++)
	{
		cout << endword[i] << " ";
	}
	cout << endl << endl;
	while (game) {
		cout << "Enter the letter -> ";
		cin >> letter;
		play(length, letter, quess, endword, game, Try, ok, remember);
	}
}

