#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<iomanip>
#include <string.h>
#include<Windows.h>
#include <io.h>  
#include <fcntl.h> 
using namespace std;


//Шифр Цезаря — один из древнейших шифров.При шифровании каждый символ заменяется другим, 
// отстоящим от него в алфавите на фиксированное число позиций.
//Пример
//Шифрование с использованием ключа : 3
//Оригинальный текст : Съешь же ещё этих мягких французских булок, да выпей чаю.
//Шифрованный текст : Фэзыя йз зьи ахлш пвёнлш чугрщцкфнлш дцосн, жг еютзм ъгб.
//Дан текстовый файл.Зашифровать его, используя шифр Цезаря.
//Результат записать в другой файл.
//
//- создать функцию, которая меняет буквы с шагом 3 через цикл(1 до3)
//если символ равен я, то присваиваем а, если(так само для Я –А), иначе считаем символы.



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
		printf("Файл удачно открылся.\n");
		
		
		while (!feof(file1)) {			
			char buf_sumb = fgetc(file1);
			char sumb = Encryption(buf_sumb);

			fputc(sumb, file2);
			printf("%c", sumb);
			
		}
		cout << "Слова зашифрованы!" << endl;
		fclose(file1);
		fclose(file2);
	}
	else { cout << "Файл не открылся! " << endl; }
}