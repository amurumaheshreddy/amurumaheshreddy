
#include <memory>

void borrower1(double*);

void borrower2(std::unique_ptr<double[]>*);

void borrower3(std::unique_ptr<double[]>&);

void uniqueness2()
{
    // p is created and owns a section of memory containing 42 numbers
    std::unique_ptr<double[]> p = std::make_unique<double[]>(42);

    // these are all okay but the first method is the most general
    // as it accepts any kind of pointer, not just unique_ptr
    borrower1(p.get());
    borrower2(&p);
    borrower3(p);

    // p dies, so the array is deleted automatically
}