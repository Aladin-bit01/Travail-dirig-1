#include <iostream>
#include <string>
#include <algorithm> //header pour pouvoir appeler la fonction sort() sur le tableau 

using namespace std;

int userPrompt();
//nombre d'éléments dans le tableau de départ 
int const NUMOFELEMETNS = 5;

int main(){
	//Tableau C++
	int numberList[5] = { 1, 3, 4, 7, 9 };
	//Valeur donnée par l'utilisateur 
	int userNum = userPrompt();
	//Nouveau tableau 
	int newNumberList[6]{};
	
	//Remplir le nouveau tableau avec les valeurs de l'ancien tableau et le userinput
	for (int i =0 ; i < NUMOFELEMETNS; i++) {
		newNumberList[i] = numberList[i];
	}
	newNumberList[NUMOFELEMETNS] = userNum;


	// Sort le nouveau tableau 	
	int size = 6;	//nombre d'éléments dans le nouveau tableau ;
	sort(newNumberList, newNumberList+size);

	//Affichage des valeurs 
	for (auto e : newNumberList) {
		cout << e << endl;
	}

}


int userPrompt() {
	string userInput;
	while (true) {
		try{
			cout << "Saisissez un entier : ";
			cin >> userInput;
			int integerNum = stoi(userInput);
			return integerNum;
		}
		catch (const std::invalid_argument& e){
			cout << "La valeur entree est non valide" << endl;
			continue;
		}	
	}
}