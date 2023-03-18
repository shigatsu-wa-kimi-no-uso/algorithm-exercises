#include<iostream>
using namespace std;

int main(){
    int n;
    string str;
    cin>>str>>n; 
    while(n--){
        for(int i=0;i<str.size();++i){
            if(str[i]>str[i+1]){
                str.erase(i,1);
                break;
            }
        }
    }
    cout<<str<<endl;
    return 0;    
}
