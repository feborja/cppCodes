#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    // Con esto recibimos el largo de la entrada siguiente, creamos el vector receptor
    vector<int> flies(n);
    // Leemos los valores
    for (int i=0;i<n;i++){
	    cin>>flies[i];
    } 
    // Ahora se procesa el vector
    int bottom = 0;
    int top = 0; // ambos indices parten igual
    // int wnd_size = 0;
    int max = 1;
    // caso borde de un solo valor
    if (n<=1){
        cout<<n<<"\n";
        return 0;
    }
    else{
        set<int> memory;
        memory.insert(flies[0]);
        while (top<(n-1)){ // No va a llegar al final a menos que esté listo
            // Agrego el valor antes de comparar
            memory.insert(flies[top+1]);
            if (memory.size() == (top-bottom+2)){
                // cout<<"Siguen unicos \n";
                top++;
                if ((top-bottom+1)>=max){
                    max =(top-bottom+1);
                }
            }
            else{
                // Se mueve de posición bottom, para esto buscamos donde está el valor que está
                // en top+1 pero dentro de mis índices
                int cache = bottom;
                bottom = find(flies.begin()+bottom, flies.end(), flies[top+1]) - flies.begin() + 1;
                // while(memory.size() != (top-bottom+2)){
                //     bottom +=1;
                // }
                // bottom +=1;
                // Limpiamos y reiniciamos el set de memoria
                for (int i = cache; i< bottom; i++){
                    memory.erase(flies[i]);
                }
                // memory.clear();

                // for (int i = bottom; i<=top;i++){
                //     memory.insert(flies[i]);
                // }
            }
        }
        cout<<max<<"\n";
    }
    return 0;
}