#include<stdio.h>
#include<windows.h>
void drawBoard();
int checkWin();

//Initialising the board
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};

//Game Board
void drawBoard(){
    printf("---TIC TAC TOE---\n");
    for (int i=0;i<3;i++){
        printf("%c  |  %c  |  %c\n",board[i][0],board[i][1],board[i][2]);
        if (i!=2)
        printf("---|-----|---\n");
    }
}

int checkWin(){
    //1 for win, 2 for tie
    
    //check row
    for (int i=0;i<3;i++){
        if ((board[i][0]==board[i][1]) && (board[i][1]==board[i][2]))
            return 1;
    }
    
    //check column
    for (int j=0;j<3;j++){
        if ((board[0][j]==board[1][j]) && (board[1][j]==board[2][j]))
        return 1;
    }

    //check diagonal
    if ((board[0][0]==board[1][1]) && (board[0][0]==board[2][2]))
    return 1;
    if ((board[0][2]==board[1][1]) && (board[0][2]==board[2][0]))
    return 1;

    //check tie
    int count=0;
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if (board[i][j]!='O' && board[i][j]!='X')
            count++;
        }
    }
    if (count==0){
        return 2;
    }
    return 0;
}
    

int main(){
    int row,column,move,gameStatus;
    int player=1;
    while(1){
        system("cls"); //clear screen
        drawBoard();
        player=(player%2==0)?2:1; //alternates between the two players
        printf("Player %d move: ",player);
        scanf("%d",&move);
        
        if ((move<1)||(move>9)){
            printf("Invalid move. Try again");
            Sleep(1000); //Displays message for 1 sec
            continue;
        }

        //row and column
        row=(move-1)/3;
        column=(move-1)%3;
        //checking for valid move
        if ((board[row][column]!='O')&&(board[row][column]!='X')){
            if (player==1){
            board[row][column]='O';
            }else{
            board[row][column]='X';
            }
        }else{
            printf("Already filled.\n");
            Sleep(1000);  //Displays message for 1 sec
            player--;
        }
        drawBoard();
        
        gameStatus=checkWin();
        if (gameStatus==1){
            printf("PLAYER %d WON !!",player);
            break;
        }else if (gameStatus==2){
            printf("DRAW !!");
            break;
        }
        player++;
    
    }
    
    return 0;
}