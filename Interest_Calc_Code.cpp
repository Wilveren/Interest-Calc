// Author: William Everett McLean
// Intent: Given the Starting Deposit, Yearly Interest Rate, and Monthly Deposit amount for 
// a saving account, calculate the ending balance, total interest earned, and total amount
// of money deposited by a user.

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

float CalcIntMonth(float &balance, float monthDeposit, float yearRate){ //Function to calculate earned interest, and update balance. For simplicity, balance is passed by reference
float EarnedInt = 0; //initializing variable for Total Interest Earned
float monthRate = yearRate / 12.0; //convert yearly interest rate to monthly interest rate and store in new variable

EarnedInt = balance * monthRate; //Calculating interest earned in first month
balance = balance + (balance * monthRate); //Updating balance with interest earned in first month

for (unsigned int i=1; i<12; i++){ //Loop will run 11 times, one for each month of the year after the first.
//Loop will calculate the new balance after the user's monthly deposit, increase the amount of
//Total Interest Earned by calculating Interest Earned for the month using the new balance, 
//and update the balance by adding interest earned for the month
balance = balance + monthDeposit;
EarnedInt = EarnedInt + (balance * monthRate);
balance = balance + (balance * monthRate);
}
return EarnedInt; //Returning the Total Interest Earned for the month.
}

string RemoveGarbage (string userString){ // Function for removing commas and spaces from user input

   
    for (unsigned int i=0;i<userString.size();++i){ //For loop will look at each individual character in the string and remove spaces
      if (userString.at(i)==' '){
         userString.erase(i,1);
         i=i-1; //since a character is erased, the placement of characters after it shift down one, so i must also shift down 1
      }
    }
	
	for (unsigned int i=0;i<userString.size();++i){ //For loop will look at each individual character in the string and remove commas
      if (userString.at(i)==','){
         userString.erase(i,1);
         i=i-1; //since a character is erased, the placement of characters after it shift down one, so i must also shift down 1
      }
    }
	
    return userString;
}

void FormatCurrency(string &output){ //Function for placing a comma where necessary, when the value is 1,000 or greater. Passed by reference for simplicity
	int decimal = output.find('.'); //Variable is set to the place in the string that a decimal appears
	
	if (decimal > 3){ //If there are more than three characters before the decimal, than the amoubt is over one thousand, and a comma is needed
		for (int i = (decimal - 3); i > 0; i -= 3){ //Loop will execute for as long as there are at least three spaces to the left of the last comma placed, and place another one. 
			output.insert(i, ",");
		}
	}
return;	
}

string Rounding(string output){ //Function for formatting output to have two decimal places
	int decimal = output.find('.'); //Variable to hold where the decimal appears
	int x = decimal+3; //Variable for identifying the character that should be deleted, as it is 3 spaces past the decimal
	while (decimal+3<output.size()) //While loop checks whether there are more than 2 characters after the decimal. If there are, they are deleted until there are only two.
	{
		output.erase(x);
	}
	return output;
}


int main(){
	
	
	float fDeposit; //Variable for initial deposit by customer
	float balance; //Variable for balance of the account, will be passed by reference to function for calculation of growth
	float monthDeposit; //Variable for deposit customer will make each month
	float rate; //Variable for yearly interest rate, will be converted to a decimal
	float interestGain; //Variable for total amount of interest gained over the year
	string input; //Variable for user input. Will be processed to remove commas and extra spaces, then fed to fDeposit and monthDeposit
	string output; //Variable for output. Float will be converted to String to allow for formatting as currency.
	
	//Ask user for input, then remove any commas or spaces from it using function RemoveGarbage
	cout << "Please enter the amount of the initial deposit." << endl << "$"; 
	getline (cin, input); 
	fDeposit = std::stof(RemoveGarbage(input));
	
	//Ask user for input, then remove any commas or spaces from it using function RemoveGarbage
	cout << "How much will you deposit per month?" << endl << "&";
	getline (cin, input);
	monthDeposit = std::stof(RemoveGarbage(input));
	
	//Ask user for input, then remove any commas or spaces from it using function RemoveGarbage
	cout << "What is the yearly interest rate on the account?" << endl;
	cout << "%";
	cin >> rate;
	
	rate = rate/100; //converting interest rate from percent to decimal
	balance=fDeposit; //setting starting balance to equal the amount of the first deposit
	interestGain=CalcIntMonth(balance, monthDeposit, rate); //Invoking function to update balance and calculate interest earned
	
	//convert balance to String to allow formatting as currency using function FormatCurrency
	output=to_string (balance); 
	FormatCurrency(output);
	
	//Displaying ending balance, using function Rounding to set to 2 decimal places.
	cout << "The balance in the account after one year is $";
	cout << Rounding(output);
	cout << endl;
	
	
	//convert total amount of money deposited by user to String to allow formatting as currency using function FormatCurrency
	output= to_string(fDeposit+(monthDeposit*11));
	FormatCurrency(output);
	
	//Displaying total money deposited by user, using function Rounding to set to 2 decimal places.
	cout << "The amount of money you deposited into the account is $";
	cout << Rounding(output);
	cout << endl;
	
	//convert total amount of interest earned to String to allow formatting as currency using function FormatCurrency
	output = to_string(interestGain);
	FormatCurrency(output);
	
	//Displaying total interest earned, using function Rounding to set to 2 decimal places.
	cout << "The total amount of interest gained is $";
	cout << Rounding(output);

return 0;
}

