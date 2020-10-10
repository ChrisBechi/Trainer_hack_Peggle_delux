#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>

char auxNome[255];

criarScript(int id){
	int num=1;
	FILE *modeloS, *destino;
	char nome[50] = "componente/comp", aux[20];
	itoa(id,aux,10);
	strcat(nome,aux);
	strcat(nome,".h");
	strcpy(auxNome,nome);
	if((modeloS=fopen("Modelos/modeloScript.txt","r"))==NULL){
		printf("arquivo não encontrado");
	}
	if((destino=fopen(nome,"w"))==NULL){
		printf("arquivo não encontrado");
	}
	char temp[255];
	while(fgets(temp,255,modeloS) != NULL){
		switch(num){
			case 1:{
				char texto[255] = "#ifndef COMP",aux[50];
				itoa(id,aux,10);
				strcat(texto,aux);
				strcat(texto,"_H_INCLUDED\n");
				fprintf(destino,texto);
				break;
			}
			case 2:{
				char texto[255] = "#define COMP",aux[50];
				itoa(id,aux,10);
				strcat(texto,aux);
				strcat(texto,"_H_INCLUDED\n");
				fprintf(destino,texto);
				break;
			}
			case 8:{
				char texto[255] = "CEstilos",aux[50];
				itoa(id,aux,10);
				strcat(texto,aux);
				strcat(texto,"(LPARAM cor){\n");
				fprintf(destino,texto);
				break;
			}
			case 12:{
				char texto[255] = "CComponentesGraficos",aux[50];
				itoa(id,aux,10);
				strcat(texto,aux);
				strcat(texto,"(){\n");
				fprintf(destino,texto);
				break;
			}
			case 16:{
				char texto[255] = "CComandos",aux[50];
				itoa(id,aux,10);
				strcat(texto,aux);
				strcat(texto,"(WPARAM id){\n");
				fprintf(destino,texto);
				break;
			}default:
				fprintf(destino,temp);
		}
		num++;
	}
	fclose(modeloS);
	fclose(destino);
}

criarJanela(int id){
	int num=1;
	FILE *modelo, *destino;
	char nome[50] = "main/janela", aux[20];
	itoa(id,aux,10);
	strcat(nome,aux);
	strcat(nome,".h");
	if((modelo=fopen("Modelos/modeloJanela.txt","r"))==NULL){
		printf("arquivo não encontrado");
	}
	if((destino=fopen(nome,"w"))==NULL){
		printf("arquivo não encontrado");
	}
	char temp[255] ="";
	while(fgets(temp,255,modelo) != NULL){
		if(num==3){
			char texto[255] = "#include \"../Componente/comp",aux[50];
			itoa(id,aux,10);
			strcat(texto,aux);
			strcat(texto,".h\"\n\n");
			fprintf(destino,texto);
		}else if(num==4){
			char texto[255] = "int idJanela",aux[50];
			itoa(id,aux,10);
			strcat(texto,aux);
			strcat(texto," = -1, cont");
			strcat(texto,aux);
			strcat(texto,"=0;\n");
			fprintf(destino,texto);
		}else if(num==6){
			char texto[255] = "LRESULT CALLBACK newJanela",aux[50];
			itoa(id,aux,10);
			strcat(texto,aux);
			strcat(texto,"(HWND,UINT,WPARAM,LPARAM);\n");
			fprintf(destino,texto);
		}else if(num==8){
			char texto[255] = "WPARAM CJanelaN",aux[50];
			itoa(id,aux,10);
			strcat(texto,aux);
			strcat(texto,"(const char *titulo, float pos_x, float pos_y, float altura, float largura){\n");
			fprintf(destino,texto);
		}else if(num==9){
			char texto[255] = "	if(idJanela",aux[50];
			itoa(id,aux,10);
			strcat(texto,aux);
			strcat(texto," != -1)return -1;\n");
			fprintf(destino,texto);
		}else if(num==19){
			char texto[255] = "	jan.lpfnWndProc = newJanela",aux[50];
			itoa(id,aux,10);
			strcat(texto,aux);
			strcat(texto,";\n");
			fprintf(destino,texto);
		}else if(num==28){
			char texto[255] = "	Construtora=idJanela",aux[50];
			itoa(id,aux,10);
			strcat(texto,aux);
			strcat(texto,"=janelaNula();\n");
			fprintf(destino,texto);
		}else if(num==29){
			char texto[255] = "	hcomp[idJanela",aux[50];
			itoa(id,aux,10);
			strcat(texto,aux);
			strcat(texto,"][0] = CreateWindowEx(0,titulo,titulo,WS_OVERLAPPED|WS_MINIMIZEBOX|WS_SYSMENU,pos_x,pos_y,largura,altura,NULL,NULL,window,NULL);\n");
			fprintf(destino,texto);
		}else if(num==30){
			char texto[255] = "	ShowWindow(hcomp[idJanela",aux[50];
			itoa(id,aux,10);
			strcat(texto,aux);
			strcat(texto,"][0],1);\n");
			fprintf(destino,texto);
		}else if(num==38){
			char texto[255] = "LRESULT CALLBACK newJanela",aux[50];
			itoa(id,aux,10);
			strcat(texto,aux);
			strcat(texto,"(HWND hwnd, UINT inteiro, WPARAM wpa, LPARAM lpa){\n");
			fprintf(destino,texto);
		}else if(num==42){
			char texto[255] = "			CComponentesGraficos",aux[50];
			itoa(id,aux,10);
			strcat(texto,aux);
			strcat(texto,"();\n			break;\n");
			fprintf(destino,texto);
		}else if(num==45){
			char texto[255] = "			Construtora=idJanela",aux[50];
			itoa(id,aux,10);
			strcat(texto,aux);
			strcat(texto,";\n");
			fprintf(destino,texto);
		}else if(num==46){
			char texto[255] = "			CComandos",aux[50];
			itoa(id,aux,10);
			strcat(texto,aux);
			strcat(texto,"(wpa);\n			break;\n		}\n");
			fprintf(destino,texto);
		}else if(num==50){
			char texto[255] = "			CEstilos",aux[50];
			itoa(id,aux,10);
			strcat(texto,aux);
			strcat(texto,"(lpa);\n");
			fprintf(destino,texto);
		}else if(num==56){
			char texto[255] = "				hcomp[idJanela",aux[50];
			itoa(id,aux,10);
			strcat(texto,aux);
			strcat(texto,"][i] = NULL;\n");
			fprintf(destino,texto);
		}else if(num==57){
			char texto[255] = "			idJanela",aux[50];
			itoa(id,aux,10);
			strcat(texto,aux);
			strcat(texto,"=-1;\n");
			fprintf(destino,texto);
		}else if(num==62){
			char texto[255] = "			SendMessage(hcomp[idJanela",aux[50];
			itoa(id,aux,10);
			strcat(texto,aux);
			strcat(texto,"][idBarra],PBM_STEPIT,0,0);\n");
			fprintf(destino,texto);
		}else if(num==63){
			char texto[255] = "			cont",aux[50];
			itoa(id,aux,10);
			strcat(texto,aux);
			strcat(texto,"++;\n");
			fprintf(destino,texto);
		}else if(num==64){
			char texto[255] = "			if(cont",aux[50];
			itoa(id,aux,10);
			strcat(texto,aux);
			strcat(texto," == timeBarr){\n");
			fprintf(destino,texto);
		}else{
			fprintf(destino,temp);
		}
		num++;
	}
	fclose(modelo);
	fclose(destino);
}

main(){
	setlocale(LC_ALL,"portuguese");
	system("title Gerar Janela");
	int id;
	printf("informe o id da nova janela: ");
	scanf("%d",&id);
	criarScript(id);
	criarJanela(id);
}
