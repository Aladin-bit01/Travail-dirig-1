#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std; 

//Fonction pour checker un gagnant ou une égalité
string check_winner(const vector<string>& grid) {
	// Vérifie les lignes et les colonnes
	for (int i = 0; i < 3; i++) {
		if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] && grid[i][0] != ' ')
			return grid[i][0] == 'x' ? "Le joueur 1 gagne." : "Le joueur 2 gagne.";
		if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i] && grid[0][i] != ' ')
			return grid[0][i] == 'x' ? "Le joueur 1 gagne." : "Le joueur 2 gagne.";
	}

	// Vérifie les diagonales
    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[1][1] != ' ')
        return grid[1][1] == 'x' ? "Le joueur 1 gagne." : "Le joueur 2 gagne.";
    if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[1][1] != ' ')
        return grid[1][1] == 'x' ? "Le joueur 1 gagne." : "Le joueur 2 gagne.";

	// Si pas de gagnant et toutes les cases sont remplies, c'est égalité
	return "Egalite";
}


int main() {
    string filename;
    cout << "Entrez le nom du fichier de la grille : ";
    cin >> filename;

    ifstream file(filename);
    vector<string> grid(3);
    string line;

    // Lecture de la grille
    if (file.is_open()) {
        for (int i = 0; i < 3; ++i) {
            if (!getline(file, line)) {
                cout << "Erreur de lecture de la grille." << endl;
                return 1; // Sortie du programme si la grille n'est pas complète
            }
            for (char c : line) {
                if (c == 'x' || c == 'o') {
                    grid[i] += c;
                }
            }
            if (grid[i].length() != 3) {
                cout << "Erreur de format de la grille." << endl;
                return 1; // Sortie du programme si la grille n'a pas exactement 3 caractères par ligne
            }
        }
        file.close();

        cout << check_winner(grid) << endl;
    }
    else {
        cout << "Impossible d'ouvrir le fichier." << endl;
    }
    return 0;
}
