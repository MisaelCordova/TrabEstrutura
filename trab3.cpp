#include<stdio.h>
#include<iostream>
#include<list>
#include<string>
#include <unistd.h>
#include<locale.h>
#include<list>
using namespace std;

string enter;

int op, inCodigo = 100000;

struct Data{
	int dia = 8, mes = 7, ano = 2021, idDias;
};
struct Emprestimo{
	Data dtEmp, dtDev, Livro livro;
};
struct User{
	string nome, endereco, telefone, email, senha, cpf;
	int codigo, quantEmprestimos;
	Emprestimo emprestimo;
};
struct Livro{
	string titulo, autor, editora, localEdicao, palavrasChaves;
	int ano, ISBN, codigo, numExemplares, exemplar;
};


list<User> listaUser;
list<User> :: iterator itu;
list<Livro> listaLivro;
list<Livro> :: iterator itl;

Data data;

void passaDia(void);
void buscaMes(void);
void dataEmprestimo(int a);

void menuPrincipal(void);
void menuCadastros(void);
void menuEmprestimos(void);

void cadastroUser(void);
void cadastroLivro(void);

void cadastroEmprestimo(void);
void cadastroReserva(void);

void listaUsers(void);
void listaLivros(void);

void verificaUser(string a);
void verificaLivro(int a);

void verificaUserEmprestimo(int a);
void verificaLivroEmprestimo(int a);
void verificaSenhaEmprestimo(int cod, string senha);

void verificaDeletaUser(int a);
void verificaDeletaLivro(int a);

void deletaUser(void);
void deletaLivro(void);


main(){
	setlocale(LC_ALL, "Portuguese");
	menuPrincipal();
}

//-------------------------------------------------------------------------------------------------------------
//MENUS
//-------------------------------------------------------------------------------------------------------------
void menuPrincipal(void){
	system("clear");
	cout << "Data: " << data.dia << "/" << data.mes << "/" << data.ano;
	cout << "\n\n-----MENU-----\n\n";
	cout << "[1] Cadastros\n";
	cout << "[2] Empr�stimos\n";
	cout << "[3] Lista de Usu�rios\n";
	cout << "[4] Lista de Livros\n";
	cout << "[5] Apagar Usu�rio\n";
	cout << "[6] Apagar Livro\n";
	cout << "[7] Sair\n";
	cin >> op;
	
	switch(op){
		case 0:
			passaDia();
			break;
		case 1:
			menuCadastros();
			break;
		case 2:
			menuEmprestimos();
			break;
		case 3:
			listaUsers();
			break;
		case 4:
			listaLivros();
			break;	
		case 5:
			deletaUser();
			break;
		case 6:
			deletaLivro();
			break;
		case 7:
			break;
		default:
			cout << "Comando Inv�lido!";
			sleep(3);
			menuPrincipal();
	}
}
void menuCadastros(void){
	system("clear");
	cout << "-----Cadastros-----\n\n";
	cout << "[1] Usu�rio\n";
	cout << "[2] Livro\n";
	cout << "[3] Voltar\n";
	cin >> op;
	
	switch(op){
		case 1:
			cadastroUser();
		case 2:
			cadastroLivro();
		case 3:
			menuPrincipal();
		default:
			cout << "Comando Inv�lido!";
			sleep(3);
			menuCadastros();
	}
}
void menuEmprestimos(void){
	system("clear");
	cout << "-----Empr�stimos-----\n\n";
	cout << "[1] Registrar empr�stimo\n";
	cout << "[2] Registrar reserva\n";
	cout << "[3] Voltar\n";
	cin >> op;
	
	switch(op){
		case 1:
			cadastroEmprestimo();
		case 2:
			cadastroReserva();
		case 3:
			menuPrincipal();
		default:
			cout << "Comando Inv�lido!";
			sleep(3);
			menuCadastros();
	}
}
//-------------------------------------------------------------------------------------------------------------
//CADASTROS USU�RIOS/LIVROS
//-------------------------------------------------------------------------------------------------------------
void cadastroUser(void){
	system("clear");
	User user;
	cout << "-----CADASTRO DE USU�RIOS-----\n\n";
	cout << "CPF...............: "; cin >> user.cpf;setbuf(stdin,NULL);verificaUser(user.cpf); 
	cout << "Nome..............: "; getline(cin, user.nome);
	cout << "Endere�o..........: "; getline(cin, user.endereco);
	cout << "Telefone..........: "; getline(cin, user.telefone);
	cout << "E-mail............: "; getline(cin, user.email);
	cout << "Senha.............: "; getline(cin, user.senha); user.codigo = listaUser.size() + 1; 
	cout << "C�digo de usu�rio.: " << user.codigo+inCodigo;
	
	listaUser.push_back(user);
	cout << "\n\nNovo usu�rio cadastrado com sucesso!";
	sleep(3);
	menuCadastros();
}
void cadastroLivro(void){
	system("clear");
	Livro livro;
	cout << "-----CADASTRO DE LIVROS-----\n\n";
	cout << "C�digo ISBN..........: "; cin >> livro.ISBN;setbuf(stdin,NULL);verificaLivro(livro.ISBN);
	cout << "T�tulo...............: "; getline(cin, livro.titulo); 
	cout << "Autor................: "; getline(cin, livro.autor); 
	cout << "Editora..............: "; getline(cin, livro.editora); 
	cout << "Local de edica��o....: "; getline(cin, livro.localEdicao); 
	cout << "Ano..................: "; cin >> livro.ano;setbuf(stdin,NULL);
	cout << "N�mero de exemplares.: "; cin >> livro.numExemplares;setbuf(stdin,NULL);
	cout << "Palavras chaves......: "; getline(cin, livro.palavrasChaves); livro.codigo = listaLivro.size() + 1;
	cout << "C�digo do livro......: " << livro.codigo+inCodigo;
	
	listaLivro.push_back(livro);
	cout << "\n\nNovo livro cadastrado com sucesso!";
	sleep(3);
	menuCadastros();
}
//-------------------------------------------------------------------------------------------------------------
//CADASTROS EMPR�STIMOS/RESERVAS
//-------------------------------------------------------------------------------------------------------------
void cadastroEmprestimo(void){
	system("clear");
	int codigoUser, codigoLivro;
	string senha;
	cout << "-----CADASTRO DE EMPR�STIMOS-----\n\n";
	cout << "C�digo de usu�rio.: "; cin >> codigoUser; verificaUserEmprestimo(codigoUser);
	cout << "C�digo do livro...: "; cin >> codigoLivro; verificaLivroEmprestimo(codigoLivro);
	cout << "Senha.: "; cin >> senha; verificaSenhaEmprestimo(codigoUser, senha);
	cout << "\n------------------------------------------------\n";dataEmprestimo(codigoUser);
	cout << "Data de empr�stimo: " << itu->emprestimo.dtEmp.dia << "/" << itu->emprestimo.dtEmp.mes << "/" << itu->emprestimo.dtEmp.ano << endl; 
	cout << "Data de devolu��o: " << itu->emprestimo.dtDev.dia << "/" << itu->emprestimo.dtDev.mes << "/" << itu->emprestimo.dtDev.ano << endl;
	cout << "\n------------------------------------------------\n";
	cout << "Empr�stimo cadastrado com sucesso!";
	
	sleep(3);
	
}
void cadastroReserva(void){
	cout << "salve";
}
//-------------------------------------------------------------------------------------------------------------
//LISTAGEM
//-------------------------------------------------------------------------------------------------------------
void listaUsers(void){
	system("clear");
	cout << "-----LISTAGEM DE USU�RIOS-----\n\n";
	itu = listaUser.begin();
	while(itu != listaUser.end()){
		cout << "C�digo de usu�rio..: " << itu -> codigo+inCodigo << "\n";
		cout << "Nome...............: " << itu -> nome << "\n";
		cout << "CPF................: " << itu -> cpf << "\n";
		cout << "Endere�o...........: " << itu -> endereco << "\n";
		cout << "Telefone...........: " << itu -> telefone << "\n";
		cout << "E-mail.............: " << itu -> email << "\n";
		cout << "Livros emprestados.: " << itu -> quantEmprestimos << "\n";
		cout << "\n------------------------------------------------\n\n";
		itu++;
	}
	cout << "Pressione enter para Voltar\n";
	cin >> enter;
	menuPrincipal();
	
}
void listaLivros(void){
	system("clear");
	cout << "-----LISTAGEM DE LIVROS-----\n\n";
	itl = listaLivro.begin();
	while(itl != listaLivro.end()){
		cout << "C�digo do Livro......: " << itl -> codigo+inCodigo << "\n";
		cout << "Titulo...............: " << itl -> titulo << "\n";
		cout << "Autor(a).............: " << itl -> autor << "\n";
		cout << "Editora..............: " << itl -> editora << "\n";
		cout << "Local de Edi��o......: " << itl -> localEdicao << "\n";
		cout << "Ano..................: " << itl -> ano << "\n";
		cout << "C�digo ISBN..........: " << itl -> ISBN << "\n";
		cout << "Palavras Chaves......: " << itl -> palavrasChaves << "\n";
		cout << "N�mero de exemplares.: " << itl -> numExemplares << "\n";
		cout << "\n------------------------------------------------\n\n";
		itl++;
	}
	cout << "Pressione enter para Voltar\n";
	cin >> enter;
	menuPrincipal();
	
}
/*void listaEmprestimos(void){
	system("clear");
	cout << "-----LISTAGEM DE Emprestimo-----\n\n";
	itu = listaUser.begin();
	while(itu != listaUser.end()){
		cout << "C�digo de usu�rio..: " << itu -> codigo+inCodigo << "\n";
		cout << "Nome...............: " << itu -> nome << "\n";
		cout << "Livro................: " << itu << "\n";
		cout << "Endere�o...........: " << itu -> endereco << "\n";
		cout << "Telefone...........: " << itu -> telefone << "\n";
		cout << "E-mail.............: " << itu -> email << "\n";
		cout << "Livros emprestados.: " << itu -> quantEmprestimos << "\n";
		cout << "\n------------------------------------------------\n\n";
		itu++;
	}
	cout << "Pressione enter para Voltar\n";
	cin >> enter;
	menuPrincipal();

}*/
//-------------------------------------------------------------------------------------------------------------
//VERIFICA��ES CADASTROS USERS/LIVROS
//-------------------------------------------------------------------------------------------------------------
void verificaUser(string a){
	itu = listaUser.begin();
	while(itu != listaUser.end()){
		if(itu -> cpf.compare(a) == 0){
			cout << "CPF j� cadastrado!\n\n";
			sleep(3);
			menuCadastros();
		}
		itu++;
	}
}
void verificaLivro(int a){
	itl = listaLivro.begin();
	while(itl != listaLivro.end()){
		if(itl -> ISBN == a){
			cout << "Livro j� cadastrado!\n\n";
			sleep(3);
			menuCadastros();
		}
		itl++;
	}
}
//-------------------------------------------------------------------------------------------------------------
//VERIFICA��ES CADASTROS EMPR�STIMOS/RESERVAS
//-------------------------------------------------------------------------------------------------------------
void verificaUserEmprestimo(int a){
	int certo = 0;
	itu = listaUser.begin();
	while(itu != listaUser.end()){
		if(itu -> codigo == a){
			certo = 1;
			break;
		}
		itu++;
	}
	if(certo == 0){
		cout << "C�digo de usu�rio inv�lido!";
		sleep(3);
		menuEmprestimos();
	}
}
void verificaLivroEmprestimo(int a){
	int certo = 0;
	itl = listaLivro.begin();
	while(itl != listaLivro.end()){
		if(itl -> codigo == a){
			certo = 1;
			break;
		}
		itl++;
	}
	if(certo == 0){
		cout << "C�digo de livro inv�lido!";
		sleep(3);
		menuEmprestimos();
	}
}
void verificaSenhaEmprestimo(int cod, string senha){
	itu = listaUser.begin();
	while(itu != listaUser.end()){
		if(itu -> codigo == cod){
			if(itu -> senha.compare(senha) == 0){
				break;
			}else{
				cout << "Senha incorreta!";
				sleep(3);
				menuEmprestimos();
			}
		}
		itu++;
	}
}
//-------------------------------------------------------------------------------------------------------------
//DATAS
//-------------------------------------------------------------------------------------------------------------
void passaDia(void){
	buscaMes();
	if(data.dia < data.idDias){
		data.dia += 1;
	}else if(data.mes < 12){
		data.mes += 1;
		data.dia = 1;
	}else{
		data.ano += 1;
		data.mes = 1;
		data.dia = 1;
	}
	//menuPrincipal();
}
void buscaMes(void){
	if(data.mes == 1 || data.mes == 3 || data.mes == 5 || data.mes == 7 || data.mes == 8 || data.mes == 10 || data.mes == 12){
		data.idDias = 31;
	}else if(data.mes == 4 || data.mes == 6 || data.mes == 9 || data.mes == 11){
		data.idDias = 30;
	}else{
		data.idDias = 28;
	}
}
void dataEmprestimo(int a){
	//list<User>::iterator it = listaUser.begin(); 
	
	int dia, mes, ano, i = 0;
	dia = data.dia;
	mes = data.mes;
	ano = data.ano;
	
	itu->emprestimo.dtEmp.dia = data.dia;
	itu->emprestimo.dtEmp.mes = data.mes;
	itu->emprestimo.dtEmp.ano = data.ano;
	
	while(i < 7){
		passaDia();
	}
	
	itu->emprestimo.dtDev.dia = data.dia;
	itu->emprestimo.dtDev.mes = data.mes;
	itu->emprestimo.dtDev.ano = data.ano;
	
	data.dia = dia;
	data.mes = mes;
	data.ano = ano;
}
//-------------------------------------------------------------------------------------------------------------
//APAGAR
//-------------------------------------------------------------------------------------------------------------
void deletaUser(void){
	system("clear");
	int cod;	
	cout << "-----DELETAR USU�RIO-----\n\n";
	cout << "C�digo do usu�rio..: ";
	cin >> cod; verificaDeletaUser(cod);
	
}
void verificaDeletaUser(int a){
	itu = listaUser.begin();
	int certo = 0;
	string sn;
	while(itu != listaUser.end()){
		if(itu -> codigo+100000 == a){
			certo = 1;
			break;
		}
		itu++;
	}
	if(certo == 1){
		cout << "Nome...............: " << itu -> nome << "\n";
		cout << "CPF................: " << itu -> cpf << "\n";
		cout << "Endere�o...........: " << itu -> endereco << "\n";
		cout << "Telefone...........: " << itu -> telefone << "\n";
		cout << "E-mail.............: " << itu -> email << "\n";
		cout << "Livros emprestados.: " << itu -> quantEmprestimos << "\n";
		cout << "\n------------------------------------------------\n\n";	
		cout << "Voc� tem certeza que deseja deletar o usu�rio do sistema?[s/n]\n";
		cin >> sn;
		while(sn.compare("s") != 0 || sn.compare("n") != 0){
			if(sn.compare("s") == 0){
				listaUser.erase(itu);
				cout << "Usu�rio deletado com sucesso!";
				sleep(3);
				menuPrincipal();	
			}else if(sn.compare("n") == 0){
				cout << "Dele��o cancelada!";
				sleep(3);
				menuPrincipal();			
			}else{
				system("clear");
				cout << "-----DELETAR USU�RIO-----\n\n";
				cout << "C�digo do usu�rio..: " << a << "\n";
				cout << "Nome...............: " << itu -> nome << "\n";
				cout << "CPF................: " << itu -> cpf << "\n";
				cout << "Endere�o...........: " << itu -> endereco << "\n";
				cout << "Telefone...........: " << itu -> telefone << "\n";
				cout << "E-mail.............: " << itu -> email << "\n";
				cout << "Livros emprestados.: " << itu -> quantEmprestimos << "\n";
				cout << "\n------------------------------------------------\n\n";	
				cout << "Comando inv�lido!\n";
				cout << "Voc� tem certeza que deseja deletar o livro do sistema?[s/n]\n";
				cin >> sn;
				
			}	
		}	
	}else{
		cout << "C�digo de usu�rio n�o registrado!";
		sleep(3);
		menuPrincipal();
	}
}

void deletaLivro(void){
	system("clear");
	int cod;	
	cout << "-----DELETAR LIVRO-----\n\n";
	cout << "C�digo do Livro......: ";
	cin >> cod; verificaDeletaLivro(cod);
}
void verificaDeletaLivro(int a){
	itl = listaLivro.begin();
	int certo = 0;
	string sn;
	while(itl != listaLivro.end()){
		if(itl -> codigo+100000 == a){
			certo = 1;
			break;
		}
		itl++;
	}
	if(certo == 1){
		cout << "Titulo...............: " << itl -> titulo << "\n";
		cout << "Autor(a).............: " << itl -> autor << "\n";
		cout << "Editora..............: " << itl -> editora << "\n";
		cout << "Local de Edi��o......: " << itl -> localEdicao << "\n";
		cout << "Ano..................: " << itl -> ano << "\n";
		cout << "C�digo ISBN..........: " << itl -> ISBN << "\n";
		cout << "Palavras Chaves......: " << itl -> palavrasChaves << "\n";
		cout << "N�mero de exemplares.: " << itl -> numExemplares << "\n";
		cout << "\n------------------------------------------------\n\n";	
		cout << "Voc� tem certeza que deseja deletar o livro do sistema?[s/n]\n";
		cin >> sn;
		while(sn.compare("s") != 0 || sn.compare("n") != 0){
			if(sn.compare("s") == 0){
				listaLivro.erase(itl);
				cout << "Livro deletado com sucesso!";
				sleep(3);
				menuPrincipal();	
			}else if(sn.compare("n") == 0){
				cout << "Dele��o cancelada!";
				sleep(3);
				menuPrincipal();			
			}else{
				system("clear");
				cout << "-----DELETAR LIVRO-----\n\n";
				cout << "C�digo do Livro......: " << a << "\n";
				cout << "Titulo...............: " << itl -> titulo << "\n";
				cout << "Autor(a).............: " << itl -> autor << "\n";
				cout << "Editora..............: " << itl -> editora << "\n";
				cout << "Local de Edi��o......: " << itl -> localEdicao << "\n";
				cout << "Ano..................: " << itl -> ano << "\n";
				cout << "C�digo ISBN..........: " << itl -> ISBN << "\n";
				cout << "Palavras Chaves......: " << itl -> palavrasChaves << "\n";
				cout << "N�mero de exemplares.: " << itl -> numExemplares << "\n";
				cout << "\n------------------------------------------------\n\n";	
				cout << "Comando inv�lido!\n";
				cout << "Voc� tem certeza que deseja deletar o livro do sistema?[s/n]\n";
				cin >> sn;
				
			}	
		}	
	}else{
		cout << "C�digo de livro n�o registrado!";
		sleep(3);
		menuPrincipal();
	}
}








