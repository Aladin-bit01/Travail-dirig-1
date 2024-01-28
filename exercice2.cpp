/**
* Programme qui calcule la limite de la suite récurrente U(n+1) = sqrt(2+Un) avec un terme initial U(0) = 1. Le résultat doit être affiché
* avec une précision de 5 chiffres après la virgule
* \file   exercice2.cpp
* \author Alaa Eddin et Harry
* \date   27 janvier 2024
* Créé le 20 janvier 2024
*/


#include <iostream>
#include <cmath>
#include <iomanip>

// Calcule la limite de la suite récurrente avec une précision donnée.

double calculateSequenceLimit(double precision) {
    double uCurrent = 1.0; //U0
    double uNext;

    do {
        uNext = std::sqrt(2.0 + uCurrent); //U(n+1) = sqrt(2 + Un)
        if (std::abs(uNext - uCurrent) < precision) {
            break;
        }
        uCurrent = uNext;
    } while (true);

    return uNext;
}

// Affiche la limite de la suite avec la précision de 5 chiffres après la virgule.


void afficheLimiteSuite(double precision) {
    double limit = calculateSequenceLimit(precision);
    std::cout << "La limite de la séquence est approximativement: "
        << std::fixed << std::setprecision(5) << limit << std::endl;
}
int main() {
    const double kPrecision = 0.00001; // 5 chiffres apres la virgule
    afficheLimiteSuite(kPrecision);
    return 0;
}