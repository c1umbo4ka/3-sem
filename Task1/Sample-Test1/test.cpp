#include "pch.h"
#include "../Domain/archive.h"
#include "../Domain/criminal_case.h"
#include <memory>
#include <vector>

TEST(ArchiveTest, AddCaseTest) {
    auto archive_ptr = std::make_shared<archive>();
    auto case1 = criminal_case::create("Иванов", "Петров", "158");
    auto case2 = criminal_case::create("Сидоров", "Иванов", "105");

    archive_ptr->add_case(case1);
    archive_ptr->add_case(case2);

    auto all_cases = archive_ptr->display_all_cases();
    EXPECT_EQ(all_cases.size(), 2);
    EXPECT_EQ(all_cases[0], "Осужденный: Иванов, Следователь: Петров, Статья: 158");
    EXPECT_EQ(all_cases[1], "Осужденный: Сидоров, Следователь: Иванов, Статья: 105");
}

TEST(ArchiveTest, FindByConvictTest) {
    auto archive_ptr = std::make_shared<archive>();
    auto case1 = criminal_case::create("Иванов", "Петров", "158");
    auto case2 = criminal_case::create("Сидоров", "Иванов", "105");

    archive_ptr->add_case(case1);
    archive_ptr->add_case(case2);

    auto found_cases = archive_ptr->find_by_convict("Иванов");
    ASSERT_EQ(found_cases.size(), 1);
    EXPECT_EQ(found_cases[0], "Осужденный: Иванов, Следователь: Петров, Статья: 158");
}

TEST(ArchiveTest, FindByDetectiveTest) {
    auto archive_ptr = std::make_shared<archive>();
    auto case1 = criminal_case::create("Иванов", "Петров", "158");
    auto case2 = criminal_case::create("Сидоров", "Иванов", "105");

    archive_ptr->add_case(case1);
    archive_ptr->add_case(case2);

    auto found_cases = archive_ptr->find_by_detective("Иванов");
    ASSERT_EQ(found_cases.size(), 1);
    EXPECT_EQ(found_cases[0], "Осужденный: Сидоров, Следователь: Иванов, Статья: 105");
}

TEST(ArchiveTest, FindByArticleTest) {
    auto archive_ptr = std::make_shared<archive>();
    auto case1 = criminal_case::create("Иванов", "Петров", "158");
    auto case2 = criminal_case::create("Сидоров", "Иванов", "105");

    archive_ptr->add_case(case1);
    archive_ptr->add_case(case2);

    auto found_cases = archive_ptr->find_by_article("105");
    ASSERT_EQ(found_cases.size(), 1);
    EXPECT_EQ(found_cases[0], "Осужденный: Сидоров, Следователь: Иванов, Статья: 105");
}

TEST(ArchiveTest, DisplayAllCasesTest) {
    auto archive_ptr = std::make_shared<archive>();
    auto case1 = criminal_case::create("Иванов", "Петров", "158");
    auto case2 = criminal_case::create("Сидоров", "Иванов", "105");

    archive_ptr->add_case(case1);
    archive_ptr->add_case(case2);

    auto all_cases = archive_ptr->display_all_cases();
    ASSERT_EQ(all_cases.size(), 2);
    EXPECT_EQ(all_cases[0], "Осужденный: Иванов, Следователь: Петров, Статья: 158");
    EXPECT_EQ(all_cases[1], "Осужденный: Сидоров, Следователь: Иванов, Статья: 105");
}

TEST(CriminalCaseTest, CreateTest) {
    auto case1 = criminal_case::create("Иванов", "Петров", "158");
    ASSERT_NE(case1, nullptr);

    EXPECT_EQ(case1->get_convict_name(), "Иванов");
    EXPECT_EQ(case1->get_detective_name(), "Петров");
    EXPECT_EQ(case1->get_crime_article(), "158");
}

TEST(CriminalCaseTest, GetInfoTest) {
    auto case1 = criminal_case::create("Иванов", "Петров", "158");
    EXPECT_EQ(case1->get_info(), "Осужденный: Иванов, Следователь: Петров, Статья: 158");
}

TEST(CriminalCaseTest, GetConvictNameTest) {
    auto case1 = criminal_case::create("Иванов", "Петров", "158");
    EXPECT_EQ(case1->get_convict_name(), "Иванов");
}

TEST(CriminalCaseTest, GetDetectiveNameTest) {
    auto case1 = criminal_case::create("Иванов", "Петров", "158");
    EXPECT_EQ(case1->get_detective_name(), "Петров");
}

TEST(CriminalCaseTest, GetCrimeArticleTest) {
    auto case1 = criminal_case::create("Иванов", "Петров", "158");
    EXPECT_EQ(case1->get_crime_article(), "158");
}

TEST(CriminalCaseTest, SetArchiveTest) {
    auto archive_ptr = std::make_shared<archive>();
    auto case1 = criminal_case::create("Иванов", "Петров", "158");

    case1->set_archive(archive_ptr);
    
    EXPECT_NO_THROW(case1->set_archive(archive_ptr));
}