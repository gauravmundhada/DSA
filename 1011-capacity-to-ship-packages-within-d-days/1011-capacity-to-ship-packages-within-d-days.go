func canShip(weights []int, days int, m int) bool {
    w := 0
    d := 1

    for i := 0; i < len(weights); i++ {
        if w + weights[i] <= m {
            w += weights[i]
        } else {
            d += 1
            w = weights[i]
        }
    }
    return d <= days
}

func shipWithinDays(weights []int, days int) int {
    n := len(weights)

    l := weights[0]
    r := 0

    for i := 0; i < n; i++ {
        if l < weights[i] {
            l = weights[i]
        }
        r += weights[i]
    }

    ans := r

    for l <= r {
        m := l + (r-l)/2;

        if canShip(weights, days, m) {
            ans = m
            r = m-1
        } else {
            l = m + 1
        }
    }
    return ans
}