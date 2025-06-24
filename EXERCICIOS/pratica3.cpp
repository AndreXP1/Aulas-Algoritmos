#include <iostream>
using namespace std;

int main() {
    int matM[4][4];
    int terceiraLinha = 1, maiorValor = 0;
    int soma = 0;
    srand(time(0));
    
    for(int i = 0;i<4;i++){
        for(int j =0;j<4;j++){
            matM[i][j] = rand() % 10;
        }
    }

    for(int i = 0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<"["<<matM[i][j]<<"]";
            if(i == j){
                soma += matM[i][j];
            }if(i==2){
                terceiraLinha *= matM[i][j];
            }if(j == 1){
                if(matM[i][j] > maiorValor){
                    maiorValor = matM[i][j];
                    }
                }
            }
            cout<<endl;
        }
    cout<<"soma diagonal principal: "<<soma<<endl;
    cout<<"multiplicação 3º linha: "<<terceiraLinha<<endl;
    cout<<"maior valor segunda coluna: "<<maiorValor<<endl;
}
