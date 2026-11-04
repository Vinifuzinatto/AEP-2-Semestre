#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void cad_acoes() {
	int op;
	
	do{
		printf("\n==========CADASTRAR AÇÃO========== \n");
		printf("1- \n");
		printf("0- Sair \n");
		
		printf("\nEscolha a opção: ");
		scanf("%d", &op);
		
		switch(op) {
			case 1:
				printf("\nbla bla bla \n");
				break;
			
			case 0:
				printf("\nSaindo... \n\n");
				break;
			
			default:
				printf("\nOpcão inválida! Tente novamente! \n");
				
		}
	} while(op != 0);
}

void list_acoes_cad() {
	
}

void pesq_acoes() {
	
}

void atualizar_acoes() {
	
}

void resumo() {

}

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int op;
	
	do {
		printf("MENU DE AÇÕES! \n\n");
		
		printf("1- Cadastrar ações \n");
		printf("2- Listar ações cadastradas \n");
		printf("3- Pesquisar ações \n");
		printf("4- Atualizar situação de uma ação \n");
		printf("5- Gerar resumo geral \n");
		printf("6- Finalizar! \n");
		
		printf("\nEscolha a opção: ");
		scanf("%d", &op);
		
		switch(op) {
			
			case 1:
				cad_acoes();
				break;
				
			case 2:
				list_acoes_cad();
				break;
				
			case 3:
				pesq_acoes();
				break;
				
			case 4:
				atualizar_acoes();
				break;
					
			case 5:
				resumo();
				break;
				
			default:
				printf("\nOpcão inválida! Tente novamente! \n\n");
		}
	}while(op != 6);

	return 0;
}
