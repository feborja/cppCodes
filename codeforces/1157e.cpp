#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//b = n-a
int main(){
    int n;
    cin >> n;
    // se trabaja con multiset -> b
    vector<int> a(n);
    multiset<int> b;
    vector<int> c(n);
    // set<int> memory;
    // Leemos los valores
    for (int i=0;i<n;i++){
	    cin>>a[i];
    } 
    int var;
     for (int i=0;i<n;i++){
	    cin>>var;
        b.insert(var);
    } 
    var = 0;
    for(int i = 0; i < n; i++ ){
        auto itr = b.lower_bound(n - a[i]);
        if (itr == b.end()){
            var = *b.begin(); 
        }
        else{
            var = *itr;
        }
        c[i]=(a[i]+var)%n;
        b.erase(b.find(var));
    }
    for (int i=0;i<(n-1);i++){
	    cout<<c[i]<<" ";
    } 
    cout<<c[n-1]<<endl;
    return 0;
}