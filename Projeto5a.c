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

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

// Assinatura das funções
void telaSobre();
void telaPrincipal();
void telaAdicionarLembrete();
void telaVerLembrete();
void telaEditarLembrete();
void telaApagarLembrete();

//Variáveis
int menu = 0;

// CódigoPrincipal
int main() {
    
    while(menu >= 0)
    {
        if(menu == 0) //Tela Principal
        {
            telaPrincipal();
        }
        else if(menu == 1) //Adicionar Lembretes
        {
            telaAdicionarLembrete();
        }
        else if(menu == 2) //Ver Lembretes
        {
            telaVerLembrete();
        }
        else if(menu == 3) //Editar Lembrete
        {
            telaEditarLembrete();
        }
        else if(menu == 4) //Apagar Lembrete
        {
            telaApagarLembrete();
        }
        else if(menu == 5) //Sobre
        {
            telaSobre();
        }
    }
    return 0;
}

// Funções


void telaPrincipal() {
    int optelaprincipal = 0 ;

    while(1)
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
        printf("///                                                                         ///\n");
        printf("///            1. Adicionar Lembretes                                       ///\n");
        printf("///            2. Ver Lembrentes                                            ///\n");
        printf("///            3. Editar Lembretes                                          ///\n");
        printf("///            4. Apagar Lembretes                                          ///\n");
        printf("///            5. Sobre o Programa                                          ///\n");
        printf("///            0. Sair                                                      ///\n");
        printf("///                                                                         ///\n");
        printf("///           Escolha a opcao : ");
        scanf("%d", &optelaprincipal);
        getchar();
        printf("///                                                                         ///\n");
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("\n");

        if(optelaprincipal >= 1 && optelaprincipal <= 5)
        {
            menu = optelaprincipal;
            Sleep(1000);
            break;
        }
        else if(optelaprincipal == 0)
        {
            menu = -1;
            printf("\n\tINFO: O programa será encerrado, muito obrigado pela visita.");
            Sleep(1000);
            break;
        }
        else
        {
            printf("\n\tERRO: Opção inválida, por favor tente novamente.");
            Sleep(2000);
            continue;
        }
    }
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
    printf("\t\t\t>>> Aperte <ENTER> para voltar a tela inicial...\n");
    menu = 0;
    getchar();
}

void telaAdicionarLembrete() {
    char nomeLembrete[50];
    char dataLembrete[10];
    char horaLembrete[5];

    system("cls");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///          ====================================================         ///\n");
    printf("///          = = = =   Agenda de Tarefas e Compromissos   = = = =         ///\n");
    printf("///          ====================================================         ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///           = = = = = = =   Criar Lembretes   = = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
    printf("///           Nome do Lembrete: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]" , nomeLembrete);
    getchar();
    printf("///           Data do Lembrete (dd/mm/aaaa): ");
    scanf("%[0-9/]" , dataLembrete);
    getchar();
    printf("///           Horario do Lembrete (hh:mm): ");
    scanf("%[0-9:]" , horaLembrete);
    getchar();
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n\tINFO: Lembrete adicionado com sucesso.\n");
    Sleep(500);
    menu = 0;
    printf("\n");
    printf("\t\t\t>>> Aperte <ENTER> para voltar a tela principal...\n");
    getchar();
}

void telaVerLembrete(){
    int selecionarLembrete = -1;
    int i;

    while(1)
    {
        if(selecionarLembrete == -1)
        {
            system("cls");
            printf("\n");
            printf("/////////////////////////////////////////////////////////////////////////////\n");
            printf("///                                                                       ///\n");
            printf("///          ====================================================         ///\n");
            printf("///          = = = =   Agenda de Tarefas e Compromissos   = = = =         ///\n");
            printf("///          ====================================================         ///\n");
            printf("///                                                                       ///\n");
            printf("/////////////////////////////////////////////////////////////////////////////\n");
            printf("/////////////////////////////////////////////////////////////////////////////\n");
            printf("///                                                                       ///\n");
            printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
            printf("///           = = = = = = =    Ver Lembretes    = = = = = = =             ///\n");
            printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
            printf("///                                                                       ///\n");
            printf("///                                                                       ///\n");
            for(i = 1; i <= 9; i++)
            {
                printf("///           %d - \"Lembrete do dia %d\"                                     ///\n", i , i);
            }
            printf("///           ...                                                         ///\n");
            printf("///           0 - Voltar ao menu principal                                ///\n");
            printf("///                                                                       ///\n");
            printf("///           Selecione o lembrete que deseja ver: ");
            scanf("%d", &selecionarLembrete);
            printf("///                                                                       ///\n");
            printf("/////////////////////////////////////////////////////////////////////////////\n");
            printf("\n");
            
            if(selecionarLembrete > 0 && selecionarLembrete <= 9)
            {
                system("cls");
                printf("\n");
                printf("/////////////////////////////////////////////////////////////////////////////\n");
                printf("/////////////////////////////////////////////////////////////////////////////\n");
                printf("///                                                                       ///\n");
                printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
                printf("///           = = = = = = =    Ver Lembretes    = = = = = = =             ///\n");
                printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
                printf("///                                                                       ///\n");
                printf("///                    O lembrete selecionado foi:                        ///\n");
                printf("///                                                                       ///\n");
                printf("///           (Lembrete do dia %d)                                         ///\n", selecionarLembrete);
                printf("///           (Data do Lembrete)                                          ///\n");
                printf("///           (Horario do Lembrete)                                       ///\n");
                printf("///                                                                       ///\n");
                printf("///                                                                       ///\n");
                printf("/////////////////////////////////////////////////////////////////////////////\n");
                printf("\n");
                menu = 0;
                printf("\t\t\t>>> Aperte <ENTER> para voltar ao menu principal...\n");
                getchar();
                break;
            }
            else if(selecionarLembrete == 0)
            {
                menu = 0;
                break;
            }
            else
            {
                selecionarLembrete = -1;
                printf("\n\tERRO: Número inválido, tente novamente.\n");
                Sleep(1500);
                continue;
            } 
        }
    }
}

void telaEditarLembrete(){
    char SelecionarLembreteEditar [50];
    char nomeEditar[50];
    char dataEditar[10];
    char horaEditar[5];

    system("cls");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///           = = = = = = = =  Editar Lembretes = = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("///           1- (nomedolembrete1)                                        ///\n");
    printf("///           2- (nomedolembrete2)                                        ///\n");
    printf("///           3- (nomedolembrete3)                                        ///\n");
    printf("///           ...                                                         ///\n");
    printf("///           Selecione o lembrete que deseja editar: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", SelecionarLembreteEditar);
    getchar();
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Aperte <ENTER> para continuar...\n");
    getchar();
    system("cls");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///           = = = = = = = =  Editar Lembretes = = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
    printf("///           Insira as novas informacoes:                                ///\n");
    printf("///                                                                       ///\n");
    printf("///           Nome do Lembrete: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]" , nomeEditar);
    getchar();
    printf("///           Data do Lembrete (dd/mm/aaaa): ");
    scanf("%[0-9/]" , dataEditar);
    getchar();
    printf("///           Horario do Lembrete (hh:mm): ");
    scanf("%[0-9:]" , horaEditar);
    getchar();
    printf("///           ...                                                         ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    menu = 0;
    printf("\t\t\t>>> Aperte <ENTER> para continuar...\n");
    getchar();
}

void telaApagarLembrete(){
    char SelecionarLembreteApagar [50];
    system("cls");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///           = = = = = = = =  Apagar Lembretes = = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("///           1- (nomedolembrete1)                                        ///\n");
    printf("///           2- (nomedolembrete2)                                        ///\n");
    printf("///           3- (nomedolembrete3)                                        ///\n");
    printf("///           ...                                                         ///\n");
    printf("///           Selecione o lembrete que deseja Apagar: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", SelecionarLembreteApagar);
    getchar();
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Aperte <ENTER> para continuar...\n");
    getchar();
    system("cls");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///           = = = = = = = =  Apagar Lembretes = = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("///                   Lembrete selecionado foi apagado                    ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    menu = 0;
    printf("\t\t\t>>> Aperte <ENTER> para continuar...\n");
    getchar();
}
