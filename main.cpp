
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <limits>

using namespace std;

// Contact structure
struct Contact {
    string name;
    string phone;
};

// Convert text to lowercase
string toLowerCase(string text) {
    for (char &ch : text) {
        ch = static_cast<char>(
            tolower(static_cast<unsigned char>(ch))
        );
    }
    return text;
}

// Naive String Matching Algorithm
bool naiveStringMatch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();

    if (m == 0) {
        return true;
    }

    if (m > n) {
        return false;
    }

    for (int i = 0; i <= n - m; i++) {
        int j = 0;

        while (j < m && text[i + j] == pattern[j]) {
            j++;
        }

        if (j == m) {
            return true;
        }
    }

    return false;
}

// Smart Contact Search System
class SmartContactSystem {
private:
    vector<Contact> contacts;

public:
    // Add a new contact
    void addContact() {
        Contact c;

        cout << "\nEnter contact name: ";
        getline(cin, c.name);

        if (c.name.empty()) {
            cout << "Name cannot be empty!\n";
            return;
        }

        cout << "Enter phone number: ";
        getline(cin, c.phone);

        if (c.phone.empty()) {
            cout << "Phone number cannot be empty!\n";
            return;
        }

        contacts.push_back(c);
        cout << "\nContact added successfully!\n";
    }

    // Search contacts using Naive String Matching
    void searchContact() {
        string pattern;

        cout << "\nEnter name or part of name to search: ";
        getline(cin, pattern);

        if (pattern.empty()) {
            cout << "Please enter a search term.\n";
            return;
        }

        pattern = toLowerCase(pattern);
        bool found = false;

        cout << "\n--- Search Results ---\n";

        for (const Contact &c : contacts) {
            string name = toLowerCase(c.name);

            if (naiveStringMatch(name, pattern)) {
                cout << "Name: " << c.name
                     << " | Phone: " << c.phone << "\n";
                found = true;
            }
        }

        if (!found) {
            cout << "No matching contacts found.\n";
        }
    }

    // Display contacts alphabetically
    void displayContacts() {
        if (contacts.empty()) {
            cout << "\nNo contacts available.\n";
            return;
        }

        vector<Contact> sortedContacts = contacts;

        sort(sortedContacts.begin(), sortedContacts.end(),
             [](const Contact &a, const Contact &b) {
                 return toLowerCase(a.name) <
                        toLowerCase(b.name);
             });

        cout << "\n--- All Contacts (A-Z) ---\n";

        for (const Contact &c : sortedContacts) {
            cout << "Name: " << c.name
                 << " | Phone: " << c.phone << "\n";
        }
    }

    // Delete a contact by exact name
    void deleteContact() {
        string nameToDelete;

        cout << "\nEnter the exact name to delete: ";
        getline(cin, nameToDelete);

        if (nameToDelete.empty()) {
            cout << "Please enter a name.\n";
            return;
        }

        string target = toLowerCase(nameToDelete);

        for (auto it = contacts.begin();
             it != contacts.end(); ++it) {

            if (toLowerCase(it->name) == target) {
                cout << "Deleted contact: "
                     << it->name << "\n";

                contacts.erase(it);
                return;
            }
        }

        cout << "Contact not found.\n";
    }
};

// Main function
int main() {
    SmartContactSystem system;
    int choice;

    do {
        cout << "\n=================================\n";
        cout << "   SMART CONTACT SEARCH SYSTEM\n";
        cout << "=================================\n";
        cout << "1. Add Contact\n";
        cout << "2. Search Contact\n";
        cout << "3. Display All Contacts\n";
        cout << "4. Delete Contact\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "\nInvalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                system.addContact();
                break;

            case 2:
                system.searchContact();
                break;

            case 3:
                system.displayContacts();
                break;

            case 4:
                system.deleteContact();
                break;

            case 5:
                cout << "\nThank you for using Smart Contact "
                     << "Search System!\n";
                break;

            default:
                cout << "\nInvalid choice. Please select 1-5.\n";
        }

    } while (choice != 5);

    return 0;
}
