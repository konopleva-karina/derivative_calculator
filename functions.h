#ifndef ACRONIS_FUNCTIONS_H
#define ACRONIS_FUNCTIONS_H

#include <cmath>
<<<<<<< HEAD
=======
#include <iostream>
>>>>>>> 7b9294f... task added
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

<<<<<<< HEAD
        void Print(std::ofstream& fd) const {
            fd << "(";
            lhs.Print(fd);
            fd << " + ";
            rhs.Print(fd);
            fd << ")";
        }
=======
        friend std::ofstream& operator<<(std::ofstream&, const Add&);
>>>>>>> 7b9294f... task added
    };

    template<typename T, typename U>
    struct Sub {
        typedef Sub<T, U> Type;

        Sub(const T& lhs, const U& rhs) : lhs(lhs), rhs(rhs) {
        }

        double operator()(double arg) const;

        T lhs;
        U rhs;

<<<<<<< HEAD
        void Print(std::ofstream& fd) const {
            lhs.Print(fd);
            fd << " - ";
            rhs.Print(fd);
        }
=======
        friend std::ofstream& operator<<(std::ofstream&, const Sub&);
>>>>>>> 7b9294f... task added
    };

    template<typename T, typename U>
    struct Mul {
        typedef Mul<T, U> Type;

        Mul(const T& lhs, const U& rhs) : lhs(lhs), rhs(rhs) {
        }

        double operator()(double arg) const;

        T lhs;
        U rhs;

<<<<<<< HEAD
        void Print(std::ofstream& fd) const {
            fd << "(";
            lhs.Print(fd);
            fd << ") * (";
            rhs.Print(fd);
            fd << ")";
        }
=======
        friend std::ofstream& operator<<(std::ofstream&, const Mul&);
>>>>>>> 7b9294f... task added
    };

    template<typename T, typename U>
    struct Div {
        typedef Div<T, U> Type;

        Div(const T& lhs, const U& rhs) : lhs(lhs), rhs(rhs) {
        }

        double operator()(double arg) const;

        T lhs;
        U rhs;

<<<<<<< HEAD
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
=======
        friend std::ofstream& operator<<(std::ofstream&, const Div&);

    };

    template<typename T, double U>
    struct Pow {
        typedef Pow<T, U> Type;

        explicit Pow(const T& base, double exp) : base(base), exp(exp) {
>>>>>>> 7b9294f... task added
        }

        double operator()(double arg) const;

<<<<<<< HEAD
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
=======
        T base;
        double exp;

        friend std::ofstream& operator<<(std::ofstream&, const Pow&);
    };

    template<double Base, typename Func>
    struct Log {
        typedef Log<Base, Func> Type;

        Log(double lhs, const Func& rhs) : base(base), func(func) {
>>>>>>> 7b9294f... task added
        }

        double operator()(double arg) const;

        double base;
        Func func;

<<<<<<< HEAD
        void Print(std::ofstream& fd) const {
            fd << "Log_";
            fd << base;
            fd << "_(";
            func.Print(fd);
            fd << ")";
        }
=======
        friend std::ofstream& operator<<(std::ofstream&, const Log&);
>>>>>>> 7b9294f... task added
    };

    template<typename Func>
    struct Sin {
        typedef Sin<Func> Type;
        explicit Sin(const Func& func) : func(func) {
        }

        double operator()(double arg) const;

        Func func;

<<<<<<< HEAD
        void Print(std::ofstream& fd) const {
            fd << "sin(";
            func.Print(fd);
            fd << ")";
        }
=======
        friend std::ofstream& operator<<(std::ofstream&, const Sin&);

>>>>>>> 7b9294f... task added
    };

    template<typename Func>
    struct Cos {
        typedef Cos<Func> Type;
        explicit Cos(const Func& func) : func(func) {
        }

        double operator()(double arg) const;

        Func func;

<<<<<<< HEAD
        void Print(std::ofstream& fd) const {
            fd << "cos(";
            func.Print(fd);
            fd << ")";
        }
=======
        friend std::ofstream& operator<<(std::ofstream&, const Cos&);
>>>>>>> 7b9294f... task added
    };

    template<typename Func>
    struct Tg {
        typedef Tg<Func> Type;
        explicit Tg(const Func& func) : func(func) {
        }

        double operator()(double arg) const;

        Func func;

<<<<<<< HEAD
        void Print(std::ofstream& fd) const {
            fd << "tg(";
            func.Print(fd);
            fd << ")";
        }
=======
        friend std::ofstream& operator<<(std::ofstream&, const Tg&);
>>>>>>> 7b9294f... task added
    };

    template<typename Func>
    struct Ctg {
        typedef Ctg<Func> Type;
        explicit Ctg(const Func& func) : func(func) {
        }

        double operator()(double arg) const;

        Func func;

<<<<<<< HEAD
        void Print(std::ofstream& fd) const {
            fd << "ctg(";
            func.Print(fd);
            fd << ")";
        }
=======
        friend std::ofstream& operator<<(std::ofstream&, const Ctg&);
>>>>>>> 7b9294f... task added
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

<<<<<<< HEAD
template<typename Base>
double Derivatives::Pow<Base>::operator()(double arg) const {
    return pow(base(arg), exp);
}

template<typename Func>
double Derivatives::Log<Func>::operator()(double arg) const {
=======
template<typename T, double U>
double Derivatives::Pow<T, U>::operator()(double arg) const {
    return pow(base(arg), exp);
}

template<double Base, typename Func>
double Derivatives::Log<Base, Func>::operator()(double arg) const {
>>>>>>> 7b9294f... task added
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

<<<<<<< HEAD
=======
template<typename T, typename U>
std::ofstream& operator<<(std::ofstream& fd, const Derivatives::Add<T, U>& add) {
    fd << add.lhs << " + " << add.rhs;
}

template<typename T, typename U>
std::ofstream& operator<<(std::ofstream& fd, const Derivatives::Sub<T, U>& sub) {
    fd << sub.lhs << " - " << sub.rhs;
}

template<typename T, typename U>
std::ofstream& operator<<(std::ofstream& fd, const Derivatives::Mul<T, U>& mul) {
    fd << mul.lhs << " - " << mul.rhs;
}

template<typename T, typename U>
std::ofstream& operator<<(std::ofstream& fd, const Derivatives::Div<T, U>& div) {
    fd << div.lhs << " - " << div.rhs;
}


template<typename T, double U>
std::ofstream& operator<<(std::ofstream& fd, const Derivatives::Pow<T, U>& pow) {
    if (pow.exp == 0.5) {
        fd << "sqrt(" << pow.base << ")";
    } else {
        fd << pow.base << "^(" << pow.exp << ")";
    }
}

template<double Base, typename Func>
std::ofstream& operator<<(std::ofstream& fd, const Derivatives::Log<Base, Func>& log) {
    fd << "Log_" << log.base << "_(" << log.func << ")";
}

template<typename Func>
std::ofstream& operator<<(std::ofstream& fd, const Derivatives::Sin<Func>& sin) {
    fd << "sin(" << sin.func << ")";
}

template<typename Func>
std::ofstream& operator<<(std::ofstream& fd, const Derivatives::Cos<Func>& cos) {
    fd << "cos(" << cos.func << ")";
}

template<typename Func>
std::ofstream& operator<<(std::ofstream& fd, const Derivatives::Tg<Func>& tg) {
    fd << "tg(" << tg.func << ")";
}

template<typename Func>
std::ofstream& operator<<(std::ofstream& fd, const Derivatives::Ctg<Func>& ctg) {
    fd << "ctg(" << ctg.func << ")";
}

>>>>>>> 7b9294f... task added
#endif //ACRONIS_FUNCTIONS_H
