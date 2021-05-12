#ifndef ACRONIS_OPERATORS_H
#define ACRONIS_OPERATORS_H

namespace Derivatives {
<<<<<<< HEAD
    template<class T, class U>
    Add <T, U> operator+(const T &lhs, const U &rhs) {
        return Add<T, U>(lhs, rhs);
    }

    template<class T, class U>
    Sub <T, U> operator-(const T &lhs, const U &rhs) {
        return Sub(lhs, rhs);
    }

    template<class T, class U>
    Mul <T, U> operator*(const T &lhs, const U &rhs) {
        return Mul(lhs, rhs);
    }

    template<class T, class U>
    Div <T, U> operator/(const T &lhs, const U &rhs) {
        return Div(lhs, rhs);
    }

    template<class F>
    class std::enable_if<!std::is_arithmetic<F>::value, Add < F, Const>>::type operator+(double val, const F &f) {
        return Add<F, Const>(f, Const(val));
    }

    template<class F>
    class std::enable_if<!std::is_arithmetic<F>::value, Add < F, Const>>::type operator+(const F &f, int val) {
        return Add<F, Const>(f, Const(val));
    }

    template<class F>
    class std::enable_if<!std::is_arithmetic<F>::value, Add < F, Const>>::type operator+(int value, const F &f) {
        return Add<F, Const>(f, Const(value));
    }

    template<class F>
    class std::enable_if<!std::is_arithmetic<F>::value, Add < F, Const>>::type operator+(const F &f, double value) {
        return Add<F, Const>(f, Const(value));
    }

    template<class F>
    class std::enable_if<!std::is_arithmetic<F>::value, Sub < F, Const>>::type operator-(const F &f, double value) {
        return Sub<F, Const>(f, Const(value));
    }

    template<class F>
    class std::enable_if<!std::is_arithmetic<F>::value, Sub < Const, F>>::type operator-(double value, const F &f) {
        return Sub<Const, F>(Const(value), f);
    }

    template<class F>
    class std::enable_if<!std::is_arithmetic<F>::value, Sub < F, Const>>::type operator-(const F &f, int value) {
        return Sub<F, Const>(f, Const(value));
    }

    template<class F>
    class std::enable_if<!std::is_arithmetic<F>::value, Sub < Const, F>>

    ::type operator-(int value, const F &f) {
        return Sub<Const, F>(Const(value), f);
    }

    template<class F>
    class std::enable_if<!std::is_arithmetic<F>::value, Mul < F, Const>>

    ::type operator*(const F &f, double value) {
        return Mul<F, Const>(f, Const(value));
    }

    template<class F>
    class std::enable_if<!std::is_arithmetic<F>::value, Mul < F, Const>>

    ::type operator*(double value, const F &f) {
        return Mul<F, Const>(f, Const(value));
    }

    template<class F>
    class std::enable_if<!std::is_arithmetic<F>::value, Mul < F, Const>>

    ::type operator*(const F &f, int value) {
        return Mul<F, Const>(f, Const(value));
    }

    template<class F>
    class std::enable_if<!std::is_arithmetic<F>::value, Mul < F, Const>>

    ::type operator*(int value, const F &f) {
        return Mul<F, Const>(f, Const(value));
    }

    template<class F>
    class std::enable_if<!std::is_arithmetic<F>::value, Div < F, Const>>

    ::type operator/(const F &f1, double value) {
        return Div<F, Const>(f1, Const(value));
    }

    template<class F>
    class std::enable_if<!std::is_arithmetic<F>::value, Div < Const, F>>

    ::type operator/(double value, const F &f) {
        return Div<Const, F>(Const(value), f);
    }

    template<class F>
    class std::enable_if<!std::is_arithmetic<F>::value, Div < F, Const>>

    ::type operator/(const F &f, int value) {
        return Div<F, Const>(f, Const(value));
    }

    template<class F>
    class std::enable_if<!std::is_arithmetic<F>::value, Div < Const, F>>

    ::type operator/(int value, const F &f) {
        return Div<Const, F>(Const(value), f);
    }
=======
    template<typename T, typename U>
    Add<T, U> operator+(const T& lhs, const U& rhs) {
        return Add(lhs, rhs);
    }

    template<typename T, typename U>
    Sub<T, U> operator-(const T& lhs, const U& rhs) {
        return Sub(lhs, rhs);
    }

    template<typename T, typename U>
    Mul<T, U> operator*(const T& lhs, const U& rhs) {
        return Mul(lhs, rhs);
    }

    template<typename T, typename U>
    Div<T, U> operator/(const T& lhs, const U& rhs) {
        return Div(lhs, rhs);
    }
>>>>>>> 7b9294f... task added
}

#endif //ACRONIS_OPERATORS_H
