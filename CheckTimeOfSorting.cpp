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

	int lenght[] = { 10000, 20000,30000,40000,50000, 60000 , 70000 , 80000 , 90000 , 100000, 110000, 120000, 130000, 140000, 150000, 160000, 170000, 180000, 190000, 200000 };//количество элементов
	for (int count_M = 0; count_M < 20; count_M++) {//цикл, который прогоняет все N-ки
		std::cout << lenght[count_M] << std::endl;
		double* array = new double[lenght[count_M]];//создаю массив длинной lenght

		int questionOfFilling = 2;

		fillingTheArray(&lenght[count_M], array, &questionOfFilling);//заполняю массив

		int answer = 1;//спрашиваю про убывание или возрастание

		int questofsort = 1; // какая сортировка выполняется: 1 - пузырьком, 2 - вставками, 3 - слияние


		double time_1 = 0., time_2 = 0.;

		if (questofsort == 1) {
			time_1 = clock();
			SortOfBubble(array, &answer, &lenght[count_M]);//сортировка пузырьком
			time_2 = clock();
		}
		else if (questofsort == 2) {
			time_1 = clock();
			SortOfChoice(array, &answer, &lenght[count_M]);//сортировка выбором
			time_2 = clock();
		}
		else {
			time_1 = clock();
			FirstMergeSort(array, 0, lenght[count_M] - 1, lenght[count_M]);//сортировка вставками
			time_2 = clock();
		}

		if (lenght[count_M] < 1000) {
			for (int count = 0; count < lenght[count_M]; ++count)//вывод данных
				std::cout << array[count] << " ";
		}

		double overall_time = time_2 - time_1;
		std::cout << "\nВремя выполнения сортировки = " << overall_time / 1000 << " секунд." << std::endl;

		delete[] array;
		array = nullptr;
	}
	return 0;
}

