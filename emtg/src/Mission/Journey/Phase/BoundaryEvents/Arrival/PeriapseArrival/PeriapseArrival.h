
// EMTG: Evolutionary Mission Trajectory Generator
// An open-source global optimization tool for preliminary mission design
// Provided by NASA Goddard Space Flight Center
//
// Copyright (c) 2013 - 2020 United States Government as represented by the
// Administrator of the National Aeronautics and Space Administration.
// All Other Rights Reserved.

// Copyright (c) 2023 The Regents of the University of Colorado.
// All Other Rights Reserved.

// Licensed under the NASA Open Source License (the "License"); 
// You may not use this file except in compliance with the License. 
// You may obtain a copy of the License at:
// https://opensource.org/licenses/NASA-1.3
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either 
// express or implied.   See the License for the specific language
// governing permissions and limitations under the License.

#pragma once

#include "arrival.h"
#include "PeriapseBoundary.h"

namespace EMTG
{
    namespace BoundaryEvents
    {
        class PeriapseArrival : virtual public ArrivalEvent,
            virtual public PeriapseBoundary
        {
        public:
            //default constructor
            PeriapseArrival() : ArrivalEvent::ArrivalEvent() {};

            //specialized constructor
            PeriapseArrival(const std::string& name,
                           const size_t& journeyIndex,
                           const size_t& phaseIndex,
                           size_t& stageIndex,
                           Astrodynamics::universe* Universe,
                           HardwareModels::Spacecraft* mySpacecraft,
                           missionoptions* myOptions);

            virtual void initialize(const std::string& name,
                const size_t& journeyIndex,
                const size_t& phaseIndex,
                size_t& stageIndex,
                Astrodynamics::universe* Universe,
                HardwareModels::Spacecraft* mySpacecraft,
                missionoptions* myOptions);

            //destructor
            virtual ~PeriapseArrival() {};
            
            //output
            virtual void output_maneuver_and_target_spec(std::ofstream& maneuver_spec_file, std::ofstream& target_spec_file, bool& haveManeuverNeedTarget);


        protected:

            //method to calculate event left side

            virtual void calcbounds_event_left_side(const std::vector<double>& RadiusBounds,
                const std::vector<double>& VelocityMagnitudeBounds,
                std::vector<size_t> timeVariables);

            virtual void calcbounds_event_right_side();

            virtual void calcbounds_specialized_constraints();

            virtual void process_event_left_side(const std::vector<doubleType>& X,
                size_t& Xindex,
                std::vector<doubleType>& F,
                size_t& Findex,
                std::vector<double>& G,
                const bool& needG);

            virtual void process_event_right_side(const std::vector<doubleType>& X,
                size_t& Xindex,
                std::vector<doubleType>& F,
                size_t& Findex,
                std::vector<double>& G,
                const bool& needG);
        };
    }//end namespace BoundaryEvents
}//end namespace EMTG