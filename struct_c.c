
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct {
    char *nome;
    char *cor;
}Carro;

void Carro_set_nome(Carro *self,const char *nome){
    if(self->nome){
        free(self->nome);
    }
    self->nome = strdup(nome);
}

void Carro_set_cor(Carro *self,const char *cor){
    if(self->cor){
        free(self->cor);
    }
    self->cor = strdup(cor);
}

Carro * newCarro( const char *nome,const char *cor){
    Carro *self = (Carro*)malloc(sizeof(Carro));
    *self  = (Carro){0};
    Carro_set_nome(self,nome);
    Carro_set_cor(self, cor);
    return self;
}

void Carro_free(Carro *self){
    free(self->nome);
    free(self->cor);
    free(self);
}


int main(){
    Carro *celta = newCarro("celta", "vermelho");
    Carro_set_cor(celta, "preto");
    printf("nome: %s\n",celta->nome);
    printf("cor: %s\n",celta->cor);
    Carro_free(celta);

}
