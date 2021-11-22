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
int vData(int dia, int mes, int ano);
int vHora(int hora, int min);

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
    char nomeLembrete[100];
    int dia, mes, ano, hora, minuto;

    while(1)
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
        printf("///           = = = = = = =   Criar Lembretes   = = = = = = =             ///\n");
        printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
        printf("///                                                                       ///\n");
        
        //Nome do lembrete
        printf("///           Nome do Lembrete: ");
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]" , nomeLembrete);
        
        //Data do Lembrete
        printf("///           Data do Lembrete (dd/mm/aaaa): ");
        scanf("%d/%d/%d", &dia, &mes, &ano);
        if(vData(dia, mes, ano) == 0) { //Verificação de data válida
            printf("\n\tERRO: Data inválida.\n");
            Sleep(1000);
            continue;
        }
        
        //Horário do Lembrete
        printf("///           Horario do Lembrete (hh:mm): ");
        scanf("%d:%d", &hora, &minuto);

        if(vHora(hora, minuto) == 0) {
            printf("\n\tERRO: Hora inválida.\n");
            Sleep(1000);
            continue;
        }
        printf("///                                                                       ///\n");
        printf("///                                                                       ///\n");
        printf("/////////////////////////////////////////////////////////////////////////////\n");
        break;
    }
    printf("\n\tINFO: Lembrete adicionado com sucesso.\n");
    Sleep(1500);
    menu = 0;

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
            
            if(selecionarLembrete > 0 && selecionarLembrete <= 9) {
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
            else if(selecionarLembrete == 0) {
                menu = 0;
                break;
            }
            else {
                selecionarLembrete = -1;
                printf("\n\tERRO: Número inválido, tente novamente.\n");
                Sleep(1500);
                continue;
            } 
        }
    }
}

void telaEditarLembrete() {
    int SelecionarLembreteEditar = -1;
    char nomeEditar[50];
    int dia, mes, ano, hora, minuto;

    while(1)
    {
        if(SelecionarLembreteEditar == -1)
        {
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
            printf("///           4- (nomedolembrete4)                                        ///\n");
            printf("///           5- (nomedolembrete5)                                        ///\n");
            printf("///           6- (nomedolembrete6)                                        ///\n");
            printf("///           7- (nomedolembrete7)                                        ///\n");
            printf("///           8- (nomedolembrete8)                                        ///\n");
            printf("///           9- (nomedolembrete9)                                        ///\n");
            printf("///          10- (nomedolembrete10)                                       ///\n");
            printf("///           ...                                                         ///\n");
            printf("///           0- Voltar ao menu inicial                                   ///\n");
            printf("///                                                                       ///\n");
            printf("///           Selecione o lembrete que deseja editar: ");
            scanf("%d", &SelecionarLembreteEditar);
            printf("///                                                                       ///\n");
            printf("/////////////////////////////////////////////////////////////////////////////\n");
            Sleep(1000);
        }
        
        if(SelecionarLembreteEditar >= 1 && SelecionarLembreteEditar <= 10) //Se for maior ou igual a zero e menor ou igual a 10, deu certo
        {
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
            
            //Nome do lembrete
            printf("///           Nome do Lembrete: ");
            scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]" , nomeEditar);
            
            //Data do Lembrete
            printf("///           Data do Lembrete (dd/mm/aaaa): ");
            scanf("%d/%d/%d", &dia, &mes, &ano);
            if(vData(dia, mes, ano) == 0) { //Verificação de data válida
                printf("\n\tERRO: Data inválida.\n");
                Sleep(1000);
                continue;
            }
            
            //Horário do Lembrete
            printf("///           Horario do Lembrete (hh:mm): ");
            scanf("%d:%d", &hora, &minuto);

            if(vHora(hora, minuto) == 0) {
                printf("\n\tERRO: Hora inválida.\n");
                Sleep(1000);
                continue;
            }
            printf("///           ...                                                         ///\n");
            printf("///                                                                       ///\n");
            printf("/////////////////////////////////////////////////////////////////////////////\n");
            printf("\n");
        }
        else if(SelecionarLembreteEditar == 0) {
            menu = 0;
            break;
        }
        else {
            SelecionarLembreteEditar = -1;
            printf("\n\tERRO: Lembrete inválido.\n");
            Sleep(1000);
            continue;
        }

        printf("\n\t\tLEMBRETE ALTERADO COM SUCESSO! Voltando ao menu inicial...\n");
        menu = 0;
        Sleep(1500);
        break;
    }
}

void telaApagarLembrete(){
    int SelecionarLembreteApagar;
    
    while(1)
    {
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
        printf("///           4- (nomedolembrete4)                                        ///\n");
        printf("///           5- (nomedolembrete5)                                        ///\n");
        printf("///           6- (nomedolembrete6)                                        ///\n");
        printf("///           7- (nomedolembrete7)                                        ///\n");
        printf("///           8- (nomedolembrete8)                                        ///\n");
        printf("///           9- (nomedolembrete9)                                        ///\n");
        printf("///          10- (nomedolembrete10)                                       ///\n");
        printf("///           ...                                                         ///\n");
        printf("///           0- Voltar ao menu inicial                                   ///\n");
        printf("///                                                                       ///\n");
        printf("///           Selecione o lembrete que deseja Apagar: ");
        scanf("%d", &SelecionarLembreteApagar);
        printf("///                                                                       ///\n");
        printf("///                                                                       ///\n");
        printf("/////////////////////////////////////////////////////////////////////////////\n");
        printf("\n");
        if(SelecionarLembreteApagar >= 1 && SelecionarLembreteApagar <= 10) {
            Sleep(1000);
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
            printf("\n\n\tVOLTANDO AO MENU INICIAL...\n");
            Sleep(1500);
            break;
        }
        else if(SelecionarLembreteApagar == 0) {
            break;
        }
        else {
            printf("\n\tERRO: Lembrete inválido.\n");
            Sleep(1000);
            continue;
        }
    }
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
