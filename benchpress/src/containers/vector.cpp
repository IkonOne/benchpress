#include <benchmark/benchmark.h>

#include <vector>

static void bench_vector_creation(benchmark::State& state) {
    for (auto _ : state) {
        std::vector<int> v{42};
        benchmark::DoNotOptimize(&v);
    }
}
BENCHMARK(bench_vector_creation);

static void bench_vector_reserve(benchmark::State& state) {
    for (auto _ : state) {
        std::vector<int> v;
        v.reserve(state.range(0));
        benchmark::DoNotOptimize(v.data());
    }
}
BENCHMARK(bench_vector_reserve)->Range(1, 1024);

static void bench_vector_push_back(benchmark::State& state) {
    for (auto _ : state) {
        std::vector<int> v;
        for (int i = 0; i < state.range(0); ++i ) {
            v.push_back(i);
        }
        benchmark::DoNotOptimize(v.data());
        benchmark::ClobberMemory();
    }
}
BENCHMARK(bench_vector_push_back)->Range(1, 1024);

static void bench_vector_reserve_push_back(benchmark::State& state) {
    for (auto _ : state) {
        std::vector<int> v;
        v.reserve(state.range(0));
        for (int i = 0; i < state.range(0); ++i ) {
            v.push_back(i);
        }
        benchmark::DoNotOptimize(v.data());
        benchmark::ClobberMemory();
    }
}
BENCHMARK(bench_vector_reserve_push_back)->Range(1, 1024);

static void bench_vector_over_reserve_push_back(benchmark::State& state) {
    for (auto _ : state) {
        std::vector<int> v;
        v.reserve(state.range(0)*state.range(1));
        for (int i = 0; i < state.range(0); ++i ) {
            v.push_back(i);
        }
        benchmark::DoNotOptimize(v.data());
    }
}
BENCHMARK(bench_vector_over_reserve_push_back)->RangePair(1, 1024, 1, 32);