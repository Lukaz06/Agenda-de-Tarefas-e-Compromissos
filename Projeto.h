///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///             Centro de Ensino Superior do Seridó                         ///
///             Departamento de Computação e Tecnologia                     ///
///             Disciplina DCT1106 -- Programação                           ///
///             Projeto Uma Agenda de Tarefas e Compromissos                ///
///             Developed by  @lukaz06 - Out, 2021                          ///
///////////////////////////////////////////////////////////////////////////////

#define MAX_USUARIOS        50
#define MAX_TAREFAS         300
#define PASTA_USUARIOS      "Usuarios\\Usuario_%d.txt"
#define PASTA_TAREFAS       "Tarefas\\Tarefa_%d.txt"

//Estruturas
struct usuarioDataNascimento {
    int dia, mes, ano;
};

struct usuarioEstrutura
{
    char nome[128];
    char celular[12];
    char cidade[128];
    char endereco[128];
    char usuario[32];
    char senha[128];
    int mod;
    struct usuarioDataNascimento nascimento;
};

struct tarefasEstrutura
{
    char usuario[32]; //Usuário que cadastrou a tarefa
    char nome[128]; //Nome da tarefa
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
    int realizada; //Se foi (1) ou não (0) realizada
};

extern struct usuarioEstrutura Usuarios[MAX_USUARIOS];
extern struct tarefasEstrutura Tarefas[MAX_TAREFAS];
