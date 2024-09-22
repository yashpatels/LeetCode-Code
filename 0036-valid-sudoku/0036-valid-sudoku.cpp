class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {


        int count = 9;

        int change = 0;
        int x =0;
        int y =0;
        while(count > 0){
            unordered_map<char,char> m;
            for (int i=x; i<x+3; i++){
                for (int j=y; j<y+3; j++){
                    if (board[i][j]=='.'){
                        continue;
                    }
                    if(m.find(board[i][j])!=m.end()){
                        cout << board[i][j];
                        return false;
                    } 
                    else{
                        m[board[i][j]]='.';
                    } 
                }
            }
            if(change==2){
                x+=3;
                y=0;
                change = 0;
            } else {
                y+=3;
                change++;
            }
            count--;
        }

        for (int i=0; i<9; i++){
            unordered_map<char,char> m1;
            for (int j=0; j<9; j++){
                if (board[i][j]=='.'){
                        continue;
                }
               if(m1.find(board[i][j])!=m1.end()){
                    cout << board[i][j];
                    return false;
                } else{
                    m1[board[i][j]]='.';
                } 

            }
        }

        for (int i=0; i<9; i++){
            unordered_map<char,char> m2;
            for (int j=0; j<9; j++){
                if (board[j][i]=='.'){
                        continue;
                }

                if(m2.find(board[j][i])!=m2.end()){
                    cout << board[j][i];
                    return false;
                } else{
                    m2[board[j][i]]='.';
                }

            }
        }
        
        return true;
    }
};