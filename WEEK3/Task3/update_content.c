  #include<stdio.h>


  int main(){
          
	  FILE *fptr1, *fptr2, *fptr3;
	  int start1 = 20, end1 = 80, start2 = 50, end2 = 90, line = 1;
	  char buffer[500]; //Created buffer to read & store data into it and later helps to write into new file 

	  //opening file1 and file2 in read mode
	  fptr1 = fopen("gx_group.txt", "r");
	  fptr2 = fopen("ai.txt", "r");

	  // a check to know whether file is opened to perform read operation or not
	  if(fptr1 == NULL || fptr2 == NULL){

		  perror("Unable to open file");
		  return 0;// dummy value to exit the program 

	  }

	  //opening output file in write mode to copy the contents from file1 and file2
	  fptr3 = fopen("copied_content.txt", "w");

	  //a check to know whether file is created to perform write operation or not 
	  if(fptr3 == NULL){

		  perror("Failed to create file");
		  return 0;// dummy value to exit the programm

	  }


	  //reading & storing data in buffer & then updating data into output file from buffer
	  while((fgets(buffer, sizeof(buffer), fptr1)) != NULL){

		  if(line >= start1 && line <= end1){

			  fputs(buffer, fptr3);

		  }
		  
		  if(line > end1) break; 

		  line++;

	  }
	  fflush(fptr1);// clear the data from buffer
	  fclose(fptr1);// close the first file after reading 

	  line = 1;



	  //similar as above 
	  while((fgets(buffer, sizeof(buffer), fptr2)) != NULL){

                  if(line >= start2 && line <= end2){

                          fputs(buffer, fptr3);

                  }

                  if(line > end2) break;

                  line++;

          }

	  fflush(fptr2);
	  fclose(fptr2);

	  printf("File copied_content.txt is created successfully");

	  return 0;

  }




