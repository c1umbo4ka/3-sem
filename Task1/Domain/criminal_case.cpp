#include "criminal_case.h"
#include <sstream>

criminal_case::criminal_case(const std::string& convict, const std::string& detective, const std::string& article)
    : convict_name(convict), detective_name(detective), crime_article(article) {}

std::shared_ptr<criminal_case> criminal_case::create(const std::string& convict, const std::string& detective, const std::string& article) {
    return std::shared_ptr<criminal_case>(new criminal_case(convict, detective, article));
}

void criminal_case::set_archive(std::shared_ptr<archive> parent) {
    parent_archive = parent;
}

std::string criminal_case::get_info() const {
    std::ostringstream oss;
    oss << "Осужденный: " << convict_name << ", Следователь: " << detective_name << ", Статья: " << crime_article;
    return oss.str();
}

std::string criminal_case::get_convict_name() const { return convict_name; }
std::string criminal_case::get_detective_name() const { return detective_name; }
std::string criminal_case::get_crime_article() const { return crime_article; }


