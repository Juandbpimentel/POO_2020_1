#include <iostream>
#include <vector>
#include <sstream>
#include<bits/stdc++.h> 

using namespace std;

//mostra o vetor
void vet_show(vector<int>& vet){
    cout << "[ ";
    for(size_t i = 0; i < vet.size(); i++)
        cout << vet[i] << " ";
    cout << "]\n";
}

void vet_rshow(vector<int>& vet){
    cout << "[ ";
    for(size_t i = vet.size()-1; i >= 0 ; i--)
        cout << vet[i] << " ";
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
            cout << "]";
        }else if(cmd == "rmi"){
        }else if(cmd == "ins"){
        }else if(cmd == "rma"){
        }else{
            cout << "Comando invalido\n";
        }
    }
    return 0;
}