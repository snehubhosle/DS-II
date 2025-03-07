#include <iostream>
using namespace std;

class emp {
public:
    int id, ch;
    string name, add;
    emp *lc, *rc;
    void create();
    void insert(emp *root, emp *next);
    void display(emp *root);
} *root = NULL;

void emp::create()
 {
    root = new emp;
    cout << "Enter employee information (ID, Name, Address): ";
    cin >> root->id >> root->name >> root->add;
    root->lc = root->rc = NULL;

    do {
        cout << "Do you want to create more nodes(1/0): ";
        cin >> ch;
        if (ch == 1) 
        {
            emp *newNode = new emp;
            cout << "Enter ID, Name, Address: ";
            cin >> newNode->id >> newNode->name >> newNode->add;
            newNode->lc = newNode->rc = NULL;
            insert(root, newNode);
        }
    } while (ch != 0);
}

void emp::insert(emp *root, emp *next)
 {
    char chr;
    cout << "Where do you want to insert under " << root->id << " L/R: ";
    cin >> chr;

    if (chr == 'L' || chr == 'l')
     {
        if (root->lc == NULL)
         { 
            root->lc = next;
        } else
         {
            insert(root->lc, next);
        }
    } 
    else if (chr == 'R' || chr == 'r')
     {
        if (root->rc == NULL) 
        { 
            root->rc = next;
        } else 
        {
            insert(root->rc, next);
        }
    }
     else
     {
        cout << "Invalid choice!" << endl;
    }
}

void emp::display(emp *root) 
{
    if (root != NULL) {
        cout << "ID: " << root->id << ", Name: " << root->name << ", Address: " << root->add << endl;
        display(root->lc);
        display(root->rc);
    }
}

int main() {
    emp E;
    int choice;

    do {
        cout << "\nEnter your choice:" << endl;
        cout << "1. Create a node" << endl;
        cout << "2. Insert data into a node" << endl;
        cout << "3. Display all nodes" << endl;
        cout << "0. Exit" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            E.create();
            break;
        case 2: {
            emp *newNode = new emp; 
            cout << "Enter employee information (ID, Name, cet marks): ";
            cin >> newNode->id >> newNode->name >> newNode->add;
            newNode->lc = newNode->rc = NULL;
            E.insert(root, newNode);
            break;
        }
        case 3:
            cout << "Displaying all nodes:" << endl;
            E.display(root);
            break;
        case 0:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}
