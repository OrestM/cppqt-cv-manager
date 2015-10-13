#include <iostream>
#include <string>
#include <array>
#include <vector>

// We should keep list of programmers CVs
// For each CV we have
//      * name field
//      * birthday year
//      * list of skills
//      * list of previous jobs
//      * we would like to print our CV

class JobRecord
{
public:
    JobRecord(const int startyear, const int endyear, const std::string &jobtitle, const std::string &companyname) :
        mCompanyName{companyname}
      , mJobTitle{jobtitle}
      , mStartYear{startyear}
      , mEndYear{endyear}      
    {

    }

    bool isValid() const
    {
        return !mJobTitle.empty()
                && mCompanyName.empty()
                && ((mStartYear && mEndYear) > 1960);
    }

    void print() const
    {
        if (isValid())
        {
            std::cout << "Company Name: " << mCompanyName << std::endl;
            std::cout << "=====================" << std::endl;
            std::cout << "Post: " << mJobTitle << std::endl;
            std::cout << "Start Year: " << mStartYear << std::endl;
            std::cout << "End Year: " << mEndYear << std::endl;
            std::cout << std::endl;
        }
    }

public:
    std::string mCompanyName;
    std::string mJobTitle;
    int mStartYear;
    int mEndYear;
};

class CV
{
public:
    CV(const std::string &name, int birthYear, const std::string &skills, const std::string &previousJobs) :
        mName{name}
      , mBirthYear{birthYear}
      , mSkills{skills}
      , mPreviousJobs{previousJobs}
    {

    }

    bool isValid() const
    {
        return !mName.empty()
                && ((mBirthYear > 1963) && (mBirthYear < 1995))
                && !mSkills.empty()
                && !mPreviousJobs.empty();
    }

    void print() const
    {
        if (isValid())
        {
            std::cout << mName << " (" << mBirthYear << ")" << std::endl;
            std::cout << "=====================" << std::endl;
            std::cout << "Skills: " << mSkills << std::endl;
            std::cout << "Previous work record: " << mPreviousJobs << std::endl;
            std::cout << std::endl;
        }
    }

private:    
    std::string mName;
    int mBirthYear;
    std::string mSkills;
    std::string mPreviousJobs;
};


int main()
{
    CV johnsCV {"John Jonson", 1978,"C++, Java", "IBM 1990-1995; Microsoft 1996-2002"};

    CV dansCV("Dan Davidson", 1988, "C++, Java", "IBM 1996-1997");

//    std::array<CV, 3> cvList {johnsCV, dansCV, {"Will Walker", 1979, "C++, Java", "IBM 1990-1999; Microsoft 1999-2010"} };
    std::vector<CV> cvList {johnsCV, dansCV, {"Will Walker", 1979, "C++, Java", "IBM 1990-1999; Microsoft 1999-2010"},
                           {"Stve Swift", 1973, "C++, Java", "IBM 1995-1999; Microsoft 1997-2005"},
                           {"Colin Harvy", 1984, "C++, Java", "IBM 1991-1996"},
                           {"Forest Mount", 1983, "C++, Java", "IBM 1993-1999; Microsoft 2010-2015"},
                           {"Harrys Harison", 1976, "C++, Java", "IBM 1994-1999"},
                           {"Lincy Jordan", 1985, "C++, Java", "IBM 1992-1998; Microsoft 2001-2006"},
                           {"William Brench", 1977, "C++, Java", "IBM 1990-1995; Microsoft 2003-2007"}};

    for (const auto& cv: cvList)
    {
        if (cv.isValid())
        {
            cv.print();
        }
        else
        {
            std::cout << "ERROR: CV is invalid" << std::endl;
        }
    }

    return 0;
}


