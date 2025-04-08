#include<iostream>
using namespace std;

class pizza
{
    int vert, adj[10][10];
    string city[10];
public:
    void accept();
    void display();
    void ssp();
}p;

void pizza::accept()
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
            }
            else
            {
                cout << "Enter the distance for " << city[i] << " to " << city[j] << ":\n ";
                cin >> adj[i][j];
            }
        }
    }
}

void pizza::display()
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

void pizza::ssp()
{
    int visited[10], dist[10];
    for (int i = 0; i < vert; i++)
    {
        dist[i] = 999;
        visited[i] = 0;
    }

    dist[0] = 0;

    for (int i = 0; i < vert - 1; i++)
    {
        int min = 999, u;
        for (int j=0; j<vert; j++)
        {
            if (!visited[j] && dist[j] < min)
            {
                min = dist[i];
                u = i;
            }
        }
        visited[u] = 1;
        for (int v = 0; v < vert; v++)
        {
            if (!visited[v] && adj[u][v] && dist[u] + adj[u][v] < dist[v])
            {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    cout << "Shortest distance from " << city[0] << " to other cities:\n";
    for (int i = 0; i < vert; i++)
    {
        cout << city[0] << " to " << city[i] << " = " << dist[i] << endl;
    }
}

int main()
{
    int ch;
    do {
        cout << "Enter choice:\n";
        cout << "1. Accept details\n";
        cout << "2. Display Matrix\n";
        cout << "3. Single source Shortest path\n";
        cout << "0. Exit\n";
        cin >> ch;
        switch (ch)
        {
            case 1:
                p.accept();
                break;
            case 2:
                p.display();
                break;
            case 3:
                p.ssp();
                break;
            default:
                cout << "Invalid choice\n";
                break;
        }
    } while (ch != 0);

    return 0;
}