/**
* Programme qui charge une grille de jeu de Tic-Tac-Toe � partir d'un fichier et d�termine le r�sultat
* de la partie : si le joueur 1 (utilise "x") gagne, si le joueur 2 (utilise "o") gagne ou s'il y a
* une �galit�. Il d�termine le gagne si un joueur forme une ligne de trois cases successives par la
* longueur, hauteur ou la diagonale. ATTENTION notre programme fonctionnait de notre c�t� quand on
* mettait les fichiers des grilles dans le folder Debug. 
* \file   exercice6.cpp
* \author Alaa Eddin et Harry
* \date   27 janvier 2024
* Cr�� le 20 janvier 2024
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// Fonction pour v�rifier un gagnant ou une �galit�
std::string checkWinner(const std::vector<std::vector<char>>& grid) {
    // V�rifie les lignes, les colonnes et les diagonales pour un gagnant
    for (int i = 0; i < 3; i++) {
        if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2])
            return grid[i][0] == 'x' ? "Le joueur 1 gagne." : "Le joueur 2 gagne.";
        if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i])
            return grid[0][i] == 'x' ? "Le joueur 1 gagne." : "Le joueur 2 gagne.";
    }
    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2])
        return grid[0][0] == 'x' ? "Le joueur 1 gagne." : "Le joueur 2 gagne.";
    if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0])
        return grid[0][2] == 'x' ? "Le joueur 1 gagne." : "Le joueur 2 gagne.";

    // Si pas de gagnant, c'est �galit�
    return "Egalite";
}

int main() {
    std::string filename;
    std::cout << "Entrez le nom du fichier de la grille : ";
    std::cin >> filename;

    std::ifstream file(filename);
    std::vector<std::vector<char>> grid(3, std::vector<char>(3));

    // Lecture de la grille
    if (file.is_open()) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                file >> grid[i][j];
            }
        }
        file.close();

        // Affichage du r�sultat
        std::cout << checkWinner(grid) << std::endl;
    }
    else {
        std::cout << "Impossible d'ouvrir le fichier." << std::endl;
        return 1;
    }
    return 0;
}
