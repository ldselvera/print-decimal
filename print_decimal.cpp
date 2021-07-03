#include <iostream>

using namespace std;

void printDigit(char);
void printOut(int);
void printDouble(double);
void printDec(double);

int main() {

	double d;
	
	cout << "Enter a number:";
	cin >> d;
	
	printDouble(d);										
	cout << endl;
	
	system("Pause");

	return 0;
}

//Function to analyze decimal number and call proper functions to be printed.
//Postcondition: The decimal number is printed.
void printDouble(double n)
{
	if (n < 0) {										//If number less than 0, negative sign displayed
		printDigit('-');
		n = -n;
	}
	int i = floor(n);									//Keep the integer part of the number
	double d = n - i;									//Keep the decimal part of the number
	printOut(i);										//Output integer part
	printDigit('.');									//Output decimal point
	printDec(d);										//Output decimal part
}

//Function to print digit or symbol.
//Postcondition: The char is printed if it is a valid symbol or number.
void printDigit(char c ) {
	//Output char of negative sign, decimal, or number.
	if (c == '-' || c == '+' || c == '.' || c == '\n' || ('0'<=c && c <= '9')) {
		cout<< c;
		return;
	}
	else {
		cout << "Invalid characters." << endl;			//if invalid character is detected, display error
		return;
	}
}

//Function to separate and call printDigit for individual digits of the integer.
//Postcondition: Each digit of the integer printed.
void printOut(int n)
{
	if (n >= 10)										//If number is greater than 10, reduce it to its digits
		printOut(n / 10);
	printDigit(static_cast<char>(48 + (n % 10)));		//conversion from int to char

}

//Function to convert the first digit of decimal part to integer and call printDigit for that integer.
//Postcondition: Each digit of the decimal part is printed.
void printDec(double n) {
	if (n <1.0e-10)										//Limit of decimal part
		return;
	else {
		int i = static_cast<int>(n * 10);				//Convert first digit of decimal to int
		printDigit(static_cast<char>(48 + i));			//Print first digit of decimal
		n = 10 * n - i;									//New decimal part
		printDec(n);
	}
}