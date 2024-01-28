/**
* Programme qui implémente la méthode de multiplicaton russe pour multiplier deux entiers en utilisant uniquement des divisions
* et des multiplications par 2. Il calcule le produit de ces deux entiers et vérifie la validité de la méthode à travers une série
* de tests prédéfinis
* \file   exercice4.cpp
* \author Alaa Eddin et Harry
* \date   27 janvier 2024
* Créé le 20 janvier 2024
*/


#include <iostream>

int russianMultiplication(int a, int b);

struct Test {
	int x, y, result;
};

int main() {

	Test myTests[] = {
		{37, 129, 37 * 129},
		{78, 139, 78 * 139},
		{55, 219, 55 * 219}
	};

	int passedTests = 0;
	for (const auto& unitTest : myTests) {
		if (unitTest.result == russianMultiplication(unitTest.x, unitTest.y)) {
			passedTests++;
		}
	}
	std::cout << passedTests << "/3 tests passent." << std::endl;
	return false;
}

int russianMultiplication(int num1, int num2) {
	int product = 0;

	while (num1 > 0) {
		if (num1 % 2 != 0) {
			product += num2;
		}
		num1 /= 2;
		num2 *= 2;
	}
	return product;
}