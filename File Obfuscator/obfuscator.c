#include <stdio.h>

int transform(int c)
{
	return ~c;
}

int main()
{

	//obfuscate the file.
	FILE* in = fopen("secret.txt", "rb+");
	FILE* out = fopen("hidden.txt", "wb+");
	

	if (in == NULL || out == NULL)
	{
		printf("Error opening file.\n");
		return 1;
	}

	int c;
	while ((c = fgetc(in)) != EOF)
		fputc(transform(c), out);

	fclose(in);
	fclose(out);


	//get the real content of the file from an obfuscated file.
	FILE* hidden = fopen("hidden.txt", "rb+");
	FILE* decrypted_file = fopen("decrypted.txt", "wb+");

	if (hidden == NULL || decrypted_file == NULL)
	{
		printf("Error opening file.\n");
		return 1;
	}

	while ((c = fgetc(hidden)) != EOF)
		fputc(transform(c), decrypted_file);
	
	fclose(decrypted_file);
	fclose(hidden);

	return 0;
}