#include <windows.h>
#include <iostream>
#include <lesson/lesson.h>
#include <stdexcept>
#include <string>



using namespace std;

void menu() {
	system("cls");
	cout << "Что вы хотите сделать? Введите цифру от 1 до 6" << endl;
	cout << "1 - вставить элемент в список по указанному индексу" << endl;
	cout << "2 - удалить элемент из списка по указанному индексу" << endl;
	cout << "3 - вывести список на экран" << endl;
	cout << "4 - определение названия первой дисциплины с максимальным количеством оплачиваемых часов по всем занятиям" << endl;
	cout << "5 - вычисление полного количества оплачиваемых часов по заданному названию" << endl;
	cout << "6 - завершить программу" << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int s=0;
	int idx;
	int n;
	int m;
	int p;
	Lesson t = Lesson();
	LessonList f = LessonList();
	while (s != 6) {
		menu();
		cin >> s;
		switch (s)
		{
		case 1:
			system("cls");
			cout << "Ввведите индекс" << endl;
			cin >> idx;
			cin >> t;
			f.insert(idx, t);
			break;

		case 2:
			system("cls");
			cout << "Введите индекс удаляемого элемента" << endl;
			cin >> idx;
			f.remove(idx);
			break;
		case 3:
			system("cls");
			f.show_all();
			break;
		case 4:
			system("cls");
			cout << "Введите количество групп" << endl;
			cin >> n;
			cout << "Введите количество подгрупп" << endl;
			cin >> m;
			cout << "0-OOP, 1-Algebra, 2-Geometria" << endl;
			cout<<f.compute_max_paid(f,n,m) << endl;
			break;
		case 5:
			system("cls");
			cout << "Введите название предмета:0-OOP, 1-Algebra, 2-Geometria" << endl;
			cin >> p;
			cout << "Введите количество групп" << endl;
			cin >> n;
			cout << "Введите количество подгрупп" << endl;
			cin >> m;
			cout << f.compute_sum( f,n,m,p) << endl;
			break;
		}
		if (s != 6) {
			system("pause");
		}
	}
}
