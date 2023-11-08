#include <iostream>
using namespace std;

int main()
{
	double monthlyPayment;
	double balance;
	double interestRate;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << "Enter the current balance of your loan: $";
	cin >> balance;
	cout << "Enter the interest rate (compounded monthly) : ";
	cin >> interestRate;
	cout << "Enter the desired monthly payment : $";
	cin >> monthlyPayment;

	while (interestRate >= 1)
	{
		interestRate = interestRate / 100;
        }

	balance = balance * (1 + interestRate / 12) - monthlyPayment;

	cout << "Your new balance is : $" << balance << endl;

        // The program stops here and doesn't complete the loop that follows.
        // This is where I'm stuck

        while (balance >0)

	{
		balance = balance * (1 + interestRate / 12) - monthlyPayment;

		cout << "Your balance is now : $" << balance << endl;
	}

	cout << "You have paid off the loan at this point. Congratulations!";
	return 0;
}
