#include "CSlice.h"

// regular exprssion that matches every correct slice syntax and s[] (this case checks additionally)
std::regex CSlice::format = std::regex(R"(s\[((\d*)|(-\d+))(:((\d*)|(-\d+))){0,2}\])");

// function that returns pointer to an integer if the given string is not empty and nullptr in other case
// expects string that starts with integer on empty string
int * CSlice::resolveString(const std::string& src) {
    if (!src.empty()) {
        return new int(atoi(src.c_str()));
    }
    return nullptr;
}

bool CSlice::checkFormat(const std::string & expr) {
    if (std::regex_match(expr, format) && expr.size() != 3) {
        return true;
    }
    else {
        return false;
    }
}

// taking slice from stored vector
std::vector<int> CSlice::slice(std::string expr)
{
    if (!checkFormat(expr)) {
        throw(std::exception("incorrect syntax"));
    }

    parse(expr);

    std::vector<int> res = {};

    for (int i = *start; i < *stop && *step > 0 || i > *stop && *step < 0; i += *step) {
        res.emplace_back(elements[i]);
    }

    return res;
}

// setting start, stop and step values regarding to the expr and stored elements
void CSlice::parse(std::string expr)
{
    delete start;
    delete stop;
    delete step;
    start = nullptr;
    stop = nullptr;
    step = nullptr;

    // extracting actual expression s[expr]
    //assert(expr[0] == 's' && expr[1] == '[' && expr[expr.size() - 1] == ']');
    expr = expr.substr(2, expr.size() - 3);

    // temporary expression slice will be used to get values
    std::string tempSlice;

    // extracting starting position
    tempSlice = expr.substr(0, expr.find(":"));
    start = resolveString(tempSlice);
    if (start != nullptr && *start < 0) {
        *start = this->elements.size() + *start;
    }

    // extracting stop and step;
    if (expr.find(":") == -1) {
        // s[idx] construction, default idx access
        if (*start < 0 || *start >= this->elements.size()) {
            delete start;
            throw(std::exception("list index out of range"));
        }
        stop = new int(*start + 1);
        step = new int(1);
    }
    else if (expr.find(":") == expr.find_last_of(":")) {
        // s[start:stop] construction
        tempSlice = expr.substr(expr.find(":") + 1, expr.size() - 1);
        stop = resolveString(tempSlice);
        step = new int(1);
    }
    else {
        // s[start:stop:step] construction
        expr = expr.substr(expr.find(":") + 1, expr.size() - 1);
        tempSlice = expr.substr(0, expr.find(":"));
        stop = resolveString(tempSlice);
        tempSlice = expr.substr(expr.find(":") + 1, expr.size());
        step = resolveString(tempSlice);
    }

    // we have to update values regarding to:
    // is it specified ot not
    // if it is specified in expression, is it less than zero or not

    // if step is unspecified
    // we have to check it first because manipulations
    // with start and stop (if they are unspecified)
    // are based on it's sign
    if (step == nullptr) {
        step = new int(1);
    }

    if (*step == 0) {
        delete start;
        delete stop;
        delete step;
        throw(std::exception("slice step cannot be zero"));
    }

    // if start is unspecified
    if (start == nullptr) {
        if (*step > 0) {
            start = new int(0);
        }
        else {
            start = new int(this->elements.size() - 1);
        }
    }
    // if start is specified and less than zero
    else if (*start < 0) {
        *start = this->elements.size() + *start;
        if (*start < 0) {
            *start = 0;
        }
        else if (*start >= elements.size()) {
            *start = elements.size() - 1;
        }
    }

    // if stop is unspecified
    if (stop == nullptr) {
        if (*step > 0) {
            stop = new int(this->elements.size());
        }
        else {
            stop = new int(-1);
        }
    }
    // if stop is specified and less than zero
    else if (*stop < 0) {
        *stop = this->elements.size() + *stop;
        if (*stop < 0) {
            *stop = 0;
        }
        else if (*stop > elements.size()) {
            *stop = elements.size();
        }
    }
}
