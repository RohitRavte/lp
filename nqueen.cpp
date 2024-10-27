#include<iostream>
using namespace std;




bool issafe(int**  board,int row,int col,int n){

    for(int i=0;i<col;i++){
        if(board[row][i]==1){
        return false;

    }}


    for(int i=row, j=col;i>=0 && j>=0;i--,j--){
        if(board[i][j]==1){
            return false;
        }
    }
     for(int i=row, j=col;i<n&&j>=0;i++,j--){
        if(board[i][j]==1){
            return false;
        }
    }


return true;




}


void nqueen(int ** board,int col,int n){

    while(col>=n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }

    for(int i=0;i<n;i++){
        if(issafe(board,i,col,n)){
            board[i][col]=1;

            nqueen(board,col+1,n);
            board[i][col]=0;
        }
    }
}



int main(){
   
   int n;
  
    cout<<"Enter the N*N matrix"<<endl;
    cin>>n;

    int**board=new int*[n];


    for(int i=0;i<n;i++){
        board[i]=new int [n]();

    }

    nqueen(board,0,n);





}