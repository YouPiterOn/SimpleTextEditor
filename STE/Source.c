#include <stdio.h>

int main() {
	char text[80];
	int command;
	while (&command != "9")
	{
		printf("Choose the command:\n");
		scanf_s("%i", &command);
		switch (command)
		{
		case 1:
			printf("\nEnter text to append:");
			scanf_s("%s", text, sizeof(text));
			break;
		case 2:
			text[strlen(text)] = "\n";
			printf("New line is started");
			break;
		}
		for (int i = 0; i < strlen(text); i++)
			printf("%c", text[i]);
	}
	return 0;
}