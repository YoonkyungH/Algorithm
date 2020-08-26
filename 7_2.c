#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(int n) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    char* answer = (char*)malloc(sizeof(char)*(n*3)+1);
    // n은 글자수와 같고 한글은 3바이트이므로 (n*3)은 글자 하나의 공간임. +1은 \0이 들어갈 공간
    for(int i=0; i<n; i++) {
        if(i%2==0)
            strcpy(answer + (i*3), "수");
        else
            strcpy(answer + (i*3), "박");
    }
    return answer;
}
