#ifndef REAL_NORM_H
#define REAL_NORM_H

#include "Real.h"

/**
 * This class implements a Real value decision variable that is
 * initialized from a normal distribution.
 */
class RealNorm : public Real
{

  public:
    RealNorm ( double mean, double std, double lowerBound, double upperBound )
		: mean_(mean), std_(std)
    {
		setLowerBound(lowerBound);
		setUpperBound(upperBound);

		auto value = PseudoRandom::randNormal(mean, std);
		while (value > upperBound || value < lowerBound)
			value = PseudoRandom::randNormal(mean, std);

		setValue(value);
    }

	Variable* deepCopy() {
		return new RealNorm(mean_, std_, getLowerBound(), getUpperBound());
	}
  private:
    double mean_;
    double std_;
};

#endif
