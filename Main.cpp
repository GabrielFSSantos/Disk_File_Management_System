
#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include "Estruturas.h"
#include "Funções.c"


// Criando Listas e Disco

    TDisco Disco;
    TListaSetores Setores;
    TListaArquivos Arquivos;

// Variavel Auxiliar

    TArquivo *aux;
    char nome[20];



// Função Callback de Redesenho da Janela de Visualiação Para Texto (No Caso o Titulo)
void DesenhaTitulo(double x,double y, double z,char *string)
{
	glRasterPos2f(x,y);

    int len =(int)strlen(string);

	for (int i=0; i<len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}
}

// Função Callback de Redesenho da Janela de Visualiação Para Texto (No Caso o Nome do Arquivo)
void DesenhaTexto(double x,double y, double z,char *string)
{
	glRasterPos2f(x,y);

    int len =(int)strlen(string);

	for (int i=0; i<len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, string[i]);
	}
}

// Função Callback de Redesenho da Janela de Visualiação Para Char (No Caso as Posições do Arquivo)
void DesenhaChar(double x,double y,double z,char w)
{
    glRasterPos2f(x,y);

	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, w);
}

// Função Callback de Redesenho da Janela de Visualiação Para Disco (No Caso a Estrurura do Disco)
void DesenhaDisco()
{
    // Somente para Ilustrar o Titulo do Disco
    char tit[40];
    strcpy(tit,"Sistema de Gerenciamento de Arquivo em Disco");
    DesenhaTitulo(4.5,21.5,0,tit);

    // Somente para Ilustrar Texto na Interface
    char arq[9];;
    strcpy(arq,"Arquivo: ");

    // Variaveis para Rodar os Laços
    int i,j;

    //Variaveis para os pontos do Quadradado do Setor
    double x1,x2,y1,y2,k;

    // Desenha o Quadrado de Fundo no Centro da Janela
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
        glVertex2f(0,0);
        glVertex2f(0,20);
        glVertex2f(16,20);
        glVertex2f(16,0);
    glEnd();

    // Desenha Todos os Quadrados das Posições do Disco
    for(i=0,x1=0,x2=2,y1=16,y2=20; i<T; i++,x1+=2,x2+=2)
    {

        // Quadrado da Posição do Disco
        glColor3f(0.37,0.62,0.63);
        glBegin(GL_QUADS);
            glVertex2f(x1,y1);
            glVertex2f(x1,y2);
            glVertex2f(x2,y2);
            glVertex2f(x2,y1);
        glEnd();

        // Contorno do Quadrado da Posição do Disco
        glColor3f(0,0,0);
        glLineWidth(8);
        glBegin(GL_LINE_LOOP);
            glVertex2f(x1,y1);
            glVertex2f(x1,y2);
            glVertex2f(x2,y2);
            glVertex2f(x2,y1);
        glEnd();


        // Desenha Todos os Quadrados das Posições dos Setor
        for(j=0,k=0;j<3;j++,k++)
        {
            // Quadrado da Posição do Setor
            glColor3f(0.86,0.86,0.86);
            glBegin(GL_QUADS);
                glVertex2f(x1+0.1,y1+0.6+k);
                glVertex2f(x1+0.1,y2-2.6+k);
                glVertex2f(x2-0.1,y2-2.6+k);
                glVertex2f(x2-0.1,y1+0.6+k);
            glEnd();

            // Contorno do Quadrado da Posição do Setor
            glColor3f(0,0,0);
            glLineWidth(2);
            glBegin(GL_LINE_LOOP);
                glVertex2f(x1+0.1,y1+0.6+k);
                glVertex2f(x1+0.1,y2-2.6+k);
                glVertex2f(x2-0.1,y2-2.6+k);
                glVertex2f(x2-0.1,y1+0.6+k);
            glEnd();

            if(Disco.Vetor[i][j]!=' ')
            {
                DesenhaTexto(x1+0.3,y1+0.9+k,0,arq);
            }
            DesenhaChar(x1+1.4,y1+0.9+k,0,Disco.Vetor[i][j]);

        }


        // Salta de Linha em Linha
        if((i+1)%8==0)
        {
            x1=-2;
            x2=0;
            y1-=4;
            y2-=4;
        }

    }


    // Contorno do Quadrado de Fundo no Centro da Janela
    glColor3f(0,0,0);
    glLineWidth(8);
    glBegin(GL_LINE_LOOP);
        glVertex2f(0,0);
        glVertex2f(0,20);
        glVertex2f(16,20);
        glVertex2f(16,0);
    glEnd();

  // Executa os comandos OpenGL
    glFlush();

}

// Função que trata a opção selecionada do Menu Principal
void MenuPrincipal(int op)
{
	switch(op)
	{
		case 0:
            // Chamada da Saida
            exit(0);
        break;
	}
}

// Função que trata a opção selecionada do Menu do Disco
void MenuDisco(int op)
{
	switch(op)
	{
		case 0:
            // Chamada da Função Desfragmentar
            system("cls");
            printf("\n>>>>>>>>>>>>>>>>> DESFRAGMENTAR DISCO: <<<<<<<<<<<<<<<<<<\n\n");

            DesfragmentarDisco(&Disco,&Setores,&Arquivos);
            printf("\nDisco Desfragmentado com Sucesso!!\n");

            printf("\n\n>>>>>>>>>>>>>>> MSG: Menu Disponivel...!!! <<<<<<<<<<<<<\n");
        break;

        case 1:
            // Chamada da Função Formatar
            system("cls");
            printf("\n>>>>>>>>>>>>>>>>>>>> FORMATAR DISCO: <<<<<<<<<<<<<<<<<<<<\n\n");

            FormatarDisco(&Disco,&Setores,&Arquivos);
            printf("\nDisco Formatado com Sucesso!!\n");

            printf("\n\n>>>>>>>>>>>>>>> MSG: Menu Disponivel...!!! <<<<<<<<<<<<<\n");
        break;
	}
	printf("\n");
	/// ImprimirDisco(&Disco); // Somente Para Verificação
	glutPostRedisplay();
}

// Função que trata a opção selecionada do Menu de Arquivo
void MenuArquivo(int op)
{
	switch(op)
	{
		case 0:
		    // Chamada da Função Inserir
		    system("cls");
		    printf("\n>>>>>>>>>>>>>>>>>>>>>>> INSERIR: <<<<<<<<<<<<<<<<<<<<<<<<\n\n");

            CriarArquivo(&Arquivos);

            printf("Digite o Nome do Arquivo: ");
            fflush(stdin);
            fgets(Arquivos.ultimo->nome,20,stdin);

            printf("Digite o Tamanho do Arquivo: ");
            fflush(stdin);
            scanf("%d",&Arquivos.ultimo->tamanho);

            FLVaziaSetores(&Arquivos.ultimo->Conteudo);

            UsarSetores(&Setores,Arquivos.ultimo);

            if(Arquivos.ultimo->Conteudo.primeiro->proxSetor!=NULL)
            {
                GravarArquivo(&Disco,Arquivos.ultimo);
                printf("\nArquivo Gravado com Sucesso!\n");
                ImprimirArquivo(Arquivos.ultimo);
            }
            else
            {
                RemoverArquivo(&Arquivos,Arquivos.ultimo);
            }
            printf("\n\n>>>>>>>>>>>>>>> MSG: Menu Disponivel...!!! <<<<<<<<<<<<<\n");


        break;

        case 1:
            // Chamada da Função Pesquisar
            system("cls");
            printf("\n>>>>>>>>>>>>>>>>>>>>>> PESQUISAR: <<<<<<<<<<<<<<<<<<<<<<<\n\n");

            printf("Digite o Nome do Arquivo: ");
            fflush(stdin);
            fgets(nome,20,stdin);

            aux = PesquisarArquivo(&Arquivos,nome);

            if(aux != NULL)
            {
                ImprimirArquivo(aux);
            }
            else
            {
                printf("\nO Arquivo nao Existe!");
            }
            printf("\n\n>>>>>>>>>>>>>>> MSG: Menu Disponivel...!!! <<<<<<<<<<<<<\n");

        break;

        case 2:
            // Chamada da Função Excluir
            system("cls");
            printf("\n>>>>>>>>>>>>>>>>>>>>>>> EXCLUIR: <<<<<<<<<<<<<<<<<<<<<<<<\n\n");

            printf("Digite o Nome do Arquivo: ");
            fflush(stdin);
            fgets(nome,20,stdin);

            aux = PesquisarArquivo(&Arquivos,nome);

            if(aux != NULL)
            {
                LibeSetores(&Setores,aux);
                RemoverArquivo(&Arquivos,aux);
                printf("\nO Arquivo Excluido com Sucesso!");
            }
            else
            {
                printf("\nO Arquivo nao Existe!");
            }
            printf("\n\n>>>>>>>>>>>>>>> MSG: Menu Disponivel...!!! <<<<<<<<<<<<<\n");

        break;

        case 3:
                // Chamada da Função Imprimir Todos
                system("cls");
                printf("\n>>>>>>>>>>>>>>>>>>> IMPRIMIR TODOS: <<<<<<<<<<<<<<<<<<<<<\n\n");

                ImprimirListaArquivos(&Arquivos);

                printf("\n\n>>>>>>>>>>>>>>> MSG: Voltando ao Menu...!!! <<<<<<<<<<<<<\n");

        break;
	}

	printf("\n");
	/// ImprimirDisco(&Disco); // Somente Para Verificação
	glutPostRedisplay();
}

// Função que Cria os Menus e Submenus e Faz a Chamada da sua Função para Tratamento
void CriarMenu()
{
    int submenu1, submenu2;

    submenu1 = glutCreateMenu(MenuArquivo);

    glutAddMenuEntry(" INSERIR ",0);
    glutAddMenuEntry(" PESQUISAR ",1);
    glutAddMenuEntry(" EXCLUIR ",2);
    glutAddMenuEntry(" IMPRIMIR TODOS ",3);

    submenu2 = glutCreateMenu(MenuDisco);

    glutAddMenuEntry(" DESFRAGMENTAR ",0);
    glutAddMenuEntry(" FORMATAR ",1);

    glutCreateMenu(MenuPrincipal);

    glutAddSubMenu(" MENU DO ARQUIVO ",submenu1);
    glutAddSubMenu(" MENU DO DISCO ",submenu2);
    glutAddMenuEntry(" SAIR ",0);

    glutAttachMenu(GLUT_RIGHT_BUTTON);

}

// Função responsável por inicializar parâmetros e variáveis
void Inicializa()
{
    // Define a janela de visualização 2D
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1,17,-1,23);
    glMatrixMode(GL_MODELVIEW);

    //Limpa a Janela de Visualização com a Cor Branca
    glClearColor(0.7,1,0.8,0);
    glClear(GL_COLOR_BUFFER_BIT);

    // Inicialização das Listas e Disco
    FLVaziaSetores(&Setores);
    FLVaziaArquivo(&Arquivos);
    FormatarDisco(&Disco,&Setores,&Arquivos);

    // Criando os Setores
    CriarSetores(&Disco,&Setores);
}

// Programa Principal
int main(int argc, char *argv[])
{
    printf("\n\t>>>>>> SISTEMA DE GERENCIAMENTO DE ARQUIVOS EM DISCO <<<<<<\n");

    glutInit(&argc,argv);

    // Define o modo de operação da Glut
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Especifica o tamanho inicial em pixels da janela
    glutInitWindowSize(1200, 1000);

    // Especifica a posição inicial da janela GLUT
    glutInitWindowPosition(0,0);

    // Cria a janela com o título passado como parâmetro
    glutCreateWindow("Sistema de Gerenciamento de Arquivos em Disco");

    // Chama a função responsável por fazer as inicializações
    Inicializa();

    //Chamada da Interface
    DesenhaDisco();

    // Registra a função callback de redesenho da janela de visualização
    glutDisplayFunc(DesenhaDisco);

    // Chamada da Função de Criação do Menu
    CriarMenu();

    // Inicia o processamento e aguarda interações do usuário
    glutMainLoop();


    FormatarDisco(&Disco,&Setores,&Arquivos);   // Limpa o Disco Apagando Todos Arquivos
    LimpaListaSetores(&Setores);                // Limpa a Lista de Setores (Apaga Todos Setore).
    free(Arquivos.primeiro);                    // Faz o Liberamento do Ponteiro Primeiro da Lista de Arquivos.
    free(Arquivos.ultimo);                      // Faz o Liberamento do Ponteiro Ultimo da Lista de Arquivos.
    free(Setores.primeiro);                     // Faz o Liberamento do Ponteiro Primeiro da Lista de Setores.
    free(Setores.ultimo);                       // Faz o Liberamento do Ponteiro Ultimo da Lista de Setores.
    aux = NULL;                                 // Faz o Aterramento do Auxiliar.
    free(aux);                                  // Faz o Liberamento do Auxiliar.


    printf("\n\n");
    return 0;
}



