# noexcept_inline_DLL_benchmark

## Tests the effect of noexcept for an inline function from a DLL

*Niels Dekker, LKEB, Leiden University Medical Center, 2021*

A performance effect was reported by gast128, April 16, 2020 who wrote at
[C++11 noexcept implementation still a performance loss with VS2017?](https://developercommunity.visualstudio.com/t/c11-noexcept-implementation-still-a-performance-lo/425370#T-N993561):

> We use Visual Studio 2017 15.9.22 x64 build and we observe now that an inline / constexpr DLL exported constructor is not inlined with noexcept. 

This Visual Studio project allows comparing the assember output when using `noexcept` to the assember output without `noexcept`, from a call to an inline member function of a DLL-experted class ([test_exe/test_main.cpp](https://github.com/N-Dekker/noexcept_inline_DLL_benchmark/blob/main/test_exe/test_main.cpp#L34)):

    obj.inline_get_data();

It appears that when `exported_class::inline_get_data()` is marked `noexcept`, the function call is not inline-expanded, as the assembler output will then have a line like this: 

    00		 call	 QWORD PTR __imp_?inline_get_data@exported_class@@QEBAHXZ

The test executable appears significantly slower when using `noexcept`.

Which may be observed at Azure Pipelines
[dekkerware/Pipelines/N-Dekker.noexcept_inline_DLL_benchmark](https://dev.azure.com/dekkerware/dekkerware/_build?definitionId=17)
