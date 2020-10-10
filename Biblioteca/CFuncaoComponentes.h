#include <windows.h>
#include <commctrl.h>
#include <locale.h>
#include "varAmbiente.h"
#include <string.h>
#ifndef CFUNCAOCOMPONENTES_H_INCLUDED
#define CFUNCAOCOMPONENTES_H_INCLUDED

	char * CToStr(char *msg){
		char *final = (char *) malloc(sizeof(char*));
		strcpy(final,"'");
		strcat(final,msg);
		strcat(final,"'");
		return final;
	}

    //Define o progresso da barra e o tempo a ser percorrido.
	int CProgresso(int IDBarra, int Tempo){
		if(Tempo != 100 && Tempo != 500 && Tempo != 1000){
			MessageBox(NULL,"Os valores aceitos são: 100, 500 e 1000","Valores invalidos",0x30);
			return 0;
		}
		idBarra = IDBarra;
		SendMessage(hcomp[Construtora][idBarra], PBM_SETRANGE, 0, MAKELPARAM(0,Tempo));	
		SetTimer(hand,(intptr_t) NULL,Tempo,0);
		SendMessage(hcomp[Construtora][idBarra],PBM_SETBARCOLOR,0,RGB(54,201,0));
		if(Tempo == 100){
			timeBarr = 10;
		}else if(Tempo == 500){
			timeBarr = 50;
		}else if(Tempo == 1000){
			timeBarr = 100;
		}
	}
	
	//Utilizado no controle do slider para obter o valor atual do controle e adicionado a um label
	void CAtualizaS(int IdSlider,int IdText){
		idSlider=IdSlider;
		idComp=IdText;		
	}
	
	void CComplementaAtualizaS(){
		int i,val = SendMessage(hcomp[Construtora][idSlider],TBM_GETPOS,0,0);
		char aux[20],lol[20] = "";
		itoa(val,aux,10);
		for(i=0;i<strlen(aux)*2;i++)
			strcat(lol,"  ");
		SetWindowText(hcomp[Construtora][idComp],lol);
		SetWindowText(hcomp[Construtora][idComp],aux);
	}
	
	//Usado dentro do CComando para habilitar ou desabilitar a caixa.
	void CCheck(int idCheckBox){
		if(IsDlgButtonChecked(hand,idCheckBox) == TRUE){
			CheckDlgButton(hand,idCheckBox, BST_UNCHECKED);
		}else{
			CheckDlgButton(hand,idCheckBox, BST_CHECKED);
		}
	}
	
	//Obtem o valor 1 se o componente está selecionado ou 0 caso não esteja selecionado.
	int CObterCheck(int idCheckBox){
		return IsDlgButtonChecked(hand,idCheckBox);	
	}
	
	//Obtem o texto que está vinculado ao componente atualmente selecionado dentro do range
	char * CObterGRadio(int idGrupos[]){
		int contVetor;
		char *msg = (char *) malloc(sizeof(char));
		for(contVetor=1;contVetor<=idGrupos[0];contVetor++){
			if(IsDlgButtonChecked(hand,idGrupos[contVetor]) == 1){
				GetWindowText(hcomp[Construtora][idGrupos[contVetor]],msg,100);
				return msg;
			}
		}
		return "";
	}
	
	//Retorna o texto que está vinculado ao componente.
	char * CObterTexto(int idComp){
		char *aux = (char *) malloc(sizeof(char *));
		GetWindowText(hcomp[Construtora][idComp],aux,50);
		return aux;
	}
	
	//Retorna o nome do item selecionado na lista
	char * CObterLista(int idLista){
			char *aux = (char *) malloc(sizeof(char *));
			int i = SendMessage(hcomp[Construtora][idLista],LB_GETCURSEL,0,0); 
			SendMessage(hcomp[Construtora][idLista],LB_GETTEXT,(LPARAM)i,(WPARAM)aux); 
			return aux;
	}
	
	//Retorna a quantidade total de itens de uma lista.
	int CTotalLista(int idLista){
			int i = SendMessage(hcomp[Construtora][idLista],LB_GETCOUNT,0,0); 
			return i;
	}
	
	//Retorna uma matriz com todos os elementos de uma lista.
	char** CTodosItens(int idLista){
		int i, total=SendMessage(hcomp[Construtora][idLista],LB_GETCOUNT,0,0);
		char **itens = malloc(total * sizeof(char*));;
		for(i=0;i<total;i++){
			itens[i] = malloc(100 * sizeof(char));
			SendMessage(hcomp[Construtora][idLista],LB_GETTEXT,i,(LPARAM)itens[i]);
		}
		return itens;
	}
	
	//Apaga todos os itens de uma lista
	void CApagarItens(int idLista){
		int index,total = SendMessage(hcomp[Construtora][idLista],LB_GETCOUNT,0,0);
		for(index=0;index<total;index++){
			SendMessage(hcomp[Construtora][idLista],LB_DELETESTRING,0,(LPARAM)NULL);
		}
	}
	
	//Insere um texto, mas antes ele apaga todo o conteudo que ali estava.
	void CInserirArquivo(char *texto){
		FILE *arquivo;
		char caminho[255];
		strcpy(caminho,CSalvarArquivo());
		if((arquivo=fopen(caminho,"wb"))==NULL){
			MessageBox(NULL,"Não foi possivel abrir o arquivo!","Erro de abertura",0x10|MB_OK);
		}
		fputs(texto,arquivo);
		fclose(arquivo);
	}
	
	//Inclui um texto a um determinado arquivo
	void CAdicionarArquivo(char *texto){
		FILE *arquivo;
		char caminho[255];
		strcpy(caminho,CSalvarArquivo());
		if((arquivo=fopen(caminho,"a"))==NULL){
			MessageBox(NULL,"Não foi possivel abrir o arquivo!","Erro de abertura",0x10|MB_OK);
		}
		fprintf(arquivo,"%s","\n");
		fprintf(arquivo,"%s",texto);
		fclose(arquivo);
	}
	
	//Obtem um vetor com todos os itens de um arquivo de texto
	char ** CObterArquivo(){
		FILE *arquivo;
		int i,numberLine=1;
		char caminho[255];
		strcpy(caminho,CBuscarArquivo());
		if((arquivo=fopen(caminho,"r"))==NULL){
			MessageBox(NULL,"Não foi possivel abrir o arquivo!","Erro de abertura",0x10|MB_OK);
		}
		while(fgets(caminho,255,arquivo) != NULL){
				numberLine++;		
		}
		rewind(arquivo);
		char **itens = malloc(numberLine * sizeof(char*));
		for(i=0;i<numberLine;i++){
			itens[i] = malloc(100 * sizeof(char));
			fgets(itens[i],100,arquivo);
		}
		fclose(arquivo);
		return itens;
	}
	
	//Retorna o item para o componente passado por parametro ou se for 0 retorna pra um area de texto
	void CLerArquivo(int idComp, int linha){
		FILE *arquivo;
		int numberLine=1;
		char caminho[255];
		strcpy(caminho,CBuscarArquivo());
		if((arquivo=fopen(caminho,"r"))==NULL){
			MessageBox(NULL,"Não foi possivel abrir o arquivo!","Erro de abertura",0x10|MB_OK);
		}
		if(linha == 0){
			while(fgets(caminho,255,arquivo) != NULL){
				int idx = GetWindowTextLength(hcomp[Construtora][idComp]);
    			SendMessage(hcomp[Construtora][idComp], EM_SETSEL, (WPARAM)idx, (LPARAM)idx);
    			SendMessage(hcomp[Construtora][idComp], EM_REPLACESEL, 0, (LPARAM)caminho);
			}
		}else{
			while(fgets(caminho,255,arquivo) != NULL){
				if(linha == numberLine)break;
				numberLine++;		
			}
			if(linha != numberLine)
			 	MessageBox(NULL,"Linha invalida","numero incorreto",MB_OK|0x10);
			else
				SetWindowText(hcomp[Construtora][idComp],caminho);
		}
		fclose(arquivo);
	}
		
	//Apaga um item da lista que está selecionado
	void CApagarItem(int idLista){
		int index,posicao = SendMessage(hcomp[Construtora][idLista],LB_GETCURSEL,0,0);
		SendMessage(hcomp[Construtora][idLista],LB_DELETESTRING,posicao,(LPARAM)NULL);
	}
	
	//Desabilita o componente que foi passado o id
	void CDesabilitar(int idComp, int status){
		EnableWindow(hcomp[Construtora][idComp],status);
	}

	//Obtem o nome de um item de uma lista suspensa
	char * CObterItem(int id){
		int itens;
		char *nome = (char*) malloc(sizeof(char));
		itens = SendMessage(hcomp[Construtora][id],CB_GETCURSEL,0,0);
		SendMessage(hcomp[Construtora][id],CB_GETLBTEXT,(WPARAM)itens,(LPARAM)nome);
		return nome;
	}
	
	//Usado para pegar a handle do componente a ser estilizado (mudando a cor do fundo ou a cor da letra)
	LPARAM CObterID(int codigo){
		return (LPARAM) GetDlgItem(hand,codigo);
	}
	
	//Modifica a Cor da Palavra definida no estilo do componente
	LPARAM CMCP(int R, int G, int B){
		HDC lol = (HDC) wpara;
		SetTextColor((HDC) lol,RGB(R,G,B));
		return (LPARAM)GetStockObject(NULL_BRUSH);
	}
	
	//Modifica a cor de fundo de uma janela
	void CMCF(int R, int G, int B){
		colr = RGB(R,G,B);
	}
	
	//Modifica a Cor de Fundo de um componente. Ex: Label
	LPARAM CMFP(int R, int G, int B){
		HDC lol = (HDC) wpara;
		/*Se algum dos valores for negativo a cor do fundo é transparente 
		se não é a cor em RGB definida pelo usuario*/
		if(R < 0 || G < 0 || B < 0){
			SetBkMode((HDC) lol,TRANSPARENT);
		}else{
			SetBkColor((HDC) lol,RGB(R,G,B));
		}
		return (LPARAM)GetStockObject(NULL_BRUSH);
	}
	//Deixa a cor de qualquer componente transparente Não importando o id do componente
	LPARAM CFundoT(){
		HDC tran = (HDC) wpara;
		SetBkMode(tran,TRANSPARENT);
		return (LPARAM)GetStockObject(NULL_BRUSH);
	}
	
	//Modifica o icone da janela definido em componentes Graficos da janela
	void CModIcone(const char *icon){
		char texto[255] = "imagem/";
		strcat(texto,icon);
		HICON lol = (HICON) LoadImage(NULL,texto,IMAGE_ICON,32,32,LR_LOADFROMFILE);
		SendMessage(hand, WM_SETICON, ICON_SMALL, (LPARAM) lol);
	}
	
	//Realiza a organização dos arquivos necessarios
	void inicializa(){
		system("rm Index.o");
		system("rm Makefile.win");
		system("rm CBGI.layout");
	}
#endif
