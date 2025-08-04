# Polymorphic Numeric Type System in C++

## Overview

This project demonstrates how to build a polymorphic numeric type system in C++ using a common abstract base class `Numeric` and templated derived classes (`TypedNumeric<T>`). The goal is to create a flexible and extensible framework that allows storing and manipulating various numeric types (such as `int`, `float`, `double`, `char`, `std::complex<double>`, and unsigned types) in a single container using runtime polymorphism.

## Features

- **Support for Multiple Numeric Types**: 
  - `int`, `short`, `long`
  - `float`, `double`
  - `char`
  - `unsigned int`, `unsigned short`, `unsigned long`
  - `std::complex<double>`

- **Arithmetic Operations**:
  - Addition
  - Subtraction
  - Multiplication
  - Division  
  > All operations return a new `Numeric*` result without modifying the original object.

- **Comparison Operations**:
  - `lessThan`, `greaterThan`, and `isEqualTo`

- **Runtime Polymorphism**:
  - Achieved using a non-template base class and template-derived classes
  - Stored in `std::vector<Numeric*>`

- **Dynamic I/O**:
  - `read()` and `write()` methods for interactive input/output
  - Type-specific `toString()` representation

- **Sorting**:
  - Sorts a mixed-type numeric vector based on comparison logic

---

## Project Structure

- `Numeric` (abstract base class):
  - Defines the interface for all numeric types
  - Pure virtual functions for arithmetic, comparison, I/O

- `TypedNumeric<T>` (templated derived class):
  - Implements functionality specific to each numeric type
  - Uses `dynamic_cast` to safely perform type-safe operations

- `main()`:
  - Demonstrates usage of the framework
  - Creates numeric objects, performs operations, and sorts them

---

## Getting Started

### Requirements

- C++11 or later
- Standard C++ compiler (GCC, Clang, MSVC)

### Build and Run

```bash
g++ main.cpp -o NumericAPP.exe
./NumericApp
