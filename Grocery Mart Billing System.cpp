#include <iostream>
#include <string>
using namespace std;

// Global Variables
string customerName;
string customerID;
int customerType;    
int paymentMethod;  

// Global Arrays 
string groceryItems[8] = {"Rice 1 KG","Sugar 1 KG","Cooking Oil 1 Litre","Milk Pack","Tea Pack","Flour 5 KG","Eggs Dozen","detergent"};

double prices[8] = {350, 180, 580, 220, 450, 950, 320, 600};

// Cart Array to track quantities of each item ordered
int cartQuantities[8] = {0}; 

double grossBill = 0;
int currentPoints = 0;
int existingPoints = 0;
int updatedPoints = 0;

// Function to Register Customer
void registerCustomer()
{
    cout << "Enter Customer Name: ";
    cin.ignore();
    getline(cin, customerName);

    cout << "Enter Customer ID: ";
    getline(cin, customerID);

    cout << "Select Customer Type (1 for Regular, 2 for Member): ";
    cin >> customerType;

    cout << "Select Payment Method (1 for Cash, 2 for Card): ";
    cin >> paymentMethod;
}

// Function to Display Grocery List
void displayGroceryList()
{
    cout << "\n========== GROCERY LIST ==========\n";
    for(int i = 0; i < 8; i++)
    {
        cout << i + 1 << ". " << groceryItems[i] 
             << " - Rs. " << prices[i] << endl;
    }
    cout << "===================================\n";
}

// Function to Add Items to Cart
void addItemsToCart()
{
    int itemNo, quantity;
    char choice;

    do
    {
        displayGroceryList();

        cout << "\nEnter Item Number (1-8): ";
        cin >> itemNo;

        if(itemNo >= 1 && itemNo <= 8)
        {
            cout << "Enter Quantity: ";
            cin >> quantity;

            if(quantity > 0)
            {
                cartQuantities[itemNo - 1] = cartQuantities[itemNo - 1] + quantity;
                cout << "Added to cart.\n";
            }
            else
            {
                cout << "Invalid Quantity.\n";
            }
        }
        else
        {
            cout << " Invalid Item Number.\n";
        }

        cout << "Add More Items? (y/n): ";
        cin >> choice;

    } while(choice == 'y' || choice == 'Y');
}

// Function to Calculate Gross Bill
double calculateGrossBill()
{
    double total = 0;
    for(int i = 0; i < 8; i++)
    {
        total = total + (prices[i] * cartQuantities[i]);
    }
    return total;
}

// Function to Calculate Sales Tax
double calculateSalesTax()
{
    double tax = 0;
    for(int i = 0; i < 8; i++)
    {
        double itemCost = prices[i] * cartQuantities[i];
        if(i == 7)
        {
            tax = tax + (itemCost * 0.10); 
        }
        else
        {
            tax = tax + (itemCost * 0.05);
        }
    }
    return tax;
}

// Function to Calculate Membership Discount
double calculateMembershipDiscount()
{
    if(customerType == 2)
    {
        return grossBill * 0.07;
    }
    return 0;
}

// Function to Calculate Bill Amount Discount
double calculateBillDiscount(double amountAfterMembership)
{
    if(amountAfterMembership >= 5000 && amountAfterMembership <= 10000)
    {
        return amountAfterMembership * 0.05;
    }
    else if(amountAfterMembership > 10000)
    {
        return amountAfterMembership * 0.10;
    }
    return 0;
}

// Function to Calculate Card Charges
double calculateCardCharges(double currentTotal)
{
    if(paymentMethod == 2)
    {
        return currentTotal * 0.02;
    }
    return 0;
}

// Function to Calculate Loyalty Points
int calculateLoyaltyPoints(double totalBillAmount)
{
    return totalBillAmount / 100;
}

// Function to Display and Process Final Bill
void displayFinalBill()
{
    grossBill = calculateGrossBill();
    double salesTax = calculateSalesTax();
    
    double amountWithTax = grossBill + salesTax;
    double memberDisc = calculateMembershipDiscount();
    double amountAfterMember = amountWithTax - memberDisc;
    
    double billDisc = calculateBillDiscount(amountAfterMember);
    double runningTotal = amountAfterMember - billDisc;
    
    double cardCharges = calculateCardCharges(runningTotal);
    double finalAmountBeforeLoyalty = runningTotal + cardCharges;
    
    // Loyalty Points Logic
    currentPoints = calculateLoyaltyPoints(finalAmountBeforeLoyalty);

    cout << "\n========== GROCERY MART BILL ==========\n\n";

    cout << "Customer Name: " << customerName << endl;
    if(customerType == 2) cout << "Customer Type: Member\n";
    else cout << "Customer Type: Regular\n";
    
    if(paymentMethod == 2) cout << "Payment Method: Card\n\n";
    else cout << "Payment Method: Cash\n\n";

    cout << "Gross Bill: Rs. " << grossBill << endl;
    cout << "Sales Tax: Rs. " << salesTax << endl;
    cout << "Membership Discount: Rs. " << memberDisc << endl;
    cout << "Bill Discount: Rs. " << billDisc << endl;
    cout << "Card Charges: Rs. " << cardCharges << endl;
    cout << "Generated Loyalty Points: " << currentPoints << endl;

    cout << "Enter Your Existing Loyalty Points (Enter 0 if you're a new user): ";
    cin >> existingPoints;

    updatedPoints = currentPoints + existingPoints;
    cout << "Loyalty Points after Purchase: " << updatedPoints << endl;

    int redeemChoice;
    cout << "Press 1 to redeem your loyalty points, Press 2 to continue: ";
    cin >> redeemChoice;

    double totalPayable = finalAmountBeforeLoyalty;
    if(redeemChoice == 1)
    {
        totalPayable = totalPayable - updatedPoints;
        if(totalPayable < 0) totalPayable = 0; // Negative bill control
    }

    cout << "\n---------------------------------------\n";
    cout << "Total Payable Amount: Rs. " << totalPayable << endl;
    cout << "Thank You For Shopping :)\n";
    cout << "=======================================\n";
}

// Function to Display Customer Details
void displayCustomerDetails()
{
    cout << "\n===== CUSTOMER DETAILS =====\n";
    cout << "Customer ID: " << customerID << endl;
    cout << "Customer Name: " << customerName << endl;
    
    if(customerType == 2) cout << "Customer Type: Member Customer\n";
    else cout << "Customer Type: Regular Customer\n";

    if(paymentMethod == 2) cout << "Payment Method: Card\n";
    else cout << "Payment Method: Cash\n";
    cout << "============================\n";
}

// Main Function at the bottom
int main()
{
    int option;

    registerCustomer();

    do
    {
        cout << "\n===== MAIN MENU =====\n";
        cout << "1. View Grocery Items\n";
        cout << "2. Add Items to Cart\n";
        cout << "3. Calculate Bill\n";
        cout << "4. View Customer Details\n";
        cout << "5. Exit\n";

        cout << "Enter Choice: ";
        cin >> option;

        if(option == 1)
        {
            displayGroceryList();
        }
        else if(option == 2)
        {
            addItemsToCart();
        }
        else if(option == 3)
        {
            displayFinalBill();
        }
        else if(option == 4)
        {
            displayCustomerDetails();
        }
        else if(option == 5)
        {
            cout << "Program Ended\n";
        }
        else
        {
            cout << "Invalid Choice\n";
        }

    } while(option != 5);

    return 0;
}
