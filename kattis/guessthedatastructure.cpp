#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    while(cin >> n){ 
        int bool_pila = 1;
        int bool_cola = 1;
        int bool_priori_cola = 1;
        int breaker=0;
        stack<int> pila;
        queue<int> cola;
        priority_queue<int> priori_cola;

        vector<int> actions(2*n);
        // Leemos los valores
        for (int i=0;i<2*n;i++){
            cin>>actions[i];
        }
    // Ejecutamos las acciones
        for(int i=0; i<2*n; i+=2){
            if(actions[i]==1){
                pila.push(actions[i+1]);
                cola.push(actions[i+1]);
                priori_cola.push(actions[i+1]);
            }
            else if(actions[i]==2){
                if (pila.empty() or cola.empty() or priori_cola.empty()){
                    bool_pila = 0;
                    bool_cola = 0;
                    bool_priori_cola = 0;
                    breaker=1;
                    break;
                }
                if (pila.top()!=actions[i+1]){
                    bool_pila *= 0;
                }
                if (cola.front()!=actions[i+1]){
                    bool_cola *= 0;
                }
                if (priori_cola.top()!=actions[i+1]){
                    bool_priori_cola *= 0;
                }
                // Se realizan las operaciones
                pila.pop();
                cola.pop();
                priori_cola.pop();
            }
        }
        // Una vez terminadas las ejecuciones, se revisa
        int sum = (bool_pila + bool_cola + bool_priori_cola);
        if(sum>1){
            cout << "not sure"<<"\n";
        }
        else if(sum==0 or breaker==1){
            cout << "impossible"<<"\n";
        }
        else if(bool_pila){
            cout << "stack"<<"\n";
        }
        else if(bool_cola){
            cout << "queue"<<"\n";
        }
        else if(bool_priori_cola){
            cout << "priority queue"<<"\n";
        }
    }
    return 0;
}