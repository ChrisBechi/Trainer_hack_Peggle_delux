#include <windows.h>
#include "../Componente/componentes.h"
#include "../Biblioteca/varAmbiente.h"

int idJanela;

LRESULT CALLBACK windowProc(HWND,UINT,WPARAM,LPARAM);

//	COMPONENTES PARA TELA

CJanela(char titulo[], float pos_x, float pos_y, float altura, float largura){
	HBRUSH cor = CreateSolidBrush(RGB(171,86,199));
	ShowWindow(GetConsoleWindow(),0);
	jan.cbSize = sizeof(jan);
	jan.cbClsExtra = 0;
	jan.cbWndExtra = 0;
	jan.hInstance = window;
	jan.hCursor = LoadCursor(NULL, IDC_ARROW);
	jan.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	jan.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	jan.hbrBackground = (HBRUSH) cor;
	jan.lpfnWndProc = windowProc;
	jan.lpszClassName = "janela";
	jan.lpszMenuName = NULL;
	jan.style = CS_HREDRAW|CS_VREDRAW;
	UnregisterClass("janela",window);
	if(!RegisterClassEx(&jan)){
		MessageBox(NULL,"Não foi possivel registrar a classe!","Erro",0x10);
		exit(0);
	}
	Construtora=idJanela=janelaNula();
	hcomp[idJanela][0] = CreateWindowEx(0,"janela",titulo,WS_OVERLAPPED|WS_MINIMIZEBOX|WS_SYSMENU,pos_x,pos_y,largura,altura,NULL,NULL,window,NULL);
	ShowWindow(hcomp[idJanela][0],1);
	while(GetMessage(&mensage,NULL,0,0)){
		TranslateMessage(&mensage);
		DispatchMessage(&mensage);
	}
	return mensage.wParam;
}

LRESULT CALLBACK windowProc(HWND hwnd, UINT inteiro, WPARAM wpa, LPARAM lpa){
	switch(inteiro){
		case WM_CREATE:{
			hand = hwnd;
			CComponentesGraficos();			
			break;
		}
		case WM_COMMAND:{
			Construtora=idJanela;
			CComandos(wpa);
			break;
		}
		case WM_DESTROY:{
			PostQuitMessage(0);
			break;
		}
		case WM_CTLCOLORSTATIC:{
			wpara = wpa;
			lpara = lpa;
			CEstilos(lpa);
			break;
		}
		default:{
			DefWindowProc(hwnd,inteiro,wpa,lpa);
			break;
		}
	}
}
