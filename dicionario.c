#include<stdio.h>
#include<string.h>

int main(){

int offset=0,cont=0;
int buffer[30]={};
int palavra=0,dentrofunc=0;
FILE *arqui=fopen("teste.txt","r");

fseek(arqui,0,SEEK_END);
offset=ftell(arqui);
fseek(arqui,0,SEEK_SET);


for(int a=0;a<offset;a++){
palavra=fgetc(arqui);
	
	if(palavra == 0x20 || palavra == 0x0a){
		buffer[cont]='\0';
		for(int v=0;v<offset;v++){
			if(buffer[v-1]=='\0'){
				break;
			}else{
			printf("%c",buffer[v]);
		}
		};
	
		puts(" ");
		memset(&buffer,0,30);
		cont=0;
		palavra=0;
	}else{

	
	buffer[cont]=palavra;
	cont++;
	palavra=0;
	};
};

return 0;
};


