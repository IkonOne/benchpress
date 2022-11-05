#include <benchmark/benchmark.h>

#include <bplib/ds/dense_map.h>

#include <vector>

static void bench_dense_map_creation(benchmark::State& state) {
    for (auto _ : state) {
        bplib::dense_map<int, int> m{{42, 42}};
        benchmark::DoNotOptimize(m.data());
        benchmark::ClobberMemory();
    }
}
BENCHMARK(bench_dense_map_creation);

static void bench_dense_map_push_back(benchmark::State& state) {
    for (auto _ : state) {
        bplib::dense_map<int, int> m;
        for (int i = 0; i < state.range(0); ++i) {
            m.push_back({i, i});
        }
        benchmark::DoNotOptimize(m.data());
        benchmark::ClobberMemory();
    }
}
BENCHMARK(bench_dense_map_push_back)->RangeMultiplier(2)->Range(8, 4096);

static void bench_dense_reserve_push_back(benchmark::State& state) {
    for (auto _ : state) {
        bplib::dense_map<int, int> m;
        m.reserve(state.range(0) * state.range(1));
        for (int i = 0; i < state.range(0); ++i) {
            m.push_back({i, i});
        }
        benchmark::DoNotOptimize(m.data());
        benchmark::ClobberMemory();
    }
}
BENCHMARK(bench_dense_reserve_push_back)->RangePair(1, 1024, 1, 32);

static void bench_dense_map_find(benchmark::State& state) {
    for (auto _ : state) {
        bplib::dense_map<int, int> m;
        m.reserve(state.range(0));
        // Pushing backwards to ensure find sorts first
        for (int i = state.range(0)-1; i >= 0; --i) {
            m.push_back({i, i});
        }
        auto val = m.find(state.range(0) / 2);
        benchmark::DoNotOptimize(val);
    }
}
BENCHMARK(bench_dense_map_find)->RangeMultiplier(2)->Range(8, 4096);