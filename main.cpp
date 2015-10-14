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
        return !mCompanyName.empty()
                && mJobTitle.empty()
                && ((mStartYear && mEndYear) > 1960);
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
    CV(const std::string &name, int birthYear, const std::string &skills) :
        mName{name}
      , mBirthYear{birthYear}
      , mSkills{skills}
    {

    }

    bool isValid() const
    {
        return !mName.empty()
                && ((mBirthYear > 1963) && (mBirthYear < 1995))
                && !mSkills.empty()
                && !mPreviousJobs.empty();;
    }

    void print() const
        {
            if (isValid())
            {
                std::cout << mName << " (" << mBirthYear << ")" << std::endl;
                std::cout << "=====================" << std::endl;
                std::cout << "Skills: " << mSkills << std::endl;
                std::cout << "Previous work: " << mPreviousJobs << std::endl;
                std::cout << std::endl;
            }
        }

    void  addJobRecord(const JobRecord &jr)
      {
            mPreviousJobsCompanyName = jr.mCompanyName;
            mPreviousJobsJobTitle = jr.mJobTitle;
            mPreviousJobsStartYear = jr.mStartYear;
            mPreviousJobsEndYear = jr.mEndYear;
            std::string  startYear = std::to_string(jr.mStartYear);
            std::string  endYear = std::to_string(jr.mEndYear);
            mPreviousJobs += " " + jr.mCompanyName + "-" + jr.mJobTitle + ", " + startYear + "-" + endYear + ";";
            TotalJobTime += jr.mEndYear - jr.mStartYear;

      }
            std::string mPreviousJobsCompanyName;
            std::string mPreviousJobsJobTitle;
            int mPreviousJobsStartYear;
            int mPreviousJobsEndYear;
            int TotalJobTime = 0;

private:
    std::string mName;
    int mBirthYear;
    std::string mSkills;
    std::string mPreviousJobs;
};


int main()
{
    CV johnsCV {"John Jonson", 1980,"C, C++"};
    JobRecord johnsjr1 {1992,1997, "middle senior", "Microsoft"}; //Record new data for johnsCV
    JobRecord johnsjr2 {1998,2006, "developer", "IBM"};
    johnsCV.addJobRecord(johnsjr1); //Add new data for johnsCV
    johnsCV.addJobRecord(johnsjr2);

    CV dansCV("Dan Davidson", 1987, "Java, C#");
    JobRecord dansjr1 {1990,1993, "junior", "IBM"};
    JobRecord dansjr2 {1994,1996, "CEO", "Apple"};
    dansCV.addJobRecord(dansjr1);
    dansCV.addJobRecord(dansjr2);

    CV willsCV("Will Walker", 1975, "C/C++");
    JobRecord willsjr1 {2000,2002, "junior", "Apple"};
    JobRecord willsjr2 {2009,2014, "CEO", "Microsoft"};
    willsCV.addJobRecord(willsjr1);
    willsCV.addJobRecord(willsjr2);

//    std::array<CV, 3> cvList {johnsCV, dansCV, {"Will Walker", 1979, "C++, Java", "IBM 1990-1999; Microsoft 1999-2010"} };
    std::vector<CV> cvList {johnsCV, dansCV , willsCV};

    for (const auto& cv: cvList)
    {
        if (cv.isValid() && (cv.TotalJobTime > 5)) //Search experience more 5 years
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
