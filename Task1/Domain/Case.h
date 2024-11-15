#pragma once
#include <string>

class Case {
public:
    virtual ~Case() = default;
    virtual std::string get_info() const = 0;
    virtual std::string get_convict_name() const = 0;
    virtual std::string get_detective_name() const = 0;
    virtual std::string get_crime_article() const = 0;
};