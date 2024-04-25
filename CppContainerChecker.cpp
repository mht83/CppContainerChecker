//////////////////////////////////////////////written by mht83/////////////////////////////////////////
#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <list>


template <typename Container, typename... Args>
bool contains_any(const Container& container, Args... args) {
    return ((std::find(container.begin(), container.end(), args) != container.end()) || ...);
}


template <typename Container, typename... Args>
bool contains_all(const Container& container, Args... args) {
    return ((std::find(container.begin(), container.end(), args) != container.end()) && ...);
}


template <typename Container, typename... Args>
bool contains_none(const Container& container, Args... args) {
    return !contains_any(container, args...);
}

int main() {
    std::vector<int> v{ 1, 2, 3, 4, 5, 6 };
    std::array<int, 6> a{ { 1, 2, 3, 4, 5, 6 } };
    std::list<int> l{ 1, 2, 3, 4, 5, 6 };

    
    std::cout<<(contains_any(v, 0, 3, 30));
    std::cout<<(contains_all(a, 1, 3, 5, 6));
    std::cout<<(!contains_none(l, 0,6));

    std::cout << "All checks passed!" << std::endl;
    return 0;
}

