class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_set<char> seenRow, seenColumn;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (seenRow.find(board[i][j]) != seenRow.end()) {
                        cout << i << ' ' << j << endl;
                        return false;
                    }
                    seenRow.insert(board[i][j]);
                }
                if (board[j][i] != '.') {
                    if (seenColumn.find(board[j][i]) != seenColumn.end()) {
                        return false;
                    }
                    seenColumn.insert(board[j][i]);
                }
            }
        }

        for (int i = 1; i <= 3; i++) {
            for (int j = 1; j <= 3; j++) {
                unordered_set<char> seenBox;
                for (int n = (i - 1) * 3; n < i * 3; n++) {
                    for (int m = (j - 1) * 3; m < j * 3; m++) {
                        if (board[n][m] != '.'){
                            if (seenBox.find(board[n][m]) != seenBox.end())
                                return false;
                            seenBox.insert(board[n][m]);
                        }
                    }
                }
            }
        }

        return true;
    }
};