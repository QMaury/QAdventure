#include <stdio.h>
#include <stdlib.h>

int answer;

int main() {
	printf("hello, sinner\n\n");
	
	printf("1) Go left\n2) Go right\n? ");
	scanf("%d", &answer );

	if(answer == 1) {
		printf("> Damnation!\n");
	}
	else if(answer == 2) {
		printf("> Salvation!\n");
	}
	
}

