#include <iostream>
#include <string>
using namespace std;

// Global Variables
string regUser = "";
string regPass = "";
bool isReg = false, loggedIn = false;

string titles[20];
string contents[20];
int totalEntries = 0;

void handleAuth() 
{
    int choice;
    while (!loggedIn) 
	{
        cout << "\n1. Register\n2. Login\n3. Exit\nChoice: ";
        cin >> choice;
        if (choice == 1) 
		{
            cout << "Username: "; 
			cin >> regUser;
            cout << "Password: "; 
			cin >> regPass;
            isReg = true; cout << "Registered!\n";
        } else if (choice == 2) 
		{
            string u, p;
            cout << "Username: "; cin >> u;
            cout << "Password: "; cin >> p;
            if (isReg && u == regUser && p == regPass) {
                loggedIn = true; cout << "Logged In!\n";
            } else cout << "Invalid Credentials!\n";
        } else exit(0);
    }
}

void createEntry() 
{
    if (totalEntries >= 20) 
	{ 
	cout << "Diary Full!\n"; 
	return; 
	}
    cin.ignore();
    cout << "Enter Title: "; 
	getline(cin, titles[totalEntries]);
    cout << "Enter Content: "; 
	getline(cin, contents[totalEntries]);
    if (titles[totalEntries].empty() || contents[totalEntries].empty()) 
	{
        cout << "Empty fields not allowed!\n";
    } 
	else 
	{
        totalEntries++; cout << "Saved!\n";
    }
}

void viewAll() {
    cout << "\n--- ALL ENTRIES ---\n";
    if (totalEntries == 0) cout << "No entries found.\n";
    for (int i = 0; i < totalEntries; i++) 
	cout << i + 1 << ". " << titles[i] << endl;
}

void readEntry() {
    viewAll(); 
	if (totalEntries == 0) 
	return;
    int idx; cout << "Enter Number: "; 
	cin >> idx;
    if (idx >= 1 && idx <= totalEntries) 
	{
        cout << "\nTitle: " << titles[idx-1] << "\nContent: " << contents[idx-1] << endl;
    } else cout << "Invalid Number!\n";
}

void editEntry() {
    viewAll(); 
	if (totalEntries == 0) 
	return;
    int idx; cout << "Enter Number to Edit: "; 
	cin >> idx;
    if (idx >= 1 && idx <= totalEntries) 
	{
        cin.ignore();
        cout << "New Title: "; getline(cin, titles[idx-1]);
        cout << "New Content: "; getline(cin, contents[idx-1]);
        cout << "Updated!\n";
    } else cout << "Invalid Number!\n";
}

void deleteOne() {
    viewAll(); 
	if (totalEntries == 0) 
	return;
    int idx; 
	cout << "Enter Number to Delete: "; 
	cin >> idx;
    if (idx >= 1 && idx <= totalEntries) 
	{
        for (int i = idx - 1; i < totalEntries - 1; i++) 
		{
            titles[i] = titles[i+1];
            contents[i] = contents[i+1];
        }
        totalEntries--; cout << "Deleted!\n";
    } else cout << "Invalid Number!\n";
}

void searchEntry() 
{
    cin.ignore();
    string keyword; 
	cout << "Enter keyword to search: "; 
	getline(cin, keyword);
    for (int i = 0; i < totalEntries; i++) 
	{
        if (titles[i].find(keyword) != string::npos) 
		{
            cout << "Found [" << i+1 << "]: " << titles[i] << endl;
        }
    }
}

int main() {
    handleAuth();
    int choice;
    do {
        cout << "\n=== STUDENT DIARY (" << totalEntries << "/20) ===\n";
        cout << "1. Create Entry\n2. View All\n3. Read Entry\n4. Edit Entry\n5. Delete One\n6. Delete All\n7. Search\n8. Exit\nChoice: ";
        cin >> choice;
        if (choice == 1) createEntry();
        else if (choice == 2) 
		viewAll();
        else if (choice == 3) 
		readEntry();
        else if (choice == 4) 
		editEntry();
        else if (choice == 5) 
		deleteOne();
        else if (choice == 6) 
		{ 
		totalEntries = 0; cout << "Cleared!\n"; 
		}
        else if (choice == 7) 
		searchEntry();
    } 
	while (choice != 8);
    return 0;
}
