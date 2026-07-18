class Spreadsheet {
public:
    vector<vector<int>> sheet;
    Spreadsheet(int rows) {
        sheet = vector<vector<int>>(rows, vector<int>(26, 0));
    }
    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        sheet[row][col] = value;
    }

    void resetCell(string cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        sheet[row][col] = 0;
    }

    int getValue(string formula) {
        int ans = 0;
        string s1 = "", s2 = "";
        int i = 1; // remove '='
        while (i < formula.size() && formula[i] != '+') {
            s1 += formula[i];
            i++;
        }
        s2 = formula.substr(i + 1);
        if (isalpha(s1[0])) {
            int col = s1[0] - 'A';
            int row = stoi(s1.substr(1)) - 1;
            ans += sheet[row][col]; // adding second if sheet cell
        } else {
            ans += stoi(s1); // adding value
        }
        if (isalpha(s2[0])) {
            int col = s2[0] - 'A';
            int row = stoi(s2.substr(1)) - 1;
            ans += sheet[row][col]; // adding second if sheet cell
        } else {
            ans += stoi(s2); // adding value
        }
        return ans;
    }
};
