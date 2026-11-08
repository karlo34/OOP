#include #include using namespace std;

class Volume {
private:
    int l = 50;
    int previous = 50;
    int step = 10;

    static int clamp(int value) {
        if (value < 0)
            return 0;
        if (value > 100)
            return 100;
        return value;
    }

    bool valid() const {
        return l >= 0 && l <= 100 &&
        previous >= 0 && previous <= 100;
    }

public:
    Volume() {
        assert(valid());
    }

    Volume(int l) {
        this->l = clamp(l);
        previous = this->l;
        assert(valid());
    }

    int get() const {
        return l;
    }

    void up() {
        l = clamp(l + 1);
        assert(valid());
    }

    void up(int step) {
        l = clamp(l + step);
        assert(valid());
    }

    void down(int step) {
        l = clamp(l - step);
        assert(valid());
    }

    void down() {
        l = clamp(l - 1);
        assert(valid());
    }

    void mute() {
    if (l != 0)
        previous = l;
        l = 0;
        assert(valid());
    }

    void unmute() {
        l = previous;
        assert(valid());
    }
};

int main()
{
    Volume v;
    cout << v.get() << '\n';
    v.up();
    v.up(60);
    cout << v.get() << '\n';
    v.mute();
    cout << v.get() << '\n';
    v.unmute();
    cout << v.get() << '\n';

    Volume w(-20);
    w.down();
    cout << w.get() << '\n';

return 0;
}

/*
50
100
0
100
0
*/
