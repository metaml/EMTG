// Copyright (c) 2023 The Regents of the University of Colorado.
// All Other Rights Reserved.

#ifndef RUNGEKUTTADP87TABLEAU_H
#define RUNGEKUTTADP87TABLEAU_H

#include "RungeKuttaTableau.h"

namespace EMTG {
	namespace Integration
	{
		class RungeKuttaDP87Tableau : public RungeKuttaTableau
		{
		public:
			// standard constructor
			RungeKuttaDP87Tableau();

		}; // end class definition

	} // end integration namespace
} // end EMTG namespace


#endif