#include<iostream>
#include<vector>
#include<map>

template<class T>
void troca_troca(T& a,T& b){
    T aux = a;
    a = b;
    b = aux;
    a[0]->mostrar();
    b[0]->mostrar();
    a[1]->mostrar();
    b[2]->mostrar();
}

struct Pessoa
{
    std::string nome;
    int idade;

    Pessoa(std::string nome = "teste", int idade=1):nome(nome),idade(idade){

    }

    void mostrar(){
        std::cout << this->nome << " " << this->idade<< std::endl;
    }
};


int main(){
    std::map<long,Pessoa> mapa;
    mapa[0] = Pessoa("Juan",13);
    mapa[1] = Pessoa("Juan",13);
    mapa[3] = Pessoa("Juan",13);
    mapa[4] = Pessoa("Juan",13);
    std::vector<Pessoa*> a,b; 

    a.push_back(new Pessoa("Juan",13));
    a.push_back(new Pessoa("Juan2",14));

    b.push_back(new Pessoa("Ryan",13));
    b.push_back(new Pessoa("Ryan",14));
    try{
        troca_troca<std::vector<Pessoa*>>(a,b);
        std::cout << "Deu certo ^-^"<< std::endl;
    }catch(std::out_of_range e){
        std::cout << "Erro, saiu do vetor ;-;"<< std::endl;
    }
}
