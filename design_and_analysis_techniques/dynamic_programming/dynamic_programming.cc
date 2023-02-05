template <typename T>
inline T max(const T& a, const T& b) {
  return a > b ? a : b;
}

#include <stdio.h>

int n = 4, W = 8;
int wt[5]{0, 2, 3, 4, 5};
int vt[5]{0, 3, 4, 5, 6};

int V_W_TB[5][9]{};
int top_to_bottom(int i, int w) {
  if (V_W_TB[i][w] != 0) {
    return V_W_TB[i][w];
  }
  if (i == 0) {
    return 0;
  }
  if (w - wt[i] < 0) {
    return top_to_bottom(i - 1, w);
  }
  V_W_TB[i][w] =
      max(top_to_bottom(i - 1, w), top_to_bottom(i - 1, w - wt[i]) + vt[i]);
  return V_W_TB[i][w];
}

int V_W_BT[5][9]{};
int bottom_to_top() {
  for (int i = 1; i <= n; i++) {
    for (int w = 1; w <= W; w++) {
      if (w - wt[i] < 0) {
        V_W_BT[i][w] = V_W_BT[i - 1][w];
        continue;
      }
      V_W_BT[i][w] = max(V_W_BT[i - 1][w], V_W_BT[i - 1][w - wt[i]] + vt[i]);
    }
  }
  return V_W_BT[n][W];
}

int main() {
  int res_1 = top_to_bottom(4, 8);
  printf("res 1: %d\n", res_1);
  for (int i = 0; i <= n; i++) {
    for (int w = 0; w <= W; w++) {
      printf("%d ", V_W_TB[i][w]);
    }
    printf("\n");
  }

  int res_2 = bottom_to_top();
  printf("res 2: %d\n", res_2);
  for (int i = 0; i <= n; i++) {
    for (int w = 0; w <= W; w++) {
      printf("%d ", V_W_BT[i][w]);
    }
    printf("\n");
  }
  return 0;
}
