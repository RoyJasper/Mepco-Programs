#include  <iostream>
#include  <conio.h>
#include  <stdlib.h>
using namespace std;
class Customer {

   private:                          // data members (properties)
      char *name;
      char *address;
      char *city;
      char *pcode;
      float acc_bal;

   public:
      Customer:: Customer() {              // constructor
         name = NULL;
         address = NULL;
         city = NULL;
         pcode = NULL;
         acc_bal = 0.00;
      }

      void addcust() {                          // add customer method
         cout << "\nEnter your name: ";    cin >> name;
         cout << "\nEnter your address: ";   cin >> address;
         cout << "\nEnter your city: ";      cin >> city;
         cout << "\nEnter your postal code: ";    cin >> pcode;
         cout << "\nEnter current account balance: ";    cin >>
         acc_bal;
      }

      void deposit(float bal) {               // deposit money method
         float dep;
         cout << "\nEnter amount to be deposited: ";    cin >> dep;
         bal = bal + dep;
         acc_bal = bal;
      }


      void withdraw(float bal) {          // withdraw money method
         float wdraw;
         cout << "\nEnter amount to be withdrawn: ";    cin >>
         wdraw;
         bal = bal - wdraw;
         acc_bal = bal;
      }

      void showdata() {                   // show data method
         cout << "Name: " << name;
         cout << "\nAddress: " << address;
         cout << "\nCity: " << city;
         cout << "\nPostal Code: " << pcode;
         cout << "\nAccount Balance: $" << acc_bal << endl;
      }

};

int main() {

/*
   cout << "\t\t\n\n" << "Main Menu";
   cout << "\t\n\n" << "Select by letter:";
   cout << "\t\n" << "a - Add a customer.";
   cout << "\t\n" << "d - Deposit money.";
   cout << "\t\n" << "w - Withdraw money.";
   cout << "\t\n" << "s - Show Account Information.";
   cout << "\t\n" << "q - Quit Application.\n\n";
   cout << "\t" << "Choice: ";
*/

   Customer cust[10];         // array of 10 instances of customer
   int i;
   for (i = 0; i < 10; i++) {
      cust[i].getdata();
      cust[i].showdata();
   }
}
