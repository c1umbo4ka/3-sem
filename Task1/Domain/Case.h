#pragma once
#include <string>

class Case {
public:
    virtual ~Case() = default;
    virtual std::string getInfo() const = 0;
    virtual std::string getConvictName() const = 0;
    virtual std::string getDetectiveName() const = 0;
    virtual std::string getCrimeArticle() const = 0;
};