#ifndef TOKENIZE_H
#define TOKENIZE_H

#include <vector>
#include <string>
#include <variant>
#include <iostream>

struct UnknownToken {
    std::string value;

    explicit UnknownToken(std::string value) : value(value) {
    }
};

bool operator==(const UnknownToken&, const UnknownToken&);

struct PlusToken {
};

bool operator==(const PlusToken&, const PlusToken&);

struct MinusToken {
};

bool operator==(const MinusToken&, const MinusToken&);

struct NumberToken {
    int value;
    explicit NumberToken(int value) : value(value) {
    }
};

bool operator==(const NumberToken&, const NumberToken&);

struct MultiplyToken {
};

bool operator==(const MultiplyToken&, const MultiplyToken&);

struct DivideToken {
};

bool operator==(const DivideToken&, const DivideToken&);

struct ResidualToken {
};

bool operator==(const ResidualToken&, const ResidualToken&);

struct SqrToken {
};

bool operator==(const SqrToken&, const SqrToken&);

struct MinToken {
};

bool operator==(const MinToken&, const MinToken&);

struct AbsToken {
};

bool operator==(const AbsToken&, const AbsToken&);

struct MaxToken {
};

bool operator==(const MaxToken&, const MaxToken&);

struct OpeningBracketToken {
};

bool operator==(const OpeningBracketToken&, const OpeningBracketToken&);

struct ClosingBracketToken {
};

bool operator==(const ClosingBracketToken&, const ClosingBracketToken&);

typedef std::variant<
        UnknownToken,
        PlusToken,
        MinusToken,
        NumberToken,
        MultiplyToken,
        DivideToken,
        ResidualToken,
        SqrToken,
        MinToken,
        AbsToken,
        MaxToken,
        OpeningBracketToken,
        ClosingBracketToken
> Token;

std::vector<Token> Tokenize(const std::string& input);

#endif // TOKENIZE_H
