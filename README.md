# noexcept_inline_DLL_benchmark

## Tests the effect of noexcept for an inline function from a DLL

*Niels Dekker, LKEB, Leiden University Medical Center*

A performance effect was reported by gast128, April 16, 2020 who wrote at
[C++11 noexcept implementation still a performance loss with VS2017?](https://developercommunity.visualstudio.com/t/c11-noexcept-implementation-still-a-performance-lo/425370#T-N993561):

> We use Visual Studio 2017 15.9.22 x64 build and we observe now that an inline / constexpr DLL exported constructor is not inlined with noexcept. 
