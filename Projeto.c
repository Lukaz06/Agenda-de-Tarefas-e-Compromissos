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
#include "lembrete.h"
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
int vData(int dia, int mes, int ano);
int vHora(int hora, int min);
void limpar(void);
void criar_menu(int opcoes, int soma);
void Msg(char msg[256]);
int abrirArquivo(char Arquivo[128], char* StrF);

//Funções de Usuários
void registrarUsuario(char rNome[128], char rCelular[12], char rCidade[128], char rEndereco[128], char rUsername[32], char rSenha[128], int rDia, int rMes, int rAno, int rMod);
int getLastUser(int modo);
void carregarUsuarios();
void LoginUsuario(int id);

//Funções externas
extern void Lembretes(int id_menu);
struct usuarioEstrutura Usuarios[MAX_USUARIOS];
struct tarefasEstrutura Tarefas[MAX_TAREFAS];
extern void carregarLembretes();
extern void verTarefas();
extern int contTasks(char usuario[128]);

//Variáveis
int menu = 0;
int login = 0;

// CódigoPrincipal
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

            char rNome[128], rCelular[12], rCidade[128], rEndereco[128], rUsername[32], rSenha[128];
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
                    etapa++;
                }
                else if(etapa == 1) //Data de Nascimento
                {
                    printf("\t Informe sua data de nascimento (Exemplo: 17/09/1997): ");
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
                    etapa++;
                }
                else if(etapa == 4) //Endereço
                {
                    printf("\t Informe seu endereço: ");
                    if(scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ.,0-9]", rEndereco) != 1) {
                        Msg("Endereço inválido.");
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
                    etapa++;
                }
                else if(etapa == 6) //Senha
                {
                    printf("\t Informe sua senha: ");
                    if(scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ.,@#$()0-9]", rSenha) != 1) {
                        Msg("Senha inválida.");
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
    printf("\t\t\t>>> Aperte <ENTER> para voltar a tela inicial...\n");
    menu = 0;
}

//Função de validação de datas
int vData(int dia, int mes, int ano) {
    if (ano >= 1900 && ano <= 9999) {
        if (mes >= 1 && mes <= 12) {
            if ((dia >= 1 && dia <= 31) && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12))
                return 1;
            else if ((dia >= 1 && dia <= 30) && (mes == 4 || mes == 6 || mes == 9 || mes == 11))
                return 1;
            else if ((dia >= 1 && dia <= 28) && (mes == 2))
                return 1;
            else if (dia == 29 && mes == 2 && (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0)))
                return 1;
            else
                return 0;
        }
        else return 0;
    }
    return 0;
}

//Função de validação de hora
int vHora(int hora, int min)
{
    if(hora >= 0 && hora <= 23)
    {
        if(min >= 0 && min <= 59)
            return 1;
        else
            return 0;
    }
    return 0;
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

void registrarUsuario(char rNome[128], char rCelular[12], char rCidade[128], char rEndereco[128], char rUsername[32], char rSenha[128], int rDia, int rMes, int rAno, int rMod)
{
    char nome_arquivo[50];
    FILE *file; //Criando variável para manipulação de arquivos
    sprintf(nome_arquivo, PASTA_USUARIOS, getLastUser(1));
    file = fopen(nome_arquivo, "w"); //Abrindo o arquivo

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

    int id = getLastUser(0);
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
            file = fopen(nome_arquivo, "r");
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

void carregarUsuarios(void)
{
    char Lukas[256], nome_arquivo[50], strObtida[256], *intAux[10], *token;
    int i, x = 0;

    for(i = 0; i < MAX_USUARIOS; i++)
    {
        x = 0;

        sprintf(nome_arquivo, PASTA_USUARIOS, i);
        
        if(abrirArquivo(nome_arquivo, Lukas))
        {
            token = strtok(Lukas, "\n");
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

int abrirArquivo(char Arquivo[128], char* StrF)
{
    char texto[256];
    strcpy(StrF, "");

    FILE *file; //Criando variável para manipulação de arquivos
    file = fopen(Arquivo, "r");
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