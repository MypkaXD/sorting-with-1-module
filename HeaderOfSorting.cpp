#include <iostream>

void SortOfChoice(double* array, int* answer, int* lenght)
{
	for (int startIndex = 0; startIndex < *lenght - 1; ++startIndex)
	{
		int smallestIndex = startIndex;
		for (int curretIndex = startIndex + 1; curretIndex < *lenght; ++curretIndex)
		{
			if (*answer == 1)
			{
				if (array[curretIndex] > array[smallestIndex])
					smallestIndex = curretIndex;
			}
			else if (*answer == 2)
			{
				if (array[curretIndex] < array[smallestIndex])
					smallestIndex = curretIndex;
			}
		}
		double temp = array[startIndex];
		array[startIndex] = array[smallestIndex];
		array[smallestIndex] = temp;
	}
}

#include <iostream>

void SortOfBubble(double* array, int* answer, int* lenght)
{
	for (int startIndex = 1; startIndex < *lenght; ++startIndex)
	{
		for (int curretIndex = 0; curretIndex < *lenght - 1; ++curretIndex)
		{
			if (*answer == 1)
			{
				if (array[curretIndex] < array[startIndex])
				{
					double temp = array[startIndex];
					array[startIndex] = array[curretIndex];
					array[curretIndex] = temp;
				}
			}
			if (*answer == 2)
			{
				if (array[curretIndex] > array[startIndex])
				{
					double temp = array[startIndex];
					array[startIndex] = array[curretIndex];
					array[curretIndex] = temp;
				}
			}
		}
	}
}

#include <iostream>

void fillingTheArray(int* lenght, double*& array, int* questionOfFilling)
{
	if (*questionOfFilling == 1)
	{
		for (int count = 0; count < *lenght; ++count)
		{
			std::cout << "a[" << count << "] " << "= ";
			std::cin >> array[count];
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				std::cout << "Что-то пошло не так, попробуйте заново" << std::endl;
				std::cout << "a[" << count << "] " << "= ";
				std::cin >> array[count];
			}
		}
	}
	else if (*questionOfFilling == 2)
	{
		srand(static_cast<int>(time(0)));
		for (int count = 0; count < *lenght; ++count)
			array[count] = rand();
	}
}

#include <iostream>

void proverka(int* x)
{
	std::cin.clear();
	std::cin.ignore(32767, '\n');
	std::cout << "Введите значение повторно:";
	std::cin >> *x;
}

#include <iostream>


void SecondMerg(double* array, int begin, int end, int lenght)
{
	int i = begin;
	int mid = begin + (end - begin) / 2;
	int j = mid + 1;
	int k = 0;
	double* arr = new double[lenght];
	while (i <= mid && j <= end)
	{
		if (array[i] <= array[j])
		{
			arr[k] = array[i];
			i++;
		}
		else
		{
			arr[k] = array[j];
			j++;
		}
		k++;
	}
	while (i <= mid)
	{
		arr[k] = array[i];
		i++;
		k++;
	}
	while (j <= end)
	{
		arr[k] = array[j];
		j++;
		k++;
	}
	for (int count = 0; count < k; count++)
	{
		array[begin + count] = arr[count];
	}
	delete[] arr;
	arr = nullptr;
}

void FirstMergeSort(double* array, int left, int right, int lenght)
{
	double temp;
	if (left < right)
	{
		if (left - right == 1)
		{
			if (array[left] > array[right])
			{
				temp = array[left];
				array[left] = array[right];
				array[right] = temp;
			}
		}
		else
		{
			FirstMergeSort(array, left, left + (right - left) / 2, lenght);
			FirstMergeSort(array, left + (right - left) / 2 + 1, right, lenght);
			SecondMerg(array, left, right, lenght);
		}
	}
}