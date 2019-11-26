#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 
struct lista{
        int  palavra[30];
        int contador;
        struct lista *prox;
};
 

int main(int argc, char **argv){


struct lista *cabeca=malloc(sizeof(struct lista));
struct lista *final=malloc(sizeof(struct lista));
 
int offset=0,cont=0;
int buffer[30]={};
int palavra=0,dentrofunc=0;
int opcao;

//arquivo sendo lido
FILE *arqui=fopen(argv[1],"r");

if(arqui==NULL){
fprintf(stderr,"Uso certo: ./dicionario ""arquivo-desejado""\n");
return 1;
};
//arquivo a ser escrito
FILE *output=fopen("dicionario.txt","w");
 
//descobrindo tamanho do arquivo 
fseek(arqui,0,SEEK_END);
offset=ftell(arqui);
fseek(arqui,0,SEEK_SET);
 
final=cabeca;
cabeca->prox=NULL;


for(int a=0;a<offset;a++){
//pegando letra por letra
    palavra=fgetc(arqui);


//verificando se o caractere atual é um "espaço" ou um "pular linha" 
        if(palavra == 0x20 || palavra == 0x0a){
                buffer[cont]='\0';


//a primeira palavra a ser inserida precisa ser uma excessao por causa da comparacao 
//com uma lista nao inicializada
		if(cabeca->prox==NULL){
         	
		struct lista *novo;
                novo=malloc(sizeof(struct lista));

		memcpy(novo->palavra,buffer,sizeof(int)*cont);
		
		novo->contador=1;
                memset(&buffer,0,30);
                cont=0;
                palavra=0;
                final->prox=novo;
                final=novo;
                final->prox=NULL;
		}else{

//estrutura de comparacao para checar se a palavra ja existe		

		struct lista *teste=cabeca->prox;
	
		while(teste != NULL){
//		comparando a palavra do nó atual com a formada no buffer
			if(memcmp(buffer,teste->palavra,30)==0){
			teste->contador+=1;
                	memset(&buffer,0,30);
                	cont=0;
                	palavra=0;
			break;
			
			}else{
//		verificando se o nó atual é o ultimo da lista
				if(teste->prox==NULL){
		
                struct lista *novo;
                novo=malloc(sizeof(struct lista));

		memcpy(novo->palavra,buffer,sizeof(int)*cont);
		
		novo->contador=1;
                memset(&buffer,0,30);
                cont=0;
                palavra=0;
                final->prox=novo;
                final=novo;
                final->prox=NULL;
		break;
    }else{    
			teste=teste->prox;
	};	

};
};
};
//transferindo o caractere atual para o buffer
	}else{
 
        buffer[cont]=palavra;
        cont++;
        palavra=0;
        };
};

struct lista *teste=cabeca->prox;

printf("1- Gerar dicionario com cadencia de palavras\n2- Ver como seria o arquivo de saida\n3- Sair\n");
scanf("%d",&opcao);

switch(opcao){

case 1:
while(teste != NULL){
	for(int b=0;b<offset;b++){
	if(teste->palavra[b]=='\0'){
		break;
	}else{
//		printf("%c",teste->palavra[b]);
		fputc(teste->palavra[b],output);	
};
	};
//	printf("    %d\n",teste->contador);
	fprintf(output,"  %d",teste->contador);
	fputc(0x0a,output);
	teste=teste->prox;
};
break;
 
case 2:

while(teste != NULL){
	for(int b=0;b<offset;b++){
	if(teste->palavra[b]=='\0'){
		break;
	}else{
		printf("%c",teste->palavra[b]);
	};
	};
	printf("    %d\n",teste->contador);
	teste=teste->prox;
};

break;

case 3:
 break;

};

fclose(arqui);
fclose(output);

struct lista *desalocando=cabeca->prox;

while(cabeca != NULL){
	desalocando=cabeca;
	cabeca=cabeca->prox;	
	free(desalocando);
	
};

return 0;
};
