#include <iostream>
#include <vector>
using namespace std;

int main()
{
    setlocale(LC_ALL, "portuguese");
    int nums[5];
    int i, impar = 0;
    for(i = 0; i< 5;i++){
        cout << "Digite o "<<i + 1<<"� Valor: "<<endl;
        cin >> nums[i];
        cout << "["<<nums[i]<<"]"<<endl;
        if(nums[i] % 2 !=0){
                impar++;
                cout<<"na posi��o "<<i+1<<endl;
        }
    }
    cout<<"Qntd impar: "<<impar<<endl;
}
