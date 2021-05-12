#ifndef ACRONIS_DERIVATIVE_CALCULATOR_H
#define ACRONIS_DERIVATIVE_CALCULATOR_H

#include <functional>
#include "types.h"
#include "functions.h"

namespace Derivatives {
    template<typename Func>
    struct DerivativesCalculator {
        typedef std::function<double(double)> Type;

        DerivativesCalculator(const Func& func, double increment=0.01) : func(func), increment(increment) {
        }

        Type derivative() const {
            return [this](double arg) -> double {
                return (func(arg + increment) - func(arg)) / increment;
            };
        }

        double operator()(double x) const {
            return (func(x + increment) - func(x)) / increment;
        }

        void Print(std::ofstream& fd) const {
            fd << 0;
        }

        Func func;
        double increment;
    };

    template<>
    struct DerivativesCalculator<Const> {
        typedef Const Type;

        DerivativesCalculator<Const>(Const) {
        }

        double operator()(double) const {
            return 0;
        }

        Type derivative() const {
            return Const(0);
        }

        void Print(std::ofstream& fd) const {
            fd << 0;
        }
    };

    template<>
    struct DerivativesCalculator<Argument> {
        typedef Const Type;
        DerivativesCalculator<Argument>(Argument) {
        }

        double operator()(double) const {
            return 1;
        }

        Type derivative() const {
            return Const(1);
        }

        void Print(std::ofstream& fd) const {
            fd << 1;
        }
    };

    //---------------------------------------- (f + g)' --------------------------------------------//
    template<>
    struct DerivativesCalculator<Add<Const, Const>> {
        typedef Const Type;

        DerivativesCalculator<Add<Const, Const>>(const Add<Const, Const>&) {
        }

        double operator()(double) const{
            return 0;
        }

        Type derivative() const {
            return Const(0);
        }

        void Print(std::ofstream& fd) const {
            fd << 0;
        }
    };

    template<>
    struct DerivativesCalculator<Add<Argument, Argument>> {
        typedef Const Type;

        DerivativesCalculator<Add<Argument, Argument>>(const Add<Argument, Argument>&) {
        }

        double operator()(double) const{
            return 2;
        }

        Type derivative() const {
            return Const(2);
        }

        void Print(std::ofstream& fd) const {
            fd << 2;
        }
    };

    template<typename T>
    struct DerivativesCalculator<Add<Const, T>> {
        typedef typename DerivativesCalculator<T>::Type Type;

        DerivativesCalculator<Add<Const, T>>(const Add<Const, T>& add) : rhs(add.rhs) {
        }

        double operator()(double arg) const {
            return rhs(arg);
        }

        Type derivative() const {
            return rhs.derivative();
        }

        void Print(std::ofstream& fd) const {
            rhs.Print(fd);
        }

        DerivativesCalculator<T> rhs;
    };

    template<typename T>
    struct DerivativesCalculator<Add<T, Const>> {
        typedef typename DerivativesCalculator<T>::Type Type;

        DerivativesCalculator<Add<T, Const>>(const Add<T, Const>& add) : lhs(add.lhs) {
        }

        double operator()(double arg) const {
            return lhs(arg);
        }

        Type derivative() const {
            return lhs.derivative();
        }

        void Print(std::ofstream& fd) const {
            lhs.Print(fd);
        }

        DerivativesCalculator<T> lhs;
    };

    template<typename T, typename U>
    struct DerivativesCalculator<Add<T, U>> {
        typedef Add<typename DerivativesCalculator<T>::Type, typename DerivativesCalculator<U>::Type> Type;

        DerivativesCalculator<Add<T, U>>(const Add<T, U>& add)
                : lhs(add.lhs), rhs(add.rhs) {
        }

        double operator()(double arg) const {
            return lhs(arg) + rhs(arg);
        }

        Type derivative() const {
            return lhs.derivative() + rhs.derivative();
        }

        void Print(std::ofstream& fd) const {
            fd << "(";
            lhs.Print(fd);
            fd << ") + (";
            rhs.Print(fd);
            fd << ")";
        }

        DerivativesCalculator<T> lhs;
        DerivativesCalculator<U> rhs;
    };

    //---------------------------------------- (f - g)' --------------------------------------------//
    template<>
    struct DerivativesCalculator<Sub<Const, Const>> {
        typedef Const Type;

        DerivativesCalculator<Sub<Const, Const>>(const Sub<Const, Const>&) {
        }

        double operator()(double) const{
            return 0;
        }

        Type derivative() const {
            return Const(0);
        }

        void Print(std::ofstream& fd) const {
            fd << 0;
        }
    };

    template<>
    struct DerivativesCalculator<Sub<Argument, Argument>> {
        typedef Const Type;

        DerivativesCalculator<Sub<Argument, Argument>>(const Sub<Argument, Argument>&) {
        }

        double operator()(double) const{
            return 0;
        }

        Type derivative() const {
            return Const(0);
        }

        void Print(std::ofstream& fd) const {
            fd << 0;
        }
    };

    template<typename T>
    struct DerivativesCalculator<Sub<Const, T>> {
        typedef typename DerivativesCalculator<T>::Type Type;

        DerivativesCalculator<Sub<Const, T>>(const Sub<Const, T>& add) : rhs(add.rhs) {
        }

        double operator()(double arg) const {
            return rhs(arg);
        }

        Type derivative() const {
            return -rhs.derivative();
        }

        void Print(std::ofstream& fd) const {
            (-rhs).Print(fd);
        }

        DerivativesCalculator<T> rhs;
    };

    template<typename T>
    struct DerivativesCalculator<Sub<T, Const>> {
        typedef typename DerivativesCalculator<T>::Type Type;

        DerivativesCalculator<Sub<T, Const>>(const Sub<T, Const>& sub) : lhs(sub.lhs) {
        }

        double operator()(double arg) const {
            return lhs(arg);
        }

        Type derivative() const {
            return lhs.derivative();
        }

        void Print(std::ofstream& fd) const {
            lhs.Print(fd);
        }

        DerivativesCalculator<T> lhs;
    };

    template<typename T, typename U>
    struct DerivativesCalculator<Sub<T, U>> {
        typedef Sub<typename DerivativesCalculator<T>::Type, typename DerivativesCalculator<U>::Type> Type;

        DerivativesCalculator<Sub<T, U>>(const Sub<T, U>& add)
                : lhs(add.lhs), rhs(add.rhs) {
        }

        double operator()(double arg) const {
            return lhs(arg) - rhs(arg);
        }

        Type derivative() const {
            return lhs.derivative() - rhs.derivative();
        }

        void Print(std::ofstream& fd) const {
            fd << "(";
            lhs.Print(fd);
            fd << " - ";
            rhs.Print(fd);
            fd << ")";
        }

        DerivativesCalculator<T> lhs;
        DerivativesCalculator<U> rhs;
    };

    //---------------------------------------- (f * g)' --------------------------------------------//
    template<>
    struct DerivativesCalculator<Mul<Const, Const>> {
        typedef Const Type;

        DerivativesCalculator<Mul<Const, Const>>(const Mul<Const, Const>&) {
        }

        double operator()(double) const{
            return 0;
        }

        Type derivative() const {
            return Const(0);
        }

        void Print(std::ofstream& fd) const {
            fd << 0;
        }
    };

    template<typename F>
    struct DerivativesCalculator<Mul<Const, F>> {
        typedef typename DerivativesCalculator<F>::Type Type;

        DerivativesCalculator<Mul<Const, F>>(const Mul<Const, F>& mul) : c(mul.lhs), df(mul.rhs) {
        }

        double operator()(double arg) const {
            return c.value * df(arg);
        }

        Type derivative() const {
            return  c * df.derivative();
        }

        void Print(std::ofstream& fd) const {
            fd << "(";
            c.Print(fd);
            fd << " * ";
            df.Print(fd);
            fd << ")";
        }

        Const c;
        DerivativesCalculator<F> df;
    };

    template<typename F>
    struct DerivativesCalculator<Mul<F, Const>> {
        typedef typename DerivativesCalculator<F>::Type Type;

        DerivativesCalculator<Mul<F, Const>>(const Mul<F, Const>& mul) : c(mul.rhs), df(mul.lhs) {
        }

        double operator()(double arg) const {
            return c.value * df(arg);
        }

        Type derivative() const {
            return c * df.derivative();
        }

        void Print(std::ofstream& fd) const {
            fd << "(";
            c.Print(fd);
            fd << " * ";
            df.Print(fd);
            fd << ")";
        }

        Const c;
        DerivativesCalculator<F> df;
    };

    template<typename F, typename U>
    struct DerivativesCalculator<Mul<F, U>> {
        typedef Mul<typename DerivativesCalculator<F>::Type, typename DerivativesCalculator<U>::Type> Type;

        DerivativesCalculator<Mul<F, U>>(const Mul<F, U>& mul) : f(mul.lhs), u(mul.rhs), df(mul.lhs), du(mul.rhs) {
        }

        double operator()(double arg) const {
            return f(arg) * du(arg) + u(arg) * df(arg);
        }

        Type derivative() const {
            return f * du.derivative() + u * df.derivative();
        }

        void Print(std::ofstream& fd) const {
            fd << "(";
            f.Print(fd);
            fd << ") * (";
            du.Print(fd);
            fd << ") + (";
            u.Print(fd);
            fd << ") * (";
            df.Print(fd);
            fd << ")";
        }

        F f;
        U u;
        DerivativesCalculator<F> df;
        DerivativesCalculator<U> du;
    };

    //---------------------------------------- (f / g)' --------------------------------------------//
    template<>
    struct DerivativesCalculator<Div<Const, Const>> {
        typedef Const Type;

        DerivativesCalculator<Div<Const, Const>>(const Div<Const, Const>&) {
        }

        double operator()(double) const{
            return 0;
        }

        Type derivative() const {
            return Const(0);
        }

        void Print(std::ofstream& fd) const {
            fd << 0;
        }
    };

    template<typename F>
    struct DerivativesCalculator<Div<Const, F>> {
        typedef typename DerivativesCalculator<F>::Type Type;

        DerivativesCalculator<Div<Const, F>>(const Div<Const, F>& mul) : c(mul.lhs), f(mul.rhs) {
        }

        double operator()(double arg) const {
            return -c.value * (1 / Pow(f(arg), 2));
        }

        Type derivative() const {
            return -c.value * (1 / Pow(f, 2));
        }

        void Print(std::ofstream& fd) const {
            fd << "-";
            (c / Pow(f, 2)).Print(fd);
        }

        Const c;
        F f;
    };

    template<typename F>
    struct DerivativesCalculator<Div<F, Const>> {
        typedef typename DerivativesCalculator<F>::Type Type;

        DerivativesCalculator<Div<F, Const>>(const Div<F, Const>& mul) : c(mul.rhs), df(mul.lhs) {
        }

        double operator()(double arg) const {
            return df(arg) / c.value;
        }

        Type derivative() const {
            return df.derivative() / c.value;
        }

        void Print(std::ofstream& fd) const {
            fd << "(";
            df.Print(fd);
            fd << ") / (";
            c.Print(fd);
            fd << ")";
        }

        Const c;
        DerivativesCalculator<F> df;
    };

    template<typename F, typename U>
    struct DerivativesCalculator<Div<F, U>> {
        typedef Div<typename DerivativesCalculator<F>::Type, typename DerivativesCalculator<U>::Type> Type;

        DerivativesCalculator<Div<F, U>>(const Div<F, U>& mul) : f(mul.lhs), u(mul.rhs), df(mul.lhs), du(mul.rhs) {
        }

        double operator()(double arg) const {
            return f(arg) * du(arg) + u(arg) * df(arg);
        }

        Type derivative() const {
            return (u * df.derivative() - f * du.derivative()) * Pow(u, -2) ;
        }

        void Print(std::ofstream& fd) const {
            fd << "(";
            (u * df).Print(fd);
            fd << ") - (";
            (f * du).Print(fd);
            fd << ") / (";
            Pow(u, 2).Print(fd);
            fd << ")";
        }

        F f;
        U u;
        DerivativesCalculator<F> df;
        DerivativesCalculator<U> du;
    };

    //---------------------------------------- (sin)' --------------------------------------------//
    template<>
    struct DerivativesCalculator<Sin<Const>> {
        typedef Const Type;

        DerivativesCalculator<Sin<Const>>(const Sin<Const>&) {
        }

        double operator()(double) const{
            return 0;
        }

        Type derivative() const {
            return Const(0);
        }

        void Print(std::ofstream& fd) const {
            fd << 0;
        }
    };

    template<typename F>
    struct DerivativesCalculator<Sin<F>> {
        typedef typename DerivativesCalculator<F>::Type Type;

        DerivativesCalculator<Sin<F>>(const Sin<F>& sin) : arg(sin.func), df(sin.func) {
        }

        double operator()(double a) const {
            return cos(arg(a)) * df(a);
        }

        Type derivative() const {
            return Cos(arg) * df.derivative();
        }

        void Print(std::ofstream& fd) const {
            Cos(arg).Print(fd);
            fd << "*";
            df.Print(fd);
        }

        F arg;
        DerivativesCalculator<F> df;
    };
}

#endif //ACRONIS_DERIVATIVE_CALCULATOR_H
