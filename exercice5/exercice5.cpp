#include <iostream>
#include <cstdlib>
#include <time.h> 
using namespace std;


int devinette(int, int);

int main()
{
	srand(time(0));
	int nombreEssaies = devinette(0, 1000);
	cout << "Bravo! Vous avez reussi en " << nombreEssaies << " tentatives! ";
}


int devinette(int min, int max) {
	double valeurAleatoire = (rand() % (max - min + 1)) + min;
	int answer;
	int tentative = 0;
	bool answered = false;
	while (!answered) {
		cout << "Entrez un nombre entier : ";
		cin >> answer;
		if (answer > max || answer < min) {
			tentative += 1;
		}
		else if (answer < int(valeurAleatoire)) {
			tentative += 1;
			cout << "Trop bas. " << endl;
		}

		else if (answer > int(valeurAleatoire)) {
			tentative += 1;
			cout << "Trop haut. " << endl;
		}

		else {
			tentative += 1;
			return tentative;
		}



	}
}