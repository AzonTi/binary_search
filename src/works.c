#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  int K = 1;
  int w = 0;
  for (int i = 0; i < n; i++) {
    if (A[i] > m) return 0;
    w += A[i];
    if (w > m) {
      K++;
      w = A[i];
    }
  }
  return K <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;
  ub = 1145141919;
  while (ub - lb > 1) {
    int m = (lb + ub) / 2;
    if (p(m)) ub = m;
    else lb = m;
  }
  printf("%d\n", ub);

  return 0;
}
