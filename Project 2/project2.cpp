/*

David Walker
Comp-1102 Project 1
Assigned: 	09-29-2014
Due:		10-13-2014

*/

#include <iostream.h>

float loanPrinciple;
float annualRate;
float paymentAmount;
float calculatedPrinciple;

void getLoanData( float& loanPrinciple, float& calculatedPrinciple, float& annualRate, float& paymentAmount );
void calculateLoanData(float principle, float rate, float payment, float& calculatedPrinciple);
void displayHeadings();
void displayPaymentSchedule();
void displaySummary();

int main()
{
	system("cls");
	getLoanData(loanPrinciple, calculatedPrinciple, annualRate, paymentAmount);
	
	
	cout<<loanPrinciple<<" "<<annualRate<<" "<<paymentAmount<<endl;
	
	calculateLoanData(loanPrinciple, annualRate, paymentAmount, calculatedPrinciple);
	calculateLoanData(loanPrinciple, annualRate, paymentAmount, calculatedPrinciple);
		calculateLoanData(loanPrinciple, annualRate, paymentAmount, calculatedPrinciple);
			calculateLoanData(loanPrinciple, annualRate, paymentAmount, calculatedPrinciple);
				calculateLoanData(loanPrinciple, annualRate, paymentAmount, calculatedPrinciple);
					calculateLoanData(loanPrinciple, annualRate, paymentAmount, calculatedPrinciple);
					

}

void getLoanData( float& loanPrinciple, float& calculatedPrinciple, float& annualRate, float& paymentAmount )
{
	cout<<"Enter principle amount: ";
	cin>>loanPrinciple;
	calculatedPrinciple = loanPrinciple;
	
	cout<<endl;
	
	cout<<"Enter annual interest rate: ";
	cin>>annualRate;
	cout<<endl;
	
	cout<<"Enter fixed payment amount: ";
	cin>>paymentAmount;
	cout<<endl;
}

void calculateLoanData(float principle, float rate, float payment, float& calculatedPrinciple)
{
	
	cout<<principle<<" ";
	cout<<calculatedPrinciple<<" ";
	cout<<payment<<" ";
	
	
	<<calculatedPrinciple*((rate/100)/12)<<" "<<payment - calculatedPrinciple*((rate/100)/12)<<" "<<calculatedPrinciple - (payment - calculatedPrinciple*((rate/100)/12))<<endl;


}