#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    double x;
    double y;
};

void move_by(Point* p, double dx, double dy) {
    p->x = p->x + dx;
    p->y = p->y + dy;
}

double dist(const Point* a, const Point* b) {
    double dx = a->x - b->x;
    double dy = a->y - b->y;

    return sqrt(dx * dx + dy * dy);
}

void move_by_ref(Point& p, double dx, double dy) {
    p.x = p.x + dx;
    p.y = p.y + dy;
}

double dist_ref(const Point& a, const Point& b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;

    return sqrt(dx * dx + dy * dy);
}

int main() {
    Point p1 = {1, 2};
    Point p2 = {4, 6};

    move_by(&p1, 2, 3);

    cout << "Pointer udaljenost: " << dist(&p1, &p2) << endl;

    move_by_ref(p1, 1, 1);

    cout << "Referenca udaljenost: " << dist_ref(p1, p2) << endl;

    Point niz[5] = {
        {3, 4},
        {1, 2},
        {5, 6},
        {0.5, 0.5},
        {2, 3}
    };

    int najbliza = 0;
    double najmanja = dist(&niz[0], new Point{0, 0});

    for (int i = 1; i < 5; i++) {
        double udaljenost = sqrt(
            niz[i].x * niz[i].x + niz[i].y * niz[i].y
        );

        if (udaljenost < najmanja) {
            najmanja = udaljenost;
            najbliza = i;
        }
    }

    cout << "Tocka najbliza ishodistu je: ("
         << niz[najbliza].x << ", "
         << niz[najbliza].y << ")" << endl;

    return 0;
}