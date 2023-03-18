#include<iostream>
#include<string>
#include<map>
using namespace std;

//P5266 学籍管理


map<string,int> info;

int op,n;
string name;
int score;



int main()
{
    cin>>n;
    map<string,int>::iterator it;
    while(n--)
    {
        cin>>op;
        switch(op)
        {
        case 1:
            cin>>name>>score;
            info[name]=score;
            cout<<"OK\n";
            break;
        case 2:
            cin>>name;
            if((it=info.find(name))!=info.end())
            {
                cout<<it->second<<"\n";               
            }
            else
            {
                cout<<"Not found\n";
            }
            break;
        case 3:
            cin>>name;
             if((it=info.find(name))!=info.end())
            {
                info.erase(it);
                cout<<"Deleted successfully\n";
            }
            else
            {
                cout<<"Not found\n";
            }
            break;
         case 4:
            cout<<info.size()<<"\n";
        }
    }
    return 0;
}