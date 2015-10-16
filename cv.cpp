#include "cv.h"

CV::CV():
      mName{"undifined_name"}
    , mBirthYear{0}
    , mSkills{"undefined_name"}
{

}

CV::CV(const std::string &name, int birthYear, const std::string &skills) :
      mName{name}
    , mBirthYear{birthYear}
    , mSkills{skills}
{

}

bool CV::isValid() const //Check if correct data
{
    return !mName.empty()
            && mBirthYear > 1963
            && mBirthYear < 1995
            && !mSkills.empty()
            && !mPreviousJobs.empty();
}

void CV::print() const //Print on screen
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

void CV::addJobRecord(const JobRecord &jr) //Create new method for JobRecord
{
    mPreviousJobsCompanyName = jr.mCompanyName;
    mPreviousJobsJobTitle = jr.mJobTitle;
    mPreviousJobsStartYear = jr.mStartYear;
    mPreviousJobsEndYear = jr.mEndYear;
    std::string  startYear = std::to_string(jr.mStartYear); //Change type int in type string
    std::string  endYear = std::to_string(jr.mEndYear);
    mPreviousJobs += " " + jr.mCompanyName + " - " + jr.mJobTitle + ", " + startYear + "-" + endYear + ";";

    TotalJobTime = jr.mEndYear - jr.mStartYear;
}
