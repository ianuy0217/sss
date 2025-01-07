#include <iostream>
#include <windows.h>

using namespace std;

int board[4][4] = {
    {0, 0, 1, 0},
    {0, 4, 0, 0},
    {0, 0, 2, 0},
    {0, 1, 0, 0},
};

bool editable[4][4];

int cur_r = 0, cur_c = 0;

int check_horizontal(int i,int j)
{
    /* TODO: Check if a horizontal line has conflict number, or is finished. */
    int k=0,t=0,r=0;
    for(int n=0;n<4;n++){
    	for(int m=0;m<4;m++){
    		if(board[i][n]==board[i][m]&&board[i][n]!=0){
    			k++;
			}
			else if(board[i][n]!=board[i][m]&&board[i][n]!=0){
				r++;
			}
		}
	}
	for(int m=0;m<4;m++){
    		if(board[i][m]!=0){
    			t++;
			}
			}
	if(k>t){
		return 1;
	}
	else if(r==12){
		return 2;
	}
    return 0;
}

int check_vertical(int i,int j)
{
    /* TODO: Check if a vertical line has conflict number, or is finished. */
    int k=0,t=0,r=0;
    for(int n=0;n<4;n++){
    	for(int m=0;m<4;m++){
    		if(board[n][j]==board[m][j]&&board[n][j]!=0){
    			k++;
			}
			else if(board[n][j]!=board[m][j]&&board[n][j]!=0){
				r++;
			}
		}
	}
	for(int m=0;m<4;m++){
    		if(board[m][j]!=0){
    			t++;
			}
			}
	if(k>t){
		return 1;
	}
	else if(r==12){
		return 2;
	}
	
    return 0;
}

int check_block(int i,int j)
{
    /* TODO: Check if a block has conflict number, or is finished. */
    int k=0,t=0;
    if(i<2&&j<2){
    	for(int n=0;n<2;n++){
    		for(int m=0;m<2;m++){
    			if(board[n][m]!=0){
    				t++;
				}
    			if(board[n][m]==board[0][0]&&board[n][m]!=0){
    				k++;
				}
				if(board[n][m]==board[0][1]&&board[n][m]!=0){
    				k++;
				}
				if(board[n][m]==board[1][0]&&board[n][m]!=0){
    				k++;
				}
				if(board[n][m]==board[1][1]&&board[n][m]!=0){
    				k++;
				}
			}
		}
	}
	else if(i<2&&j>1){
    	for(int n=0;n<2;n++){
    		for(int m=2;m<4;m++){
    			if(board[n][m]!=0){
    				t++;
				}
    			if(board[n][m]==board[0][2]&&board[n][m]!=0){
    				k++;
				}
				if(board[n][m]==board[0][3]&&board[n][m]!=0){
    				k++;
				}
				if(board[n][m]==board[1][2]&&board[n][m]!=0){
    				k++;
				}
				if(board[n][m]==board[1][3]&&board[n][m]!=0){
    				k++;
				}
			}
		}
	}
	else if(i>1&&j<2){
    	for(int n=2;n<4;n++){
    		for(int m=0;m<2;m++){
    			if(board[n][m]!=0){
    				t++;
				}
    			if(board[n][m]==board[2][0]&&board[n][m]!=0){
    				k++;
				}
				if(board[n][m]==board[2][1]&&board[n][m]!=0){
    				k++;
				}
				if(board[n][m]==board[3][0]&&board[n][m]!=0){
    				k++;
				}
				if(board[n][m]==board[3][1]&&board[n][m]!=0){
    				k++;
				}
			}
		}
	}
	else if(i>1&&j>1){
    	for(int n=2;n<4;n++){
    		for(int m=2;m<4;m++){
    			if(board[n][m]!=0){
    				t++;
				}
    			if(board[n][m]==board[2][2]&&board[n][m]!=0){
    				k++;
				}
				if(board[n][m]==board[2][3]&&board[n][m]!=0){
    				k++;
				}
				if(board[n][m]==board[3][2]&&board[n][m]!=0){
    				k++;
				}
				if(board[n][m]==board[3][3]&&board[n][m]!=0){
    				k++;
				}
			}
		}
	}
	if(k>t){
		return 1;
	}
	if (k==4){
		return 2;
	}
	return 0;
}


void fill_number(char c)
{
    /* TODO: Fill a number in to the cell the cursor is now pointing to.
             After fill in the number, check the horizontal line, the
             vertical line and the block the cell is in.
     */
     if (c=='1'){
     		board[cur_r][cur_c]=1;
     		return;
		 }
		 
		else if (c=='2'){
     		board[cur_r][cur_c]=2;
     		return;
		 }
     	
     	else if (c=='3'){
     		board[cur_r][cur_c]=3;
     		return;
		 }
		
		else if (c=='4'){
			board[cur_r][cur_c]=4;
			return;
		}
		else if (c=='0'){
			board[cur_r][cur_c]=0;
			return;
		}

}

void move_cursor(char c)
{
    /* TODO: Move the cursor up, down, to the left or to the right.
             Remember to check if the cursor is moving out of bound.
    */
    if(c=='w'||c=='W'){
		if(cur_r-1>=0){
			if(cur_r-1==0&&cur_c==2){
				
			}
			else if(cur_r-1==1&&cur_c==1){
				cur_r-=2;
			}
			else if(cur_r-1==2&&cur_c==2){
				cur_r-=2;
			}
			else if(cur_r-1==3&&cur_c==1){
				cur_r-=2;
			}
			else{
				cur_r--;
			}
		}
	}
	else if(c=='s'||c=='S'){
    	if(cur_r+1<4){
			if(cur_r+1==0&&cur_c==2){
				cur_r+=2;
			}
			else if(cur_r+1==1&&cur_c==1){
				cur_r+=2;
			}
			else if(cur_r+1==2&&cur_c==2){
				cur_r+=2;
			}
			else if(cur_r+1==3&&cur_c==1){
			}
			else{
				cur_r++;
			}
		}
	}
	else if(c=='d'||c=='D'){
    	if(cur_c+1<4){
			if(cur_r==0&&cur_c+1==2){
				cur_c+=2;
			}
			else if(cur_r==1&&cur_c+1==1){
				cur_c+=2;
			}
			else if(cur_r==2&&cur_c+1==2){
				cur_c+=2;
			}
			else if(cur_r==3&&cur_c+1==1){
				cur_c+=2;
			}
			else{
				cur_c++;
			}
		}
	}
	else if(c=='a'||c=='A'){
    	if(cur_c-1>=0){
			if(cur_r==0&&cur_c-1==2){
				cur_c-=2;
			}
			else if(cur_r==1&&cur_c-1==1){
				cur_c-=2;
			}
			else if(cur_r==2&&cur_c-1==2){
				cur_c-=2;
			}
			else if(cur_r==3&&cur_c-1==1){
				cur_c-=2;
			}
			else{
				cur_c--;
			}
		}
	}

}

bool is_invalid(int i, int j)
{
    /* TODO: Check if board[i][j] is in a line that has conflict numbers. */
    check_horizontal(i,j);
    check_block(i,j);
    check_vertical(i,j);
    if(check_horizontal(i,j)==1){
    	return true;
	}
	else if(check_block(i,j)==1){
    	return true;
	}
	else if(check_vertical(i,j)==1){
    	return true;
	}
    return false;
}

bool is_done(int i, int j)
{
    /* TODO: Check if board[i][j] is in a line that has finished. */
    check_horizontal(i,j);
    check_block(i,j);
    check_vertical(i,j);
    if(check_horizontal(i,j)==2){
    	return true;
	}
	else if(check_block(i,j)==2){
    	return true;
	}
	else if(check_vertical(i,j)==2){
    	return true;
	}
    return false;
}

bool check_win()
{
    /* TODO: Check if the game is set. That is, every cell is finished. */
    /* TODO: Check if the game is set. That is, every cell is finished. */
    int k=0;
    for(int i=0;i<4;i++){
    if(check_horizontal(i,0)==2)k++;
    if(check_vertical(0,i)==2)k++;
    }
    if(check_block(0,0)==2)k++;
    if(check_block(2,0)==2)k++;
    if(check_block(0,2)==2)k++;
    if(check_block(2,2)==2)k++;
    if(k==12)return true;
    return false;

	return false;
}

bool is_moving_action(char c)
{
    return (c == 'W' || c == 'w' || c == 'S' || c == 's' ||
            c == 'A' || c == 'a' || c == 'D' || c == 'd');
}

bool is_filling_action(char c)
{
    return (c >= '0' && c <= '4');
}

string get_styled_text(string text, string style)
{
    string color = "", font = "";
    for (char c : style)
    {
        if (c == 'R')
            color = "31";
        if (c == 'G')
            color = "32";
        if (c == 'E')
            color = "41";
        if (c == 'C')
            color = "106";
        if (c == 'B')
            font = ";1";
    }
    return "\x1b[" + color + font + "m" + text + "\x1b[0m";
}

void print_board()
{
    // Flush the screen
    cout << "\x1b[2J\x1b[1;1H";

    // Print usage hint.
    cout << get_styled_text("W/A/S/D: ", "B") << "move cursor" << endl;
    cout << get_styled_text("    1-4: ", "B") << "fill in number" << endl;
    cout << get_styled_text("      0: ", "B") << "clear the cell" << endl;
    cout << get_styled_text("      Q: ", "B") << "quit" << endl;
    cout << endl;

    // Iterate through and print each cell.
    for (int i = 0; i < 4; ++i)
    {
        // Print horizontal divider.
        if (i && i % 2 == 0)
            cout << "---------------" << endl;

        // Print the first vertical divider in each line.
        cout << "|";
        for (int j = 0; j < 4; ++j)
        {
            // Set text style based on the state of the cell.
            string style = "";

            // Set style for the cell the cursor pointing to.
            if (cur_r == i && cur_c == j)
                style = "C";
            // Set style for the cell in an invalid line.
            else if (is_invalid(i, j))
                style = "E";
            // Set style for the cell in a finished line.
            else if (is_done(i, j))
                style = "G";

            // Set style for a the cell that is immutable.
            if (!editable[i][j])
                style += "B";

            // Print the cell out in styled text.
            // If the content is 0, print a dot, else print the number.
            if (board[i][j] == 0)
                cout << get_styled_text(" ¡P ", style);
            else
                cout << get_styled_text(" " + to_string(board[i][j]) + " ", style);

            // Print the vertical divider for each block.
            if ((j + 1) % 2 == 0)
                cout << "|";
        }
        cout << endl;
    }
}

void initialize()
{
    // Set up styled text for Windows.
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);

    // Mark editable cells
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            editable[i][j] = !board[i][j];

    // Print the initial board out.
    print_board();
}

int main()
{
    char c;
    bool action_ok;

    initialize();
    while (cin >> c)
    {
        action_ok = false;
        if (is_moving_action(c))
        {
            action_ok = true;
            move_cursor(c);
        }

        if (is_filling_action(c))
        {
            action_ok = true;
            fill_number(c);
        }

        if (c == 'Q' || c == 'q')
            break;

        print_board();

        if (check_win())
        {
            cout << "YOU WIN!" << endl;
            break;
        }

        
    }

    
}


