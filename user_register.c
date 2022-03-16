#include<stdio.h>

void user_register {
	
	printf("Please enter a user name:");
	scanf("%s", input_name);
	printf("Please enter a password:");
	scanf("%s", password);
	register_check();
}

void register_check {
	
	File *user;
	index = 0;
	int i;
	
	user = fopen("user.txt","r");
	while (!feof(user)){
		fscanf(user, "%s\n", user_name);
		index ++;
	}
	fclose(user);
	
	for (i=0; i<index; i++){
		if (strcmp(input_name, user_name) == 0){
			printf("Sorry, registration unsuccessful, the username you entered already exsits.");
			break;
		}
		else {
			fwrite(buffer,sizeof(char), sizeof(input_name), user);
			fwrite(buffer,sizeof(char), sizeof(password), user);
			printf("Congratulations for registration successful!")
		}
	}
}


