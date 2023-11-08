#include <iostream>
#include <iomanip>
#include <cmath>  // For pow function
using namespace std;

int main()
{
	double carPrice, downPayment, annual_rate, loan_amount;
	double monthly_payment1, monthly_payment2, monthly_payment3, monthly_payment4;
	double monthly_payment1A, monthly_payment2B, monthly_payment3C, monthly_payment4D;
	double monthly_rate, loanDuration;

	//rate = MONTHLY interest rate
	//N = number of payments
	//L = amount of the loan

	//ask user to enter the price of the car
	cout << "enter the price of the car: ";
	cin >> carPrice;

	//ask user to enter the downpayment amount
	cout << "enter the down payment amount: ";
	cin >> downPayment;

	//ask user to enter the annual interest rate of the loan
	cout << "enter the annual(per year) interest rate of the loan: ";
	cin >> annual_rate;

	//loanDuration = numPayments (N)
	loan_amount = carPrice - downPayment;
	monthly_rate = annual_rate/loanDuration;

	cout << "----------------------------------------------\n";
	cout << setw(5) << "Monthly Payments\n";



	monthly_payment1 = (monthly_rate * pow((1 +  monthly_rate), 24) / ((pow(1 + monthly_rate), 24) - 1)) * loan_amount;
	cout << setw(10) << "2 yrs: " <<  monthly_payment1 << endl;

	monthly_payment2 = (monthly_rate * (pow(1 +  monthly_rate), 36) / ((pow(1 +  monthly_rate), 36) - 1)) * loan_amount;
	cout << setw(10) << "3 yrs: " <<  monthly_payment2 << endl;

	monthly_payment3 = (monthly_rate * pow((1 +  monthly_rate), 48) / ((pow(1 +  monthly_rate), 48) - 1)) * loan_amount;
	cout << setw(10) << "4 yrs: " <<  monthly_payment3 << endl;

	monthly_payment4 = (monthly_rate * pow((1 +  monthly_rate), 60) / ((pow(1 +  monthly_rate), 60) - 1)) * loan_amount;
	cout << setw(10) << "5 yrs: " <<  monthly_payment4 << endl;
	cout << "----------------------------------------------\n";

	//loan's duration in months: 2-5 yrs(24 to 60 months)
	cout << "enter loan duration in months\n";
	cin >> loanDuration;
	cout << "loan's duration is: " << loanDuration << "months\n";

	//2-3 years
	if (loanDuration >= 24 && loanDuration <= 35)
		monthly_payment1A = (monthly_rate * pow((1 + monthly_rate)^ loanDuration )) / ((pow(1 + monthly_rate), loanDuration) - 1) * loan_amount;
		cout << "monthly payments for 2 years are: " << monthly_payment1A << endl;

        //3-4 years
	else if (loanDuration >=36  && loanDuration <= 47)
		monthly_payment2B = (monthly_rate * pow((1 + monthly_rate), loanDuration )) / ((pow(1 + monthly_rate), loanDuration) - 1) * loan_amount;
		cout << "monthly payments for 3 years are: " << monthly_payment2B << endl;

	//4-5 years
	else if (loanDuration >= 48  && loanDuration < 60)
		monthly_payment3C = ((monthly_rate) * (pow((1 + monthly_rate), loanDuration )) / ((pow(1 + monthly_rate), loanDuration) - 1)) * loan_amount;
		cout << "monthly payments for 4 years are: " << monthly_payment3C << endl;

	//5 years
	else if (loanDuration == 60)
		monthly_payment4D = ((monthly_rate * (pow((1 + monthly_rate), loanDuration )) / ((pow(1 + monthly_rate), loanDuration) - 1)) * loan_amount;
		cout << "monthly payments for 5 years are: " << monthly_payment4D << endl;

	else
		cout << "The bank offers car loans for periods ranging only from 2-5 years (24 to 60 months)\n";


   return 0;
}
