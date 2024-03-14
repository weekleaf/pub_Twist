#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"
// void delay(double sec,geometry_msgs::Twist *msg){
//     ros::Time t = ros::Time::now();
//     ros::Duration d(sec);
//     while(ros::Time::now().toSec() - t.toSec() < d.toSec());
// }
int main(int argc,char *argv[]){
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"pub_Twist");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 1000);
    geometry_msgs::Twist msg;
    ros::Time t = ros::Time::now();
    ros::Duration d(5.0);
    while (ros::ok)
    {   
        msg.linear.x = 0.0;
        msg.linear.y = 0.2;
        msg.linear.z = 0.0;
        msg.angular.x = 0.0;
        msg.angular.y = 0.0;
        msg.angular.z = 0.0;
        //pub.publish(msg);
        t = ros::Time::now();
        while(ros::Time::now().toSec() - t.toSec() < d.toSec()){
            pub.publish(msg);
        }
        // ros::Duration(5).sleep();
        // ros::Duration(5).sleep();
        msg.linear.x = 0.0;
        msg.linear.y = -0.2;
        msg.linear.z = 0.0;
        msg.angular.x = 0.0;
        msg.angular.y = 0.0;
        msg.angular.z = 0.0;
        //pub.publish(msg);
        t = ros::Time::now();
        while(ros::Time::now().toSec() - t.toSec() < d.toSec()){
            pub.publish(msg);
        }
        ros::spinOnce();
    }
    return 0;
}