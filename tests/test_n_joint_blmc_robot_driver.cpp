/**
 * @file
 * @brief Test for NJointBlmcRobotDriver.
 * @copyright Copyright (c) 2020, New York University & Max Planck Gesellschaft.
 */
#include <gtest/gtest.h>
#include <blmc_robots/n_joint_blmc_robot_driver.hpp>

using Driver = blmc_robots::SimpleNJointBlmcRobotDriver<2>;

TEST(TestNJointBlmcRobotDriverConfig, is_within_joint_limits)
{
    Driver::Config config;
    config.joint_lower_limits << -1.0, 0;
    config.joint_upper_limits << +0.5, +1.0;

    // bounds are inclusive
    ASSERT_TRUE(config.is_within_joint_limits(config.joint_lower_limits));
    ASSERT_TRUE(config.is_within_joint_limits(config.joint_upper_limits));

    // some positions inside the limits
    ASSERT_TRUE(config.is_within_joint_limits(Driver::Vector(0, 0.3)));
    ASSERT_TRUE(config.is_within_joint_limits(Driver::Vector(-0.9, 0.9)));
    ASSERT_TRUE(config.is_within_joint_limits(Driver::Vector(0.4, 0.1)));

    // some positions outside the limits
    ASSERT_FALSE(config.is_within_joint_limits(Driver::Vector(-2, -1)));
    ASSERT_FALSE(config.is_within_joint_limits(Driver::Vector(-2, 0.5)));
    ASSERT_FALSE(config.is_within_joint_limits(Driver::Vector(-0.5, -1)));
    ASSERT_FALSE(config.is_within_joint_limits(Driver::Vector(-0.5, 2)));
    ASSERT_FALSE(config.is_within_joint_limits(Driver::Vector(1, 2)));
    ASSERT_FALSE(config.is_within_joint_limits(Driver::Vector(1, 0.5)));
}
