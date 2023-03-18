#include<iostream>
#include<algorithm>
#include<set>
using namespace std;


//P5250 木材仓库
set<int,less<int>> s;

int n;
int op,l;


int main()
{
    cin>>n;
    set<int>::iterator it,llb,lb;
    while(n--)
    {
        cin>>op>>l;
        if(op==1)
        {
            if(s.find(l)!=s.end())
            {
                cout<<"Already Exist\n";
            }
            else
            {
                s.insert(l);
            }
        }
        else
        {
            if(s.empty())
            {
                cout<<"Empty\n";
            }
            else if(s.size()==1)
            {
                cout<<*s.begin()<<"\n";
                s.erase(s.begin());
            }
            else
            {
                if((llb=lb=s.lower_bound(l))!=s.end())
                {
                    if(*lb>l)
                    {
                        if(lb==s.begin())
                        {
                            it=lb;
                        }
                        else
                        {
                            --llb;
                            if(l-*llb>*lb-l)
                            {
                                it=lb;
                            }

                            else
                            {
                                it=llb;
                            }
                        }
                    }
                    else
                    {
                        it=lb;
                    }
                }
                else
                {
                    it=--s.end();
                }
                cout<<*it<<"\n";
                s.erase(it);
            }
        }
    }


    return 0;
}