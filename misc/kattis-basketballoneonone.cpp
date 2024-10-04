#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    string match;
    cin >> match;
    int pA = 0;
    int pB = 0;
    
    // Se realiza un conteo de puntajes
    for (int i = 1; i < match.size(); i+=2){
        int plus = match[i] - 48;
        if (match[i-1]=='A'){
            pA+=plus;
        }
        if (match[i-1]=='B'){
            pB+=plus;
        }
    }
    // Condicionales para ganar
        // Caso A
    if (pA==11 and pB<10){
        cout << "A"<<endl;
        return 0;
    }
    if (pA>pB and pA-pB>=2){
        cout << "A"<<endl;
        return 0;
    }
        // Caso B
    if (pB==11 and pA<10){
        cout << "B"<<endl;
        return 0;
    }
    if (pB>pA and pB-pA>=2){
        cout << "B"<<endl;
        return 0;
    }
}