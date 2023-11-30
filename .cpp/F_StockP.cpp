#include "Cabecalho.h"

//-------------------- ADICIONA --------------------//
void Classe::adicionaPratoStock(string** mat2, int idPrato) {
    cout << left << "---- REGISTRAR PRATO ----" << endl;
    //ID
    mat2[idPrato][0] = to_string(idPrato + 1);
    cout << "ID PRATO: " << mat2[idPrato][0] << endl;

    //Nome
    cout << "NOME: ";
    cin.ignore();
    getline(cin, mat2[idPrato][1]);

    // Validade
    int dia = rand() % 31 + 1;
    int mes = rand() % 12 + 1;
    int ano = rand() % 10 + 2023; // Gerando um ano aleatório entre 2023 e 2032
    mat2[idPrato][2] = to_string(dia) + "/" + to_string(mes) + "/" + to_string(ano);

    //Quantidade
    int quantidade = rand() % 100 + 1;
    mat2[idPrato][3] = to_string(quantidade);

    // Preço (gerando valor aleatório entre 1.00 e 100.00)
    double preco = rand() % 10000 + 100;
    preco /= 100; // Convertendo para um número decimal com 2 casas decimais
    mat2[idPrato][4] = to_string(preco);
    mat2[idPrato][5] = 36;

    // Preço + IVA
    double precoComIVA = preco * 0.30 + preco;
    mat2[idPrato][6] = to_string(precoComIVA);
    mat2[idPrato][7] = 36;
}
//-------------------- EDITA --------------------//
void Classe::editaStockPrato(string** mat2, int idPrato) {
    int rpStcP; double preco;
    cout << left << "------ EDITA STOCK ------" << endl;
    cout << left << "ID DO PRATO A SER EDITADO: ";
    cin >> idPrato;
    cout << endl;

    for (int i = 0; i < idPrato; i++) {
        if (stoi(mat2[i][0]) == idPrato) {
            do {
                cout << left << "------ DADOS PRATO ------" << endl;
                cout << left << "1. NOME" << endl;
                cout << left << "2. VALIDADE" << endl;
                cout << left << "3. QUANTIA" << endl;
                cout << left << "4. PRECO" << endl;
                cout << left << "5. TODOS" << endl;
                cin >> rpStcP;
                system("cls");
            } while (rpStcP < 1 || rpStcP > 5);

            switch (rpStcP) {
                case 1: {
                    cout << left << "------ EDITAR NOME ------" << endl;
                    cout << "NOVO NOME: ";
                    cin.ignore();
                    getline(cin, mat2[idPrato - 1][1]);
                    break;
                }
                case 2: {
                    cout << left << "---- EDITAR VALIDADE ----" << endl;
                    //VALIDADE
                    cout << "NOVA VALIDADE: ";
                    cin.ignore();
                    getline(cin, mat2[idPrato - 1][2]);
                    break;
                }
                case 3: {
                    cout << left << "----- EDITA QUANTIA -----" << endl;
                    //QUANTIA
                    cout << "NOVA QUANTIA: ";
                    cin >> mat2[idPrato - 1][3];
                    break;
                }
                case 4: {
                    cout << left << "------ EDITA PRECO ------" << endl;
                    //PRECO
                    cout << "NOVO PRECO: ";
                    cin >> preco;
                    mat2[idPrato - 1][4] = to_string(preco);
                    // Preço + IVA
                    double precoComIVA = preco * 1.30;
                    mat2[idPrato - 1][6] = to_string(precoComIVA);
                    break;
                }
                case 5: {
                    cout << left << "------ EDITA PRATO ------" << endl;
                    //NOME
                    cout << "NOVO NOME: ";
                    cin.ignore();
                    getline(cin, mat2[idPrato - 1][1]);
                    //VALIDADE
                    cout << "NOVA VALIDADE: ";
                    cin.ignore();
                    getline(cin, mat2[idPrato - 1][2]);
                    //QUANTIA
                    cout << "NOVA QUANTIA: ";
                    cin >> mat2[idPrato - 1][3];
                    //PRECO
                    cout << "NOVO PRECO: ";
                    cin >> preco;
                    mat2[idPrato - 1][4] = to_string(preco);
                    // Preço + IVA
                    double precoComIVA = preco * 1.30;
                    mat2[idPrato - 1][6] = to_string(precoComIVA);
                    break;
                }

            }
        }
    }
}
//-------------------- LIMPAR E REMOVE MATRIZ PRATO --------------------//
void Classe::removeMatPrato(string** mat2, int ln2, int cl2, int idPrato) {
    cout << "ID DO PRATO  : ";
    cin >> idPrato;

    if (idPrato >= 1 && idPrato <= ln2) {
        for (int j = 0; j < cl2; j++) {
            mat2[idPrato - 1][j] = "";
        }

        for (int i = idPrato - 1; i < ln2 - 1; i++) {
            for (int j = 0; j < cl2; j++) {
                mat2[i][j] = mat2[i + 1][j];
            }
        }
        ln2--;
    }
}
//-------------------- PRINTS --------------------//
void Classe::printaPrato(string** mat2, int idPrato) {
    system("cls");
    cout << left << "--------- PRATO ---------" << endl;
    cout << left << "ID: " << mat2[idPrato - 1][0] << endl;
    cout << left << "NOME: " << mat2[idPrato - 1][1] << endl;
    cout << left << "VALIDADE: " << mat2[idPrato - 1][2] << endl;
    cout << left << "QUANTIA: " << mat2[idPrato - 1][3] << endl;
    cout << left << "PRECO: " << mat2[idPrato - 1][4] << mat2[idPrato - 1][5] << endl;
    cout << left << "PRECO(IVA): " << mat2[idPrato - 1][6] << mat2[idPrato - 1][7] << endl;
    cout << endl;
}

void Classe::printaStockPrato(string** mat2, int ln2, int idPrato) {
    system("cls");
    cout << left << "------ LISTA PRATO ------" << endl;
    for (int i = 0; i < idPrato; i++) {
        if (idPrato > 0 || idPrato < ln2) {
            cout << left << " ID PRATO: " << mat2[i][0] << endl;
            cout << left << " NOME: " << mat2[i][1] << endl;
            cout << left << " VALIDADE: " << mat2[i][2] << endl;
            cout << left << " QUANTIA: " << mat2[i][3] << endl;
            cout << left << " PRECO: " << mat2[i][4] << mat2[i][5] << endl;
            cout << left << " PRECO(IVA): " << mat2[i][6] << mat2[i][7] << endl;
            cout << endl;
        }
    }
}
void Classe::printaCarta(string** mat2, int ln2, int idPrato) {
    system("cls");
    cout << left << "--------- CARTA ---------" << endl;
    for (int i = 0; i < idPrato; i++) {
        if (idPrato > 0 || idPrato < ln2) {
            cout << left << " ID PRATO: " << mat2[i][0] << endl;
            cout << left << " NOME: " << mat2[i][1] << endl;
            cout << left << " QUANTIA: " << mat2[i][3] << endl;
            cout << left << " PRECO(IVA): " << mat2[i][6] << mat2[i][7] << endl;
            cout << endl;
        }
    }
}
//------------------------------------------------//