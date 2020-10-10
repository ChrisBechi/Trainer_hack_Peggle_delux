#ifndef COMPONENTES_H_INCLUDED
#define COMPONENTES_H_INCLUDED
#include <windows.h>
#include "../Biblioteca/CBibliotecaDeComponentes.h"
#include "../Biblioteca/CFuncaoComponentes.h"
#include "../Biblioteca/CBancoDeDados.h"
#include <tlhelp32.h>
#include <wchar.h>

#define OFFSET 5

char proc[255];

DWORD getPID(char *Process){
   	HANDLE listProcess = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
   	PROCESSENTRY32 ps32;
   	if(listProcess){
   		ps32.dwSize = sizeof(PROCESSENTRY32);
   		do{   		
		   	if(strcmp(ps32.szExeFile,Process) == 0){
		   		break;
			}	
		}while(Process32Next(listProcess,&ps32));
	}
	return (DWORD) ps32.th32ProcessID;
}

uintptr_t getBase(DWORD pid, char *Process){
	uintptr_t num = 0;
   	HANDLE listProcess = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE,pid);
   	MODULEENTRY32 md32;
   	md32.dwSize = sizeof(MODULEENTRY32);
   	if(Module32First(listProcess, &md32)){
   		do{   	
		   	if(strcmp(md32.szModule,Process)==0){	
		   		num = (uintptr_t) md32.modBaseAddr;
		   		break;
			}
		}while(Module32Next(listProcess,&md32));
	}
	CloseHandle(listProcess);
	return num;
}

intptr_t AddressBase(HANDLE hproc, uintptr_t ptr, unsigned int offset[OFFSET]){
	int addr = ptr;
	int i;
	for( i=0; i<OFFSET;++i){	
		ReadProcessMemory(hproc, (LPVOID) addr, &addr,sizeof(addr),0);
		addr += offset[i];
	}
	return (intptr_t) addr;
}

WINAPI Refresh(){
	while(1){
		int Valor=0;
		DWORD pid = getPID(proc);
		HANDLE process = OpenProcess(PROCESS_ALL_ACCESS,FALSE,pid);
		
		intptr_t address = 0x19ff7c-0x268;
		unsigned int offset[5] = {0x164,0x1C,0x178,0x154,0x360};
		intptr_t addrFinal = AddressBase(process,address,offset);
		ReadProcessMemory(process,(LPVOID) addrFinal,&Valor,sizeof(Valor),0);
		char qtdLar[10];
		itoa(Valor,qtdLar,10);
		SetWindowText(hcomp[Construtora][9],qtdLar);
		//----------------------------------------------------------------------
		unsigned int offsetA[5] = {0x15C,0x1C,0x174,0x154,0x36C};
		addrFinal = AddressBase(process, address,offsetA);
		ReadProcessMemory(process,(LPVOID)addrFinal,&Valor,sizeof(Valor),0);
		char qtdAzul[10];
		itoa(Valor,qtdAzul,10);
		SetWindowText(hcomp[Construtora][4],qtdAzul);
		//-------------------------------------------------------------------------
		unsigned int offsetUni[5] = {0x160,0x1C,0x178,0x154,0x1DC};
		addrFinal = AddressBase(process, address,offsetUni);
		ReadProcessMemory(process,(LPVOID)addrFinal,&Valor,sizeof(Valor),0);
		char uni[10];
		itoa(Valor,uni,10);
		SetWindowText(hcomp[Construtora][12],uni);
		//---------------------------------------------------------------------------
		unsigned int offsetBall[5] = {0x16C,0x1C,0x10,0x154,0x17C};
		addrFinal = AddressBase(process, address,offsetBall);
		ReadProcessMemory(process,(LPVOID)addrFinal,&Valor,sizeof(Valor),0);
		char ball[10];
		itoa(Valor,ball,10);
		SetWindowText(hcomp[Construtora][16],ball);
		//---------------------------------------------------------------------------
		address = 0x19ff7c-0x268;
		unsigned int offsetpts[5] = {0x16C,0x10,0x88,0x154,0x174};
		addrFinal = AddressBase(process,address,offsetpts);
		ReadProcessMemory(process,(LPVOID) addrFinal,&Valor,sizeof(Valor),0);
		char pts[10];
		itoa(Valor,pts,10);
		SetWindowText(hcomp[Construtora][21],pts);
		//---------------------------------------------------------------------------
		address = 0x19ff7c-0x268;
		unsigned int offsetegi[5] = {0x16C,0x1C,0x10,0x154,0x1F4};
		addrFinal = AddressBase(process,address,offsetegi);
		ReadProcessMemory(process,(LPVOID) addrFinal,&Valor,sizeof(Valor),0);
		char egito[10];
		itoa(Valor,egito,10);
		SetWindowText(hcomp[Construtora][26],egito);
		//---------------------------------------------------------------------------
		address = 0x19ff7c-0x700;
		unsigned int offsetcar[5] = {0x88,0x16C,0x14,0x154,0x1E4};
		addrFinal = AddressBase(process,address,offsetcar);
		ReadProcessMemory(process,(LPVOID) addrFinal,&Valor,sizeof(Valor),0);
		char caran[10];
		itoa(Valor,caran,10);
		SetWindowText(hcomp[Construtora][30],caran);
		//---------------------------------------------------------------------------
		address = 0x19ff7c-0x268;
		unsigned int offsetabo[5] = {0x164,0x1C,0x178,0x154,0x204};
		addrFinal = AddressBase(process,address,offsetabo);
		ReadProcessMemory(process,(LPVOID) addrFinal,&Valor,sizeof(Valor),0);
		char abobora[10];
		itoa(Valor,abobora,10);
		SetWindowText(hcomp[Construtora][34],abobora);
		//---------------------------------------------------------------------------
		address = 0x19ff7c-0x700;
		unsigned int offsetdra[5] = {0x4,0xB8,0x200,0x154,0x234};
		addrFinal = AddressBase(process,address,offsetdra);
		ReadProcessMemory(process,(LPVOID) addrFinal,&Valor,sizeof(Valor),0);
		char dragao[10];
		itoa(Valor,dragao,10);
		SetWindowText(hcomp[Construtora][38],dragao);
		//---------------------------------------------------------------------------
		address = 0x19ff7c-0x268;
		unsigned int offsetcor[5] = {0x14C,0x8,0x1C,0x150,0x20C};
		addrFinal = AddressBase(process,address,offsetcor);
		ReadProcessMemory(process,(LPVOID) addrFinal,&Valor,sizeof(Valor),0);
		char coruja[10];
		itoa(Valor,coruja,10);
		SetWindowText(hcomp[Construtora][42],coruja);
		
		if(CObterCheck(46) == TRUE){
			intptr_t Address = 0x19ff7c-0x268;
			unsigned int offset[5] = {0x16C,0x1C,0x10,0x154,0x17C};
			intptr_t AddrFinal = AddressBase(process,Address,offset);
			int Valor = 10;
			WriteProcessMemory(process,(LPVOID) AddrFinal, &Valor, sizeof(Valor),0);
		} 
		
		if(CObterCheck(47) == TRUE){
			intptr_t Address = 0x19ff7c-0x268;
			unsigned int offset[5] = {0x160,0x1C,0x178,0x154,0x10C};
			intptr_t AddrFinal = AddressBase(process,Address,offset);
			int Valor = 10000;
			WriteProcessMemory(process,(LPVOID) AddrFinal, &Valor, sizeof(Valor),0);
		}
		
		if(CObterCheck(48) == TRUE){
			intptr_t Address = 0x19ff7c-0x268;
			unsigned int offset[5] = {0x160,0x1C,0x178,0x154,0x1DC};
			intptr_t AddrFinal = AddressBase(process,Address,offset);
			int Valor = 2;
			WriteProcessMemory(process,(LPVOID) AddrFinal, &Valor, sizeof(Valor),0);
		}
		
		if(CObterCheck(49) == TRUE){
			intptr_t Address = 0x19ff7c-0x268;
			unsigned int offset[5] = {0x16C,0x1C,0x10,0x154,0x1F4};
			intptr_t AddrFinal = AddressBase(process,Address,offset);
			int Valor = 2;
			WriteProcessMemory(process,(LPVOID) AddrFinal, &Valor, sizeof(Valor),0);
		}
		
		if(CObterCheck(50) == TRUE){
			intptr_t Address = 0x19ff7c-0x700;
			unsigned int offset[5] = {0x88,0x16C,0x14,0x154,0x1E4};
			intptr_t AddrFinal = AddressBase(process,Address,offset);
			int Valor = 2;
			WriteProcessMemory(process,(LPVOID) AddrFinal, &Valor, sizeof(Valor),0);
		}
		
		if(CObterCheck(51) == TRUE){
			intptr_t Address = 0x19ff7c-0x268;
			unsigned int offset[5] = {0x164,0x1C,0x178,0x154,0x204};
			intptr_t AddrFinal = AddressBase(process,Address,offset);
			int Valor = 2;
			WriteProcessMemory(process,(LPVOID) AddrFinal, &Valor, sizeof(Valor),0);
		}
		
		if(CObterCheck(52) == TRUE){
			intptr_t Address = 0x19ff7c-0x700 ;
			unsigned int offset[5] = {0x4,0xB8,0x200,0x154,0x234};
			intptr_t AddrFinal = AddressBase(process,Address,offset);
			int Valor = 2;
			WriteProcessMemory(process,(LPVOID) AddrFinal, &Valor, sizeof(Valor),0);
		}
		
		if(CObterCheck(53) == TRUE){
			intptr_t Address = 0x19ff7c-0x268;
			unsigned int offset[5] = {0x14C,0x8,0x1C,0x150,0x20C};
			intptr_t AddrFinal = AddressBase(process,Address,offset);
			int Valor = 2;
			WriteProcessMemory(process,(LPVOID) AddrFinal, &Valor, sizeof(Valor),0);
		}
		strcpy(proc,CObterTexto(55));	
		CloseHandle(process);
		Sleep(100);
	}
}

CEstilos(LPARAM cor){
	if(cor == CObterID(1) || cor == CObterID(15)){
		CMCP(255,255,255);
		CFundoT();
	}else if(cor == CObterID(3) || cor == CObterID(17) || cor == CObterID(54)){
		CFundoT();	
		CMCP(255,255,255);
	}else if(cor == CObterID(4) || cor == CObterID(20)){
		CMCP(255,255,255);
		CFundoT();
	}else if(cor == CObterID(6) || cor == CObterID(22)){
		CFundoT();
		CMCP(255,255,255);
	}else if(cor == CObterID(8) || cor == CObterID(25)){
		CFundoT();
		CMCP(255,255,255);
	}else if(cor == CObterID(11) || cor == CObterID(29)){
		CFundoT();
		CMCP(255,255,255);
	}else if(cor == CObterID(33) || cor == CObterID(37)){
		CFundoT();
		CMCP(255,255,255);
	}else if(cor == CObterID(41) || cor == CObterID(37)){
		CFundoT();
		CMCP(255,255,255);
	}else if(cor == CObterID(45)){
		CMFP(171,86,199);
		CMCP(255,255,255);
	}else if(cor == CObterID(46) || cor == CObterID(47) || cor == CObterID(48) || cor == CObterID(49) || cor == CObterID(50) || cor == CObterID(51) || cor == CObterID(52) || cor == CObterID(53)){
		CFundoT();
		CMCP(255,255,255);
	}
}

CComponentesGraficos(){	
	
	CGroupBox(4,132,342,252);
	CModIcone("peggle-ico2.ico");
	CImagem("Peggle-header.bmp",0,0,356,125);
	//-------------------------------------------
	CTexto(1,"Bolas Azuis",27,190,80,15);
	CNumero(2,112,189,30,20);
	CTextoC(3,"- Qtd. Atual",108,190,150,15);
	CCaixaDeTextoB(4,223,189,30,20);
	EnableWindow(hcomp[Construtora][4],FALSE);
	CBotao(5,"Alterar",260,187,52,25);
	//-------------------------------------------
	CTexto(6,"Bolas Laranja",20,219,91,15);
	CNumero(7,112,217,30,20);
	CTextoC(8,"- Qtd. Atual",108,219,150,15);
	CCaixaDeTextoB(9,223,217,30,20);
	EnableWindow(hcomp[Construtora][9],FALSE);
	CBotao(10,"Alterar",260,215,52,25);
	//-------------------------------------------
	CImagem("uni.bmp",10,251,35,35);
	CTexto(11,"Especial",50,248,100,15);
	CCaixaDeTexto(12,50,265,55,20);
	EnableWindow(hcomp[Construtora][12],FALSE);
	CCaixaDeTexto(13,110,248,60,15);
	CBotao(14,"Alterar",110,263,60,23);
	EnableWindow(hcomp[Construtora][12],FALSE);
	//-------------------------------------------
	CTexto(15,"Bolas:",10,138,45,15);
	CCaixaDeTextoB(16,55,137,61,20);
	CTexto(17," ADD:",10,160,40,15);
	CNumero(18,55,160,61,20);
	CBotao(19,"Alterar",118,137,52,44);
	EnableWindow(hcomp[Construtora][16],FALSE);
	//-------------------------------------------
	CTexto(20,"Pts:",182,138,45,15);
	CCaixaDeTextoB(21,210,137,78,20);
	CTexto(22," ADD:",172,162,40,15);
	CNumero(23,210,160,78,20);
	CBotao(24,"Alterar",290,137,52,44);
	EnableWindow(hcomp[Construtora][21],FALSE);
	//-------------------------------------------
	CImagem("cat.bmp",303,251,35,35);
	CTexto(25,"Especial",244,248,100,15);
	CCaixaDeTexto(26,244,265,55,20);
	EnableWindow(hcomp[Construtora][26],FALSE);
	CCaixaDeTexto(27,180,248,60,15);
	CBotao(28,"Alterar",180,263,60,23);
	EnableWindow(hcomp[Construtora][26],FALSE);
	//-------------------------------------------
	CImagem("car.bmp",10,296,35,35);
	CTexto(29,"Especial",50,296,100,15);
	CCaixaDeTexto(30,50,312,55,20);
	EnableWindow(hcomp[Construtora][12],FALSE);
	CCaixaDeTexto(31,110,296,60,15);
	CBotao(32,"Alterar",110,312,60,23);
	EnableWindow(hcomp[Construtora][30],FALSE);
	//-------------------------------------------
	CImagem("abo.bmp",303,296,35,35);
	CTexto(33,"Especial",244,296,100,15);
	CCaixaDeTexto(34,244,312,55,20);
	EnableWindow(hcomp[Construtora][26],FALSE);
	CCaixaDeTexto(35,180,296,60,15);
	CBotao(36,"Alterar",180,312,60,23);
	EnableWindow(hcomp[Construtora][34],FALSE);
	CreateThread(NULL,0,Refresh,NULL,0,0);	
	//-------------------------------------------
	CImagem("dra.bmp",10,341,35,35);
	CTexto(37,"Especial",50,341,100,15);
	CCaixaDeTexto(38,50,357,55,20);
	EnableWindow(hcomp[Construtora][12],FALSE);
	CCaixaDeTexto(39,110,341,60,15);
	CBotao(40,"Alterar",110,357,60,23);
	EnableWindow(hcomp[Construtora][38],FALSE);
	//-------------------------------------------
	CImagem("cor.bmp",303,341,35,35);
	CTexto(41,"Especial",244,341,100,15);
	CCaixaDeTexto(42,244,357,55,20);
	EnableWindow(hcomp[Construtora][26],FALSE);
	CCaixaDeTexto(43,180,341,60,15);
	CBotao(44,"Alterar",180,357,60,23);
	//-------------------------------------------
	CGroupBox(4,395,342,80);
	CTextoC(45,"Bloquear Valores",15,387,120,15);
	CCheckBox(46,"Bolas",110,450,50,20);
	CCheckBox(47,"Bonus",180,450,65,20);
	CImagem("uni.bmp",10,410,25,25);
	CCheckBox(48,"",40,415,15,20);
	CImagem("cat.bmp",70,410,25,25);
	CCheckBox(49,"",100,415,15,20);
	CImagem("car.bmp",127,410,25,25);
	CCheckBox(50,"",157,415,15,20);
	CImagem("abo.bmp",183,410,25,25);
	CCheckBox(51,"",213,415,15,20);
	CImagem("dra.bmp",240,410,25,25);
	CCheckBox(52,"",270,415,15,20);
	CImagem("cor.bmp",295,410,25,25);
	CCheckBox(53,"",325,415,15,20);
	CTextoC(54,"Processo:",60,480,75,15);
	CCaixaDeTextoB(55,130,478,150,20);
	EnableWindow(hcomp[Construtora][42],FALSE);
	CreateThread(NULL,0,Refresh,NULL,0,0);	
}

CComandos(WPARAM id){
	switch(id){
		case 10:{
			DWORD pid = getPID(proc);
			intptr_t Address = 0x19ff7c-0x268;
			HANDLE process = OpenProcess(PROCESS_ALL_ACCESS,FALSE,pid);
			unsigned int offset[5] = {0x164,0x1C,0x178,0x154,0x360};
			intptr_t AddrFinal = AddressBase(process,Address,offset);
			int Valor = atoi(CObterTexto(7));
			WriteProcessMemory(process,(LPVOID) AddrFinal, &Valor, sizeof(Valor),0);
			CloseHandle(process);
			SetWindowText(hcomp[Construtora][7],"");
			CloseHandle(process);
			break;
		}
		case 5:{
			DWORD pid = getPID(proc);
			intptr_t Address = 0x19ff7c-0x268;
			HANDLE process = OpenProcess(PROCESS_ALL_ACCESS,FALSE,pid);
			unsigned int offset[5] = {0x15C,0x1C,0x174,0x154,0x36C};
			intptr_t AddrFinal = AddressBase(process,Address,offset);
			int Valor = atoi(CObterTexto(2));
			WriteProcessMemory(process,(LPVOID) AddrFinal, &Valor, sizeof(Valor),0);
			CloseHandle(process);            
			SetWindowText(hcomp[Construtora][2],"");
			break;
		}
		case 14:{
			DWORD pid = getPID(proc);
			intptr_t Address =  0x19ff7c-0x268;
			HANDLE process = OpenProcess(PROCESS_ALL_ACCESS,FALSE,pid);
			unsigned int offset[5] = {0x160,0x1C,0x178,0x154,0x1DC};
			intptr_t AddrFinal = AddressBase(process,Address,offset);
			int Valor = atoi(CObterTexto(13));
			WriteProcessMemory(process,(LPVOID) AddrFinal, &Valor, sizeof(Valor),0);
			CloseHandle(process);
			SetWindowText(hcomp[Construtora][13],"");
			break;
		}
		case 19:{
			DWORD pid = getPID(proc);
			intptr_t Address = 0x19ff7c-0x268;
			HANDLE process = OpenProcess(PROCESS_ALL_ACCESS,FALSE,pid);
			unsigned int offset[5] = {0x16C,0x1C,0x10,0x154,0x17C};
			intptr_t AddrFinal = AddressBase(process,Address,offset);
			int Valor = atoi(CObterTexto(18));
			WriteProcessMemory(process,(LPVOID) AddrFinal, &Valor, sizeof(Valor),0);
			CloseHandle(process);
			SetWindowText(hcomp[Construtora][18],"");
			break;
		}
		case 24:{
			DWORD pid = getPID(proc);
			intptr_t Address = 0x19ff7c-0x268;
			HANDLE process = OpenProcess(PROCESS_ALL_ACCESS,FALSE,pid);
			unsigned int offset[5] = {0x16C,0x10,0x88,0x154,0x174};
			intptr_t AddrFinal = AddressBase(process,Address,offset);
			int Valor = atoi(CObterTexto(23));
			WriteProcessMemory(process,(LPVOID) AddrFinal, &Valor, sizeof(Valor),0);
			CloseHandle(process);
			SetWindowText(hcomp[Construtora][23],"");
			break;
		}
		case 28:{
			DWORD pid = getPID(proc);
			intptr_t Address = 0x19ff7c-0x268;
			HANDLE process = OpenProcess(PROCESS_ALL_ACCESS,FALSE,pid);
			unsigned int offset[5] = {0x16C,0x1C,0x10,0x154,0x1F4};
			intptr_t AddrFinal = AddressBase(process,Address,offset);
			int Valor = atoi(CObterTexto(27));
			WriteProcessMemory(process,(LPVOID) AddrFinal, &Valor, sizeof(Valor),0);
			CloseHandle(process);
			SetWindowText(hcomp[Construtora][27],"");
			break;
		}
		case 32:{
			DWORD pid = getPID(proc);
			intptr_t Address = 0x19ff7c-0x700;
			HANDLE process = OpenProcess(PROCESS_ALL_ACCESS,FALSE,pid);
			unsigned int offset[5] = {0x88,0x16C,0x14,0x154,0x1E4};
			intptr_t AddrFinal = AddressBase(process,Address,offset);
			int Valor = atoi(CObterTexto(31));
			WriteProcessMemory(process,(LPVOID) AddrFinal, &Valor, sizeof(Valor),0);
			CloseHandle(process);
			SetWindowText(hcomp[Construtora][31],"");
			break;
		}
		case 36:{
			DWORD pid = getPID(proc);
			intptr_t Address = 0x19ff7c-0x268;
			HANDLE process = OpenProcess(PROCESS_ALL_ACCESS,FALSE,pid);
			unsigned int offset[5] = {0x164,0x1C,0x178,0x154,0x204};
			intptr_t AddrFinal = AddressBase(process,Address,offset);
			int Valor = atoi(CObterTexto(35));
			WriteProcessMemory(process,(LPVOID) AddrFinal, &Valor, sizeof(Valor),0);
			CloseHandle(process);
			SetWindowText(hcomp[Construtora][35],"");
			break;
		}
		case 40:{
			DWORD pid = getPID(proc);
			intptr_t Address = 0x19ff7c-0x700;
			HANDLE process = OpenProcess(PROCESS_ALL_ACCESS,FALSE,pid);
			unsigned int offset[5] = {0x4,0xB8,0x200,0x154,0x234};
			intptr_t AddrFinal = AddressBase(process,Address,offset);
			int Valor = atoi(CObterTexto(39));
			WriteProcessMemory(process,(LPVOID) AddrFinal, &Valor, sizeof(Valor),0);
			CloseHandle(process);
			SetWindowText(hcomp[Construtora][39],"");
			break;
		}
		case 44:{
			DWORD pid = getPID(proc);
			intptr_t address = 0x19ff7c-0x3EC;
			unsigned int offset[5] = {0x2A4,0x84,0x1C,0x150,0x20C};
			HANDLE process = OpenProcess(PROCESS_ALL_ACCESS,FALSE,pid);
			intptr_t AddrFinal = AddressBase(process,address,offset);
			int Valor = atoi(CObterTexto(43));
			WriteProcessMemory(process,(LPVOID) AddrFinal, &Valor, sizeof(Valor),0);
			CloseHandle(process);
			SetWindowText(hcomp[Construtora][43],"");
			break;
		}
		case 46:{
			CCheck(46);
			break;
		}
		case 47:{
			CCheck(47);
			break;
		}
		case 48:{
			CCheck(48);
			break;
		}
		case 49:{
			CCheck(49);
			break;
		}
		case 50:{
			CCheck(50);
			break;
		}
		case 51:{
			CCheck(51);
			break;
		}
		case 52:{
			CCheck(52);
			break;
		}
		case 53:{
			CCheck(53);
			break;
		}
		default:{
			break;
		}
	}
}
#endif
