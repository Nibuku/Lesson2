#include <windows.h>
#include <iostream>
#include <lesson/lesson.h>
#include <stdexcept>
#include <string>



using namespace std;

void menu() {
	system("cls");
	cout << "��� �� ������ �������? ������� ����� �� 1 �� 6" << endl;
	cout << "1 - �������� ������� � ������ �� ���������� �������" << endl;
	cout << "2 - ������� ������� �� ������ �� ���������� �������" << endl;
	cout << "3 - ������� ������ �� �����" << endl;
	cout << "4 - ����������� �������� ������ ���������� � ������������ ����������� ������������ ����� �� ���� ��������" << endl;
	cout << "5 - ���������� ������� ���������� ������������ ����� �� ��������� ��������" << endl;
	cout << "6 - ��������� ���������" << endl;
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
			cout << "�������� ������" << endl;
			cin >> idx;
			cin >> t;
			f.insert(idx, t);
			break;

		case 2:
			system("cls");
			cout << "������� ������ ���������� ��������" << endl;
			cin >> idx;
			f.remove(idx);
			break;
		case 3:
			system("cls");
			f.show_all();
			break;
		case 4:
			system("cls");
			cout << "������� ���������� �����" << endl;
			cin >> n;
			cout << "������� ���������� ��������" << endl;
			cin >> m;
			cout << "0-OOP, 1-Algebra, 2-Geometria" << endl;
			cout<<f.compute_max_paid(f,n,m) << endl;
			break;
		case 5:
			system("cls");
			cout << "������� �������� ��������:0-OOP, 1-Algebra, 2-Geometria" << endl;
			cin >> p;
			cout << "������� ���������� �����" << endl;
			cin >> n;
			cout << "������� ���������� ��������" << endl;
			cin >> m;
			cout << f.compute_sum( f,n,m,p) << endl;
			break;
		}
		if (s != 6) {
			system("pause");
		}
	}
}
