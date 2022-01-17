///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///             Centro de Ensino Superior do Seridó                         ///
///             Departamento de Computação e Tecnologia                     ///
///             Disciplina DCT1106 -- Programação                           ///
///             Projeto Uma Agenda de Tarefas e Compromissos                ///
///             Developed by  @lukaz06 - Out, 2021                          ///
///////////////////////////////////////////////////////////////////////////////

//Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lembrete.h"
#include "utilidades.h"
#include "Projeto.h"

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

//Definições
#define MENU_PRINCIPAL      10
#define MENU_LOGIN          20

// Assinatura das funções
void telaSobre();
void telaPrincipal();
void telaLogin();
void titulo(char title[128]);
void limpar(void);
void criar_menu(int opcoes, int soma);
void Msg(char msg[256]);
int abrirArquivo(char Arquivo[128], char* StrF);
int openFile(char Arquivo[128]);

//Funções de Usuários
void registrarUsuario(char rNome[128], char rCelular[12], char rCidade[128], char rEndereco[128], char rUsername[32], char rSenha[128], int rDia, int rMes, int rAno, int rMod);
int getLastUser(int modo);
void carregarUsuarios();
void LoginUsuario(int id);
int uExists(char usuario[128], int modo);
int alterarUsuario(int id, char what[128], char campo[256]);
int excluirUsuario(char usuario[32]);

//Funções externas
extern void Lembretes(int id_menu);
struct usuarioEstrutura Usuarios[MAX_USUARIOS];
struct tarefasEstrutura Tarefas[MAX_TAREFAS];
extern void carregarLembretes();
extern void verTarefas();
extern int contTasks(char usuario[128]);
extern int vData(int dia, int mes, int ano);
extern int vHora(int hora, int min);
extern void pausa(int seg);

//Variáveis
int menu = 0;
int login = 0;

#define LINHAS_ARQUIVO 10

char matriz[LINHAS_ARQUIVO][256];

// Código Principal
int main() {

    carregarUsuarios();
    carregarLembretes();

    while(menu >= 0)
    {
        if(menu == 0) //Tela Principal
        {
            if(login == -1)
            {
                telaLogin();
                criar_menu(2, MENU_LOGIN);
            }
            else
            {
                telaPrincipal();
                criar_menu(4, MENU_PRINCIPAL);
            }
            
        }
        else if(menu == MENU_PRINCIPAL+1 || menu == MENU_PRINCIPAL+2 || menu == MENU_PRINCIPAL+3 || menu == MENU_PRINCIPAL+4)
        {
            Lembretes(menu-MENU_PRINCIPAL);
        }
        else if(menu == MENU_LOGIN+1 || menu == MENU_LOGIN+2) //Login e Registro
        {
            LoginUsuario(menu-MENU_LOGIN);
        }
    }

    printf("\n\tINFO: O programa será encerrado, muito obrigado pela visita.");
    Sleep(1000);
    return 0;
}

void LoginUsuario(int id)
{
    int etapa;

    switch (id)
    {
        case 1: //Login
        {
            etapa = 0;
            char lUsername[32], lSenha[128];
            int i;

            while(1)
            {
                titulo("///          = = = = = = = = = = =  Login!  = = = = = = = = = = =         ///");

                limpar();
                printf("\n\t Informe o seu nome de usuário: ");
                if(scanf("%[A-Za-z_]", lUsername) != 1) {
                    Msg("Usuário inválido.");
                    continue;
                }

                limpar();
                printf("\n\t Informe sua senha: ");
                if(scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ.,@#$()0-9]", lSenha) != 1) {
                    Msg("Senha inválida.");
                    continue;
                }

                for(i=0; i < MAX_USUARIOS; i++)
                {
                    if (strcmp(Usuarios[i].usuario, lUsername) == 0)
                    {
                        if(strcmp(Usuarios[i].senha, lSenha) == 0)
                        {
                            login = i;
                            break;
                        }
                    }
                }

                if(login == -1)
                {
                    Msg("Usuário e/ou senha inválidos.");
                    continue;
                }
                else
                {
                    menu = 0;
                    break;
                }
            }
        }
        break;

        case 2: //Registro
        {
            etapa = 0;

            char rNome[128], rCelular[12], rCidade[128], rEndereco[128], rUsername[128], rSenha[128];
            int dia, mes, ano, decisao;

            while (1)
            {
                titulo("///          = = = = = = = = = = = Registro = = = = = = = = = = =         ///");
                
                limpar();

                if(etapa == 0) //Nome
                {
                    printf("\t Informe seu nome e sobrenome: ");
                    if(scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", rNome) != 1) {
                        Msg("Nome inválido.");
                        continue;
                    }

                    if(strlen(rNome) >= 100) {
                        Msg("O limite máximo de caracteres é 100.");
                        continue;
                    }

                    etapa++;
                }
                else if(etapa == 1) //Data de Nascimento
                {
                    printf("\t Informe sua data de nascimento (Exemplo: 15/02/1995): ");
                    scanf("%d/%d/%d", &dia, &mes, &ano);

                    if((vData(dia, mes, ano) == 0)) {
                        Msg("Data inválida.");
                        continue;
                    }
                    etapa++;
                }
                else if(etapa == 2) //Número de Celular
                {
                    printf("\t Informe seu número de celular (somente números): ");
                    if((scanf("%[0-9]", rCelular) != 1) || (strlen(rCelular) != 11)) {
                        Msg("Número de celular inválido.");
                        continue;
                    }
                    etapa++;
                }
                else if(etapa == 3) //Cidade
                {
                    printf("\t Informe a cidade que você reside: ");
                    if(scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", rCidade) != 1) {
                        Msg("Cidade inválida.");
                        continue;
                    }

                    if(strlen(rCidade) >= 120) {
                        Msg("O limite máximo de caracteres é 120.");
                        continue;
                    }
                    etapa++;
                }
                else if(etapa == 4) //Endereço
                {
                    printf("\t Informe seu endereço: ");
                    if(scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ.,0-9]", rEndereco) != 1) {
                        Msg("Endereço inválido.");
                        continue;
                    }

                    if(strlen(rEndereco) >= 120) {
                        Msg("O limite máximo de caracteres é 120.");
                        continue;
                    }

                    etapa++;
                }
                else if(etapa == 5) //Nome de usuário
                {
                    printf("\tInforme o seu nome de usuário (exemplo: Susu_Gostoso): ");
                    if(scanf("%[A-Za-z_]", rUsername) != 1) {
                        Msg("Usuário inválido.");
                        continue;
                    }

                    if(uExists(rUsername, 0) != -1) {
                        Msg("Usuário já cadastrado no sistema.");
                        continue;
                    }

                    if(strlen(rUsername) >= 32) {
                        Msg("O limite máximo de caracteres é 32.");
                        continue;
                    }

                    etapa++;
                }
                else if(etapa == 6) //Senha
                {
                    printf("\t Informe sua senha: ");
                    if(scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ.,@#$()0-9]", rSenha) != 1) {
                        Msg("Senha inválida.");
                        continue;
                    }

                    if(strlen(rSenha) >= 40) {
                        Msg("O limite máximo de caracteres é 40.");
                        continue;
                    }

                    break;
                }
            }

            titulo("///          = = = = = = = = = = = Registro = = = = = = = = = = =         ///");
            
            //Informações Obtidas
            printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=[ Informações obtidas ]=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("\n\tNome: %s\n", rNome);
            printf("\n\tData de Nascimento: %d/%d/%d\n", dia, mes, ano);
            printf("\n\tCelular: %s\n", rCelular);
            printf("\n\tCidade: %s\n", rCidade);
            printf("\n\tEndereço: %s\n", rEndereco);
            printf("\n\tNome de usuário: %s\n", rUsername);
            printf("\n\tSenha: %s\n", rSenha);
            printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        
            limpar();

            printf("\n\t As informações estão corretas? (1-SIM, 0-NÃO): ");
            if(scanf("%d", &decisao) != 1) {
                menu = 0;
                break;
            }

            if(decisao != 1) {
                menu = 0;
                break;
            }

            registrarUsuario(rNome, rCelular, rCidade, rEndereco, rUsername, rSenha, dia, mes, ano, 0);

            printf("\n\t Usuário cadastrado com sucesso!");
            Sleep(1500);
            menu = 0;
        }
        break;
    }
}

void telaLogin(void)
{
    system("cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                Universidade Federal do Rio Grande do Norte              ///\n");
    printf("///                Centro de Ensino Superior do Serido                      ///\n");
    printf("///                Departamento de Computaçao e Tecnologia                  ///\n");
    printf("///                Disciplina DCT1106 -- Programaçao                        ///\n");
    printf("///                Projeto Uma Agenda de Tarefas e Compromissos             ///\n");
    printf("///                Developed by  @lukaz06 - Out, 2021                       ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///        = = = = = Agenda de Tarefas e Compromissos = = = = =             ///\n");
    printf("///        = = = = = = =  Tela de Login/Cadastro  = = = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Login                                                     ///\n");
    printf("///            2. Registro                                                  ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}

// Funções
void telaPrincipal() {
    system("cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                Universidade Federal do Rio Grande do Norte              ///\n");
    printf("///                Centro de Ensino Superior do Serido                      ///\n");
    printf("///                Departamento de Computaçao e Tecnologia                  ///\n");
    printf("///                Disciplina DCT1106 -- Programaçao                        ///\n");
    printf("///                Projeto Uma Agenda de Tarefas e Compromissos             ///\n");
    printf("///                Developed by  @lukaz06 - Out, 2021                       ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///        = = = = = Agenda de Tarefas e Compromissos = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Adicionar Lembretes                                       ///\n");
    printf("///            2. Gerenciar Lembrentes                                      ///\n");
    printf("///            3. Meus dados                                                ///\n");
    printf("///            4. Sobre o Programa                                          ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}

void telaSobre() {
    system("cls");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                           ///\n");
    printf("///     = = = = = Projeto Uma Agenda de Tarefas e Compromissos = = = = =      ///\n");
    printf("///                                                                           ///\n");
    printf("///  Um programa de computador que realiza o agendamento de tarefas, de forma ///\n");
    printf("///  eficiente, fornecendo lembretes ao usuario sobre compromissos agendados. ///\n");
    printf("///                                                                           ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    getchar();
    getchar();
    printf("\t\t\t>>> Aperte <ENTER> para voltar a tela inicial...\n");
    menu = 0;
}

void criar_menu(int opcoes, int soma)
{
    int chose;

    limpar();
    printf("\n\t>>> Digite a opção que deseja escolher: ");
    scanf("%d", &chose);

    if(chose >= 1 && chose <= opcoes) {
        chose += soma;
        menu = chose;
    }
    else if(chose == 0) {
        if(menu == 0) {
            menu = -1;
        }
        else {
            menu = 0;
        }
    }
    else {
        printf("\n\t ERRO: Opção inválida, tente novamente. ");
        Sleep(1000);
        menu = 0;
    }
}

void limpar(void) // Funçao utilitária para limpar o buffer do teclado
{
    setbuf(stdin, NULL);
}

void titulo(char title[128])
{
    system("cls");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///          ====================================================         ///\n");
    printf("///          = = = =   Agenda de Tarefas e Compromissos   = = = =         ///\n");
    printf("%s\n", title);
    printf("///          ====================================================         ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}

void Msg(char msg[256])
{
    printf("\n\t ERRO: %s", msg);
    Sleep(1500);
}

int uExists(char usuario[128], int modo)
{
    char Lukas[256], nome_arquivo[50], strObtida[256], *token;
    int i, x = 0, valor = -1;

    for(i = 0; i < MAX_USUARIOS; i++)
    {
        x = 0;

        if(modo == 1) //Arquivo
        {
            sprintf(nome_arquivo, PASTA_USUARIOS, i);
            if(abrirArquivo(nome_arquivo, Lukas))
            {
                token = strtok(Lukas, "\n");
                while( token != NULL )
                {
                    sprintf(strObtida, "%s", token);

                    if(x == 4) //Nome de usuário
                    {
                        if(strcmp(usuario, strObtida) == 0)
                        {
                            valor = i;
                            break;
                        }
                    }
                    token = strtok(NULL, "\n");
                    x++;
                }
            }
        }
        else //Variável
        {
            if (strcmp(Usuarios[i].usuario, usuario) == 0)
            {
                valor = i;
                break;
            }
        }
    }
    return valor;
    
}

int alterarUsuario(int id, char what[128], char campo[256])
{
    int numerico;
    char *tmpNumero[20];

    if (strcmp(what, "nome") == 0) {
        registrarUsuario(campo, Usuarios[id].celular, Usuarios[id].cidade, Usuarios[id].endereco, Usuarios[id].usuario, Usuarios[id].senha, Usuarios[id].nascimento.dia, Usuarios[id].nascimento.mes, Usuarios[id].nascimento.ano, Usuarios[id].mod);
    } 
    else if (strcmp(what, "celular") == 0) {
        registrarUsuario(Usuarios[id].nome, campo, Usuarios[id].cidade, Usuarios[id].endereco, Usuarios[id].usuario, Usuarios[id].senha, Usuarios[id].nascimento.dia, Usuarios[id].nascimento.mes, Usuarios[id].nascimento.ano, Usuarios[id].mod);
    }
    else if (strcmp(what, "cidade") == 0) {
        registrarUsuario(Usuarios[id].nome, Usuarios[id].celular, campo, Usuarios[id].endereco, Usuarios[id].usuario, Usuarios[id].senha, Usuarios[id].nascimento.dia, Usuarios[id].nascimento.mes, Usuarios[id].nascimento.ano, Usuarios[id].mod);
    }
    else if (strcmp(what, "endereco") == 0) {
        registrarUsuario(Usuarios[id].nome, Usuarios[id].celular, Usuarios[id].cidade, campo, Usuarios[id].usuario, Usuarios[id].senha, Usuarios[id].nascimento.dia, Usuarios[id].nascimento.mes, Usuarios[id].nascimento.ano, Usuarios[id].mod);
    }
    else if (strcmp(what, "senha") == 0) {
        registrarUsuario(Usuarios[id].nome, Usuarios[id].celular, Usuarios[id].cidade, Usuarios[id].endereco, Usuarios[id].usuario, campo, Usuarios[id].nascimento.dia, Usuarios[id].nascimento.mes, Usuarios[id].nascimento.ano, Usuarios[id].mod);
    }
    else if (strcmp(what, "dia") == 0) {
        numerico = strtol(campo, tmpNumero, 10);
        registrarUsuario(Usuarios[id].nome, Usuarios[id].celular, Usuarios[id].cidade, Usuarios[id].endereco, Usuarios[id].usuario, Usuarios[id].senha, numerico, Usuarios[id].nascimento.mes, Usuarios[id].nascimento.ano, Usuarios[id].mod);
    }
    else if (strcmp(what, "mes") == 0) {
        numerico = strtol(campo, tmpNumero, 10);
        registrarUsuario(Usuarios[id].nome, Usuarios[id].celular, Usuarios[id].cidade, Usuarios[id].endereco, Usuarios[id].usuario, Usuarios[id].senha, Usuarios[id].nascimento.dia, numerico, Usuarios[id].nascimento.ano, Usuarios[id].mod);
    }
    else if (strcmp(what, "ano") == 0) {
        numerico = strtol(campo, tmpNumero, 10);
        registrarUsuario(Usuarios[id].nome, Usuarios[id].celular, Usuarios[id].cidade, Usuarios[id].endereco, Usuarios[id].usuario, Usuarios[id].senha, Usuarios[id].nascimento.dia, Usuarios[id].nascimento.mes, numerico, Usuarios[id].mod);
    }
    else if (strcmp(what, "mod") == 0) {
        numerico = strtol(campo, tmpNumero, 10);
        registrarUsuario(Usuarios[id].nome, Usuarios[id].celular, Usuarios[id].cidade, Usuarios[id].endereco, Usuarios[id].usuario, Usuarios[id].senha, Usuarios[id].nascimento.dia, Usuarios[id].nascimento.mes, Usuarios[id].nascimento.ano, numerico);
    }
    else {
        return 0;
    }
    return 1;
}

void registrarUsuario(char rNome[128], char rCelular[12], char rCidade[128], char rEndereco[128], char rUsername[32], char rSenha[128], int rDia, int rMes, int rAno, int rMod)
{
    int id_arq = uExists(rUsername, 1);

    char nome_arquivo[50];
    FILE *file; //Criando variável para manipulação de arquivos
    
    if(id_arq != -1) { //Usuário existe
        sprintf(nome_arquivo, PASTA_USUARIOS, id_arq);
    }
    else { //Usuário não existe
        sprintf(nome_arquivo, PASTA_USUARIOS, getLastUser(1));
    }
    file = fopen(nome_arquivo, "wt"); //Abrindo o arquivo

    fprintf(file, "%s\n", rNome); //Nome Completo
    fprintf(file, "%s\n", rCelular); //Celular
    fprintf(file, "%s\n", rCidade); //Cidade
    fprintf(file, "%s\n", rEndereco); //Endereço
    fprintf(file, "%s\n", rUsername); //Nome de Usuário
    fprintf(file, "%s\n", rSenha); //Senha
    fprintf(file, "%d\n", rDia); //Dia de Nascimento
    fprintf(file, "%d\n", rMes); //Mês de Nascimento
    fprintf(file, "%d\n", rAno); //Ano de Nascimento
    fprintf(file, "%d", rMod); //Nivel de moderação (1 ou 0)
    fclose(file); //Fechamento do arquivo

    int id = uExists(rUsername, 0);
    if(id == -1) {
        id = getLastUser(0);
    }

    strcpy(Usuarios[id].nome, rNome);
    strcpy(Usuarios[id].celular, rCelular);
    strcpy(Usuarios[id].cidade, rCidade);
    strcpy(Usuarios[id].endereco, rEndereco);
    strcpy(Usuarios[id].usuario, rUsername);
    strcpy(Usuarios[id].senha, rSenha);
    Usuarios[id].nascimento.dia = rDia;
    Usuarios[id].nascimento.mes = rMes;
    Usuarios[id].nascimento.ano = rAno;
    Usuarios[id].mod = rMod;
}

int getLastUser(int modo)
{
    int i = 0;
    char nome_arquivo[50];

    if(modo == 1) //Arquivo
    {
        while (i < MAX_USUARIOS)
        {
            FILE *file;
            sprintf(nome_arquivo, PASTA_USUARIOS, i);
            file = fopen(nome_arquivo, "rt");
            if((file != NULL)) {
                i++;
                fclose(file);
                continue;
            }
            break;
        }
    }
    else //Variável do Estruct
    {
        for(i = 0; i < MAX_USUARIOS; i++)
        {
            if (strcmp(Usuarios[i].nome, "$") == 0) {
                break;
            }
        }
    }
    return i;
}

int excluirUsuario(char usuario[32])
{
    char nome_arquivo[50];
    int id_arq = uExists(usuario, 1);
    int id_var = uExists(usuario, 0);

    if(id_arq == -1 || id_var == -1) {
        return 0;
    }

    sprintf(nome_arquivo, PASTA_USUARIOS, id_arq);
    remove(nome_arquivo);

    strcpy(Usuarios[id_var].nome, "$");
    strcpy(Usuarios[id_var].usuario, "$");
    
    if(id_var == login) {
        login = -1;
    }
    return 1;
}

void carregarUsuarios(void)
{
    char ArquivoCompleto[512], 
        nome_arquivo[50], 
        strObtida[256], 
        *intAux[10], 
        *token;

    int i, x;

    for(i = 0; i < MAX_USUARIOS; i++)
    {
        x = 0;

        sprintf(nome_arquivo, PASTA_USUARIOS, i);
        
        if(abrirArquivo(nome_arquivo, ArquivoCompleto))
        {
            token = strtok(ArquivoCompleto, "\n");
            while( token != NULL )
            {
                sprintf(strObtida, "%s", token);
                switch (x)
                {
                    case 0: 
                        strcpy(Usuarios[i].nome, strObtida);
                        break;
                    case 1: 
                        strcpy(Usuarios[i].celular, strObtida);
                        break;
                    case 2: 
                        strcpy(Usuarios[i].cidade, strObtida);
                        break;
                    case 3: 
                        strcpy(Usuarios[i].endereco, strObtida);
                        break;
                    case 4: 
                        strcpy(Usuarios[i].usuario, strObtida);
                        break;
                    case 5: 
                        strcpy(Usuarios[i].senha, strObtida);
                        break;
                    case 6: 
                        Usuarios[i].nascimento.dia = strtol(strObtida, intAux, 10);
                        break;
                    case 7: 
                        Usuarios[i].nascimento.mes = strtol(strObtida, intAux, 10);
                        break;
                    case 8: 
                        Usuarios[i].nascimento.ano = strtol(strObtida, intAux, 10);
                        break;
                    case 9: 
                        Usuarios[i].mod = strtol(strObtida, intAux, 10);
                        break;
                }
                token = strtok(NULL, "\n");
                x++;
            }
        }
        else {
            strcpy(Usuarios[i].nome, "$");
        }
    } //Fim do for
}

int openFile(char Arquivo[128])
{
    char texto[512], ArquivoCompleto[512], *token;
    int i = 0;

    strcpy(ArquivoCompleto, "");

    for(i = 0; i < 10; i++) {
        strcpy(matriz[i], "#");
    }

    FILE *file; //Criando variável para manipulação de arquivos
    file = fopen(Arquivo, "rt"); //Abrindo o arquivo
    if((file != NULL)) { //Se o arquivo existir
        while(fgets(texto, sizeof(texto), file) != NULL) {
            strcat(ArquivoCompleto, texto);
        }
    } 
    else return 0;

    token = strtok(ArquivoCompleto, "\n");
    i = 0;
    while( token != NULL ) {
        strcpy(matriz[i], token);
        token = strtok(NULL, "\n");
        i++;
    }
    fclose(file);
    return 1;
}

int abrirArquivo(char Arquivo[128], char* StrF)
{
    char texto[512];
    strcpy(StrF, "");

    FILE *file; //Criando variável para manipulação de arquivos
    file = fopen(Arquivo, "rt");
    if((file != NULL)) {
        while(fgets(texto, sizeof(texto), file) != NULL) {
            strcat(StrF, texto);
        }
    } 
    else {
        fclose(file);
        return 0;
    }
    fclose(file);
    return 1;
}

