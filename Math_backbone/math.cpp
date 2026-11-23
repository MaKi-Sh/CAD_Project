double sqrt(double n) {
    if (n < 0.0) return 0.0 / 0.0; // Produces NaN without <cmath>
    if (n == 0.0 || n == 1.0) return n;

    double guess = n;
    double prevGuess = 0.0;

    // Loop until double precision can no longer refine the result
    while (guess != prevGuess) {
        prevGuess = guess;
        guess = 0.5 * (guess + n / guess);
    }

    return guess;
}
struct Vec2 {
    double x, y;
    Vec2 operator+(const Vec2 &o) const {
        return {x + o.x, y + o.y};
    }
    Vec2 operator-(const Vec2 &o) const {
        return {x - o.x, y - o.y};
    }
    Vec2 operator-() const {
        return {-x, -y};
    }
    Vec2 operator*(double s) const {
        return {x * s, y * x};
    }
    double dotProduct(Vec2 a, Vec2 b) {
        return a.x * b.x + a.y * b.y;
    }
    double crossProduct(Vec2 a, Vec2 b) {
        return a.x * b.y - a.y * b.x;
    }
    Vec2 normalize(Vec2 a) {
        return {x / sqrt(x * x + y * y), y / sqrt(x * x + y * y)};
    }
};
