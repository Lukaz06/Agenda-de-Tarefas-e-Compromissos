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

struct usuarioEstrutura Usuarios[MAX_USUARIOS];
struct tarefasEstrutura Tarefas[MAX_TAREFAS];

void Lembretes(int id_menu)
{
    int etapa = 0;

    switch (id_menu)
    {
        case 1: //Criar Lembrete
        {
            etapa = 0;
            char nomeLembrete[256];
            int dia, mes, ano, hora, minuto, opfinal;

            while(1)
            {
                titulo("///          = = = = = = = =   Criar  Lembretes   = = = = = = = =         ///");

                limpar();
                if(etapa == 0) //Nome do Lembrete
                {
                    printf("\n\t Informe o Nome do Lembrete: ");
                    if(scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]" , nomeLembrete) != 1) {
                        Msg("Nome inválido.");
                        continue;
                    }

                    if(strlen(nomeLembrete) >= 100)
                    {
                        Msg("Número de caracteres excedido (100).");
                        continue;
                    }

                    if(tExists(Usuarios[login].usuario, nomeLembrete, 0) != -1)
                    {
                        Msg("Esse lembrete já existe, tente com outro nome.");
                        continue;
                    }
                    etapa++;
                }
                else if(etapa == 1) //Data do Lembrete
                {
                    printf("\n\t Informe a Data do Lembrete (dd/mm/aaaa): ");
                    scanf("%d/%d/%d", &dia, &mes, &ano);
                    
                    if(vData(dia, mes, ano) == 0) { //Verificação de data válida
                        Msg("Data inválida.");
                        continue;
                    }
                    etapa++;
                }
                else if(etapa == 2) //Hora do Lembrete
                {
                    printf("\n\t Informe o Horário do Lembrete (hh:mm): ");
                    scanf("%d:%d", &hora, &minuto);

                    if(vHora(hora, minuto) == 0) {
                        Msg("Hora inválida.");
                        continue;
                    }
                    etapa++;
                    break;
                }
                else{
                    break;
                }
            }

            titulo("///          = = = = = = = =   Criar  Lembretes   = = = = = = = =         ///");
            printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=[ Informações obtidas ]=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("\n\t Nome: %s", nomeLembrete);
            printf("\n\t Data: %d/%d/%d", dia, mes, ano);
            printf("\n\t Hora: %d:%d\n", hora, minuto);
            printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

            printf("\n\t [1]: SIM, AS INFORMAÇÕES ESTÃO CORRETAS.\n\t [0]: NÃO, AS INFORMAÇÕES ESTÃO INCORRETAS.\n");
            limpar();
            printf("\n\t As informações estão corretas?: ");
            scanf("%d", &opfinal);

            if(opfinal != 0) {
                if(registrarTarefa(Usuarios[login].usuario, nomeLembrete, dia, mes, ano, hora, minuto, 0))
                {
                    printf("\n\t\t Tarefa registrada com sucesso. Retornando ao menu inicial...");
                    Sleep(1500);
                }
                else{
                    Msg("Não foi possível registrar a tarefa, tente novamente mais tarde.");
                }
            }

            menu = 0;
        }
        break;

        case 2: //Ver Lembretes
        {
            int i, numTarefas = 0, VerEscolha;
            int TarefasEncontradas[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

            for(i = 0; i < MAX_TAREFAS; i++)
            {
                if(numTarefas > 9) {
                    break;
                }

                if (strcmp(Tarefas[i].usuario, Usuarios[login].usuario) == 0)
                {
                    TarefasEncontradas[numTarefas] = i;
                    numTarefas++;
                }
            }

            titulo("///          = = = = = = = = =  Minhas Tarefas  = = = = = = = = =         ///");

            int o;
            for(i = 0; i < numTarefas; i++)
            {
                o = TarefasEncontradas[i];
                
                if(Tarefas[o].realizada == 1)
                    printf("\n\t [%d]: %s (%d/%d/%d às %d:%d) (Realizada)", i+1, Tarefas[o].nome, Tarefas[o].dia, Tarefas[o].mes, Tarefas[o].ano, Tarefas[o].hora, Tarefas[o].minuto);
                else
                    printf("\n\t [%d]: %s (%d/%d/%d às %d:%d)", i+1, Tarefas[o].nome, Tarefas[o].dia, Tarefas[o].mes, Tarefas[o].ano, Tarefas[o].hora, Tarefas[o].minuto);

            }
            printf("\n\t [0]: Cancelar");
            printf("\n\n\t Escolha um lembrete (1-%d): ", numTarefas);
            scanf("%d", &VerEscolha);

            int posOpcao;
            char op[2];

            if(VerEscolha >= 1 && VerEscolha <= numTarefas)
            {
                titulo("///          = = = = = = = = =  Minhas Tarefas  = = = = = = = = =         ///");
                o = TarefasEncontradas[VerEscolha-1];

                printf("\n\t Lembrete: '%s'", Tarefas[o].nome);
                if(Tarefas[o].realizada == 1) {
                    printf("\n\n\t [1]: Marcar lembrete como 'não realizado'");
                    strcpy(op, "0");
                } else {
                    printf("\n\n\t [1]: Marcar lembrete como 'realizado'");
                    strcpy(op, "1");
                }
                printf("\n\t [2]: Modificar nome do Lembrete (%s)", Tarefas[o].nome);
                printf("\n\t [3]: Modificar data do Lembrete (%d/%d/%d)", Tarefas[o].dia, Tarefas[o].mes, Tarefas[o].ano);
                printf("\n\t [4]: Modificar hora do Lembrete (%d:%d)", Tarefas[o].hora, Tarefas[o].minuto);
                printf("\n\t [5]: Apagar Lembrete");
                printf("\n\t [0]: Cancelar");

                printf("\n\n\t Selecione a opção (1-5): ");
                scanf("%d", &posOpcao);

                if(posOpcao == 1) //Marcar como realizado
                {
                    if(modificarTarefa(o, "realizada", op))
                    {
                        printf("\n\n\t INFO: Tarefa modificada com sucesso.");
                        Sleep(1500);
                    }
                }
                else if(posOpcao == 2) //Editar nome
                {
                    char nomeLembrete[128];
                    while(1)
                    {
                        printf("\n\t Informe o Nome do Lembrete: ");
                        if(scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]" , nomeLembrete) != 1) {
                            Msg("Nome inválido.");
                            continue;
                        }

                        if(strlen(nomeLembrete) >= 100)
                        {
                            Msg("Número de caracteres excedido (100).");
                            continue;
                        }

                        if(tExists(Usuarios[login].usuario, nomeLembrete, 0) != -1)
                        {
                            Msg("Esse lembrete já existe, tente com outro nome.");
                            continue;
                        }
                        break;
                    }

                    if(modificarTarefa(o, "nome", nomeLembrete))
                    {
                        printf("\n\n\t INFO: Tarefa modificada com sucesso.");
                        Sleep(1500);
                    }
                }
                else if(posOpcao == 3) //Editar data lembrete
                {
                    int dia, mes, ano;
                    char sdia[10], smes[10], sano[10];

                    while(1)
                    {
                        printf("\n\t Informe a Data do Lembrete (dd/mm/aaaa): ");
                        scanf("%d/%d/%d", &dia, &mes, &ano);
                        
                        if(vData(dia, mes, ano) == 0) { //Verificação de data válida
                            Msg("Data inválida.");
                            continue;
                        }
                        break;
                    }

                    sprintf(sdia, "%d", dia);
                    sprintf(smes, "%d", mes);
                    sprintf(sano, "%d", ano);

                    if(modificarTarefa(o, "dia", sdia) && modificarTarefa(o, "mes", smes) && modificarTarefa(o, "ano", sano)) {
                        printf("\n\n\t INFO: Tarefa modificada com sucesso.");
                        Sleep(1500);
                    }
                }
                else if(posOpcao == 4) //Editar hora lembrete
                {
                    int hora, minuto;
                    char shora[10], sminuto[10];

                    while(1)
                    {
                        printf("\n\t Informe o Horário do Lembrete (hh:mm): ");
                        scanf("%d:%d", &hora, &minuto);

                        if(vHora(hora, minuto) == 0) {
                            Msg("Hora inválida.");
                            continue;
                        }
                    }

                    sprintf(shora, "%d", hora);
                    sprintf(sminuto, "%d", minuto);

                    if(modificarTarefa(o, "hora", shora) && modificarTarefa(o, "mes", sminuto)) {
                        printf("\n\n\t INFO: Tarefa modificada com sucesso.");
                        Sleep(1500);
                    }
                }
                else if(posOpcao == 5) //Excluir
                {
                    if(excluirTarefa(Usuarios[login].usuario, Tarefas[o].nome))
                    {
                        printf("\n\n\t INFO: Tarefa excluída com sucesso.");
                        Sleep(1500);
                    }
                }
                else { //cancel
                    menu = 0;
                }
            }
            else{
                menu = 0;
            }
        }
        break;

        case 3: //Meus dados
        {
            int e;

            while(1)
            {
                titulo("///          = = = = = = = =  Minhas Informações  = = = = = = = =         ///");
                printf("\n\t Nome: %s", Usuarios[login].nome);
                printf("\n\t Usuário: %s", Usuarios[login].usuario);
                printf("\n\t Celular: %s", Usuarios[login].celular);
                printf("\n\t Cidade: %s", Usuarios[login].cidade);
                printf("\n\t Endereço: %s", Usuarios[login].endereco);
                printf("\n\t Data de Nascimento: %d/%d/%d\n", Usuarios[login].nascimento.dia, Usuarios[login].nascimento.mes, Usuarios[login].nascimento.ano);

                printf("\n\t [1]: Editar informações");
                printf("\n\t [2]: Excluir minha conta");
                printf("\n\t [0]: Cancelar");

                printf("\n\n\t Informe sua escolha (0-2): ");
                scanf("%d", &e);

                
            }
            
        }
        break;

        case 4: //Sobre o Programa
        {
            telaSobre();
        }
        break;
    }
}

int excluirTarefa(char tUsuario[32], char tNome[128])
{
    int id_arq = tExists(tUsuario, tNome, 1);
    int id_var = tExists(tUsuario, tNome, 0);
    char nome_arquivo[50];

    if(id_arq == -1 || id_var == -1) {
        return 0;
    }

    sprintf(nome_arquivo, PASTA_TAREFAS, id_arq);
    remove(nome_arquivo);
    strcpy(Tarefas[id_var].nome, "$");
    strcpy(Tarefas[id_var].usuario, "$");
    return 1;
}

int tExists(char tUsuario[32], char tNome[128], int modo)
{
    char Lukas[256], nome_arquivo[50], strObtida[256], *token;
    int i, x = 0, etapa, valor = -1;

    for(i = 0; i < MAX_TAREFAS; i++)
    {
        x = 0;

        if(modo == 1) //Procura por meio de arquivos, retornando o número do arquivo
        {
            etapa = 1;

            sprintf(nome_arquivo, PASTA_TAREFAS, i);
            if(abrirArquivo(nome_arquivo, Lukas))
            {
                token = strtok(Lukas, "\n");
                while( token != NULL )
                {
                    sprintf(strObtida, "%s", token);
                    
                    if(x == 0 && etapa == 1 && strcmp(tUsuario, strObtida) == 0) //Nome de usuário
                    {
                        etapa++;
                    }
                    else if(x == 1 && etapa == 2 && strcmp(tNome, strObtida) == 0) //Nome da Tarefa
                    {
                        etapa++;
                    }
                    else if(etapa == 3)
                    {
                        valor = i;
                        break;
                    }

                    token = strtok(NULL, "\n");
                    x++;
                }
            }
        }
        else
        {
            if (strcmp(Tarefas[i].usuario, tUsuario) == 0)
            {
                if (strcmp(Tarefas[i].nome, tNome) == 0)
                {
                    valor = i;
                    break;
                }
            }
        }
    }
    return valor;
}

void carregarLembretes(void)
{
    char Lukas[256], nome_arquivo[50], strObtida[256], *intAux[10], *token;
    int i, x = 0;

    for(i = 0; i < MAX_TAREFAS; i++)
    {
        x = 0;

        sprintf(nome_arquivo, PASTA_TAREFAS, i);
        
        if(abrirArquivo(nome_arquivo, Lukas))
        {
            token = strtok(Lukas, "\n");
            while( token != NULL )
            {
                sprintf(strObtida, "%s", token);
                switch (x)
                {
                    case 0: 
                        strcpy(Tarefas[i].usuario, strObtida);
                        break;
                    case 1: 
                        strcpy(Tarefas[i].nome, strObtida);
                        break;
                    case 2: 
                        Tarefas[i].dia = strtol(strObtida, intAux, 10);
                        break;
                    case 3: 
                        Tarefas[i].mes = strtol(strObtida, intAux, 10);
                        break;
                    case 4: 
                        Tarefas[i].ano = strtol(strObtida, intAux, 10);
                        break;
                    case 5: 
                        Tarefas[i].hora = strtol(strObtida, intAux, 10);
                        break;
                    case 6: 
                        Tarefas[i].minuto = strtol(strObtida, intAux, 10);
                        break;
                    case 7: 
                        Tarefas[i].realizada = strtol(strObtida, intAux, 10);
                        break;
                }
                token = strtok(NULL, "\n");
                x++;
            }
        }
        else {
            strcpy(Tarefas[i].nome, "$");
        }
    } //Fim do for
}

void verTarefas(void)
{
    int i;

    for(i = 0; i < MAX_TAREFAS; i++)
    {
        if (strcmp(Tarefas[i].nome, "$") != 0)
        {
            printf("\n\t Tarefa: %s", Tarefas[i].nome);
            printf("\n\t Usuário: %s", Tarefas[i].usuario);
            printf("\n\t Data: %d/%d/%d às %d:%d", Tarefas[i].dia, Tarefas[i].mes, Tarefas[i].ano, Tarefas[i].hora, Tarefas[i].minuto);
            printf("\n\n");
        }
    }
}

int contTasks(char usuario[128])
{
    int i, count = 0;
    for(i = 0; i < MAX_TAREFAS; i++)
    {
        if (strcmp(Tarefas[i].usuario, usuario) == 0)
        {
            count++;
        }
    }
    return count;
}

int getLastTask(int modo)
{
    int i = 0, valor;
    char nome_arquivo[50];

    if(modo == 1) //Arquivo
    {
        while (i < MAX_TAREFAS)
        {
            FILE *file;
            sprintf(nome_arquivo, PASTA_TAREFAS, i);
            file = fopen(nome_arquivo, "r");
            if((file != NULL)) {
                i++;
                fclose(file);
                continue;
            }
            valor = i;
            break;
        }
    }
    else //Variável do Estruct
    {
        for(i = 0; i < MAX_TAREFAS; i++)
        {
            if (strcmp(Tarefas[i].nome, "$") == 0) {
                valor = i;
                break;
            }
        }
    }
    return valor;
}

int modificarTarefa(int id_var, char what[50], char str[128])
{
    int numerico;
    char *tmpNumero[20];

    if(tExists(Tarefas[id_var].usuario, Tarefas[id_var].nome, 0) == -1) {
        return 0;
    }

    if (strcmp(what, "nome") == 0) {
        registrarTarefa(Tarefas[id_var].usuario, Tarefas[id_var].nome, Tarefas[id_var].dia, Tarefas[id_var].mes, Tarefas[id_var].ano, Tarefas[id_var].hora, Tarefas[id_var].minuto, Tarefas[id_var].realizada);
    }
    else if (strcmp(what, "dia") == 0) {
        numerico = strtol(str, tmpNumero, 10);
        registrarTarefa(Tarefas[id_var].usuario, Tarefas[id_var].nome, numerico, Tarefas[id_var].mes, Tarefas[id_var].ano, Tarefas[id_var].hora, Tarefas[id_var].minuto, Tarefas[id_var].realizada);
    }
    else if (strcmp(what, "mes") == 0) {
        numerico = strtol(str, tmpNumero, 10);
        registrarTarefa(Tarefas[id_var].usuario, Tarefas[id_var].nome, Tarefas[id_var].dia, numerico, Tarefas[id_var].ano, Tarefas[id_var].hora, Tarefas[id_var].minuto, Tarefas[id_var].realizada);
    }
    else if (strcmp(what, "ano") == 0) {
        numerico = strtol(str, tmpNumero, 10);
        registrarTarefa(Tarefas[id_var].usuario, Tarefas[id_var].nome, Tarefas[id_var].dia, Tarefas[id_var].mes, numerico, Tarefas[id_var].hora, Tarefas[id_var].minuto, Tarefas[id_var].realizada);
    }
    else if (strcmp(what, "hora") == 0) {
        numerico = strtol(str, tmpNumero, 10);
        registrarTarefa(Tarefas[id_var].usuario, Tarefas[id_var].nome, Tarefas[id_var].dia, Tarefas[id_var].mes, Tarefas[id_var].ano, numerico, Tarefas[id_var].minuto, Tarefas[id_var].realizada);
    }
    else if (strcmp(what, "minuto") == 0) {
        numerico = strtol(str, tmpNumero, 10);
        registrarTarefa(Tarefas[id_var].usuario, Tarefas[id_var].nome, Tarefas[id_var].dia, Tarefas[id_var].mes, Tarefas[id_var].ano, Tarefas[id_var].hora, numerico, Tarefas[id_var].realizada);
    }
    else if (strcmp(what, "realizada") == 0) {
        numerico = strtol(str, tmpNumero, 10);
        registrarTarefa(Tarefas[id_var].usuario, Tarefas[id_var].nome, Tarefas[id_var].dia, Tarefas[id_var].mes, Tarefas[id_var].ano, Tarefas[id_var].hora, Tarefas[id_var].minuto, numerico);
    }
    else {
        return 0;
    }
    return 1;
}

int registrarTarefa(char tUsuario[32], char tNome[128], int tDia, int tMes, int tAno, int tHora, int tMinuto, int tRealizada)
{
    int id_arq = tExists(tUsuario, tNome, 1);
    int id_var = tExists(tUsuario, tNome, 0);

    if(contTasks(tUsuario) < 10)
    {
        char nome_arquivo[50];
        FILE *file; //Criando variável para manipulação de arquivos
        
        if(id_arq == -1) //Se não existir
        {
            sprintf(nome_arquivo, PASTA_TAREFAS, getLastTask(1));
        }
        else
        {
            sprintf(nome_arquivo, PASTA_TAREFAS, id_arq);
        }
        
        file = fopen(nome_arquivo, "w"); //Abrindo o arquivo

        fprintf(file, "%s\n", tUsuario); //Usuário
        fprintf(file, "%s\n", tNome); //Nome da Tarefa
        fprintf(file, "%d\n", tDia); //Dia
        fprintf(file, "%d\n", tMes); //Mês
        fprintf(file, "%d\n", tAno); //Ano
        fprintf(file, "%d\n", tHora); //Hora
        fprintf(file, "%d\n", tMinuto); //Minuto
        fprintf(file, "%d", tRealizada); //Realização
        fclose(file); //Fechamento do arquivo

        int id;
        if(id_var != -1) {
            id = id_var;
        }
        else {
            id = getLastTask(0);
        }

        strcpy(Tarefas[id].usuario, tUsuario);
        strcpy(Tarefas[id].nome, tNome);
        Tarefas[id].dia = tDia;
        Tarefas[id].mes = tMes;
        Tarefas[id].ano = tAno;
        Tarefas[id].hora = tHora;
        Tarefas[id].minuto = tMinuto;
        Tarefas[id].realizada = tRealizada;

        return 1;
    }
    return 0;
}