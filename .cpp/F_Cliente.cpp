#include "Cabecalho.h"

//-------------------- ADICIONA --------------------//
void Classe::adicionaCli(string** mat, int idCli) {
    cout << left << "--- REGISTRAR CLIENTE ---" << endl;
    //ID
    mat[idCli][0] = to_string(idCli + 1);
    cout << "ID CLIENTE: " << mat[idCli][0] << endl;
    //Nome
    cout << "NOME: ";
    cin.ignore();
    getline(cin, mat[idCli][1]);
    //Telefone
    cout << "TELEMOVEL: ";
    cin >> (mat[idCli][2]);
    //Endereco
    cout << "ENDERECO: ";
    cin.ignore();
    getline(cin, mat[idCli][3]);
}
//-------------------- PEDIDO --------------------//
void Classe::pedido(string** mat, string** mat2, int idPrato, int idCli, int ln, int ln2) {
    int qtdPedido;
    double soma = 0;

    //CLIENTE
    do{
        cout << left << "ID DO CLIENTE: ";
        cin >> idCli;
    } while (idCli != stoi(mat[idCli - 1][0]));

    //QTD PEDIDO
    cout << left << "QUANTIDADE DE PEDIDO: ";
    cin >> qtdPedido;

    //PRATO
    int* vec = new int[qtdPedido];
    Classe::printaCarta(mat2, ln2, idPrato);
    cout << left << "-------- PEDIDOS --------" << endl;
    for (int i = 0; i < qtdPedido; i++) {
        cout << left << "ID DO PEDIDO: ";
        cin >> idPrato;
        vec[i] = idPrato - 1;
        soma = soma + stod(mat2[idPrato - 1][6]);
    }

    system("cls");
    cout << left << "--- PEDIDO DO CLIENTE ---" << endl;
    for (int i = 0; i < qtdPedido; i++) {
        cout << left << "ID PRATO: " << mat2[vec[i]][0] << endl;
        cout << left << "NOME PRATO: " << mat2[vec[i]][1] << endl;
        cout << left << "QUANTIDADE: " << mat2[vec[i]][3] << endl;
        cout << left << "VALOR: " << mat2[vec[i]][4] << mat2[i][5] << endl;
        cout << endl;
    }
    cout << left << "ID CLIENTE: " << idCli << endl;
    cout << left << "NUMERO DE PEDIDOS: " << qtdPedido << endl;
    cout << left << "TOTAL: " << soma << mat2[idPrato - 1][7] << endl;
}
//-------------------- EDITA --------------------//
void Classe::editaCli(string** mat, int idCli) {
    int rpCl;
    cout << left << "----- EDITA CLIENTE -----" << endl;
    cout << left << "ID DO CLIENTE A SER EDITADO: ";
    cin >> idCli;
    cout << endl;

    for (int i = 0; i < idCli; i++) {//Posicao da linhas
        if (stoi(mat[i][0]) == idCli) {
            system("cls");
            do {
                cout << left << "----- DADOS CLIENTE -----" << endl;
                cout << left << "1. NOME" << endl;
                cout << left << "2. TELEMOVEL" << endl;
                cout << left << "3. ENDERECO" << endl;
                cout << left << "4. TODOS" << endl;
                cin >> rpCl;
                system("cls");
            } while (rpCl < 1 || rpCl > 4);
            switch (rpCl) {
                case 1: {
                    cout << left << "------ EDITAR NOME ------" << endl;
                    cout << left << "NOVO NOME: ";
                    cin.ignore();
                    getline(cin, mat[idCli - 1][1]);
                    break;
                }
                case 2: {
                    cout << left << "---- EDITA TELEMOVEL ----" << endl;
                    cout << left << "NOVO TELEMOVEL: ";
                    cin >> mat[idCli - 1][2];
                    break;
                }
                case 3: {
                    cout << left << "---- EDITAR ENDERECO ----" << endl;
                    cout << left << "NOVO ENDERECO: ";
                    cin.ignore();
                    getline(cin, mat[idCli - 1][3]);
                    break;
                }
                case 4: {
                    cout << left << "----- EDITA CLIENTE -----" << endl;
                    cout << left << "NOVO NOME: ";
                    cin.ignore();
                    getline(cin, mat[idCli - 1][1]);
                    cout << left << "NOVO TELEMOVEL: ";
                    cin >> mat[idCli - 1][2];
                    cout << left << "NOVO ENDERECO: ";
                    cin.ignore();
                    getline(cin, mat[idCli - 1][3]);
                    break;
                }
            }
        }
    }
}
//-------------------- LIMPAR E REMOVE MATRIZ CLIENTE --------------------//
void Classe::removeMatCli(string** mat, int ln, int cl, int idCli) {
    cout << left << "---- REMOVER CLIENTE ----" << endl;
    cout << left << "ID DO CLIENTE: ";
    cin >> idCli;

    if (idCli >= 1 && idCli <= ln) {
        for (int j = 0; j < cl; j++) {
            mat[idCli - 1][j] = "";
        }
        
        for (int i = idCli - 1; i < ln - 1; i++) {
            for (int j = 0; j < cl; j++) {
                mat[i][j] = mat[i + 1][j];
            }
        }
        ln--;
    }
}
//-------------------- PRINTS --------------------//
void Classe::printaCli(string** mat, int idCli) {
    system("cls");
    cout << left << "-------- CLIENTE --------" << endl;
    cout << left << "ID: " << mat[idCli - 1][0] << endl;
    cout << left << "NOME: " << mat[idCli - 1][1] << endl;
    cout << left << "TELEMOVEL: " << mat[idCli - 1][2] << endl;
    cout << left << "ENDERECO: " << mat[idCli - 1][3] << endl;
    cout << endl;
}
void Classe::printaListaCli(string** mat, int ln , int idCli) {
    system("cls");
    cout << left << "----- LISTA CLIENTE -----" << endl;
    for (int i = 0; i < idCli; i++) {
        if (idCli > 0 || idCli < ln) {
            cout << left << "ID: " << mat[i][0] << endl;
            cout << left << "NOME: " << mat[i][1] << endl;
            cout << left << "TELEMOVEL: " << mat[i][2] << endl;
            cout << left << "ENDERECO: " << mat[i][3] << endl;
            cout << endl;
        }
    }
}
//---------------------------------------------------------------------------//