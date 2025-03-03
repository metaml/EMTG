// Copyright (c) 2023 The Regents of the University of Colorado.
// All Other Rights Reserved.

//header file for missionoptions class
//auto-generated by make_EMTG_missionoptions_journeyoptions.py

#pragma once

#include "EMTG_enums.h"
#include "journeyoptions.h"
#include "file_utilities.h"

#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>

#ifdef EMTG_OPTIONS_PYTHON_INTERFACE
#include "boost/python.hpp"
#include "boost/python/list.hpp"
#include "boost/python/extract.hpp"
#endif

namespace EMTG
{
    class missionoptions
    {
    public:
        //constructor - just initializes everything
        missionoptions();
        missionoptions(std::string optionsfilename);
        
        //destructor
        ~missionoptions(){};
        
        //parser
        void parse_mission(const std::string& optionsfilename);
        void parse_line(const std::string& linestring, size_t& lineNumber);
        
        //writer
        void write(std::string optionsFileName, const bool& writeAll = true);
        
        //initial guess assembler
        void assemble_initial_guess();
        
        //fields
        std::vector<EMTG::JourneyOptions> Journeys;//vector of journey objects
        size_t number_of_journeys;//how many journeys do we have?
        
        //fields
        size_t number_of_phases;//how many phases in this journey?

        //internally set fields
        double G;//universal gravitation constant
        double g0;//acceleration due to gravity at sea level on Earth (m/s^2)
        double AU;//astronomical unit
        std::vector< std::tuple<std::string, double> > trialX;
        std::vector<double> current_trialX;
        double TU;
        std::string description;
        std::string outputfile;
        std::string working_directory;

        std::string mission_name;//mission name
        ObjectiveFunctionType objective_type;//objective type, see ObjectiveFunctionType in EMTG_enums.h
        size_t objective_journey;//Journey associated with objective function (if applicable)
        bool include_initial_impulse_in_cost;//Include the initial impulse in calculating the delta-v objective function?
        bool global_timebounded;//0: unbounded, 1: bounded total time (note that the global arrival date bound is by definition the same as the last journey's arrival date bound and is not duplicated
        double launch_window_open_date;//launch window open date (MJD)
        std::vector<double> total_flight_time_bounds;//flight time bounds (days)
        std::vector<double> DLA_bounds;//DLA in degrees
        std::vector<double> RLA_bounds;//RLA in degrees
        PhaseType mission_type;//mission type, #0: MGALTS, #1: FBLTS, #2: MGALT, #3: FBLT, #4: PSBI, #5: PSFB, #6: MGAnDSMs, #7: CoastPhase, #8: SundmanCoastPhase, #9: variable phase type, #10: ProbeEntryPhase, #11 ControlLawThrustPhase
        int NLP_solver_type;//NLP solver type,#0: SNOPT,#1: WORHP,#2: IPOPT-MA27, #3: IPOPT-MUMPS
        NLPMode NLP_solver_mode;//NLP solver mode,#0: find feasible point only,#1: find optimal solution,#2: satisfy equality constraints
        bool quiet_NLP;//Quiet NLP solver?
        bool ACE_feasible_point_finder;//Enable ACE feasible point finder?
        bool MBH_always_write_archive;//Write every hop to the MBH archive, even if it is not an improvement?
        bool MBH_archive_state_vector;//include state vector in MBH archive file?
        int MBH_max_not_improve;//quantity Max_not_improve for MBH
        int MBH_max_trials;//maximum number of trials for MBH
        int MBH_max_run_time;//maximum run time for MBH, in seconds
        double MBH_max_step_size;//Maximum step size (uniform) or scale factor (other distributions)
        int MBH_hop_distribution;//MBH hop probabilty distribution,#0: uniform,#1: Cauchy,#2: Pareto,#3: Gaussian
        double MBH_Pareto_alpha;//Pareto distribution alpha
        bool MBH_write_every_improvement;//Write every MBH improvement for later animation?
        double MBH_time_hop_probability;//probability of MBH time hop operation
        double snopt_feasibility_tolerance;//feasibility tolerance
        double snopt_optimality_tolerance;//optimality tolerance
        double NLP_max_step;//NLP max step
        size_t snopt_major_iterations;//NLP major iterations
        size_t snopt_minor_iterations;//NLP minor iterations
        int snopt_max_run_time;//NLP max run time (seconds)
        bool enable_Scalatron;//Enable Scalatron?
        bool enable_NLP_chaperone;//Enable NLP chaperone?
        bool seed_MBH;//Seed MBH?
        bool skip_first_nlp_run;//Skip first NLP run in an MBH process?
        bool NLP_stop_on_goal_attain;//Stop NLP on goal attain?
        double NLP_objective_goal;//Objective value at which NLP stops
        int MBH_RNG_seed;//MBH RNG seed (negative number means system clock)
        bool print_NLP_movie_frames;//Print NLP movie frames?
        bool quiet_basinhopping;//Quiet MBH?
        std::string SPICE_leap_seconds_kernel;//SPICE leap seconds kernel - required for SPICE to work
        std::string SPICE_reference_frame_kernel;//SPICE_reference_frame_kernel
        std::string universe_folder;//Universe folder
        int ephemeris_source;//0: static, 1: SPICE (default to static if no SPICE file supplied for a body), 2: SplineEphem
        size_t SplineEphem_points_per_period;//How many sample points should SplineEphem use per orbital period of each body?
        size_t SplineEphem_non_central_body_sun_points_per_period;//How many sample points should SplineEphem use per orbital period of the sun with respect to the central body?
        bool SplineEphem_truncate_ephemeris_at_maximum_mission_epoch;//Truncate SplineEphem at maximum mission epoch?
        double earliestPossibleEpoch;//Beginning of the SplineEphem data set
        double latestPossibleEpoch;//End of the SplineEphem data set
        PropagatorType propagatorType;//Propagator type,#0: Keplerian propagator,#1: Integrated propagator
        IntegratorType integratorType;//Integrator type,#0: rk7813M adaptive step,#1: rk8 fixed step
        double integrator_tolerance;//adaptive step integrator tolerance
        double integration_time_step_size;//integration step size (maximum for adaptive, fixed for fixed)
        int num_timesteps;//number of timesteps per phase
        size_t spiral_segments;//number of spiral segments
        bool allow_initial_mass_to_vary;//Allow the mass at the beginning of the first journey to vary up to the allowed maximum?
        double maximum_mass;//maximum possible mass of the spacecraft (kg)
        double IspLT;//specific impulse of the engine used for low-thrust maneuvers
        double IspLT_minimum;//minimum specific impulse for variable specific impulse problems
        double IspChem;//specific impulse of the engine used for impulsive maneuvers
        double Thrust;//thrust of the spacecraft, in Newtons
        double LV_margin;//LV margin (as a fraction)
        double LV_adapter_mass;//LV adapter mass (kg)
        int engine_type;//low-thrust engine type, from original EMTGv8 list
        int number_of_electric_propulsion_systems;//number of thruster systems (used to be called number of engines)
        double engine_duty_cycle;//percentage of time that engine can operate
        DutyCycleType duty_cycle_type;//duty cycle type,#0: averaged,#1: realistic
        double thrust_scale_factor;//scale factor to apply to thrust ONLY, not mass flow rate, can use to approximate cosine loss
        double power_at_1_AU;//Power at 1 AU (kW)
        SpacecraftPowerSupplyType power_source_type;//power source type, 0: fixed, 1: solar
        SpacecraftPowerSupplyCurveType solar_power_model_type;//Solar power model type,#0: classic Sauer model,#1: polynomial (0th order on the left)
        std::vector<double> solar_power_gamma;//solar power coefficients gamma_1 through gamma_5, if all gamma = [1 0 0 0 0], then solar power is a simple 1/r^2
        double power_margin;//power margin (fraction)
        double power_decay_rate;//power system decay rate (fraction per year)
        int power_decay_type;//How to model power decay.\n#0: e^(-t * power_decay_rate) \n#2: decay_coeff[0] + decay_coeff[1] * e^(decay_coeff[2] * t) + decay_coeff[3] * t
        std::vector<double> decay_coefficients;//Decay coefficients if power_decay_type = 1
        double power_system_decay_reference_epoch;//reference date when the power system begins to decay
        double throttle_sharpness;//Throttle sharpness (higher means more precise, lower means smoother)
        ThrottleLogic throttle_logic_mode;//Throttle logic mode #0: maximum number of thrusters,#1: minimum number of thrusters
        std::vector<double> spacecraft_power_coefficients;//spacecraft power coefficients A, B, and C represent the power requirements of the spacecraft at a distance r from the sun, #i.e. heaters, communications, etc
        std::vector<double> engine_input_thrust_coefficients;//thrust polynomial coefficients
        std::vector<double> engine_input_mass_flow_rate_coefficients;//mass flow rate polynomial coefficients
        std::vector<double> engine_input_power_bounds;//thruster input power bounds (kW)
        double user_defined_engine_efficiency;//Propulsion system efficiency (fraction)
        SpacecraftBusPowerType spacecraft_power_model_type;//spacecraft power model type
        double TCM_Isp;//Isp for TCMs
        double TCM_post_launch;//TCM magnitude post-launch (km/s)
        double TCM_pre_flyby;//TCM magnitude before flybys (km/s)
        double TCM_maneuver_fraction;//Post-DSM TCM magnitude as a fraction of DSM magnitude
        bool trackACS;//Track ACS propellant consumption?
        double ACS_kg_per_day;//ACS propellant consumption (kg/day)
        std::vector<double> final_mass_constraint_bounds;//Bounds on final mass constraints
        bool constrain_final_mass;//Constrain final wet mass?
        bool constrain_dry_mass;//Constrain dry mass?
        bool enable_electric_propellant_tank_constraint;//Constrain electric propellant tank?
        double maximum_electric_propellant;//Electric propellant tank capacity (kg)
        double electric_propellant_margin;//Electric propellant margin (fraction)
        bool enable_chemical_propellant_tank_constraint;//Constrain chemical propellant?
        double maximum_chemical_fuel;//Chemical fuel tank capacity (kg)
        double maximum_chemical_oxidizer;//Chemical oxidizer tank capacity (kg)
        double bipropellant_mixture_ratio;//Bipropellant mixture ratio
        double chemical_propellant_margin;//Chemical propellant margin (fraction)
        SpacecraftModelInputType SpacecraftModelInput;//Spacecraft object input type,#0: Assemble from libraries,#1: Read .emtg_spacecraftoptions file,#2: Assemble from missionoptions object
        std::string HardwarePath;//HardwarePath
        std::string ThrottleTableFile;//ThrottleTableFile
        std::string LaunchVehicleLibraryFile;//LaunchVehicleLibraryFile
        std::string PowerSystemsLibraryFile;//PowerSystemsLibraryFile
        std::string PropulsionSystemsLibraryFile;//PropulsionSystemsLibraryFile
        std::string SpacecraftOptionsFile;//SpacecraftOptionsFile
        std::string LaunchVehicleKey;//LaunchVehicleKey
        std::string PowerSystemKey;//PowerSystemKey
        std::string ElectricPropulsionSystemKey;//ElectricPropulsionSystemKey
        std::string ChemicalPropulsionSystemKey;//ChemicalPropulsionSystemKey
        bool perturb_SRP;//solar radiation pressure?
        bool perturb_thirdbody;//third body perturbations?
        bool perturb_J2;//J2?
        double spacecraft_area;//spacecraft area (for SRP, in m^2)
        double coefficient_of_reflectivity;//Coefficient of reflectivity
        double  solar_percentage;//Percentage of the Sun seen by the spacecraft
        double solar_flux;//Solar constant (flux density at 1 AU) [W/m^2 = kg/s^3]
        double speed_of_light_vac;//Speed of light in a vacuum [m/s]
        double forced_post_launch_coast;//Forced post-launch coast, in days
        double forced_pre_flyby_coast;//Forced pre-flyby coast, in days
        double forced_post_flyby_coast;//Forced post-flyby coast, in days
        std::string waypoint_file_path;//Path to waypoint file
        std::string covariance_file_path;//Path to covariance file
        StateRepresentation ParallelShootingStateRepresentation;//state representation for parallel shooting (Cartesian, SphericalRADEC, SphericalAZFPA, COE, MEE)
        StateRepresentation PeriapseBoundaryStateRepresentation;//state representation for periapse boundary conditions (Cartesian, SphericalRADEC, SphericalAZFPA, COE, MEE, IncomingBplane, OutgoingBplane)
        ConstraintStateRepresentation ParallelShootingConstraintStateRepresentation;//state representation for parallel shooting constraints (Cartesian or same as encoded states)
        bool print_only_non_default_options;//Write only options that are *not* default into the .emtgopt file?
        ReferenceFrame output_file_frame;//reference frame for output file (0: J2000_ICRF, 1: J2000_BCI, 2: J2000_BCF, 3: TrueOfDate_BCI, 4: TrueOfDate_BCF, 5: Principle Axes, 6: Topocentric, 7: Polar)
        bool override_default_output_file_name;//Override default output file name?
        std::string forced_output_file_name;//User-defined output file name
        bool output_dormant_journeys;//Output ephemeris for time spent waiting between journeys?
        double post_mission_wait_time;//How long to output an ephemeris after the mission end (days)
        bool override_working_directory;//Override the working directory?
        std::string forced_working_directory;//User-defined working directory
        bool override_mission_subfolder;//Create a mission subfolder?
        std::string forced_mission_subfolder;//Mission subfolder
        bool short_output_file_names;//Shorten output file names?
        bool generate_forward_integrated_ephemeris;//Generate forward-integrated ephemeris?
        int forward_integrated_ephemeris_central_body_SPICE_ID;//SPICE ID of central body for forward integrated ephemeris
        bool add_control_switch_line_to_ephemeris;//Add control switch line to ephemeris?
        bool append_mass_to_ephemeris_output;//Append mass to ephemeris output?
        bool append_control_to_ephemeris_output;//Append control vector to ephemeris output?
        bool append_thrust_to_ephemeris_output;//Append thrust magnitude to ephemeris output?
        bool append_mdot_to_ephemeris_output;//Append mass flow rate to ephemeris output?
        bool append_Isp_to_ephemeris_output;//Append Isp to ephemeris output?
        bool append_active_power_to_ephemeris_output;//Append active power to ephemeris output?
        bool append_number_of_active_engines_to_ephemeris_output;//Append number of active propulsion systems to ephemeris output?
        bool append_throttle_level_to_ephemeris_output;//Append throttle level to ephemeris output?
        bool call_system_to_generate_bsp;//Should EMTG make a system call to clean the .ephemeris file and call python to call spice to generate the bsp?
        std::string spice_utilities_path;//Where are the spice utilities brief and mkspk located?
        std::string spice_utility_extension;//What is the file extension on the spice utlities? Likely either ".exe" for Windows or "" for *nix
        std::string pyemtg_path;//Where is PyEMTG located?
        int spacecraft_SPICE_ID;//SPICE ID of spacecraft for bsp
        bool background_mode;//Close program after completion?
        bool output_STMs;//Output STMs?
        bool output_maneuver_and_target_spec_files;//Output maneuver and target spec files?
        bool generate_acceleration_model_instrumentation_file;//generates a complete output of all acceleration model data at each integration time step (only works for numerically integrated trajectories
        size_t stop_after_journey;//Stop after a particular journey? (if this value is greater than the number of journeys, do the whole mission)
        InnerLoopSolverType run_inner_loop;//Which inner loop solver to run?
        bool check_derivatives;//Check derivatives using NLP finite differencing?
        std::string user_data;//Field for taking notes
        
    private:
        //lower and upper bounds
        ObjectiveFunctionType objective_type_lowerBound;
        ObjectiveFunctionType objective_type_upperBound;
        size_t objective_journey_lowerBound;
        size_t objective_journey_upperBound;
        double launch_window_open_date_lowerBound;
        double launch_window_open_date_upperBound;
        std::vector<double> total_flight_time_bounds_lowerBound;
        std::vector<double> total_flight_time_bounds_upperBound;
        std::vector<double> DLA_bounds_lowerBound;
        std::vector<double> DLA_bounds_upperBound;
        double RLA_bounds_lowerBound;
        double RLA_bounds_upperBound;
        PhaseType mission_type_lowerBound;
        PhaseType mission_type_upperBound;
        int NLP_solver_type_lowerBound;
        int NLP_solver_type_upperBound;
        NLPMode NLP_solver_mode_lowerBound;
        NLPMode NLP_solver_mode_upperBound;
        int MBH_max_not_improve_lowerBound;
        int MBH_max_not_improve_upperBound;
        int MBH_max_trials_lowerBound;
        int MBH_max_trials_upperBound;
        int MBH_max_run_time_lowerBound;
        int MBH_max_run_time_upperBound;
        double MBH_max_step_size_lowerBound;
        double MBH_max_step_size_upperBound;
        int MBH_hop_distribution_lowerBound;
        int MBH_hop_distribution_upperBound;
        double MBH_Pareto_alpha_lowerBound;
        double MBH_Pareto_alpha_upperBound;
        double MBH_time_hop_probability_lowerBound;
        double MBH_time_hop_probability_upperBound;
        double snopt_feasibility_tolerance_lowerBound;
        double snopt_feasibility_tolerance_upperBound;
        double snopt_optimality_tolerance_lowerBound;
        double snopt_optimality_tolerance_upperBound;
        double NLP_max_step_lowerBound;
        double NLP_max_step_upperBound;
        size_t snopt_major_iterations_lowerBound;
        size_t snopt_major_iterations_upperBound;
        size_t snopt_minor_iterations_lowerBound;
        size_t snopt_minor_iterations_upperBound;
        int snopt_max_run_time_lowerBound;
        int snopt_max_run_time_upperBound;
        double NLP_objective_goal_lowerBound;
        double NLP_objective_goal_upperBound;
        int MBH_RNG_seed_lowerBound;
        int MBH_RNG_seed_upperBound;
        int ephemeris_source_lowerBound;
        int ephemeris_source_upperBound;
        size_t SplineEphem_points_per_period_lowerBound;
        size_t SplineEphem_points_per_period_upperBound;
        size_t SplineEphem_non_central_body_sun_points_per_period_lowerBound;
        size_t SplineEphem_non_central_body_sun_points_per_period_upperBound;
        double earliestPossibleEpoch_lowerBound;
        double earliestPossibleEpoch_upperBound;
        double latestPossibleEpoch_lowerBound;
        double latestPossibleEpoch_upperBound;
        PropagatorType propagatorType_lowerBound;
        PropagatorType propagatorType_upperBound;
        IntegratorType integratorType_lowerBound;
        IntegratorType integratorType_upperBound;
        double integrator_tolerance_lowerBound;
        double integrator_tolerance_upperBound;
        double integration_time_step_size_lowerBound;
        double integration_time_step_size_upperBound;
        int num_timesteps_lowerBound;
        int num_timesteps_upperBound;
        size_t spiral_segments_lowerBound;
        size_t spiral_segments_upperBound;
        double maximum_mass_lowerBound;
        double maximum_mass_upperBound;
        double IspLT_lowerBound;
        double IspLT_upperBound;
        double IspLT_minimum_lowerBound;
        double IspLT_minimum_upperBound;
        double IspChem_lowerBound;
        double IspChem_upperBound;
        double Thrust_lowerBound;
        double Thrust_upperBound;
        double LV_margin_lowerBound;
        double LV_margin_upperBound;
        double LV_adapter_mass_lowerBound;
        double LV_adapter_mass_upperBound;
        int engine_type_lowerBound;
        int engine_type_upperBound;
        int number_of_electric_propulsion_systems_lowerBound;
        int number_of_electric_propulsion_systems_upperBound;
        double engine_duty_cycle_lowerBound;
        double engine_duty_cycle_upperBound;
        DutyCycleType duty_cycle_type_lowerBound;
        DutyCycleType duty_cycle_type_upperBound;
        double thrust_scale_factor_lowerBound;
        double thrust_scale_factor_upperBound;
        double power_at_1_AU_lowerBound;
        double power_at_1_AU_upperBound;
        SpacecraftPowerSupplyType power_source_type_lowerBound;
        SpacecraftPowerSupplyType power_source_type_upperBound;
        SpacecraftPowerSupplyCurveType solar_power_model_type_lowerBound;
        SpacecraftPowerSupplyCurveType solar_power_model_type_upperBound;
        double solar_power_gamma_lowerBound;
        double solar_power_gamma_upperBound;
        double power_margin_lowerBound;
        double power_margin_upperBound;
        double power_decay_rate_lowerBound;
        double power_decay_rate_upperBound;
        int power_decay_type_lowerBound;
        int power_decay_type_upperBound;
        double decay_coefficients_lowerBound;
        double decay_coefficients_upperBound;
        double power_system_decay_reference_epoch_lowerBound;
        double power_system_decay_reference_epoch_upperBound;
        double throttle_sharpness_lowerBound;
        double throttle_sharpness_upperBound;
        ThrottleLogic throttle_logic_mode_lowerBound;
        ThrottleLogic throttle_logic_mode_upperBound;
        double spacecraft_power_coefficients_lowerBound;
        double spacecraft_power_coefficients_upperBound;
        double engine_input_thrust_coefficients_lowerBound;
        double engine_input_thrust_coefficients_upperBound;
        double engine_input_mass_flow_rate_coefficients_lowerBound;
        double engine_input_mass_flow_rate_coefficients_upperBound;
        double engine_input_power_bounds_lowerBound;
        double engine_input_power_bounds_upperBound;
        double user_defined_engine_efficiency_lowerBound;
        double user_defined_engine_efficiency_upperBound;
        SpacecraftBusPowerType spacecraft_power_model_type_lowerBound;
        SpacecraftBusPowerType spacecraft_power_model_type_upperBound;
        double TCM_Isp_lowerBound;
        double TCM_Isp_upperBound;
        double TCM_post_launch_lowerBound;
        double TCM_post_launch_upperBound;
        double TCM_pre_flyby_lowerBound;
        double TCM_pre_flyby_upperBound;
        double TCM_maneuver_fraction_lowerBound;
        double TCM_maneuver_fraction_upperBound;
        double ACS_kg_per_day_lowerBound;
        double ACS_kg_per_day_upperBound;
        double final_mass_constraint_bounds_lowerBound;
        double final_mass_constraint_bounds_upperBound;
        double maximum_electric_propellant_lowerBound;
        double maximum_electric_propellant_upperBound;
        double electric_propellant_margin_lowerBound;
        double electric_propellant_margin_upperBound;
        double maximum_chemical_fuel_lowerBound;
        double maximum_chemical_fuel_upperBound;
        double maximum_chemical_oxidizer_lowerBound;
        double maximum_chemical_oxidizer_upperBound;
        double bipropellant_mixture_ratio_lowerBound;
        double bipropellant_mixture_ratio_upperBound;
        double chemical_propellant_margin_lowerBound;
        double chemical_propellant_margin_upperBound;
        SpacecraftModelInputType SpacecraftModelInput_lowerBound;
        SpacecraftModelInputType SpacecraftModelInput_upperBound;
        double spacecraft_area_lowerBound;
        double spacecraft_area_upperBound;
        double coefficient_of_reflectivity_lowerBound;
        double coefficient_of_reflectivity_upperBound;
        double  solar_percentage_lowerBound;
        double  solar_percentage_upperBound;
        double solar_flux_lowerBound;
        double solar_flux_upperBound;
        double speed_of_light_vac_lowerBound;
        double speed_of_light_vac_upperBound;
        double forced_post_launch_coast_lowerBound;
        double forced_post_launch_coast_upperBound;
        double forced_pre_flyby_coast_lowerBound;
        double forced_pre_flyby_coast_upperBound;
        double forced_post_flyby_coast_lowerBound;
        double forced_post_flyby_coast_upperBound;
        StateRepresentation ParallelShootingStateRepresentation_lowerBound;
        StateRepresentation ParallelShootingStateRepresentation_upperBound;
        StateRepresentation PeriapseBoundaryStateRepresentation_lowerBound;
        StateRepresentation PeriapseBoundaryStateRepresentation_upperBound;
        ConstraintStateRepresentation ParallelShootingConstraintStateRepresentation_lowerBound;
        ConstraintStateRepresentation ParallelShootingConstraintStateRepresentation_upperBound;
        ReferenceFrame output_file_frame_lowerBound;
        ReferenceFrame output_file_frame_upperBound;
        double post_mission_wait_time_lowerBound;
        double post_mission_wait_time_upperBound;
        int forward_integrated_ephemeris_central_body_SPICE_ID_lowerBound;
        int forward_integrated_ephemeris_central_body_SPICE_ID_upperBound;
        int spacecraft_SPICE_ID_lowerBound;
        int spacecraft_SPICE_ID_upperBound;
        size_t stop_after_journey_lowerBound;
        size_t stop_after_journey_upperBound;
        InnerLoopSolverType run_inner_loop_lowerBound;
        InnerLoopSolverType run_inner_loop_upperBound;

    }; //end class missionoptions
}//close namespace EMTG
