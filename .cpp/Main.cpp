#include "Cabecalho.h"

int main() {
	//MATRIZ - 1
	int ln = 100, cl = 4;
	string** mat = new string * [ln];
	for (int i = 0; i < ln; i++) {
		mat[i] = new string[cl];
	}
	//MATRIZ - 2
	int ln2 = 100, cl2 = 8;
	string** mat2 = new string * [ln];
	for (int i = 0; i < ln; i++) {
		mat2[i] = new string[cl2];
	}
	//Variaveis
	bool verifica = false;
	int rpMenu, idCli = 0, idPrato = 0, soma = 100, id = 0;

	//INICIO DO PROGRAMA
	do {
		do{
			cout << "--- MENU GERAL RESTAURANTE ---" << endl;
			cout << "1. MENU DOS CLIENTES" << endl;
			cout << "2. MENU DOS STOCKS" << endl;
			cout << "3. MENU DOS RELATORIOS" << endl;
			cout << "4. SAIR " << endl;
			cout << "OPCAO: ";
			cin >> rpMenu;
			system("cls");
		} while (rpMenu < 1 || rpMenu > 4);

		switch (rpMenu) {
			// ----- CLIENTE ----- //
			case 1: {
				int rpCliente;
				do {
					cout << "-------- MENU CLIENTE --------" << endl;
					cout << "1. PEDIDO DO CLIENTE" << endl;
					cout << "2. RESGISTRAR CLIENTES" << endl;
					cout << "3. EDITAR CLIENTES" << endl;
					cout << "4. REMOVER CLIENTES" << endl;
					cout << "5. MOSTRAR CLIENTES" << endl;
					cout << "6. SAIR" << endl;
					cout << "OPCAO: ";
					cin >> rpCliente;
					system("cls");
				} while (rpCliente < 1 || rpCliente > 6);

				switch (rpCliente) {
					//PEDIDO DO CLIENTE
					case 1: {
						Classe::pedido(mat, mat2, idPrato, idCli, ln, ln2);
						system("pause");
						system("cls");
						break;
					}
					//REGISTRO DO CLIENTE
					case 2: {
						Classe::adicionaCli(mat, idCli);
						idCli++;
						Classe::printaCli(mat, idCli);
						cout << left << "CLIENTE ADICIONADO COM SUCESSO!!" << endl;
						system("pause");
						system("cls");
						break;
					}
					//EDITAR CLIENTE
					case 3: {
						Classe::editaCli(mat, idCli);
						Classe::printaCli(mat, idCli);
						cout << left << "CLIENTE EDITADO COM SUCESSO!!" << endl;
						system("pause");
						system("cls");
						break;
					}
					//REMOVER CLIENTE
					case 4: {
						Classe::removeMatCli(mat, ln, cl, idCli);
						idCli--;
						cout << left << "CLIENTE REMOVIDO COM SUCESSO!!" << endl;
						system("pause");
						system("cls");
						break;
					}
					//MOSTRAR CLIENTE
					case 5: {
						Classe::printaListaCli(mat, ln, idCli);
						system("pause");
						system("cls");
						break;
					}
					//SAIR
					case 6: {
						system("cls");
						break;
					}
				}
				break;
			}
			// ----- STOCK ----- //
			case 2: {
				int rpStock;
				do {
					cout << "--------- MENU STOCK ---------" << endl;
					cout << "1. REGISTRAR PRATO" << endl;
					cout << "2. EDITAR PRATO" << endl;
					cout << "3. REMOVER PRATO" << endl;
					cout << "4. MOSTRAR PRATOS" << endl;
					cout << "5. SAIR" << endl;
					cout << "OPCAO: ";
					cin >> rpStock;
					system("cls");
				} while (rpStock < 1 || rpStock > 5);

				switch (rpStock) {
					//REGISTRO DO STOCK
					case 1: {
						Classe::adicionaPratoStock(mat2, idPrato);
						idPrato++;
						Classe::printaPrato(mat2, idPrato);
						cout << left << "PRATO ADICIONADO COM SUCESSO!!" << endl;
						system("pause");
						system("cls");
						break;
					}
					//EDITAR STOCK
					case 2: {
						Classe::editaStockPrato(mat2, idPrato);
						Classe::printaPrato(mat2, idPrato);
						cout << left << "PRATO EDITADO COM SUCESSO!!" << endl;
						system("pause");
						system("cls");
						break;
					}
					//REMOVER STOCK
					case 3: {
						Classe::removeMatPrato(mat2, ln2, cl2, idPrato);
						idPrato--;
						cout << left << "PRATO REMOVIDO COM SUCESSO!!" << endl;
						system("pause");
						system("cls");	
						break;
					}
					//MOSTRAR STOCK
					case 4: {
						Classe::printaStockPrato(mat2, ln2, idPrato);
						system("pause");
						system("cls");
						break;
					}
					//SAIR
					case 5: {
						system("cls");
						break;
					}
				break;
				}
			break;
			}
			// ----- RELATORIO ----- //
			case 3: {
				int rpRelatorios;
				do {
					cout << "------- MENU RELATORIO -------" << endl;
					cout << "1. RELATORIO" << endl;
					cout << "2. RECIBO" << endl;
					cout << "3. SAIR" << endl;
					cout << "OPCAO: ";
					cin >> rpRelatorios;
					system("cls");
				} while (rpRelatorios < 1 || rpRelatorios > 3);

				switch (rpRelatorios) {
					//RELATORIO
					case 1: {
						Classe::relatorio(mat2, idPrato);
						system("pause");
						system("cls");
						break;
					}
					//RECIBO
					case 2: {
						Classe::recibo();
						system("pause");
						system("cls");
						break;
					}
					//SAIR
					case 3: {
						system("cls");
						break;
					}
				}
				break;
			}
			// ----- FECHA SISTEMA ----- //
			case 4: {
				exit(0);
				break;
			}
		}
	}while (verifica == false);
}