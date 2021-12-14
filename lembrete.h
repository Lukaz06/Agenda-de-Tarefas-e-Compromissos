///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///             Centro de Ensino Superior do Seridó                         ///
///             Departamento de Computação e Tecnologia                     ///
///             Disciplina DCT1106 -- Programação                           ///
///             Projeto Uma Agenda de Tarefas e Compromissos                ///
///             Developed by  @lukaz06 - Out, 2021                          ///
///////////////////////////////////////////////////////////////////////////////

//Assinatura das funções do módulo lembretes
void Lembretes(int id_menu);
void carregarLembretes();
void verTarefas();
int contTasks(char usuario[128]);
int registrarTarefa(char tUsuario[32], char tNome[128], int tDia, int tMes, int tAno, int tHora, int tMinuto, int tRealizada);
int getLastTask(int modo);
int tExists(char tUsuario[32], char tNome[128], int modo);
int modificarTarefa(int id_var, char what[50], char str[128]);
int excluirTarefa(char tUsuario[32], char tNome[128]);
int excluirTodasTarefas(char usuario[128]);
int validarDatav2(int dia, int mes, int ano, int hora, int minuto);

//Funções externas
extern int vData(int dia, int mes, int ano);
extern int vHora(int hora, int min);
extern int menu;
extern int getLastTask(int modo);
extern void titulo(char title[128]);
extern void limpar(void);
extern void Msg(char msg[256]);
extern void telaSobre();
extern int login;
extern int abrirArquivo(char Arquivo[128], char* StrF);
extern int alterarUsuario(int id, char what[128], char campo[256]);
extern int excluirUsuario(char usuario[32]);
