#pragma once
#include "Case.h"

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

criminal_case::criminal_case(const std::string& convict, const std::string& detective, const std::string& article)
    : convict_name(convict), detective_name(detective), crime_article(article) {}

std::string criminal_case::get_info() const {
    return "Осужденный: " + convict_name + ", Следователь: " + detective_name + ", Статья: " + crime_article;
}

std::string criminal_case::get_convict_name() const { return convict_name; }
std::string criminal_case::get_detective_name() const { return detective_name; }
std::string criminal_case::get_crime_article() const { return crime_article; }
