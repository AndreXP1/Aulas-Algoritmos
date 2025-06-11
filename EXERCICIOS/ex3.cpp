#include <iostream>
using namespace std;

int main() {
    float num[10] = {};
    int n;
    do
    {
        cout << "Insira um valor de 1 a 10"<<endl;
        cin >> n;
        if(n<1||n>10){
            cout<<"Insira um valor que esteja entre 1 e 10!!"<<endl;
        }

    } while (n<1||n>10);
    
    for(int i=0;i<n;i++){
        cout<<"insira valor"<<endl;
    }
}