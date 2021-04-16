class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // First lets define some testing ground
        // abcdefaghijklmnobylr
        // 15
        // the biggest string is bcdefaghijklmno
        // I can count the occurrencies to see if it repeats
        // If not, I can ignore, if does, I need the position
        // so if none of the positions between repeat in the range
        // that's the length without repetition
        // a -> 0,6
        // b -> 1,16
        // so no other repeat in between
        // Now, if a repeats in between b, it's invalidate b
        // If a starts before or ends after b, its ok
        
        // abcdeafg
        // !!      
        
        if (s.length() < 2) {
            return s.length();
        }

        std::string::iterator sub_initial = s.begin();
        std::string::iterator sub_final = s.begin() + 1;
        
        // Will save previous characters and it counts
        std::map<char, std::string::iterator> char_map;
        // Add the first char to the map and set it to 1
        char_map[*sub_initial] = sub_initial;
        std::cout << "Adding : " << *sub_initial << std::endl;
        int distance = 0;
        // Walk the sub_final iterator until find a repeated char
        for(; sub_final != s.end(); sub_final++ ) {
            if (char_map.count(*sub_final) > 0) {
                // that means that we found a repeated char
                std::cout << "Repeated : " << *sub_final << std::endl;
                // when I find a repeated I need get the length of the substring and save
                int temp_distance = std::distance(sub_initial, sub_final);
                if (distance < temp_distance) {
                    distance = temp_distance;
                    std::cout << "Biggest distance so far : " << distance << std::endl;
                }
                // hiabcdeafg
                // ! *    ?   
                // Now I need to remove the ocurrences before the first character that repeat
                std::string::iterator it = char_map[*sub_final];
                for (; sub_initial != it + 1; sub_initial++) {
                    std::cout << "Removing : " << *sub_initial << std::endl;
                    char_map.erase(*sub_initial);
                }
                char_map[*sub_final] = sub_final;
                std::cout << "Adding : " << *sub_final << std::endl;
            } else {
                // Not found yet, so I can add
                char_map[*sub_final] = sub_final;
                std::cout << "Adding : " << *sub_final << std::endl;
            }
        }
        
        // To test one last time pass the end
        int temp_distance = std::distance(sub_initial, sub_final);
        if (distance < temp_distance) {
            distance = temp_distance;
            std::cout << "Biggest distance so far : " << distance << std::endl;
        }
        
        return distance;
    }
};