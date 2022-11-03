#include <benchmark/benchmark.h>

#include <list>

static void BM_list_creation(benchmark::State& state) {
    for (auto _ : state) {
        std::list<int> l{1};
        benchmark::DoNotOptimize(&l);
    }
}
BENCHMARK(BM_list_creation);

static void BM_list_resize(benchmark::State& state) {
    for (auto _ : state) {
        std::list<int> l;
        l.resize(state.range(0));
        benchmark::DoNotOptimize(l.begin());
        benchmark::ClobberMemory();
    }
}
BENCHMARK(BM_list_resize)->Range(1, 1024);

static void BM_list_push_back(benchmark::State& state) {
    for (auto _ : state) {
        std::list<int> l;
        for (int i = 0; i < state.range(0); ++i) {
            l.push_back(i);
        }
        benchmark::ClobberMemory();
    }
}
BENCHMARK(BM_list_push_back)->Range(1, 1024);