#include <iostream>
using namespace std;

int russianMultiplication(int, int);

struct Test {
	int x, y, result;
};

int main(){
	Test test1{37, 129, (37 * 129)};
	Test test2{78, 139, (78 * 139)};
	Test test3{55, 219, (55 * 219)};

	Test mesTests[3] = { test1, test2, test3 };

	int passedTests = 0;
	for (auto unitTest : mesTests) {
		if (unitTest.result == russianMultiplication(unitTest.x, unitTest.y)) {
			passedTests += 1;
		}
	}
	cout << passedTests << "/3 tests passent.";
}

int russianMultiplication(int num1, int num2) {
	int produit = 0;
	if (num1 % 2 != 0)
		produit += num2;
	while (num1 != 1) {
		num1 = num1 / 2;
		num2 = num2 * 2;
		if (num1 % 2 != 0) {
			produit += num2;
		}
	}
	return produit;
}
