#include<map>
template<typename K, typename V>
class interval_map{
     friend void IntervalMapTest();
     V m_valBegin;
     std::map<K,V> m_map;
public:
     // constructor associaltes whole range of K with val
     interval_map(V const& val): m_valBegin(val) {}

     // assign value val to interval [keyBegin, keyEnd)
     // overwriting previous values in this interval
     // conforming to the C++ Standard Library conventions
     // includes keyBegin, excludes keyEnd
     // if !(keyBegin < keyEnd), this designates an empty interval
     // and assigns val to nothing
     void assign(K const& keyBegin, K const& keyEnd, V const& val){
          if (keyEnd < keyBegin) {
            return;
        }

        auto it_begin = m_map.lower_bound(keyBegin);
        auto it_Ubegin = m_map.upper_bound(keyBegin);

        auto it_end = m_map.upper_bound(keyEnd);

        if (m_map.size() == 0) {
            if (val == m_valBegin)
                return;
        }

        if (it_end != m_map.end()) {
            if (val == it_end->second) {
                return;
            }
        }
        if (it_begin != m_map.begin()) {
            if (val == std::prev(it_begin)->second) {
                return;
            }
        }

        if (it_begin == m_map.end()) {

            if (it_end != m_map.end() && it_Ubegin->first < it_end->first) {
                m_map.insert({keyEnd, it_Ubegin->second});
            }
            m_map.erase(it_Ubegin, it_end);
            m_map.insert({keyBegin, val});

        } else {
            if (it_end != m_map.end()) {
                m_map.insert({keyEnd, it_end->second});
            }
            m_map.erase(it_begin, it_end);
            m_map.insert({keyBegin, val});
        }
     }

     // look up value at key
     V const& operator[](K const& key) const{
          auto it = m_map.upper_bound(key);
          if(it == m_map.begin()){
               return m_valBegin;
          }else{
               return (--it)->second;
          }
     }

};

#include <iostream>
void IntervalMapTest() {

    std::srand(time(0));

    // Number of random test cases
    const int numTestCases = 1000;
    // Generate random test cases
    for (int i = 0; i < numTestCases; ++i) {

        interval_map<int,char> iMap('F');
        std::map<int, char> referenceMap;

        // Randomly generate startKey, endKey, and value
        int startKey = std::rand() % numTestCases;
        int endKey = startKey + std::rand() % 50;
        char value = static_cast<char>('A' + std::rand() % 26);

        // Perform the assignment in both the inter_map and referenceMap
        iMap.assign(startKey, endKey, value);
        for (int key = startKey; key <= endKey; ++key) {
            referenceMap[key] = value;
        }

        // Compare the results of inter_map with the referenceMap
        // and print an error message if they differ
        for (const auto& entry : referenceMap) {
            int key = entry.first;
            char expectedValue = entry.second;
            char actualValue = iMap[key]; // You may need a getValue() function in your inter_map class
            if (actualValue != expectedValue) {
                std::cout << "Test "<<i <<" failed: Key " << key << ", Expected " << expectedValue << ", Actual " << actualValue << std::endl;
            }
        }

    }
    std::cout << "Randomized test completed." << std::endl;
}

#include<bits/stdc++.h>  
using namespace std;


int main(){
     IntervalMapTest();
     return 0;
}