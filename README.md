# CPP_THREADS_EXAMPLE
ROS 기본 싱글 스레드에서 2개의 topic 을 구독할 때  
멀티 스레드를 사용할 경우의 example code

catkin_make 또는 catkin build 후


싱글 스레드 노드 실행
```
rosrun cpp_threads_example cpp_threads_example_node
```

멀티 스레드 노드 실행
```
rosrun cpp_threads_example cpp_threads_example_async_node 

```


odom 및 imu topic은 turtlebot3_gazebo 시뮬레이터 및 로봇에서 직접 받아서 사용  
또는 다른 가능한 토픽으로 변경해서 사용
