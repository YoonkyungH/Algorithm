#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int std[31] = {0};

    for(int i=1; i<=n; i++) {
        std[i] = 1;
    }
    for(int i=0; i<reserve.size(); i++) {
        std[reserve[i]] = 2;
    } // 더 가져온 학생들
    for(int i=0; i<lost.size(); i++) {
        std[lost[i]]--;
    } // 잃어버린 학생들

    for(int i=0; i<lost.size(); i++) {
        if(std[lost[i]]==0){
            if(std[lost[i]-1] == 2) {
                std[lost[i]-1]--; std[lost[i]]++;
            }
            else if(std[lost[i]+1] == 2) {
                std[lost[i]+1]--; std[lost[i]]++;
            }
        }
    }

    for(int i=1; i<=n; i++) {
        if(std[i] >= 1){
            answer++;
        }
    }
    return answer;
}
