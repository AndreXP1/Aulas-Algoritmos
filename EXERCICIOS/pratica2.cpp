#include <iostream>
using namespace std;

int main() {
    int ordem;

    cout<<"Digite a ordem da matriz entre 2 e 6: "<<endl;
    cin >> ordem;
    if(ordem >6 || ordem<2){
        cout<<"digite um valor de ordem valido";
    }else{
        int matM[ordem][ordem];


        for (int i = 0; i < ordem; i++){
            for(int j = 0; j< ordem;j++){
                if(i != j){
                    matM[i][j] = 0;
                }else{
                    matM[i][j] = 1;
                }
                cout<<"["<<matM[i][j]<<"]";
            }
            cout<<endl;
        }
        
        while (true) {
            int opcao;
            cout << "\nEscolha uma opção:\n";
            cout << "1 - Imprimir matriz completa\n";
            cout << "2 - Imprimir triângulo superior\n";
            cout << "3 - Imprimir triângulo inferior\n";
            cout << "0 - Sair\n";
            cin >> opcao;

            if (opcao == 0) break;

            switch (opcao) {
                case 1: // Matriz completa
                    for (int i = 0; i < ordem; i++) {
                        for (int j = 0; j < ordem; j++) {
                            cout << "[" << matM[i][j] << "]";
                        }
                        cout << endl;
                    }
                    break;

                case 2: // Triângulo superior
                    for (int i = 0; i < ordem; i++) {
                        for (int j = 0; j < ordem; j++) {
                            if (j > i) {
                                cout << "[" << matM[i][j] << "]";
                            } else {
                                cout << "[]";
                            }
                        }
                        cout << endl;
                    }
                    break;

                case 3: // Triângulo inferior
                    for (int i = 0; i < ordem; i++) {
                        for (int j = 0; j < ordem; j++) {
                            if (i > j) {
                                cout << "[" << matM[i][j] << "]";
                            } else {
                                cout << "[]";
                            }
                        }
                        cout << endl;
                    }
                    break;

                default:
                    cout << "Opção inválida!\n";
            }
        }
    }
    
}