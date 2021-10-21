#include <stdio.h>
#include <stdlib.h>

int answer;
int sword = 0;

int main() {
	printf("Adventure 0.2 - QMaury\n\n");
	
	printf("1) Go west\n2) Go east\n? ");
	scanf("%d", &answer);

	if(answer == 1) {
		printf("> You are dead.\n");
	}
	else if(answer == 2) {
		printf("\n1) Go north\n2) Go east\n? ");
		scanf("%d", &answer);		/*  I am beginning to see that */
		if(answer == 1) {		/*  this code is fucking retarded.  */
			printf("> You've been killed by a ghoul.\n> Game over.\n");
			return 0;
		}
		else if(answer == 2) {
			printf("> You find a sword\n\n");
			int sword = 1;
			printf("1) Go west\n? ");
			scanf("%d", &answer);
			if(answer == 1) {   /*	GOD I AM A FUCKING RETARDED  */
				printf("\n1) Go north\n2) Go east\n? ");
				scanf("%d", &answer);
				if(answer == 1) {
					printf("> You encounter a ghoul.\n> You kill the ghoul.\n");
					printf("> You win!\n");
					return 0;
				}
	}
		}
	}
	else {
		printf("> invalid answer\n");
	}
}
