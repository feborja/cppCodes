#include <iostream>
#include <vector>
// #include <string>
using namespace std;

bool solver(){
    int n, m;
    cin >> n >> m;
    string t1, t2;
    cin >> t1 >> t2;
    int errors = 0;
    for (int i = 1; i < t1.size(); i++){
        if (t1[i-1]==t1[i]){
            errors++;
        }
    }
    if (t1.back()==t2.back()){
        errors++;
    }
    for (int i = 1; i < t2.size(); i++){
        if (t2[i-1]==t2[i]){
            errors++;
        }
    }
    if (errors>1){
        return 0;
    }
    else{
        return 1;
    }
    }

int main(){
    int t;
    cin >> t;
    while(t--){
        if(solver()){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        } 
    }
    return 0;
}