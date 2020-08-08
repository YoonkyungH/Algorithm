#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int index=0;
    vector<int> v;

    for(int i=0; i<moves.size(); i++) {
        index = moves[i]-1;
        for(int j=0; j<board.size(); j++) {
            if(board[j][index]!=0) {
                v.push_back(board[j][index]);
                board[j][index] = 0;
                break;
            } 
        } if(v.size()>=2) {
            for(int y=0; y<v.size(); y++) {
                if(v[y] == v[y-1]) {
                    answer += 2;
                    v.pop_back();
                    v.pop_back();
                }
            }
        }
    }
    return answer;
}
