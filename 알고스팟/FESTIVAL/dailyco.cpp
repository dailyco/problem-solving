#include <iostream>

using namespace std;

int main() {
  int C, N, L;
  scanf("%d", &C);

  for (int c = 0; c < C; c++) {
    scanf("%d %d", &N, &L);

    int price[1001];
    for (int j = 1; j <= N; j++)
      scanf("%d", &price[j]);

    int p_sum[1001];
    p_sum[0] = 0;
    p_sum[1] = price[1];
    for (int j = 2; j <= N; j++)
      p_sum[j] = p_sum[j-1] + price[j];

    double avg = (double)p_sum[L] / L;
    for (int j = L; j <= N; j++) {
      int s = 0, e = j;
      while(e <= N) {
        double c_avg = (double)(p_sum[e] - p_sum[s]) / j;
        if (avg > c_avg) {
          avg = c_avg;
        }
        s++; e++;
      }
    }

    printf("%.11f\n",avg);
  }
}