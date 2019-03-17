/*Program uses a vector object to store a set of real numbers. The
program outputs the smallest, largest, and average of the numbers. When declar-
ing the vector object, do not specify its size. Use the function push_back to
insert elements in the vector object.*/
//Kevin Wang
//BCS 370
//main.cpp

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void inputNumber(vector<double>& number);
void showNumber(vector<double>& number);
int main() {
	vector<double> realNumbers;
	inputNumber(realNumbers); //Get the numbers
	showNumber(realNumbers);
	system("pause");
	return 0;
}

void inputNumber(vector<double>& number) {
	double num;
	char proceed = 'Y';

	while (proceed == 'Y' || proceed =='y') {
		cout << "Enter number: ";
		cin >> num;
		number.push_back(num);
		cout << "Do you want to add more numbers? (Y/N)" << endl;
		cin >> proceed;
		cout << endl; 
	}
}

void showNumber(vector<double>& number) {
	double num = 0;
	double maxNum = number.front();
	double minNum = number.front();

	//Calculate the average of the numbers
	for (int i = 0; i < number.size(); i++) {
		num += number[i];
		if (number[i] > maxNum) {
			maxNum = number[i];
		}
		else if (number[i] < minNum) {
			minNum = number[i];
		}
	}

	double numAvg = (num / number.size());
	//Outputs the smallest, largest, and average of the numbers
	cout << "Smallest: " << minNum << endl;
	cout << "Largest: " << maxNum << endl;
	cout << "Average: " << numAvg << endl;


}


