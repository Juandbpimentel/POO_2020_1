#include <vector>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <locale>

using namespace std;

class Tamagotchi{
    private:
        string nome;
        int maxEnergia, maxFome, maxLimpeza;
        int energia, fome, limpeza;
        int diamantes;
        int idade;
        bool statusEnergia;
        bool msgMorte;

        void setEnergia(int value){
            if(value <= 0){
                this->energia = value;
                this->statusEnergia = false;
                return;
            }
            else if (value > this->maxEnergia){
                this->energia = maxEnergia;
            }
            else{
                this->energia = value;
            }
        }
        void setFome(int value){
            if(value <= 0){
                this->fome = value;
                this->statusEnergia = false;
                return;
            }
            else if (value > this->maxFome){
                this->fome = maxFome;
            }
            else{
                this->fome = value;
            }
        }

        void setLimpeza(int value){
            if(value <= 0){
                this->limpeza = value;
                this->statusEnergia = false;

                return;
            }
            else if (value > this->maxLimpeza){
                this->limpeza = maxLimpeza;
            } else{
                this->limpeza = value;
            }
        }

        void setNome(string value){
            this->nome = value;
            return;
        }

        void setMsgMorte(int op){
            if(op == 1)
                this->msgMorte = true;
            else{
                this->msgMorte = false;
            }
        }

    public:
        Tamagotchi(string nome = "Bichinho",int energia = 0, int fome = 0, int limpeza = 0):
            nome(nome),maxEnergia(energia),maxLimpeza(limpeza),maxFome(fome),
            energia(energia),limpeza(limpeza),fome(fome){
            this->idade = 0;
            this->diamantes = 0;
            this->statusEnergia = true;
            this->msgMorte = false;
        }

        ~Tamagotchi(){

        }

        void mensagemMorte(){
            if(getMsgMorte() == true){
                cout<< endl << "Utilize a função reiniciar para reviver seu Tamagotchi, para melhor entendimento utilize a função help" << endl;
            }else if(this->getEnergia() < 1){
                cout<< endl << "Seu bichinho morreu de cansaço, visite a lápide dele para lembrar de sua, extremamente longa, vida de " << this->getIdade() <<" ações e prestar seu respeito\n\n\n"
                << "              _________________________________  \n"
                << "             |             R.I.P               | \n"
                << "             |            Bichinho             | \n"
                << "             |  O melhor amigo do programador  | \n"
                << "             |_________________________________| \n";
                cout<< endl << endl << endl << "Utilize a função reset para reiniciar seu Tamagotchi, para melhor entendimento utilize a função help" << endl << endl;
                setMsgMorte(1);
                
            }else if(this->getFome() < 1){
                cout<< endl << "Seu bichinho morreu de Desnutrição, visite a lápide dele para lembrar de sua, extremamente longa, vida de " << this->getIdade() <<" ações e prestar seu respeito\n\n\n"
                << "              _________________________________  \n"
                << "             |             R.I.P               | \n"
                << "             |            Bichinho             | \n"
                << "             |  O melhor amigo do programador  | \n"
                << "             |_________________________________| \n";
                cout<< endl << endl << endl << "Utilize a função reset para reiniciar seu Tamagotchi, para melhor entendimento utilize a função help" << endl << endl;
                setMsgMorte(1);
            }else if(this->getLimpeza() < 1){
                cout<< endl << "Seu bichinho morreu por causa de uma infecção pelas bactérias da sujeira dele, visite a lápide dele para lembrar de sua, extremamente longa, vida de " << this->getIdade() <<" ações e prestar seu respeito\n\n\n"
                << "              _________________________________  \n"
                << "             |             R.I.P               | \n"
                << "             |            Bichinho             | \n"
                << "             |  O melhor amigo do programador  | \n"
                << "             |_________________________________| \n";
                cout<< endl << endl << endl << "Utilize a função reset para reiniciar seu Tamagotchi, para melhor entendimento utilize a função help" << endl << endl;
                setMsgMorte(1);
            }
        }

    //Gets

        string getNome(){
            return this->nome;
        }

        int getEnergia(){
            return this->energia;
        }

        int getFome(){
            return this->fome;
        }

        int getLimpeza(){
            return this->limpeza;
        };

        int getMaxEnergia(){
            return this->maxEnergia;
        }

        int getMaxFome(){
            return this->maxFome;
        }

        int getMaxLimpeza(){
            return this->maxLimpeza;
        };

        int getDiamantes(){
            return this->diamantes;
        }

        int getIdade(){
            return this->idade;
        }

        bool getStatus_Energia(){
            return this->statusEnergia;
        }

        bool getMsgMorte(){
            return this->msgMorte;
        }
    // Ações do pet
        void comer(){
            if(this->getStatus_Energia() == true)
                this->setEnergia(getEnergia() - 1);
            if(this->getStatus_Energia() == true)
                this->setFome(getFome() + 4);
            if(this->getStatus_Energia() == true)
                this->setLimpeza(getLimpeza() - 2);
            if(this->getStatus_Energia() == true){
                this->idade += 1;
                cout << "Nhoc";
                if(this->idade > 1){
                    for (size_t i = 1; i < this->idade; i++){
                    cout << " nhoc";
                    }
                }
                cout << endl << endl;
            }else{
                this->mensagemMorte();
            }
        }

        void dormir(){
            if(this->getStatus_Energia() == true)
            if(getEnergia() >= 5)
                this->setEnergia(getMaxEnergia());
            if(this->getStatus_Energia() == true)
                this->setFome(getFome());
            if(this->getStatus_Energia() == true)
                this->setLimpeza(getLimpeza());
            if(this->getStatus_Energia() == true){
                this->idade += 1;
                cout << "ZzZz";
                if(this->idade > 1){
                    for (size_t i = 1; i < this->idade; i++){
                        cout << " ZzZz";
                    }
                }
                cout << endl << endl;
            }else{
                this->mensagemMorte();
            }

        }

        void banhar(){
            if(this->getStatus_Energia() == true)
                this->setEnergia(getEnergia() + 3);
            if(this->getStatus_Energia() == true)
                this->setFome(getFome() - 1);
            if(this->getStatus_Energia() == true)
                this->setLimpeza(getMaxLimpeza());
            if(this->getStatus_Energia() == true){
                this->idade += 1;
                cout << " (Esfrega) ";
                if(this->idade > 1){
                    for (size_t i = 0; i < this->idade; i++){
                        cout << "*Shish* ";
                    }
                }else{
                    cout << "*Shish* ";
                }
                cout << endl;
                cout << " (Molha) *Shhhhhh*  " << endl;
                cout << " (Cheirinho bom)" << endl;
            }else{
                this->mensagemMorte();
            }

        }

        void brincar(){
            if(this->getStatus_Energia() == true)
                this->setEnergia(getEnergia() - 2);
            if(this->getStatus_Energia() == true)
                this->setFome(getFome() - 1);
            if(this->getStatus_Energia() == true)
                this->setLimpeza(getLimpeza() - 3);
            if(this->getStatus_Energia() == true){
                this->idade += 1;
                this->diamantes += 1;
                cout << " Ihuu";
                if(this->idade > 1){
                    for (size_t i = 1; i < this->idade; i++){
                        cout << " ihuu";
                    }
                }
                cout << endl << endl;
            }else{
                this->mensagemMorte();
            }

        }

        string stringstreambichinho(){
            stringstream ss;
            ss <<"| Nome: "       << nome      <<
                 " | Energia: "   << energia   << "/"     << maxEnergia <<
                 " | Fome: "      << fome      << "/"     << maxFome    <<
                 " | Limpeza: "   << limpeza   << "/"     << maxLimpeza <<
                 " | Diamantes: " << diamantes << 
                 " | Idade: "     << idade     << " |";
            return ss.str();
        }

        void mostrar(){

            cout << endl;
            for(int i = stringstreambichinho().size(); i>0; i--)
                cout << '-';
            cout << endl << stringstreambichinho() << endl;
            for(int i = stringstreambichinho().size(); i>0; i--)
                cout << '-';
            cout << endl;

            cout << "Digite uma opção para seu bichinho fazer:"<< endl
                << "1) Brincar"   << endl
                << "2) Comer" << endl
                << "3) Dormir"    << endl
                << "4) Banhar" << endl
                << "(Se quiser escolher outro bichinho digite sair, help se quiser ler sobre os comandos e reiniciar em caso de falecimento do seu bichinho)"<< endl << endl
                << ">>>>>>>>>> ";
        }


};

void vet_rmind(vector<Tamagotchi>& vet, int value){
    if(value < vet.size() && value >= 0){
        cout << "O bichinho " << vet.at(value).getNome() << " foi removido com sucesso" << endl;
        vet.erase(vet.begin()+value);
        return;
    }else{
        return;
    }
}

struct Menu
{   
    private:
    vector<Tamagotchi> bichinho;

    void criar_bichinho(vector<Tamagotchi>& Vetor){
        string nome = "Bichinho", nome2 = "Bichinho";
        int energia = 0, fome = 0, limpeza = 0;
        
        string line; 
        
        if(Vetor.size() == 0){
            cout <<"Ainda não há nenhum bichinho para selecionar, você criará um novo bichinho:" << endl << endl;
        }
        
        cout << "Digite o nome do seu bichinho, energia, fome e limpeza de seu bichinho: ";

        getline(cin,line);
        stringstream in(line);
        in >> nome >> energia >> fome >> limpeza;

        if( energia <= 0)
            energia = 20;
        if (fome <= 0)
            fome = 20;
        if (limpeza <= 0)
            limpeza = 20;

        Tamagotchi aux(nome,energia,fome,limpeza);
        Vetor.push_back(aux);
    }

    void opcoes_bicho(int bichoEscolhido, string line){ 
        string op;
        stringstream in2(line);
        in2 >> op;
        
        if( op == "help"){
            system("cls||clear");
            cout << endl << "------------------------------------------------------------------------------------------------------------------------------" << endl
                         << "|                                                          Comandos                                                          |" << endl
                         << "------------------------------------------------------------------------------------------------------------------------------" << endl
                         << "|  Comer  | Enche a Fome do seu bichinho                                                                                     |" << endl
                         << "------------------------------------------------------------------------------------------------------------------------------" << endl
                         << "| Banhar  | Enche a limpeza do seu bichinho                                                                                  |" << endl
                         << "------------------------------------------------------------------------------------------------------------------------------" << endl
                         << "| Brincar | Dá diamantes pro seu bichinho aumentando a pontuação                                                             |" << endl
                         << "------------------------------------------------------------------------------------------------------------------------------" << endl
                         << "| Dormir  | Enche a energia do seu bichinho                                                                                  |" << endl
                         << "------------------------------------------------------------------------------------------------------------------------------" << endl
                         << "|Reiniciar| digite reiniciar para reviver seu bichinho com 20 pontos de cada categoria, opcionalmente voce pode digitar seu  |" << endl
                         << "|         | nome, a vida, a fome e a limpeza máxima do seu bichinho na frente do comando - Exemplo: Reiniciar nome 50 50 50  |" << endl
                         << "------------------------------------------------------------------------------------------------------------------------------" << endl;

        }else if (op == "Reiniciar" || op == "reiniciar"){
            system("cls||clear");
            string nome = "Bichinho";
            int energia = 0, fome = 0, limpeza = 0;
            in2 >> nome >> energia >> fome >> limpeza;
            if( energia <= 0)
                energia = 20;
            if (fome <= 0)
                fome = 20;
            if (limpeza <= 0)
                limpeza = 20;
            bichinho.at(bichoEscolhido) = Tamagotchi(nome,energia, fome, limpeza);
            cout << endl << "Seu bichinho foi revivido :3!"<< endl;

        }else if (op == "1" || op == "Brincar"|| op == "brincar" ){//brincar
            system("cls||clear");
            bichinho.at(bichoEscolhido).brincar();

        }else if (op == "2" || op == "Comer"|| op == "comer" ){//comer
            system("cls||clear");
            bichinho.at(bichoEscolhido).comer();

        }else if (op == "3" || op == "Dormir"|| op == "dormir" ){//dormir
            system("cls||clear");
            bichinho.at(bichoEscolhido).dormir();

        }else if (op == "4" || op == "Banhar"|| op == "banhar" ){//banhar
            system("cls||clear");
            bichinho.at(bichoEscolhido).banhar();

        }else{
            system("cls||clear");
            cout << "operação inválida" << endl;
        }
    }
 
    public:

    
    void terminal(){
        string line;

        while(true){
            int bichoEscolhido = -4;
            if(bichinho.size() == 0){
                system("cls||clear");
                criar_bichinho(bichinho);
                system("cls||clear");
            }

            cout << "Escolha um bicho ou uma opção" << endl;            
            for(int i = 0; i < bichinho.size(); i++){
                cout << " " << i << ") "<< bichinho.at(i).getNome()<< endl; 
            }
            cout << "-1" << ") "<< "Criar Novo Bichinho" << endl;
            cout << "-2" << ") "<< "Remover Bichinho" << endl;
            cout << "-3" << ") "<< "Sair" << endl;
            cout << endl << ">>>>>>>>>> ";
            getline(cin,line);
            stringstream in(line);
            in >> bichoEscolhido;
            
            if(bichoEscolhido == -3){
                system("cls||clear");
                cout << "Saindo..."<< endl;
                return;
            }else if(bichoEscolhido == -2){
                system("cls||clear");
                int bichoRemover;
                string escolha;

                cout << "Escolha um dos bichinhos para remover" << endl;
                for(int i = 0; i < bichinho.size(); i++){
                    cout << " " << i << ") "<< bichinho.at(i).getNome()<< endl; 
                }

                getline(cin,escolha);
                stringstream aux(escolha);

                in >> bichoRemover;
                system("cls||clear");
                vet_rmind(bichinho,bichoRemover);

            }else if(bichoEscolhido == -1){
                system("cls||clear");
                criar_bichinho(bichinho);
                system("cls||clear");
            }else if(bichoEscolhido > -1 && bichinho.size() > bichoEscolhido){
                system("cls||clear");
                while(true){
                    bichinho.at(bichoEscolhido).mostrar();
                    getline(cin,line);
                    cout << endl;
                    if(line == "sair"){
                        system("cls||clear");
                        break;
                    }
                    opcoes_bicho(bichoEscolhido,line);
                }
            }else{
                system("cls||clear");
                cout << "Opção inválida" << endl;
            }

        }
    }
};

int main(){
    setlocale(LC_ALL,"pt");
    Menu menu;
    menu.terminal();
    return 0;
};
