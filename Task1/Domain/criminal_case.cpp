﻿#include "criminal_case.h"
#include "Case.h"

criminal_case::criminal_case(const std::string& convict, const std::string& detective, const std::string& article)
    : convict_name(convict), detective_name(detective), crime_article(article) {}

std::string criminal_case::get_info() const {
    return "Осужденный: " + convict_name + ", Следователь: " + detective_name + ", Статья: " + crime_article;
}
std::string criminal_case::get_convict_name() const { return convict_name; }
std::string criminal_case::get_detective_name() const { return detective_name; }
std::string criminal_case::get_crime_article() const { return crime_article; }

