#include <benchmark/benchmark.h>
#include <vector>

#include "buffer_stage1.h"
#include "buffer_stage2.h"

// 为了避免命名冲突，使用不同的类名
using GoodBufferStage1 = GoodBuffer;

// ============================================================================
// 阶段1 vs 阶段2：构造函数对比
// ============================================================================

// 阶段1：只能复制构造
static void BM_Stage1_CopyConstruction(benchmark::State &state)
{
    size_t size = state.range(0);
    for (auto _ : state)
    {
        GoodBufferStage1 buf1(size);
        GoodBufferStage1 buf2 = buf1; // 必须复制
        benchmark::DoNotOptimize(buf2);
    }
}
BENCHMARK(BM_Stage1_CopyConstruction)->Range(64, 1024 * 1024);

// 阶段2：可以移动构造
static void BM_Stage2_MoveConstruction(benchmark::State &state)
{
    size_t size = state.range(0);
    for (auto _ : state)
    {
        GoodBufferStage2 buf1(size);
        GoodBufferStage2 buf2 = std::move(buf1); // 使用移动
        benchmark::DoNotOptimize(buf2);
    }
}
BENCHMARK(BM_Stage2_MoveConstruction)->Range(64, 1024 * 1024);

// ============================================================================
// 阶段1 vs 阶段2：赋值操作符对比
// ============================================================================

// 阶段1：复制赋值
static void BM_Stage1_CopyAssignment(benchmark::State &state)
{
    size_t size = state.range(0);
    GoodBufferStage1 buf1(size);
    GoodBufferStage1 buf2(size);
    for (auto _ : state)
    {
        buf1 = buf2; // 复制赋值
        benchmark::DoNotOptimize(buf1);
    }
}
BENCHMARK(BM_Stage1_CopyAssignment)->Range(64, 1024 * 1024);

// 阶段2：移动赋值
static void BM_Stage2_MoveAssignment(benchmark::State &state)
{
    size_t size = state.range(0);
    GoodBufferStage2 buf1(size);
    for (auto _ : state)
    {
        GoodBufferStage2 buf2(size);
        buf1 = std::move(buf2); // 移动赋值
        benchmark::DoNotOptimize(buf1);
    }
}
BENCHMARK(BM_Stage2_MoveAssignment)->Range(64, 1024 * 1024);

// ============================================================================
// 阶段1 vs 阶段2：容器操作对比
// ============================================================================

// 阶段1：vector push_back（必须复制临时对象）
static void BM_Stage1_VectorPushBack(benchmark::State &state)
{
    for (auto _ : state)
    {
        std::vector<GoodBufferStage1> vec;
        for (int i = 0; i < 100; ++i)
        {
            GoodBufferStage1 buf(1024 * 1024);
            vec.push_back(buf); // 必须复制
        }
    }
}
BENCHMARK(BM_Stage1_VectorPushBack);

// 阶段2：vector push_back（自动使用移动）
static void BM_Stage2_VectorPushBack(benchmark::State &state)
{
    for (auto _ : state)
    {
        std::vector<GoodBufferStage2> vec;
        for (int i = 0; i < 100; ++i)
        {
            vec.push_back(GoodBufferStage2(1024 * 1024)); // 自动移动
        }
    }
}
BENCHMARK(BM_Stage2_VectorPushBack);

// ============================================================================
// 阶段2：复制 vs 移动对比（同一个类）
// ============================================================================

static void BM_Stage2_CopyVsMove_Copy(benchmark::State &state)
{
    size_t size = state.range(0);
    for (auto _ : state)
    {
        GoodBufferStage2 buf1(size);
        GoodBufferStage2 buf2 = buf1; // 复制
        benchmark::DoNotOptimize(buf2);
    }
}
BENCHMARK(BM_Stage2_CopyVsMove_Copy)->Range(64, 1024 * 1024);

static void BM_Stage2_CopyVsMove_Move(benchmark::State &state)
{
    size_t size = state.range(0);
    for (auto _ : state)
    {
        GoodBufferStage2 buf1(size);
        GoodBufferStage2 buf2 = std::move(buf1); // 移动
        benchmark::DoNotOptimize(buf2);
    }
}
BENCHMARK(BM_Stage2_CopyVsMove_Move)->Range(64, 1024 * 1024);

BENCHMARK_MAIN();
