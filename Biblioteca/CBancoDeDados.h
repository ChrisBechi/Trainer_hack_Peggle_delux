#ifndef CBANCODEDADOS_H_INCLUDED
#define CBANCODEDADOS_H_INCLUDED
#include <ctype.h>
#include "varAmbiente.h"
	
	char conexao[4][50];
	
	void importConnection(){
		FILE *conn;
		char aux[50]="",final[50]="",retorno[50];
		if((conn=fopen("BancoDeDados/BancoDeDados.txt","r")) == NULL){
			MessageBox(NULL,"Não foi possivel abrir o arquivo!","ERROR Arquivo",MB_OK|0x10);
		}	
		int item=0;
		while(fscanf(conn,"%s",aux) != EOF){
			int cont=0,cont2=0;
			while(aux[cont] != '=')cont++;
			while(aux[cont] != '\0'){
				cont++;
				final[cont2] = aux[cont];
				cont2++;
			}
			final[cont2] = '\0';
			strcpy(conexao[item],final);
			item++;
		}	
		fclose(conn);		
	}
	
	int CBDAbre(){
		mysql_init(&conn);
		importConnection();
		if(mysql_real_connect(&conn,conexao[0],conexao[1],conexao[2],conexao[3],0,NULL,0))
			return 0;
		else
			return 1;
	}
	
	void AddDataBase(const char *Banco){
		FILE *conn;
		char aux[500]="",final[50]="",retorno[50];
		if((conn=fopen("BancoDeDados/BancoDeDados.txt","r")) == NULL){
			MessageBox(NULL,"Não foi possivel abrir o arquivo!","ERROR Arquivo",MB_OK|0x10);
		}	
		fread(aux,sizeof(char),500,conn);
		int comprimento=strlen(aux);
		fclose(conn);
		while(aux[comprimento] != '='){
			aux[comprimento] = ' ';
			comprimento--;
		}
		int cont=0;
		comprimento++;
		while(Banco[cont] != '\0'){
			aux[comprimento] = Banco[cont];
			cont++;
			comprimento++;
		}
		aux[comprimento] = '\0';
		if((conn=fopen("BancoDeDados/BancoDeDados.txt","w")) == NULL){
			MessageBox(NULL,"Não foi possivel abrir o arquivo!","ERROR Arquivo",MB_OK|0x10);
		}	
		fputs(aux,conn);
		fclose(conn);						
	}
	
	void CBDFecha(){
		mysql_close(&conn);		
	}
	
	int VerificaCaracter(const char *tabela){
		int cont=0, kanji=0;
		while(tabela[cont] != '\0'){
			kanji = (int) tabela[cont];
			if(kanji < 65 || kanji > 90){
				if(kanji < 97 || kanji > 122){
					return 1;
				}
			}
			cont++;
		}
		return 0;
	}
	
	int CBDCriarBanco(const char *NomeDoBanco){
		mysql_init(&conn);
		importConnection();
		mysql_real_connect(&conn,conexao[0],conexao[1],conexao[2],"",0,NULL,0);
		char query[255] = "CREATE DATABASE IF NOT EXISTS ";
		if(VerificaCaracter(NomeDoBanco) == 0){
			strcat(query,NomeDoBanco);
			strcat(query," default character set utf8 default collate utf8_general_ci;");
			mysql_query(&conn,query);
			CBDFecha();
			AddDataBase(NomeDoBanco);
			return 0;
		}
		CBDFecha();
		return 1;
	}
	
	int CBDCriarTabela(const char *NomeDaTabela, char Campos[][100]){
		
		int count=0;
		if(CBDAbre()!= 0){
			MessageBox(NULL,"Não foi possivel abrir a conexão!","ERROR de conexao",MB_OK|0x10);
		}
		char query[10000] ="CREATE TABLE IF NOT EXISTS ";
		strcat(query,NomeDaTabela);
		strcat(query,"(");
		for(count=1;count<=atoi(Campos[0]);count++){
			strcat(query,Campos[count]);
			strcat(query,",");	
		}
		query[strlen(query)-1] = ')';
		strcat(query,"DEFAULT charset = utf8;");
		if(VerificaCaracter(NomeDaTabela) == 0){
			mysql_query(&conn,query);
			CBDFecha();
			return 0;
		}
		CBDFecha();
		return 1;
	}
	
	int CBDApagarTabela(const char *NomeDaTabela){
		int count=0;
		if(CBDAbre()!= 0){
			MessageBox(NULL,"Não foi possivel abrir a conexão!","ERROR de conexao",MB_OK|0x10);
		}
		char query[10000] ="DROP TABLE IF EXISTS ";
		strcat(query,NomeDaTabela);
		if(VerificaCaracter(NomeDaTabela) == 0){
			mysql_query(&conn,query);
			CBDFecha();
			return 0;
		}
		CBDFecha();
		return 1;
	}
	
	int CBDApagarBanco(const char *NomeDoBanco){
		mysql_init(&conn);
		importConnection();
		mysql_real_connect(&conn,conexao[0],conexao[1],conexao[2],"",0,NULL,0);
		char query[10000] ="DROP DATABASE IF EXISTS ";
		strcat(query,NomeDoBanco);
		if(VerificaCaracter(NomeDoBanco) == 0){
			mysql_query(&conn,query);
			CBDFecha();
			return 0;
		}
		CBDFecha();
		return 1;
	}
	
	int CBDInserir(char *Tabela, char Ordem[][100], char Campos[][100]){
		
		int count=0;
		if(CBDAbre()!= 0){
			MessageBox(NULL,"Não foi possivel abrir a conexão!","ERROR de conexao",MB_OK|0x10);
		}
		char query[10000] ="INSERT INTO ";
		strcat(query,Tabela);
		strcat(query,"(");
		for(count=1;count<=atoi(Ordem[0]);count++){
			strcat(query,Ordem[count]);
			strcat(query,",");	
		}
		query[strlen(query)-1] = ')';
		strcat(query," values (");	
		for(count=0;count<=atoi(Ordem[0])-1;count++){
			strcat(query,Campos[count]);
			strcat(query,",");	
		}
		query[strlen(query)-1] = ')';
		if(VerificaCaracter(Tabela) == 0){
			mysql_query(&conn,query);
			CBDFecha();
			return 0;
		}
		return 1;
	}
	
	int CBDAtualizar(char *Tabela, char Campos[][100], char *condicao){
		
		int count=0;
		if(CBDAbre()!= 0){
			MessageBox(NULL,"Não foi possivel abrir a conexão!","ERROR de conexao",MB_OK|0x10);
		}
		char query[10000] ="UPDATE ";
		strcat(query,Tabela);
		strcat(query," SET ");
		for(count=1;count<=atoi(Campos[0]);count++){
			strcat(query,Campos[count]);
			strcat(query,",");	
		}
		query[strlen(query)-1] = ' ';
		strcat(query,"WHERE ");
		strcat(query,condicao);
		if(VerificaCaracter(Tabela) == 0){
			mysql_query(&conn,query);
			CBDFecha();
			return 0;
		}
		return 1;
	}
	
	int CBDApagarTudo(char *Tabela){
		if(CBDAbre()!= 0){
			MessageBox(NULL,"Não foi possivel abrir a conexão!","ERROR de conexao",MB_OK|0x10);
			return -1;
		}
		char query[300] ="TRUNCATE TABLE ";
		strcat(query,Tabela);
		if(VerificaCaracter(Tabela) == 0){
			mysql_query(&conn,query);
			CBDFecha();
			return 0;
		}
		CBDFecha();
		return 1;
	}
	
	int CBDApagarDado(char *Tabela, char *campo, char *porNome, int porNumero){
		if(CBDAbre() != 0){
			MessageBox(NULL,"Não foi possivel abrir a conexão!","ERROR de conexao",MB_OK|0x10);
			return -1;
		}
		char query[300] ="delete from ";
		strcat(query,Tabela);
		strcat(query," where ");
		strcat(query,campo);
		strcat(query,"=");
		if(porNumero < 0){
			strcat(query,porNome);
		}else if(porNome != NULL && strcmp(porNome,"") != 0){			
			char convert[10];
			itoa(porNumero,convert,10);
			strcat(query,convert);
		}else{
			return -1;
		}
		if(VerificaCaracter(Tabela) == 0){
			mysql_query(&conn,query);
			CBDFecha();
			return 0;
		}
		CBDFecha();
		return 1;
	}
	
	int CBDAddColuna(char *Tabela, char *coluna, char posicao, char *ColunaAnterior){
		if(CBDAbre()!= 0){
			MessageBox(NULL,"Não foi possivel abrir a conexão!","ERROR de conexao",MB_OK|0x10);
			return -1;
		}
		char query[300] ="ALTER TABLE ";
		strcat(query,Tabela);
		if(VerificaCaracter(Tabela) == 0){
			strcat(query," ADD ");
			strcat(query,coluna);
			if(posicao=='P' || posicao=='p')
				strcat(query," FIRST ");
			else if(posicao=='A' || posicao=='a'){
				strcat(query," AFTER ");
				strcat(query,ColunaAnterior);
			}			
			mysql_query(&conn,query);
			CBDFecha();
			return 0;
		}
		CBDFecha();
		return 1;
	}	
	
	
	int CBDApagarColuna(char *Tabela, char *coluna){
		if(CBDAbre()!= 0){
			MessageBox(NULL,"Não foi possivel abrir a conexão!","ERROR de conexao",MB_OK|0x10);
			return -1;
		}
		char query[300] ="ALTER TABLE ";
		strcat(query,Tabela);
		if(VerificaCaracter(Tabela) == 0){
			strcat(query," DROP COLUMN ");
			strcat(query,coluna);						
			mysql_query(&conn,query);
			CBDFecha();
			return 0;
		}
		CBDFecha();
		return 1;
	}
	
	int CBDModificaColuna(char *Tabela, char *coluna){
		if(CBDAbre()!= 0){
			MessageBox(NULL,"Não foi possivel abrir a conexão!","ERROR de conexao",MB_OK|0x10);
			return -1;
		}
		char query[300] ="ALTER TABLE ";
		strcat(query,Tabela);
		if(VerificaCaracter(Tabela) == 0){
			strcat(query," MODIFY COLUMN ");
			strcat(query,coluna);						
			mysql_query(&conn,query);
			CBDFecha();
			return 0;
		}
		CBDFecha();
		return 1;
	}
	
	int CBDAddFK(char *Tabela,char *coluna, char *TabelaPK, char *PK){
		if(CBDAbre()!= 0){
			MessageBox(NULL,"Não foi possivel abrir a conexão!","ERROR de conexao",MB_OK|0x10);
			return -1;
		}
		char query[300] ="ALTER TABLE ";
		strcat(query,Tabela);
		if(VerificaCaracter(Tabela) == 0){
			strcat(query," ADD CONSTRAINT FK_");
			strcat(query,coluna);
			strcat(query," FOREIGN KEY (`");
			strcat(query,coluna);
			strcat(query,"`) REFERENCES ");
			strcat(query,TabelaPK);	
			strcat(query,"(`");					
			strcat(query,PK);
			strcat(query,"`)");
			mysql_query(&conn,query);
			CBDFecha();
			SetWindowText(hcomp[Construtora][15],query);
			return 0;
		}
		CBDFecha();
		return 1;
	}
	
	int CBDAddPK(char *Tabela, char *coluna){
		if(CBDAbre()!= 0){
			MessageBox(NULL,"Não foi possivel abrir a conexão!","ERROR de conexao",MB_OK|0x10);
			return -1;
		}
		char query[300] ="ALTER TABLE ";
		strcat(query,Tabela);
		if(VerificaCaracter(Tabela) == 0){
			strcat(query," ADD PRIMARY_KEY(`");
			strcat(query,coluna);
			strcat(query,"`)");						
			mysql_query(&conn,query);
			CBDFecha();
			return 0;
		}
		CBDFecha();
		return 1;
	}	
	
	char** CBDConsulta(const char *Tabela, const char *ordenar){
		MYSQL_RES *restore;
		MYSQL_ROW linha;
		MYSQL_FIELD *campo;
		if(CBDAbre()!= 0){
			MessageBox(NULL,"Não foi possivel abrir a conexão!","ERROR de conexao",MB_OK|0x10);
		}
		if(VerificaCaracter(Tabela) == 0){
			char query[500] ="Select * from ";
			strcat(query,Tabela);
			if(ordenar[0] != '\0'){
				strcat(query," ORDER BY ");
				strcat(query,ordenar);
			}
			mysql_query(&conn,query);
			restore = mysql_store_result(&conn);
			int coluna=mysql_num_fields(restore);
			int col,lin;
			int numLinha= mysql_num_rows(restore);
			char **campos = malloc((numLinha * coluna) * sizeof(char*));
			for(lin=0; lin < numLinha; lin++){
				linha = mysql_fetch_row(restore);
				for(col=0; col < coluna; col++){
					campos[col] = malloc( 100 * sizeof(char));
					if(linha[col] != NULL){
						strcpy(campos[col],linha[col]);
						MessageBox(NULL,campos[col],"Caption",MB_OK);
					}else{
						strcpy(campos[col],"\0");
					}
				}				
			}
			CBDFecha();
			return campos;
		}
		CBDFecha();
		return NULL;
	}
	
	char** CBDConsultaCondicao(const char *Tabela, char campos[][100], const char *condicao,const char *ordenar){
		MYSQL_RES *restore;
		MYSQL_ROW linha;
		MYSQL_FIELD *campo;
		if(CBDAbre()!= 0){
			MessageBox(NULL,"Não foi possivel abrir a conexão!","ERROR de conexao",MB_OK|0x10);
		}
		if(VerificaCaracter(Tabela) == 0){
			char query[500] ="Select ";
			int i=1;
			while(i<=atoi(campos[0])){
				strcat(query,campos[i]);
				strcat(query,",");
				i++;
			}
			query[strlen(query)-1] = ' ';
			strcat(query,"from ");
			strcat(query,Tabela);
			if(condicao[0] != '\0'){
				strcat(query," where ");
				strcat(query,condicao);
			}
			if(ordenar[0] != '\0'){
				strcat(query," ORDER BY ");
				strcat(query,ordenar);
			}
			mysql_query(&conn,query);
			restore = mysql_store_result(&conn);
			int coluna=mysql_num_fields(restore);
			int numLinha=mysql_num_rows(restore);
			int col,lin;
			char **campos = malloc((numLinha * coluna) * sizeof(char*));
			for(lin=0; lin < numLinha; lin++){
				linha = mysql_fetch_row(restore);
				for(col=0; col < coluna; col++){
					campos[col] = malloc( 100 * sizeof(char));
					if(linha[col] != NULL){
						strcpy(campos[col],linha[col]);
						MessageBox(NULL,campos[col],"Caption",MB_OK);
					}else{
						strcpy(campos[col],"\0");
					}
				}				
			}
			CBDFecha();
			return campos;
		}
		CBDFecha();
		return NULL;
	}	
	
	char** CBDInnerJoin(char campos[][100], char Joins[][100],const char *condicao,const char *ordenar){
		MYSQL_RES *restore;
		MYSQL_ROW linha;
		MYSQL_FIELD *campo;
		if(CBDAbre()!= 0){
			MessageBox(NULL,"Não foi possivel abrir a conexão!","ERROR de conexao",MB_OK|0x10);
		}
		if(VerificaCaracter(Joins[1]) == 0){
			char query[500] ="Select ";
			int i=1;
			while(i<=atoi(campos[0])){
				strcat(query,campos[i]);
				strcat(query,",");
				i++;
			}
			query[strlen(query)-1] = ' ';
			strcat(query,"from ");
			strcat(query,Joins[1]);
			i=1;
			int count=1;
			while(i<=atoi(Joins[0])){
				strcat(query," INNER JOIN ");
				count+=2;
				strcat(query,Joins[count]);
				strcat(query," on ");
				count-=2;
				strcat(query,Joins[count]);
				strcat(query,".");
				count++;
				strcat(query,Joins[count]);
				strcat(query," = ");
				count++;
				strcat(query,Joins[count]);
				strcat(query,".");
				count++;
				strcat(query,Joins[count]);
				count--;
				i++;
			}
			MessageBox(NULL,query,"Caption",MB_OK);
			if(condicao[0] != '\0'){
				strcat(query," where ");
				strcat(query,condicao);
			}
			if(ordenar[0] != '\0'){
				strcat(query," ORDER BY ");
				strcat(query,ordenar);
			}
			mysql_query(&conn,query);
			restore = mysql_store_result(&conn);
			int coluna=mysql_num_fields(restore);
			int numLinha=mysql_num_rows(restore);
			int col,lin;
			char **campos = malloc((numLinha * coluna) * sizeof(char*));
			for(lin=0; lin < numLinha; lin++){
				linha = mysql_fetch_row(restore);
				for(col=0; col < coluna; col++){
					campos[col] = malloc( 100 * sizeof(char));
					if(linha[col] != NULL){
						strcpy(campos[col],linha[col]);
						MessageBox(NULL,campos[col],"Caption",MB_OK);
					}else{
						strcpy(campos[col],"\0");
					}
				}				
			}
			CBDFecha();
			return campos;
		}
		CBDFecha();
		return NULL;
	}	
	
	int CBDConsultaTotal(const char *Tabela, const char *condicao){
		MYSQL_RES *restore;
		MYSQL_ROW linha;
		MYSQL_FIELD *campo;
		if(CBDAbre()!= 0){
			MessageBox(NULL,"Não foi possivel abrir a conexão!","ERROR de conexao",MB_OK|0x10);
		}
		if(VerificaCaracter(Tabela) == 0){
			char query[500] ="Select count(*) ";
			int i=1;
			strcat(query,"from ");
			strcat(query,Tabela);
			if(condicao[0] != '\0'){
				strcat(query," where ");
				strcat(query,condicao);
			}
			mysql_query(&conn,query);
			restore = mysql_store_result(&conn);
			linha = mysql_fetch_row(restore);
			int total = atoi(linha[0]);
			CBDFecha();
			return total;
		}
		CBDFecha();
		return 0;
	}	
	
	int CBDConsultaMin(const char *Tabela, const char *campo, const char *condicao){
		MYSQL_RES *restore;
		MYSQL_ROW linha;
		if(CBDAbre()!= 0){
			MessageBox(NULL,"Não foi possivel abrir a conexão!","ERROR de conexao",MB_OK|0x10);
		}
		if(VerificaCaracter(Tabela) == 0){
			char query[500] ="Select min(";
			strcat(query,campo);
			strcat(query,") from ");
			strcat(query,Tabela);
			if(condicao[0] != '\0'){
				strcat(query," where ");
				strcat(query,condicao);
			}
			mysql_query(&conn,query);
			restore = mysql_store_result(&conn);
			linha = mysql_fetch_row(restore);
			int total = atoi(linha[0]);
			CBDFecha();
			return total;
		}
		CBDFecha();
		return 1;
	}
	
	int CBDConsultaMax(const char *Tabela, const char *campo, const char *condicao){
		MYSQL_RES *restore;
		MYSQL_ROW linha;
		if(CBDAbre()!= 0){
			MessageBox(NULL,"Não foi possivel abrir a conexão!","ERROR de conexao",MB_OK|0x10);
		}
		if(VerificaCaracter(Tabela) == 0){
			char query[500] ="Select max(";
			strcat(query,campo);
			strcat(query,") from ");
			strcat(query,Tabela);
			if(condicao[0] != '\0'){
				strcat(query," where ");
				strcat(query,condicao);
			}
			mysql_query(&conn,query);
			restore = mysql_store_result(&conn);
			linha = mysql_fetch_row(restore);
			int total = atoi(linha[0]);
			CBDFecha();
			return total;
		}
		CBDFecha();
		return 1;
	}
	
	int CBDConsultaSoma(const char *Tabela, const char *campo, const char *condicao){
		MYSQL_RES *restore;
		MYSQL_ROW linha;
		if(CBDAbre()!= 0){
			MessageBox(NULL,"Não foi possivel abrir a conexão!","ERROR de conexao",MB_OK|0x10);
		}
		if(VerificaCaracter(Tabela) == 0){
			char query[500] ="Select sum(";
			strcat(query,campo);
			strcat(query,") from ");
			strcat(query,Tabela);
			if(condicao[0] != '\0'){
				strcat(query," where ");
				strcat(query,condicao);
			}
			mysql_query(&conn,query);
			restore = mysql_store_result(&conn);
			linha = mysql_fetch_row(restore);
			int total = atoi(linha[0]);
			CBDFecha();
			return total;
		}
		CBDFecha();
		return 1;
	}
	
	double CBDConsultaMedia(const char *Tabela, const char *campo, const char *condicao){
		MYSQL_RES *restore;
		MYSQL_ROW linha;
		if(CBDAbre()!= 0){
			MessageBox(NULL,"Não foi possivel abrir a conexão!","ERROR de conexao",MB_OK|0x10);
		}
		if(VerificaCaracter(Tabela) == 0){
			char query[500] ="Select avg(";
			strcat(query,campo);
			strcat(query,") from ");
			strcat(query,Tabela);
			if(condicao[0] != '\0'){
				strcat(query," where ");
				strcat(query,condicao);
			}
			mysql_query(&conn,query);
			restore = mysql_store_result(&conn);
			linha = mysql_fetch_row(restore);
			double total = atof(linha[0]);
			CBDFecha();
			return total;
		}
		CBDFecha();
		return 1;
	}				
#endif
