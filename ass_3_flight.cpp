#include <iostream>
using namespace std;

class GR {
    int fuel, vert;
    string city[100];
    int adj[100][100]; 
    struct GRList {
        int fuel;
        string city;
        GRList *next;
    } *head[10];
public:
    void adjMat();
    void adjList();
} g;

void GR::adjMat() 
{
    cout << "Enter the number of cities: ";
    cin >> vert;

    cout << "Enter the cities names: ";
    for (int i = 0; i < vert; i++) 
    {
        cin >> city[i];
    }

    cout << "Enter the fuel required between cities:\n";
    for (int i = 0; i < vert; i++)
     {
        for (int j = 0; j < vert; j++) 
        { 
            if (i == j) {
                adj[i][j] = 0; 
            } else {
                cout << "Enter the fuel for " << city[i] << " to " << city[j] << ":\n ";
                cin >> adj[i][j];
            }
        }
    }

    cout << "Fuel Requirement Matrix:\n";
    cout << "  ";
    for (int i = 0; i < vert; i++) 
    {
        cout << city[i] << "    ";
    }
    cout << endl;

    for (int i = 0; i < vert; i++) 
    {
        cout << city[i] << " ";
        for (int j = 0; j < vert; j++)
        {
            cout << adj[i][j] << "     ";
        }
        cout << endl;
    }
}

void GR::adjList()
{
    int v;
    cout << "Enter the number of cities: ";
    cin >> v;
    cout << "Enter the city names: ";
    for (int i = 0; i < v; i++)
    {
        head[i] = new GRList;
        cin >> head[i]->city;
        head[i]->next = NULL;
    }
    
    int e;
    string s, d;
    GRList *n1, *temp;
    cout << "Enter the total number of edges: ";
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        cout << "Enter the source and destination: ";
        cin >> s >> d;
        int j;
        for (j = 0; j < v; j++)
        {
            if (s == head[j]->city)
                break;
        }
        
        n1 = new GRList;
        n1->city = d;
        cout << "Enter the fuel required: ";
        cin >> n1->fuel;
        n1->next = NULL;
        temp = head[j];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n1;
    }
    
    for (int i = 0; i < v; i++)
    {
        cout << "City: " << head[i]->city << " -> ";
        GRList *temp = head[i]->next;
        while (temp != NULL)
        {
            cout << temp->city << " [Fuel: " << temp->fuel << "] -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
}

int main()
{
    int choice;
    do
    {
        cout << "Choose representation:\n";
        cout << "1. Adjacency Matrix\n";
        cout << "2. Adjacency List\n";
        cout << "0. Exit\n";
        cin >> choice;
        
        switch (choice)
        {
            case 1:
                g.adjMat();
                break;
            case 2:
                g.adjList();
                break;
            case 0:
                exit(0);
            default:
                cout << "Invalid choice!";
        }
    } while (choice != 0);
    
    return 0;
}
