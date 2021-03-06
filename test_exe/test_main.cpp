/*
Copyright Niels Dekker, LKEB, Leiden University Medical Center

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0.txt

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#define TEST_LIB_EXPORT __declspec(dllimport)
#include "../test_library/exported_class.h"
#include <climits>

#ifdef USE_NOEXCEPT
#  pragma message("[Info] Build using noexcept")
#else
#  pragma message("[Info] Build without noexcept")
#endif

int main()
{
	constexpr exported_class obj{};
	int sum{};

	for (int i{}; i < INT_MAX; ++i)
	{
		sum += obj.inline_get_data();
	}

	return sum;
}
