#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;
class Operacao{
private:
    int indice;
    string descricao;
    float valor;
    float saldo;

public:
    Operacao(int indice = 0, string descricao = "", float valor = 0, float saldo = 0):
    indice(indice),descricao(descricao),valor(valor),saldo(saldo){};
};

class Conta{
private:
    int nextId;//id da próxima operaçao
    float saldo; 
    int numero;
    vector<Operacao> Estrato;
public: 
    Conta(int nextId, float saldo):nextId(nextId),saldo(saldo){
        srand((unsigned)time(0));
        this->numero = rand();
    };
    bool salvarOperacao(string label, float value, float saldo){

    } // usado para alterar saldo e extrato
    bool debitar(string label, float value){

    } //usado para saque e tarifa
    bool creditar(string label, float value){

    } // usado para extorno e depósito 
    vector<Operacao> getExtratoN(){

    } //retorna as última n operacoes
};