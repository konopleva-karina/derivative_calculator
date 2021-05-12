#include <algorithm>
#include "tokenizer.h"

bool operator==(const UnknownToken& lhs, const UnknownToken& rhs) {
    return lhs.value == rhs.value;
}

bool operator==(const PlusToken&, const PlusToken&) {
    return true;
}

bool operator==(const MinusToken&, const MinusToken&) {
    return true;
}

bool operator==(const NumberToken& lhs, const NumberToken& rhs) {
    return lhs.value == rhs.value;
}

bool operator==(const MultiplyToken&, const MultiplyToken&) {
    return true;
}

bool operator==(const DivideToken&, const DivideToken&) {
    return true;
}

bool operator==(const ResidualToken&, const ResidualToken&) {
    return true;
}

bool operator==(const SqrToken&, const SqrToken&) {
    return true;
}

bool operator==(const MinToken&, const MinToken&) {
    return true;
}

bool operator==(const AbsToken&, const AbsToken&) {
    return true;
}

bool operator==(const MaxToken&, const MaxToken&) {
    return true;
}

bool operator==(const OpeningBracketToken&, const OpeningBracketToken&) {
    return true;
}

bool operator==(const ClosingBracketToken&, const ClosingBracketToken&) {
    return true;
}

std::vector<std::string> Split(const std::string& str, const std::string& delimeters) {
    std::vector<std::string> tokens;
    std::size_t beg = str.find_first_not_of(delimeters);

    for(size_t end = str.find_first_of(delimeters, beg); end != std::string::npos;
        end = str.find_first_of(delimeters, beg)) {
        tokens.push_back(str.substr(beg, end - beg));
        beg = str.find_first_not_of(delimeters, end);
    }

    if (beg != std::string::npos) {
        tokens.push_back(str.substr(beg));
    }

    return tokens;
}

bool IsNumber(const std::string& str) {
    if (str.empty()) {
        return false;
    }

    auto beg = str.begin();
    if (str[0] == '-' || str[0] == '+') {
        beg = std::next(beg);
    }

    return std::all_of(beg, str.end(), [str](char ch){return isdigit(ch);});
}

std::vector<Token> Tokenize(const std::string& input) {
    const std::vector<std::string> strings = Split(input, " ");
    std::vector<Token> tokens;
    for (const auto& string : strings) {
        if (string == "+") {
            tokens.emplace_back(PlusToken{});
            std::cout << "Plus";
        } else if (string == "-") {
            tokens.emplace_back(MinusToken{});
            std::cout << "Minus";
        } else if (string == "*") {
            tokens.emplace_back(MultiplyToken{});
            std::cout << "Multiply";
        } else if (string == "/") {
            tokens.emplace_back(DivideToken{});
            std::cout << "\\";
        } else if (string == "%") {
            tokens.emplace_back(ResidualToken{});
        } else if (string == "(") {
            tokens.emplace_back(OpeningBracketToken{});
        }  else if (string == ")") {
            tokens.emplace_back(ClosingBracketToken{});
        } else if (string == "sqr") {
            tokens.emplace_back(SqrToken{});
        } else if (string == "max") {
            tokens.emplace_back(MaxToken{});
        } else if (string == "min") {
            tokens.emplace_back(MinToken{});
        } else if (string == "abs") {
            tokens.emplace_back(AbsToken{});
        } else if (IsNumber(string)) {
            tokens.emplace_back(NumberToken(std::stoi(string)));
            std::cout << "number";
        } else {
            tokens.emplace_back(UnknownToken(string));
            std::cout << "var";
        }
    }

    return tokens;
}
