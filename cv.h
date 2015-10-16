#ifndef CV_H
#define CV_H
#include <iostream>
#include <string>
#include <jobrecord.h> //Import class jobrecord.h

//Create new class CV

class CV
{
public:
    CV();
    CV(const std::string &name, int birthYear, const std::string &skills);

    bool isValid() const;
    void print() const;
    void addJobRecord(const JobRecord &jr);

    int TotalJobTime = 0;

private:
    std::string mPreviousJobsCompanyName;
    std::string mPreviousJobsJobTitle;
    int mPreviousJobsStartYear;
    int mPreviousJobsEndYear;

    std::string mName;
    int mBirthYear;
    std::string mSkills;
    std::string mPreviousJobs;
};

#endif // CV_H
