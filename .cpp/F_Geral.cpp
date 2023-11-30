#include "Cabecalho.h"

//-------------------- RELATORIO --------------------//
void Classe::relatorio(string** mat2, int idPrato) {
    int qtd = 0;
    for (int i = 0; i < idPrato; i++){
        qtd = qtd + stod(mat2[i][3]);
    }
    cout << left << qtd << endl;
}



//-------------------- RECIBO --------------------//
void Classe::recibo() {

    cout << left << "PRATO REMOVIDO COM SUCESSO!!" << endl;

    // ----- DATA ----- //
    // Obtendo a data atual
    time_t now;
    time(&now);
    struct tm local_time;
    // Obtendo a data e hora local de forma segura
    localtime_s(&local_time, &now);
    // Formatando a data no formato desejado
    char date_buffer[80];
    strftime(date_buffer, sizeof(date_buffer), "%d/%m/%Y", &local_time);
    // Exibindo a data no console
    cout << "DATA DO RECIBO: " << date_buffer << endl;

}

