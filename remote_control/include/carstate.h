#include <vector>
#include <string>
#include "ros/ros.h"
#include "std_msgs/Float64.h"

#pragma once

class carstate
{
protected:

    // const float steeringGain   = -1.2135;
    // const float steeringOffset = 0.4;
    
    // MAYBE: make thise singleton... (probaly not)
    // ros::Publisher _duty_cycle_pub;
    // ros::Publisher _servo_pub;
    ros::NodeHandle *_n;
    
    ros::Publisher _ackermann_cmd_mux;
    
    const float MAX_TURN = 0.34;
    const float MAX_SPEED = 2.0;
    
    float _speed;
    float _angle;
    
public:
    carstate(ros::NodeHandle *n);
    
    virtual void run(void) = 0;
    
    // void SetWheel(float angle);
    // void SetSpeed(float speed);
    void Ackerman(float speed, float angle);
    
    virtual ~carstate(void);
};