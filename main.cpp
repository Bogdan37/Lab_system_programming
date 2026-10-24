#include <iostream>
#include <vector>
#include <cmath>

constexpr size_t N = 20'000'000;

void compute_heavy(std::vector<float>& a, const std::vector<float>& b) {
    for (size_t iter = 0; iter < 40; ++iter) {
        for (size_t i = 0; i < N; ++i) {
            a[i] = a[i] * 0.5f + b[i] * 1.5f;
        }
    }
}

void compute_light(std::vector<float>& a) {
    for (size_t iter = 0; iter < 10; ++iter) {
        for (size_t i = 0; i < N; ++i) {
            a[i] = a[i] + 1.0f;
        }
    }
}

int main() {
    std::vector<float> a(N, 1.0f);
    std::vector<float> b(N, 2.0f);

    compute_heavy(a, b);
    compute_light(a);

    std::cout << "Done. Sample val: " << a[0] << std::endl;
    return 0;
}