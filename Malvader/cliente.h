#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//declarações de variáves, começo.

typedef struct { 
    double saldo;
    int ativo;
    int agencia [8];
    int conta [16];
    int cpf [16];
    int telefone [20];
    char nome [100];
    char data_nascimento [11];
    char cidade[60];
    char senha[20];
    char sexo[2]; 
    
} Cliente;
// struct Banco
typedef struct {
    Cliente* clientes;
    int qtd;
    int cap;
} Banco;
void banco_init(Banco* b){
    b-> clientes = NULL;
    b-> qtd = 0;
    b->cap = 0;
}
void banco_free(Banco* b){
    free (b->clientes);
    b->clientes = NULL;
    b->qtd = 0;
    b->cap = 0;
}
int banco_adicionar_cliente(Banco* b, Cliente novo) {
  //Verificar se precisa aumentar o vetor.
    if (b->qtd == b->cap) {

        int nova_cap = (b->cap == 0) ? 4 : b->cap * 2;

        Cliente* temp = realloc(b->clientes, nova_cap * sizeof(Cliente));
        if (!temp) {
            return 0;
        }

        b->clientes = temp;
        b->cap = nova_cap;
    }

    b->clientes[b->qtd] = novo;
    b->qtd++;

    return 1; 
}


//início do programa

int main(){

    return 0;
}

