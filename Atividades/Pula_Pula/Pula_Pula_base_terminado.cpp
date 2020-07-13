#include <vector>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <locale>

using namespace std;

class Kid{
    private:   

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

        Kid(string name, int age):
        name(name),age(age){};
};

class Trampoline{
    private:
        vector<Kid> kidsWaiting;
        vector<Kid> kidsPlaying;
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
        };

        void arrive(Kid kid){
            this->kidsWaiting.push_back(kid);
        }

        void show(){
            cout << endl << this->toString() << endl;
        }

        void in(){
            this->kidsPlaying.push_back(kidsWaiting.at(0));
            cout << ">> " <<kidsWaiting.at(0).getName() << " entrou" << endl;
            this->kidsWaiting.erase(this->kidsWaiting.begin());
        }

        void out(){          
            this->kidsWaiting.push_back(kidsPlaying.at(0));
            cout << ">> " <<kidsPlaying.at(0).getName() << " saiu" << endl;
            this->kidsPlaying.erase(this->kidsPlaying.begin());
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
                Kid aux(nome,idade);
                this->arrive(aux);
                system("cls||clear");
                cout << ">> " << nome << " entrou na fila" << endl;
            }else if(op == "entrar"){
                if(kidsWaiting.size()>0){
                    system("cls||clear");
                    this->in();
                }
                else
                    cout << endl << "Não há ninguém na fila pra entrar no pula-pula" << endl;
                
            }else if(op == "sair"){
                if(kidsPlaying.size()>0){
                    system("cls||clear");
                    this->out();
                }
                else
                    cout << endl << "Não há ninguém dentro do pula-pula" << endl;
            }else if(op == "mostrar"){
                system("cls||clear");
                this->show();
            }else{
                system("cls||clear");
                cout << endl << "operação inválida" << endl;
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

};

int main(){
    Trampoline teste;
    teste.terminal();
    cout << "saindo" << endl;
}