#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include <string.h>

main(){
	setlocale(LC_ALL, "portuguese");	
	int i=0, j=0, t, op, menu=0, vetor3[99], aux3, busca2;
	char vetor1[99][99], aux[99], vetor2[99][99], aux2[99], busca[99][99];
	char continuar='S';
	while (menu != 4 ){	
	//MENU
	system("cls");
	continuar='S';
	printf("#############################################\n");
	printf("|     BIT A BIT - SUA AGENDA ELETRÔNICA     |\n");
	printf("| 1 - CADASTRAR CONTATO                     |\n");
	printf("| 2 - BUSCAR CONTATO                        |\n");
	printf("| 3 - IMPRIMIR AGENDA                       |\n");
	printf("| 4 - SAIR                                  |\n");
	printf("#############################################\n");
	printf("## Digite a opção desejada:\n-->");
	scanf("%d",&menu);
	
	switch(menu){
	//CADASTRA CONTATO
	case 1:
		system("cls");
		while(continuar == 'S' || continuar == 's'){
			printf("#############################################\n");
			printf("|          ## CADASTRAR CONTATO ##          |\n");
			printf("#############################################\n");
			printf("Informe o nome do contato:\n-->");
			scanf("%s",&vetor1[i]);
			printf("Informe o telefone:(xx) xxxxx-xxxx\n-->");
			scanf(" %s", &vetor2[i]);
			printf("Informe o grupo:(1 - Família | 2 - Amigos | 3 - Trabalho)\n-->");
			scanf("%d",&vetor3[i]);
			i++;
			printf("Deseja cadastrar outro contato? S ou N\n");
			scanf("%s", &continuar);
		}
		t=i;
	break;
	//IMPRIME OS VETORES
	case 3:
		system("cls");
		continuar = 'S';
			while(continuar == 'S' || continuar == 's'){
			printf("#############################################\n");
			printf("|          ## IMPRIMINDO A AGENDA ##        |\n");
			printf("|1 - Ordem Alfabética                       |\n");
			printf("|2 - Ordenar por Grupo                      |\n");
			printf("#############################################\n");
		printf("-->");
		scanf("%d", &op);
		if(op==1){
			for (i = 0; i < t; i++) { 
	   			for (j =i + 1; j < t; j++) {
				      // verifica se tem que ser depois, se for troca de posição
				      if (strcmp(vetor1[i], vetor1[j]) > 0) {
				         strcpy(aux, vetor1[i]);
				         strcpy(vetor1[i], vetor1[j]);
				         strcpy(vetor1[j], aux);
				         //ordena os telefones
				         strcpy(aux2, vetor2[i]);
				         strcpy(vetor2[i], vetor2[j]);
				         strcpy(vetor2[j], aux2);
				         //ordena os grupos
					     aux3=vetor3[i];
					     vetor3[i]=vetor3[j];
					     vetor3[j]=aux3;
				         
				      }
	   			}
			}
		}
		else if(op==2){
			for (i=0; i<t; i++){
				for(j=i+1;j<t;j++){
					if(vetor3[i]>vetor3[j]){
						//ordena os grupos
						aux3=vetor3[i];
						vetor3[i]=vetor3[j];
						vetor3[j]=aux3;
				         //ordena os telefones
				         strcpy(aux2, vetor2[i]);
				         strcpy(vetor2[i], vetor2[j]);
				         strcpy(vetor2[j], aux2);
						//ordena os nomes
						strcpy(aux, vetor1[i]);
				        strcpy(vetor1[i], vetor1[j]);
				        strcpy(vetor1[j], aux);
					}
				}
			}
		
		}
			for (i=0; i<t; i++){
				printf("Nome: %s | Telefone: %s | Grupo: %d\n", vetor1[i], vetor2[i], vetor3[i]);
		    	printf("\n");
		}
			printf("Deseja imprimir em outro formato? S ou N\n");
			scanf("%s", &continuar);	
	}
	break;
	//FAZ A BUSCA POR OPÇÃO DO USUÁRIO	
	case 2:	
			continuar = 'S';
			while(continuar == 'S' || continuar == 's'){
			system("cls");
			printf("#############################################\n");
			printf("|          ## BUSCAR NA AGENDA ##           |\n");
			printf("|Buscar Contato:                            |\n");
			printf("|1 - Nome do Contato                        |\n");
			printf("|2 - Grupo                                  |\n");
			printf("#############################################\n");
		printf("-->");
		scanf("%d", &op);
		if(op == 1){
		
				printf("## Informe o nome para buscar na agenda:\n-->");
				scanf("%79s",busca[0]);
				i=0;
				while(i<=t){
					if(strcmp(vetor1[i],busca[0])==0){
						printf("Contato encontrado!\n-->");
						printf("Nome: %s | Telefone: %s | Grupo: %d\n", vetor1[i], vetor2[i], vetor3[i]);
						printf("\n");
						//break;
						}
					i++;
				}
			
		}
		else if(op == 2){
			
			printf("## Informe o grupo para buscar na agenda: (1 - Família | 2 - Amigos | 3 - Trabalho)\n-->");
				scanf("%d",&busca2);
				if (busca2==1){
					printf("Lista de contatos do grupo FAMÍLIA.\n");
				}
				else if(busca2==2){
					printf("Lista de contatos do grupo AMIGOS.\n");
				}
				else if(busca2==3){
					printf("Lista de contatos do grupo TRABALHO.\n");
				}
				i=0;
				
				while(i<=t){
					if(vetor3[i] == busca2){
						printf("Nome: %s | Telefone: %s | Grupo: %d\n", vetor1[i], vetor2[i], vetor3[i]);
						printf("\n");
						//break;
						}
					i++;
				}
		}
	printf("Deseja fazer outra busca? S ou N\n");
			scanf("%s", &continuar);
	}	
	break;
	default:
		break;
}
}
system("pause");	
}
