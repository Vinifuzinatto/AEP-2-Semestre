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

## Manual do usuário

## Cuidados com a privacidade
O sistema trabalha somente com dados fictícios e informações coletivas sobre as ações. Por isso: não cadastre nomes de alunos, prontuários, diagnósticos, condições clínicas ou qualquer outro dado pessoal ou de saúde.

## REQUISITOS PARA USO
- Computador com Windows, Linux ou macOS. Compilador de linguagem C (como o GCC/MinGW) ou um ambiente de desenvolvimento que o utilize (Dev-C++ ou Visual Studio Code com a extensão C/C++).

- Arquivo-fonte Menu_AEP.c disponível no repositório do projeto: https://github.com/Vinifuzinatto/AEP-2-Semestre.git 

- Não é necessário acesso à internet, banco de dados ou bibliotecas externas: o programa usa apenas stdio.h, stdlib.h, string.h e ctype.h.

## INSTRUÇÕES DE COMPILAÇÃO
Mantenha o arquivo com o nome Menu_AEP.c e escolha uma das opções abaixo. 
Opção 1 – Terminal com GCC. Abra o terminal na pasta do arquivo e execute: gcc Menu_AEP.c -o Menu_AEP -Wall -Wextra. Se não houver erros, será gerado o executável Menu_AEP.exe (Windows) ou Menu_AEP (Linux e macOS). 
Opção 2 – Dev-C++. Abra o arquivo Menu_AEP.c e use o menu Executar > Compilar e Executar (tecla F11). 
Opção 3 – Visual Studio Code. Com a extensão C/C++ e o compilador GCC (MinGW) instalados, abra a pasta do projeto e use o botão de execução (▶) no canto superior direito do editor, que compila e executa o arquivo aberto.

## INSTRUÇÕES DE EXECUÇÃO
No terminal, dentro da pasta onde está o executável: 
Windows (Prompt de Comando ou PowerShell): .\Menu_AEP.exe 
Linux e macOS: ./Menu_AEP 
No Windows, se o programa for aberto com duplo clique, a janela pode fechar assim que ele terminar; por isso, prefira executá-lo pelo terminal. Ao iniciar, o menu principal é exibido e permanece ativo, voltando a aparecer após cada operação, até que o usuário escolha a opção 6 (Finalizar). 

## REGRAS GERAIS DE PREENCHIMENTO
Números: digite apenas números inteiros dentro do intervalo exibido na mensagem. Letras, valores vazios ou fora do intervalo fazem o sistema repetir a pergunta. 
Campos obrigatórios: escola, faixa etária, turma, atividade, equipe/função responsável e textos do check-list não podem ficar em branco. Somente as observações são opcionais (basta pressionar Enter). 
Código da atividade: número inteiro de 1 a 999999 e único; não é possível repetir um código já cadastrado. 
Data: formato DD/MM/AAAA, com as barras e dois dígitos para dia e mês (exemplo: 05/11/2026). O sistema confere se a data existe, inclusive em anos bissextos, e aceita anos a partir de 1900. 
Participantes: a quantidade de alunos que participaram não pode ser maior que a de inscritos. 
Acentos: recomenda-se digitar os textos sem acentos e sem cedilha, pois as mensagens do sistema também são exibidas assim, evitando erros de exibição no terminal. 
Tamanho dos textos: cada campo de texto tem um limite de caracteres; o que ultrapassar o limite é ignorado. 
Capacidade: até 100 atividades por execução e até 5 itens de check-list por atividade.

## DESCRIÇÃO DAS FUNCIONALIDADES
Opção 1 – Cadastrar atividades. Abre o submenu “Cadastrar ação”, com “1 – Nova atividade” e “0 – Voltar ao menu principal”. Ao escolher 1, o sistema solicita, nesta ordem: código; data; escola; faixa etária; turma; atividade; equipe/função responsável; quantidade de alunos inscritos; quantidade de alunos que participaram; quantidade prevista da atividade no dia (meta); quantidade já realizada; situação (1 – Em andamento, 2 – Realizada, 3 – Cancelada); observações coletivas; quantidade de itens do check-list (de 0 a 5) e o texto de cada item. Ao final, é exibida a mensagem “Atividade cadastrada! Total: N” e o submenu reaparece, permitindo novo cadastro ou retorno ao menu. Se o limite de 100 atividades já tiver sido atingido, o sistema informa e não permite novo cadastro. 
Opção 2 – Listar atividades cadastradas. Exibe, para cada atividade, código, data, escola, turma, faixa etária, atividade, equipe responsável, alunos inscritos e participantes, frequência coletiva, percentual de participação, meta do dia e quantidade realizada, situação, observações coletivas e check-list, em que [X] indica item concluído e [ ] item pendente. Se não houver registros, aparece “Nenhuma atividade cadastrada.” 
Opção 3 – Pesquisar atividades. Abre um submenu com duas formas de busca. Na opção 1 (por código), o sistema mostra os dados completos da atividade ou informa “Atividade nao encontrada.”. Na opção 2 (por data), lista as atividades daquele dia com escola, turma, meta, quantidade feita e situação, e apresenta o total do dia (meta, realizado e quanto falta). A opção 0 volta ao menu principal. 
Opção 4 – Atualizar atividade e check-list. Solicita o código da atividade e abre um submenu que permanece ativo até o usuário escolher 0. Nele é possível alterar a situação (1), a quantidade de participantes (2, limitada ao número de inscritos), a quantidade realizada da meta (3) e as observações coletivas (4, sendo que Enter limpa o texto), além de marcar ou desmarcar um item do check-list informando o número do item (5). É necessário haver ao menos uma atividade cadastrada. 
Opção 5 – Gerar relatório / atividades do dia. Abre um submenu com duas escolhas. O relatório geral (1) mostra o total de atividades, a quantidade em andamento, realizadas e canceladas, o total de inscrições e de participações, a frequência coletiva em percentual, a meta total e as execuções realizadas. Como o mesmo aluno pode participar de várias atividades, essas somas não representam alunos únicos. A opção 2 apresenta as atividades de uma data, como na pesquisa por data. 
Opção 6 – Finalizar. Encerra o programa exibindo “Programa encerrado. Dados em memória descartados.”


