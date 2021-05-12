#ifndef ACRONIS_FUNCTIONS_H
#define ACRONIS_FUNCTIONS_H

#include <cmath>
#include <fstream>
#include "types.h"

namespace Derivatives {
    template<typename T, typename U>
    struct Add {
        typedef Add<T, U> Type;

        Add(const T& lhs, const U& rhs) : lhs(lhs), rhs(rhs) {
        }

        double operator()(double arg) const;

        T lhs;
        U rhs;

        void Print(std::ofstream& fd) const {
            fd << "(";
            lhs.Print(fd);
            fd << " + ";
            rhs.Print(fd);
            fd << ")";
        }
    };

    template<typename T, typename U>
    struct Sub {
        typedef Sub<T, U> Type;

        Sub(const T& lhs, const U& rhs) : lhs(lhs), rhs(rhs) {
        }

        double operator()(double arg) const;

        T lhs;
        U rhs;

        void Print(std::ofstream& fd) const {
            lhs.Print(fd);
            fd << " - ";
            rhs.Print(fd);
        }
    };

    template<typename T, typename U>
    struct Mul {
        typedef Mul<T, U> Type;

        Mul(const T& lhs, const U& rhs) : lhs(lhs), rhs(rhs) {
        }

        double operator()(double arg) const;

        T lhs;
        U rhs;

        void Print(std::ofstream& fd) const {
            fd << "(";
            lhs.Print(fd);
            fd << ") * (";
            rhs.Print(fd);
            fd << ")";
        }
    };

    template<typename T, typename U>
    struct Div {
        typedef Div<T, U> Type;

        Div(const T& lhs, const U& rhs) : lhs(lhs), rhs(rhs) {
        }

        double operator()(double arg) const;

        T lhs;
        U rhs;

        void Print(std::ofstream& fd) const {
            lhs.Print(fd);
            fd << " / ";
            rhs.Print(fd);
        }
    };

    template<typename Base>
    struct Pow {
        typedef Pow<Base> Type;

        Pow(const Base& base, double exp) : base(base), exp(exp) {
        }

        double operator()(double arg) const;

        Base base;
        double exp;

        void Print(std::ofstream& fd) const {
            if (exp == 0.5) {
                fd << "sqrt(";
                base.Print(fd);
                fd << ")";
            } else {
                fd << "(";
                base.Print(fd);
                fd << ")^(";
                fd << exp;
                fd << ")";
            }
        }
    };

    template<typename Func>
    struct Log {
        typedef Log<Func> Type;

        Log(double base, const Func& func) : base(base), func(func) {
        }

        double operator()(double arg) const;

        double base;
        Func func;

        void Print(std::ofstream& fd) const {
            fd << "Log_";
            fd << base;
            fd << "_(";
            func.Print(fd);
            fd << ")";
        }
    };

    template<typename Func>
    struct Sin {
        typedef Sin<Func> Type;
        explicit Sin(const Func& func) : func(func) {
        }

        double operator()(double arg) const;

        Func func;

        void Print(std::ofstream& fd) const {
            fd << "sin(";
            func.Print(fd);
            fd << ")";
        }
    };

    template<typename Func>
    struct Cos {
        typedef Cos<Func> Type;
        explicit Cos(const Func& func) : func(func) {
        }

        double operator()(double arg) const;

        Func func;

        void Print(std::ofstream& fd) const {
            fd << "cos(";
            func.Print(fd);
            fd << ")";
        }
    };

    template<typename Func>
    struct Tg {
        typedef Tg<Func> Type;
        explicit Tg(const Func& func) : func(func) {
        }

        double operator()(double arg) const;

        Func func;

        void Print(std::ofstream& fd) const {
            fd << "tg(";
            func.Print(fd);
            fd << ")";
        }
    };

    template<typename Func>
    struct Ctg {
        typedef Ctg<Func> Type;
        explicit Ctg(const Func& func) : func(func) {
        }

        double operator()(double arg) const;

        Func func;

        void Print(std::ofstream& fd) const {
            fd << "ctg(";
            func.Print(fd);
            fd << ")";
        }
    };
}

template<typename T, typename U>
double Derivatives::Add<T, U>::operator()(double arg) const {
    return lhs(arg) + rhs(arg);
}

template<typename T, typename U>
double Derivatives::Sub<T, U>::operator()(double arg) const {
    return lhs(arg) - rhs(arg);
}

template<typename T, typename U>
double Derivatives::Mul<T, U>::operator()(double arg) const {
    return lhs(arg) * rhs(arg);
}

template<typename T, typename U>
double Derivatives::Div<T, U>::operator()(double arg) const {
    return lhs(arg) / rhs(arg);
}

template<typename Base>
double Derivatives::Pow<Base>::operator()(double arg) const {
    return pow(base(arg), exp);
}

template<typename Func>
double Derivatives::Log<Func>::operator()(double arg) const {
    return 1 / log(base) * log(func(arg));
}

template<typename Func>
double Derivatives::Sin<Func>::operator()(double arg) const {
    return sin(func(arg));
}

template<typename Func>
double Derivatives::Cos<Func>::operator()(double arg) const {
    return cos(func(arg));
}

template<typename Func>
double Derivatives::Tg<Func>::operator()(double arg) const {
    return tan(func(arg));
}

template<typename Func>
double Derivatives::Ctg<Func>::operator()(double arg) const {
    return 1 / tan(func(arg));
}

#endif //ACRONIS_FUNCTIONS_H
