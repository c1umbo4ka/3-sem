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
    void addCase(const std::string& convict, const std::string& detective, const std::string& article);
    std::vector<std::string> findByConvict(const std::string& convict) const;
    std::vector<std::string> findByDetective(const std::string& detective) const;
    std::vector<std::string> findByArticle(const std::string& article) const;
    std::vector<std::string> displayAllCases() const;
};

void Archive::addCase(const std::string& convict, const std::string& detective, const std::string& article) {
    cases.push_back(std::make_shared<CriminalCase>(convict, detective, article));
    std::cout << "Дело добавлено: " << convict << ", " << detective << ", статья: " << article << std::endl;
}

std::vector<std::string> Archive::findByConvict(const std::string& convict) const {
    std::vector<std::string> results;
    for (const auto& caseItem : cases) {
        if (caseItem->getConvictName() == convict) {
            results.push_back(caseItem->getInfo());
        }
    }
    return results;
}

std::vector<std::string> Archive::findByDetective(const std::string& detective) const {
    std::vector<std::string> results;
    for (const auto& caseItem : cases) {
        if (caseItem->getDetectiveName() == detective) {
            results.push_back(caseItem->getInfo());
        }
    }
    return results;
}

std::vector<std::string> Archive::findByArticle(const std::string& article) const {
    std::vector<std::string> results;
    for (const auto& caseItem : cases) {
        if (caseItem->getCrimeArticle() == article) {
            results.push_back(caseItem->getInfo());
        }
    }
    return results;
}

std::vector<std::string> Archive::displayAllCases() const {
    std::vector<std::string> results;
    for (const auto& caseItem : cases) {
        results.push_back(caseItem->getInfo());
    }
    return results;
}


