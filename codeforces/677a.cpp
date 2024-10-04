#include <iostream>
#include <vector>
using namespace std;


int main(){
    int n;
    int h;
    cin >> n;
    cin >> h;
    // Con esto recibimos el largo de la entrada siguiente, creamos el vector
    vector<int> a(n);
    // Leemos los valores
    for (int i=0;i<n;i++){
	    cin>>a[i];
    }
    // Operamos
    int ancho=0;
    for (int i = 0; i < n; i++)
    {
        if (a[i]>h)
        {
            ancho +=2;
        }
        else
        {
            ancho +=1;
        }
        
    }
    cout << ancho;
    return 0;
}