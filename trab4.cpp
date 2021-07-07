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
	Data dtEmp, dtDev;
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

int i;

void passaDia(void);
void buscaMes(void);
void dataEmprestimo(int a);

void menuPrincipal(void);
void menuCadastros(void);
void menuEmprestimos(void);
void menuEditar(void);

void cadastroUser(void);
void cadastroLivro(void);

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

void editaUser(void);
void verificaUserEditar(int a);
void editaLivro(void);
void verificaLivroEditar(int a);

void imprime();

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
	cout << "[2] Empréstimos\n";
	cout << "[3] Editar\n";
	cout << "[4] Lista de Usuários\n";
	cout << "[5] Lista de Livros\n";
	cout << "[6] Deletar Usuário\n";
	cout << "[7] Deletar Livro\n";
	cout << "[8] Sair\n";
    cout << "[9] Ordenar lista\n";
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
			menuEditar();
			break;
		case 4:
			listaUsers();
			break;
		case 5:
			listaLivros();
			break;	
		case 6:
			deletaUser();
			break;
		case 7:
			deletaLivro();
			break;
        case 9:
            imprime();
            break;
		case 8:
			cout << "";
			break;
		default:
			cout << "Comando Inválido!";
			sleep(3);
			menuPrincipal();
	}
}
void menuCadastros(void){
	system("clear");
	cout << "-----Cadastros-----\n\n";
	cout << "[1] Usuário\n";
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
			cout << "Comando Inválido!";
			sleep(3);
			menuCadastros();
	}
}
void menuEmprestimos(void){
	system("clear");
	cout << "-----Empréstimos-----\n\n";
	cout << "[1] Registrar empréstimo\n";
	cout << "[2] Registrar reserva\n";
	cout << "[3] Voltar\n";
	cin >> op;
	
	switch(op){
		case 1:
			//cadastroEmprestimo();
		case 2:
			cadastroReserva();
		case 3:
			menuPrincipal();
		default:
			cout << "Comando Inválido!";
			sleep(3);
			menuCadastros();
	}
}
void menuEditar(void){
	system("clear");
	cout << "-----EDITAR-----\n\n";
	cout << "[1] Usuário\n";
	cout << "[2] Livro\n";
	cout << "[3] Voltar\n";
	cin >> op;
	
	switch(op){
		case 1:
			editaUser();
		case 2:
			editaLivro();
		case 3:
			menuPrincipal();
		default:
			cout << "Comando Inválido!";
			sleep(3);
			menuCadastros();
	}
}
//-------------------------------------------------------------------------------------------------------------
//CADASTROS USUÁRIOS/LIVROS
//-------------------------------------------------------------------------------------------------------------
void cadastroUser(void){
	system("clear");
	User user;
	cout << "-----CADASTRO DE USUÁRIOS-----\n\n";
	cout << "CPF...............: "; cin >> user.cpf;setbuf(stdin,NULL);verificaUser(user.cpf); 
	cout << "Nome..............: "; getline(cin, user.nome);
	cout << "Endereço..........: "; getline(cin, user.endereco);
	cout << "Telefone..........: "; getline(cin, user.telefone);
	cout << "E-mail............: "; getline(cin, user.email);
	cout << "Senha.............: "; getline(cin, user.senha); user.codigo = listaUser.size() + 1; 
	cout << "Código de usuário.: " << user.codigo+inCodigo;
	
	listaUser.push_back(user);
	cout << "\n\nNovo usuário cadastrado com sucesso!";
	sleep(3);
	menuCadastros();
}
void cadastroLivro(void){
	system("clear");
	Livro livro;
	cout << "-----CADASTRO DE LIVROS-----\n\n";
	cout << "Código ISBN..........: "; cin >> livro.ISBN;setbuf(stdin,NULL);verificaLivro(livro.ISBN);
	cout << "Título...............: "; getline(cin, livro.titulo); 
	cout << "Autor................: "; getline(cin, livro.autor); 
	cout << "Editora..............: "; getline(cin, livro.editora); 
	cout << "Local de edicação....: "; getline(cin, livro.localEdicao); 
	cout << "Ano..................: "; cin >> livro.ano;setbuf(stdin,NULL);
	cout << "Número de exemplares.: "; cin >> livro.numExemplares;setbuf(stdin,NULL);
	cout << "Palavras chaves......: "; getline(cin, livro.palavrasChaves); livro.codigo = listaLivro.size() + 1;
	cout << "Código do livro......: " << livro.codigo+inCodigo;
	
	listaLivro.push_back(livro);
	cout << "\n\nNovo livro cadastrado com sucesso!";
	sleep(3);
	menuCadastros();
}
//-------------------------------------------------------------------------------------------------------------
//CADASTROS EMPRÉSTIMOS/RESERVAS
//-------------------------------------------------------------------------------------------------------------
void cadastroReserva(void){
	cout << "salve";
}
//-------------------------------------------------------------------------------------------------------------
//LISTAGEM
//-------------------------------------------------------------------------------------------------------------
void listaUsers(void){
	system("clear");
	cout << "-----LISTAGEM DE USUÁRIOS-----\n\n";
	itu = listaUser.begin();
	while(itu != listaUser.end()){
		cout << "Código de usuário..: " << itu -> codigo+inCodigo << "\n";
		cout << "Nome...............: " << itu -> nome << "\n";
		cout << "CPF................: " << itu -> cpf << "\n";
		cout << "Endereço...........: " << itu -> endereco << "\n";
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
		cout << "Código do Livro......: " << itl -> codigo+inCodigo << "\n";
		cout << "Titulo...............: " << itl -> titulo << "\n";
		cout << "Autor(a).............: " << itl -> autor << "\n";
		cout << "Editora..............: " << itl -> editora << "\n";
		cout << "Local de Edição......: " << itl -> localEdicao << "\n";
		cout << "Ano..................: " << itl -> ano << "\n";
		cout << "Código ISBN..........: " << itl -> ISBN << "\n";
		cout << "Palavras Chaves......: " << itl -> palavrasChaves << "\n";
		cout << "Número de exemplares.: " << itl -> numExemplares << "\n";
		cout << "\n------------------------------------------------\n\n";
		itl++;
	}
	cout << "Pressione enter para Voltar\n";
	cin >> enter;
	menuPrincipal();
	
}
//-------------------------------------------------------------------------------------------------------------
//VERIFICAÇÕES CADASTROS USERS/LIVROS
//-------------------------------------------------------------------------------------------------------------
void verificaUser(string a){
	itu = listaUser.begin();
	while(itu != listaUser.end()){
		if(itu -> cpf.compare(a) == 0){
			cout << "CPF já cadastrado!\n\n";
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
			cout << "Livro já cadastrado!\n\n";
			sleep(3);
			menuCadastros();
		}
		itl++;
	}
}
//-------------------------------------------------------------------------------------------------------------
//VERIFICAÇÕES CADASTROS EMPRÉSTIMOS/RESERVAS
//-------------------------------------------------------------------------------------------------------------
void verificaUserEmprestimo(int a){
	int certo = 0;
	itu = listaUser.begin();
	while(itu != listaUser.end()){
		if(itu -> codigo+inCodigo == a){
			certo = 1;
			break;
		}
		itu++;
	}
	if(certo == 0){
		cout << "Código de usuário inválido!";
		sleep(3);
		menuEmprestimos();
	}
}
void verificaLivroEmprestimo(int a){
	int certo = 0;
	itl = listaLivro.begin();
	while(itl != listaLivro.end()){
		if(itl -> codigo+inCodigo == a){
			certo = 1;
			break;
		}
		itl++;
	}
	if(certo == 0){
		cout << "Código de livro inválido!";
		sleep(3);
		menuEmprestimos();
	}
}
void verificaSenhaEmprestimo(int cod, string senha){
	itu = listaUser.begin();
	while(itu != listaUser.end()){
		if(itu -> codigo+inCodigo == cod){
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
	menuPrincipal();
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

//-------------------------------------------------------------------------------------------------------------
//DELETAR
//-------------------------------------------------------------------------------------------------------------
void deletaUser(void){
	system("clear");
	int cod;	
	cout << "-----DELETAR USUÁRIO-----\n\n";
	cout << "Código do usuário..: ";
	cin >> cod; verificaDeletaUser(cod);
	
}
void verificaDeletaUser(int a){
	itu = listaUser.begin();
	int certo = 0;
	string sn;
	while(itu != listaUser.end()){
		if(itu -> codigo+inCodigo == a){
			certo = 1;
			break;
		}
		itu++;
	}
	if(certo == 1){
		cout << "Nome...............: " << itu -> nome << "\n";
		cout << "CPF................: " << itu -> cpf << "\n";
		cout << "Endereço...........: " << itu -> endereco << "\n";
		cout << "Telefone...........: " << itu -> telefone << "\n";
		cout << "E-mail.............: " << itu -> email << "\n";
		cout << "Livros emprestados.: " << itu -> quantEmprestimos << "\n";
		cout << "\n------------------------------------------------\n\n";	
		cout << "Você tem certeza que deseja deletar o usuário do sistema?[s/n]\n";
		cin >> sn;
		while(sn.compare("s") != 0 || sn.compare("n") != 0){
			if(sn.compare("s") == 0){
				listaUser.erase(itu);
				cout << "Usuário deletado com sucesso!";
				sleep(3);
				menuPrincipal();	
			}else if(sn.compare("n") == 0){
				cout << "Deleção cancelada!";
				sleep(3);
				menuPrincipal();			
			}else{
				system("clear");
				cout << "-----DELETAR USUÁRIO-----\n\n";
				cout << "Código do usuário..: " << a << "\n";
				cout << "Nome...............: " << itu -> nome << "\n";
				cout << "CPF................: " << itu -> cpf << "\n";
				cout << "Endereço...........: " << itu -> endereco << "\n";
				cout << "Telefone...........: " << itu -> telefone << "\n";
				cout << "E-mail.............: " << itu -> email << "\n";
				cout << "Livros emprestados.: " << itu -> quantEmprestimos << "\n";
				cout << "\n------------------------------------------------\n\n";	
				cout << "Comando inválido!\n";
				cout << "Você tem certeza que deseja deletar o livro do sistema?[s/n]\n";
				cin >> sn;
				
			}	
		}	
	}else{
		cout << "Código de usuário não registrado!";
		sleep(3);
		menuPrincipal();
	}
}

void deletaLivro(void){
	system("clear");
	int cod;	
	cout << "-----DELETAR LIVRO-----\n\n";
	cout << "Código do Livro......: ";
	cin >> cod; verificaDeletaLivro(cod);
}
void verificaDeletaLivro(int a){
	itl = listaLivro.begin();
	int certo = 0;
	string sn;
	while(itl != listaLivro.end()){
		if(itl -> codigo+inCodigo == a){
			certo = 1;
			break;
		}
		itl++;
	}
	if(certo == 1){
		cout << "Titulo...............: " << itl -> titulo << "\n";
		cout << "Autor(a).............: " << itl -> autor << "\n";
		cout << "Editora..............: " << itl -> editora << "\n";
		cout << "Local de Edição......: " << itl -> localEdicao << "\n";
		cout << "Ano..................: " << itl -> ano << "\n";
		cout << "Código ISBN..........: " << itl -> ISBN << "\n";
		cout << "Palavras Chaves......: " << itl -> palavrasChaves << "\n";
		cout << "Número de exemplares.: " << itl -> numExemplares << "\n";
		cout << "\n------------------------------------------------\n\n";	
		cout << "Você tem certeza que deseja deletar o livro do sistema?[s/n]\n";
		cin >> sn;
		while(sn.compare("s") != 0 || sn.compare("n") != 0){
			if(sn.compare("s") == 0){
				listaLivro.erase(itl);
				cout << "Livro deletado com sucesso!";
				sleep(3);
				menuPrincipal();	
			}else if(sn.compare("n") == 0){
				cout << "Deleção cancelada!";
				sleep(3);
				menuPrincipal();			
			}else{
				system("clear");
				cout << "-----DELETAR LIVRO-----\n\n";
				cout << "Código do Livro......: " << a << "\n";
				cout << "Titulo...............: " << itl -> titulo << "\n";
				cout << "Autor(a).............: " << itl -> autor << "\n";
				cout << "Editora..............: " << itl -> editora << "\n";
				cout << "Local de Edição......: " << itl -> localEdicao << "\n";
				cout << "Ano..................: " << itl -> ano << "\n";
				cout << "Código ISBN..........: " << itl -> ISBN << "\n";
				cout << "Palavras Chaves......: " << itl -> palavrasChaves << "\n";
				cout << "Número de exemplares.: " << itl -> numExemplares << "\n";
				cout << "\n------------------------------------------------\n\n";	
				cout << "Comando inválido!\n";
				cout << "Você tem certeza que deseja deletar o livro do sistema?[s/n]\n";
				cin >> sn;
				
			}	
		}	
	}else{
		cout << "Código de livro não registrado!";
		sleep(3);
		menuPrincipal();
	}
}
//-------------------------------------------------------------------------------------------------------------
//EDITAR
//-------------------------------------------------------------------------------------------------------------
void editaUser(void){
	    system("clear");
		cout << "-----------Editar Usuário-----------\n\n";
		int cod;
		cout << "Código de usuário..: ";
		cin >> cod; verificaUserEditar(cod);	
		cout << "\n------------------------------------------------\n\n";	
		cout << "[1] Nome...............: " << itu -> nome << "\n";
		cout << "[2] CPF................: " << itu -> cpf << "\n";
		cout << "[3] Endereço...........: " << itu -> endereco << "\n";
		cout << "[4] Telefone...........: " << itu -> telefone << "\n";
		cout << "[5] E-mail.............: " << itu -> email << "\n";
		cout << "[6] Senha..............: ****";
		cout << "\n------------------------------------------------\n\n";
		cout << "Selecione o que deseja editar\n\n";
		cin >> op;
		
		switch(op){
			case 1:
				system("clear");
				cout << "-----------Editar Usuário-----------\n\n";
				cout << "Nome...............: ";
				cin.ignore();getline(cin, itu -> nome);
				cout <<"Registro Salvo com sucesso";
				sleep(3);
				menuEditar();
				break;
			case 2:
				system("clear");
				cout << "-----------Editar Usuário-----------\n\n";
				cout << "CPF................: ";
				cin.ignore();getline(cin, itu -> cpf);
				cout <<"Registro Salvo com sucesso";
				sleep(3);
				menuEditar();
				break;
			case 3:
				system("clear");
				cout << "-----------Editar Usuário-----------\n\n";
				cout << "Endereço...........: ";
				cin.ignore();getline(cin, itu -> endereco);
				cout << "Registro Salvo com sucesso";
				sleep(3);
				menuEditar();
				break;
			case 4:
				system("clear");
				cout << "-----------Editar Usuário-----------\n\n";
				cout << "Telefone...........: ";
				cin.ignore();getline(cin, itu -> telefone);
				cout <<"Registro Salvo com sucesso";
				sleep(3);
				menuEditar();
				break;
			case 5:
				system("clear");
				cout << "-----------Editar Usuário-----------\n\n";
				cout << "E-mail.............: ";
				cin.ignore();getline(cin, itu -> email);
				cout <<"Registro Salvo com sucesso";
				sleep(3);
				menuEditar();
				break;
			case 6: 
				system("clear");
				cout << "-----------Editar Usuário-----------\n\n";
				cout << "Senha..............: ";
				cin.ignore();getline(cin, itu -> senha);
				cout <<"Registro Salvo com sucesso";
				sleep(3);
				menuEditar();
				break;
			default:
				cout <<"Comando Inválido!";
				sleep(3);
				menuEditar();
				break;	
				
		}
		
}

void verificaUserEditar(int a){
	int certo = 0;
	itu = listaUser.begin();
	while(itu != listaUser.end()){
		if(itu -> codigo+inCodigo == a){
			certo = 1;
			break;
		}
		itu++;
	}
	if(certo == 0){
		cout << "Código de usuário inválido!";
		sleep(3);
		menuEditar();
	}
}

void editaLivro(void){
	system("clear");
		cout << "-----------Editar Livro-----------\n\n";
		int cod;
		cout << "Código de livro..........: ";
		cin >> cod; verificaLivroEditar(cod);	
		cout << "\n------------------------------------------------\n\n";	
		cout << "[1] Titulo...............: " << itl -> titulo << "\n";
		cout << "[2] Autor(a).............: " << itl -> autor << "\n";
		cout << "[3] Editora..............: " << itl -> editora << "\n";
		cout << "[4] Local de Edição......: " << itl -> localEdicao << "\n";
		cout << "[5] Ano..................: " << itl -> ano << "\n";
		cout << "[6] Código ISBN..........: " << itl -> ISBN << "\n";
		cout << "[7] Palavras Chaves......: " << itl -> palavrasChaves << "\n";
		cout << "[8] Número de exemplares.: " << itl -> numExemplares << "\n";
		cout << "\n------------------------------------------------\n\n";
		cout << "Selecione o que deseja editar\n\n";
		cin >> op;
		
		switch(op){
			case 1:
				system("clear");
				cout << "-----------Editar Livro-----------\n\n";
				cout << "Titulo...............: ";
				cin.ignore();getline(cin, itl -> titulo);
				cout <<"Registro Salvo com sucesso";
				sleep(3);
				menuEditar();
				break;
			case 2:
				system("clear");
				cout << "-----------Editar Livro-----------\n\n";
				cout << "Autor(a).............: ";
				cin.ignore();getline(cin, itl -> autor);
				cout <<"Registro Salvo com sucesso";
				sleep(3);
				menuEditar();
				break;
			case 3:
				system("clear");
				cout << "-----------Editar Livro-----------\n\n";
				cout << "Editora..............: ";
				cin.ignore();getline(cin, itl -> editora);
				cout <<"Registro Salvo com sucesso";
				sleep(3);
				menuEditar();
				break;
			case 4:
				system("clear");
				cout << "-----------Editar Livro-----------\n\n";
				cout << "Local de Edição......: ";
				cin.ignore();getline(cin, itl -> localEdicao);
				cout <<"Registro Salvo com sucesso";
				sleep(3);
				menuEditar();
				break;
			case 5:
				system("clear");
				cout << "-----------Editar Livro-----------\n\n";
				cout << "Ano..................: ";
				cin >> itl -> ano;setbuf(stdin,NULL);
				cout <<"Registro Salvo com sucesso";
				sleep(3);
				menuEditar();
				break;
			case 6:
				system("clear");
				cout << "-----------Editar Livro-----------\n\n";
				cout << "Código ISBN..........: ";
				cin >> itl -> ISBN;setbuf(stdin,NULL);
				cout <<"Registro Salvo com sucesso";
				sleep(3);
				menuEditar();
				break;
			case 7:
				system("clear");
				cout << "-----------Editar Livro-----------\n\n";
				cout << "Palavras Chaves......: ";
				cin.ignore();getline(cin, itl -> palavrasChaves);
				cout <<"Registro Salvo com sucesso";
				sleep(3);
				menuEditar();
				break;
			case 8:
				system("clear");
				cout << "-----------Editar Livro-----------\n\n";
				cout << "Número de exemplares.: ";
				cin >> itl -> numExemplares;setbuf(stdin,NULL);
				cout <<"Registro Salvo com sucesso";
				sleep(3);
				menuEditar();
				break;
			default:
				cout <<"Comando Inválido!";
				sleep(3);
				menuEditar();
				break;		
				
		}
		
}

void verificaLivroEditar(int a){
	int certo = 0;
	itl = listaLivro.begin();
	while(itl != listaLivro.end()){
		if(itl -> codigo+inCodigo == a){
			certo = 1;
			break;
		}
		itl++;
	}
	if(certo == 0){
		cout << "Código de livro inválido!";
		sleep(3);
		menuEditar();
     
	}
}

int buscatam(){
    int tam = listaLivro.size();
    return tam;
}



void imprime(){
    int a= buscatam();
    string titulos[a]; 
    itl = listaLivro.begin();
	while(itl != listaLivro.end()){
        for(i=0;i<listaLivro.size();i++){
            titulos[i]=itl->titulo;
        }
        itl++;
    }
    for(i=0;i<listaLivro.size();i++){
       cout << titulos[i]<<"\n";
   }
}





