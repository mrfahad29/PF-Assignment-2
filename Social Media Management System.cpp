#include <iostream>
#include <string>
using namespace std;

// Global Variables 
string clientName;
string businessName;
int businessType;         
int campaignDuration;    
int selectedPlatformNo = 0; 
int staticPosts = 0;
int reelPosts = 0;
int carouselPosts = 0;
double adBudget = 0;

// Global Arrays 
string platforms[3] = {"Instagram", "Facebook", "LinkedIn"};
double baseCharges[3] = {15000, 12000, 20000};


// Function to Register Client
void registerClient()
{
    cout <<"Enter Client Name: ";
    getline(cin, clientName);

    cout << "Enter Business Name: ";
    getline(cin, businessName);

    cout << "Select Business Type:\n";
    cout << "  1. Small Business\n";
    cout << "  2. Medium Business\n";
    cout << "  3. Corporate Business\n";
    cout << "Enter Choice (1-3): ";
    cin >> businessType;

    cout << "Enter Campaign Duration (in days): ";
    cin >> campaignDuration;
}

// Function to Display Social Media Platforms
void displayPlatforms()
{
    cout << "\n========== AVAILABLE PLATFORMS ==========\n";
    for(int i = 0; i < 3; i++)
    {
        cout << i + 1 << ". " << platforms[i] 
             << " (Base Management Charges: Rs. " << baseCharges[i] << ")\n";
    }
    cout << "=========================================\n";
}

// Function to Select Platform
void selectPlatform()
{
    displayPlatforms();
    cout << "\nEnter Platform Number (1-3) for Campaign: ";
    cin >> selectedPlatformNo;

    if(selectedPlatformNo >= 1 && selectedPlatformNo <= 3)
    {
        cout << "\n--- Enter Campaign Content Requirements ---\n";
        cout << "Number of Static Posts (Rs. 1,000 each): ";
        cin >> staticPosts;

        cout << "Number of Reel/Video Posts (Rs. 2,500 each): ";
        cin >> reelPosts;

        cout << "Number of Carousel Posts (Rs. 1,800 each): ";
        cin >> carouselPosts;

        cout << "Enter Advertisement Budget (Rs.): ";
        cin >> adBudget;
        
        cout << "Campaign details updated successfully!\n";
    }
    else
    {
        cout << "Invalid Platform Selected. Try again.\n";
        selectedPlatformNo = 0; // Reset if invalid
    }
}

// Function to Calculate Post Design Cost
double calculatePostDesignCost()
{
    double cost = (staticPosts * 1000) + (reelPosts * 2500) + (carouselPosts * 1800);
    return cost;
}

// Function to Calculate Ad Handling Fee
double calculateAdHandlingFee()
{
    if(adBudget < 50000)
    {
        return adBudget * 0.05;
    }
    else if(adBudget >= 50000 && adBudget <= 100000)
    {
        return adBudget * 0.08;
    }
    else if(adBudget > 100000)
    {
        return adBudget * 0.10;
    }
    return 0;
}

// Function to Calculate Extra Duration Charges
double calculateExtraDurationCharges()
{
    if(campaignDuration > 30)
    {
        return (campaignDuration - 30) * 500;
    }
    return 0;
}

// Function to Calculate GST 
double calculateGST(double totalServiceCost)
{
    return totalServiceCost * 0.16;
}

// Function to Calculate Discount based on Business Type
double calculateDiscount(double platformAndDesignCost)
{
    if(businessType == 1)    
    {
        return platformAndDesignCost * 0.05;
    }
    else if(businessType == 2) 
    {
        return platformAndDesignCost * 0.08;
    }
    else if(businessType == 3) 
    {
        return platformAndDesignCost * 0.10;
    }
    return 0;
}

// Function to Display Final Campaign Bill
void displayFinalCampaignBill()
{
    if(selectedPlatformNo == 0)
    {
        cout << "\n Please select a platform and campaign details (Option 2) first.\n";
        return;
    }

    double platformCost = baseCharges[selectedPlatformNo - 1];
    double designCost = calculatePostDesignCost();
    double handlingFee = calculateAdHandlingFee();
    double extraDurationCost = calculateExtraDurationCharges();

    // Total Service Cost subject to GST and Discounts
    double serviceCostBeforeTax = platformCost + designCost + handlingFee + extraDurationCost;
    
    double gst = calculateGST(serviceCostBeforeTax);
    
    // Discount usually applies to agency's internal service fees
    double discount = calculateDiscount(platformCost + designCost);

    // Final Calculation: (Service Fees + GST + Ad Budget) - Discount
    double finalCampaignCost = serviceCostBeforeTax + gst + adBudget - discount;

    cout << "\n========== SOCIAL MEDIA CAMPAIGN BILL ==========\n\n";

    cout << "Client Name: " << clientName << endl;
    cout << "Business Name: " << businessName << endl;
    
    if(businessType == 1) cout << "Business Type: Small Business\n";
    else if(businessType == 2) cout << "Business Type: Medium Business\n";
    else if(businessType == 3) cout << "Business Type: Corporate Business\n";
    
    cout << "Selected Platform: " << platforms[selectedPlatformNo - 1] << endl;
    cout << "Campaign Duration: " << campaignDuration << " Days" << endl;

    cout << "\nPlatform Management Charges: Rs. " << platformCost << endl;
    cout << "Post Design Cost: Rs. " << designCost << endl;
    cout << "Ad Budget: Rs. " << adBudget << endl;
    cout << "Ad Handling Fee: Rs. " << handlingFee << endl;
    cout << "Extra Duration Charges: Rs. " << extraDurationCost << endl;
    cout << "GST: Rs. " << gst << endl;
    cout << "Discount: Rs. " << discount << endl;

    cout << "------------------------------------------------\n";
    cout << "Final Campaign Cost: Rs. " << finalCampaignCost << endl;
    cout << "================================================\n";
}

// Function to Display Client Details
void displayClientDetails()
{
    cout << "\n===== CLIENT PROFILE DETAILS =====\n";
    cout << "Client Name: " << clientName << endl;
    cout << "Business Name: " << businessName << endl;
    
    if(businessType == 1) cout << "Business Type: Small Business\n";
    else if(businessType == 2) cout << "Business Type: Medium Business\n";
    else if(businessType == 3) cout << "Business Type: Corporate Business\n";
    
    cout << "Campaign Duration: " << campaignDuration << " Days\n";
    if(selectedPlatformNo != 0)
    {
        cout << "Active Campaign Platform: " << platforms[selectedPlatformNo - 1] << endl;
    }
    else
    {
        cout << "Active Campaign Platform: None Selected Yet\n";
    }
    cout << "==================================\n";
}

// Main Function
int main()
{
    int option;
    registerClient();

    do
    {
        cout << "\n===== MAIN MENU =====\n";
        cout << "1. View Platforms\n";
        cout << "2. Select Campaign Platform\n";
        cout << "3. Calculate Campaign Cost\n";
        cout << "4. View Client Details\n";
        cout << "5. Exit\n";

        cout << "Enter Choice: ";
        cin >> option;

        if(option == 1)
        {
            displayPlatforms();
        }
        else if(option == 2)
        {
            selectPlatform();
        }
        else if(option == 3)
        {
            displayFinalCampaignBill();
        }
        else if(option == 4)
        {
            displayClientDetails();
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
