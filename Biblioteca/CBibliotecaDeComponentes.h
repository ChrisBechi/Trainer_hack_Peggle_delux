#include <windows.h>
#include <commctrl.h>
#include "varAmbiente.h"
#include <string.h>
#include <stdio.h>
#ifndef CBIBLIOTECADECOMPONENTES_H_INCLUDED
#define CBIBLIOTECADECOMPONENTES_H_INCLUDED
	int ncomp=0;
	
	void CCriarMenu(int qtdItem, char Menu1[][100], char Menu2[][100], char Menu3[][100], char Menu4[][100], char Menu5[][100], char Menu6[][100], char Menu7[][100], char Menu8[][100], char Menu9[][100], char Menu10[][100]){
		switch(qtdItem){
			case 1:{
				int i;
				HMENU menuBar = CreateMenu();
				HMENU opcao1 = CreateMenu();
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao1, Menu1[1]);
				for(i=2;i<=atoi(Menu1[0]);i++){
					if(strcmp(Menu1[i],"linha") == 0){
						AppendMenu(opcao1, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu1[i][aux] != '-' && Menu1[i][aux] != '\0'){
							texto[aux] = Menu1[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao1, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu1[i][aux] != '\0'){
							if(Menu1[i][aux] == '-'){
								Menu1[i][aux-1] = '\0';
								while(Menu1[i][aux] != '\0'){
									image[count] = Menu1[i][aux+1];
									aux++;
									count++;
								}
								image[count] = '\0';
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao1,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
					}
				}
				SetMenu(hand, menuBar);
				SetMenu(hand, opcao1);
				break;
			}
			case 2:{
				int i;
				HMENU menuBar = CreateMenu();
				HMENU opcao1 = CreateMenu();
				HMENU opcao2 = CreateMenu();
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao1, Menu1[1]);
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao2, Menu2[1]);
				for(i=2;i<=atoi(Menu1[0]);i++){
					if(strcmp(Menu1[i],"linha") == 0){
						AppendMenu(opcao1, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu1[i][aux] != '-' && Menu1[i][aux] != '\0'){
							texto[aux] = Menu1[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao1, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu1[i][aux] != '\0'){
							if(Menu1[i][aux] == '-'){
								Menu1[i][aux-1] = '\0';
								while(Menu1[i][aux] != '\0'){
									image[count] = Menu1[i][aux+1];
									aux++;
									count++;
								}
								image[count] = '\0';
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao1,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				for(i=2;i<=atoi(Menu2[0]);i++){
					if(strcmp(Menu2[i],"linha") == 0){
						AppendMenu(opcao2, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu2[i][aux] != '-' && Menu2[i][aux] != '\0'){
							texto[aux] = Menu2[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao2, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu2[i][aux] != '\0'){
							if(Menu2[i][aux] == '-'){
								Menu2[i][aux-1] = '\0';
								while(Menu2[i][aux] != '\0'){
									image[count] = Menu2[i][aux+1];
									aux++;
									count++;
								}
								image[count] = '\0';
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao2,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				SetMenu(hand, menuBar);
				SetMenu(hand, opcao1);
				SetMenu(hand, opcao2);
				break;
			}
			case 3:{
				int i;
				HMENU menuBar = CreateMenu();
				HMENU opcao1 = CreateMenu();
				HMENU opcao2 = CreateMenu();
				HMENU opcao3 = CreateMenu();
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao1, Menu1[1]);
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao2, Menu2[1]);
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao3, Menu3[1]);
				for(i=2;i<=atoi(Menu1[0]);i++){
					if(strcmp(Menu1[i],"linha") == 0){
						AppendMenu(opcao1, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu1[i][aux] != '-' && Menu1[i][aux] != '\0'){
							texto[aux] = Menu1[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao1, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu1[i][aux] != '\0'){
							if(Menu1[i][aux] == '-'){
								Menu1[i][aux-1] = '\0';
								while(Menu1[i][aux] != '\0'){
									image[count] = Menu1[i][aux+1];
									aux++;
									count++;
								}
								image[count] = '\0';
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao1,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				for(i=2;i<=atoi(Menu2[0]);i++){
					if(strcmp(Menu2[i],"linha") == 0){
						AppendMenu(opcao2, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu2[i][aux] != '-' && Menu2[i][aux] != '\0'){
							texto[aux] = Menu2[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao2, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu2[i][aux] != '\0'){
							if(Menu2[i][aux] == '-'){
								Menu2[i][aux-1] = '\0';
								while(Menu2[i][aux] != '\0'){
									image[count] = Menu2[i][aux+1];
									aux++;
									count++;
								}
								image[count] = '\0';
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao2,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				for(i=2;i<=atoi(Menu3[0]);i++){
					if(strcmp(Menu3[i],"linha") == 0){
						AppendMenu(opcao3, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu3[i][aux] != '-' && Menu3[i][aux] != '\0'){
							texto[aux] = Menu3[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao3, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu3[i][aux] != '\0'){
							if(Menu3[i][aux] == '-'){
								Menu3[i][aux-1] = '\0';
								while(Menu3[i][aux] != '\0'){
									image[count] = Menu3[i][aux+1];
									aux++;
									count++;
								}
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao3,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				SetMenu(hand, menuBar);
				SetMenu(hand, opcao1);
				SetMenu(hand, opcao2);
				SetMenu(hand, opcao3);
				break;
			}
			case 4:{
				int i;
				HMENU menuBar = CreateMenu();
				HMENU opcao1 = CreateMenu();
				HMENU opcao2 = CreateMenu();
				HMENU opcao3 = CreateMenu();
				HMENU opcao4 = CreateMenu();
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao1, Menu1[1]);
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao2, Menu2[1]);
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao3, Menu3[1]);
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao4, Menu4[1]);
				for(i=2;i<=atoi(Menu1[0]);i++){
					if(strcmp(Menu1[i],"linha") == 0){
						AppendMenu(opcao1, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu1[i][aux] != '-' && Menu1[i][aux] != '\0'){
							texto[aux] = Menu1[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao1, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu1[i][aux] != '\0'){
							if(Menu1[i][aux] == '-'){
								Menu1[i][aux-1] = '\0';
								while(Menu1[i][aux] != '\0'){
									image[count] = Menu1[i][aux+1];
									aux++;
									count++;
								}
								image[count] = '\0';
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao1,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				for(i=2;i<=atoi(Menu2[0]);i++){
					if(strcmp(Menu2[i],"linha") == 0){
						AppendMenu(opcao2, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu2[i][aux] != '-' && Menu2[i][aux] != '\0'){
							texto[aux] = Menu2[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao2, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu2[i][aux] != '\0'){
							if(Menu2[i][aux] == '-'){
								Menu2[i][aux-1] = '\0';
								while(Menu2[i][aux] != '\0'){
									image[count] = Menu2[i][aux+1];
									aux++;
									count++;
								}
								image[count] = '\0';
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao2,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				for(i=2;i<=atoi(Menu3[0]);i++){
					if(strcmp(Menu3[i],"linha") == 0){
						AppendMenu(opcao3, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu3[i][aux] != '-' && Menu3[i][aux] != '\0'){
							texto[aux] = Menu3[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao3, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu3[i][aux] != '\0'){
							if(Menu3[i][aux] == '-'){
								Menu3[i][aux-1] = '\0';
								while(Menu3[i][aux] != '\0'){
									image[count] = Menu3[i][aux+1];
									aux++;
									count++;
								}
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao3,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				for(i=2;i<=atoi(Menu4[0]);i++){
					if(strcmp(Menu4[i],"linha") == 0){
						AppendMenu(opcao4, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu4[i][aux] != '-' && Menu4[i][aux] != '\0'){
							texto[aux] = Menu4[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao4, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu4[i][aux] != '\0'){
							if(Menu4[i][aux] == '-'){
								Menu4[i][aux-1] = '\0';
								while(Menu4[i][aux] != '\0'){
									image[count] = Menu4[i][aux+1];
									aux++;
									count++;
								}
								image[count] = '\0';
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao4,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				SetMenu(hand, menuBar);
				SetMenu(hand, opcao1);
				SetMenu(hand, opcao2);
				SetMenu(hand, opcao3);
				SetMenu(hand, opcao4);
				break;
			}
			case 5:{
				int i;
				HMENU menuBar = CreateMenu();
				HMENU opcao1 = CreateMenu();
				HMENU opcao2 = CreateMenu();
				HMENU opcao3 = CreateMenu();
				HMENU opcao4 = CreateMenu();
				HMENU opcao5 = CreateMenu();
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao1, Menu1[1]);
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao2, Menu2[1]);
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao3, Menu3[1]);
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao4, Menu4[1]);
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao5, Menu5[1]);
				for(i=2;i<=atoi(Menu1[0]);i++){
					if(strcmp(Menu1[i],"linha") == 0){
						AppendMenu(opcao1, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu1[i][aux] != '-' && Menu1[i][aux] != '\0'){
							texto[aux] = Menu1[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao1, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu1[i][aux] != '\0'){
							if(Menu1[i][aux] == '-'){
								Menu1[i][aux-1] = '\0';
								while(Menu1[i][aux] != '\0'){
									image[count] = Menu1[i][aux+1];
									aux++;
									count++;
								}
								image[count] = '\0';
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao1,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				for(i=2;i<=atoi(Menu2[0]);i++){
					if(strcmp(Menu2[i],"linha") == 0){
						AppendMenu(opcao2, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu2[i][aux] != '-' && Menu2[i][aux] != '\0'){
							texto[aux] = Menu2[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao2, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu2[i][aux] != '\0'){
							if(Menu2[i][aux] == '-'){
								Menu2[i][aux-1] = '\0';
								while(Menu2[i][aux] != '\0'){
									image[count] = Menu2[i][aux+1];
									aux++;
									count++;
								}
								image[count] = '\0';
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao2,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				for(i=2;i<=atoi(Menu3[0]);i++){
					if(strcmp(Menu3[i],"linha") == 0){
						AppendMenu(opcao3, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu3[i][aux] != '-' && Menu3[i][aux] != '\0'){
							texto[aux] = Menu3[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao3, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu3[i][aux] != '\0'){
							if(Menu3[i][aux] == '-'){
								Menu3[i][aux-1] = '\0';
								while(Menu3[i][aux] != '\0'){
									image[count] = Menu3[i][aux+1];
									aux++;
									count++;
								}
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao3,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				for(i=2;i<=atoi(Menu4[0]);i++){
					if(strcmp(Menu4[i],"linha") == 0){
						AppendMenu(opcao4, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu4[i][aux] != '-' && Menu4[i][aux] != '\0'){
							texto[aux] = Menu4[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao4, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu4[i][aux] != '\0'){
							if(Menu4[i][aux] == '-'){
								Menu4[i][aux-1] = '\0';
								while(Menu4[i][aux] != '\0'){
									image[count] = Menu4[i][aux+1];
									aux++;
									count++;
								}
								image[count] = '\0';
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao4,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				for(i=2;i<=atoi(Menu5[0]);i++){
					if(strcmp(Menu5[i],"linha") == 0){
						AppendMenu(opcao5, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu5[i][aux] != '-' && Menu5[i][aux] != '\0'){
							texto[aux] = Menu5[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao5, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu5[i][aux] != '\0'){
							if(Menu5[i][aux] == '-'){
								Menu5[i][aux-1] = '\0';
								while(Menu5[i][aux] != '\0'){
									image[count] = Menu5[i][aux+1];
									aux++;
									count++;
								}
								image[count] = '\0';
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao5,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				SetMenu(hand, menuBar);
				SetMenu(hand, opcao1);
				SetMenu(hand, opcao2);
				SetMenu(hand, opcao3);
				SetMenu(hand, opcao4);
				SetMenu(hand, opcao5);
				break;
			}
			case 6:{
				int i;
				HMENU menuBar = CreateMenu();
				HMENU opcao1 = CreateMenu();
				HMENU opcao2 = CreateMenu();
				HMENU opcao3 = CreateMenu();
				HMENU opcao4 = CreateMenu();
				HMENU opcao5 = CreateMenu();
				HMENU opcao6 = CreateMenu();
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao1, Menu1[1]);
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao2, Menu2[1]);
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao3, Menu3[1]);
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao4, Menu4[1]);
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao5, Menu5[1]);
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao6, Menu6[1]);
				for(i=2;i<=atoi(Menu1[0]);i++){
					if(strcmp(Menu1[i],"linha") == 0){
						AppendMenu(opcao1, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu1[i][aux] != '-' && Menu1[i][aux] != '\0'){
							texto[aux] = Menu1[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao1, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu1[i][aux] != '\0'){
							if(Menu1[i][aux] == '-'){
								Menu1[i][aux-1] = '\0';
								while(Menu1[i][aux] != '\0'){
									image[count] = Menu1[i][aux+1];
									aux++;
									count++;
								}
								image[count] = '\0';
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao1,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				for(i=2;i<=atoi(Menu2[0]);i++){
					if(strcmp(Menu2[i],"linha") == 0){
						AppendMenu(opcao2, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu2[i][aux] != '-' && Menu2[i][aux] != '\0'){
							texto[aux] = Menu2[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao2, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu2[i][aux] != '\0'){
							if(Menu2[i][aux] == '-'){
								Menu2[i][aux-1] = '\0';
								while(Menu2[i][aux] != '\0'){
									image[count] = Menu2[i][aux+1];
									aux++;
									count++;
								}
								image[count] = '\0';
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao2,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				for(i=2;i<=atoi(Menu3[0]);i++){
					if(strcmp(Menu3[i],"linha") == 0){
						AppendMenu(opcao3, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu3[i][aux] != '-' && Menu3[i][aux] != '\0'){
							texto[aux] = Menu3[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao3, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu3[i][aux] != '\0'){
							if(Menu3[i][aux] == '-'){
								Menu3[i][aux-1] = '\0';
								while(Menu3[i][aux] != '\0'){
									image[count] = Menu3[i][aux+1];
									aux++;
									count++;
								}
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao3,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				for(i=2;i<=atoi(Menu4[0]);i++){
					if(strcmp(Menu4[i],"linha") == 0){
						AppendMenu(opcao4, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu4[i][aux] != '-' && Menu4[i][aux] != '\0'){
							texto[aux] = Menu4[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao4, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu4[i][aux] != '\0'){
							if(Menu4[i][aux] == '-'){
								Menu4[i][aux-1] = '\0';
								while(Menu4[i][aux] != '\0'){
									image[count] = Menu4[i][aux+1];
									aux++;
									count++;
								}
								image[count] = '\0';
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao4,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				for(i=2;i<=atoi(Menu5[0]);i++){
					if(strcmp(Menu5[i],"linha") == 0){
						AppendMenu(opcao5, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu5[i][aux] != '-' && Menu5[i][aux] != '\0'){
							texto[aux] = Menu5[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao5, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu5[i][aux] != '\0'){
							if(Menu5[i][aux] == '-'){
								Menu5[i][aux-1] = '\0';
								while(Menu5[i][aux] != '\0'){
									image[count] = Menu5[i][aux+1];
									aux++;
									count++;
								}
								image[count] = '\0';
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao5,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				for(i=2;i<=atoi(Menu6[0]);i++){
					if(strcmp(Menu6[i],"linha") == 0){
						AppendMenu(opcao6, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu6[i][aux] != '-' && Menu6[i][aux] != '\0'){
							texto[aux] = Menu6[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao6, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu6[i][aux] != '\0'){
							if(Menu6[i][aux] == '-'){
								Menu6[i][aux-1] = '\0';
								while(Menu6[i][aux] != '\0'){
									image[count] = Menu6[i][aux+1];
									aux++;
									count++;
								}
								image[count] = '\0';
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao6,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				SetMenu(hand, menuBar);
				SetMenu(hand, opcao1);
				SetMenu(hand, opcao2);
				SetMenu(hand, opcao3);
				SetMenu(hand, opcao4);
				SetMenu(hand, opcao5);
				SetMenu(hand, opcao6);
				break;
			}
			case 7:{
				int i;
				HMENU menuBar = CreateMenu();
				HMENU opcao1 = CreateMenu();
				HMENU opcao2 = CreateMenu();
				HMENU opcao3 = CreateMenu();
				HMENU opcao4 = CreateMenu();
				HMENU opcao5 = CreateMenu();
				HMENU opcao6 = CreateMenu();
				HMENU opcao7 = CreateMenu();
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao1, Menu1[1]);
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao2, Menu2[1]);
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao3, Menu3[1]);
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao4, Menu4[1]);
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao5, Menu5[1]);
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao6, Menu6[1]);
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao7, Menu7[1]);
				for(i=2;i<=atoi(Menu1[0]);i++){
					if(strcmp(Menu1[i],"linha") == 0){
						AppendMenu(opcao1, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu1[i][aux] != '-' && Menu1[i][aux] != '\0'){
							texto[aux] = Menu1[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao1, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu1[i][aux] != '\0'){
							if(Menu1[i][aux] == '-'){
								Menu1[i][aux-1] = '\0';
								while(Menu1[i][aux] != '\0'){
									image[count] = Menu1[i][aux+1];
									aux++;
									count++;
								}
								image[count] = '\0';
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao1,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				for(i=2;i<=atoi(Menu2[0]);i++){
					if(strcmp(Menu2[i],"linha") == 0){
						AppendMenu(opcao2, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu2[i][aux] != '-' && Menu2[i][aux] != '\0'){
							texto[aux] = Menu2[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao2, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu2[i][aux] != '\0'){
							if(Menu2[i][aux] == '-'){
								Menu2[i][aux-1] = '\0';
								while(Menu2[i][aux] != '\0'){
									image[count] = Menu2[i][aux+1];
									aux++;
									count++;
								}
								image[count] = '\0';
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao2,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				for(i=2;i<=atoi(Menu3[0]);i++){
					if(strcmp(Menu3[i],"linha") == 0){
						AppendMenu(opcao3, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu3[i][aux] != '-' && Menu3[i][aux] != '\0'){
							texto[aux] = Menu3[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao3, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu3[i][aux] != '\0'){
							if(Menu3[i][aux] == '-'){
								Menu3[i][aux-1] = '\0';
								while(Menu3[i][aux] != '\0'){
									image[count] = Menu3[i][aux+1];
									aux++;
									count++;
								}
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao3,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				for(i=2;i<=atoi(Menu4[0]);i++){
					if(strcmp(Menu4[i],"linha") == 0){
						AppendMenu(opcao4, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu4[i][aux] != '-' && Menu4[i][aux] != '\0'){
							texto[aux] = Menu4[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao4, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu4[i][aux] != '\0'){
							if(Menu4[i][aux] == '-'){
								Menu4[i][aux-1] = '\0';
								while(Menu4[i][aux] != '\0'){
									image[count] = Menu4[i][aux+1];
									aux++;
									count++;
								}
								image[count] = '\0';
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao4,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				for(i=2;i<=atoi(Menu5[0]);i++){
					if(strcmp(Menu5[i],"linha") == 0){
						AppendMenu(opcao5, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu5[i][aux] != '-' && Menu5[i][aux] != '\0'){
							texto[aux] = Menu5[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao5, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu5[i][aux] != '\0'){
							if(Menu5[i][aux] == '-'){
								Menu5[i][aux-1] = '\0';
								while(Menu5[i][aux] != '\0'){
									image[count] = Menu5[i][aux+1];
									aux++;
									count++;
								}
								image[count] = '\0';
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao5,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				for(i=2;i<=atoi(Menu6[0]);i++){
					if(strcmp(Menu6[i],"linha") == 0){
						AppendMenu(opcao6, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu6[i][aux] != '-' && Menu6[i][aux] != '\0'){
							texto[aux] = Menu6[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao6, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu6[i][aux] != '\0'){
							if(Menu6[i][aux] == '-'){
								Menu6[i][aux-1] = '\0';
								while(Menu6[i][aux] != '\0'){
									image[count] = Menu6[i][aux+1];
									aux++;
									count++;
								}
								image[count] = '\0';
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao6,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				for(i=2;i<=atoi(Menu7[0]);i++){
					if(strcmp(Menu7[i],"linha") == 0){
						AppendMenu(opcao7, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu7[i][aux] != '-' && Menu7[i][aux] != '\0'){
							texto[aux] = Menu7[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao7, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu7[i][aux] != '\0'){
							if(Menu7[i][aux] == '-'){
								Menu7[i][aux-1] = '\0';
								while(Menu7[i][aux] != '\0'){
									image[count] = Menu7[i][aux+1];
									aux++;
									count++;
								}
								image[count] = '\0';
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao7,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				SetMenu(hand, menuBar);
				SetMenu(hand, opcao1);
				SetMenu(hand, opcao2);
				SetMenu(hand, opcao3);
				SetMenu(hand, opcao4);
				SetMenu(hand, opcao5);
				SetMenu(hand, opcao6);
				SetMenu(hand, opcao7);
				break;
			}
			case 8:{
				int i;
				HMENU menuBar = CreateMenu();
				HMENU opcao1 = CreateMenu();
				HMENU opcao2 = CreateMenu();
				HMENU opcao3 = CreateMenu();
				HMENU opcao4 = CreateMenu();
				HMENU opcao5 = CreateMenu();
				HMENU opcao6 = CreateMenu();
				HMENU opcao7 = CreateMenu();
				HMENU opcao8 = CreateMenu();
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao1, Menu1[1]);
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao2, Menu2[1]);
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao3, Menu3[1]);
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao4, Menu4[1]);
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao5, Menu5[1]);
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao6, Menu6[1]);
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao7, Menu7[1]);
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao8, Menu8[1]);
				for(i=2;i<=atoi(Menu1[0]);i++){
					if(strcmp(Menu1[i],"linha") == 0){
						AppendMenu(opcao1, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu1[i][aux] != '-' && Menu1[i][aux] != '\0'){
							texto[aux] = Menu1[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao1, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu1[i][aux] != '\0'){
							if(Menu1[i][aux] == '-'){
								Menu1[i][aux-1] = '\0';
								while(Menu1[i][aux] != '\0'){
									image[count] = Menu1[i][aux+1];
									aux++;
									count++;
								}
								image[count] = '\0';
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao1,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				for(i=2;i<=atoi(Menu2[0]);i++){
					if(strcmp(Menu2[i],"linha") == 0){
						AppendMenu(opcao2, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu2[i][aux] != '-' && Menu2[i][aux] != '\0'){
							texto[aux] = Menu2[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao2, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu2[i][aux] != '\0'){
							if(Menu2[i][aux] == '-'){
								Menu2[i][aux-1] = '\0';
								while(Menu2[i][aux] != '\0'){
									image[count] = Menu2[i][aux+1];
									aux++;
									count++;
								}
								image[count] = '\0';
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao2,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				for(i=2;i<=atoi(Menu3[0]);i++){
					if(strcmp(Menu3[i],"linha") == 0){
						AppendMenu(opcao3, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu3[i][aux] != '-' && Menu3[i][aux] != '\0'){
							texto[aux] = Menu3[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao3, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu3[i][aux] != '\0'){
							if(Menu3[i][aux] == '-'){
								Menu3[i][aux-1] = '\0';
								while(Menu3[i][aux] != '\0'){
									image[count] = Menu3[i][aux+1];
									aux++;
									count++;
								}
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao3,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				for(i=2;i<=atoi(Menu4[0]);i++){
					if(strcmp(Menu4[i],"linha") == 0){
						AppendMenu(opcao4, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu4[i][aux] != '-' && Menu4[i][aux] != '\0'){
							texto[aux] = Menu4[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao4, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu4[i][aux] != '\0'){
							if(Menu4[i][aux] == '-'){
								Menu4[i][aux-1] = '\0';
								while(Menu4[i][aux] != '\0'){
									image[count] = Menu4[i][aux+1];
									aux++;
									count++;
								}
								image[count] = '\0';
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao4,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				for(i=2;i<=atoi(Menu5[0]);i++){
					if(strcmp(Menu5[i],"linha") == 0){
						AppendMenu(opcao5, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu5[i][aux] != '-' && Menu5[i][aux] != '\0'){
							texto[aux] = Menu5[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao5, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu5[i][aux] != '\0'){
							if(Menu5[i][aux] == '-'){
								Menu5[i][aux-1] = '\0';
								while(Menu5[i][aux] != '\0'){
									image[count] = Menu5[i][aux+1];
									aux++;
									count++;
								}
								image[count] = '\0';
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao5,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				for(i=2;i<=atoi(Menu6[0]);i++){
					if(strcmp(Menu6[i],"linha") == 0){
						AppendMenu(opcao6, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu6[i][aux] != '-' && Menu6[i][aux] != '\0'){
							texto[aux] = Menu6[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao6, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu6[i][aux] != '\0'){
							if(Menu6[i][aux] == '-'){
								Menu6[i][aux-1] = '\0';
								while(Menu6[i][aux] != '\0'){
									image[count] = Menu6[i][aux+1];
									aux++;
									count++;
								}
								image[count] = '\0';
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao6,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				for(i=2;i<=atoi(Menu7[0]);i++){
					if(strcmp(Menu7[i],"linha") == 0){
						AppendMenu(opcao7, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu7[i][aux] != '-' && Menu7[i][aux] != '\0'){
							texto[aux] = Menu7[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao7, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu7[i][aux] != '\0'){
							if(Menu7[i][aux] == '-'){
								Menu7[i][aux-1] = '\0';
								while(Menu7[i][aux] != '\0'){
									image[count] = Menu7[i][aux+1];
									aux++;
									count++;
								}
								image[count] = '\0';
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao7,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				for(i=2;i<=atoi(Menu8[0]);i++){
					if(strcmp(Menu8[i],"linha") == 0){
						AppendMenu(opcao8, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu8[i][aux] != '-' && Menu8[i][aux] != '\0'){
							texto[aux] = Menu8[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao8, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu8[i][aux] != '\0'){
							if(Menu8[i][aux] == '-'){
								Menu8[i][aux-1] = '\0';
								while(Menu8[i][aux] != '\0'){
									image[count] = Menu8[i][aux+1];
									aux++;
									count++;
								}
								image[count] = '\0';
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao8,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				SetMenu(hand, menuBar);
				SetMenu(hand, opcao1);
				SetMenu(hand, opcao2);
				SetMenu(hand, opcao3);
				SetMenu(hand, opcao4);
				SetMenu(hand, opcao5);
				SetMenu(hand, opcao6);
				SetMenu(hand, opcao7);
				SetMenu(hand, opcao8);
				break;
			}
			case 9:{
				int i;
				HMENU menuBar = CreateMenu();
				HMENU opcao1 = CreateMenu();
				HMENU opcao2 = CreateMenu();
				HMENU opcao3 = CreateMenu();
				HMENU opcao4 = CreateMenu();
				HMENU opcao5 = CreateMenu();
				HMENU opcao6 = CreateMenu();
				HMENU opcao7 = CreateMenu();
				HMENU opcao8 = CreateMenu();
				HMENU opcao9 = CreateMenu();
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao1, Menu1[1]);
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao2, Menu2[1]);
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao3, Menu3[1]);
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao4, Menu4[1]);
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao5, Menu5[1]);
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao6, Menu6[1]);
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao7, Menu7[1]);
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao8, Menu8[1]);
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao9, Menu9[1]);
				for(i=2;i<=atoi(Menu1[0]);i++){
					if(strcmp(Menu1[i],"linha") == 0){
						AppendMenu(opcao1, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu1[i][aux] != '-' && Menu1[i][aux] != '\0'){
							texto[aux] = Menu1[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao1, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu1[i][aux] != '\0'){
							if(Menu1[i][aux] == '-'){
								Menu1[i][aux-1] = '\0';
								while(Menu1[i][aux] != '\0'){
									image[count] = Menu1[i][aux+1];
									aux++;
									count++;
								}
								image[count] = '\0';
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao1,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				for(i=2;i<=atoi(Menu2[0]);i++){
					if(strcmp(Menu2[i],"linha") == 0){
						AppendMenu(opcao2, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu2[i][aux] != '-' && Menu2[i][aux] != '\0'){
							texto[aux] = Menu2[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao2, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu2[i][aux] != '\0'){
							if(Menu2[i][aux] == '-'){
								Menu2[i][aux-1] = '\0';
								while(Menu2[i][aux] != '\0'){
									image[count] = Menu2[i][aux+1];
									aux++;
									count++;
								}
								image[count] = '\0';
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao2,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				for(i=2;i<=atoi(Menu3[0]);i++){
					if(strcmp(Menu3[i],"linha") == 0){
						AppendMenu(opcao3, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu3[i][aux] != '-' && Menu3[i][aux] != '\0'){
							texto[aux] = Menu3[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao3, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu3[i][aux] != '\0'){
							if(Menu3[i][aux] == '-'){
								Menu3[i][aux-1] = '\0';
								while(Menu3[i][aux] != '\0'){
									image[count] = Menu3[i][aux+1];
									aux++;
									count++;
								}
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao3,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				for(i=2;i<=atoi(Menu4[0]);i++){
					if(strcmp(Menu4[i],"linha") == 0){
						AppendMenu(opcao4, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu4[i][aux] != '-' && Menu4[i][aux] != '\0'){
							texto[aux] = Menu4[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao4, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu4[i][aux] != '\0'){
							if(Menu4[i][aux] == '-'){
								Menu4[i][aux-1] = '\0';
								while(Menu4[i][aux] != '\0'){
									image[count] = Menu4[i][aux+1];
									aux++;
									count++;
								}
								image[count] = '\0';
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao4,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				for(i=2;i<=atoi(Menu5[0]);i++){
					if(strcmp(Menu5[i],"linha") == 0){
						AppendMenu(opcao5, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu5[i][aux] != '-' && Menu5[i][aux] != '\0'){
							texto[aux] = Menu5[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao5, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu5[i][aux] != '\0'){
							if(Menu5[i][aux] == '-'){
								Menu5[i][aux-1] = '\0';
								while(Menu5[i][aux] != '\0'){
									image[count] = Menu5[i][aux+1];
									aux++;
									count++;
								}
								image[count] = '\0';
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao5,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				for(i=2;i<=atoi(Menu6[0]);i++){
					if(strcmp(Menu6[i],"linha") == 0){
						AppendMenu(opcao6, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu6[i][aux] != '-' && Menu6[i][aux] != '\0'){
							texto[aux] = Menu6[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao6, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu6[i][aux] != '\0'){
							if(Menu6[i][aux] == '-'){
								Menu6[i][aux-1] = '\0';
								while(Menu6[i][aux] != '\0'){
									image[count] = Menu6[i][aux+1];
									aux++;
									count++;
								}
								image[count] = '\0';
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao6,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				for(i=2;i<=atoi(Menu7[0]);i++){
					if(strcmp(Menu7[i],"linha") == 0){
						AppendMenu(opcao7, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu7[i][aux] != '-' && Menu7[i][aux] != '\0'){
							texto[aux] = Menu7[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao7, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu7[i][aux] != '\0'){
							if(Menu7[i][aux] == '-'){
								Menu7[i][aux-1] = '\0';
								while(Menu7[i][aux] != '\0'){
									image[count] = Menu7[i][aux+1];
									aux++;
									count++;
								}
								image[count] = '\0';
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao7,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				for(i=2;i<=atoi(Menu8[0]);i++){
					if(strcmp(Menu8[i],"linha") == 0){
						AppendMenu(opcao8, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu8[i][aux] != '-' && Menu8[i][aux] != '\0'){
							texto[aux] = Menu8[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao8, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu8[i][aux] != '\0'){
							if(Menu8[i][aux] == '-'){
								Menu8[i][aux-1] = '\0';
								while(Menu8[i][aux] != '\0'){
									image[count] = Menu8[i][aux+1];
									aux++;
									count++;
								}
								image[count] = '\0';
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao8,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				for(i=2;i<=atoi(Menu9[0]);i++){
					if(strcmp(Menu9[i],"linha") == 0){
						AppendMenu(opcao9, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu9[i][aux] != '-' && Menu9[i][aux] != '\0'){
							texto[aux] = Menu9[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao9, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu9[i][aux] != '\0'){
							if(Menu9[i][aux] == '-'){
								Menu9[i][aux-1] = '\0';
								while(Menu9[i][aux] != '\0'){
									image[count] = Menu9[i][aux+1];
									aux++;
									count++;
								}
								image[count] = '\0';
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao9,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				SetMenu(hand, menuBar);
				SetMenu(hand, opcao1);
				SetMenu(hand, opcao2);
				SetMenu(hand, opcao3);
				SetMenu(hand, opcao4);
				SetMenu(hand, opcao5);
				SetMenu(hand, opcao6);
				SetMenu(hand, opcao7);
				SetMenu(hand, opcao8);
				SetMenu(hand, opcao9);
				break;
			}
			case 10:{
				int i;
				HMENU menuBar = CreateMenu();
				HMENU opcao1 = CreateMenu();
				HMENU opcao2 = CreateMenu();
				HMENU opcao3 = CreateMenu();
				HMENU opcao4 = CreateMenu();
				HMENU opcao5 = CreateMenu();
				HMENU opcao6 = CreateMenu();
				HMENU opcao7 = CreateMenu();
				HMENU opcao8 = CreateMenu();
				HMENU opcao9 = CreateMenu();
				HMENU opcao10 = CreateMenu();
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao1, Menu1[1]);
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao2, Menu2[1]);
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao3, Menu3[1]);
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao4, Menu4[1]);
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao5, Menu5[1]);
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao6, Menu6[1]);
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao7, Menu7[1]);
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao8, Menu8[1]);
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao9, Menu9[1]);
				AppendMenu(menuBar, MF_POPUP, (UINT_PTR) opcao10, Menu10[1]);
				for(i=2;i<=atoi(Menu1[0]);i++){
					if(strcmp(Menu1[i],"linha") == 0){
						AppendMenu(opcao1, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu1[i][aux] != '-' && Menu1[i][aux] != '\0'){
							texto[aux] = Menu1[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao1, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu1[i][aux] != '\0'){
							if(Menu1[i][aux] == '-'){
								Menu1[i][aux-1] = '\0';
								while(Menu1[i][aux] != '\0'){
									image[count] = Menu1[i][aux+1];
									aux++;
									count++;
								}
								image[count] = '\0';
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao1,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				for(i=2;i<=atoi(Menu2[0]);i++){
					if(strcmp(Menu2[i],"linha") == 0){
						AppendMenu(opcao2, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu2[i][aux] != '-' && Menu2[i][aux] != '\0'){
							texto[aux] = Menu2[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao2, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu2[i][aux] != '\0'){
							if(Menu2[i][aux] == '-'){
								Menu2[i][aux-1] = '\0';
								while(Menu2[i][aux] != '\0'){
									image[count] = Menu2[i][aux+1];
									aux++;
									count++;
								}
								image[count] = '\0';
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao2,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				for(i=2;i<=atoi(Menu3[0]);i++){
					if(strcmp(Menu3[i],"linha") == 0){
						AppendMenu(opcao3, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu3[i][aux] != '-' && Menu3[i][aux] != '\0'){
							texto[aux] = Menu3[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao3, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu3[i][aux] != '\0'){
							if(Menu3[i][aux] == '-'){
								Menu3[i][aux-1] = '\0';
								while(Menu3[i][aux] != '\0'){
									image[count] = Menu3[i][aux+1];
									aux++;
									count++;
								}
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao3,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				for(i=2;i<=atoi(Menu4[0]);i++){
					if(strcmp(Menu4[i],"linha") == 0){
						AppendMenu(opcao4, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu4[i][aux] != '-' && Menu4[i][aux] != '\0'){
							texto[aux] = Menu4[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao4, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu4[i][aux] != '\0'){
							if(Menu4[i][aux] == '-'){
								Menu4[i][aux-1] = '\0';
								while(Menu4[i][aux] != '\0'){
									image[count] = Menu4[i][aux+1];
									aux++;
									count++;
								}
								image[count] = '\0';
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao4,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				for(i=2;i<=atoi(Menu5[0]);i++){
					if(strcmp(Menu5[i],"linha") == 0){
						AppendMenu(opcao5, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu5[i][aux] != '-' && Menu5[i][aux] != '\0'){
							texto[aux] = Menu5[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao5, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu5[i][aux] != '\0'){
							if(Menu5[i][aux] == '-'){
								Menu5[i][aux-1] = '\0';
								while(Menu5[i][aux] != '\0'){
									image[count] = Menu5[i][aux+1];
									aux++;
									count++;
								}
								image[count] = '\0';
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao5,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				for(i=2;i<=atoi(Menu6[0]);i++){
					if(strcmp(Menu6[i],"linha") == 0){
						AppendMenu(opcao6, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu6[i][aux] != '-' && Menu6[i][aux] != '\0'){
							texto[aux] = Menu6[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao6, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu6[i][aux] != '\0'){
							if(Menu6[i][aux] == '-'){
								Menu6[i][aux-1] = '\0';
								while(Menu6[i][aux] != '\0'){
									image[count] = Menu6[i][aux+1];
									aux++;
									count++;
								}
								image[count] = '\0';
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao6,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				for(i=2;i<=atoi(Menu7[0]);i++){
					if(strcmp(Menu7[i],"linha") == 0){
						AppendMenu(opcao7, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu7[i][aux] != '-' && Menu7[i][aux] != '\0'){
							texto[aux] = Menu7[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao7, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu7[i][aux] != '\0'){
							if(Menu7[i][aux] == '-'){
								Menu7[i][aux-1] = '\0';
								while(Menu7[i][aux] != '\0'){
									image[count] = Menu7[i][aux+1];
									aux++;
									count++;
								}
								image[count] = '\0';
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao7,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				for(i=2;i<=atoi(Menu8[0]);i++){
					if(strcmp(Menu8[i],"linha") == 0){
						AppendMenu(opcao8, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu8[i][aux] != '-' && Menu8[i][aux] != '\0'){
							texto[aux] = Menu8[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao8, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu8[i][aux] != '\0'){
							if(Menu8[i][aux] == '-'){
								Menu8[i][aux-1] = '\0';
								while(Menu8[i][aux] != '\0'){
									image[count] = Menu8[i][aux+1];
									aux++;
									count++;
								}
								image[count] = '\0';
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao8,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				for(i=2;i<=atoi(Menu9[0]);i++){
					if(strcmp(Menu9[i],"linha") == 0){
						AppendMenu(opcao9, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu9[i][aux] != '-' && Menu9[i][aux] != '\0'){
							texto[aux] = Menu9[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao9, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu9[i][aux] != '\0'){
							if(Menu9[i][aux] == '-'){
								Menu9[i][aux-1] = '\0';
								while(Menu9[i][aux] != '\0'){
									image[count] = Menu9[i][aux+1];
									aux++;
									count++;
								}
								image[count] = '\0';
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao9,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				for(i=2;i<=atoi(Menu10[0]);i++){
					if(strcmp(Menu10[i],"linha") == 0){
						AppendMenu(opcao10, MF_SEPARATOR, (UINT_PTR) NULL, NULL);
					}else{
						int aux=0,count=0;
						char image[50]="",texto[100];
						while(Menu10[i][aux] != '-' && Menu10[i][aux] != '\0'){
							texto[aux] = Menu10[i][aux];
							aux++;
						}
						texto[aux] = '\0';
						AppendMenu(opcao10, MF_STRING, (UINT_PTR) btnAction, texto);
						aux=count=0;
						while(Menu10[i][aux] != '\0'){
							if(Menu10[i][aux] == '-'){
								Menu10[i][aux-1] = '\0';
								while(Menu10[i][aux] != '\0'){
									image[count] = Menu10[i][aux+1];
									aux++;
									count++;
								}
								image[count] = '\0';
								char teste[100] = "imagem/";
								strcat(teste,image);
								HBITMAP fotinha = (HBITMAP) LoadImage(NULL,teste,IMAGE_BITMAP,15,15,LR_LOADFROMFILE);
								SetMenuItemBitmaps(opcao10,(UINT_PTR) btnAction,MF_BYCOMMAND,fotinha,fotinha);
							}
							aux++;
						}
						btnAction++;
					}
				}
				SetMenu(hand, menuBar);
				SetMenu(hand, opcao1);
				SetMenu(hand, opcao2);
				SetMenu(hand, opcao3);
				SetMenu(hand, opcao4);
				SetMenu(hand, opcao5);
				SetMenu(hand, opcao6);
				SetMenu(hand, opcao7);
				SetMenu(hand, opcao8);
				SetMenu(hand, opcao9);
				SetMenu(hand, opcao10);
				break;
			}	
		}
	}
	
	void CBotao(int id, const char *title, float pos_x, float pos_y, float comprimento, float altura){
		if(hcomp[Construtora][id] == NULL && id < 400){
			hcomp[Construtora][id] = CreateWindowEx(0,WC_BUTTON,title,WS_CHILD|WS_VISIBLE,pos_x,pos_y,comprimento,altura,hand, (HMENU)(intptr_t) id,icomp[Construtora][id],NULL);
			ncomp++;
		}else if(id >= 400){
			MessageBox(NULL,"O ID deve ser menor de 400.","ID incorreto",MB_OK);
		}else{
			MessageBox(NULL,"Já existe um componente com esse ID.","ID existente",MB_OK);
		}
	}
	
	void CBotaoImagem(int id, const char *ImagemIcon, int IComp, int IAlt, float pos_x, float pos_y, float comprimento, float altura){
		if(hcomp[Construtora][id] == NULL && id < 400){
			char texto[255] = "imagem/";
			strcat(texto,ImagemIcon);
			hcomp[Construtora][id] = CreateWindowEx(0,WC_BUTTON,NULL,WS_CHILD|WS_VISIBLE|BS_ICON,pos_x,pos_y,comprimento,altura,hand, (HMENU)(intptr_t) id,icomp[Construtora][id],NULL);
			HBITMAP image = (HBITMAP) LoadImage(NULL,texto,IMAGE_ICON,IComp,IAlt,LR_LOADFROMFILE);
			SendMessage(hcomp[Construtora][id],BM_SETIMAGE,IMAGE_ICON,(LPARAM) image);
			ncomp++;
		}else if(id >= 400){
			MessageBox(NULL,"O ID deve ser menor de 400.","ID incorreto",MB_OK);
		}else{
			MessageBox(NULL,"Já existe um componente com esse ID.","ID existente",MB_OK);
		}
	}

	void CTexto(int id, const char *title, float pos_x, float pos_y, float comprimento, float altura){
		if(hcomp[Construtora][id] == NULL && id < 400){
			hcomp[Construtora][id] = CreateWindowEx(0,WC_STATIC, title, WS_CHILD|WS_VISIBLE, pos_x, pos_y, comprimento, altura, hand, (HMENU)(intptr_t) id, icomp[Construtora][id],NULL);
			ncomp++;
		}else if(id >= 400){
			MessageBox(NULL,"O ID deve ser menor de 400.","ID incorreto",MB_OK);
		}else{
			MessageBox(NULL,"Já existe um componente com esse ID.","ID existente",MB_OK);
		}
	}
	
	void CTextoC(int id, const char *title, float pos_x, float pos_y, float comprimento, float altura){
		if(hcomp[Construtora][id] == NULL && id < 400){
			hcomp[Construtora][id] = CreateWindowEx(0,WC_STATIC, title, WS_CHILD|WS_VISIBLE|ES_CENTER, pos_x, pos_y, comprimento, altura, hand, (HMENU)(intptr_t) id, icomp[Construtora][id],NULL);
			ncomp++;
		}else if(id >= 400){
			MessageBox(NULL,"O ID deve ser menor de 400.","ID incorreto",MB_OK);
		}else{
			MessageBox(NULL,"Já existe um componente com esse ID.","ID existente",MB_OK);
		}
	}
	
	void CCaixaDeTexto(int id, float pos_x, float pos_y, float comprimento, float altura){
		if(hcomp[Construtora][id] == NULL && id < 400){
			hcomp[Construtora][id] = CreateWindow(WC_EDIT, NULL, WS_CHILD|WS_VISIBLE, pos_x, pos_y, comprimento, altura, hand, NULL, NULL,NULL);
			ncomp++;
		}else if(id >= 400){
			MessageBox(NULL,"O ID deve ser menor de 400.","ID incorreto",MB_OK);
		}else{
			MessageBox(NULL,"Já existe um componente com esse ID.","ID existente",MB_OK);
		}
	}
	void CCaixaDeTextoB(int id, float pos_x, float pos_y, float comprimento, float altura){
		if(hcomp[Construtora][id] == NULL && id < 400){
			hcomp[Construtora][id] = CreateWindow(WC_EDIT, NULL, WS_CHILD|WS_VISIBLE|WS_BORDER, pos_x, pos_y, comprimento, altura, hand, NULL, NULL,NULL);
			ncomp++;
		}else if(id >= 400){
			MessageBox(NULL,"O ID deve ser menor de 400.","ID incorreto",MB_OK);
		}else{
			MessageBox(NULL,"Já existe um componente com esse ID.","ID existente",MB_OK);
		}
	}
	void CCheckBox(int id, const char *title, float pos_x, float pos_y, float comprimento, float altura){
		if(hcomp[Construtora][id] == NULL && id < 400){
			hcomp[Construtora][id] = CreateWindow(WC_BUTTON, title, WS_CHILD|WS_VISIBLE|BS_CHECKBOX ,pos_x, pos_y, comprimento, altura, hand, (HMENU)(intptr_t) id, icomp[Construtora][id],NULL);
			ncomp++;
		}else if(id >= 400){
			MessageBox(NULL,"O ID deve ser menor de 400.","ID incorreto",MB_OK);
		}else{
			MessageBox(NULL,"Já existe um componente com esse ID.","ID existente",MB_OK);
		}
	}
	
	
	void CGroupBox(float pos_x, float pos_y, float comprimento, float altura){
		CreateWindow(WC_STATIC, NULL, WS_CHILD|WS_VISIBLE|BS_GROUPBOX, pos_x, pos_y, comprimento, altura, hand, NULL, NULL,NULL);
	}
	
	//Cria o grupo de radios que virão depois dele ser instanciado
	void CGrupoRadio(int id, const char *title, float pos_x, float pos_y, float comprimento, float altura){
		if(hcomp[Construtora][id] == NULL && id < 400){
			hcomp[Construtora][id] = CreateWindow(WC_BUTTON, title, WS_CHILD|WS_VISIBLE|BS_AUTORADIOBUTTON|WS_GROUP, pos_x, pos_y, comprimento, altura, hand, (HMENU)(intptr_t) id, icomp[Construtora][id],NULL);
			ncomp++;
		}else if(id >= 400){
			MessageBox(NULL,"O ID deve ser menor de 400.","ID incorreto",MB_OK);
		}else{
			MessageBox(NULL,"Já existe um componente com esse ID.","ID existente",MB_OK);
		}
	}
	
	//Radio box que virão depois do Grupo ser definido pela função acima
	void CRadioButton(int id, const char *title, float pos_x, float pos_y, float comprimento, float altura){
		if(hcomp[Construtora][id] == NULL && id < 400){
			hcomp[Construtora][id] = CreateWindow(WC_BUTTON, title, WS_CHILD|WS_VISIBLE|BS_AUTORADIOBUTTON, pos_x, pos_y, comprimento, altura, hand, (HMENU)(intptr_t) id, icomp[Construtora][id],NULL);
			ncomp++;
		}else if(id >= 400){
			MessageBox(NULL,"O ID deve ser menor de 400.","ID incorreto",MB_OK);
		}else{
			MessageBox(NULL,"Já existe um componente com esse ID.","ID existente",MB_OK);
		}
	}
	
	//Cria uma area de edição de texto 
	void CTextArea(int id, float pos_x, float pos_y, float comprimento, float altura){
		if(hcomp[Construtora][id] == NULL && id < 400){
			LoadLibrary("DLL/msftedit.dll"); //Carrega a dll para usar o edit text
			hcomp[Construtora][id] = CreateWindowEx(0,"RICHEDIT50W","",WS_CHILD|WS_BORDER|WS_VISIBLE|ES_MULTILINE|WS_VSCROLL|WS_HSCROLL,pos_x, pos_y, comprimento, altura,hand,0,NULL,NULL);
			ncomp++;
		}else if(id >= 400){
			MessageBox(NULL,"O ID deve ser menor de 400.","ID incorreto",MB_OK);
		}else{
			MessageBox(NULL,"Já existe um componente com esse ID.","ID existente",MB_OK);
		}
	}
	
	//Cria um campo de senha
	void CPasswordBox(int id, float pos_x, float pos_y, float comprimento, float altura){
		if(hcomp[Construtora][id] == NULL && id < 400){
			hcomp[Construtora][id] = CreateWindow(WC_EDIT, NULL, WS_CHILD|WS_VISIBLE|ES_PASSWORD, pos_x, pos_y, comprimento, altura, hand, NULL, NULL,NULL);
			ncomp++;
		}else if(id >= 400){
			MessageBox(NULL,"O ID deve ser menor de 400.","ID incorreto",MB_OK);
		}else{
			MessageBox(NULL,"Já existe um componente com esse ID.","ID existente",MB_OK);
		}
	}
	
	//Cria um campo de texto com borda
	void CPasswordBoxB(int id, float pos_x, float pos_y, float comprimento, float altura){
		if(hcomp[Construtora][id] == NULL && id < 400){
			hcomp[Construtora][id] = CreateWindow(WC_EDIT, NULL, WS_CHILD|WS_VISIBLE|ES_PASSWORD|WS_BORDER, pos_x, pos_y, comprimento, altura, hand, NULL, NULL,NULL);
			ncomp++;
		}else if(id >= 400){
			MessageBox(NULL,"O ID deve ser menor de 400.","ID incorreto",MB_OK);
		}else{
			MessageBox(NULL,"Já existe um componente com esse ID.","ID existente",MB_OK);
		}
	}
	
	//Cria um campo de entrada que só aceita numeros
	void CNumero(int id, float pos_x, float pos_y, float comprimento, float altura){ 
		if(hcomp[Construtora][id] == NULL && id < 400){
			hcomp[Construtora][id] = CreateWindow(WC_EDIT, NULL, WS_CHILD|WS_VISIBLE|ES_NUMBER|WS_BORDER, pos_x, pos_y, comprimento, altura, hand, NULL, NULL,NULL);
			ncomp++;
		}else if(id >= 400){
			MessageBox(NULL,"O ID deve ser menor de 400.","ID incorreto",MB_OK);
		}else{
			MessageBox(NULL,"Já existe um componente com esse ID.","ID existente",MB_OK);
		}
	}
	
	//Cria um comboBox/Lista suspensa tipo lista.
	void CLSuspensa(int id, int amostra, char itens[][100], float pos_x, float pos_y, float comprimento, float altura){ 
		if(hcomp[Construtora][id] == NULL && id < 400){
			int i;
			hcomp[Construtora][id] = CreateWindow(WC_COMBOBOX, NULL, WS_CHILD|WS_VISIBLE|CBS_DROPDOWN|CBS_HASSTRINGS|WS_VSCROLL, pos_x, pos_y, comprimento, altura, hand, NULL, NULL,NULL);
			for(i=1;i<atoi(itens[0]);i++)
				SendMessage(hcomp[Construtora][id],CB_ADDSTRING,(WPARAM)NULL,(LPARAM)itens[i]);
			SendMessage(hcomp[Construtora][id],CB_SETCURSEL,(WPARAM)amostra-1,(LPARAM)0);
			ncomp++;
		}else if(id >= 400){
			MessageBox(NULL,"O ID deve ser menor de 400.","ID incorreto",MB_OK);
		}else{
			MessageBox(NULL,"Já existe um componente com esse ID.","ID existente",MB_OK);
		}
	}
	
	//Componente Slider que ao deslizar vai modificando o valor.
	void CSlider(int id, int vMin, int vMax, float pos_x, float pos_y, float comprimento, float altura){
		if(hcomp[Construtora][id] == NULL && id < 400){
			hcomp[Construtora][id] = CreateWindowEx(0,TRACKBAR_CLASS, NULL, WS_CHILD|WS_VISIBLE|TBS_AUTOTICKS|TBS_ENABLESELRANGE|TBS_NOTICKS, pos_x, pos_y, comprimento, altura, hand, (HMENU)(intptr_t) id, icomp[Construtora][id],NULL);
			SendMessage(hcomp[Construtora][id], TBM_SETRANGE, (WPARAM) TRUE, (LPARAM) MAKELONG(vMin,vMax));
			SendMessage(hcomp[Construtora][id], TBM_SETPAGESIZE, 0, (LPARAM) 10);
			SendMessage(hcomp[Construtora][id], TBM_SETPOS, (WPARAM) TRUE, (LPARAM) (vMax/2));
			ncomp++;
		}else if(id >= 400){
			MessageBox(NULL,"O ID deve ser menor de 400.","ID incorreto",MB_OK);
		}else{
			MessageBox(NULL,"Já existe um componente com esse ID.","ID existente",MB_OK);
		}
	}
	
	//Cria uma barra de progresso
	void CBarraDeProgresso(int id, float pos_x, float pos_y, float comprimento, float altura){
		if(hcomp[Construtora][id] == NULL && id < 400){
			hcomp[Construtora][id] = CreateWindowEx(0,PROGRESS_CLASS, NULL, WS_CHILD|WS_VISIBLE|TBS_AUTOTICKS|TBS_ENABLESELRANGE|PBS_SMOOTH, pos_x, pos_y, comprimento, altura, hand, NULL, NULL,NULL);
			ncomp++;
		}else if(id >= 400){
			MessageBox(NULL,"O ID deve ser menor de 400.","ID incorreto",MB_OK);
		}else{
			MessageBox(NULL,"Já existe um componente com esse ID.","ID existente",MB_OK);
		}
	}
	
	//Adiciona uma imagem para a janela onde foi chamada a função
	void CImagem(const char *nome, int pos_x, int pos_y, int comprimento, int altura){
		char texto[255] = "imagem/";
		strcat(texto,nome);
		HINSTANCE ban;
		HWND banner = CreateWindow(WC_STATIC,NULL,WS_BORDER|SS_BITMAP|WS_CHILD|WS_VISIBLE,pos_x,pos_y,comprimento,altura,hand,NULL,ban,NULL);
		HBITMAP img2 = (HBITMAP) LoadImage(NULL,texto,IMAGE_BITMAP,comprimento,altura,LR_LOADFROMFILE);
		if(!img2)
			MessageBox(0,texto,"Erro de imagem",MB_OK|0x10);
		SendMessage((HWND) banner, (UINT) STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) img2);
		ncomp++;
	}
	
	//Cria uma lista com textos.
	void CLista(int idLista, int pos_x, int pos_y, int comprimento, int altura){
		hcomp[Construtora][idLista] = CreateWindow(WC_LISTBOX,NULL,WS_BORDER|LBS_NOTIFY|WS_CHILD|WS_VISIBLE|WS_VSCROLL|WS_HSCROLL,pos_x,pos_y,comprimento,altura,hand,(HMENU)(intptr_t) idLista,icomp[Construtora][idLista],NULL);
		ncomp++;
	}
	
	//Cria uma lista com textos em ordem alfabetica.
	void CListaO(int idLista, int pos_x, int pos_y, int comprimento, int altura){
		hcomp[Construtora][idLista] = CreateWindow(WC_LISTBOX,NULL,LBS_SORT|WS_BORDER|LBS_NOTIFY|WS_CHILD|WS_VISIBLE|WS_VSCROLL|WS_HSCROLL,pos_x,pos_y,comprimento,altura,hand,(HMENU)(intptr_t) idLista,icomp[Construtora][idLista],NULL);
		ncomp++;
	}
	
	//Uma caixa de dialogo que retorna o caminho completo do arquivo
	char * CBuscarArquivo(){
		HINSTANCE CDialog;
		char *dir = (char *) malloc(sizeof(char *));
		strcpy(dir,"\0");
		OPENFILENAMEA dlg;
		ZeroMemory(&dlg,sizeof(OPENFILENAME));
		dlg.lStructSize = sizeof(OPENFILENAMEA);
		dlg.hwndOwner = hand;
		dlg.hInstance = CDialog;
		dlg.lpstrFilter = "File Text\0*.TXT\0";
		dlg.nFilterIndex = 1;
		dlg.nMaxFile = 255;
		dlg.lpstrFile = dir;
		dlg.lpstrTitle = "Abrir";
		dlg.lpstrInitialDir = "C:\\Users\\%username%\\Documents\0";
		dlg.Flags = OFN_ALLOWMULTISELECT|OFN_EXPLORER|OFN_FILEMUSTEXIST|OFN_FORCESHOWHIDDEN|OFN_OVERWRITEPROMPT;
		GetOpenFileNameA(&dlg);
		return dir;
	}
	
	//Caixa de dialogo que retorna onde quer salvar o arquivo.
	char * CSalvarArquivo(){
		HINSTANCE CDialog;
		char *dir = (char *) malloc(sizeof(char *));
		strcpy(dir,"\0");
		OPENFILENAMEA dlg;
		ZeroMemory(&dlg,sizeof(OPENFILENAME));
		dlg.lStructSize = sizeof(OPENFILENAMEA);
		dlg.hwndOwner = hand;
		dlg.hInstance = CDialog;
		dlg.lpstrFilter = "File Text\0*.TXT\0";
		dlg.nFilterIndex = 1;
		dlg.nMaxFile = 255;
		dlg.lpstrFile = dir;
		dlg.lpstrTitle = "Salvar";
		dlg.lpstrInitialDir = "C:\\Users\\%username%\\Documents\0";
		dlg.Flags = OFN_ALLOWMULTISELECT|OFN_EXPLORER|OFN_FILEMUSTEXIST|OFN_FORCESHOWHIDDEN|OFN_OVERWRITEPROMPT;
		GetSaveFileNameA(&dlg);
		return dir;
	}
	
	//Cria um fundo com uma imagem definida pelo usuario
	void CFundoImagem(const char *nome){
		char texto[255] = "imagem/";
		strcat(texto,nome);
		RECT lol;
		GetWindowRect(hand,&lol);
		HWND banner = CreateWindow(WC_STATIC,NULL,WS_BORDER|SS_BITMAP|WS_CHILD|WS_VISIBLE,0,0,0,0,hand,NULL,NULL,NULL);
		HBITMAP img2 = (HBITMAP) LoadImage(NULL,texto,IMAGE_BITMAP,lol.right-lol.left,lol.bottom-lol.top,LR_LOADFROMFILE);
		if(!img2)
			MessageBox(0,texto,"Erro de imagem",MB_OK|0x10);
		SendMessage((HWND) banner, (UINT) STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) img2);
		ncomp++;
	}
#endif
