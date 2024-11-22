#include "archive.h"
#include "criminal_case.h"
#include "case.h"

void archive::add_case(const std::string& convict, const std::string& detective, const std::string& article) {
    cases.push_back(std::make_shared<criminal_case>(convict, detective, article));
    std::cout << "Дело добавлено: " << convict << ", " << detective << ", статья: " << article << std::endl;
}

std::vector<std::string> archive::find_by_convict(const std::string& convict) const {
    std::vector<std::string> results;
    for (const auto& case_item : cases) {
        if (case_item->get_convict_name() == convict) {
            results.push_back(case_item->get_info());
        }
    }
    return results;
}

std::vector<std::string> archive::find_by_detective(const std::string& detective) const {
    std::vector<std::string> results;
    for (const auto& case_item : cases) {
        if (case_item->get_detective_name() == detective) {
            results.push_back(case_item->get_info());
        }
    }
    return results;
}

std::vector<std::string> archive::find_by_article(const std::string& article) const {
    std::vector<std::string> results;
    for (const auto& case_item : cases) {
        if (case_item->get_crime_article() == article) {
            results.push_back(case_item->get_info());
        }
    }
    return results;
}

std::vector<std::string> archive::display_all_cases() const {
    std::vector<std::string> results;
    for (const auto& case_item : cases) {
        results.push_back(case_item->get_info());
    }
    return results;
}

