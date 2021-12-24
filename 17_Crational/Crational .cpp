#include <iostream>

using namespace std;

class CRational {
private:
    //поля
    int num; //числитель
    int denom; //знаменатель
    int gcd(int a, int b) {
        while (a != b) {
            if (a > b) {
                int tmp = a;
                a = b;
                b = tmp;
            }
            b = b - a;
        }
        return a;
    }
    void reduct() {
        int a = gcd(num, denom);
        while (a != 1) {
            num /= a;
            denom /= a;
            a = gcd(num, denom);
        }
    }
    CRational() {
        num = 0;
        denom = 1;
    }
public:
    //инициализация двумя числами
    CRational(int n, int den) {
        if (den == 0) {
            cout << "wrong input";
            exit(1);
        }
        num = n;
        denom = den;
        reduct();
    }

    static CRational add(CRational a, CRational b) {
        CRational res;
        res.num = a.num * b.denom + a.denom * b.num;
        res.denom = b.denom * a.denom;
        res.reduct();
        return res;
    }

    static CRational mul(CRational a, CRational b) {
        CRational res;
        res.num = a.num * b.num;
        res.denom = b.denom * a.denom;
        res.reduct();
        return res;
    }

    void print() {
        if (num == denom) {
            cout << num;
        } else if (num > denom) {
            cout << num / denom << " " << num % denom << "/" << denom;
        } else {
            cout << num % denom << "/" << denom;
        }
        cout << endl;
    }
};

int main() {
    CRational a = CRational(1, 3);
    CRational b = CRational(1, 4);
    //public методы можно вызывать отовсюду
    //а если он static, то не нужно указывать вызывающий объект, в отличие от print()
    CRational c = CRational::add(a, b);
    c.print();
    a = CRational(2, 0);
    b = CRational(3, 4);
    c = CRational::mul(a, b);
    c.print();
    return 0;
}