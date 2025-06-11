#include <iostream>
using namespace std;


int main(){
  string nome[20] = {}, acimaMedia[20] = {};
  float nota[20], mediaTurma, somaNotas = {};
  int n = 0;

  while(n<=0 || n>20){
  cout <<"insira a quantidade de alunos na turma"<<endl;
  cin >> n;
  	if(n<=0 || n >20){
    	cout << "Tem que ser menor ou igual a 20 porra"<<endl;
  	}
  }

	for(int i = 1;i<=n;i++ ){
		cout <<"Insira o nome dos alunos: \n";
		cin >> nome[i-1];
    	cout << "insira a nota do aluno: \n ";
		cin >> nota[i-1];
		somaNotas += nota[i-1];	
	}

	mediaTurma = somaNotas/n;

	cout<<mediaTurma<<endl;

	for(int i = 0; i<n;i++){
		if(nota[i] > mediaTurma){
			cout<< "Alunos acima da média: "<<endl;
			cout<< "Aluno: "<<nome[i]<<endl;
			cout<< "Nota: "<<nota[i]<<endl;
		}else if(nota[i] < mediaTurma){
			cout<< "Alunos abaixo da média: "<<endl;
			cout<< "Aluno: "<<nome[i]<<endl;
			cout<< "Nota: "<<nota[i]<<endl;
		}else{
			cout<< "Aluno ná merdia :D"<<endl;
		}
	}


}