#include<iostream>
#include<list>
#include<map>
using namespace std;
//P1160 链表操作简单模拟

list<int> s;
typedef map<int,list<int>::iterator> MAP;
MAP m;
//map<int,list<int>::iterator>
/*
5
1 0
2 0
2 1
4 0
3
1
3
5
*/
int main()
{
    int n,k;
    cin>>n;
    int x,y;   
    m[1]=s.insert(s.begin(),1);
  //  m[0]=s.begin();
  //  m[1]=s.begin();
 //   if(m[1]==s.begin())
  //  {
    //    cout<<"equal!\n";
  //  }
  //  else cout<<"unequal!\n";
    list<int>::iterator chk=s.begin();
    MAP::iterator mit;
    list<int>::iterator it;
    
    //cout<<*chk<<" "<<*m[1]<<"\n";
    for(int i=2;i<=n;i++)
    {
        cin>>x>>y;
        if(y)
        {
            it=m[x];
            m[i]=s.insert(++it,i);
      //     cout<<"insert "<<i<<" after "<<x<<"\n";
        //    cout<<"listnow "<<*m[i]<<"\n";
       //     cout<<"list1 "<<*m[1]<<"\n";
        //    cout<<"listbgn "<<*chk<<"\n";
       //     cout<<"m0 "<<*m[0]<<"\n";
     //       if(m[1]==s.begin())
        //    {
       //         cout<<"equal!\n";
       ////     }
       ///     else cout<<"unequal!\n";
          //  cout<<"listbegin"<<*s.begin()<<"\n";
        }
        else
        {
            m[i]=s.insert(m[x],i);
      //      cout<<"insert "<<i<<" before "<<x<<"\n";
        //    cout<<"listnow "<<*m[i]<<"\n";
        //    cout<<"list1 "<<*m[1]<<"\n";
       //     cout<<"listbgn "<<*chk<<"\n";
        ///    cout<<"m0 "<<*m[0]<<"\n";
         //   if(m[1]==s.begin())
        //    {
         //       cout<<"equal!\n";
        //    }
          //  else cout<<"unequal!\n";
         //   cout<<"listbegin "<<*s.begin()<<"\n";
        }
        
     //   for (it=s.begin();it!=s.end();it++)
     //   {
     //       cout<<*it<<" ";
    //   }
     //   cout<<"\n";
    }
  //  for (it=s.begin();it!=s.end();it++)
 //   {
  //      cout<<*it<<" ";
  //  }
  //  cout<<"\n";
    cin>>k;
    
    for(int i=1;i<=k;i++)
    {
        cin>>x;
        if((mit=m.find(x))!=m.end())
        {
         //   cout<<"erase "<<x<<" val"<<*mit->second<<"\n";
            s.erase(mit->second);
            m.erase(mit);
          
            //cout<<"end "<<*m.end()->second<<"\n";
        }   
   //     else 
    //    {
    //        cout<<"not found\n";
    //    }
        
      //  for (it=s.begin();it!=s.end();it++)
     //   {
     //       cout<<*it<<" ";
    //    }
     //   cout<<"\n";
     //   cout<<"list1 "<<*m[1]<<"\n";
      //  cout<<"listbgn "<<*chk<<"\n";
     //   cout<<"m0 "<<*m[0]<<"\n";
   //     if(m[1]==s.begin())
    //    {
    //        cout<<"equal!\n";
    //    }
     //   else cout<<"unequal!\n";
    //    cout<<"listbegin"<<*s.begin()<<"\n";
     //   cout<<"\n";    
    }
    
    for (it=s.begin();it!=s.end();it++)
    {
        cout<<*it<<" ";
    }
    
    return 0;
}