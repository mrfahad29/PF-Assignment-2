#include <iostream>
#include <string>
using namespace std;

string customerName;
string contactNumber;
string orderType;
int persons;
double foodBill = 0;

string foodItems[8] = {
    "Chicken Burger",
    "Zinger Burger",
    "Pizza Small",
    "Pizza Large",
    "Chicken Biryani",
    "BBQ Platter",
    "Fries",
    "Cold Drink"
};

double prices[8] = {450, 550, 900, 1800, 350, 1200, 250, 120};

void registerCustomer()
{
    

    cout << "Enter Customer Name: ";
    getline(cin, customerName);

    cout << "Enter Contact Number: ";
    getline(cin, contactNumber);

    cout << "Enter Order Type (Dine-in/Takeaway): ";
    getline(cin, orderType);

    cout << "Enter Number of Persons: ";
    cin >> persons;
}

void displayMenu()
{
    cout << "\n========== FOOD MENU ==========\n";

    for(int i = 0; i < 8; i++)
    {
        cout << i + 1 << ". " << foodItems[i]
             << " - Rs. " << prices[i] << endl;
    }
}

void placeOrder()
{
    int itemNo, quantity;
    char choice;

    do
    {
        displayMenu();

        cout << "\nEnter Item Number: ";
        cin >> itemNo;

        cout << "Enter Quantity: ";
        cin >> quantity;

        foodBill = foodBill + (prices[itemNo - 1] * quantity);

        cout << "Add More Items? (y/n): ";
        cin >> choice;

    } while(choice == 'y' || choice == 'Y');
}

double calculateServiceCharges()
{
    if(orderType == "Dine-in" || orderType == "dine-in")
    {
        return foodBill * 0.10;
    }
    else
    {
        return foodBill * 0.05;
    }
}

double calculateGST()
{
    return foodBill * 0.16;
}

double calculateDiscount()
{
    if(foodBill >= 3000 && foodBill <= 5000)
    {
        return foodBill * 0.05;
    }
    else if(foodBill > 5000 && foodBill <= 10000)
    {
        return foodBill * 0.10;
    }
    else if(foodBill > 10000)
    {
        return foodBill * 0.15;
    }
    else
    {
        return 0;
    }
}

void finalBill()
{
    double service = calculateServiceCharges();
    double gst = calculateGST();
    double discount = calculateDiscount();

    double total = foodBill + service + gst - discount;

    cout << "\n========== RESTAURANT BILL ==========\n";

    cout << "Customer Name: " << customerName << endl;
    cout << "Contact Number: " << contactNumber << endl;
    cout << "Order Type: " << orderType << endl;
    cout << "Number of Persons: " << persons << endl;

    cout << "\nFood Bill: Rs. " << foodBill << endl;
    cout << "Service Charges: Rs. " << service << endl;
    cout << "GST: Rs. " << gst << endl;
    cout << "Discount: Rs. " << discount << endl;

    if(total > 5000)
    {
        cout << "Free Delivery Added\n";
    }

    cout << "------------------------------------\n";
    cout << "Total Payable Amount: Rs. " << total << endl;
    cout << "Enjoy Your Meal \n";
    cout << "====================================\n";
}

void customerDetails()
{
    cout << "\n===== CUSTOMER DETAILS =====\n";

    cout << "Customer Name: " << customerName << endl;
    cout << "Contact Number: " << contactNumber << endl;
    cout << "Order Type: " << orderType << endl;
    cout << "Number of Persons: " << persons << endl;
}

int main()
{
    int option;

    registerCustomer();

    do
    {
        cout << "\n===== MAIN MENU =====\n";
        cout << "1. View Food Menu\n";
        cout << "2. Place Order\n";
        cout << "3. Calculate Bill\n";
        cout << "4. View Customer Details\n";
        cout << "5. Exit\n";

        cout << "Enter Choice: ";
        cin >> option;

        if(option == 1)
        {
            displayMenu();
        }
        else if(option == 2)
        {
            placeOrder();
        }
        else if(option == 3)
        {
            finalBill();
        }
        else if(option == 4)
        {
            customerDetails();
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
