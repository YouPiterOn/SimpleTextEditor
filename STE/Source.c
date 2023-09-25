#include <stdio.h>
#include <stdlib.h>

struct node {
	char symbol;
	struct node* next;
};

int main() {
	struct node *head = (struct node*)malloc(sizeof(struct node));
	struct node* pointer = NULL;
	head->next = NULL;
	char text[80];
	FILE* myFile;
	char filename[20];
	int command = 0;
	int i;
	int line = 0;
	int sym = 0;
	char clear;
	while (command != 9)
	{
		printf("Choose the command:\n");
		
		scanf_s("%i", &command);
		switch (command)
		{
		case 1:
			printf("Enter text to append:");
			scanf_s("%c", &clear);
			scanf_s("%[^\n]", text, sizeof(text));
			i = 0;
			pointer = head;
			while (pointer->next != NULL) {
				pointer = pointer->next;
			}
			while (text[i] != '\0') {
				struct node *newnode = (struct node*)malloc(sizeof(struct node));
				newnode->symbol = text[i];
				newnode->next = NULL;
				pointer->next = newnode;
				pointer = pointer->next;
				i++;
			}
			break;
		case 2:
			pointer = head;
			while (pointer->next != NULL) {
				pointer = pointer->next;
			}
			struct node* newnode = (struct node*)malloc(sizeof(struct node));
			newnode->symbol = '\n';
			newnode->next = NULL;
			pointer->next = newnode;
			printf("New line is started\n");
			break;
		case 3:
			printf("Enter file name for saving:");
			
			scanf_s("%s", filename, sizeof(filename));
			fopen_s(&myFile, filename, "w");
			pointer = head->next;
			while (pointer != NULL) {
				fprintf(myFile, "%c", pointer->symbol);
				pointer = pointer->next;
			}
			fflush(myFile);
			fclose(myFile);
			break;
		case 4:
			printf("Enter file name for reading:");
			scanf_s("%s", filename, sizeof(filename));
			fopen_s(&myFile, filename, "r");
			char symbol;
			pointer = head;
			while (pointer->next != NULL) {
				pointer = pointer->next;
			}
			while ((symbol = fgetc(myFile)) != EOF) {
				struct node* newnode = (struct node*)malloc(sizeof(struct node));
				newnode->symbol = symbol;
				newnode->next = NULL;
				pointer->next = newnode;
				pointer = pointer->next;
			}
			fclose(myFile);
			break;
		case 5:
			pointer = head;
			while (pointer->next != NULL) {
				printf("%c", pointer->next->symbol);
				pointer = pointer->next;
			}
			printf("\n");
			break;
		case 6:;
			printf("Choose line and index:");
			scanf_s("%i %i", &line, &sym);
			pointer = head->next;
			while (line > 0 || sym > 0) {
				if (pointer == NULL) {
					printf("no such symbol");
					break;
				}
				if (pointer->symbol == '\n') {
					line--;
				}
				if (line == 0) {
					sym--;
				}
				pointer = pointer->next;
			}
			if (pointer == NULL) {
				break;
			}
			printf("Enter text to append:");
			scanf_s("%c", &clear);
			scanf_s("%[^\n]", text, sizeof(text));
			i = 0;
			struct node *tail = pointer->next;
			while (text[i] != '\0') {
				struct node* newnode = (struct node*)malloc(sizeof(struct node));
				newnode->symbol = text[i];
				newnode->next = NULL;
				pointer->next = newnode;
				pointer = pointer->next;
				i++;
			}
			pointer->next = tail;
			break;
		case 7:
			printf("Enter text to search:");
			scanf_s("%c", &clear);
			scanf_s("%[^\n]", text, sizeof(text));
			pointer = head->next;
			line = 0;
			sym = 0;
			while (pointer->next != NULL)
			{

				if (pointer->symbol == text[0]) {
					struct node *pointer2 = pointer->next;
					i = 1;
					while (text[i] != '\0' && pointer2 != NULL)
					{
						if (text[i] != pointer2->symbol) {
							break;
						}
						i++;
						pointer2 = pointer2->next;
					}
					if (text[i] == '\0') {
						printf("Text is present in this position: %i %i\n", line, sym);
						break;
					}
				}
				sym++;
				if (pointer->symbol == '\n') {
					line++;
					sym = 0;
				}
				pointer = pointer->next;
				if(pointer->next == NULL) {
					printf("No such text\n");
				}
			}
			break;
		case 8:
			system("cls");
		}
		
	}
	return 0;
}