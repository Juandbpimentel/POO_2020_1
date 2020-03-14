#include<iostream>
#include<sstream>
using namespace std;

struct Pessoa
{
    string nome;
    int idade;

    Pessoa(string nome ="",int idade =-1){
        this->nome = nome;
        this->idade = idade;
        cout << this->nome << " está nascendo\n";
    }

    ~Pessoa(){
        cout << this->nome << " está morrendo\n";
    }
};

struct Motoca
{
    int potencia;
    Pessoa * passageiro {nullptr};
    int minutos;

    Motoca( int potencia = 1, int minutos = 0, Pessoa * passageiro = nullptr){
        this->potencia = potencia;
        this->minutos = minutos;
        this->passageiro = passageiro;
    }

    void subir( Pessoa * passageiro ){
        if(this->passageiro != nullptr)
            cout << "já tem gente na motoca\n";
        this->passageiro = passageiro;
    }

    Pessoa * descer(){
        if(this->passageiro == nullptr){
            cout << "A motoca já está vazia\n";
            return nullptr;
        }
        Pessoa * temp = this->passageiro;
        this->passageiro = nullptr;
        this->minutos = 0;
        return temp;
    }

    void dirigir(){
        if( this->passageiro == nullptr){
            cout << "Não tem ninguém para dirigir a motoca\n";
            return;
        }else if(this->passageiro->idade >= 4){
            if(this->minutos > 0){
                cout <<"Passageiro " << this->passageiro->nome << ": Eita caracaaaaaaaa, partiu bora dar uma voltinha mermão ^-^\n";
                cout << "Motor da moto: ";
                for (size_t i = 0; i < this->potencia ; i++)
                    cout << " vrum";
                cout << "\n";
                this->minutos --;
            }else{
                cout << "O tempo da voltinha acabou, compre tempo ou saia da moto\n";
                return;
            }
        }else
            cout << this->passageiro->nome <<"O passageiro não sabe andar de motoca ainda\n";
    }

    void comprarTempo(int value){
        if(this->passageiro != nullptr){
            this->minutos += value;
        }else
        {
            cout << "Não há ninguém na motoca para dar uma voltinha\n";
            return;
        }

    }

    void buzinar(){
        if(this->passageiro != nullptr){
            cout << "P";
            for (size_t i = 0; i < this->potencia ; i++)
                cout << "e";
            cout << "m\n";
        }else
            cout << "Não há ninguém na motoca para buzinar\n";
    }
};

void help(){
    cout << "subir <String nome> <Int idade>\n"
    << "dirigir\n"
    << "descer\n"
    << "comprarTempo <int tempo>\n"
    << "buzinar\n"
    << "show\n"
    << "init <Int potência>\n"
    << "help\n";
}

void show(Motoca motoca){
            cout << "| Potência: " << motoca.potencia
                 << " | Minutos: " << motoca.minutos;
            if(motoca.passageiro != nullptr){
                cout <<" | Passageiro( Nome: "<< motoca.passageiro->nome\
                <<" | Idade: "<< motoca.passageiro->idade << " )";
            }else{
                cout << " | Passageiro( null )";
            }
            cout << " |\n";
}

int main(){
    Motoca motoca;
    while(true){
        string line;
        cout << "$";
        getline(cin, line);
        stringstream ss(line);
        cout << "..." << line << "\n";
        string cmd;
        ss >> cmd;
        if(cmd == "end"){
            break;
        }else if(cmd == "help"){
            help();
        }else if(cmd == "init"){
            int newPotencia = 0;
            ss >> newPotencia;
            motoca = Motoca(newPotencia);
        }else if (cmd == "subir")
        {
            string nome;
            int idade = 0;
            ss >> nome >> idade;
            motoca.subir(new Pessoa(nome,idade));
        }else if(cmd == "dirigir"){
            motoca.dirigir();
        }else if (cmd == "descer"){
            Pessoa * temp = motoca.descer();
            if(temp != nullptr){
                delete temp;
            }
        }else if (cmd == "comprarTempo"){
            int tempo = 0;
            ss >> tempo;
            motoca.comprarTempo(tempo);
        }else if(cmd == "buzinar"){
            motoca.buzinar();
        }else if(cmd == "show"){
            show(motoca);
        }else{
            cout << "comando inválido\n";
        }

    }
};
