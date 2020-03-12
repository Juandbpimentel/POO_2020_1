#include <iostream>
using namespace std;

struct Carro{
    int nPessoas = 0;
    
    int maxPessoas = 2;
    
    float gasolina = 0;
    
	float maxGasolina = 20;

    bool embarcar_um(){
        if (this->nPessoas < this->maxPessoas){
            this->nPessoas += 1;
            cout << "embarcou\n";
            return true;
        }
        cout << "ta lotado\n";
        return false;
    }

    bool desembarcar_um(){
        if(this->nPessoas<=0){
            cout << "Não foi possível desembarcar pois não há ninguém no carro\n";
            return false;
        }else{
            this->nPessoas-=1;
            cout << "Desembarcou\n";
            return true;
        }
    }
    bool dirigir(float dist){
        if(this->nPessoas == 0){
            cout << "Não tem quem dirija\n";
            return false;
        }
        
        if(this->gasolina-dist<0){
            cout << "Não há gasolina suficiente\n";
            return false;
        }else{
            cout << "O carro andou "<< dist << " km\n";
            this->gasolina -= dist;
            return true;
        }
    }

    bool abastecer(float gasolina_adic){
        this->gasolina += gasolina_adic;
        if(this->maxGasolina < this->gasolina ){
            this->gasolina = this->maxGasolina;
        }
        cout << "Abastecido\n";
        return true;
    }
};

int main() {
    Carro * carro = new Carro();
	int op = 0; 
	while(op !=5){
		switch(op){
			case 1:
				carro->embarcar_um();
				op = 0;			
				break;
			case 2:
				carro->desembarcar_um();
				op = 0;			
				break;
			case 3:
				float dist;
				cout<<"Digite a distância que você irá dirigir: ";
				cin >> dist;
				cout<<"\n";
				carro->dirigir(dist);
				op = 0;			
				break;
			case 4:
				float quant;
				cout<<"Digite a quantidade que você irá abastecer: ";
				cin >> quant;
				cout<<"\n";
				carro->abastecer(quant);
				op = 0;
				break;
			case 5:
				break;
			
			default:
				cout << "<><><><><><> Ações para fazer com o carro <><><><><><>"<< "\n\n";				
				
				cout << "1 - Embarcar uma pessoa no carro"<< "\n";
				cout << "2 - Desembarcar alguém do carro"<< "\n";
				cout << "3 - Dirigir o carro"<< "\n";
				cout << "4 - Abastecer o carro"<< "\n";
				cout << "5 - Sair do carro"<< "\n\n";
				
				cout << "Digite o número da ação que você irá executar com seu carro: \n";
				cin >> op;
				break;
		}
	}
	return 1;
}
