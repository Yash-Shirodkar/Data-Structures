#include <iostream>
#include <cstdlib>
using namespace std;
#define MAX 20

class AdjMatCities
{
    int n,**adj;
public:
    AdjMatCities(int n)
    {
        this->n = n;
        adj = new int* [n];
        for (int i = 0; i < n; i++)
        {
            adj[i] = new int [n];
            for(int j = 0; j < n; j++)
                adj[i][j]=0;
        }
    }
    void add_path(int origin, int destin, int time)
    {
        if(origin > n || destin > n || origin < 0 || destin < 0)
            cout<<"Invalid Path Between Cities!\n";
        else
        {
            adj[origin - 1][destin - 1] = time;
            adj[destin - 1][origin - 1] = time;
        }
    }
    void displayMap()
    {
        int i,j;
        cout<<"\nCITIES : \n";
        for(i = 0;i < n;i++)
        {
            for(j = 0; j < n; j++)
                cout<<adj[i][j]<<"\t";
            cout<<endl;
        }
    }
};

int main()
{
    int nodes, max_paths, origin, destin, time;
    int s, d;
    string cities[10];
    cout<<"Enter Number Of Cities: ";
    cin>>nodes;
    AdjMatCities am(nodes);
    max_paths = nodes * (nodes - 1);
    for(int i=0;i<nodes;i++)
    {
        cout<<"\nEnter Name Of City "<<i+1<<" : ";
        cin>>cities[i];
    }
    cout<<"\n\nName Of Cities :";
    for(int i=0;i<nodes;i++)
    {
        cout<<"\n"<<i+1<<" Denotes : "<<cities[i];
    }
    cout<<"\n\n";
    for (int i = 0; i < max_paths; i++)
    {
        cout<<"\nEnter Origin City No (Enter -1 & -1 To Exit)      : ";
        cin>>origin;
        cout<<"\nEnter Destination City No (Enter -1 & -1 To Exit) : ";
        cin>>destin;
        if((origin == -1) && (destin == -1))
            break;
        cout<<"\nEnter Time Of Flight From "<<cities[origin-1]<<" To "<<cities[destin-1]<<" : ";
        cin>>time;
        am.add_path(origin, destin, time);
    }
    am.displayMap();
    return 0;
}
