#ifndef ARRAY_INIT_H
#define ARRAY_INIT_H
#include <stdlib.h>

template <typename T>
	void ascending(T* array, int length) {
		for (int i = 0; i < length; i++) {
			array[i] = i;
		}
	}

void ascending(int* array, int length) {
	ascending<int>(array, length);
}

void ascending(char* array, int length) {
	ascending<char>(array, length);
}

void ascending(double* array, int length) {
	ascending<double>(array, length);
}

void ascending(float* array, int length) {
	ascending<float>(array, length);
}

template <typename T>
	void descending(T* array, int length) {
		for (int i = 0; i < length; i++) {
			array[i] = length - i - 1;
		}
	}

void descending(int* array, int length) {
	descending<int>(array, length);
}

void descending(char* array, int length) {
	descending<char>(array, length);
}

void descending(double* array, int length) {
	descending<double>(array, length);
}

void descending(float* array, int length) {
	descending<float>(array, length);
}

template <typename T>
	void random(T* array, int length) {
		for (int i = 0; i < length; i++) {
		array[i] = rand() % 100;
		}
}

void random(int* array, int length) {
	random<int>(array, length);
}

void random(char* array, int length) {
	random<char>(array, length);
}

void random(double* array, int length) {
	random<double>(array, length);
}

void random(float* array, int length) {
	random<float>(array, length);
}

#endif