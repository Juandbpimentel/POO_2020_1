#include <iostream>
#include <vector>

using namespace std;

class Fone{
public:
    int index;
    string id;
    string number;

    Fone(int index,string id = "",string number = ""):
    index(index),id(id),number(number){}

    Fone(){
        this->index = 0;
        this->id = "";
        this->number = "";
    }

    static bool validar(string number){
        string valid = "0123456789()-.";
        for(char c : number)
            if(valid.find(c) == string::npos)
                return false;
        return true;
    }  
};

ostream& operator<<(ostream& ost, const Fone& fone){
    ost << "[" << fone.index << " | " << fone.id << " | " << fone.number << "]";
    return ost;
}

int main(){
    Fone fone;
    string number = "4002-8922";
    fone = (Fone::validar(number)) ?  Fone(1,"Bom Dia & Cia",number) : Fone(1,"erro","erro");

    cout << fone << endl;

    int a[10] = {0,1,2,3,4,5,6,7,8,9};

    for (int i = 0; i < 10 ; i++)
    {
        cout << a[i] << endl;
    }
    
}
