#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Numero{
public:
    string id;
    string number;
    int index;

    Numero(int index = 0, string id = "",string number = ""):
    index(index),id(id),number(number){}

    static bool validar(string number){
        string valid = "0123456789()-. ";
        for(char c : number)
            if(valid.find(c) == string::npos)
                return false;
        return true;
    }

    int getIndex(){
        return index;
    }
};

ostream& operator<<(ostream& ost, const Numero& numero){
    ost << "[" << numero.index << " | " << numero.id << " | " << numero.number << "]";
    return ost;
}




class Contato{
private:
    string nome;
    vector<Numero*> numeros;
public:
    Contato(string nome = "", vector<Numero*> numeros = vector<Numero*>()):
    nome(nome),numeros(numeros){
    }

    bool addNumero(Numero* numero){
        if(numero == nullptr || !(Numero::validar(numero->number)) ){
            return false;
        }else{
            numero->index = numeros.size();
            numeros.push_back(numero);
            return true;
        }
    }

    bool rmNumero(int index){
        if(index >= (int) numeros.size() || index < 0 ){
            return false;
        }else{
            numeros.erase(numeros.begin() + index);
            for (int i = 0; i < numeros.size(); i++){
                numeros[i]->index = i;
            }
            return true;
        }
    }

    vector<Numero*> getNumeros(){
        return numeros;
    }

    string getNome(){
        return this->nome;
    }

    friend ostream& operator<<(ostream& ost, Contato& contato);
};

ostream& operator<<(ostream& ost, Contato& contato){
    ost << "- " << contato.nome << " ";

    if(contato.numeros.size()>0){
        for (int i = 0; i < contato.numeros.size(); i++){
            if(contato.numeros[i]!= nullptr){
                ost << "[" << contato.numeros[i]->index << "|" << contato.numeros[i]->id << "|" << contato.numeros[i]->number <<"]";
            }else{
                ost << "";
            }
        }
        return ost;
    }else
        return ost;
}

template<class T>
T getss(stringstream& in){
    T t;
    in >> t;
    return t;
}

int main(){
    Contato contatomain = Contato("Pessoa");
    string line, cmd;
    while(true){
        getline(cin,line);
        cout << ">>>" << line << endl;
        stringstream in(line);
        in >> cmd;
        if(cmd == "init"){
            contatomain = Contato(getss<string>(in));
        }else if (cmd == "add"){
            if(!contatomain.addNumero(new Numero(0, getss<string>(in), getss<string>(in))))
                cout << "Número inválido" << endl;
            else
                cout << "Deu certo" << endl;
            
        }else if (cmd == "show"){
            cout << contatomain.getNome() << " ";
            if(contatomain.getNumeros().size()>0)
                for (int i = 0; i < contatomain.getNumeros().size(); i++)
                    cout << *contatomain.getNumeros()[i];
            cout << endl;
                
            
        }else if (cmd == "remove"){
            int aux = getss<int>(in);
            cout << aux << "teste" << endl;
            if(!contatomain.rmNumero(aux))
                cout << "Índice do número inválido" << endl;
            else
                cout << "Deu certo"<< endl;
        }else if(cmd == "help"){
            cout << "add <string> <string>" << endl;
            cout << "remove <int>" << endl;
            cout << "show" << endl;
            cout << "init <string>" << endl;
        }
        
        
        
    }
}