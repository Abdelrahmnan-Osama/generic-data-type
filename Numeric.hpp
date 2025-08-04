#include <iostream>
#include <complex>
#include <exception>
#include <vector>
#include <algorithm>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////
//                                   Abstract Class
///////////////////////////////////////////////////////////////////////////////////////

class Numeric
{
public:
    virtual Numeric *add(Numeric *other) const = 0;
    virtual Numeric *subtract(Numeric *other) const = 0;
    virtual Numeric *multiply(Numeric *other) const = 0;
    virtual Numeric *divide(Numeric *other) const = 0;

    virtual bool lessThan(Numeric *other) const = 0;
    virtual bool greaterThan(Numeric *other) const = 0;
    virtual bool isEqualTo(Numeric *other) const = 0;

    virtual string toString() const = 0;
    virtual void read() = 0;
    virtual void write() const = 0;
};

///////////////////////////////////////////////////////////////////////////////////////
//                                 Derived Template Class
///////////////////////////////////////////////////////////////////////////////////////

template <class T>
class TypedNumeric : public Numeric
{
private:
    T number;

    TypedNumeric<T> *convertToChild(Numeric *other) const
    {
        TypedNumeric<T> *childPtr = dynamic_cast<TypedNumeric<T> *>(other);
        if (childPtr == nullptr)
        {
            throw bad_cast();
        }

        return childPtr;
    }

public:
    TypedNumeric(T number = 0) : number(number) {}

    Numeric *add(Numeric *other) const override
    {
        try
        {
            TypedNumeric<T> *childPtr = convertToChild(other);
            return new TypedNumeric<T>(this->number + childPtr->number);
        }
        catch (const bad_cast &e)
        {
            std::cerr << "Invalid type: cannot add different Numeric types.\n";
            return nullptr;
        }
    }
    Numeric *subtract(Numeric *other) const override
    {
        try
        {
            TypedNumeric<T> *childPtr = convertToChild(other);
            return new TypedNumeric<T>(this->number - childPtr->number);
        }
        catch (const bad_cast &e)
        {
            std::cerr << "Invalid type: cannot subtract different Numeric types.\n";
            return nullptr;
        }
    }
    Numeric *multiply(Numeric *other) const override
    {
        try
        {
            TypedNumeric<T> *childPtr = convertToChild(other);
            return new TypedNumeric<T>(this->number * childPtr->number);
        }
        catch (const bad_cast &e)
        {
            std::cerr << "Invalid type: cannot multiply different Numeric types.\n";
            return nullptr;
        }
    }
    Numeric *divide(Numeric *other) const override
    {
        try
        {
            TypedNumeric<T> *childPtr = convertToChild(other);
            return new TypedNumeric<T>(this->number / childPtr->number);
        }
        catch (const bad_cast &e)
        {
            std::cerr << "Invalid type: cannot divide different Numeric types.\n";
            return nullptr;
        }
    }

    bool lessThan(Numeric *other) const override;
    bool greaterThan(Numeric *other) const override;
    bool isEqualTo(Numeric *other) const override;

    string toString() const override;
    void read() override;
    void write() const override;
};

///////////////////////////////////////////////////////////////////////////////////////
//                                     Generics
///////////////////////////////////////////////////////////////////////////////////////

template <class T>
inline bool TypedNumeric<T>::isEqualTo(Numeric *other) const
{
    try
    {
        TypedNumeric<T> *childPtr = convertToChild(other);
        return (this->number == childPtr->number);
    }
    catch (const bad_cast &e)
    {
        return false;
    }
}

template <class T>
inline bool TypedNumeric<T>::lessThan(Numeric *other) const
{
    try
    {
        TypedNumeric<T> *childPtr = convertToChild(other);
        return (this->number < childPtr->number);
    }
    catch (const bad_cast &e)
    {
        return false;
    }
}

template <class T>
inline bool TypedNumeric<T>::greaterThan(Numeric *other) const
{
    try
    {
        TypedNumeric<T> *childPtr = convertToChild(other);
        return (this->number > childPtr->number);
    }
    catch (const bad_cast &e)
    {
        return false;
    }
}

template <class T>
inline string TypedNumeric<T>::toString() const
{
    return std::string(typeid(T).name()) + ": " + std::to_string(number);
}

template <class T>
inline void TypedNumeric<T>::read()
{
    cout << "Enter a numeric value: ";
    cin >> number;
}

template <class T>
inline void TypedNumeric<T>::write() const
{
    cout << toString() << endl;
}

///////////////////////////////////////////////////////////////////////////////////////
//                                 Specializations
///////////////////////////////////////////////////////////////////////////////////////

// Specialization for complex
template <>
inline bool TypedNumeric<complex<double>>::isEqualTo(Numeric *other) const
{
    try
    {
        TypedNumeric<complex<double>> *childPtr = convertToChild(other);
        return (this->number == childPtr->number);
    }
    catch (const bad_cast &e)
    {
        return false;
    }
}

// Specialization for complex
template <>
inline bool TypedNumeric<complex<double>>::lessThan(Numeric *other) const
{
    try
    {
        TypedNumeric<complex<double>> *childPtr = convertToChild(other);
        return (abs(this->number) < abs(childPtr->number));
    }
    catch (const bad_cast &e)
    {
        return false;
    }
}

// Specialization for complex
template <>
inline bool TypedNumeric<complex<double>>::greaterThan(Numeric *other) const
{
    try
    {
        TypedNumeric<complex<double>> *childPtr = convertToChild(other);
        return (abs(this->number) > abs(childPtr->number));
    }
    catch (const bad_cast &e)
    {
        return false;
    }
}

// Specialization for int
template <>
inline std::string TypedNumeric<int>::toString() const
{
    return "int: " + std::to_string(number);
}

// Specialization for short
template <>
inline std::string TypedNumeric<short>::toString() const
{
    return "short: " + std::to_string(number);
}

// Specialization for long
template <>
inline std::string TypedNumeric<long>::toString() const
{
    return "long: " + std::to_string(number);
}

// Specialization for float
template <>
inline std::string TypedNumeric<float>::toString() const
{
    return "float: " + std::to_string(number);
}

// Specialization for double
template <>
inline std::string TypedNumeric<double>::toString() const
{
    return "double: " + std::to_string(number);
}

// Specialization for char
template <>
inline std::string TypedNumeric<char>::toString() const
{
    return std::string("char: ") + number;
}

// Specialization for unsigned int
template <>
inline std::string TypedNumeric<unsigned int>::toString() const
{
    return "unsigned int: " + std::to_string(number);
}

// Specialization for unsigned short
template <>
inline std::string TypedNumeric<unsigned short>::toString() const
{
    return "unsigned short: " + std::to_string(number);
}

// Specialization for unsigned long
template <>
inline std::string TypedNumeric<unsigned long>::toString() const
{
    return "unsigned long: " + std::to_string(number);
}

// Specialization for complex
template <>
inline string TypedNumeric<complex<double>>::toString() const
{
    string complexStr = "complex<double>: " + to_string(number.real()) + " + " + to_string(number.imag()) + "i";
    return complexStr;
}

// int specialization
template <>
inline void TypedNumeric<int>::read()
{
    std::cout << "Enter an integer: ";
    std::cin >> number;
}

// short specialization
template <>
inline void TypedNumeric<short>::read()
{
    std::cout << "Enter a short integer: ";
    std::cin >> number;
}

// long specialization
template <>
inline void TypedNumeric<long>::read()
{
    std::cout << "Enter a long integer: ";
    std::cin >> number;
}

// float specialization
template <>
inline void TypedNumeric<float>::read()
{
    std::cout << "Enter a float: ";
    std::cin >> number;
}

// double specialization
template <>
inline void TypedNumeric<double>::read()
{
    std::cout << "Enter a double: ";
    std::cin >> number;
}

// char specialization
template <>
inline void TypedNumeric<char>::read()
{
    std::cout << "Enter a character: ";
    std::cin >> number;
}

// unsigned int specialization
template <>
inline void TypedNumeric<unsigned int>::read()
{
    std::cout << "Enter an unsigned integer: ";
    std::cin >> number;
}

// unsigned short specialization
template <>
inline void TypedNumeric<unsigned short>::read()
{
    std::cout << "Enter an unsigned short: ";
    std::cin >> number;
}

// unsigned long specialization
template <>
inline void TypedNumeric<unsigned long>::read()
{
    std::cout << "Enter an unsigned long: ";
    std::cin >> number;
}

// complex specialization
template <>
inline void TypedNumeric<complex<double>>::read()
{
    double r, i;

    cout << "Enter the real part: ";
    cin >> r;

    cout << "Enter the imaginary part: ";
    cin >> i;

    number.real(r);
    number.imag(i);
}
