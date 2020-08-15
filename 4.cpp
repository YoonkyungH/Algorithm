#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int l=10, r=11; // 10은 * 11은 #
    int ln = 0, rn = 0; // 움직인 횟수
    int j=0;

    for(int i=0; i<numbers.size(); i++) {
        if(numbers[0] == 2 || numbers[0] == 5 || numbers[0] == 8 || numbers[0] == 0) {
            if(hand == "left") {
                answer += 'L'; l = numbers[0];
            }else if(hand == "right") {
                answer += 'R'; r = numbers[0];
            } i++;
        }
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
            answer += 'L'; l = numbers[i];
        } else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            answer += 'R'; r = numbers[i];
        } else {
            if(l==1 || l==4 || l==7) {
                if(numbers[i]>l) {
                    l+=1; ln++; while(l!=numbers[i]) {
                        l+=3; ln++;
                    }
                }else if(numbers[i]<l) {
                    l+=1; ln++; while(l!=numbers[i]) {
                        l-=3; ln++;
                    }
                }
            }
            if(l==3 || l==6 || l==9) {
                if(numbers[i]>r) {
                    r-=1; rn++; while(r!=numbers[i]) {
                        r+=3; rn++;
                    }
                }else if(numbers[i]<r) {
                    r-=1; rn++; while(r!=numbers[i]) {
                        r-=3; rn++;
                    }
                }
            }
            if(rn>ln)
                answer += 'L';
            else if(ln>rn)
                answer += 'R';
            else if(ln==rn) {
                if(hand == "right") {
                    answer += 'R';
                }
                else if(hand == "left") {
                    answer += 'L';
                }
            }
        }
    }
    return answer;
}
