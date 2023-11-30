#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Classe{
public:
	//AREA CLIENTE ------------------------------------------------------------------//
	
	static void adicionaCli(string** mat, int idCli);
	static void editaCli(string** mat, int idCli);
	static void removeMatCli(string** mat, int ln, int cl, int idCli);
	static void printaCli(string** mat, int idCli);
	static void printaListaCli(string** mat, int ln, int idCli);
		
	//AREA STOCK ------------------------------------------------------------------//
	static void adicionaPratoStock(string** mat2, int idPrato);
	static void editaStockPrato(string** mat2, int idPrato);
	static void removeMatPrato(string** mat2, int ln2, int cl2, int idPrato);
	static void printaCarta(string** mat2, int ln2, int idPrato);
	static void printaPrato(string** mat2, int idPrato);
	static void printaStockPrato(string** mat2, int ln2, int idPrato);

	//AREA GERAL ------------------------------------------------------------------//
	static void pedido(string** mat, string** mat2, int idPrato, int idCli, int ln, int ln2);
	static void relatorio(string** mat2, int idPrato);
	static void recibo();


private:


};