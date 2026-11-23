#include <cmath>
#include <optional>

constexpr double LINEAR_TOL = 1e-15; // distances, in mm

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
        return {x * s, y * s};
    }
    Vec2 operator/(double s) const {
        return {x / s, y / s};
    }
};
struct Vec3 {
    double x, y, z;

    Vec3 operator+(const Vec3 &o) const {
        return {x + o.x, y + o.y, z + o.z};
    }
    Vec3 operator-(const Vec3 &o) const {
        return {x - o.x, y - o.y, z - o.z};
    }
    Vec3 operator-() const {
        return {-x, -y, -z};
    }
    Vec3 operator*(double s) const {
        return {x * s, y * s, z * s};
    }
    Vec3 operator/(double s) const {
        return {x / s, y / s, z / s};
    }
};
// Lets you write 2.0 * v as well as v * 2.0
inline Vec2 operator*(double s, const Vec2 &v) {
    return v * s;
}

inline Vec3 operator*(double s, const Vec3 &v) {
    return v * s;
}

inline double dot(const Vec2 &a, const Vec2 &b) {
    return a.x * b.x + a.y * b.y;
}

inline double dot(const Vec3 &a, const Vec3 &b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

// In 2D the cross product is a single number:
// > 0 means b is counter-clockwise from a, < 0 clockwise, 0 parallel.
inline double cross(const Vec2 &a, const Vec2 &b) {
    return a.x * b.y - a.y * b.x;
}

inline Vec3 cross(const Vec3 &a, const Vec3 &b) {
    return {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}

inline double length(const Vec2 &v) {
    return std::sqrt(dot(v, v));
}

inline double length(const Vec3 &v) {
    return std::sqrt(dot(v, v));
}

// Returns nothing for a (near) zero-length vector, which has no direction.
inline std::optional<Vec2> normalized(const Vec2 &v) {
    double len = length(v);
    if (len < LINEAR_TOL) return std::nullopt;
    return v / len;
}
inline std::optional<Vec2> normalized(const Vec3 &v) {
    double len = length(v);
    if (len < LINEAR_TOL) return std::nullopt;
    return v / len;
}
// True if the two points are closer than the tolerance.
inline bool samePoint(const Vec2 &a, const Vec2 &b) {
    return length(a - b) < LINEAR_TOL;
}
inline bool samePoint(const Vec3 &a, const Vec3 &b) {
    return length(a - b) < LINEAR_TOL;
}
