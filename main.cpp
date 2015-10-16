#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cv.h> //Import class cv.h


int main()
{
    CV johnsCV {"John Jonson", 1980,"C, C++"};
    JobRecord johnsjr1 {1992,1997, "middle senior", "Microsoft"}; //Data for johnsCV
    johnsCV.addJobRecord(johnsjr1); //Add new data for johnsCV

    CV dansCV("Dan Davidson", 1987, "Java, C#");
    JobRecord dansjr1 {1990,1993, "junior", "IBM"};;
    dansCV.addJobRecord(dansjr1);

    CV willsCV("Will Walker", 1975, "C/C++");
    JobRecord willsjr1 {2009,2014, "CEO", "Microsoft"};
    willsCV.addJobRecord(willsjr1);

//    std::array<CV, 3> cvList {johnsCV, dansCV, {"Will Walker", 1979, "C++, Java", "IBM 1990-1999; Microsoft 1999-2010"} };
    std::vector<CV> cvList {johnsCV, dansCV , willsCV};

    for (const auto& cv: cvList)
    {
        if (cv.isValid() && (cv.TotalJobTime >= 5)) //Search experience more 5 years
        {
            cv.print();
        }
        else
        {
            std::cout << "ERROR: CV is invalid\n" << std::endl;
        }
    }

    return 0;
}
