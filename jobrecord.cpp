#include "jobrecord.h"

JobRecord::JobRecord():
     mStartYear(0)
   , mEndYear(0)
   , mJobTitle("undefined_job_title")
   , mCompanyName("undefined_company_name")
 {

 }

JobRecord::JobRecord(int startYear, int endYear, const std::string &jobTitle, const std::string &companyName):
    mStartYear(startYear)
  , mEndYear(endYear)
  , mJobTitle(jobTitle)
  , mCompanyName(companyName)
{

}

bool JobRecord::isValid() const
    {
        return !mCompanyName.empty()
                && mJobTitle.empty()
                && mStartYear > 1960
                && mEndYear > 1960;
    }
