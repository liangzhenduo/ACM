#include <iostream>
#include <string>
#include <set>
using namespace std;
int main(){
    set<string> s;
    string tmp;
    while(cin>>tmp)
        s.insert(tmp);
    for(set<string>::iterator it=s.begin();it!=s.end();it++){
        tmp=*it;
        for(int i=1;i<tmp.length();i++)
            if(s.find(tmp.substr(0,i))!=s.end()&&s.find(tmp.substr(i,tmp.length()-i))!=s.end()){
                cout<<tmp<<endl;
                break;
            }
    }
}
