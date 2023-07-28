// Copyright (c) 2023 The Regents of the University of Colorado.
// All Other Rights Reserved.

#ifndef RUNGEKUTTA4TABLEAU_H
#define RUNGEKUTTA4TABLEAU_H

#include "RungeKuttaTableau.h"

namespace EMTG {
	namespace Integration
	{
		class RungeKutta4Tableau : public RungeKuttaTableau
		{
		public:
			// standard constructor
			RungeKutta4Tableau();

		}; // end class definition

	} // end integration namespace
} // end EMTG namespace


#endif