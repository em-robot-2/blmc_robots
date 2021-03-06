/**
 * \file stuggihop.hpp
 * \author Manuel Wuthrich
 * \date 2018
 * \copyright Copyright (c) 2019, New York University & Max Planck Gesellschaft.
 */

#ifndef STUGGIHOP_H
#define STUGGIHOP_H

#include <blmc_drivers/blmc_joint_module.hpp>
#include <blmc_robots/common_header.hpp>
#include <blmc_robots/slider.hpp>

namespace blmc_robots
{
class Stuggihop
{
public:
    typedef Eigen::Matrix<double, 1, 1> Vector1d;

    /**
     * @brief Stuggihop is the constructor of the class.
     */
    Stuggihop();

    /**
     * @brief initialize the robot by setting aligning the motors and calibrate
     * the sensors to 0
     */
    void initialize();

    /**
     * @brief send_target_torques sends the target currents to the motors
     */
    void send_target_motor_current(
        const Eigen::Ref<Vector2d> target_motor_current);

    /**
     * @brief send_target_torques sends the target currents to the motors
     */
    void send_target_joint_torque(
        const Eigen::Ref<Vector2d> target_joint_torque);

    /**
     * @brief acquire_sensors acquire all available sensors, WARNING !!!!
     * this method has to be called prior to any getter to have up to date data.
     */
    void acquire_sensors();

    /**
     * @brief set_hardstop2zero_offsets
     *
     */
    void set_hardstop2zero_offsets(
        const Eigen::Ref<Vector2d> hardstop2zero_offsets);

    /**
     * @brief set_start2hardstop_offsets
     *
     */
    void set_start2hardstop_offsets(
        const Eigen::Ref<Vector2d> start2hardstop_offsets);

    /**
     * @brief get_motor_positions
     * @return the current motors positions (rad).
     * WARNING !!!!
     * The method <acquire_sensors>"()" has to be called
     * prior to any getter to have up to date data.
     */
    const Eigen::Ref<Vector2d> get_motor_positions()
    {
        return motor_positions_;
    }

    /**
     * @brief get_motor_velocities
     * @return the current motors velocities (rad/s).
     * WARNING !!!!
     * The method <acquire_sensors>"()" has to be called
     * prior to any getter to have up to date data.
     */
    const Eigen::Ref<Vector2d> get_motor_velocities()
    {
        return motor_velocities_;
    }

    /**
     * @brief get_motor_currents
     * @return the current motors currents in (Ampere: A).
     * WARNING !!!!
     * The method <acquire_sensors>"()" has to be called
     * prior to any getter to have up to date data.
     */
    const Eigen::Ref<Vector2d> get_motor_currents()
    {
        return motor_currents_;
    }

    /**
     * @brief get_motor_target_currents
     * @return the target current motors currents in (Ampere: A).
     * WARNING !!!!
     * The method <acquire_sensors>"()" has to be called
     * prior to any getter to have up to date data.
     */
    const Eigen::Ref<Vector2d> get_motor_target_currents()
    {
        return motor_target_currents_;
    }

    /**
     * @brief get_motor_torques
     * @return the motor torques in Nm
     * WARNING !!!!
     * The method <acquire_sensors>"()" has to be called
     * prior to any getter to have up to date data.
     */
    const Eigen::Ref<Vector2d> get_motor_torques()
    {
        return motor_torques_;
    }

    /**
     * @brief get_target_motor_torques
     * @return the target motor torques in Nm
     */
    const Eigen::Ref<Vector2d> get_target_motor_torques()
    {
        return motor_target_torques_;
    }

    /**
     * @brief get_motor_inertias
     * @return the motor inertias
     */
    const Eigen::Ref<Vector2d> get_motor_inertias()
    {
        return motor_inertias_;
    }

    /**
     * @brief get_motor_encoder_indexes
     * @return the position of the index of the encoders a the motor level
     * WARNING !!!!
     * The method <acquire_sensors>"()" has to be called
     * prior to any getter to have up to date data.
     */
    const Eigen::Ref<Vector2d> get_motor_encoder_indexes()
    {
        return motor_encoder_indexes_;
    }

    /**
     * @brief get_motor_torque_constants
     * @return the torque constants of each motor
     */
    const Eigen::Ref<Vector2d> get_motor_torque_constants()
    {
        return motor_torque_constants_;
    }

    /**
     * @brief get_joint_positions
     * @return  the joint angle of each module
     * WARNING !!!!
     * The method <acquire_sensors>"()" has to be called
     * prior to any getter to have up to date data.
     */
    const Eigen::Ref<Vector2d> get_joint_positions()
    {
        return joint_positions_;
    }

    /**
     * @brief get_joint_velocities
     * @return the joint velocities
     * WARNING !!!!
     * The method <acquire_sensors>"()" has to be called
     * prior to any getter to have up to date data.
     */
    const Eigen::Ref<Vector2d> get_joint_velocities()
    {
        return joint_velocities_;
    }

    /**
     * @brief get_joint_torques
     * @return the joint torques
     * WARNING !!!!
     * The method <acquire_sensors>"()" has to be called
     * prior to any getter to have up to date data.
     */
    const Eigen::Ref<Vector2d> get_joint_torques()
    {
        return joint_torques_;
    }

    /**
     * @brief get_joint_torques
     * @return the target joint torques
     */
    const Eigen::Ref<Vector2d> get_joint_target_torques()
    {
        return joint_target_torques_;
    }

    /**
     * @brief get_joint_gear_ratios
     * @return  the joint gear ratios
     */
    const Eigen::Ref<Vector2d> get_joint_gear_ratios()
    {
        return joint_gear_ratios_;
    }

    /**
     * @brief get_joint_encoder_index
     * @return The last observed encoder index in joint coordinates.
     * WARNING !!!!
     * The method <acquire_sensors>"()" has to be called
     * prior to any getter to have up to date data.
     */
    const Eigen::Ref<Vector2d> get_joint_encoder_index()
    {
        return joint_encoder_index_;
    }

    /**
     * @brief get_hardstop2zero_offsets
     * @return the position where the robot should be in "zero" configuration
     */
    const Eigen::Ref<Vector2d> get_hardstop2zero_offsets()
    {
        return joint_hardstop2zero_offsets_;
    }
    /**
     * @brief get_start2hardstop_offsets_
     * @return the position where the robot should be in "zero" configuration
     */
    const Eigen::Ref<Vector2d> get_start2hardstop_offsets_()
    {
        return joint_start2hardstop_offsets_;
    }

    /**
     * @brief get_slider_positions
     * @return the current sliders positions.
     * WARNING !!!!
     * The method <acquire_sensors>"()" has to be called
     * prior to any getter to have up to date data.
     */
    // const Eigen::Ref<Vector1d> get_slider_positions()
    // {
    //   return slider_positions_;
    // }

    /**
     * @brief get_contact_sensors_states
     * @return the state of the contacts states
     * WARNING !!!!
     * The method <acquire_sensors>"()" has to be called
     * prior to any getter to have up to date data.
     */
    // const Eigen::Ref<Vector1d> get_contact_sensors_states()
    // {
    //   return contact_sensors_states_;
    // }

    /**
     * @brief get_contact_sensors_states
     * @return the state of the contacts states
     * WARNING !!!!
     * The method <acquire_sensors>"()" has to be called
     * prior to any getter to have up to date data.
     */
    // const Eigen::Ref<Vector1d> get_height_sensors()
    // {
    //   return height_sensors_states_;
    // }

    /**
     * @brief get_base_positions
     * @return the x,y position of the floating base
     * The method <acquire_sensors>"()" has to be called
     * prior to any getter to have up to date data.
     */
    const Eigen::Ref<Vector2d> get_base_positions()
    {
        return base_positions_;
    }

    /**
     * @brief get_base_velocities
     * @return the x,y velocities of the floating base
     * The method <acquire_sensors>"()" has to be called
     * prior to any getter to have up to date data.
     */
    const Eigen::Ref<Vector2d> get_base_velocities()
    {
        return base_velocities_;
    }

    /**
     * @brief get_max_current
     * @return the max current that has been hardcoded in the constructor of
     * this class. TODO: parametrize this via yaml or something else.
     */
    const Eigen::Ref<Vector2d> get_max_current()
    {
        return motor_max_current_;
    }

    /**
     * @brief get_max_torque
     * @return the max torque that has been hardcoded in the constructor of this
     * class. TODO: parametrize this via yaml or something else.
     */
    const Eigen::Ref<Vector2d> get_max_joint_torque()
    {
        return joint_max_torque_;
    }

    /**
     * @brief set_max_current sets the maximum current that the motor can
     * to apply.
     * @param max_current contain 1 value per each motors.
     */
    void set_max_current(const Eigen::Ref<Vector2d> max_current)
    {
        motor_max_current_ = max_current;
        for (unsigned i = 0; i < motors_.size(); ++i)
        {
            motors_[i]->set_max_current(motor_max_current_(i));
        }
        joint_max_torque_ = motor_max_current_.array() *
                            motor_torque_constants_.array() *
                            joint_gear_ratios_.array();
    }

private:
    /**
     * Motor data
     */

    /**
     * @brief motor_positions_
     */
    Vector2d motor_positions_;
    /**
     * @brief motor_velocities_
     */
    Vector2d motor_velocities_;
    /**
     * @brief motor_currents_
     */
    Vector2d motor_currents_;
    /**
     * @brief motor_torques_
     */
    Vector2d motor_torques_;
    /**
     * @brief motor_inertias_
     */
    Vector2d motor_inertias_;
    /**
     * @brief motor_encoder_indexes_
     */
    Vector2d motor_encoder_indexes_;
    /**
     * @brief motor_target_currents_
     */
    Vector2d motor_target_currents_;
    /**
     * @brief motor_target_torques_
     */
    Vector2d motor_target_torques_;
    /**
     * @brief motor_torque_constants_ are the motor torque constants
     */
    Vector2d motor_torque_constants_;
    /**
     * @brief target_motor_current_tmp_ is used to convert the joint torque to
     * motor current
     */
    Vector2d target_motor_current_tmp_;

    /**
     * Joint data
     */

    /**
     * @brief joint_positions_
     */
    Vector2d joint_positions_;
    /**
     * @brief joint_velocities_
     */
    Vector2d joint_velocities_;
    /**
     * @brief joint_torques_
     */
    Vector2d joint_torques_;
    /**
     * @brief joint_target_torques_
     */
    Vector2d joint_target_torques_;
    /**
     * @brief joint_gear_ratios are the joint gear ratios
     */
    Vector2d joint_gear_ratios_;
    /**
     * @brief joint_encoder_index_ The last observed encoder_index at the
     * joints.
     */
    Vector2d joint_encoder_index_;

    Vector2d joint_hardstop2zero_offsets_;
    /**
     * @brief joint_start2hardstop_offsets_ are the offsets from the encoders
     * when powered on, till the hardstops. These need to be calibrated each
     * time.
     */
    Vector2d joint_start2hardstop_offsets_;
    /**
     * @brief joint_max_torque_
     */
    Vector2d joint_max_torque_;

    /**
     * Additional data
     */

    /**
     * @brief boom_gear_ratios are the joint gear ratios
     */
    Vector2d boom_gear_ratios_;
    /**
     * @brief boom_encoder_index_ The last observed encoder_index at the booms.
     */
    Vector2d boom_encoder_index_;

    /**
     * @brief boom_zero_positions_ is the configuration considered as zero
     * position
     */
    Vector2d boom_zero_positions_;

    /**
     * @brief boom_length_ is the length (radius) of the boom
     */
    Vector1d boom_length_;

    /**
     * @brief based_positions_ is a 2D vector with the x and y position of the
     * floating base
     */
    // Vector1d height_sensors_states_;
    Vector2d base_positions_;

    /**
     * @brief based_positions_ is a 2D vector with the x and y position of the
     * floating base
     */
    // Vector1d height_sensors_states_;
    Vector2d base_velocities_;

    /**
     * @brief based_positions_ is a 2D vector with the x and y position of the
     * floating base
     */
    // Vector1d height_sensors_states_;
    Vector2d boom_positions_;

    /**
     * @brief based_positions_ is a 2D vector with the x and y position of the
     * floating base
     */
    // Vector1d height_sensors_states_;
    Vector2d boom_velocities_;

    /**
     * @brief max_current_ is the maximum current that can be sent to the
     * motors, this a safe guard for development
     */
    Vector2d motor_max_current_;

    /**
     * Drivers communication objects
     */

    /**
     * @brief can_buses_ are the 2 can buses on the robot.
     */
    std::array<CanBus_ptr, 2> can_buses_;
    /**
     * @brief can_motor_boards_ are the 2 can motor board.
     */
    std::array<CanBusMotorBoard_ptr, 2> can_motor_boards_;
    /**
     * @brief motors_ are the objects allowing us to send motor commands and
     * receive data
     */
    std::array<SafeMotor_ptr, 2> motors_;

    /**
     * @brief sliders_ these are analogue input from linear potentiometers.
     */
    // std::array<Slider_ptr, 2> sliders_;

    /**
     * @brief boom_encoders_ are the encoders measuring the boom joints. These
     * are plugged into the quadrature ports of motors, and we'll thus use a
     * Motor to
     */
    std::array<SafeMotor_ptr, 2> boom_encoders_;

    /**
     * @brief contact_sensors_ is the contact sensors at each foot tips. They
     * also are analogue inputs.
     */
    // std::array<ContactSensor_ptr, 1> contact_sensors_;

    /**
     * @brief contact_sensors_ is the contact sensors at each foot tips. They
     * also are analogue inputs.
     */
    // std::array<HeightSensor_ptr, 1> height_sensors_;
};

}  // namespace blmc_robots

#endif  // STUGGIHOP_H
