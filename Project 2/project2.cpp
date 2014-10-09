/*

David Walker
Comp-1102 Project 1
Assigned: 	09-29-2014
Due:		10-13-2014

*/

#include <iostream.h>
#include <iomanip.h>

void getLoanData( float& loanPrinciple, float& annualRate, float& paymentAmount, float& calculatedPrinciple );
void calculateLoanData(float annualrate, float paymentAmount, float& calculatedPrinciple, int& paymentNumber, float& totalInterest);
void displayHeading();
void displayPaymentSchedule(float annualrate, float paymentAmount, float& calculatedPrinciple, int& paymentNumber, float& totalInterest);
void displaySummary(int totalPayments, float loanPrinciple, float annualRate, float totalInterest);

int main()
{
	float loanPrinciple;
	float annualRate;
	float paymentAmount;
	float calculatedPrinciple;
	
	int paymentNumber = 0;
	float totalInterest = 0.00;
	
	cout.setf(cout.fixed);
	cout.precision(2);

	system("cls");
	
	getLoanData(loanPrinciple, annualRate, paymentAmount, calculatedPrinciple);
	
	displayPaymentSchedule(annualRate, paymentAmount, calculatedPrinciple, paymentNumber, totalInterest);
	
	displaySummary(paymentNumber, loanPrinciple, annualRate, totalInterest);
}

void getLoanData( float& loanPrinciple, float& annualRate, float& paymentAmount, float& calculatedPrinciple)
{
	loanPrinciple = 0.00;
	annualRate = 0.00;
	paymentAmount = 0.00;
	
	while(loanPrinciple <= 0.00)
	{
		cout<<"Enter principle amount: ";
		cin>>loanPrinciple;	
		calculatedPrinciple = loanPrinciple;
		cout<<endl;
	}
	
	while(annualRate <= 0.00)
	{
		cout<<"Enter annual interest rate: ";
		cin>>annualRate;
		cout<<endl;
	}
	
	while(paymentAmount <= (loanPrinciple*((annualRate/100)/12)))
	{
		cout<<"Enter fixed payment amount: ";
		cin>>paymentAmount;
		cout<<endl;
	}
	
}

void calculateLoanData(float rate, float payment, float& calculatedPrinciple, int& paymentNumber, float& totalInterest)
{
	//the calculations assume an APR not an APY
	
	paymentNumber++;																		//increment payment number
	cout<<"|"<<setw(9)<<paymentNumber<<" ";													//display payment number
	cout<<"|"<<setw(12)<<calculatedPrinciple<<" ";											//display principle balance before making payment

	if(calculatedPrinciple + (calculatedPrinciple*((rate/100)/12)) > payment)				//checking if payment is more than calculatedPrinciple plus interest due
		payment = payment;																	//set payment amount equal to input parameter
	else
		payment = calculatedPrinciple + (calculatedPrinciple*((rate/100)/12));				//set payment amount equal to calculatedPrinciple plus interest due
	
	cout<<"|"<<setw(10)<<payment<<" ";														//display amount of payment
	cout<<"|"<<setw(11)<<calculatedPrinciple*((rate/100)/12)<<" ";							//display amount of payment applied to interest
	cout<<"|"<<setw(12)<<payment - calculatedPrinciple*((rate/100)/12)<<" ";				//display amount of payment applied to principle
	
	totalInterest = totalInterest + (calculatedPrinciple*((rate/100)/12));					//adding to total interest for summary
	
	calculatedPrinciple = calculatedPrinciple - (payment - calculatedPrinciple*((rate/100)/12));	//calculate new principle
	
	cout<<"|"<<setw(12)<<calculatedPrinciple<<" |"<<endl;									//display new principle
}

void displayHeading()
{
	cout<<"|-----------------------------------------------------------------------------|"<<endl;
	cout<<"| payment  |  principle  |  payment  |  interest  |  principle  |     new     |"<<endl;
	cout<<"|    #     |   amount    |  amount   |    paid    |  reduction  |  principle  |"<<endl;
	cout<<"|-----------------------------------------------------------------------------|"<<endl;
}

void displayPaymentSchedule(float annualRate, float paymentAmount, float& calculatedPrinciple, int& paymentNumber, float& totalInterest)
{	
	cout<<" -----------------------------------------------------------------------------"<<endl;
	cout<<"|                             Payment Schedule                                |"<<endl;
	displayHeading();	
	
	while(calculatedPrinciple > 0.01)
	{
		if(paymentNumber!= 0 && paymentNumber%10 == 0){
		system("pause");
			displayHeading();}
			
		calculateLoanData(annualRate, paymentAmount, calculatedPrinciple, paymentNumber, totalInterest);
	}
	cout<<"|                                                                             |"<<endl;
}

void displaySummary(int totalPayments, float loanPrinciple, float annualRate, float totalInterest)
{
	
	cout<<"|-----------------------------------------------------------------------------|"<<endl;
	cout<<"|                             Schedule Summary                                |"<<endl;
	cout<<"|-----------------------------------------------------------------------------|"<<endl;
	cout<<"|  total payments  |  original principle  |  interest rate  |  interest paid  |"<<endl;
	cout<<"|-----------------------------------------------------------------------------|"<<endl;
	cout<<"|"<<setw(17)<<totalPayments<<" ";
	cout<<"|"<<setw(21)<<loanPrinciple<<" ";
	cout<<"|"<<setw(16)<<annualRate<<" ";
	cout<<"|"<<setw(16)<<totalInterest<<" |"<<endl;
	cout<<" -----------------------------------------------------------------------------"<<endl;
}