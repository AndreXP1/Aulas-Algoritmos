#include <iostream>
using namespace std;

int main() {
    int matM[3][3];
    int impar = 0;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout <<"digite os valores de lina e coluna"<<endl;
            cin >> matM[i][j];
        }
        
    }

    for(int i=0; i<3;i++){
        for(int j=0;j<3;j++){
            if(matM[i][j]%2 != 0){
                cout <<"[*"<<matM[i][j]<<"]";
                impar += 1;
            }else{
                cout<<"["<<matM[i][j]<<"]";
            }   
        }
        cout<<endl;
    }
    return 0;
}