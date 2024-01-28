/**
* Programme qui choisit de manière aléatoire un chiffre entre 0 et 1000 et demande à l'utilisateur de deviner 
* la valeur tout en lui indiquant si son input est plus haut ou plus bas que la valeur choisi par le programme. 
* Une fois deviné, le programme dit à l'utilisateur le nombre de tentatives qu'il avait besoin pour deviner 
* \file   exercice5.cpp
* \author Alaa Eddin et Harry
* \date   27 janvier 2024
* Créé le 20 janvier 2024
*/


#include <iostream>
#include <cstdlib>
#include <time.h> 
using namespace std;

int devinette(int, int);

int main() {
	srand(time(0));
	int nAttempts = devinette(0, 1000);
	cout << "Bravo! Vous avez reussi en " << nAttempts << " tentatives! ";
}


int devinette(int min, int max) {
	double randomValue = (rand() % (max - min + 1)) + min;
	int    answer;
	int    nAttempts = 0;
	bool   isRightAnswer = false;
	while (!isRightAnswer) {
		cout << "Entrez un nombre entier : ";
		cin >> answer;
		if (answer > max || answer < min) {
			nAttempts += 1;
		}
		else if (answer < int(randomValue)) {
			nAttempts += 1;
			cout << "Trop bas. " << endl;
		}

		else if (answer > int(randomValue)) {
			nAttempts += 1;
			cout << "Trop haut. " << endl;
		}

		else {
			nAttempts += 1;
			return nAttempts;
		}
	}
}