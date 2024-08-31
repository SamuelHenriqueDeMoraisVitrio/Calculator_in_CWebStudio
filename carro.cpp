
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct Carro{
    char *nome;
    char *cor;

    //new
    void set_nome(const char *nome){
        if(this->nome){
            free(this->nome);
        }
        this->nome = strdup(nome);
    }

    void set_cor(const char *cor){
        if(this->cor){
            free(this->cor);
        }
        this->cor = strdup(cor);
    }

    Carro(const char *nome,const char *cor){
        this->set_nome(nome);
        this->set_cor(cor);
    }

    ~Carro(){
        free(this->nome);
        free(this->cor);
    }

};


int  main(){
    Carro *celta = new Carro("celta","vermelho");
    celta->set_cor("preto");
    printf("nome:%s\n",celta->nome);
    printf("cor: %s\n",celta->cor);

    delete celta;
}
