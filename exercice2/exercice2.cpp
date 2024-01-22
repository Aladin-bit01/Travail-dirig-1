#include <iostream>
#include <cmath>
#include <iomanip>

double calculate_sequence_limit(double precision) {
    double U_n = 1;
    double U_next;
    do {
        U_next = std::sqrt(2 + U_n);
        if (std::abs(U_next - U_n) < precision) {
            break;
        }
        U_n = U_next;
    } while (true);

    return U_next;
}
int main()
{
    double precision = 0.00001;
    double limit = calculate_sequence_limit(precision);
    std::cout << "La limite de la séquence est approximativement: " << std::setprecision(10)
            << limit << std::endl;
    return false;
}