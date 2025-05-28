#include <iostream>
using namespace std;

int main(){
    setlocale(LC_ALL, "portuguese");

    string alunos[4];
    float n1, n2, media;


    for(int i = 0; i<4;i++){
        cout<<"Digite o nome do aluno: "<<endl;
        cin >> alunos[i];
        cout<<"["<<alunos[i]<<"]"<<endl;
    }
}
