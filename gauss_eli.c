#include <stdio.h>
#define ROW 3


void printAb(int row, double Ab[row][row+1]){
  int i, j = 0;

  for(i = 0; i < row; i++){
    for(j =  0; j < row+1; j++){
      printf("%f ", Ab[i][j]);
    }
    printf("\n");
  }

}

void forward(int row, double Ab[row][row+1]){

  int i, j, k;
  double a = 0;

  for(i = 0; i < row; i++){
    for(j = i+1; j < row; j++){
      a = Ab[j][i] / Ab[i][i];
      for(k = i; k < row+1; k++){
        Ab[j][k] -= a * Ab[i][k];
      }
    }
  }
  printAb(row, Ab);
}

void backward(int row, double Ab[row][row+1], double x[row]){

  int i, j;

  for(i = row-1; i >= 0; i--){
    for(j = i + 1; j < row; j++){
      Ab[i][j] = Ab[i][j] * x[j];
      x[i] -= Ab[i][j];
    }
    x[i] = Ab[i][row] / Ab[i][i];
  }

  for(i = 0; i < row; i++){
    printf("x%d = %f\n", i, x[i]);
  }
}

int main(void){

  double Ab[3][4] = {{1, 2, -2, 3},
                          {1, -1, 3, 4},
                          {2, 3, -5, 1}
                          };
  double x[3] = {0, 0, 0};

  forward(3, Ab);
  backward(3, Ab, x);

}
