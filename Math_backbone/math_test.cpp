#include "math.cpp"
#include <cassert>
#include <iostream>
int main() {
    Vec3 a{1, 2, 3}, b{3, 4, 5};
    Vec3 s = a + b;
    assert(s.x == 4 && s.y == 6 && s.z == 8);
    Vec3 d = b - a;
    assert(d.x == 2 && d.y == 2 && s.z == 2);
    Vec3 m = a * 3;
    assert(m.x == 3 && m.y == 6 && m.z == 9); // was {3, 2} before the fix
    Vec3 m2 = 3 * a;
    assert(m2.x == 3 && m2.y == 6 && m2.z == 9);
    Vec3 n = -a;
    assert(n.x == -1 && n.y == -2 && n.z == -3);

    assert(dot(Vec3{1, 0, 0}, Vec3{0, 1, 1}) == 0);
    assert(cross(Vec3{1, 0, 0}, Vec3{0, 0, 1}) == Vec3{0, 0, 0});
    assert(length(Vec3{1, 2, 2}) == 3);

    auto u = normalized(Vec3{1, 2, 2});
    assert(u && samePoint(*u, Vec3{0.3333, 0.6667, 0.6667}));
    assert(!normalized(Vec3{0, 0, 0}));
    assert(!normalized(Vec3{1e-12, 0, 0}));

    assert(samePoint(Vec3{1, 1, 1}, Vec3{1 + 1e-9, 1, 1}));
    assert(!samePoint(Vec3{1, 1, 1}, Vec3{1.001, 1, 1}));

    std::cout << "All Tests Passed";
}
