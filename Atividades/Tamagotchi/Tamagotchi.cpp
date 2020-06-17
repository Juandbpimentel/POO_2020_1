#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

class Tamagotchi
{
private:
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
        }
        else{
            this->limpeza = value;
        }
    }

    void setMsgMorte(int op){
        if(op == 1)
            this->msgMorte = true;
        else{
            this->msgMorte = false;
        }
    }

public:
    Tamagotchi(int energia = 0, int fome = 0, int limpeza = 0):
        maxEnergia(energia),maxLimpeza(limpeza),maxFome(fome),
        energia(energia),fome(fome),limpeza(limpeza){
        this->idade = 0;
        this->diamantes = 0;
        this->statusEnergia = true;
        this->msgMorte = false;
    }

    ~Tamagotchi(){

    }

    void mensagemMorte(){
        if(getMsgMorte() == true){
            cout<< endl << "Utilize a função reset para reiniciar seu Tamagotchi, para melhor entendimento utilize a função help" << endl;
        }else if(this->getEnergia() < 1){
            cout<< "Seu bichinho morreu de cansaço, visite a lápide dele para lembrar de sua, extremamente longa, vida de " << this->getIdade() <<" ações e prestar seu respeito\n\n\n"
            << "              _________________________________  \n"
            << "             |             R.I.P               | \n"
            << "             |            Bichinho             | \n"
            << "             |  O melhor amigo do programador  | \n"
            << "             |_________________________________| \n";
            cout<< endl << endl << endl << "Utilize a função reset para reiniciar seu Tamagotchi, para melhor entendimento utilize a função help" << endl << endl;
            setMsgMorte(1);
            
        }else if(this->getFome() < 1){
            cout<< "Seu bichinho morreu de Desnutrição, visite a lápide dele para lembrar de sua, extremamente longa, vida de " << this->getIdade() <<" ações e prestar seu respeito\n\n\n"
            << "              _________________________________  \n"
            << "             |             R.I.P               | \n"
            << "             |            Bichinho             | \n"
            << "             |  O melhor amigo do programador  | \n"
            << "             |_________________________________| \n";
            cout<< endl << endl << endl << "Utilize a função reset para reiniciar seu Tamagotchi, para melhor entendimento utilize a função help" << endl << endl;
            setMsgMorte(1);
        }else if(this->getLimpeza() < 1){
            cout<< "Seu bichinho morreu por causa de uma infecção pelas bactérias da sujeira dele, visite a lápide dele para lembrar de sua, extremamente longa, vida de " << this->getIdade() <<" ações e prestar seu respeito\n\n\n"
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
    void alimentar(){
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
            cout << " (Esfrega) *Shish Shish*  " << endl;
            cout << " (Molha) *Shhhhhh*  " << endl;
            cout << " (Cheirinho bom)" << endl;
        }else
        {
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
        }else
        {
            this->mensagemMorte();
        }

    }

    string mostrar(){
        stringstream ss;
        ss << "| E:" <<  energia  << "/"     << maxEnergia <<
             " | F:" <<    fome   << "/"     << maxFome    <<
             " | L:" <<  limpeza  << "/"     << maxLimpeza <<
             " | D:" << diamantes << " | I:" << idade << " |";
        return ss.str();
    }
};

struct Menu
{   
    Tamagotchi bichinho = Tamagotchi(20,20,20);

    void opcoes(string line){
        stringstream in(line);
        string op;
        in >> op;
        if( op == "help"){
            cout << "alimentar" << endl
                 << "banhar" << endl
                 << "brincar" << endl
                 << "clean" << endl
                 << "dormir" << endl
                 << "eat" << endl
                 << "help" << endl
                 << "mostrar" << endl
                 << "play" << endl
                 << "show" << endl
                 << "shower" << endl
                 << "sleep" << endl
                 << "reiniciar [ Integer Vida ] [ Integer Fome ] [ Integer Limpeza ]" << endl
                 << "reset [ Integer Vida ] [ Integer Fome ] [ Integer Limpeza ]" << endl;

        }else if (op == "reiniciar" || op == "reset"){
            int energia = 0, fome = 0, limpeza = 0;
            in >> energia >> fome >> limpeza;
            if( energia <= 0)
                energia = 20;
            if (fome <= 0)
                fome = 20;
            if (limpeza <= 0)
                limpeza = 20;

            bichinho = Tamagotchi(energia, fome, limpeza);
            cout << "Seu bichinho está sendo revivido!"<< endl;
        }
        else if (op == "mostrar" || op == "show"){
            cout << bichinho.mostrar() << endl;
        }
        else if (op == "brincar" || op == "play"){
            bichinho.brincar();
        }else if (op == "alimentar" || op == "eat"){
            bichinho.alimentar();
        }
        else if (op == "dormir" || op == "sleep"){
            bichinho.dormir();
        }
        else if (op == "banhar" || op == "shower" || op == "clean"){
            bichinho.banhar();
        }else{
            cout << "operação inválida" << endl;
        }
    }

    void terminal(){
        string line;
        while(true){
            getline(cin, line);
            cout << "$" << line << endl;
            if(line == "end"){
                cout << "end...";
                return;
            }
            opcoes(line);
        }
    }
};

int main(){
    Menu menu;
    menu.terminal();
    return 0;
};
