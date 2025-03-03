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

//base class for acceleration model terms

#ifndef ACCELERATION_MODEL_TERM_H
#define ACCELERATION_MODEL_TERM_H

#include <iostream>
#include <string>
#include <vector>

#include "SpacecraftAccelerationModel.h"
#include "doubleType.h"
#include "EMTG_Matrix.h"

namespace EMTG
{
    namespace Astrodynamics
    {
        class SpacecraftAccelerationModel;
        class AccelerationModelTerm
        {
        public:
            // constructor           
            AccelerationModelTerm(SpacecraftAccelerationModel * parent_acceleration_model);
			
			virtual ~AccelerationModelTerm();
			
            // methods
            virtual void computeAccelerationTerm() = 0;
            virtual void computeAccelerationTerm(const bool & generate_derivatives) = 0;
            virtual AccelerationModelTerm* clone() const = 0;

            inline math::Matrix<doubleType> getTermAcceleration() const { return this->term_acceleration; }

            virtual void populateInstrumentationFile(std::ofstream & acceleration_model_file) = 0;

            //fields
        protected:

            math::Matrix<doubleType> term_acceleration;

            // pointer to the acceleration model of which this term is a part
            SpacecraftAccelerationModel * acceleration_model;

        };

        inline AccelerationModelTerm * new_clone(AccelerationModelTerm const & other)
        {
            return other.clone();
        }

    } // end Astrodynamics namespace
} // end EMTG namespace

#endif