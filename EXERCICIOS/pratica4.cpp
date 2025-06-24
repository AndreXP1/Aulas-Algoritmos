#include <iostream>
using namespace std;

int main() {
    int matM[4][4];
    int opcao;
    srand(time(0));
    
    for(int i = 0;i<4;i++){
        for(int j =0;j<4;j++){
            matM[i][j] = rand() % 10;
        }
    }

    do{
        cout<<endl;
        cout<<"escolha uma opção abaixo: "<<endl;
        cout<<"1- Mostrar matriz preenchida"<<endl;
        cout<<"2- Diagonal principal"<<endl;
        cout<<"3- Triângulo superior"<<endl;
        cout<<"4- Triângulo inferior"<<endl;
        cout<<"5- Sair"<<endl;
        cin >> opcao;
        switch (opcao){
            case 1:
            for (int i = 0; i < 4; i++){
                for(int j=0;j<4;j++){
                    cout<<"[ "<<matM[i][j]<<" ]";
                }
                cout<<endl;
            }
            break;
            case 2:
            for (int i = 0; i < 4; i++){
                cout<<endl;
                for(int j=0;j<4;j++){
                    if(i == j){
                        cout<<"["<<matM[i][j]<<"]";
                    }else{
                        cout<<"[ ]";
                    }
                }
            }
            break;
            case 3:
            for (int i = 0; i < 4; i++){
                cout<<endl;
                for(int j=0;j<4;j++){
                    if(i<j){
                        cout<<"["<<matM[i][j]<<"]";
                    }else{
                        cout<<"[ ]";
                    }
                }
            }
            break;
            case 4:
            for (int i = 0; i < 4; i++){
                cout<<endl;
                for(int j=0;j<4;j++){
                    if(i>j){
                        cout<<"["<<matM[i][j]<<"]";
                    }else{
                        cout<<"[ ]";
                    }
                }
            }
            break;
        }
    }while(opcao !=5||opcao<1||opcao>5);
}