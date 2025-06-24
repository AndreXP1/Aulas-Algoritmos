#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "portuguese");

    int matM[3][2];

    for(int l = 0; l<3; l++){
        for(int c =0; c<2;c++){
            cout<<"Digite o valor da linha e da coluna: "<<endl;
            cin >> matM[l][c];
        }
    }

    for(int l =0;l<3;l++){
        for(int c=0;c<2;c++){
            cout<<"["<<matM[l][c]<<"]";
        }
        cout<<endl;
    }
    return 0;
}