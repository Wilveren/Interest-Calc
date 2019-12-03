#include <iostream>
using namespace std;

float CalcIntMonth(float &balance, float monthDeposit, float Rate){
float EarnedInt=0;
float monthRate = Rate / 12.0;

EarnedInt = balance * monthRate;
balance = balance + (balance * monthRate);

for (unsigned int i=1;i<12;i++){
balance = balance + monthDeposit;
EarnedInt = EarnedInt + (balance * monthRate);
balance = balance + (balance * monthRate);
}
return EarnedInt;
}

int main(){
	
	float fDeposit;
	float balance;
	float monthDeposit;
	float rate;
	float rawRate;
	float interestGain;
	
	cout << "Please enter the amount of the initial deposit. Do not use commas. Ex: $1,000 should be entered as '1000'." << endl;
	cin >> fDeposit;
	cout << "How much will you deposit per month?" << endl;
	cin >> monthDeposit;
	cout << "What is the yearly interest rate on the account?" << endl;
	cout << "%";
	cin >> rawRate;
	
	rate = rawRate/100;
	balance=fDeposit;
	interestGain=CalcIntMonth(balance, monthDeposit, rate);

	
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

