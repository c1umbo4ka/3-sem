#pragma once
#include "Case.h"

class CriminalCase : public Case {
    std::string convictName;
    std::string detectiveName;
    std::string crimeArticle;

public:
    CriminalCase(const std::string& convict, const std::string& detective, const std::string& article);
    std::string getInfo() const override;
    std::string getConvictName() const override;
    std::string getDetectiveName() const override;
    std::string getCrimeArticle() const override;
};

CriminalCase::CriminalCase(const std::string& convict, const std::string& detective, const std::string& article)
    : convictName(convict), detectiveName(detective), crimeArticle(article) {}

std::string CriminalCase::getInfo() const {
    return "Осужденный: " + convictName + ", Следователь: " + detectiveName + ", Статья: " + crimeArticle;
}

std::string CriminalCase::getConvictName() const { return convictName; }
std::string CriminalCase::getDetectiveName() const { return detectiveName; }
std::string CriminalCase::getCrimeArticle() const { return crimeArticle; }
