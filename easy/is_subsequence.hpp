#include <cassert>
#include <string>
#include <vector>

namespace leet_code
{
    bool isSubsequence(std::string s, std::string t)
    {
        std::size_t f{0};
        for (const auto &c : t)
        {
            f += static_cast<std::size_t>(c == s[f]);
        }
        return f == s.size();
    }
} // namespace leet_code