#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int arr[3] = {0,}; // 학생들의 점수를 기록 후 비교해 answer에 넣음
    int A[5] = {1, 2, 3, 4, 5}; // 1번 수포자
    int B[8] = {2, 1, 2, 3, 2, 4, 2, 5}; // 2번
    int C[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}; // 3번
    int i = 0; // answers를 셈

    for(int j=0; j<5; j++) { // A 학생
        if(i >= answers.size())
            break;
        if(answers[i] == A[j])
            arr[0] += 1;
        if(j == 4)
            j = 0;
        i++;
    } i = 0;
    for(int k=0; k<8; k++) { // B 학생
        if(i >= answers.size())
            break;
        if(answers[i] == B[k])
            arr[1] += 1;
        if(k == 7)
            k = 0;
        i++;
    } i=0;
    for(int l=0; l<10; l++) { // C 학생
        if(i >= answers.size())
            break;
        if(answers[i] == C[l])
            arr[2] += 1;
        if(l == 9)
            l = 0;
        i++;
    }
    if(arr[0] >= arr[1] && arr[0] >= arr[2])
        answer.push_back(1);
    if(arr[1] >= arr[0] && arr[1]>= arr[2])
        answer.push_back(2);
    if(arr[2] >= arr[0] && arr[2] >= arr[1])
        answer.push_back(3);

    return answer;
}
