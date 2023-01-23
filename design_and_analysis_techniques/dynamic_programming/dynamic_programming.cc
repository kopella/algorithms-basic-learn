template <typename T>
inline T max(const T& a, const T& b) {
  return a > b ? a : b;
}

void question_one();

int main() {
  question_one();
  return 0;
}

void question_one() {
  int p[11]{0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

  int r[11]{};
  for (int i = 1; i <= 10; i++) {
    r[i] = -1;
  }
}