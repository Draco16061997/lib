//Цель: Разработать систему учета книг в библиотеке, используя ООП и стандартные средства работы с файлами в C++.
//
//Основные классы :
//
//Book - Класс, представляющий книгу.
//
//Поля : название, автор, год издания, ISBN, количество экземпляров.
//Методы : конструкторы, методы для доступа к полям, метод для вывода данных о книге в форматированном виде.
//
//Library - Класс для учета книг в библиотеке.
//Поля : список книг, путь к файлу каталога.
//Методы :
//    добавление книги;
//удаление книги по ISBN;
//поиск книги по названию, автору или ISBN;
//сохранение каталога в файл;
//загрузка каталога из файла;
//вывод всех книг.
//
//Функциональные требования :
//Программа должна предоставлять меню для :
//добавления новой книги;
//удаления книги;
//поиска книги;
//вывода списка всех книг;
//сохранения текущего каталога в файл;
//загрузки каталога из файла.
//
//Для сохранения и загрузки каталога используйте текстовый файл в следующем формате :
//[название] ; [автор] ; [год издания] ; [ISBN] ; [количество экземпляров]
//
//
//Пример
//Война и мир; Лев Толстой; 1869; 1234567890123; 3
//Мастер и Маргарита; Михаил Булгаков; 1967; 0987654321098; 5

#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;


class Book {
private:
	string title;
	string avtor;
	string data;
	int ISBN;
	int coun;

public:
	Book(string title, string avtor, string data, int ISBN, int coun) {
		this->title = title;
		this->avtor = avtor;
		this->data = data;
		this->ISBN = ISBN;
		this->coun = coun;
	}


	string getTitle() { return title; }
	string getAvtor() { return avtor; }
	string getData() { return data; }
	int getISBN() const { return ISBN; }
	int getCoun() { return coun; }

	void setTitle(string title) { this->title = title; }
	void setAvtor(string avtor) { this->avtor = avtor; }
	void setData(string data) { this->data = data; }
	void setISBN(int ISBN) { this->ISBN = ISBN; }
	void setCoun(int coun) { this->coun = coun; }

	void getInfo()
	{
		cout << "Name: " << title << " || " << "Avtor: " << avtor << " || " << "Data: " << data << " || " << "ISBN: " << ISBN << " || " << "Coun: " << coun << endl;
	}
};

//Library - Класс для учета книг в библиотеке.
//Поля : список книг, путь к файлу каталога.
//Методы :
//добавление книги; +
//удаление книги по ISBN;
//поиск книги по названию, автору или ISBN;+
//сохранение каталога в файл;+
//загрузка каталога из файла;+
//вывод всех книг.+

class Library {
private:
	vector<Book> books;
	string fileName = "lib.txt";

public:
	void RewritingFile() {
		ofstream file(fileName, ios::trunc);

		if (file.is_open()) {
			cout << "File is ReWriting " << endl;
			file.close();
		}


	}

	void addToLibrary(Book book, bool appendIsFile = false) {
		books.push_back(book);
		cout << " appendet" << endl;
		if (appendIsFile) { AppendToFile(book); }
	}

	void getLibraryInfo() {
		for (int i = 0; i < books.size(); i++) {
			books[i].getInfo();
		}
	}

	void AppendToFile(Book book) {
		ofstream Append;
		Append.open(fileName, ios_base::app);
		//Война и мир; Лев Толстой; 1869; 1234567890123; 3
		//Мастер и Маргарита; Михаил Булгаков; 1967; 0987654321098; 5
		Append << book.getTitle() << "; " << book.getAvtor() << "; " << book.getData() << "; " << book.getISBN() << "; " << book.getCoun()<<";" << endl;
		cout << "file appendet" << endl;
		Append.close();
	}
	
	void ReadFromFile() {
		books.clear();

		ifstream in(fileName);
		string line;
		size_t pos;

		

		while (getline(in, line))
			{

			
			vector<string> subline;

			while (line.find(";") != string::npos)
			{
				string str = line.substr(0, line.find(";"));
				
				str.erase(0,1);
				subline.push_back(str);
				line.erase(0, line.find(";")+1);
			}
		
			Book book{ subline[0], subline[1], subline[2], stoi(subline[3]), stoi(subline[4]) };
			books.push_back(book);
			}

		in.close();

	}

	void findBookTitle(string Title){
		vector<Book> FindNames;
		for (int i = 0; i < books.size(); i++) {
			if (books[i].getTitle() == Title) {
				FindNames.push_back(books[i]);
			}
		}

		for (int i = 0; i < FindNames.size(); i++) {
			FindNames[i].getInfo();
		}
	}

	void findBookAvtor(string Avtor) {
		vector<Book> FindNames;
		for (int i = 0; i < books.size(); i++) {
			if (books[i].getAvtor() == Avtor) {
				FindNames.push_back(books[i]);
			}
		}

		for (int i = 0; i < FindNames.size(); i++) {
			FindNames[i].getInfo();
		}
	}

	void findBookISBN(int ISBN) {
		vector<Book> FindNames;
		for (int i = 0; i < books.size(); i++) {
			if (books[i].getISBN() == ISBN) {
				FindNames.push_back(books[i]);
			}
		}

		for (int i = 0; i < FindNames.size(); i++) {
			FindNames[i].getInfo();
		}
	}

	void removeBook(int ISBN){}
};








void main() {


	Book book{ "Jamala", "Jack London", "1869", 6543246, 46 };
	Book book2{ "harison","Victorios", "1909",34534, 456 };
	
	Library lib;
	

	lib.ReadFromFile();

	//lib.getLibraryInfo();
	//cout << book.getAvtor();

	//lib.findBookISBN(1);
	lib.findBookAvtor("Jack London");
	//lib.findBookTitle("Jamala");

	
	
	


}
