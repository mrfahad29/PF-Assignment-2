#include <iostream>
#include <string>
using namespace std;

string customerName;
string customerId;
int metersInstalled;
char customerType;
int unitConsumed;
double fixedTotal = 0;
double cost = 0;
double dutyAmount = 0;
double taxAmount =0;

double slabRate[8] = {12.21, 14.53, 31.51, 38.41, 41.62, 43.04, 44.18, 49.10};
int fixedCharges[6] = {0,200,400,600,800,1000};

//Function Customer Registration

void registerCustomer()
{
	cout<<"Enter Your Name: ";
	getline(cin,customerName);
	
	cout<<"Enter Your Customer ID: ";
	cin>>customerId;
	
	cout<<"Enter (H) for Household and (C) for Commercial Connection: ";
	cin>>customerType;
	
	cout<<"Number of Meters Already Installed: ";
	cin>>metersInstalled ;
}

//Function Main Menu

void displayMenu()
{
	cout <<"\n=========== Main Menu ===========\n"<<endl;
		cout<<"1. Press 1 for Calculate Monthly Bill: "<<endl;
		cout<<"2. Press 2 Apply for New Connection: "<<endl;
		cout<<"3. Press 3 for View Customer Detail: "<<endl;
		cout<<"4. Press 4 for Exit Program: "<<endl;	
}

//Function Customer Detail 

void customerDetail()
{
	cout<<"Customer Name: "<<customerName <<endl;
	cout<<"Customer ID: "<<customerId <<endl;
	
	if (customerType == 'H' || customerType == 'h')
	{
		cout<<"Connection Type: Household Connection" <<endl;
	}
	else 
	{
		cout<<"Connection Type: Commercial Connection"<<endl;
	}
	cout<<"Meters Installed: "<<metersInstalled <<endl;
}

//Function Total Monthly Bill

void monthlyBill()
{
    double totalBill = 0;
    
	cout<<"Enter Total Unit Consumed: ";
	cin>>unitConsumed;
	if (unitConsumed>=1 && unitConsumed<=100)
	{
		cost = slabRate[0] * unitConsumed; 
	}
	else if (unitConsumed>=101 && unitConsumed<=200)
	{
		cost = slabRate[1] * unitConsumed; 
	}
	else if (unitConsumed>=201 && unitConsumed<=300)
	{
		cost = slabRate[2] * unitConsumed; 
	}
	else if (unitConsumed>=301 && unitConsumed<=400)
	{
		cost = slabRate[3] * unitConsumed; 
	}
	else if (unitConsumed>=401 && unitConsumed<=500)
	{
		cost = slabRate[4] * unitConsumed; 
	}
	else if (unitConsumed>=501 && unitConsumed<=600)
	{
		cost = slabRate[5] * unitConsumed; 
	}
	else if (unitConsumed>=601 && unitConsumed<=700)
	{
		cost = slabRate[6] * unitConsumed; 
	}
	else 
	{
		cost = slabRate[7] * unitConsumed;
	}
	
}

//	Apply Fixed Charges

void fixedCharge()
{
   
   if (unitConsumed>=1 && unitConsumed<=300)
   {
   	  fixedTotal = 0;
   }
   else if (unitConsumed>=301 && unitConsumed<=400)
   {
   	 fixedTotal = fixedCharges[1];
   }
   else if (unitConsumed>=401 && unitConsumed<=500)
   {
   	 fixedTotal = fixedCharges[2];
   }
   else if (unitConsumed>=501 && unitConsumed<=600)
   {
   	 fixedTotal = fixedCharges[3];
   }
   else if (unitConsumed>=601 && unitConsumed<=700)
   {
   	 fixedTotal = fixedCharges[4];
   }
   else
   {
   	 fixedTotal = fixedCharges[5];
   }   	
}
	
//Function Duty Charges

void dutyCharges()
{
	dutyAmount = cost * 0.015;
}	

//Function Income Tax Calculate

void calculateIncome_Tax()
{
	if (customerType == 'H' || customerType == 'h')
	{
		taxAmount = cost * 0.10;
	}
	else
	{
		taxAmount = cost * 0.15;
	}
}

//Function Final Bill

void displayFinal_Bill()
{
	double meterRent = 250;
	double tvFee = 35;
	double subTotal;
	double gstAmount;
	double totalPayable;
	subTotal = cost + fixedTotal + dutyAmount + taxAmount + meterRent + tvFee;
	gstAmount = subTotal * 0.18;
	totalPayable = gstAmount + subTotal;
	cout<<"\n========== LESCO ELECTRICITY BILL ==========\n" <<endl;
	cout<<"Customer Name: "<<customerName <<endl;
	cout<<"Customer Id: " <<customerId <<endl;
	if (customerType == 'H' || customerType == 'h')
	{
		cout<<"Customer Type: Household Connection" <<endl;
	}
	else 
	{
		cout<<"Customer Type: Commercial Connection"<<endl;
	}
	cout<<"Unit Consumed: " <<unitConsumed <<endl <<endl;
	cout<<"Electricity Consumption Charges: Rs."<<cost <<endl;
	cout<<"Electricity Duty: Rs." <<dutyAmount<<endl;
	cout<<"Fixed Charges: Rs." <<fixedTotal <<endl;
	cout<<"Meter Rent: Rs." <<meterRent <<endl;
	cout<<"TV Fee: Rs." <<tvFee <<endl;
	cout<<"GST Charges: Rs." <<gstAmount <<endl;
	cout<<"Income Tax: Rs." <<taxAmount <<endl <<endl;
	cout<<"Total Payable Bill: Rs." <<totalPayable <<endl;
	
}

//Function New Connection

void newConnection()
{
	double meterCost = 3500;
    double cableCost = 1500;
    double securityCost = 5000;
    double additionalCharges = 0; 
    double properConnection_Cost = 0;
    double totalConnection_Charges;
    int choice;
    cout<<"Do you want a new proper connection? (Press 1 for Yes, 0 for No): ";
    cin>>choice;
    if (choice == 1)
    {
    	properConnection_Cost = 250000;
	}
	if (customerType == 'H' || customerType == 'h')
	{
		if (metersInstalled == 1 )
		{
			additionalCharges = 2500;
		}
		else 
		{
			additionalCharges = 5000;
		}
	}
	else
	{
		if (metersInstalled == 1)
		{
			additionalCharges = 35000;
		}
		else
		{
			additionalCharges = 70000;
		}
	}
	totalConnection_Charges = meterCost + cableCost + securityCost + additionalCharges + properConnection_Cost;
	cout<<"Total New Connection Charges: Rs." <<totalConnection_Charges <<endl;
}

int main()
{
	registerCustomer();
	int choice;
	do 
	{
	displayMenu();
	cout<<"Enter Your Choice: ";
    cin>>choice;
	
	if (choice == 1)
	{
    monthlyBill();          
    fixedCharge();          
    dutyCharges();          
    calculateIncome_Tax();  
    displayFinal_Bill();
    	
	}
	else if (choice == 2)
	{
		newConnection();
	}
	else if (choice == 3)
	{
		customerDetail();
	}
	else if (choice == 4)
	{
		cout<<"You Exit the Program";
	}
	else 
	{
		cout<<"You Entered Invalid Choice";
	}
}
	while(choice!=4);
	
	return 0;
}

