#ifndef THREAD_EXAMPLE_H
#define THREAD_EXAMPLE_H

#include <ros/ros.h>
#include <nav_msgs/Odometry.h>
#include <sensor_msgs/Imu.h>

class ThreadClass {
public:
    // constructor & destructor
    ThreadClass();
    virtual ~ThreadClass();

private:
    //ROS NodeHandle
    ros::NodeHandle node_handle_;
    
    //Assync spinner
    ros::AsyncSpinner spinner;
    
    // subscribers
    ros::Subscriber imu_sub;
    ros::Subscriber odom_sub;

    //methods
    void imuCallback(const sensor_msgs::Imu::ConstPtr &msg);
    void odomCallback(const nav_msgs::Odometry::ConstPtr &msg);
};

#endif 

