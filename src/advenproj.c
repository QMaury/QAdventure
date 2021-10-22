#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
int sword = 0;
int location = 0;
int action;
int ghould = 0;
int ded = 0;
int wizded = 0;

void txtdvd() {
	printf("\n|=========================================|\n\n");
}

int getAction() {
	char actionString[80];

	fgets(actionString, sizeof(actionString), stdin);
	return atoi(actionString);;
}


void invalid() {
    printf("> ????\n");
}

void doLocation0() {
	txtdvd();
    printf("> You are at the entrance to the cave. There are 2 ways forward.\n");
    printf("> You can go east or west.\n");
    printf("1) Go east\n2) Go west\n? ");
    action = getAction();
    switch (action) {
        case 1 :
            location = 1;
            break;
     	   case 2 :
            	location = 4;
            	break;
        default :
            invalid();
            break;
    }
}
  
void doLocation1() {
	txtdvd();
  	printf("> You are in an empty room.\n");
    	printf("> There are 2 ways forward.\n");
    	printf("> East and north\n");
    	printf("1) Go east\n2) Go north\n3) Go west\n? ");
    	action = getAction();
    	switch (action) {
        	case 1 :
        	    location = 2;
           	break;
        	case 2 :
            	location = 3;
            	break;
        	case 3 :
            	location = 0;
            	break;
        	default :
            	invalid();
            	break;
    	}
}

void doLocation2() {
	if(sword == 0) {
		txtdvd();
		printf("> You are in a room with a sword. You take the sword.\n");
		sword = 1;
		printf("1) Go west\n? ");
		action = getAction();
		switch(action) {
			case 1 :
			location = 1;
			break;
			default :
			invalid();
			break;
		}
	}

	else if(sword == 1) {
		txtdvd();
		printf("> This room is empty.\n");
		printf("1) Go west\n? ");
		action = getAction();
		switch(action) {
			case 1 :
			location = 1;
			break;
			default :
			invalid();
			break;
		}
	}
}
void doLocation4() {
	if(wizded == 0) {
		if(sword == 0) {
			txtdvd();
			printf("> You encounter an evil magician!\n> You have no weapons to fight with\n");
			printf("> The magician casts a fireball and you are quickly engulfed in flames.\n");
			ded = 1;
		}
		if(sword == 1 && wizded == 0) {
			txtdvd();
			wizded = 1;
			printf("> You encounter an evil magician!\n> You equip your sword and attack!\n");
			printf("> The magician is defeated, and you usurp his power to cast fireballs.\n");
			printf("1) Go east\n? ");
			action = getAction(); 
			switch(action) {
				case 1:
				location = 0;
				break;
				default:
				invalid();
				break;
			}
		}
	}
	else if(wizded == 1) {
		txtdvd();
		printf("> This room is empty besides the carcass of the magician you killed earlier\n");
		printf("1) Go east\n? ");
		action = getAction(); 
		switch(action) {
			case 1:
			location = 0;
			break;
			default:
			invalid();
			break;
		}
	}
}
void doLocation3() {
	if(wizded == 0) {
		txtdvd();
		printf("> You are in a pitch black room. You can't see a thing!\nYour eyes are just beginning to adjust to the dark,\n");
		printf("> when you are attacked by an un-seen foe!\n");
		printf("> Not being able to see your enemy, you're quickly killed.\n");
		ded = 1;
	}
	if(wizded == 1) {
		txtdvd();
		printf("> You are in a pitch black room. You can't see a thing!\n");
		printf("1) Go south\n2) Cast a fireball\n? ");
		action = getAction();
		switch(action) {
			case 1:
				location = 1;
				break;
			case 2:
				location = 5;
				break;
			default:
				invalid();
				break;
		}

	}
}

void doLocationPyr() {
	txtdvd();
	printf("> You cast a fireball! The room is quickly illuminated and you can see again.\n");
	printf("> In the corner of the room, you spot a ghoul!!\n> You equip your sword and kill the beast.\n");
	ghould = 1;
}

void doLocationWizd() {
	txtdvd();
	printf("> You find nothing in this room aside from the carcass of a magician you killed earlier\n");
	printf("1) Go east\n? ");
}

int main() {
	printf("QAdventure 1.5.1");
	doLocation0();
	while (!ded && !ghould) {
        switch (location) {
            case 0:
                doLocation0();
                break;
            case 1:
                doLocation1();
                break;
            case 2:
                doLocation2();
                break;
            case 3:
                doLocation3();
                break;
	    case 4:
		doLocation4();
		break;
	    case 5: 
		doLocationPyr();
		break;
	    case 6:
		doLocationWizd();
		break;
        }
    }
	if (ghould) {
		printf("> You killed the ghoul!\n> You win!\n");
	}
	else if(ded) {
		printf("> You have died.\n> Game over.\n");
	}
}
