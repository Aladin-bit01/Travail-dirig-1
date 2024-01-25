#include <iostream>
#include <cmath>
#include <iomanip>

/*
* Calcule la limite de la suite récurrente avec une précision donnée.
*/

double calculLimiteSuite(double precision) {
    double uPresent = 1.0; //U0
    double uProchain;

    do {
        uProchain = std::sqrt(2.0 + uPresent); //U(n+1) = sqrt(2 + Un)
        if (std::abs(uProchain - uPresent) < precision) {
            break;
        }
        uPresent = uProchain;
    } while (true);

    return uProchain;
}

/*
* Affiche la limite de la suite avec la précision de 5 chiffres après la virgule.
*/

void afficheLimiteSuite(double precision) {
    double limit = calculLimiteSuite(precision);
    std::cout << "La limite de la séquence est approximativement: "
        << std::fixed << std::setprecision(5) << limit << std::endl;
}
int main() {
    const double kPrecision = 0.00001; // 5 chiffres apres la virgule
    afficheLimiteSuite(kPrecision);
    return false;
}