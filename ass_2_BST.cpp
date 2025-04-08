#include <iostream>
using namespace std;

class student
{
public:
    int rono, ch;
    float cet;
    string name;
    student *lc, *rc;

    void create();
    void insert(student *root, student *next);
    void display(student *root);
    void min_marks(student *root);
    void search(student *root, int no); 
    student* delete_leaf(student *root); 
    void update(student *root ,int no);
} *root = NULL;

void student::create() 
{
    root = new student;
    cout << "Enter student information (rono, Name, cet marks): ";
    cin >> root->rono >> root->name >> root->cet;
    root->lc = root->rc = NULL;

    do {
        cout << "Do you want to create more nodes(1/0): ";
        cin >> ch;
        if (ch == 1) 
        {
            student *newNode = new student;
            cout << "Enter rono, Name, cet marks: ";
            cin >> newNode->rono >> newNode->name >> newNode->cet;
            newNode->lc = newNode->rc = NULL;
            insert(root, newNode);
        }
    } while (ch != 0);
}

void student::insert(student *root, student *next)
{
    if (root->cet > next->cet)
    {
        if (root->lc == NULL) 
        {
            root->lc = next;
        } 
        else 
        {
            insert(root->lc, next);
        }
    } 
    else if (root->cet < next->cet) 
    {
        if (root->rc == NULL) 
        {
            root->rc = next;
        } 
        else 
        {
            insert(root->rc, next);
        }
    }
}

void student::min_marks(student *root) 
{
    if (root == NULL) 
        return;

    if (root->lc == NULL)  
    {
        cout << root->rono << "\t" << root->name << "\t" << root->cet << endl;
        return;
    }
    
    min_marks(root->lc);  
}

void student::display(student *root) 
{
    if (root != NULL) 
    {
        display(root->lc);
        cout << root->rono << "\t" << root->name << "\t" << root->cet << endl;
        display(root->rc);
    }
}

void student::search(student *root, int no) 
{
    if (root == NULL) 
    {
        cout << "Student not found!" << endl;
        return;
    }

    if (root->rono == no) 
    {
        cout << "Student Found: " << root->rono << "\t" << root->name << "\t" << root->cet << endl;
        return;
    }
    else if (no < root->rono) 
    {
        search(root->lc, no);  
    }
    else 
    {
        search(root->rc, no);   
    }
}

student* student::delete_leaf(student *root)
{
    if (root == NULL)
        return NULL;

    if (root->lc == NULL && root->rc == NULL)
    {
        cout << "Deleting leaf node: \n";
        cout << root->rono << "\t" << root->name << "\t" << root->cet << endl;
        delete root;
        return NULL;  
    }

    root->lc = delete_leaf(root->lc);
    root->rc = delete_leaf(root->rc);

    return root;  
}

void student::update(student *root,int no)

{
    if (root == NULL)
    {
        cout << "Student not found!" << endl;
        return;
    }

    if (root->rono == no)
    {
        cout << "Student Found: " << root->rono << "\t" << root->name << "\t" << root->cet << endl;
        cout << "Enter new CET marks: ";
        cin >> root->cet;
        cout << "Record updated successfully!" << endl;
        return;
    }
    else if (no < root->rono)
    {
        update(root->lc, no);
    }
    else
    {
        update(root->rc, no);
    }
}
int main() 
{
    student S;
    int choice, no;

    do
    {
        cout << "\nEnter your choice:" << endl;
        cout << "1. Create a node" << endl;
        cout << "2. Display all nodes" << endl;
        cout << "3. Student with lowest marks" << endl;
        cout << "4. Delete leaf node" << endl;
        cout << "5. Search student by roll no" << endl;
        cout << "6. Update record"<<endl;
        cout << "0. Exit" << endl;
        cin >> choice;

        switch (choice) 
        {
            case 1:
                S.create();
                break;
            case 2:
                cout << "Displaying all nodes:" << endl;
                cout << "\nRoNO" << "\t" << "Name" << "\t" << "Marks\n";
                S.display(root);
                break;
            case 3:
                cout << "Student with lowest marks is:\n";
                cout << "\nRoNO" << "\t" << "Name" << "\t" << "Marks\n";
                S.min_marks(root);
                break;
            case 4:
                root = S.delete_leaf(root);  
                break;
            case 5:
                cout << "Enter Roll no to search record:\n";
                cin >> no;
                S.search(root, no);
                break;
            case 6:
                cout <<"enter roll no to update";
        }
    } while (choice != 0);

    return 0;
}
