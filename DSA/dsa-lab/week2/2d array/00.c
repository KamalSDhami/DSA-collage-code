int main(){
    int mat [4][3]={{0,0,1},{0,1,1},{1,1,1},{0,0,0}};
    int n = 4,x =3;
    int row = search(mat,n,x);
    print("Row : %d",row);
}
int search (int mat[4][3],int n, int x)
{
    if(n==0){
        return -1;
    }
    int i= 0,j=n-1,ans =-1;
    while(i<n && j>=0){
        if (mat[i][j]==1)
        {
            j--;
            ans =i;
        }else{
            i++;
        }
    }if(ans >0 ){
        printf("%d",ans);
    }else{
        printf("No one is found");
    }return 0;
}