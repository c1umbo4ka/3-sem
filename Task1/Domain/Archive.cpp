#include "archive.h"
#include "criminal_case.h"
#include <algorithm>

void archive::add_case(const std::shared_ptr<Case>& case_ptr) {
    cases.emplace_back(case_ptr);
    auto criminal_case_ptr = std::dynamic_pointer_cast<criminal_case>(case_ptr);
    if (criminal_case_ptr) {
        criminal_case_ptr->set_archive(shared_from_this());
    }
}

std::vector<std::string> archive::find_by_convict(const std::string& convict) const {
    std::vector<std::string> results;
    std::for_each(cases.begin(), cases.end(), [&results, &convict](const auto& case_item) {
    if (case_item->get_convict_name() == convict) {
        results.emplace_back(case_item->get_info());
        }
    });
    return results;
}

std::vector<std::string> archive::find_by_detective(const std::string& detective) const {
    std::vector<std::string> results;
    std::for_each(cases.begin(), cases.end(), [&results, &detective](const auto& case_item) {
        if (case_item->get_detective_name() == detective) {
            results.emplace_back(case_item->get_info());
        }
    });
    return results;
}

std::vector<std::string> archive::find_by_article(const std::string& article) const {
    std::vector<std::string> results;
    std::for_each(cases.begin(), cases.end(), [&results, &article](const auto& case_item) {
        if (case_item->get_crime_article() == article) {
            results.emplace_back(case_item->get_info());
        }
    });
    return results;
}

std::vector<std::string> archive::display_all_cases() const {
    std::vector<std::string> results;
    std::for_each(cases.begin(), cases.end(), [&results](const auto& case_item) {
        results.emplace_back(case_item->get_info());
    });
    return results;
}
