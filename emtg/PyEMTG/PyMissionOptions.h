//header file for PyMissionOptions class
//auto-generated by make_EMTG_missionoptions_journeyoptions.py

#ifdef EMTG_OPTIONS_PYTHON_INTERFACE
#include "boost/python.hpp"
#include "boost/python/list.hpp"
#include "boost/python/extract.hpp"

    BOOST_PYTHON_MODULE(PyMissionOptions)
    {
        using namespace EMTG;

        boost::python::class_<JourneyOptions>("JourneyOptions", boost::python::init<std::string>())
                                          .def_readwrite("journey_name", &JourneyOptions::journey_name)
                                          .def_readwrite("journey_central_body", &JourneyOptions::journey_central_body)
                                          .def_readwrite("destination_list", &JourneyOptions::destination_list)
                                          .def_readwrite("sequence", &JourneyOptions::sequence)
                                          .def_readwrite("phase_type", &JourneyOptions::phase_type)
                                          .def_readwrite("impulses_per_phase", &JourneyOptions::impulses_per_phase)
                                          .def_readwrite("override_num_steps", &JourneyOptions::override_num_steps)
                                          .def_readwrite("number_of_steps", &JourneyOptions::number_of_steps)
                                          .def_readwrite("override_duty_cycle", &JourneyOptions::override_duty_cycle)
                                          .def_readwrite("duty_cycle", &JourneyOptions::duty_cycle)
                                          .def_readwrite("override_PropagatorType", &JourneyOptions::override_PropagatorType)
                                          .def_readwrite("propagatorType", &JourneyOptions::propagatorType)
                                          .def_readwrite("override_integration_step_size", &JourneyOptions::override_integration_step_size)
                                          .def_readwrite("integration_step_size", &JourneyOptions::integration_step_size)
                                          .def_readwrite("override_flyby_altitude_bounds", &JourneyOptions::override_flyby_altitude_bounds)
                                          .def_readwrite("flyby_altitude_bounds", &JourneyOptions::flyby_altitude_bounds)
                                          .def_readwrite("PeriapseArrival_override_altitude", &JourneyOptions::PeriapseArrival_override_altitude)
                                          .def_readwrite("PeriapseArrival_altitude_bounds", &JourneyOptions::PeriapseArrival_altitude_bounds)
                                          .def_readwrite("PeriapseDeparture_altitude_bounds", &JourneyOptions::PeriapseDeparture_altitude_bounds)
                                          .def_readwrite("num_interior_control_points", &JourneyOptions::num_interior_control_points)
                                          .def_readwrite("CoastPhaseMatchPointFraction", &JourneyOptions::CoastPhaseMatchPointFraction)
                                          .def_readwrite("CoastPhaseForwardIntegrationStepLength", &JourneyOptions::CoastPhaseForwardIntegrationStepLength)
                                          .def_readwrite("CoastPhaseBackwardIntegrationStepLength", &JourneyOptions::CoastPhaseBackwardIntegrationStepLength)
                                          .def_readwrite("journey_end_TCM", &JourneyOptions::journey_end_TCM)
                                          .def_readwrite("enable_periapse_burns", &JourneyOptions::enable_periapse_burns)
                                          .def_readwrite("bounded_departure_date", &JourneyOptions::bounded_departure_date)
                                          .def_readwrite("timebounded", &JourneyOptions::timebounded)
                                          .def_readwrite("departure_date_bounds", &JourneyOptions::departure_date_bounds)
                                          .def_readwrite("wait_time_bounds", &JourneyOptions::wait_time_bounds)
                                          .def_readwrite("flight_time_bounds", &JourneyOptions::flight_time_bounds)
                                          .def_readwrite("arrival_date_bounds", &JourneyOptions::arrival_date_bounds)
                                          .def_readwrite("departure_type", &JourneyOptions::departure_type)
                                          .def_readwrite("initial_impulse_bounds", &JourneyOptions::initial_impulse_bounds)
                                          .def_readwrite("departure_elements_vary_flag", &JourneyOptions::departure_elements_vary_flag)
                                          .def_readwrite("departure_elements", &JourneyOptions::departure_elements)
                                          .def_readwrite("departure_elements_bounds", &JourneyOptions::departure_elements_bounds)
                                          .def_readwrite("departure_elements_reference_epoch", &JourneyOptions::departure_elements_reference_epoch)
                                          .def_readwrite("departure_elements_state_representation", &JourneyOptions::departure_elements_state_representation)
                                          .def_readwrite("departure_elements_frame", &JourneyOptions::departure_elements_frame)
                                          .def_readwrite("AllowJourneyFreePointDepartureToPropagate", &JourneyOptions::AllowJourneyFreePointDepartureToPropagate)
                                          .def_readwrite("maximum_starting_mass_increment", &JourneyOptions::maximum_starting_mass_increment)
                                          .def_readwrite("minimum_starting_mass_increment", &JourneyOptions::minimum_starting_mass_increment)
                                          .def_readwrite("fixed_starting_mass_increment", &JourneyOptions::fixed_starting_mass_increment)
                                          .def_readwrite("fixed_ending_mass_increment", &JourneyOptions::fixed_ending_mass_increment)
                                          .def_readwrite("variable_mass_increment", &JourneyOptions::variable_mass_increment)
                                          .def_readwrite("constrain_initial_mass", &JourneyOptions::constrain_initial_mass)
                                          .def_readwrite("maximum_initial_mass", &JourneyOptions::maximum_initial_mass)
                                          .def_readwrite("departure_class", &JourneyOptions::departure_class)
                                          .def_readwrite("departure_ellipsoid_axes", &JourneyOptions::departure_ellipsoid_axes)
                                          .def_readwrite("arrival_type", &JourneyOptions::arrival_type)
                                          .def_readwrite("arrival_elements_vary_flag", &JourneyOptions::arrival_elements_vary_flag)
                                          .def_readwrite("arrival_elements", &JourneyOptions::arrival_elements)
                                          .def_readwrite("arrival_elements_bounds", &JourneyOptions::arrival_elements_bounds)
                                          .def_readwrite("arrival_elements_reference_epoch", &JourneyOptions::arrival_elements_reference_epoch)
                                          .def_readwrite("arrival_elements_state_representation", &JourneyOptions::arrival_elements_state_representation)
                                          .def_readwrite("arrival_elements_frame", &JourneyOptions::arrival_elements_frame)
                                          .def_readwrite("AllowJourneyFreePointArrivalToPropagate", &JourneyOptions::AllowJourneyFreePointArrivalToPropagate)
                                          .def_readwrite("final_velocity", &JourneyOptions::final_velocity)
                                          .def_readwrite("forced_terminal_coast", &JourneyOptions::forced_terminal_coast)
                                          .def_readwrite("forced_initial_coast", &JourneyOptions::forced_initial_coast)
                                          .def_readwrite("arrival_class", &JourneyOptions::arrival_class)
                                          .def_readwrite("arrival_ellipsoid_axes", &JourneyOptions::arrival_ellipsoid_axes)
                                          .def_readwrite("zero_turn_flyby_distance", &JourneyOptions::zero_turn_flyby_distance)
                                          .def_readwrite("terminal_intercept_flyby_distance", &JourneyOptions::terminal_intercept_flyby_distance)
                                          .def_readwrite("escape_spiral_starting_radius", &JourneyOptions::escape_spiral_starting_radius)
                                          .def_readwrite("capture_spiral_final_radius", &JourneyOptions::capture_spiral_final_radius)
                                          .def_readwrite("FreePointArrival_print_target_spec", &JourneyOptions::FreePointArrival_print_target_spec)
                                          .def_readwrite("journey_end_deltav", &JourneyOptions::journey_end_deltav)
                                          .def_readwrite("journey_end_propulsion_system", &JourneyOptions::journey_end_propulsion_system)
                                          .def_readwrite("perturbation_bodies", &JourneyOptions::perturbation_bodies)
                                          .def_readwrite("stage_after_departure", &JourneyOptions::stage_after_departure)
                                          .def_readwrite("stage_before_arrival", &JourneyOptions::stage_before_arrival)
                                          .def_readwrite("stage_after_arrival", &JourneyOptions::stage_after_arrival)
                                          .def_readwrite("freeze_decision_variables", &JourneyOptions::freeze_decision_variables)
                                          .def_readwrite("ephemeris_pegged_orbit_insertion_SMA", &JourneyOptions::ephemeris_pegged_orbit_insertion_SMA)
                                          .def_readwrite("ephemeris_pegged_orbit_insertion_ECC", &JourneyOptions::ephemeris_pegged_orbit_insertion_ECC)
                                          .def_readwrite("impact_momentum_enhancement_factor", &JourneyOptions::impact_momentum_enhancement_factor)
                                          ;

        boost::python::class_<missionoptions>("MissionOptions", boost::python::init<std::string>())
                                          .def_readwrite("Journeys", &missionoptions::Journeys)
                                          .def_readwrite("number_of_journeys", &missionoptions::number_of_journeys)
                                          .def_readwrite("mission_name", &missionoptions::mission_name)
                                          .def_readwrite("objective_type", &missionoptions::objective_type)
                                          .def_readwrite("objective_journey", &missionoptions::objective_journey)
                                          .def_readwrite("include_initial_impulse_in_cost", &missionoptions::include_initial_impulse_in_cost)
                                          .def_readwrite("global_timebounded", &missionoptions::global_timebounded)
                                          .def_readwrite("launch_window_open_date", &missionoptions::launch_window_open_date)
                                          .def_readwrite("total_flight_time_bounds", &missionoptions::total_flight_time_bounds)
                                          .def_readwrite("DLA_bounds", &missionoptions::DLA_bounds)
                                          .def_readwrite("RLA_bounds", &missionoptions::RLA_bounds)
                                          .def_readwrite("mission_type", &missionoptions::mission_type)
                                          .def_readwrite("NLP_solver_type", &missionoptions::NLP_solver_type)
                                          .def_readwrite("NLP_solver_mode", &missionoptions::NLP_solver_mode)
                                          .def_readwrite("quiet_NLP", &missionoptions::quiet_NLP)
                                          .def_readwrite("ACE_feasible_point_finder", &missionoptions::ACE_feasible_point_finder)
                                          .def_readwrite("MBH_always_write_archive", &missionoptions::MBH_always_write_archive)
                                          .def_readwrite("MBH_archive_state_vector", &missionoptions::MBH_archive_state_vector)
                                          .def_readwrite("MBH_max_not_improve", &missionoptions::MBH_max_not_improve)
                                          .def_readwrite("MBH_max_trials", &missionoptions::MBH_max_trials)
                                          .def_readwrite("MBH_max_run_time", &missionoptions::MBH_max_run_time)
                                          .def_readwrite("MBH_max_step_size", &missionoptions::MBH_max_step_size)
                                          .def_readwrite("MBH_hop_distribution", &missionoptions::MBH_hop_distribution)
                                          .def_readwrite("MBH_Pareto_alpha", &missionoptions::MBH_Pareto_alpha)
                                          .def_readwrite("MBH_write_every_improvement", &missionoptions::MBH_write_every_improvement)
                                          .def_readwrite("MBH_time_hop_probability", &missionoptions::MBH_time_hop_probability)
                                          .def_readwrite("snopt_feasibility_tolerance", &missionoptions::snopt_feasibility_tolerance)
                                          .def_readwrite("snopt_optimality_tolerance", &missionoptions::snopt_optimality_tolerance)
                                          .def_readwrite("NLP_max_step", &missionoptions::NLP_max_step)
                                          .def_readwrite("snopt_major_iterations", &missionoptions::snopt_major_iterations)
                                          .def_readwrite("snopt_minor_iterations", &missionoptions::snopt_minor_iterations)
                                          .def_readwrite("snopt_max_run_time", &missionoptions::snopt_max_run_time)
                                          .def_readwrite("enable_Scalatron", &missionoptions::enable_Scalatron)
                                          .def_readwrite("enable_NLP_chaperone", &missionoptions::enable_NLP_chaperone)
                                          .def_readwrite("seed_MBH", &missionoptions::seed_MBH)
                                          .def_readwrite("skip_first_nlp_run", &missionoptions::skip_first_nlp_run)
                                          .def_readwrite("NLP_stop_on_goal_attain", &missionoptions::NLP_stop_on_goal_attain)
                                          .def_readwrite("NLP_objective_goal", &missionoptions::NLP_objective_goal)
                                          .def_readwrite("MBH_RNG_seed", &missionoptions::MBH_RNG_seed)
                                          .def_readwrite("print_NLP_movie_frames", &missionoptions::print_NLP_movie_frames)
                                          .def_readwrite("quiet_basinhopping", &missionoptions::quiet_basinhopping)
                                          .def_readwrite("SPICE_leap_seconds_kernel", &missionoptions::SPICE_leap_seconds_kernel)
                                          .def_readwrite("SPICE_reference_frame_kernel", &missionoptions::SPICE_reference_frame_kernel)
                                          .def_readwrite("universe_folder", &missionoptions::universe_folder)
                                          .def_readwrite("ephemeris_source", &missionoptions::ephemeris_source)
                                          .def_readwrite("SplineEphem_points_per_period", &missionoptions::SplineEphem_points_per_period)
                                          .def_readwrite("SplineEphem_non_central_body_sun_points_per_period", &missionoptions::SplineEphem_non_central_body_sun_points_per_period)
                                          .def_readwrite("SplineEphem_truncate_ephemeris_at_maximum_mission_epoch", &missionoptions::SplineEphem_truncate_ephemeris_at_maximum_mission_epoch)
                                          .def_readwrite("earliestPossibleEpoch", &missionoptions::earliestPossibleEpoch)
                                          .def_readwrite("latestPossibleEpoch", &missionoptions::latestPossibleEpoch)
                                          .def_readwrite("propagatorType", &missionoptions::propagatorType)
                                          .def_readwrite("integratorType", &missionoptions::integratorType)
                                          .def_readwrite("integrator_tolerance", &missionoptions::integrator_tolerance)
                                          .def_readwrite("integration_time_step_size", &missionoptions::integration_time_step_size)
                                          .def_readwrite("num_timesteps", &missionoptions::num_timesteps)
                                          .def_readwrite("spiral_segments", &missionoptions::spiral_segments)
                                          .def_readwrite("allow_initial_mass_to_vary", &missionoptions::allow_initial_mass_to_vary)
                                          .def_readwrite("maximum_mass", &missionoptions::maximum_mass)
                                          .def_readwrite("IspLT", &missionoptions::IspLT)
                                          .def_readwrite("IspLT_minimum", &missionoptions::IspLT_minimum)
                                          .def_readwrite("IspChem", &missionoptions::IspChem)
                                          .def_readwrite("Thrust", &missionoptions::Thrust)
                                          .def_readwrite("LV_margin", &missionoptions::LV_margin)
                                          .def_readwrite("LV_adapter_mass", &missionoptions::LV_adapter_mass)
                                          .def_readwrite("engine_type", &missionoptions::engine_type)
                                          .def_readwrite("number_of_electric_propulsion_systems", &missionoptions::number_of_electric_propulsion_systems)
                                          .def_readwrite("engine_duty_cycle", &missionoptions::engine_duty_cycle)
                                          .def_readwrite("duty_cycle_type", &missionoptions::duty_cycle_type)
                                          .def_readwrite("thrust_scale_factor", &missionoptions::thrust_scale_factor)
                                          .def_readwrite("power_at_1_AU", &missionoptions::power_at_1_AU)
                                          .def_readwrite("power_source_type", &missionoptions::power_source_type)
                                          .def_readwrite("solar_power_model_type", &missionoptions::solar_power_model_type)
                                          .def_readwrite("solar_power_gamma", &missionoptions::solar_power_gamma)
                                          .def_readwrite("power_margin", &missionoptions::power_margin)
                                          .def_readwrite("power_decay_rate", &missionoptions::power_decay_rate)
                                          .def_readwrite("throttle_sharpness", &missionoptions::throttle_sharpness)
                                          .def_readwrite("throttle_logic_mode", &missionoptions::throttle_logic_mode)
                                          .def_readwrite("spacecraft_power_coefficients", &missionoptions::spacecraft_power_coefficients)
                                          .def_readwrite("engine_input_thrust_coefficients", &missionoptions::engine_input_thrust_coefficients)
                                          .def_readwrite("engine_input_mass_flow_rate_coefficients", &missionoptions::engine_input_mass_flow_rate_coefficients)
                                          .def_readwrite("engine_input_power_bounds", &missionoptions::engine_input_power_bounds)
                                          .def_readwrite("user_defined_engine_efficiency", &missionoptions::user_defined_engine_efficiency)
                                          .def_readwrite("spacecraft_power_model_type", &missionoptions::spacecraft_power_model_type)
                                          .def_readwrite("TCM_Isp", &missionoptions::TCM_Isp)
                                          .def_readwrite("TCM_post_launch", &missionoptions::TCM_post_launch)
                                          .def_readwrite("TCM_pre_flyby", &missionoptions::TCM_pre_flyby)
                                          .def_readwrite("TCM_maneuver_fraction", &missionoptions::TCM_maneuver_fraction)
                                          .def_readwrite("trackACS", &missionoptions::trackACS)
                                          .def_readwrite("ACS_kg_per_day", &missionoptions::ACS_kg_per_day)
                                          .def_readwrite("final_mass_constraint_bounds", &missionoptions::final_mass_constraint_bounds)
                                          .def_readwrite("constrain_final_mass", &missionoptions::constrain_final_mass)
                                          .def_readwrite("constrain_dry_mass", &missionoptions::constrain_dry_mass)
                                          .def_readwrite("enable_electric_propellant_tank_constraint", &missionoptions::enable_electric_propellant_tank_constraint)
                                          .def_readwrite("maximum_electric_propellant", &missionoptions::maximum_electric_propellant)
                                          .def_readwrite("electric_propellant_margin", &missionoptions::electric_propellant_margin)
                                          .def_readwrite("enable_chemical_propellant_tank_constraint", &missionoptions::enable_chemical_propellant_tank_constraint)
                                          .def_readwrite("maximum_chemical_fuel", &missionoptions::maximum_chemical_fuel)
                                          .def_readwrite("maximum_chemical_oxidizer", &missionoptions::maximum_chemical_oxidizer)
                                          .def_readwrite("bipropellant_mixture_ratio", &missionoptions::bipropellant_mixture_ratio)
                                          .def_readwrite("chemical_propellant_margin", &missionoptions::chemical_propellant_margin)
                                          .def_readwrite("SpacecraftModelInput", &missionoptions::SpacecraftModelInput)
                                          .def_readwrite("HardwarePath", &missionoptions::HardwarePath)
                                          .def_readwrite("ThrottleTableFile", &missionoptions::ThrottleTableFile)
                                          .def_readwrite("LaunchVehicleLibraryFile", &missionoptions::LaunchVehicleLibraryFile)
                                          .def_readwrite("PowerSystemsLibraryFile", &missionoptions::PowerSystemsLibraryFile)
                                          .def_readwrite("PropulsionSystemsLibraryFile", &missionoptions::PropulsionSystemsLibraryFile)
                                          .def_readwrite("SpacecraftOptionsFile", &missionoptions::SpacecraftOptionsFile)
                                          .def_readwrite("LaunchVehicleKey", &missionoptions::LaunchVehicleKey)
                                          .def_readwrite("PowerSystemKey", &missionoptions::PowerSystemKey)
                                          .def_readwrite("ElectricPropulsionSystemKey", &missionoptions::ElectricPropulsionSystemKey)
                                          .def_readwrite("ChemicalPropulsionSystemKey", &missionoptions::ChemicalPropulsionSystemKey)
                                          .def_readwrite("perturb_SRP", &missionoptions::perturb_SRP)
                                          .def_readwrite("perturb_thirdbody", &missionoptions::perturb_thirdbody)
                                          .def_readwrite("perturb_J2", &missionoptions::perturb_J2)
                                          .def_readwrite("spacecraft_area", &missionoptions::spacecraft_area)
                                          .def_readwrite("coefficient_of_reflectivity", &missionoptions::coefficient_of_reflectivity)
                                          .def_readwrite("solar_percentage", &missionoptions::solar_percentage)
                                          .def_readwrite("solar_flux", &missionoptions::solar_flux)
                                          .def_readwrite("speed_of_light_vac", &missionoptions::speed_of_light_vac)
                                          .def_readwrite("forced_post_launch_coast", &missionoptions::forced_post_launch_coast)
                                          .def_readwrite("forced_pre_flyby_coast", &missionoptions::forced_pre_flyby_coast)
                                          .def_readwrite("forced_post_flyby_coast", &missionoptions::forced_post_flyby_coast)
                                          .def_readwrite("waypoint_file_path", &missionoptions::waypoint_file_path)
                                          .def_readwrite("covariance_file_path", &missionoptions::covariance_file_path)
                                          .def_readwrite("ParallelShootingStateRepresentation", &missionoptions::ParallelShootingStateRepresentation)
                                          .def_readwrite("PeriapseBoundaryStateRepresentation", &missionoptions::PeriapseBoundaryStateRepresentation)
                                          .def_readwrite("print_only_non_default_options", &missionoptions::print_only_non_default_options)
                                          .def_readwrite("output_file_frame", &missionoptions::output_file_frame)
                                          .def_readwrite("override_default_output_file_name", &missionoptions::override_default_output_file_name)
                                          .def_readwrite("forced_output_file_name", &missionoptions::forced_output_file_name)
                                          .def_readwrite("output_dormant_journeys", &missionoptions::output_dormant_journeys)
                                          .def_readwrite("post_mission_wait_time", &missionoptions::post_mission_wait_time)
                                          .def_readwrite("override_working_directory", &missionoptions::override_working_directory)
                                          .def_readwrite("forced_working_directory", &missionoptions::forced_working_directory)
                                          .def_readwrite("override_mission_subfolder", &missionoptions::override_mission_subfolder)
                                          .def_readwrite("forced_mission_subfolder", &missionoptions::forced_mission_subfolder)
                                          .def_readwrite("short_output_file_names", &missionoptions::short_output_file_names)
                                          .def_readwrite("generate_forward_integrated_ephemeris", &missionoptions::generate_forward_integrated_ephemeris)
                                          .def_readwrite("add_control_switch_line_to_ephemeris", &missionoptions::add_control_switch_line_to_ephemeris)
                                          .def_readwrite("append_mass_to_ephemeris_output", &missionoptions::append_mass_to_ephemeris_output)
                                          .def_readwrite("append_control_to_ephemeris_output", &missionoptions::append_control_to_ephemeris_output)
                                          .def_readwrite("append_thrust_to_ephemeris_output", &missionoptions::append_thrust_to_ephemeris_output)
                                          .def_readwrite("append_mdot_to_ephemeris_output", &missionoptions::append_mdot_to_ephemeris_output)
                                          .def_readwrite("append_Isp_to_ephemeris_output", &missionoptions::append_Isp_to_ephemeris_output)
                                          .def_readwrite("append_active_power_to_ephemeris_output", &missionoptions::append_active_power_to_ephemeris_output)
                                          .def_readwrite("append_number_of_active_engines_to_ephemeris_output", &missionoptions::append_number_of_active_engines_to_ephemeris_output)
                                          .def_readwrite("append_throttle_level_to_ephemeris_output", &missionoptions::append_throttle_level_to_ephemeris_output)
                                          .def_readwrite("background_mode", &missionoptions::background_mode)
                                          .def_readwrite("output_STMs", &missionoptions::output_STMs)
                                          .def_readwrite("output_maneuver_and_target_spec_files", &missionoptions::output_maneuver_and_target_spec_files)
                                          .def_readwrite("generate_acceleration_model_instrumentation_file", &missionoptions::generate_acceleration_model_instrumentation_file)
                                          .def_readwrite("stop_after_journey", &missionoptions::stop_after_journey)
                                          .def_readwrite("run_inner_loop", &missionoptions::run_inner_loop)
                                          .def_readwrite("check_derivatives", &missionoptions::check_derivatives)
                                          .def_readwrite("user_data", &missionoptions::user_data)
                                          ;


    }
#endif
