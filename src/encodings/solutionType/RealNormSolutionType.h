#ifndef REAL_NORM_SOLUTION_TYPE_H
#define REAL_NORM_SOLUTION_TYPE_H

#include "SolutionType.h"
#include "RealNorm.h"

/**
 * This class is aimed at defining a Type encoding a RealNorm
 * solution.
 **/
class RealNormSolutionType : public SolutionType
{

  public:
    RealNormSolutionType ( Problem* problem, double* mean, double* std )
        : SolutionType ( problem ), mean_ ( mean ), std_ ( std )
    {
    }

	~RealNormSolutionType() {
		delete[] mean_;
		delete[] std_;
	}

    Variable** createVariables ( )
    {
        int i;
        Variable** variables =
            new Variable*[ problem_->getNumberOfVariables ( ) ];
        if ( variables == NULL )
        {
            cout
                << "Error grave: Impossible to reserve memory for variable type"
                << endl;
            exit ( -1 );
        }

        for ( i = 0; i < problem_->getNumberOfVariables ( ); i++ )
        {
            variables[ i ] = new RealNorm ( mean_[i], std_[i],
											problem_->getLowerLimit ( i ),
											problem_->getUpperLimit ( i ) );
        }

        return variables;
    }

  protected:
    double* mean_;
    double* std_;
};

#endif
