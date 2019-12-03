// Author: William Everett McLean
// Intent: Given the Starting Deposit, Yearly Interest Rate, and Monthly Deposit amount for 
// a saving account, calculate the ending balance, total interest earned, and total amount
// of money deposited by a user.

#include <iostream>
using namespace std;

float CalcIntMonth(float &balance, float monthDeposit, float Rate){ //Function to calculate earned interest, and update balance
float EarnedInt=0; //initializing variable for Total Interest Earned
float monthRate = Rate / 12.0; //convert yearly interest rate to monthly interest rate

EarnedInt = balance * monthRate; //Calculating interest earned in first month
balance = balance + (balance * monthRate); //Updating balance with interest earned in first month

for (unsigned int i=1;i<12;i++){ //Loop will run 11 times, one for each month of the year after the first.
//Loop will calculate the new balance after the user's monthly deposit, increase the amount of
//Total Interest Earned by calculating Interest Earned for the month using the new balance, 
//and update the balance by adding interest earned for the month
balance = balance + monthDeposit;
EarnedInt = EarnedInt + (balance * monthRate);
balance = balance + (balance * monthRate);
}
return EarnedInt; //Returning the Total Interest Earned for the month.
}

int main(){
	
	float fDeposit; //Variable for initial deposit by customer
	float balance; //Variable for balance of the account, will be passed by reference to function
	float monthDeposit; //Variable for deposit customer will make each month
	float rate; //Variable for yarly interest rate converted to a decimal
	float rawRate; //Variable for interest rate given by customer as a percent
	float interestGain; //Variable for total amount of interest gained over the year
	
	cout << "Please enter the amount of the initial deposit. Do not use commas. Ex: $1,000 should be entered as '1000'." << endl;
	cin >> fDeposit;
	cout << "How much will you deposit per month?" << endl;
	cin >> monthDeposit;
	cout << "What is the yearly interest rate on the account?" << endl;
	cout << "%";
	cin >> rawRate;
	
	rate = rawRate/100; //converting interest rate from percent to decimal
	balance=fDeposit; //setting starting balance to equal the amount of the first deposit
	interestGain=CalcIntMonth(balance, monthDeposit, rate); //Invoking function to update balance and calculate interest earned

	//Displaying ending balance, total deposits, and total interests all set at 2 decimal places.
	cout << "The balance in the account after one year is $";
	printf("%.2f", balance);
	cout << endl;
	
	cout << "The amount of money you deposited into the account is $";
	printf("%.2f", (fDeposit+(monthDeposit*11)));
	cout << endl;
	
	cout << "The total amount of interest gained is $";
	printf("%.2f", interestGain);
	

return 0;
}

