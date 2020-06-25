#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void printResults(int responses[5][10], char* issues[5]);
void slowFill(int responses[5][10], char* issues[5]);
void fillResponses(int responses[5][10]);

int main(void) {

	srand((unsigned int)time(NULL));

	char* issues[5] = { "economy", "deficit", "health care", "immigration", "drug law" };

	int responses[5][10] = { 0 };

	fillResponses(responses);
	printResults(responses, issues);

}

void slowFill(int responses[5][10], char* issues[5]) {
	puts("Rate the importance of each issue 1 to 10.");
	for (int person = 0; person < 10; ++person) {
		printf("Person %d\n", person);
		for (int issue = 0; issue < 5; ++issue) {
			printf("%s: ", issues[issue]);
			scanf_s("%d", &responses[issue][person]);
		}
	}
}

void fillResponses(int responses[5][10]) {
	for (int issue = 0; issue < 5; ++issue) {
		for (int person = 0; person < 10; ++person) {
			responses[issue][person] = rand() % 10;
		}
	}
}

void printResults(int responses[5][10], char* issues[5]) {
	printf("%4s", " ");
	for (int person = 0; person < 11; ++person) {
		if (person < 10) {
			printf("%4d", person);
		}
		else {
			printf("%4s", "Ave");
		}
		
	}
	puts("");
	int voterSum[10] = { 0 };
	int issueSum[5] = { 0 };
	for (int issue = 0; issue < 6; ++issue) {
		if (issue < 5) {
			printf("%4d", issue);
			for (int person = 0; person < 11; ++person) {
				if (person < 10) {
					issueSum[issue] += responses[issue][person];
					voterSum[person] += responses[issue][person];
					printf("%4d", responses[issue][person]);
				}
				else {
					printf("%4d", issueSum[issue] / 10);
				}
				
			}
		}
		else {
			printf("%4s", "Tot");
			for (int person = 0; person < 10; ++person) {
				printf("%4d", voterSum[person]);
			}
		}
		
		puts("");
	}
	puts("");
	int highestIssue = 0;
	int lowestIssue = 0;
	for (int ind = 0; ind < 5; ++ind) {
		if (issueSum[highestIssue] < issueSum[ind]) {
			highestIssue = ind;
		}
		if (issueSum[lowestIssue] > issueSum[ind]) {
			lowestIssue = ind;
		}
	}
	printf("Highest rated issue: %s %d votes\n", issues[highestIssue], issueSum[highestIssue]);
	printf("Lowest rated issue: %s %d votes\n", issues[lowestIssue], issueSum[lowestIssue]);
}