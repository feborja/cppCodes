#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    
    map<ll, ll> xx;
    map<ll, ll> yy;
    map<pair<ll,ll>, ll> xy; 
    int n;
    cin >> n;

    for (int i=0; i<n; i++){
        ll x, y;
        cin >> x >> y;

        xx[x]++;
        yy[y]++;
        xy[make_pair(x,y)]++;
    }
    // Notar formula de sumatoria para coordenadas comunes si x=x o y=y
    // nro de lineas = ((k-1)*k)/2
    ll sum = 0;
    for (auto [llave, valor] : xx){
        // ++ 
        sum += ((valor-1)*valor)/2;
    }

    for (auto [llave, valor] : yy){
        // ++
        sum += ((valor-1)*valor)/2;
    }

    for (auto [llave, valor] : xy){
        // --
        // Restamos repetidos, si hay mas de una persona en un puesto, se simplifica a una uwuwuwuwuu
        if (valor>1){
            sum -= ((valor-1)*(valor))/2;
        }
    }
    cout<< sum << "\n";
    return 0;
}