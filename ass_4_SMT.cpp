#include <iostream>
using namespace std;

class SMT 
{
    int fuel, vert;
    string city[100];
    int adj[100][100]; 
public:
    void accept();
    void smt();
    void display();
} g;

void SMT::accept()
{
    cout << "Enter the number of cities: ";
    cin >> vert;

    cout << "Enter the cities names: ";
    for (int i = 0; i < vert; i++) 
    {
        cin >> city[i];
    }

    cout << "Enter the distance between cities:\n";
    for (int i = 0; i < vert; i++) 
    
    {
        for (int j = 0; j < vert; j++) 
        { 
            if (i == j) 
            {
                adj[i][j] = 0; 
            } else 
            {
                cout << "Enter the distance for " << city[i] << " to " << city[j] << ":\n ";
                cin >> adj[i][j];
            }
        }
    }
}

void SMT::display() 
{
    cout << "Distance Matrix:\n";
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

void SMT::smt() 
{
    int key[100];
    int parent[100];
    bool visited[100];
    int min,u;

    for (int i = 0; i < vert; i++) 
    {
        key[i] = 999;
        visited[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;
    min = 999, u = -1;

    for (int e = 0; e < vert - 1; e++) 
    {
        for (int i = 0; i < vert; i++) 
        {
            if (!visited[i] && key[i] < min)
             {
                min = key[i];
                u = i;
            }
        }
        visited[u] = true;
        for (int j = 0; j < vert; j++) 
        {
            if (adj[u][j] && !visited[j] && adj[u][j] < key[j]) 
            {
                parent[j] = u;
                key[j] = adj[u][j];
            }
        }
    }

    cout << "\nShortest path is:\n";
    int distance = 0;
    for (int i = 1; i < vert; i++) 
    {
        cout << city[parent[i]] << " -> " << city[i] << "  Fuel: " << key[i] << endl;
        distance += key[i];
    }
    cout << "Total Distance: " << distance << "\n";
}

int main() 
{  
    int ch;
    do {
        cout << "Enter choice:\n";
        cout << "1. Accept details\n";
        cout << "2. Display Matrix\n";
        cout << "3. Shortest Distance\n";
        cin >> ch;
        switch (ch) 
        {
            case 1:
                g.accept();
                break;
            case 2:
                g.display();
                break;
            case 3:
                g.smt();
                break;
            default:
                cout << "Invalid choice\n";
                break;
        }
    } while (ch != 0);

    return 0;
}
