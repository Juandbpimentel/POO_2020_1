#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>
struct Espiral{
    //atributos
    std::string nome;
    int qtd=0;
    float preco=0.0;
    
    Espiral(std::string nome= "", int qtd=0, float preco=0.00){
        this->nome=nome;
        this->qtd=qtd;
        this->preco=preco;
    }
    std::string toString(){
        std::stringstream saida;
        if(nome==""){
            saida << " [ empty : " << std::to_string(qtd) << " U : " <<  std::to_string(preco) << " RS ]";
            return saida.str();
        }
        saida << " [ " << nome << " : " << std::to_string(qtd) << " U : "<< std::to_string(preco) << " RS ]";
        return saida.str();
    }
};

struct Maquina{
    std::vector<Espiral> espirais;
    float saldoCliente=0;
    float lucro=0;
    int maxProdutos=0;
    int nespirais=0;
    public:
        Maquina(int nespirais, int maxProdutos){
            this->nespirais=nespirais;
            this->maxProdutos=maxProdutos;
            
            for(int i=0; i<=nespirais;i++){
                Espiral *aux=new Espiral();
                espirais.push_back(*aux);
            }
        }
        std::string toString2(){
            std::stringstream saida;
            saida << "Saldo:"<< std::to_string(saldoCliente) << "\n";
            for(int i=0; i<=espirais.size(); i++){
                saida << std::to_string(i) << espirais[i].toString()<<"\n";
            }
            return saida.str();
        }
        float getSaldo(){
            return this->saldoCliente;
        }
        bool alterarEspiral(int indice, std::string nome, int qtd, float preco){
            if(indice < 0 || indice >= (int) espirais.size()){    // -1 < indice < cadeiras.size() também funfa
                std::cout << "fail: indice invalido\n";
                return false;
            }
            //2. Não colocar a pessoa numa cadeira já ocupada
            if(espirais[indice].nome!=""){
                std::cout << "fail: espiral ocupada\n";
                return false;
            }
            //3. Não inserir a pessoa se ela já estiver na sala com o mesmo id
            for(int i=0; i<=espirais.size(); i++){
                if(espirais[i].nome == nome){
                    std::cout << "fail: pessoa ja esta no cinema\n";
                    return false;
                }
            }
            Espiral *aux=new Espiral(nome, qtd, preco);
            espirais[indice] = *aux;
            return true;
        }
};
//+ inserirDinheiro(value: number): boolean
//+ pedirTroco(): float
//+ vender(indice: int): boolean
//+ alterarEspiral(indice: int, nome: String, qtd : int, preco :float) : boolean
//+ getSaldo(): float *
//+ toString() String
int main(){
    Maquina *maquina=new Maquina(4,5);
    //maquina->alterarEspiral(1,"tampico", 2, 3.50);
    std::cout.precision(3);
    std:: cout << maquina->toString2() << "\n";
}