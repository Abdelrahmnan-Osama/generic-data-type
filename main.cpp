#include "Numeric.hpp"

int main(int argc, char const *argv[])
{
    TypedNumeric<int> int1(20);
    TypedNumeric<int> int2(10);

    // ------------------------

    TypedNumeric<float> float1(2.5f);
    TypedNumeric<float> float2(1.5f);

    // ------------------------

    TypedNumeric<double> double1(2.71);
    TypedNumeric<double> double2(3.14);

    // ------------------------

    TypedNumeric<unsigned int> uint1(200u);
    TypedNumeric<unsigned int> uint2(100u);

    // ------------------------

    TypedNumeric<std::complex<double>> cmplx1(std::complex<double>(2.0, 3.0));
    TypedNumeric<std::complex<double>> cmplx2(std::complex<double>(1.0, 1.0));

    // -------------------------

    std::vector<Numeric *> v;

    v.push_back(&int1);
    v.push_back(&int2);

    v.push_back(&float1);
    v.push_back(&float2);

    v.push_back(&double1);
    v.push_back(&double2);

    v.push_back(&uint1);
    v.push_back(&uint2);

    v.push_back(&cmplx1);
    v.push_back(&cmplx2);

    for (size_t i = 0; i < v.size(); i++)
    {
        v[i]->write();
    }
    cout << endl;

    // -------------------------

    // Math Operations
    for (size_t i = 0; i < v.size(); i += 2)
    {
        if (i % 2 == 0)
        {
            Numeric *result = v[i]->add(v[i + 1]);
            if (result != nullptr)
            {
                result->write();
            }
        }
    }
    cout << endl;

    // -------------------------

    // ascending order sorting per type
    sort(v.begin(), v.end(), [](Numeric *a, Numeric *b)
         { return a->lessThan(b); });

    for (size_t i = 0; i < v.size(); i++)
    {

        v[i]->write();
    }

    return 0;
}
