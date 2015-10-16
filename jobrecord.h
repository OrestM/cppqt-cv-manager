#ifndef JOBRECORD_H
#define JOBRECORD_H
#include <iostream>
#include <string>

//Create new class JobRecord

class JobRecord
{
public:
    JobRecord();
    JobRecord(int startYear, int endYear, const std::string &jobTitle, const std::string &companyName);

    bool isValid() const;

public:
    int mStartYear;
    int mEndYear;
    std::string mJobTitle;
    std::string mCompanyName;
};

#endif // JOBRECORD_H
