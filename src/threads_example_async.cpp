#include <ros/ros.h>
#include <iostream>
#include "cpp_threads_example/threads_example_async.h"

    // 컨스트럭터에 node_hanle_을 (private으로 되어 있음) 사용
    ThreadClass::ThreadClass() : node_handle_(""), spinner(0) {
        // spinner(0) 은 가능한 코어를 모두 사용한다 
        ROS_INFO("Init Started");

        //spinner.start()를 함으로써 멀티 쓰레드를 사용할 수 있게 된다 
        // 아래에서 imuCallback에서 Duration으로 sleep을 걸어도 다른 콜백 함수인 odomCallback은 정상 작동하게 된다 
        spinner.start();
        
        // topic은 상황에 맞게 변경
        imu_sub = node_handle_.subscribe("/imu", 10, &ThreadClass::imuCallback, this);
        odom_sub = node_handle_.subscribe("/odom", 10, &ThreadClass::odomCallback, this);

        ROS_INFO("Init Finished");

    }

    ThreadClass::~ThreadClass() {
        ros::shutdown(); 
    }

    void ThreadClass::imuCallback(const sensor_msgs::Imu::ConstPtr &msg) {
        float x_vel = msg->angular_velocity.x;
        float y_vel = msg->angular_velocity.y;

        ros::Duration(5.0).sleep(); // 만약 이렇게 sleep을 넣어준다면?
        // ros::spin은 single thread 이기 때문에 다른 콜백 함수에 영향을 준다 그래서 엉망이 된다..
        // multi thread를 해보면 sleep과는 상관 없이 잘 작동한다 
        ROS_INFO("IMU VEL [%f, %f]", x_vel, y_vel);
    }

    void ThreadClass::odomCallback(const nav_msgs::Odometry::ConstPtr &msg) {
        float x_pos = msg->pose.pose.position.x;
        float y_pos = msg->pose.pose.position.y;

        ROS_INFO("ODOM POS [%f, %f]", x_pos, y_pos);
    }


int main(int argc, char** argv) { 
    ros::init(argc, argv, "Thread_example_node");
    ThreadClass thread_obj;

    ros::waitForShutdown();

    return 0;
}