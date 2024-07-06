#include <cassert>
#include <unordered_map>
#include <vector>

namespace leet_code
{
    bool isIsomorphic(std::string fst, std::string snd)
    {
        constexpr std::size_t char_value_count{256};
        int fst_map[char_value_count] = {0};
        int snd_map[char_value_count] = {0};

        for (std::size_t i{0}; i < fst.size(); ++i)
        {
            if (fst_map[fst[i]] != snd_map[snd[i]])
            {
                return false;
            }
            fst_map[fst[i]] = i + 1;
            snd_map[snd[i]] = i + 1;
        }
        return true;
    }
} // namespace leet_code