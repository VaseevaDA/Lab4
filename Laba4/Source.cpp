#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int isAlpha(char c) {
	return (((c <= 'z') && (c >= 'a')) || ((c >= 'A') && (c <= 'Z')));
}
int strlen(char* str) {
	int len = 0;

	while (*str != '\0') {
		len++;
		str++;
	}
	return len;
}
void swap(char** a, char** b) {
	char* c = 0;
	c = *a;
	*a = *b;
	*b = c;
}

int main() {
	char text[200] = { 0 };
	char* array[200] = { 0 };
	printf("Enter array\n");
	fgets(text, sizeof(text), stdin);
	for (size_t i = 0; i < sizeof(text); i++) {
		if (!isAlpha(text[i])) {
			text[i] = '\0';
		}
	}
	size_t size = 0;
	for (size_t i = 0; i < sizeof(text); i++) {
		while (!isAlpha(text[i])) {
			i++;
		}
		array[size] = &text[i];
		size++;
		while (isAlpha(text[i])) {
			i++;
		}
	}
	for (size_t i = 0; i < size-1; i++) {
		printf("%s\n", array[i]);
	}
	printf("____________\n");
	for (size_t i = 0; i < size - 2; i++) {
		for (size_t j = 0; j < size - 2; j++) {
			if (strlen(array[j]) > strlen(array[j + 1])) {
				swap(&array[j], &array[j + 1]);
			}
		}
	}
	for (size_t i = 0; i < size-1; i++) {
		printf("%s\n", array[i]);
	}
	return 0;
}