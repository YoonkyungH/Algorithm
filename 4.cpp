#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";

    int lNum = 10;
    int rNum = 12;
    int lDistanse = 0;
    int rDistanse = 0;

    for (int i = 0; i < numbers.size(); i++) {
        if (lNum == 0) {
           lNum = 11;
        }
        if (rNum == 0) {
            rNum = 11;
        }
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            answer += "L";
            lNum = numbers[i];
        } else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            answer += "R";
            rNum = numbers[i];
        } else {
            if (numbers[i] != 0) {
                lDistanse = abs(numbers[i] - lNum); // abs() 절대값 함수
                rDistanse = abs(numbers[i] - rNum);
            } else {
                lDistanse = abs(11 - lNum);
                rDistanse = abs(11 - rNum);
            }
            if (lDistanse % 3 == 0) {
                lDistanse = lDistanse / 3;
            } else {
                lDistanse = (lDistanse % 3) + (lDistanse / 3);
            }
            if (rDistanse % 3 == 0) {
                rDistanse = rDistanse / 3;
            } else {
                rDistanse = (rDistanse % 3) + (rDistanse / 3);
            }
            if (lDistanse > rDistanse) {
                answer += "R";
                rNum = numbers[i];
            } else if (lDistanse == rDistanse) {
                answer += toupper(hand[0]); // toupper() 소문자에서 대문자 변환
                if (hand[0] == 'r') {
                    rNum = numbers[i];
                } else {
                    lNum = numbers[i];
                }
            } else {
                answer += "L";
                lNum = numbers[i];
            }
        }

    }

    return answer;
}
