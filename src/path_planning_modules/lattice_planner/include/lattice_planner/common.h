#ifndef COMMON_H_
#define COMMON_H_

#include <fstream>
#include <iostream>
#include <string>

#include <nav_msgs/msg/odometry.hpp>
#include <std_msgs/msg/header.hpp>
#include <vector>
#include "map.h"
#include "reference_line.h"
#include "rclcpp/rclcpp.hpp"
// #include <ros/ros.h>

#include <tf2/LinearMath/Quaternion.h>
#include <tf2/transform_datatypes.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <tf2/convert.h>

struct VehicleState {
  double x;
  double y;
  double heading;   // 车辆朝向
  double kappa;     // 曲率(切线斜率)
  double velocity;    // 速度
  double angular_velocity;  // 角速度
  double acceleration;    // 加速度

  // 规划起点
  double planning_init_x; 
  double planning_init_y;

  double roll;  
  double pitch;
  double yaw;

  double target_curv;  // 期望点的曲率

  double vx;
  double vy;
  double vz;

  double ax;
  double ay;
  double az;

  // added
  double start_point_x;
  double start_point_y;

  double relative_x = 0;
  double relative_y = 0;

  double relative_distance = 0;
};

struct TrajectoryPoint {
  double x;
  double y;
  double heading;
  double kappa;
  double v;
  double a;
};

// 轨迹
struct TrajectoryData {
  std::vector<TrajectoryPoint> trajectory_points;
};

struct LateralControlError {
  double lateral_error; // 横向误差
  double heading_error; // 转向误差
  double lateral_error_rate;  // 横向误差速率
  double heading_error_rate;  // 转向误差速度
};


struct ControlCmd {
  double steer_target;
  double acc;
};


struct EulerAngles {
    double roll, pitch, yaw;
};

struct tPoint {
  double t;
};
typedef std::vector<double> T_Points;

struct sPoint {
  double s;
  double s_d;
  double s_dd;
  double s_ddd;
  double cd = 0.0;
  double cv = 0.0;
  double cf = 0.0;
};
typedef std::vector<sPoint> S_Points;

struct dPoint {
  double d;
  double d_d;
  double d_dd;
  double d_ddd;
};
typedef std::vector<dPoint> D_Points;

struct xPoint {
  double x;
  double y;
  double yaw;
  double ds;
  double c;
};
typedef std::vector<xPoint> X_Points;



typedef std::shared_ptr<LateralControlError> LateralControlErrorPtr;

#endif