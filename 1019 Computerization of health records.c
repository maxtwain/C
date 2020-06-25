#include <stdio.h>
#include <string.h>

typedef struct healthProfile {
	char firstName[30];
	char lastName[30];
	char gender;
	struct birthdate {
		unsigned int month;
		unsigned int day;
		unsigned int year;
	} Birthdate;
	unsigned int inchHeight;
	unsigned int poundWeight;
} HealthProfile;

void setProfile(HealthProfile* profilePtr);
void printStruct(HealthProfile* profilePtr);

int main(void) {

	HealthProfile profile01;

	setProfile(&profile01);
	printStruct(&profile01);

}

void setProfile(HealthProfile* profilePtr) {
	strcpy(profilePtr->firstName, "Jay");
	strcpy(profilePtr->lastName, "Gin");
	profilePtr->gender = 'M';
	profilePtr->Birthdate.month = 5;
	profilePtr->Birthdate.day = 24;
	profilePtr->Birthdate.year = 1852;
	profilePtr->inchHeight = 5;
	profilePtr->poundWeight = 43;
}

void printStruct(HealthProfile* profilePtr) {
	printf("Name: %s %s\nGender: %c\nBirthday: %2d/%2d/%4d\nHeight: %d\nWeight: %d\n", profilePtr->firstName, profilePtr->lastName, profilePtr->gender, profilePtr->Birthdate.month, profilePtr->Birthdate.day, profilePtr->Birthdate.year, profilePtr->inchHeight, profilePtr->poundWeight);
}