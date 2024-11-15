#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "Case.h"
#include "criminal_case.h"

class Archive {
    std::vector<std::shared_ptr<Case>> cases;

public:
    void add_case(const std::string& convict, const std::string& detective, const std::string& article);
    std::vector<std::string> find_by_convict(const std::string& convict) const;
    std::vector<std::string> find_by_detective(const std::string& detective) const;
    std::vector<std::string> find_by_article(const std::string& article) const;
    std::vector<std::string> display_all_cases() const;
};

void Archive::add_case(const std::string& convict, const std::string& detective, const std::string& article) {
    cases.push_back(std::make_shared<criminal_case>(convict, detective, article));
    std::cout << "Дело добавлено: " << convict << ", " << detective << ", статья: " << article << std::endl;
}

std::vector<std::string> Archive::find_by_convict(const std::string& convict) const {
    std::vector<std::string> results;
    for (const auto& caseItem : cases) {
        if (caseItem->get_convict_name() == convict) {
            results.push_back(caseItem->get_info());
        }
    }
    return results;
}

std::vector<std::string> Archive::find_by_detective(const std::string& detective) const {
    std::vector<std::string> results;
    for (const auto& caseItem : cases) {
        if (caseItem->get_detective_name() == detective) {
            results.push_back(caseItem->get_info());
        }
    }
    return results;
}

std::vector<std::string> Archive::find_by_article(const std::string& article) const {
    std::vector<std::string> results;
    for (const auto& caseItem : cases) {
        if (caseItem->get_crime_article() == article) {
            results.push_back(caseItem->get_info());
        }
    }
    return results;
}

std::vector<std::string> Archive::display_all_cases() const {
    std::vector<std::string> results;
    for (const auto& caseItem : cases) {
        results.push_back(caseItem->get_info());
    }
    return results;
}


