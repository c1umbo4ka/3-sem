#pragma once
#include "case.h"

class criminal_case : public Case {
    std::string convict_name;
    std::string detective_name;
    std::string crime_article;

public:
    criminal_case(const std::string& convict, const std::string& detective, const std::string& article);
    std::string get_info() const override;
    std::string get_convict_name() const override;
    std::string get_detective_name() const override;
    std::string get_crime_article() const override;
};



