std = c99
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int answer;
int sword = 0;
int location = 0;
int pyr = 0;
int castpyr = 0;
int action;
int ghould = 0;
int ded = 0;
int wizd = 0;

int getAction() {
	char actionString[80];

	fgets(actionString, sizeof(actionString), stdin);
	return atoi(actionString);;
}


void invalid() {
    printf("> ????\n");
}

void doLocation0() {
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
		if(!wizd && sword) {
			wizd == 1;
		}
            	break;
        default :
            invalid();
            break;
    }
}
  
void doLocation1() {
    printf("> You are in an empty room.\n");
    printf("> There are 2 ways forward.\n");
    printf("> East and north\n");
    printf("1) Go east\n2) Go north\n3) Go west\n? ");
    action = getAction();
    switch (action)
    {
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
	if(sword==0) {
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
	else {
		printf("> This room is empty.\n");
		printf("1) Go west\n? ");
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
	if(wizd == 0) {
		if(sword == 0) {
			printf("> You encounter an evil magician!\nYou have no weapons to fight with\n");
			printf("> The magician casts a fireball and you are quickly engulfed in flames.");
			ded = 1;
		}
		if(sword == 1) {
			printf("> You encounter an evil magician!\nYou equip your sword and attack!\n");
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
			wizd = 1;
		}
	}
	else {
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
	if(pyr == 0) {
		printf("> You are in a pitch black room. You can't see a thing!\nYour eyes are just beginning to adjust to the dark,\n");
		printf("> when you are attacked by an un-seen foe!\n");
		printf("> Not being able to see your enemy, you're quickly killed.\n");
		ded = 1;
	}
	if(pyr == 1) {
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
	printf("> You cast a fireball! The room is quickly illuminated and you can see again\n");
	printf("> In the corner of the room, you spot a ghoul!!\n> You equip your sword and kill the beast.\n");
	ghould = 1;
}

void doLocationWizd() {
	printf("> You find nothing in this room aside from the carcass of a magician you killed earlier\n");
	printf("1) Go east\n? ");
}

int main() {
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
		printf("> You killed the ghoul!\nYou win!.\n");
	}
	else if(ded) {
		printf("> You have died.\nGame over.\n");
	}
}
