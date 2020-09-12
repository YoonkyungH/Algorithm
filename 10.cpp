#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    sort(arr.begin(), arr.end());

    for(int i=0; i<arr.size()-1; i++) {
        if(arr[i] != arr[i+1]) {
            answer.push_back(arr[i]);
        }
    }
    answer.push_back(arr[arr.size()-1]);


    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}
