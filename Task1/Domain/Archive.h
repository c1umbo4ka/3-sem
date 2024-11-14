#pragma once
#include <vector>
#include <memory>
#include <string>
#include "Case.h"
#include "criminal_case.h"

class Archive {
    std::vector<std::shared_ptr<Case>> cases;

public:
    void addCase(const std::string& convict, const std::string& detective, const std::string& article);
    void findByConvict(const std::string& convict) const;
    void findByDetective(const std::string& detective) const;
    void findByArticle(const std::string& article) const;
    void displayAllCases() const;
};

void Archive::addCase(const std::string& convict, const std::string& detective, const std::string& article) {
    cases.push_back(std::make_shared<CriminalCase>(convict, detective, article));
    std::cout << "Дело добавлено: " << convict << ", " << detective << ", статья: " << article << std::endl;
}

void Archive::findByConvict(const std::string& convict) const {
    bool found = false;
    for (const auto& caseItem : cases) {
        if (caseItem->getConvictName() == convict) {
            std::cout << "Найдено дело: " << caseItem->getInfo() << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "Дело с осужденным " << convict << " не найдено.\n";
    }
}

void Archive::findByDetective(const std::string& detective) const {
    bool found = false;
    std::cout << "Дела, в которых участвует следователь " << detective << ":\n";
    for (const auto& caseItem : cases) {
        if (caseItem->getDetectiveName() == detective) {
            std::cout << caseItem->getInfo() << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "Дела со следователем " << detective << " не найдены.\n";
    }
}

void Archive::findByArticle(const std::string& article) const {
    bool found = false;
    std::cout << "Дела по статье " << article << ":\n";
    for (const auto& caseItem : cases) {
        if (caseItem->getCrimeArticle() == article) {
            std::cout << caseItem->getInfo() << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "Дела по статье " << article << " не найдены.\n";
    }
}

void Archive::displayAllCases() const {
    std::cout << "Список всех дел:\n";
    for (const auto& caseItem : cases) {
        std::cout << caseItem->getInfo() << std::endl;
    }
}

