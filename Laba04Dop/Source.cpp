#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
int IsVowel(char a) {
	char character[] = {'A','a','E','e','Y','y','U','u','I','i','O','o' };
	for (size_t i = 0; i < sizeof(character); i++) {
		if (a == character[i]) {
			return 1;
		}
	}
	return 0;
}
int Vowel—ounter(char* a) {
	int i = 0;
	int count = 0;
	while (a[i] != '\0') {
		if (IsVowel(a[i])) {
			count++;
		}
		i++;
	}
	return count;
}
void swap(char** a, char** b) {
	char* c = 0;
	c = *a;
	*a = *b;
	*b = c;
}




int isAlpha(char c) {
	return (((c <= 'z') && (c >= 'a')) || ((c >= 'A') && (c <= 'Z')));
}
int main() {
	int size = 0;
	char* array;
	char** text;
	printf("Enter size of array\n");
	scanf("%d",&size);
	array = (char*)malloc(size * sizeof(char));
	if (array == NULL) {
		return printf("ERROR");
	}
	text = (char**)calloc(size , sizeof(char*));
	if (text == NULL) {
		return printf("ERROR");
	}
	printf("Enter array\n");
	char e = 0;
	scanf("%c", &e);
	fgets(array, size, stdin);
	for (size_t i = 0; i < size; i++) {
		if (!isAlpha(array[i])) {
			array[i] = '\0';
		}
	}
	size_t number = 0;
	for (size_t i = 0; i < size; i++) {
		while (!isAlpha(array[i]) && i<size) {
			i++;
		}
		text[number] = &array[i];
		number++;
		while (isAlpha(array[i]) && i < size) {
			i++;
		}
	}
	printf("Words from array\n");
	for (size_t i = 0; i < number - 1; i++) {
		if (text[i] != NULL) {
			printf("%s\n", text[i]);
		
		}
		
	}
	printf("______________________\n");
	printf("Sorted array\n");
	for (size_t i = 0; i < number - 2; i++) {
		for (size_t j = 0; j < number - 2; j++) {
			if (Vowel—ounter(text[j]) > Vowel—ounter(text[j + 1])) {
				swap(&text[j], &text[j + 1]);
			}
		}
	}
	for (size_t i = 0; i < number - 1; i++) {
		printf("%s\n", text[i]);
	}
	return 0;


}
