#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ACOES 100
#define MAX_CHECKLIST 5

/*
   Sistema AEP / PSE - dados ficticios e coletivos.
   Nao cadastrar nomes de alunos, dados de saude ou outros dados pessoais.
   Nao usa arquivos, banco SQL ou internet: tudo fica apenas na memoria.
*/
typedef struct {
    int codigo;
    char data[11];              /* DD/MM/AAAA */
    char escola[60];
    char faixa_etaria[40];
    char turma[40];
    char atividade[100];
    char responsavel[70];      /* Equipe ou funcao; nao nome pessoal */
    int inscritos;
    int participantes;
    int meta_dia;              /* Quantas realizacoes estao previstas */
    int realizadas_dia;        /* Quantas foram executadas */
    int situacao;              /* 1=Em andamento, 2=Realizada, 3=Cancelada */
    char observacoes[250];    /* Somente observacoes coletivas */
    int quantidade_itens;
    char checklist[MAX_CHECKLIST][100];
    int item_concluido[MAX_CHECKLIST];
} Acao;

Acao banco[MAX_ACOES];
int total_acoes = 0;

int ler_inteiro(const char *mensagem, int minimo, int maximo);
int indice_codigo(int codigo);
int data_valida(const char data[]);
double participacao_percentual(const Acao *a);
const char *situacao_texto(int situacao);

/* Le uma linha de texto sem deixar caracteres pendentes na entrada. */
void ler_campo(const char *mensagem, char destino[], int capacidade, int obrigatorio) {
    int c, i, vazio;
    do {
        printf("%s", mensagem);
        if (fgets(destino, capacidade, stdin) == NULL) {
            printf("\nEntrada encerrada.\n");
            exit(0);
        }
        i = (int)strcspn(destino, "\n");
        if (destino[i] == '\n') {
            destino[i] = '\0';
        } else {
            while ((c = getchar()) != '\n' && c != EOF) { }
        }
        vazio = 1;
        for (i = 0; destino[i] != '\0'; i++) {
            if (!isspace((unsigned char)destino[i])) {
                vazio = 0;
                break;
            }
        }
        if (obrigatorio && vazio) {
            printf("Este campo nao pode ficar vazio.\n");
        }
    } while (obrigatorio && vazio);
}
void ler_data(char destino[]) {
    do {
        ler_campo("Data da atividade (DD/MM/AAAA): ", destino, 11, 1);
        if (!data_valida(destino)) printf("Data invalida. Use DD/MM/AAAA.\n");
    } while (!data_valida(destino));
}
void mostrar_acao(const Acao *a) {
    int i;
    printf("\n--------------------------------------\n");
    printf("Codigo: %d | Data: %s\n", a->codigo, a->data);
    printf("Escola: %s | Turma: %s\n", a->escola, a->turma);
    printf("Faixa etaria: %s\n", a->faixa_etaria);
    printf("Atividade: %s\n", a->atividade);
    printf("Equipe/funcao responsavel: %s\n", a->responsavel);
    printf("Alunos inscritos: %d\n", a->inscritos);
    printf("Alunos participantes: %d\n", a->participantes);
    printf("Frequencia coletiva da turma: %d de %d\n", a->participantes, a->inscritos);
    printf("Percentual de participacao: %.2f%%\n", participacao_percentual(a));
    printf("Meta para o dia: %d | Feito: %d\n", a->meta_dia, a->realizadas_dia);
    printf("Situacao: %s\n", situacao_texto(a->situacao));
    printf("Observacoes coletivas: %s\n", a->observacoes[0] ? a->observacoes : "Nenhuma");
    printf("Check-list (%d itens):\n", a->quantidade_itens);
    if (a->quantidade_itens == 0) printf("  Nenhum item definido.\n");
    for (i = 0; i < a->quantidade_itens; i++) {
        printf("  [%c] %d - %s\n", a->item_concluido[i] ? 'X' : ' ',
               i + 1, a->checklist[i]);
    }
}
void cad_acoes() {
    int op, codigo, i;
    Acao nova;

    do {
        printf("\n========== CADASTRAR ACAO ==========\n");
        printf("1 - Nova atividade\n0 - Voltar ao menu principal\n");
        op = ler_inteiro("Opcao: ", 0, 1);
        if (op == 0) break;
        if (total_acoes >= MAX_ACOES) {
            printf("Limite de %d atividades atingido.\n", MAX_ACOES);
            continue;
        }

        do {
            codigo = ler_inteiro("Codigo da atividade (1 a 999999): ", 1, 999999);
            if (indice_codigo(codigo) != -1) printf("Codigo ja utilizado.\n");
        } while (indice_codigo(codigo) != -1);

        memset(&nova, 0, sizeof(nova));
        nova.codigo = codigo;
        ler_data(nova.data);
        ler_campo("Escola: ", nova.escola, sizeof(nova.escola), 1);
        ler_campo("Faixa etaria (ex.: 12 a 14 anos): ", nova.faixa_etaria,
                  sizeof(nova.faixa_etaria), 1);
        ler_campo("Turma (ex.: 7A): ", nova.turma, sizeof(nova.turma), 1);
        ler_campo("Atividade (ex.: alongamento): ", nova.atividade,
                  sizeof(nova.atividade), 1);
        ler_campo("Equipe/funcao responsavel (sem nomes pessoais): ", nova.responsavel,
                  sizeof(nova.responsavel), 1);
        nova.inscritos = ler_inteiro("Quantidade de alunos inscritos: ", 0, 100000);
        nova.participantes = ler_inteiro("Quantidade de alunos que participaram: ",
                                          0, nova.inscritos);
        nova.meta_dia = ler_inteiro("Quantidade prevista da atividade no dia (meta): ",
                                    0, 100000);
        nova.realizadas_dia = ler_inteiro("Quantidade ja realizada: ", 0, 100000);
        printf("1 - Em andamento\n2 - Realizada\n3 - Cancelada\n");
        nova.situacao = ler_inteiro("Situacao: ", 1, 3);
        printf("Nao registre nomes de alunos, prontuarios ou dados de saude.\n");
        ler_campo("Observacoes apenas coletivas (Enter = nenhuma): ", nova.observacoes,
                  sizeof(nova.observacoes), 0);

        nova.quantidade_itens = ler_inteiro("Quantidade de itens do check-list (0 a 5): ",
                                            0, MAX_CHECKLIST);
        for (i = 0; i < nova.quantidade_itens; i++) {
            char mensagem[70];
            sprintf(mensagem, "Texto do item %d: ", i + 1);
            ler_campo(mensagem, nova.checklist[i], sizeof(nova.checklist[i]), 1);
            nova.item_concluido[i] = 0;
        }

        banco[total_acoes] = nova;
        total_acoes++;
        printf("\nAtividade cadastrada! Total: %d\n", total_acoes);
    } while (op != 0);
}
void list_acoes_cad() {
    int i;
    if (total_acoes == 0) {
        printf("\nNenhuma atividade cadastrada.\n");
        return;
    }
    printf("\n========== ATIVIDADES CADASTRADAS ==========\n");
    for (i = 0; i < total_acoes; i++) mostrar_acao(&banco[i]);
}
void atividades_por_data() {
    char data[11];
    int i, encontrou = 0, metas = 0, feitas = 0;
    ler_data(data);
    printf("\n========== ATIVIDADES DO DIA %s ==========\n", data);
    for (i = 0; i < total_acoes; i++) {
        if (strcmp(banco[i].data, data) == 0) {
            printf("- %s (%s, turma %s) | Meta: %d | Feito: %d | %s\n",
                   banco[i].atividade, banco[i].escola, banco[i].turma,
                   banco[i].meta_dia, banco[i].realizadas_dia,
                   situacao_texto(banco[i].situacao));
            metas += banco[i].meta_dia;
            feitas += banco[i].realizadas_dia;
            encontrou = 1;
        }
    }
    if (!encontrou) printf("Nenhuma atividade cadastrada nesta data.\n");
    else printf("TOTAL DO DIA - Meta: %d | Realizado: %d | Falta: %d\n",
                metas, feitas, metas > feitas ? metas - feitas : 0);
}
void pesq_acoes() {
    int op, codigo, indice;
    printf("\n========== PESQUISAR ATIVIDADES ==========\n");
    printf("1 - Por codigo\n2 - Por data (atividades do dia)\n0 - Voltar\n");
    op = ler_inteiro("Opcao: ", 0, 2);
    if (op == 1) {
        codigo = ler_inteiro("Codigo: ", 1, 999999);
        indice = indice_codigo(codigo);
        if (indice == -1) printf("Atividade nao encontrada.\n");
        else mostrar_acao(&banco[indice]);
    } else if (op == 2) {
        atividades_por_data();
    }
}
void atualizar_acoes() {
    int codigo, indice, op, item;
    Acao *a;
    if (total_acoes == 0) {
        printf("\nCadastre uma atividade antes de atualizar.\n");
        return;
    }
    codigo = ler_inteiro("Codigo da atividade a atualizar: ", 1, 999999);
    indice = indice_codigo(codigo);
    if (indice == -1) {
        printf("Atividade nao encontrada.\n");
        return;
    }
    a = &banco[indice];
    do {
        printf("\n===== ATUALIZAR ATIVIDADE %d =====\n", codigo);
        printf("1 - Situacao\n");
        printf("2 - Quantidade de alunos participantes\n");
        printf("3 - Quantidade realizada da meta\n");
        printf("4 - Observacoes coletivas\n");
        printf("5 - Marcar/desmarcar item do check-list\n");
        printf("0 - Voltar\n");
        op = ler_inteiro("Opcao: ", 0, 5);
        switch (op) {
            case 1:
                printf("1 - Em andamento\n2 - Realizada\n3 - Cancelada\n");
                a->situacao = ler_inteiro("Situacao: ", 1, 3);
                break;
            case 2:
                a->participantes = ler_inteiro("Quantos participaram: ",
                                               0, a->inscritos);
                break;
            case 3:
                a->realizadas_dia = ler_inteiro("Quantidade ja feita: ", 0, 100000);
                break;
            case 4:
                printf("Somente informacoes coletivas; nao inclua dados individuais.\n");
                ler_campo("Observacoes (Enter = limpar): ", a->observacoes,
                          sizeof(a->observacoes), 0);
                break;
            case 5:
                if (a->quantidade_itens == 0) {
                    printf("Esta atividade nao possui itens de check-list.\n");
                } else {
                    for (item = 0; item < a->quantidade_itens; item++) {
                        printf("%d - [%c] %s\n", item + 1,
                               a->item_concluido[item] ? 'X' : ' ', a->checklist[item]);
                    }
                    item = ler_inteiro("Numero do item a alternar: ", 1,
                                       a->quantidade_itens) - 1;
                    a->item_concluido[item] = !a->item_concluido[item];
                }
                break;
            case 0:
                break;
        }
    } while (op != 0);
}
void relatorio_geral() {
    int i, em_andamento = 0, realizadas = 0, canceladas = 0;
    int inscritos = 0, participantes = 0, metas = 0, feitas = 0;
    double percentual = 0.0;
    for (i = 0; i < total_acoes; i++) {
        if (banco[i].situacao == 1) em_andamento++;
        else if (banco[i].situacao == 2) realizadas++;
        else canceladas++;
        inscritos += banco[i].inscritos;
        participantes += banco[i].participantes;
        metas += banco[i].meta_dia;
        feitas += banco[i].realizadas_dia;
    }
    if (inscritos > 0) percentual = 100.0 * participantes / inscritos;
    printf("\n========== RELATORIO GERAL ==========\n");
    printf("Atividades cadastradas: %d\n", total_acoes);
    printf("Em andamento: %d | Realizadas: %d | Canceladas: %d\n",
           em_andamento, realizadas, canceladas);
    printf("Inscricoes nas atividades: %d\n", inscritos);
    printf("Participacoes nas atividades: %d\n", participantes);
    printf("Frequencia coletiva (participacoes/inscricoes): %.2f%%\n", percentual);
    printf("Meta total de execucoes: %d | Execucoes realizadas: %d\n", metas, feitas);
    printf("Obs.: somas de inscricoes nao representam alunos unicos.\n");
}
void resumo() {
    int op;
    printf("\n========== RESUMOS E RELATORIOS ==========\n");
    printf("1 - Relatorio geral\n2 - Atividades de uma data\n0 - Voltar\n");
    op = ler_inteiro("Opcao: ", 0, 2);
    if (op == 1) relatorio_geral();
    if (op == 2) atividades_por_data();
}

int main() {
    int op;
    
    do {
        printf("\n========== MENU DE ACOES - PSE ==========\n");
        printf("1 - Cadastrar atividades\n");
        printf("2 - Listar atividades cadastradas\n");
        printf("3 - Pesquisar atividades\n");
        printf("4 - Atualizar atividade e check-list\n");
        printf("5 - Gerar relatorio / atividades do dia\n");
        printf("6 - Finalizar\n");
        op = ler_inteiro("\nEscolha a opcao: ", 1, 6);
        switch (op) {
            case 1: cad_acoes(); break;
            case 2: list_acoes_cad(); break;
            case 3: pesq_acoes(); break;
            case 4: atualizar_acoes(); break;
            case 5: resumo(); break;
            case 6: printf("\nPrograma encerrado. Dados em memoria descartados.\n"); break;
        }
    } while (op != 6);
    return 0;
}

int ler_inteiro(const char *mensagem, int minimo, int maximo) {
    char entrada[50];
    char sobra;
    int numero;
    do {
        ler_campo(mensagem, entrada, sizeof(entrada), 1);
        if (sscanf(entrada, " %d %c", &numero, &sobra) == 1 &&
            numero >= minimo && numero <= maximo) {
            return numero;
        }
        printf("Digite um numero inteiro entre %d e %d.\n", minimo, maximo);
    } while (1);
}
int data_valida(const char data[]) {
    int d, m, a, dias;
    int i;
    if (strlen(data) != 10 || data[2] != '/' || data[5] != '/') return 0;
    for (i = 0; i < 10; i++) {
        if (i != 2 && i != 5 && !isdigit((unsigned char)data[i])) return 0;
    }
    if (sscanf(data, "%2d/%2d/%4d", &d, &m, &a) != 3) return 0;
    if (a < 1900 || m < 1 || m > 12 || d < 1) return 0;
    dias = 31;
    if (m == 4 || m == 6 || m == 9 || m == 11) dias = 30;
    if (m == 2) {
        dias = 28;
        if (a % 400 == 0 || (a % 4 == 0 && a % 100 != 0)) dias = 29;
    }
    return d <= dias;
}
int indice_codigo(int codigo) {
    int i;
    for (i = 0; i < total_acoes; i++) {
        if (banco[i].codigo == codigo) return i;
    }
    return -1;
}
double participacao_percentual(const Acao *a) {
    if (a->inscritos == 0) return 0.0;
    return 100.0 * a->participantes / a->inscritos;
}
const char *situacao_texto(int situacao) {
    if (situacao == 1) return "Em andamento";
    if (situacao == 2) return "Realizada";
    return "Cancelada";
}
