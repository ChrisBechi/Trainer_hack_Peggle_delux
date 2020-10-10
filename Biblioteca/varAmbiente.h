#ifndef VARAMBIENTE_H_DEFINED
#define VARAMBIENTE_H_DEFINED
#include <stdio.h>
#include "../BancoDeDados/MySql/mysql.h"
	HWND hand;
	WPARAM wpara;
	LPARAM lpara;
	HWND hcomp[100][500],mapJanelas[50];
	HINSTANCE icomp[100][500];
	MSG mensage;
	WNDCLASSEX jan;
	HINSTANCE window;
	COLORREF colr = RGB(0,255,255);
	MYSQL conn;
	int btnAction=401;
	int Construtora=0;
	int timeBarr=0,idBarra=0;
	int idSlider=0,idComp=0; 
	int janelaNula(){
		int i;
		for(i=0;hcomp[i][0]!=NULL;i++);
		return i;
	}
#endif
