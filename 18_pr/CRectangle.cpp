#include <iostream>
#include <fstream>

class CRectangleClass {
private:
    double minX;
    double minY;
    double maxY;
    double maxX;
public:
    CRectangleClass(
        double minX,
        double maxX,
        double minY,
        double maxY
    ) {
        this->minX = minX;
        this->minY = minY;
        this->maxY = maxY;
        this->maxX = maxX;
    }
    static bool isInterset(
        const CRectangleClass & rect1, 
        const CRectangleClass & rect2
    ) {
        int conditions = 0;
        
        if ((rect1.maxX >= rect2.minX && rect1.minX <= rect2.minX) || (rect2.maxX >= rect1.minX && rect2.minX <= rect1.minX)) {
            conditions++;
        }

        if ((rect1.maxY >= rect2.minY && rect1.minY <= rect2.minY) || (rect2.maxY >= rect1.minY && rect2.minY <= rect1.minY)) {
            conditions++;
        }

        return conditions == 2;
    }
};

int main()
{
    double x1, y1, x2, y2;
    std::ifstream fin;
    fin.open("input.txt");
    fin >> x1 >> x2 >> y1 >> y2;
    CRectangleClass rect1(x1, x2, y1, y2);
    fin >> x1 >> x2 >> y1 >> y2;
    fin.close();
    CRectangleClass rect2(x1, x2, y1, y2);
    std::cout << CRectangleClass::isInterset(rect1, rect2) << std::endl;
}
