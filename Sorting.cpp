#include <iostream>
#include <ctime>
#include "HeaderOfSorting.h"

void answerLH(int *answer)
{
	std::cout << "Сортировку выполнить в порядке убывания/возрастания - 1/2" << std::endl;
	std::cin >> *answer;
	while (*answer != 1 && *answer != 2)
	{
		proverka(&*answer);
	}
}

void questionOfFill(int* questionOfFilling)
{
	std::cin >> *questionOfFilling;
	while (*questionOfFilling != 1 && *questionOfFilling != 2)
	{
		proverka(*&questionOfFilling);
	}
}

void getValue(int* lenght)//получаю количество эл-тов + проверяю на их правильность
{
	std::cout << "Сколько элeментов в массиве?" << std::endl;
	std::cin >> *lenght;
	while (std::cin.fail())
	{
		proverka(*&lenght);
	}
}

int main()
{
	setlocale(LC_ALL, "rus");//русский текст

	int lenght;//получаю и проверяю колчиство элементов в массиве
	getValue(&lenght);

	double* array = new double[lenght];//создаю массив длинной lenght

	std::cout << "Вы сами введете данные? Да/нет - 1/2" << std::endl;//Вопрос про автоматический или ручной ввод данных
	int questionOfFilling;
	questionOfFill(&questionOfFilling);

	fillingTheArray(&lenght, array, &questionOfFilling);//заполняю массив

	int answer;//спрашиваю про убывание или возрастание
	answerLH(&answer);

	std::cout << "Какую сортировку желаете выполнить?\n1 - сортировка пузырьком\n2 - сортировка выбором\n3 - сортировка слиянием" << std::endl;
	int questofsort;
	std::cin >> questofsort;
	while (questofsort != 1 && questofsort != 2 && questofsort != 3)
		proverka(&questofsort);

	double time_1 = 0., time_2 = 0.;

	if (questofsort == 1){
		time_1 = clock();
		SortOfBubble(array, &answer, &lenght);//сортировка пузырьком
		time_2 = clock();
}
	else if (questofsort == 2){
		time_1 = clock();
		SortOfChoice(array, &answer, &lenght);//сортировка выбором
		time_2 = clock();
	}
	else {
		time_1 = clock();
		FirstMergeSort(array, 0, lenght - 1, lenght);//сортировка вставками
		time_2 = clock();
	}

	if (lenght < 1000) {
		for (int count = 0; count < lenght; ++count)//вывод данных
			std::cout << array[count] << " ";
	}
	
	double overall_time = time_2 - time_1;
	std::cout << "\nВремя выполнения сортировки = " << overall_time / 1000 << " секунд." << std::endl;

	delete[] array;
	array = nullptr;
	return 0;
}

