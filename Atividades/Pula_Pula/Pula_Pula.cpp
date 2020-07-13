#include <vector>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <locale>

using namespace std;

class Kid{
    private:   
        int acount;
        string name; 
        int age;
         
        void setName(string value){
            this->name = value;
        }

        void setAge(int value){
            if(age>0){
                this->age = value;
            }
        }

    public:
        string toString(){
            stringstream ss;
            ss << this->name << ":" << this->age;
            return ss.str();
        }
        string getName(){
            return this->name;
        }

        int getAge(){
            return this->age;
        }

        void brincar(){
            this->acount+=1;
        }

        int pedirProPaiPagar(){
            return this->acount;
        }

        Kid(string name, int age, int acount):
        name(name),age(age),acount(acount){};
};

class Trampoline{
    private:
        int lucro;
        int espaco_trampolim;
        vector<Kid> kidsWaiting;
        vector<Kid> kidsPlaying;

        void receberDinheiro(int value){
            this->lucro += value;
        }

        void setEspaco(int espaco){
            this->espaco_trampolim = espaco;
        }

    public:
        string toString(){
            string waiting = "",playing = "", aux;
            
            if(kidsPlaying.size()==0)
                playing = "Vazio ";
            else
                for(int i = kidsPlaying.size()-1; i>=0 ; i--)
                    playing += (kidsPlaying.at(i).toString()+ " ");
            
            
            if(kidsWaiting.size()==0)
                waiting = "Vazio ";
            else
                for(int i = kidsWaiting.size()-1; i>=0 ; i--)

                    waiting += (kidsWaiting.at(i).toString()+ " ");

            aux = "=> " + waiting + "=> " + "[ " + playing + "]";
            return aux;
        }

        int caixa(){
            return this->lucro;
        }

        void arrive(Kid kid){
            this->kidsWaiting.push_back(kid);
        }

        void show(){
            cout << this->toString() << endl;
        }

        void in(){
            if(kidsPlaying.size() < espaco_trampolim){
                kidsWaiting.at(0).brincar();

                this->kidsPlaying.push_back(kidsWaiting.at(0));

                cout << ">> " <<kidsWaiting.at(0).getName() << " entrou" << endl;
                this->kidsWaiting.erase(this->kidsWaiting.begin());
                return ;
            }else{
                cout << "O trampolim já chegou em sua capacidade máxima " << endl;
            }
            
        }

        void out(){          
            this->kidsWaiting.push_back(kidsPlaying.at(0));

            cout << ">> " <<kidsPlaying.at(0).getName() << " saiu" << endl;
            this->kidsPlaying.erase(this->kidsPlaying.begin());
        }

        void papaiBuscou(string nome){
            bool achou = false;

            for(int i = 0; i<kidsPlaying.size(); i++)
                if(kidsPlaying.at(i).getName() == nome){
                    achou = true;
                    
                    this->receberDinheiro(kidsPlaying.at(i).pedirProPaiPagar());

                    cout << "Tchau " << nome << endl;
                    this->kidsPlaying.erase(this->kidsPlaying.begin()+i);
                    break;
                }

            if(!achou)
                for(int i = 0; i<kidsWaiting.size(); i++)
                    if(kidsWaiting.at(i).getName() == nome){
                        achou = true;
                        
                        this->receberDinheiro(kidsWaiting.at(i).pedirProPaiPagar());

                        cout << "Tchau " << nome << endl;
                        this->kidsWaiting.erase(this->kidsWaiting.begin()+i);
                        break;
                    }
            if(!achou)
                cout << "Mano, seu filho não tá aqui, é melhor chamar a polícia e procurar ele °-°" << endl;
        }

        int saldoCrianca(string nome){
            for(int i = 0; i<kidsPlaying.size(); i++)
                if(kidsPlaying.at(i).getName() == nome)
                    return kidsPlaying.at(i).pedirProPaiPagar();
            for(int i = 0; i<kidsWaiting.size(); i++)
                if(kidsWaiting.at(i).getName() == nome)
                    return kidsWaiting.at(i).pedirProPaiPagar();
            return -1;
        }

        void fecharPulaPula(){
            while(kidsWaiting.size()>0){
                    this->receberDinheiro(kidsWaiting.at(0).pedirProPaiPagar());
                    this->kidsWaiting.erase(this->kidsWaiting.begin());
                }
            while(kidsPlaying.size()>0){
                this->receberDinheiro(kidsPlaying.at(0).pedirProPaiPagar());
                this->kidsPlaying.erase(this->kidsPlaying.begin());
            }
            cout << "Todas as crianças foram tiradas do brinquedo" << endl;
        }

        void opcoes(string line){

            stringstream opc(line);
            string op;
            opc >> op;

            if(op == "chegou"){
                string nome = "Mininx";
                int idade = 0;

                opc >> nome >> idade;

                if(idade <= 0)
                    idade = 1;   

                Kid aux(nome,idade,0);
                this->arrive(aux);

                system("cls||clear");
                cout << ">> " << nome << " entrou na fila" << endl;
            
            }else if(op == "entrar"){
                if(kidsWaiting.size()>0){
                    system("cls||clear");
                    this->in();
                }else{
                    system("cls||clear");
                    cout << "Não há ninguém na fila pra entrar no pula-pula" << endl;
                }
            
            }else if(op == "sair"){
                
                if(kidsPlaying.size()>0){
                    system("cls||clear");
                    this->out();
                }else{
                    system("cls||clear");
                    cout << "Não há ninguém dentro do pula-pula" << endl;
                }
                
            }else if(op == "buscar"){
                system("cls||clear");
                string nome = "Mininx";
                int idade = 0;

                opc >> nome;
                this->papaiBuscou(nome);

            }else if(op == "mostrar"){
                system("cls||clear");
                this->show();
            
            }else if(op == "caixa"){
                system("cls||clear");
                cout << "Caixa do dia :" << this->caixa() << endl;
            
            }else if(op == "fechar"){
                system("cls||clear");
                this->fecharPulaPula();
            
            }else if(op == "saldo"){
                system("cls||clear");

                string nome = "Mininx";
                int valor;

                opc >> nome;

                valor = saldoCrianca(nome);

                if(valor == -1)
                    cout << "Essa criança não está no brinquedo" << endl;
                else
                cout << "O saldo do "<< nome << " é de: " << valor << " R$" << endl;

            }else if(op == "init"){
                int espaco;
                opc >> espaco;
                while(kidsPlaying.size()>0){
                    this->out();
                }
                this->setEspaco(espaco);
                system("cls||clear");
                cout << "O Pula pula antigo foi vendido e o novo chegou " << endl;
            
            }else{
                system("cls||clear");
                cout << "operação inválida" << endl;
            }
        };

        void terminal(){
            string line;
                while(true){
                    getline(cin,line);
                    cout << endl;
                    if(line == "end"){
                        system("cls||clear");
                        break;
                    }
                    opcoes(line);
                }
        }

        Trampoline(int lucro, int espaco_trampolim):
        lucro(lucro), espaco_trampolim(espaco_trampolim){}

};

int main(){
    Trampoline teste(0,5);
    teste.terminal();
    cout << "saindo" << endl;
}