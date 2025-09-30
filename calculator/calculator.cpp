#include <iostream>
using namespace std;
float aggregaitonOperator(float number1, float number2);
float subtractionOperator(float number1, float number2);
float multiplicationOperator(float number1, float number2);
float divisionOperator(float number1, float number2);

int main()
{
	float number1, number2;
	char operation;
	cout << "Enter first number: ";
	cin >> number1;
	cout << "Enter second number: ";
	cin >> number2;
	cout << "Enter operation (+, -, *, /): ";
	cin >> operation;
	switch (operation)
	{
	case '+':
		cout << "Result: " << aggregaitonOperator(number1, number2) << endl;
		break;
	case '-':
		cout << "Result: " << subtractionOperator(number1, number2) << endl;
		break;
	case '*':
		cout << "Result: " << multiplicationOperator(number1, number2) << endl;
		break;
	case '/':
		if (number2 != 0)
			cout << "Result: " << divisionOperator(number1, number2) << endl;
		else
			cout << "Error: Division by zero!" << endl;
		break;
	default:
		cout << "Error: Invalid operation!" << endl;
		break;
	}
	return 0;
}

float aggregaitonOperator(float number1, float number2)
{	
	return number1 + number2;
}

float subtractionOperator(float number1, float number2)
{
	return number1 - number2;
}

float multiplicationOperator(float number1, float number2)
{
	return number1 * number2;	
}

float divisionOperator(float number1, float number2)
{
	return number1 / number2;
}
