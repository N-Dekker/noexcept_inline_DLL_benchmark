#define TEST_LIB_EXPORT __declspec(dllexport)
#include "exported_class.h"

int exported_class::non_inline_get_data() const OPTIONAL_EXCEPTION_SPECIFIER
{
    return m_data;
}

