#include <stdio.h>
#include <string.h>

#define WSIZE 50
int main(void) {
	char* word[WSIZE] = { "gold", "grandiose", "bumpy", "horn", "protest", "glass", "plantation", "reproduce", "cross", "cart", "badge", "ossified", "wanting", "unkempt", "jam", "floor", "hunt", "measure", "occur", "wreck", "coil", "heat", "rule", "smoggy", "talk", "reign", "forgetful", "literate", "cake", "color", "sore", "optimal", "weigh", "collect", "tempt", "silk", "synonymous", "bolt", "sister", "need", "repulsive", "trains", "extend", "decision", "guttural", "flesh", "pedal", "eyes", "vague", "handsomely" };

	for (int i0 = 0; i0 < WSIZE; ++i0) {
		if (word[i0][0] == 'b') {
			printf("%s\n", word[i0]);
		}
	}
	puts("\n");
}





