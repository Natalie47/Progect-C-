#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<iomanip>
#include <string.h>
#include<Windows.h>
#include <io.h>  
#include <fcntl.h> 
using namespace std;


//���� ������ � ���� �� ���������� ������.��� ���������� ������ ������ ���������� ������, 
// ��������� �� ���� � �������� �� ������������� ����� �������.
//������
//���������� � �������������� ����� : 3
//������������ ����� : ����� �� ��� ���� ������ ����������� �����, �� ����� ���.
//����������� ����� : ����� �� ��� ���� ����� ����������� �����, �� ����� ���.
//��� ��������� ����.����������� ���, ��������� ���� ������.
//��������� �������� � ������ ����.
//
//- ������� �������, ������� ������ ����� � ����� 3 ����� ����(1 ��3)
//���� ������ ����� �, �� ����������� �, ����(��� ���� ��� � ��), ����� ������� �������.



char Encryption(char buf_sumb) {
	for (int i = 1; i <= 3; i++)
	{
		if (buf_sumb == 'z') { 
			buf_sumb = 'a'; 
		}
		else { 
			buf_sumb++; 
		}
	}
	return buf_sumb;
}







int main() {
	setlocale(LC_ALL, "rus");
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);

	FILE* file1, * file2;

	char buf_sumb[128];
	

	if (fopen_s(&file1, "file1.txt", "r") == NULL && fopen_s(&file2, "file2.txt", "w") == NULL) {
		printf("���� ������ ��������.\n");
		
		
		while (!feof(file1)) {			
			char buf_sumb = fgetc(file1);
			char sumb = Encryption(buf_sumb);

			fputc(sumb, file2);
			printf("%c", sumb);
			
		}
		cout << "����� �����������!" << endl;
		fclose(file1);
		fclose(file2);
	}
	else { cout << "���� �� ��������! " << endl; }
}