#ifndef ACRONIS_TYPES_H
#define ACRONIS_TYPES_H

#include <fstream>

namespace Derivatives {
    struct Const {
        typedef Const Type;

        Const(int c)  : value(c) {
        }

        Const(double c)  : value(c) {
        }

        double operator() (double) const {
            return value;
        }

        operator int() const {
            return value;
        }

        operator double() const {
            return value;
        }

        double value;

        void Print(std::ofstream& fd) const {
            fd << value;
        }
    };

    struct Argument {
        typedef Argument Type;

        double operator() (double value) const {
            return value;
        }

        void Print(std::ofstream& fd) const {
            fd << "x";
        }
    };
}

#endif //ACRONIS_TYPES_H
