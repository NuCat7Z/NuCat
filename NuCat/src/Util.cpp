#include "Util.h"
#include <algorithm>
std::string Util::StringtoLowerCase(const std::string& input) {
    std::string result = input;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}