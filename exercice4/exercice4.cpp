#include <iostream>

int russianMultiplication(int a, int b);

struct Test {
	int x, y, result;
};

int main() {

	Test mesTests[] = {
		{37, 129, 37 * 129},
		{78, 139, 78 * 139},
		{55, 219, 55 * 219}
	};

	int passedTests = 0;
	for (const auto& unitTest : mesTests) {
		if (unitTest.result == russianMultiplication(unitTest.x, unitTest.y)) {
			passedTests++;
		}
	}
	std::cout << passedTests << "/3 tests passent." << std::endl;
	return false;
}
/*
* Implémente la multiplication russe.
* @param num1 Le premier entier à multiplier.
* @param num2 Le deuxième entier à multiplier.
* @return Le produit des deux entiers.
*/

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