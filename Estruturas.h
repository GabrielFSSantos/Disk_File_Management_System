#ifndef ESTRUTURAS_H_INCLUDED
#define ESTRUTURAS_H_INCLUDED
#define T 40

// ESTRUTURAS

typedef struct Disco // Vetor de Strings, que Armazena os Arquivos.
{
    char Vetor[T][3]; //Sendo T o Tamanho do Vetor e 3 a Quantidade de Caracteres Armazenadas em Cada Posição

}TDisco;

typedef struct Setor // Guarda Intervalos do Disco e o Endereço do Proximo Setor.
{
    int inicio;              // Inicio do Intervalo.
    int fim;                 // Fim do Intervalo.
    struct Setor *proxSetor; // Ponteiro para o Proximo Setor.

}TSetor;

typedef struct ListaSetores // Uma Lista do Tipo Setor, que Armazena 2 Endereços de Setor, o Primeiro e o Ultimo da Lista e a Quantidade de Setores Disponiveis.
{
    TSetor* primeiro; // Guarda o Endereço do Primeiro Setor da Lista (Cabeça).
    TSetor* ultimo;   // Guarda o Endereço do Ultimo Setor da Lista.
    int tam;          // Mantem Atualizado a Quantidade de Setores Disponiveis na Lista.

}TListaSetores;

typedef struct Arquivo // Guarda as Informações do Arquivo o seu Conteudo e o Endereço do Proximo Arquivo.
{
    char nome[20];               // String para Armazenar o Nome.
    int id;                      // Int que Armazena qual o Indice do Arquivo.
    int tamanho;                 // Numero de Caracteres que o Arquivo Possue, ou seja, seu Tamanho em Disco.
    TListaSetores Conteudo;      // Lista de Setores que Armazena os Intervalos onde se Encontra o Arquivo em Disco.
    struct Arquivo *proxArquivo; // Ponteiro para o Proximo Arquivo.

}TArquivo;

typedef struct ListaArquivos // Guarda o Primeiro e o Ultimo Endereço de Celula de uma Lista.
{
    TArquivo* primeiro; // Guarda o Endereço do Primeiro Arquivo da Lista (Cabeça).
    TArquivo* ultimo;   // Guarda o Endereço do Ultimo Arquivo da Lista.
    int indice;         // Mantem Atualizado a Quantidade de Arquivos que á na Lista.

}TListaArquivos;


// FUNÇÕES BASE SETORES
void FLVaziaSetores(TListaSetores *Lista); // Inicializa a Lista de Setores e Cria a Primeira Celula (Cabeça).
int VaziaSetores(TListaSetores Lista); // Verifica se a Lista de Setores esta Vazia.
void CriarSetores(TDisco *Disco, TListaSetores *Lista); // Divide o Disco em Setores, cada Setor terá 2 posições do Disco.
void UsarSetores(TListaSetores *Lista, TArquivo *Arquivo); // Seleciona os Setores Necessarios para um Arquivo, de Forma Aleatoria.
void LibeSetores(TListaSetores *Lista, TArquivo *Arquivo); // Retorna os Vetores de um Arquivo para Lista de Setores Livres.
void LimpaListaSetores(TListaSetores *Setores); // Limpa a Lista de Setores (Apaga Todos Setore).


// FUNÇÕES BASE ARQUIVO
void FLVaziaArquivo(TListaArquivos *Lista); // Inicializa a Lista de Arquivos e o Indice e Cria a Primeira Celula (Cabeça).
int VaziaArquivo(TListaArquivos Lista); // Verifica se a Lista de Arquivos esta Vazia.
void CriarArquivo(TListaArquivos *Lista); // Cria uma nova Celula de Arquivo e Ela Recebe seu ID.
void GravarArquivo(TDisco *Disco, TArquivo *Arquivo); //Grava o ID do Arquivo no Disco, nos seus Respectivos Setores.
TArquivo* PesquisarArquivo(TListaArquivos *Lista, char *nome); // Pesquisa por um Arquivo no Disco e Retorna seu Endereço.
void RemoverArquivo(TListaArquivos *Lista, TArquivo *Arquivo); // Apaga o Arquivo do Disco e Torna o seu Intervalo Livre.
void ImprimirArquivo(TArquivo *Arquivo); // Imprime as Informações de um Arquivo
void ImprimirListaArquivos(TListaArquivos *Lista); // Imprime Todos os Arquivos


// FUNÇÕES BASE DISCO
void DesfragmentarDisco(TDisco *Disco, TListaSetores *Setores, TListaArquivos *Arquivos); // Realoca os Arquivos no Disco de Forma Organizada.
void FormatarDisco(TDisco *Disco, TListaSetores *Setores, TListaArquivos *Arquivos); // Limpa o Disco Apagando Todos Arquivos
void ImprimirDisco(TDisco *Disco);

#endif // ESTRUTURAS_H_INCLUDED
