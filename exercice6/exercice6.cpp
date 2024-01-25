#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// Fonction pour vérifier un gagnant ou une égalité
std::string checkWinner(const std::vector<std::vector<char>>& grid) {
    // Vérifie les lignes, les colonnes et les diagonales pour un gagnant
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

    // Si pas de gagnant, c'est égalité
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

        // Affichage du résultat
        std::cout << checkWinner(grid) << std::endl;
    }
    else {
        std::cout << "Impossible d'ouvrir le fichier." << std::endl;
        return 1;
    }
    return 0;
}
