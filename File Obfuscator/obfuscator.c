#include <stdio.h>

int transform(int c)
{
	return ~c;
}

int main()
{

	//obfuscate the file.
	FILE* in1 = fopen("first_open.txt", "rb+");
	FILE* out1 = fopen("second_secret.txt", "wb+");
	

	if (in1 == NULL || out1 == NULL)
	{
		printf("Error opening file.\n");
		return 1;
	}

	int c;
	while ((c = fgetc(in1)) != EOF)
		fputc(transform(c), out1);

	fclose(in1);
	fclose(out1);


	//get the real content of the file from an obfuscated file.
	FILE* in2 = fopen("second_secret.txt", "rb+");
	FILE* out2 = fopen("third_open.txt", "wb+");

	if (in2 == NULL || out2 == NULL)
	{
		printf("Error opening file.\n");
		return 1;
	}

	while ((c = fgetc(in2)) != EOF)
		fputc(transform(c), out2);
	
	fclose(in2);
	fclose(out2);

	return 0;
}