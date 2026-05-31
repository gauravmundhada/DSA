class Solution {
public:
     bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
    multiset<long long> set;        
    
    for (int asteroid : asteroids)
        set.insert(asteroid);
    
    long long total_mass = mass;

    while (!set.empty()) {
        auto it = set.lower_bound(total_mass);

        if (it != set.end() && *it == total_mass) {
            total_mass += *it;
            set.erase(it);
        } 
        else {
            if (it == set.begin())
                break;

            auto prevIt = prev(it);
            total_mass += *prevIt;
            set.erase(prevIt);
        }
    }

    return set.empty();
}
}; 


/*
greedy - at every point I will take the asteroid which is equal to mass or just smaller than it
can't think of any tc which will not work with greedy

I have to optimize the way of picking the asteroid :
sort and then take lower bound - 1 or prev(*it)


mass = 10, asteroids = [3,9,19,5,21]
[3,5,9,19,21]


*/