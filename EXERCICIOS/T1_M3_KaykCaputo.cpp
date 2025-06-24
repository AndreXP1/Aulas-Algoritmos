#include <iostream>
#include <iomanip>
using namespace std;

/*
Sistema Simplificado de Controle de Estoque

Objetivo:
Gerenciar até 20 produtos em estoque, cadastrando nome, quantidade e preço.
Permite realizar:
 - Cadastro de produto com nome único
 - Listagem dos produtos cadastrados
 - Entrada e saída de estoque (alteração da quantidade)
 - Busca por produto
 - Relatórios de maior/menor quantidade e valor total (não implementados aqui)

Regras:
 - Nome do produto deve ser uma palavra (sem espaços)
 - Quantidades e preços não podem ser negativos
 - Não é permitido saída maior que estoque atual
*/

string prodName[20]; // Armazena nomes dos produtos
int prodQuant[20];   // Armazena quantidades em estoque dos produtos
float prodPrice[20]; // Armazena preço unitário dos produtos
int prodCount = 0;   // Quantidade de produtos cadastrados atualmente

int opt = 0; // Opção do menu escolhida pelo usuário

string nome;    // Variável auxiliar para armazenar nome de produto temporariamente
int quantidade; // Variável auxiliar para quantidade temporária
float preco;    // Variável auxiliar para preço temporário

int main()
{
    do
    {
        // Limpa a tela
        system("clear");

        cout << "M3 - Kayk Capuyo e André Gustavo" << endl;
        cout << "===============================" << endl;
        cout << "     - SISTEMA DE ESTOQUE -    " << endl;
        cout << "===============================" << endl;
        cout << "|             MENU             |" << endl;
        cout << "-------------------------------" << endl;
        cout << "| 1 - Cadastrar Produto        |" << endl;
        cout << "| 2 - Listar Produtos          |" << endl;
        cout << "| 3 - Entrada no Estoque       |" << endl;
        cout << "| 4 - Saída no Estoque         |" << endl;
        cout << "| 5 - Buscar Produto por Nome  |" << endl;
        cout << "| 6 - Maior/Menor Quantidade   |" << endl;
        cout << "| 7 - Valor Total em Estoque   |" << endl;
        cout << "-------------------------------" << endl;
        cout << "| 8 - Sair                     |" << endl;
        cout << "===============================" << endl;
        cout << "Escolha uma opção: ";
        cin >> opt;
        cout << endl;

        switch (opt)
        {
        case 1:
        {
            // Cadastro de produto
            if (prodCount >= 20)
            {
                cout << "Erro: Limite de produtos atingido!" << endl;
                break;
            }

            cout << "Nome do produto (somente uma palavra): ";
            cin >> nome;

            // Verifica se já existe produto com mesmo nome
            bool duplicado = false;
            for (int i = 0; i < prodCount; i++)
            {
                if (prodName[i] == nome)
                {
                    duplicado = true;
                    break;
                }
            }

            if (duplicado)
            {
                cout << "Erro: Produto com esse nome já cadastrado!" << endl;
                break;
            }

            cout << "Quantidade em estoque: ";
            cin >> quantidade;
            if (quantidade < 0)
            {
                cout << "Erro: Quantidade não pode ser negativa!" << endl;
                break;
            }

            cout << "Preço unitário: ";
            cin >> preco;
            if (preco < 0)
            {
                cout << "Erro: Preço não pode ser negativo!" << endl;
                break;
            }

            // Salva dados nos arrays
            prodName[prodCount] = nome;
            prodQuant[prodCount] = quantidade;
            prodPrice[prodCount] = preco;
            prodCount++;

            cout << "Produto cadastrado com sucesso!" << endl;
            break;
        }

        case 2:
        {
            // Listagem dos produtos cadastrados
            if (prodCount == 0)
            {
                cout << "Erro: Nenhum produto cadastrado ainda." << endl;
                break;
            }

            cout << "Produtos cadastrados:" << endl;
            cout << fixed << setprecision(2);
            for (int i = 0; i < prodCount; i++)
            {
                cout << i + 1 << ". "
                     << "Nome: " << prodName[i]
                     << " | Quantidade: " << prodQuant[i]
                     << " | Preço: R$" << prodPrice[i] << endl;
            }
            break;
        }

        case 3:
        {
            // Entrada no estoque
            if (prodCount == 0)
            {
                cout << "Erro: Nenhum produto cadastrado ainda." << endl;
                break;
            }

            cout << "Insira o nome do produto: ";
            cin >> nome;

            bool existeProduto = false;

            for (int i = 0; i < prodCount; i++)
            {
                if (prodName[i] == nome)
                {
                    existeProduto = true;
                    cout << "Insira a quantidade a ser adicionada: ";
                    cin >> quantidade;

                    if (quantidade < 0)
                    {
                        cout << "Erro: Quantidade não pode ser negativa!" << endl;
                        break;
                    }

                    prodQuant[i] += quantidade;
                    cout << endl
                         << "Entrada cadastrada com sucesso!" << endl;
                    break;
                }
            }

            if (!existeProduto)
            {
                cout << endl
                     << "Erro: Produto não encontrado :(" << endl;
            }

            break;
        }

        case 4:
        {
            // Saída do estoque
            if (prodCount == 0)
            {
                cout << "Nenhum produto cadastrado ainda." << endl;
                break;
            }

            cout << "Insira o nome do produto: ";
            cin >> nome;

            bool existeProduto = false;

            for (int i = 0; i < prodCount; i++)
            {
                if (prodName[i] == nome)
                {
                    existeProduto = true;
                    cout << "Insira a quantidade a ser retirada: ";
                    cin >> quantidade;

                    if (quantidade < 0)
                    {
                        cout << "Erro: Quantidade não pode ser negativa!" << endl;
                        break;
                    }

                    if (quantidade > prodQuant[i])
                    {
                        cout << "Erro: Estoque insuficiente. Estoque atual: " << prodQuant[i] << endl;
                        break;
                    }

                    prodQuant[i] -= quantidade;
                    cout << endl
                         << "Saída cadastrada com sucesso!" << endl;
                    break;
                }
            }

            if (!existeProduto)
            {
                cout << endl
                     << "Produto não encontrado :(" << endl;
            }

            break;
        }

        case 5:
        {
            // Buscar Produto por Nome
            if (prodCount == 0)
            {
                cout << "Erro: Nenhum produto cadastrado ainda." << endl;
                break;
            }

            cout << "Digite o nome do produto para buscar: ";
            cin >> nome;

            bool encontrado = false;
            for (int i = 0; i < prodCount; i++)
            {
                if (prodName[i] == nome)
                {
                    cout << "Produto encontrado!" << endl;
                    cout << fixed << setprecision(2);
                    cout << "Nome: " << prodName[i] << endl;
                    cout << "Quantidade: " << prodQuant[i] << endl;
                    cout << "Preço unitário: R$" << prodPrice[i] << endl;
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado)
            {
                cout << "Produto não cadastrado." << endl;
            }
            break;
        }

        case 6:
        {
            // Maior/Menor Quantidade em Estoque
            if (prodCount == 0)
            {
                cout << "Erro: Nenhum produto cadastrado ainda." << endl;
                break;
            }

            int idxMaior = 0, idxMenor = 0;
            for (int i = 1; i < prodCount; i++)
            {
                if (prodQuant[i] > prodQuant[idxMaior])
                    idxMaior = i;
                if (prodQuant[i] < prodQuant[idxMenor])
                    idxMenor = i;
            }

            cout << "Produto com MAIOR quantidade em estoque:" << endl;
            cout << fixed << setprecision(2);
            cout << "Nome: " << prodName[idxMaior] << endl;
            cout << "Quantidade: " << prodQuant[idxMaior] << endl;
            cout << "Preço unitário: R$" << prodPrice[idxMaior] << endl;

            cout << endl << "Produto com MENOR quantidade em estoque:" << endl;
            cout << fixed << setprecision(2);
            cout << "Nome: " << prodName[idxMenor] << endl;
            cout << "Quantidade: " << prodQuant[idxMenor] << endl;
            cout << "Preço unitário: R$" << prodPrice[idxMenor] << endl;

            break;
        }

        case 7:
        {
            // Valor Total em Estoque
            if (prodCount == 0)
            {
                cout << "Erro: Nenhum produto cadastrado ainda." << endl;
                break;
            }

            float total = 0.0;
            for (int i = 0; i < prodCount; i++)
            {
                total += prodQuant[i] * prodPrice[i];
            }
            cout << fixed << setprecision(2);
            cout << "Valor total em estoque: R$" << total << endl;
            break;
        }
        case 8:
            // Encerrar o programa
            cout << "Encerrando o programa..." << endl;
            break;

        default:
            // Opção inválida no menu
            cout << "Opção inválida. Tente novamente." << endl;
        }

        // Pausa para o usuário ler as mensagens antes de continuar
        if (opt != 8)
        {
            cout << endl
                 << "Pressione Enter para continuar...";
            cin.ignore();
            cin.ignore(); // Dois ignores pois estava ocorrendo a necessidade de pressionar o enter duas vezes
        }

    } while (opt != 8);

    return 0;
}
