#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


//exercicio 4
int main() {
    float v[15] = {}, maior;
    float menor = 100;

    srand(time(0));

    for(int i = 0;i<15;i++){
        v[i] = rand() % 101;
    }

    for(int i = 0;i<15;i++){
        if(v[i] < menor){
            menor = v[i];
        }else if(v[i] > maior){
            maior = v[i];
        }
    }

    cout<<"menor numeor é: "<<menor<<endl;
    cout<<"mairo nuemroé : "<<maior<<endl;
}