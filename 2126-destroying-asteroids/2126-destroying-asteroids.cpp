class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();
        long long currMass = mass; // to avoid overflow

        sort(asteroids.begin(), asteroids.end());

        for (auto ast : asteroids) {
            if (currMass < ast) return false;
            currMass += ast;
        }
        return true;
    }
};


/*
greedy - at every point I will take the asteroid which is equal to mass or just smaller than it
can't think of any tc which will not work with greedy

I have to optimize the way of picking the asteroid :
sort and then take lower bound - 1 or prev(*it)


mass = 10
asteroids = [1,2]


*/