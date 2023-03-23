#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// to show array.
void display(float arr[3][3]){
    for (int i = 0; i<3; i++){
        for (int j = 0; j<3; j++){
            printf("%7.2f", arr[i][j]);
        }
        printf("\n");
    }
}
// negating array
void modify(float arr[3][3]){
    float new_array[3][3];
     for (int i = 0; i<3; i++){
        for (int j = 0; j<3; j++){
            new_array[i][j] = - arr[i][j];
        }
    }
    display(new_array);
}
// changing row with column.
void transpose(float arr[3][3]){
    float new_array[3][3];
    for (int i = 0; i<3; i++){
        for (int j = 0; j<3; j++){
            new_array[j][i] = arr[i][j];
        }
    }
    display(new_array);

}
// finding max value in every row.
void findMaxInRow(float arr[3][3]){

    for (int i = 0; i<3; i++){
        float maxInRow = arr[i][0];
        for (int j = 0; j<3; j++){
            if (maxInRow < arr[i][j]){
                maxInRow = arr[i][j];
            }
        }
        printf("The max in %d. row: %.2f \n",i+1, maxInRow);

    }
}
//To know if a matrix is symmetric,
//find the transpose of that matrix. If the transpose of that
//matrix is equal to itself, it is a symmetric matrix.
int isSymmetric(float arr[3][3]){

    int ans = 1;
    for (int i = 0; i<3; i++){
        for (int j = 0; j<3; j++){
            if(arr[i][j] != arr[j][i]){
                ans = 0;
                break;
            }
        }
    }
    return ans;
}

//|A| = a(ei − fh) − b(di − fg) + c(dh − eg) (3x3) matrix consist of (a-i).
float determinant(float a[3][3]){
    float determinant = a[0][0] * ((a[1][1]*a[2][2]) - (a[2][1]*a[1][2])) -a[0][1] * (a[1][0]
   * a[2][2] - a[2][0] * a[1][2]) + a[0][2] * (a[1][0] * a[2][1] - a[2][0] * a[1][1]);

    return determinant;
}

void inverse(float arr[3][3]){

    //A matrix has no inverse if its determinant is equal to 0.
    if(determinant(arr)== 0)
        printf("There is no inverse.\n");

    //otherwise we can find inverse.(I took the formula from net.)
    else{
        float new_array[3][3];
        for (int i = 0; i<3; i++){
            for (int j = 0; j<3; j++){
                new_array[i][j]=((arr[(j+1)%3][(i+1)%3] * arr[(j+2)%3][(i+2)%3]) - (arr[(j+1)%3][(i+2)%3] * arr[(j+2)%3][(i+1)%3]))/ determinant(arr);
            }

        }
        display(new_array);
    }

}
int main()
{
// to create array this algorithm will take values from user.
    float matrix[3][3];
    printf("Enter the array (3x3): \n");
    for (int i = 0; i<3; i++){
        for (int j = 0; j<3; j++){
            printf("[%d][%d]. position: ", i,j);
            scanf("%f", &matrix[i][j]);
        }
    }

    do{
        // display the array occured.
        printf("\nYour array: \n");
        display(matrix);

        // operations
        printf("\nChoose an operation to perform: \n");
        printf("[a] Modify matrix\n");
        printf("[b] Transpose matrix\n");
        printf("[c] Find the maximum element in each row of the matrix\n");
        printf("[d] Check whether the matrix is symmetric\n");
        printf("[e] Find the determinant of the matrix\n");
        printf("[f] Find the inverse of the matrix\n");
        printf("[q] Quit\n");

        // choice taken from user
        char choice;
        printf("Enter your choice: ");
        scanf("%s",&choice);
        printf("\n");

        // checking choice and doing operations according to choice
        switch (choice){

            case 'a':
            case 'A':
                printf("The modified matrix: \n");
                modify(matrix);
                break;

            case 'b':
            case 'B':
                printf("The transposed matrix: \n");
                transpose(matrix);
                break;

            case 'c':
            case 'C':
                findMaxInRow(matrix);
                break;

            case 'd':
            case 'D':
                if(isSymmetric(matrix))
                    printf("The array is symmetric.\n");

                else
                    printf("The array is not symmetric.\n");

                break;

            case 'e':
            case 'E':
                printf("The determinant of matrix: %.2f\n",determinant(matrix));
                break;

            case 'f':
            case 'F':
                printf("The inverse of the matrix:\n");
                inverse(matrix);
                break;

            case 'q':
            case 'Q':
                return 0;
                break;

            default:
                printf("\nPlease enter a valid value!!!");
                continue;
        }

    }while(true);

    return 0;
}
