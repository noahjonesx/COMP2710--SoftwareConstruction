 
//noah jones 
//nhj0004
//hw1.cpp
//Compiled using G++ from MinGW on Windows 11
//Compile by typing 'g++ hw1.cpp -o "hw1"' and then './hw1/' in powershell current directory
//References:
//https://stackoverflow.com/questions/17928865/correct-way-to-use-cin-fail
//https://stackoverflow.com/questions/257091/how-do-i-flush-the-cin-buffer
//https://www.cplusplus.com/doc/tutorial/operators/

#include <iostream>
 //allows 'numeric_limits' in clearCin function
 #include <limits>
 using namespace std;

 //clear cin method - call to execute
 //clears error flag after invalid user input 
void clearCin() {
  cin.clear();
  //sets streamsize to clear MAX amount of invalid input characters
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
  //set variables to be used 
  double loan;
  double interestRate;
  double interestRateC;
  double interestTotal;
  double monthlyPayment;
  double principle;
  // current month must start at zero 
  int currentMonth = 0;

  //format currency 
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  //max amount (2) digits to be written after decimal
  cout.precision(2);

  //prompt for user input for amount of loan 
  //ensures that the program will not continue until..
  //..a POSITIVE INTEGER is entered

  cout << "\nLoan Amount: ";
  //prompt user to input loan amount 
  cin >> loan;
  //enter while loop upon invalid input to get an acceptable value 
    while (cin.fail() || (loan < 0)) {
      cout << "ERROR: Please enter a postive integer!" <<endl;
      cout << "Loan amount must be a positive number";
      clearCin(); //calls clearCin method
      //remprompt for user input
      cin >> loan;
    }

    //prompt user to enter Interest Rate - (percent per year)
  cout << "Interest Rate (% per year): ";
  cin >> interestRate;
  //enter while loop upon invalid input to get an acceptable value 
    while (cin.fail() || (interestRate < 0)) {
      cout << "ERROR: Please enter a postive integer!" <<endl;
      cout << "Interest Rate must be a postive percentage!";
      clearCin(); //calls clearCin method 
      //reprompt for user input
      cin >> loan;
    } 
    //convert interest rates for proper calculations
    //interest is entered yearly, but must be calculated monthly
    //divide by 12 months for monthly interest
    interestRate /= 12;
    //convert value for percentage (stored in interestRateC)
    interestRateC = interestRate / 100;

    //prompt user for amount paid per month
    cout << "Monthly Payment Amount: ";
    cin >> monthlyPayment;
    //enter while loop upon invalid user input 
      while (cin.fail() || (monthlyPayment < 0)) {
        cout << "ERROR: Please enter a postive integer!";
        cout << "Monthly Payment must be a positive number" <<endl;
          clearCin(); //call clearCin method 
        cin >> monthlyPayment;
      }
      //space
      cout << endl;
       // AMORTIZATION TABLE 
 cout << "*****************************************************************\n" 
      << "\tAmortization Table\n" 
      << "*****************************************************************\n" 
      << "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n"; 

//loop to fill table

while (loan > 0) {
//payment (permonth) calculated as (remaining loan * interest rate)
//set this calculation to 'payment'
double payment = loan * interestRateC;
//table starts when current month = 0
  if (currentMonth == 0){
    //print month tab (first column)
    //increment month each interation, tab over 
    cout << currentMonth++ << "\t$" << loan;
    //when loan reaches less than 1000, tab over
    //fixes spacing error due to decrease in digits of payment
    if (loan < 1000) cout << "\t$";
    cout << "\t" << "N/A\tN/A\tN/A\t\tN/A\\n";
}
else {

  interestTotal += payment;
  //continue if monthly payment is greater than monthly loan payment
  if (loan * (1 + interestRateC) < monthlyPayment) {
   //monthlyPayment = (payment + loan)
    monthlyPayment = loan + payment;
   //princple = (montly payment - payment)
    principle = monthlyPayment - payment;
    
    //finally, set loan to loan - principle for current balance
    loan -= principle;
  }
  //if monthly payment is less than monthly loan payment
  else if (loan * (1 + interestRateC) >= monthlyPayment) {
    principle = monthlyPayment - payment;
    loan -= principle;
  }
  //print current month incrementing up, starting from zero
  //tab over and print current loan amount 
  cout << currentMonth++ << "\t$" << loan;
  //when loan is less than 1000, tab over
  //fixes spacing error due to decrease in amount of digits
  if (loan < 1000) cout << "\t";
  //print remaining columns, with tab in between all
    cout << "\t$" << monthlyPayment << "\t$" << interestRate << "\t$" << payment << "\t\t" << principle << "\n";
  }
}
cout << "****************************************************************\n"; 
 cout << "\nIt takes " << --currentMonth << " months to pay off " 
      << "the loan.\n" 
      << "Total interest paid is: $" << interestTotal; 
 cout << endl << endl;  
 return 0; 
}