#include <stdio.h>
#include <stdlib.h>

//allow users to create account
int user_register (user_name, password) {
	
	printf("Please enter a user name:");
	scanf("%s", user_name);
	printf("Please enter a password:");
	scanf("%s", password);
	register_check();
    return 0;
}

//Check if the register name already existed
void register_check {
	
	File *user;
	index = 0;
	int i;
	
	user = fopen("user.txt","r");
	while (!feof(user)){
		fscanf_s(user, "%s\n", user_name);
		index ++;
	}
	fclose(user);
	
	for (i=0; i<index; i++){
		if (strcmp(user_name, user_name) == 0){
			printf("Sorry, registration unsuccessful, the username you entered already exists.");
			break;
		}
		else {
			fwrite(buffer,sizeof(char), sizeof(input_name), user);
			fwrite(buffer,sizeof(char), sizeof(password), user);
			printf("Congratulations for registration successful!")
		}
	}
}


