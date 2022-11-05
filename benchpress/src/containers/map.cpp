#include <benchmark/benchmark.h>

#include <map>

static void bench_map_creation(benchmark::State& state) {
    for (auto _ : state) {
        std::map<int, int> m{{42, 42}};
        benchmark::DoNotOptimize(&m);
        benchmark::ClobberMemory();
    }
}
BENCHMARK(bench_map_creation);

static void bench_map_insert(benchmark::State& state) {
    std::map<int, int> m;
    for (auto _ : state) {
        for (int i = 0; i < state.range(0); ++i)
            m.insert({i, i});
        benchmark::DoNotOptimize(&m);
    }
}
BENCHMARK(bench_map_insert)->RangeMultiplier(2)->Range(1, 4096);

static void bench_map_find(benchmark::State& state) {
    for (auto _ : state) {
        std::map<int, int> m;
        for (int i = 0; i < state.range(0); ++i) {
            m.insert({i, i});
        }
        auto val = m.find(state.range(0) / 2);
        benchmark::DoNotOptimize(val);
    }
}
BENCHMARK(bench_map_find)->RangeMultiplier(2)->Range(8, 2<<16);
