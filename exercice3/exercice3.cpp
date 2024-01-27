/**
* Programme qui demande un chiffre à l'utilisateur et l'ajoute à un tableau de 5 chiffres ordonnées de manière croissante
* tout en s'assurant de conserver l'ordre croissant des valeurs après avoir ajouté l'entrée de l'utilisateur
* \file   exercice3.cpp
* \author Alaa Eddin et Harry
* \date   27 janvier 2024
* Créé le 20 janvier 2024
*/


#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;


int userPrompt();
int const numOfElementsInitialList = 5;
int const numOfElementsNewList = 6;

int main(){

	int listOfNumbers[5] = {1, 3, 4, 7, 9};
	int userNumber = userPrompt();
	int newListOfNumbers[6] = {};
	
	for (int i =0 ; i < numOfElementsInitialList; i++) {
		newListOfNumbers[i] = listOfNumbers[i];
	}
	newListOfNumbers[numOfElementsInitialList] = userNumber;

	sort(newListOfNumbers, newListOfNumbers + numOfElementsNewList);

	for (auto element : newListOfNumbers) {
		cout << element << endl;
	}
}


int userPrompt() {
	string userInput;
	bool   isActive = true;
	while (isActive) {
		try {
			cout << "Saisissez un entier : ";
			cin >> userInput;
			int integerNumber = stoi(userInput);
			return integerNumber;
		}
		catch (const invalid_argument& e) {
			cout << "La valeur entree est non valide" << endl;
			continue;
		}	
	}
}