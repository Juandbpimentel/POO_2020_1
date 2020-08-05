#include <iostream>
#include <vector>
#include <sstream>
#include <locale>
#include <cmath>

/*Func Iniciar_máquina: inicia a máquina com n expirais e com k espaços para produtos,
se já houver uma máquina, criar uma nova e apagar a anterior*/
/*Func mostrar_conteudo: Mostra uma lista com o índice, nome do produto, espaços para o produto e o preço
, se não houver nenhum produto no espaço, colocar '-' no lugar das informações*/

class Espiral{
    private:
        std::string nome_do_produto;
        int qtd;
        float preco;
    public:
    
    Espiral(std::string nome_do_produto = "Disquete", int qtd = 1, float preco = 0):preco(preco),nome_do_produto(nome_do_produto),qtd(qtd){}

    std::string toString(){
        std::stringstream ss;
        ss << this->nome_do_produto << " : " << this->qtd<< " U" << " : " << "R$ "; 
        return ss.str();
    }

    std::string getNome(){
        return this->nome_do_produto;
    }

    float getPreco(){
        return this->preco;
    }

    int getQtd(){
        return this->qtd;
    }

    void setQtd(int value){
        this->qtd = value;
    }

};

class Maquina{
    private:

        std::vector<Espiral*> espirais;
        float saldo;
        float lucro;

    public:
        Maquina(int qtd_espirais = 5):espirais(qtd_espirais){
            this->saldo = 0;
            this->lucro = 0;
        }

        bool fazer_upgrade_maquina(int qtd_esp){
            if(qtd_esp > 0){
                std::vector<Espiral*> aux(qtd_esp,nullptr);
                espirais = aux;
                return true;
            }
            return false;
            
        }

        bool preencher_espiral(int ind, Espiral* produto_novo){
            if(this->espirais[ind] == nullptr &&  ind < this->espirais.size() ){
                this->espirais[ind] = produto_novo;
                return true;
            }
            else
                return false;
        }

        bool limpar_espiral(int ind){
            if(this->espirais[ind] == nullptr || ind >= this->espirais.size())
                return false;
            else{
                this->espirais[ind] = nullptr;
                return true;
            }
                
        }

        bool inserir_dinheiro(float value){
            if(value <= 0){
                return false;
            }else{
                this->saldo += value;
                return true;
            }
        }

        std::string toString(){
            std::stringstream sld;
            sld << "- Saldo: R$ " << this->saldo << "\n- Espirais: \n";
            std::string retorno = sld.str();

            for(int i = 0; i < espirais.size();i++){

                std::stringstream ss;

                if(espirais[i] != nullptr){

                    std::string espacos = "",espaco_extra = "";
                    int aux2 = (26 - espirais[i]->toString().size())/2;

                    if((26 - espirais[i]->toString().size())%2 == 1){
                        espaco_extra=" ";
                    }

                    while(aux2 > 0){
                        espacos += " ";
                        aux2--;
                    }


                    ss << i;
                    if((26 - espirais[i]->toString().size())%2 == 1)
                        retorno += ss.str() + " [" + espacos + " " + espaco_extra; 
                    else
                        retorno += ss.str() + " [" + espacos + " ";
                    std::stringstream preco;
                    preco << espirais[i]->getPreco();
                    retorno += espirais[i]->toString();
                    retorno += preco.str() + espacos + "]\n";
                }else{
                    ss << i;
                    retorno += ss.str() + " - \n";
                }
            }
            return retorno;
        }

        void mostrarLucro(){
            std::cout << std::fixed;
            std::cout.precision(2);
            std::cout << "Seu lucro é de R$ " << this->lucro << std::endl;
        }

        void mostrar(){
            std::cout << std::fixed;
            std::cout.precision(2);
            std::cout << "- Saldo: R$ "<< this->saldo <<"\n- Espirais: \n\n";
            
            for(int i = 0; i < espirais.size();i++){

                std::stringstream ss;
                std::string retorno = "";
                if(espirais[i] != nullptr){

                    std::string espacos = "",espaco_extra = "";
                    int aux2 = (26 - espirais[i]->toString().size())/2;

                    if((26 - espirais[i]->toString().size())%2 == 1){
                        espaco_extra=" ";
                    }

                    while(aux2 > 0){
                        espacos += " ";
                        aux2--;
                    }


                    ss << i;
                    if((26 - espirais[i]->toString().size())%2 == 1)
                        retorno += ss.str() + " [" + espacos + " " + espaco_extra; 
                    else
                        retorno += ss.str() + " [" + espacos + " ";
                    retorno += espirais[i]->toString();
                    std::cout << retorno << espirais[i]->getPreco() << espacos << "]\n";
                }else{
                    ss << i;
                    retorno += ss.str() + " - \n";
                    std::cout << retorno;
                }
            }

        }

        bool comprar(int ind){
            if(this->espirais[ind] != nullptr && ind < espirais.size()){

                if( this->saldo >= this->espirais[ind]->getPreco()){
                    
                    this->espirais[ind]->setQtd(this->espirais[ind]->getQtd()-1);

                    this->saldo -= this->espirais[ind]->getPreco();
                    this->lucro += this->espirais[ind]->getPreco();

                    std::cout<< "Você comprou um " + espirais[ind]->getNome() << ", seu saldo agora é de R$ "<<this->saldo <<std::endl;
                    
                    if(this->espirais[ind]->getQtd()==0)
                        this->espirais[ind] = nullptr;

                    return true;   
                }
                else
                    return false;
            }
            else
                return false;
        }

        void terminal(){
            std::string line;
            while(true){
                std::getline(std::cin, line);
                std::cout << std::endl;
                if(line == "end"){
                    std::cout << "end...";
                    return;
                }
                opcoes(line);
            }
        }

        float getSaldo(){
            return this->saldo;
        }

        float pedirTroco(){
            float aux = this->getSaldo();
            this->saldo = 0;
            return aux;
        }

        void opcoes(std::string line){
            std::stringstream in(line);
            std::string op;
            in >> op;
            
            if(op == "init_maquina"){
                int qtd = 0;
                in >> qtd;
                if(this->fazer_upgrade_maquina(qtd)){
                    std::cout << "Upgrade feito com sucesso" << std::endl;
                }else
                    std::cout << "Não foi possível fazer a reforma na máquina, a quantidade de espirais é inválida" << std::endl;
            
            
            
            }else if(op == "preencher"){
                int qtd = 5, ind;
                float preco = 0.50;
                std::string nome ="Disquete";

                in >> ind >> nome >> qtd >> preco;
                
                if( this->preencher_espiral(ind , new Espiral(nome,qtd,preco)) ){
                    std::cout << "Espiral Preenchido com sucesso" << std::endl;
                }else{
                    std::cout << "A posição de espiral que você escolheu é inválida" << std::endl;
                }
                        
            
            }else if(op == "esvaziar"){
                int ind = -1;
                in >> ind;
                if(this->limpar_espiral(ind))
                    std::cout << "Espiral esvaziado com sucesso" << std::endl;
                else    
                    std::cout << "A posição de espiral que você escolheu é inválida" << std::endl;
            
            
            
            }else if(op == "dinheiro"){
                float value = 0;
                in >> value;
                if(this->inserir_dinheiro(value))
                    std::cout << "Dinheiro coletado com sucesso, seu saldo agora é de " << "R$ " << this->getSaldo() << std::endl;
                else
                    std::cout << "O valor inserido é inválido" << std::endl;
            
            
            
            }else if(op == "mostrar"){
                this->mostrar();
            
            
            
            }else if(op == "lucro"){
                this->mostrarLucro();
            
            
            
            }else if(op == "mostrartst"){
                std::cout << this->toString();
            
            
            
            }else if(op == "comprar"){
                int ind = -1;
                in >> ind;
                if(!(this->comprar(ind)))
                    std::cout << "Você não tem dinheiro o suficiente para comprar esse produto ou a posição escolhida é inválida" << std::endl;
            
            
            
            }else if(op == "troco"){
                float aux = this->pedirTroco();

                if(aux == 0){
                    std::cout << "Você não tem dinheiro para receber de troco" <<std::endl;       
                }else
                std::cout << "Você recebeu R$ " << aux <<" de troco" <<std::endl;   
            
            
            
            }else{
                std::cout << "Opção inválida"<< std::endl;
            }

        }
};


int main(){
    setlocale(LC_ALL,"pt");
    Maquina teste(10);
    teste.terminal();
    return 0;
}