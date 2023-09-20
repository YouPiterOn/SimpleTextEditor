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
	FILE** myFile;
	int command;
	while (&command != "9")
	{
		printf("Choose the command:\n");
		
		scanf_s("%i", &command);
		switch (command)
		{
		case 0:
			pointer = head;
			while (pointer->next != NULL) {
				printf("%c", pointer->next->symbol);
				pointer = pointer->next;
			}
			printf("\n");
			break;
		case 1:
			printf("Enter text to append:");
			scanf_s("%s", text, sizeof(text));
			int i = 0;
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
			char filename[20];
			scanf_s("%s", filename, sizeof(filename));
			fopen_s(myFile, filename, "w");
			pointer = head;
			while (pointer->next != NULL) {
				fprintf(myFile, pointer->symbol);
				pointer = pointer->next;
			}
			head = NULL;
			head = (struct node*)malloc(sizeof(struct node));
			pointer = NULL;
		}
		
	}
	return 0;
}