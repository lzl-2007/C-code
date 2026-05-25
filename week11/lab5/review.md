# Code Review: node.cc

## Correctness Issues

1. **Critical Error in `BuildSharedTree`**:
   - Line 50 uses `std::make_unique<SharedNode>` but returns `std::shared_ptr<SharedNode>`
   - This causes a compilation error as `unique_ptr` cannot be implicitly converted to `shared_ptr`
   - **Fix**: Replace with `std::make_shared<SharedNode>(depth)`

2. **Negative Depth Handling**:
   - Both tree builders only check `depth == 0` but don't handle negative values
   - Calling with negative depth causes infinite recursion
   - **Fix**: Change condition to `if (depth <= 0)`

## Robustness Issues

1. **Redundant Timing Implementation**:
   - `test()` function duplicates the timing logic already implemented in `test_with_timer()`
   - Creates maintenance burden and potential inconsistency
   - **Fix**: Remove `test()` entirely and rely on `Timer` class

2. **Inconsistent Timer Messages**:
   - `"unique_ptr construct "` (with trailing space) vs `"shared_ptr construct"` (no space)
   - Causes inconsistent output formatting
   - **Fix**: Standardize message format

## Code Duplication

1. **Structural Duplication**:
   - `UniqueNode`/`BuildUniqueTree` and `SharedNode`/`BuildSharedTree` have nearly identical patterns
   - **Opportunity**: Template-based implementation could reduce duplication

2. **Dead Code**:
   - `test()` function is defined but never called
   - **Fix**: Remove unused function

## Style Improvements

1. **Timer Constructor Efficiency**:
   - Pass `std::string` by const reference instead of by value
   - **Fix**: `explicit Timer(const std::string& str)`

2. **Whitespace Consistency**:
   - Mixed spacing around operators (e.g., `depth==0` vs `root.reset()`) 
   - **Fix**: Add spaces around operators for readability