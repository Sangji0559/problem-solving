#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

const char* test_str = "th1s_H3x_pr1int3r";
const char* hint = "hexprinter";

void print_hex(const char* buf, int size) {
	int index;
	for (index = 0; index < size; index++) {
		if (index % 16 == 0) printf("\n");
		printf("0x%02X ", buf[index]);
	}
}

void encode_list() {
	print_hex(test_str, strlen(test_str));
}

int main() {
	
	char str[31];
	printf("30자 이내의 문자열을 입력하세요 \n");
	scanf("%s", str);
	if (!strcmp(str , hint)) {
		encode_list();
	}
	else {
		printf("Wrong");
		print_hex(hint, strlen(hint));
	}
	
	return 0;
}