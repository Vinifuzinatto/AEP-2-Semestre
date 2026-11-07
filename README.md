# Sistema de Acompanhamento de Atividades Físicas - PSE

## Sobre o projeto

Este projeto tem como objetivo desenvolver um sistema para auxiliar na organização, planejamento e acompanhamento das atividades físicas realizadas nas escolas dentro do Programa Saúde na Escola (PSE).

O sistema permitirá registrar informações como data da atividade, escola, turma, atividade realizada, número de participantes, frequência da turma, percentual de participação e entre outros pontos. Também será possível acompanhar a regularidade das atividades e consultar o histórico das ações realizadas.

## Problema identificado

Apesar da promoção da atividade física fazer parte das ações do Programa Saúde na Escola, existe a necessidade de facilitar a organização e o acompanhamento dessas atividades.

Dessa forma, o sistema busca centralizar as informações e auxiliar os responsáveis no planejamento e no monitoramento das ações realizadas nas escolas.

## Integrantes

- Nome: KAUAN BORIN ROLIM DE MOURA - RA 26004945-2
- Nome: MARCO ANTONIO LOBATO DE SOUSA - RA 26005468-2
- Nome: VINÍCIUS DOS SANTOS FUZINATTO - RA 26006172-2
- Nome: VINICIUS HENRIQUE BENEVENTO - RA 26015304-2

## Documentação

A documentação referente ao desenvolvimento do projeto está disponível no seguinte link:

DRIVE: [Clique aqui](https://drive.google.com/drive/folders/1GlbhSfpVkZUMRJK3gPX4WXxVtiyv1R5z?usp=sharing)

TRELLO: [Clique aqui](https://trello.com/invite/b/6a8d97bc8d03dfebb42621bc/ATTIa0eb9b6ae6a8579329a7d48c95babe86A7E9F417/aep-2-2026-esoft-2-m-a)

# Manual do usuário

Sistema em linguagem C, executado no terminal, para cadastrar, listar, pesquisar e atualizar atividades do Programa Saúde na Escola (PSE), com foco em atividades físicas, e gerar relatórios coletivos de participação.

> [!WARNING]
> **Privacidade:** o sistema trabalha somente com dados fictícios e informações coletivas sobre as ações. Não cadastre nomes de alunos, prontuários, diagnósticos, condições clínicas ou qualquer outro dado pessoal ou de saúde.

## Sumário

- [Requisitos](#requisitos)
- [Obtendo o projeto](#obtendo-o-projeto)
- [Compilação](#compilação)
- [Execução](#execução)
- [Regras de preenchimento](#regras-de-preenchimento)
- [Funcionalidades](#funcionalidades)
- [Limitações](#limitações)

## Requisitos

- Computador com Windows, Linux ou macOS.
- Compilador de linguagem C (como GCC/MinGW) ou um ambiente de desenvolvimento que o utilize (Dev-C++ ou Visual Studio Code com a extensão C/C++).
- Arquivo-fonte `Menu_AEP.c`, disponível neste repositório.

Não é necessário acesso à internet, banco de dados ou bibliotecas externas: o programa usa apenas `stdio.h`, `stdlib.h`, `string.h` e `ctype.h`.

## Obtendo o projeto

```bash
git clone https://github.com/Vinifuzinatto/AEP-2-Semestre.git
cd AEP-2-Semestre
```

## Compilação

Mantenha o arquivo com o nome `Menu_AEP.c` e escolha uma das opções abaixo.

### Opção 1: terminal com GCC

Abra o terminal na pasta do arquivo e execute:

```bash
gcc Menu_AEP.c -o Menu_AEP -Wall -Wextra
```

Se não houver erros, será gerado o executável `Menu_AEP.exe` (Windows) ou `Menu_AEP` (Linux e macOS).

### Opção 2: Dev-C++

Abra o arquivo `Menu_AEP.c` e use o menu **Executar > Compilar e Executar** (tecla **F11**).

### Opção 3: Visual Studio Code

Com a extensão C/C++ e o compilador GCC (MinGW) instalados, abra a pasta do projeto e use o botão de execução (▶) no canto superior direito do editor, que compila e executa o arquivo aberto.

## Execução

No terminal, dentro da pasta onde está o executável:

| Sistema | Comando |
| --- | --- |
| Windows (Prompt de Comando ou PowerShell) | `.\Menu_AEP.exe` |
| Linux e macOS | `./Menu_AEP` |

> [!NOTE]
> No Windows, se o programa for aberto com duplo clique, a janela pode fechar assim que ele terminar. Por isso, prefira executá-lo pelo terminal.

Ao iniciar, o menu principal é exibido e permanece ativo, voltando a aparecer após cada operação, até que o usuário escolha a opção 6 (Finalizar).

### Menu principal

| Opção | Ação |
| :---: | --- |
| 1 | Cadastrar atividades |
| 2 | Listar atividades cadastradas |
| 3 | Pesquisar atividades |
| 4 | Atualizar atividade e check-list |
| 5 | Gerar relatório / atividades do dia |
| 6 | Finalizar |

## Regras de preenchimento

| Campo | Regra |
| --- | --- |
| Números | Digite apenas números inteiros dentro do intervalo exibido na mensagem. Letras, valores vazios ou fora do intervalo fazem o sistema repetir a pergunta. |
| Campos obrigatórios | Escola, faixa etária, turma, atividade, equipe/função responsável e textos do check-list não podem ficar em branco. Somente as observações são opcionais (basta pressionar Enter). |
| Código da atividade | Número inteiro de 1 a 999999 e único. Não é possível repetir um código já cadastrado. |
| Data | Formato `DD/MM/AAAA`, com as barras e dois dígitos para dia e mês (exemplo: `05/11/2026`). O sistema confere se a data existe, inclusive em anos bissextos, e aceita anos a partir de 1900. |
| Participantes | A quantidade de alunos que participaram não pode ser maior que a de inscritos. |
| Acentos | Recomenda-se digitar os textos sem acentos e sem cedilha, pois as mensagens do sistema também são exibidas assim, evitando erros de exibição no terminal. |
| Tamanho dos textos | Cada campo de texto tem um limite de caracteres. O que ultrapassar o limite é ignorado. |
| Capacidade | Até 100 atividades por execução e até 5 itens de check-list por atividade. |

## Funcionalidades

### Opção 1: cadastrar atividades

Abre o submenu **Cadastrar ação**, com as opções `1 – Nova atividade` e `0 – Voltar ao menu principal`.

Ao escolher `1`, o sistema solicita, nesta ordem:

1. Código
2. Data
3. Escola
4. Faixa etária
5. Turma
6. Atividade
7. Equipe/função responsável
8. Quantidade de alunos inscritos
9. Quantidade de alunos que participaram
10. Quantidade prevista da atividade no dia (meta)
11. Quantidade já realizada
12. Situação (`1` – Em andamento, `2` – Realizada, `3` – Cancelada)
13. Observações coletivas
14. Quantidade de itens do check-list (de 0 a 5)
15. Texto de cada item do check-list

Ao final, é exibida a mensagem `Atividade cadastrada! Total: N` e o submenu reaparece, permitindo novo cadastro ou retorno ao menu. Se o limite de 100 atividades já tiver sido atingido, o sistema informa e não permite novo cadastro.

### Opção 2: listar atividades cadastradas

Exibe, para cada atividade:

- código, data, escola, turma e faixa etária;
- atividade e equipe responsável;
- alunos inscritos e participantes, frequência coletiva e percentual de participação;
- meta do dia e quantidade realizada;
- situação e observações coletivas;
- check-list, em que `[X]` indica item concluído e `[ ]` item pendente.

Se não houver registros, aparece `Nenhuma atividade cadastrada.`

### Opção 3: pesquisar atividades

Abre um submenu com duas formas de busca:

- **Por código (1):** mostra os dados completos da atividade ou informa `Atividade nao encontrada.`
- **Por data (2):** lista as atividades daquele dia com escola, turma, meta, quantidade feita e situação, e apresenta o total do dia (meta, realizado e quanto falta).

A opção `0` volta ao menu principal.

### Opção 4: atualizar atividade e check-list

Solicita o código da atividade e abre um submenu que permanece ativo até o usuário escolher `0`. É necessário haver ao menos uma atividade cadastrada.

| Opção | O que altera |
| :---: | --- |
| 1 | Situação da atividade |
| 2 | Quantidade de participantes (limitada ao número de inscritos) |
| 3 | Quantidade realizada da meta |
| 4 | Observações coletivas (Enter limpa o texto) |
| 5 | Marca ou desmarca um item do check-list, informando o número do item |

### Opção 5: gerar relatório / atividades do dia

Abre um submenu com duas escolhas:

- **Relatório geral (1):** mostra o total de atividades, a quantidade em andamento, realizadas e canceladas, o total de inscrições e de participações, a frequência coletiva em percentual, a meta total e as execuções realizadas.
- **Atividades do dia (2):** apresenta as atividades de uma data, como na pesquisa por data.

> [!NOTE]
> Como o mesmo aluno pode participar de várias atividades, as somas do relatório geral não representam alunos únicos.

### Opção 6: finalizar

Encerra o programa exibindo `Programa encerrado. Dados em memória descartados.`

## Limitações

- Os dados ficam apenas na memória e são descartados quando o programa é encerrado.
- Capacidade de até 100 atividades por execução e 5 itens de check-list por atividade.
- O sistema trabalha somente com dados fictícios e coletivos, sem informações pessoais ou de saúde dos alunos.


