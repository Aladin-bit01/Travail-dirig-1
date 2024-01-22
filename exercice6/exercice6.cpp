#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std; 

//Fonction pour checker un gagnant ou une égalité
string check_winner(const vector<string>& grid) {
	//Regarde les lignes et les colones
	for (int i = 0; i < 3; i++) {
		if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2])
			return grid[i][0] == 'x' ? "Le joueur 1 gagne." : "Le joueur 2 gagne.";
		if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i])
			return grid[0][i] == 'x' ? "Le joueur 1 gagne." : "Le joueur 2 gagne.";
	}

	//Regarde les diagonales
	if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] ||
		grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0])
		return grid[0][0] == 'x' ? "Le joueur 1 gagne." : "Le joueur 2 gagne.";

	//Regarde si les cases sont remplies
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (grid[i][j] != 'x' && grid[i][j] != 'o')
				return "Pas encore fini.";

	//Si pas de gagnant et espaces remplies, cest egal
	return "Egalite"; 
}

int main() {
	string filename;
	cout << "Entrez le nom du fichier de la grille : ";
	cin >> filename;

	ifstream file(filename);
	vector<string> grid(3);
	string line;

	//Lecture de la grille
	if (file.is_open()) {
		for (int i = 0; i < 3 && getline(file, line); ++i) {
			if (line.size() >= 3) {
				grid[i] = line.substr(0, 3);
			}
		}
		file.close();

		cout << check_winner(grid) << endl;
	}else {
		cout << "Impossible d'ouvrir le fichier." << endl;
	}
	return 0;
}