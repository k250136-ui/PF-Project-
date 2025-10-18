
     function for matrix 
void matrix(int r,int c,int M[r][c])
{
    printf("\n");
    for(int i=0;i<r;i++)
    {
        printf("   ");
        for(int j=0;j<c;i++)
        {
            printf(" %4d", M[r][c]);
        }
        printf("\n");
    }
}     
     
     
     // Matrix 
    // int r, c, choice;
    // printf("Enter number of rows: ");
    scanf("%d", &r);
    printf("Enter number of columns: ");
    scanf("%d", &c);

    int A[r][c], B[r][c], C[r][c];
    
    printf("\nEnter elements of Matrix A:\n");
    for (int i=0;i<r;i++)
    {
        for (int j=0;j<c;j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
    printf("\nEnter elements of Matrix B:\n");
    for (int i=0;i<r;i++)
    {
        for (int j=0;j<c;j++)
        {
            scanf("%d", &B[i][j]);
        }
    }
    for(int i=0;i<r;i++)
        for(int j=0;j,c;j++)
        {
        C[i][j]=A[i][j]+B[i][j];
        printf("%d%d%d", r,c,C[i][j]);
        }