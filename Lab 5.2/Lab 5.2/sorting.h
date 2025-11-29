#ifndef SORTING_H
#define SORTING_H

template <typename T>
void quickSort(T* array, int left, int right, int& count_srav, int& count_perem) {
	if (left > right) return;
	T p = array[(left + right) / 2];
	int i = left;
	int j = right;
	while (i <= j) {
		while (array[i] < p) {
			i++;
			count_srav++;
		}

		count_srav++;
		while (array[j] > p) {
			j--;
			count_srav++;
		}
		if (i <= j) {
			if (array[i] != array[j]) {
				T tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				count_perem ++;
			}
			i++;
			j--;
		}
	}
	quickSort(array, i, right, count_srav, count_perem);
	quickSort(array, left, j, count_srav, count_perem);
}

void quickSort(int* array, int left, int right, int& count_srav, int& count_perem) {
	quickSort<int>(array, left, right, count_srav, count_perem);
}

void quickSort(char* array, int left, int right, int& count_srav, int& count_perem) {
	quickSort<char>(array, left, right, count_srav, count_perem);
}

void quickSort(double* array, int left, int right, int& count_srav, int& count_perem) {
	quickSort<double>(array, left, right, count_srav, count_perem);
}

void quickSort(float* array, int left, int right, int& count_srav, int& count_perem) {
	quickSort<float>(array, left, right, count_srav, count_perem);
}

template <typename T>
int binarySearch(T* array, int length, int i, int& count_srav) {
	int mid = i / 2;
	int key = mid;
	if (array[i] > array[mid]) {
		while (key < i) {
			key++;
			count_srav++;
			if(array[i] < array[mid]) {
				return key;
			}
		}
		return i;
	}
	else if(array[i] < array[mid]) {
		while (key > 0) {
			key--;
			count_srav++;
			if (array[i] > array[mid]) {
				return key + 1;
			}
		}
		return 0;
	}
	else {
		return key + 1;
	}
}

template <typename T>
void binarySort(T* array, int length, int& count_srav, int& count_perem) {
	T tmp = 0;
	for (int i = 1; i < length; i++) {
		int key = binarySearch(array, length, i, count_srav);
		tmp = array[i];
		if (key != i) {
			for (int j = i; j > key; j--) {
				array[j] = array[j - 1];
				count_perem++;
			}
			array[key] = tmp;
			count_perem++;
		}
	}
}

void binarySort(int* array, int left, int right, int& count_srav, int& count_perem) {
	quickSort<int>(array, left, right, count_srav, count_perem);
}

void binarySort(char* array, int left, int right, int& count_srav, int& count_perem) {
	quickSort<char>(array, left, right, count_srav, count_perem);
}

void binarySort(double* array, int left, int right, int& count_srav, int& count_perem) {
	quickSort<double>(array, left, right, count_srav, count_perem);
}

void binarySort(float* array, int left, int right, int& count_srav, int& count_perem) {
	quickSort<float>(array, left, right, count_srav, count_perem);
}

#endif