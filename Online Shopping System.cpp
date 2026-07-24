#include <iostream>
#include <string>
using namespace std;

// Global Variables 
string userName;
string email;
string city;
int customerType;    
int paymentMethod;   
// Global Arrays 
string products[8] = {"T-Shirt","Jeans","Shoes","Watch","Handbag","Headphones","Mobile Cover","Perfume"};

double prices[8] = {1200, 3500, 5000, 2500, 4200, 3000, 700, 2800};

// Cart Array to track quantities
int cartQuantities[8] = {0};


double productTotal = 0;

// Function to Register User
void registerUser()
{
    cout << "Enter User Name: ";
    cin.ignore();
    getline(cin, userName);

    cout << "Enter Email: ";
    getline(cin, email);

    cout << "Enter City: ";
    getline(cin, city);

    cout << "Select Customer Type (1 for New Customer, 2 for Returning Customer): ";
    cin >> customerType;
}

// Function to Display Products
void displayProducts()
{
    cout << "\n========== PRODUCT LIST ==========\n";
    for(int i = 0; i < 8; i++)
    {
        cout << i + 1 << ". " << products[i] 
             << " - Rs. " << prices[i] << endl;
    }
    cout << "===================================\n";
}

// Function to Add Products to Cart
void addProductsToCart()
{
    int productNo, quantity;
    char choice;

    do
    {
        displayProducts();

        cout << "\nEnter Product Number (1-8): ";
        cin >> productNo;

        if(productNo >= 1 && productNo <= 8)
        {
            cout << "Enter Quantity: ";
            cin >> quantity;

            if(quantity > 0)
            {
                cartQuantities[productNo - 1] = cartQuantities[productNo - 1] + quantity;
                cout << "[?] Added to cart.\n";
            }
            else
            {
                cout << "[!] Invalid Quantity.\n";
            }
        }
        else
        {
            cout << "[!] Invalid Product Number.\n";
        }

        cout << "Add More Items? (y/n): ";
        cin >> choice;

    } while(choice == 'y' || choice == 'Y');
}

//  Function to Calculate Product Total
double calculateProductTotal()
{
    double total = 0;
    for(int i = 0; i < 8; i++)
    {
        total = total + (prices[i] * cartQuantities[i]);
    }
    return total;
}

// Function to Calculate GST (17%)
double calculateGST()
{
    return productTotal * 0.17;
}

// Function to Calculate Delivery Charges
double calculateDeliveryCharges()
{
    if(city == "Lahore" || city == "lahore" || 
       city == "Karachi" || city == "karachi" || 
       city == "Islamabad" || city == "islamabad")
    {
        return 250;
    }
    else
    {
        return 500;
    }
}

// Function to Calculate Customer Discount
double calculateCustomerDiscount()
{
    if(customerType == 1)
    {
        return productTotal * 0.05;
    }
    else if(customerType == 2)
    {
        return productTotal * 0.10;
    }
    return 0;
}

// Function to Calculate Order Value Discount
double calculateOrderValueDiscount()
{
    if(productTotal >= 5000 && productTotal <= 10000)
    {
        return productTotal * 0.05;
    }
    else if(productTotal > 10000)
    {
        return productTotal * 0.12;
    }
    return 0;
}

// Function to Calculate Payment Charges (Card = 2.5%)
double calculatePaymentCharges(double currentTotal)
{
    if(paymentMethod == 2)
    {
        return currentTotal * 0.025;
    }
    return 0;
}

// Function to Display Checkout Bill
void displayCheckoutBill()
{
    productTotal = calculateProductTotal();
    double gst = calculateGST();
    double delivery = calculateDeliveryCharges();
    double customerDisc = calculateCustomerDiscount();
    double orderDisc = calculateOrderValueDiscount();
    
    // Total calculation before card processing fee
    double intermediateTotal = productTotal + gst + delivery - customerDisc - orderDisc;
    
    // Ask payment method during checkout
    cout << "\nSelect Payment Method:\n";
    cout << "1. Cash on Delivery (COD)\n";
    cout << "2. Debit/Credit Card\n";
    cout << "Enter Choice: ";
    cin >> paymentMethod;
    
    double paymentCharges = calculatePaymentCharges(intermediateTotal);
    double finalPayable = intermediateTotal + paymentCharges;

    cout << "\n========== ONLINE SHOPPING BILL ==========\n\n";

    cout << "User Name: " << userName << endl;
    cout << "City: " << city << endl;
    if(customerType == 1) cout << "Customer Type: New Customer\n";
    else cout << "Customer Type: Returning Customer\n";

    cout << "\nProduct Total: Rs. " << productTotal << endl;
    cout << "GST: Rs. " << gst << endl;
    cout << "Delivery Charges: Rs. " << delivery << endl;
    cout << "Customer Discount: Rs. " << customerDisc << endl;
    cout << "Order Discount: Rs. " << orderDisc << endl;
    cout << "Payment Charges: Rs. " << paymentCharges << endl;

    cout << "------------------------------------------\n";
    cout << "Final Payable Amount: Rs. " << finalPayable << endl;
    cout << "Thank You for Shopping :)\n";
    cout << "==========================================\n";
}

// Function to view user profile details
void viewUserDetails()
{
    cout << "\n===== USER DETAILS =====\n";
    cout << "User Name: " << userName << endl;
    cout << "Email: " << email << endl;
    cout << "City: " << city << endl;
    if(customerType == 1) cout << "Customer Type: New Customer\n";
    else cout << "Customer Type: Returning Customer\n";
    cout << "========================\n";
}

// Main Function
int main()
{
    int option;

    registerUser();

    do
    {
        cout << "\n===== MAIN MENU =====\n";
        cout << "1. View Products\n";
        cout << "2. Add Product to Cart\n";
        cout << "3. Calculate Checkout Bill\n";
        cout << "4. View User Details\n";
        cout << "5. Exit\n";

        cout << "Enter Choice: ";
        cin >> option;

        if(option == 1)
        {
            displayProducts();
        }
        else if(option == 2)
        {
            addProductsToCart();
        }
        else if(option == 3)
        {
            displayCheckoutBill();
        }
        else if(option == 4)
        {
            viewUserDetails();
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
