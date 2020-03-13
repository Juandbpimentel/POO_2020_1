#include <iostream>
#include <vector>
#include <sstream>
#include<bits/stdc++.h> 

using namespace std;

//mostra o vetor
void vet_show(vector<int>& vet){
    cout << "[ ";
    for(size_t i = 0; i < vet.size(); i++)
        cout << vet.at(i) << " ";
    cout << "]\n";
}

//mostra o vetor espelhado
void vet_rshow(vector<int>& vet){
    cout << "[ ";
    for(vector<int>::iterator i = vet.end()-1; i >= vet.begin() ; --i)
        cout << *i << " ";
    cout << "]\n";
}

//retorna o índice que contém value ou -1 se não existir
int vet_find(vector<int>& vet, int value){
    vector<int> :: iterator it;

    it = find (vet.begin(), vet.end(), value); 
    if (it != vet.end()) 
    { 
        return it - vet.begin(); 
    } 
    else
        return -1; 

}

void vet_rmind(vector<int>& vet, int value){
    if(value < vet.size() && value >= 0){
        vet.erase(vet.begin()+value);
        return ;
    }else{
        return;
    }
}

int vet_insert(vector<int>& vet, int pos, int value){
    auto it = vet.begin();
    it += pos;
    if(it > vet.end()){
        vet.push_back(value);
        return 1;
    }else{
        vet.insert(it,value);
    }return -1;
}

int vet_set(vector<int>& vet, int pos, int value){
    auto it = vet.begin();
    it += pos;
    if(it < vet.end() && it>= vet.begin()){
        *it = value;
        return 1;
    }
    return -1;
}
int main(){
    vector<int> vet;
    string line;
    while(true){
        getline(cin, line);
        stringstream ss(line);
        cout << "$" << line << "\n";
        string cmd;
        ss >> cmd; //pegando o primeiro token
        if(line == "end"){
            break;
        }else if(cmd == "add"){
            int value;
            while(ss >> value) //enquanto conseguir retirar valores
                vet.push_back(value);
        }else if(cmd == "show"){
            vet_show(vet);
        }else if(cmd == "rshow"){
            vet_rshow(vet);
        }else if(cmd == "find"){
            int value;
            cout << "[ ";
            while(ss >> value){
                int v = vet_find(vet,value);
                if(v != -1){
                    cout << v << " "; 
                }else{
                    cout << -1 << " ";
                }
            }
            cout << "]\n";
        }else if(cmd == "rmi"){
            int value;
            while(ss >> value){
                vet_rmind(vet,value);
            }
        }else if(cmd == "ins"){
            int value, pos;
            ss >> pos >> value;
            vet_insert(vet,pos,value);

        }else if(cmd == "rma"){
            vet.clear();
        }else if(cmd == "get"){
            int pos;
            ss >> pos;
            cout << vet.at(pos) << "\n";
        }else if(cmd == "set"){
            int value, pos;
            ss >> pos >> value;
            vet_set(vet,pos,value);

        }else{
            cout << "Comando invalido\n";
        }
    }
    return 0;
}