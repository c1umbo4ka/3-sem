#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "case.h"
#include "criminal_case.h"

class archive {
    std::vector<std::shared_ptr<Case>> cases;

public:
    void add_case(const std::string& convict, const std::string& detective, const std::string& article);
    std::vector<std::string> find_by_convict(const std::string& convict) const;
    std::vector<std::string> find_by_detective(const std::string& detective) const;
    std::vector<std::string> find_by_article(const std::string& article) const;
    std::vector<std::string> display_all_cases() const;
};




