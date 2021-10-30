///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///             Centro de Ensino Superior do Seridó                         ///
///             Departamento de Computação e Tecnologia                     ///
///             Disciplina DCT1106 -- Programação                           ///
///             Projeto Uma Agenda de Tarefas e Compromissos                ///
///             Developed by  @lukaz06 - Out, 2021                          ///
///////////////////////////////////////////////////////////////////////////////


// Assinatura das funções
    void telaSobre();
    void telaPrincipal();
    void telaAdicionarLembrete(); 
    void telaVerLembrete();  
    void telaEditarLembrete(); 
    void telaApagarLembrete(); 
    

























// CódigoPrincipal 

#include <stdio.h> 
int main() { 
    telaSobre();
    telaPrincipal();
    telaAdicionarLembrete();
    telaVerLembrete();
    telaEditarLembrete(); 
    telaApagarLembrete();
//(apresentação de telas)
    return 0;
} 


// Funções 
void telaSobre() {
    system("clear||cls");
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
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
} 



void telaPrincipal() {
    system("clear||cls");
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
    printf("///            1. Adicionar Lembretes                                      ///\n");
    printf("///            2. Ver Lembrentes                                            ///\n");
    printf("///            3. Editar Lembretes                                         ///\n");
    printf("///            4. Apagar Lembretes                                         ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
} 



void telaAdicionarLembrete() { 
    system("clear||cls");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///          ===================================================          ///\n");
    printf("///          = = = =   Agenda de Tarefas e Compromissos   = = = =         ///\n");
    printf("///          ===================================================          ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///           = = = = = = =   Criar Lembretes   = = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n"); 
    printf("///           Nome do Lembrete:                                           ///\n");
    printf("///           Data do Lembrete (dd/mm/aaaa):                              ///\n");
    printf("///           Horario do Lembrete (hh:mm):                                ///\n"); 
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
} 



void telaVerLembrete(){ 
    system("clear||cls");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///          ===================================================          ///\n");
    printf("///          = = = =   Agenda de Tarefas e Compromissos   = = = =         ///\n");
    printf("///          ===================================================          ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///           = = = = = = =    Ver Lembretes    = = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n"); 
    printf("///           Selecione o lembrete que deseja ver:                        ///\n"); 
    printf("///                                                                       ///\n"); 
    printf("///           1- (nomedolembrete1)                                        ///\n");
    printf("///           2- (nomedolembrete2)                                        ///\n");
    printf("///           3- (nomedolembrete3)                                        ///\n"); 
    printf("///           ...                                                         ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();     
    system("clear||cls");
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
    printf("///           (Nome do Lembrete)                                          ///\n");
    printf("///           (Data do Lembrete)                                          ///\n");
    printf("///           (Horario do Lembrete)                                       ///\n"); 
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}



void telaEditarLembrete(){
    system("clear||cls");
    printf("\n"); 
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///           = = = = = = = =  Editar Lembretes = = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n"); 
    printf("///           Selecione o lembrete que deseja editar:                     ///\n"); 
    printf("///                                                                       ///\n"); 
    printf("///           1- (nomedolembrete1)                                        ///\n");
    printf("///           2- (nomedolembrete2)                                        ///\n");
    printf("///           3- (nomedolembrete3)                                        ///\n"); 
    printf("///           ...                                                         ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); 
    system("clear||cls");
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
    printf("///           Nome do Lembrete:                                           ///\n");
    printf("///           Data do Lembrete (dd/mm/aaaa):                              ///\n");
    printf("///           Horario do Lembrete (hh:mm):                                ///\n"); 
    printf("///           ...                                                         ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();  
} 



void telaApagarLembrete(){
    system("clear||cls");
    printf("\n"); 
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///           = = = = = = = =  Apagar Lembretes = = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n"); 
    printf("///           Selecione o lembrete que deseja Apagar:                     ///\n"); 
    printf("///                                                                       ///\n"); 
    printf("///           1- (nomedolembrete1)                                        ///\n");
    printf("///           2- (nomedolembrete2)                                        ///\n");
    printf("///           3- (nomedolembrete3)                                        ///\n"); 
    printf("///           ...                                                         ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    system("clear||cls");
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
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}