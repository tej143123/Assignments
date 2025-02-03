#include<stdio.h>
#include<ctype.h>

int main(){

	FILE *fptr1, *fptr2;
	char ch;

	fptr1 = fopen("file1.txt", "r");

	if(fptr1 == NULL){

		perror("Unable to open file");
		return 1;

	}

	fptr2 = fopen("file2.txt", "w");
	if(fptr2 == NULL){

		perror("Unable to create file");
		return 1;

	}

	else{
		printf("File is created");
	}				

	while((ch = fgetc(fptr1)) != EOF){

		if(islower(ch)){
			fputc(toupper(ch), fptr2);
		}
		else{
			fputc(tolower(ch), fptr2);
		}

	}

	fclose(fptr1);
	fclose(fptr2);

	return 0;

}



