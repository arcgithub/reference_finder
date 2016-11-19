#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include "geometry_msgs/Pose.h"
#include "nav_msgs/Path.h"
#include "arc_msgs/State.h"
#include <sstream>
#include"iostream"
#include <math.h>

using namespace std;

arc_msgs::State status;
nav_msgs::Path pathus;
float x_now=status.pose.pose.position.x;
float y_now=status.pose.pose.position.y;
float theta_now=status.pose.pose.orientation.z;
float x_curve;
float y_curve;
float theta_curve;
int s_0=status.current_arrayposition;


void intersect(int n_points)
{
for(int i=0; i<n_points; i++)
	{
	}
}

void curve(float s)
{
x_curve=s*s;
y_curve=2*s;
}

void derivative(float s)
{
theta_curve=1/s;
}

void curvature (float s)
{
-4/pow(4*s*s+4,1.5);
}

void safe_the_path(const nav_msgs::Path subscribed)
{
pathus=subscribed;
}

void safe_the_state(const arc_msgs::State subscribed)
{
  status=subscribed;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "reference_finder");
  ros::NodeHandle n;
  ros::Subscriber sub1 = n.subscribe("state", 1000, safe_the_state);
  ros::Subscriber sub2 = n.subscribe("path", 1000, safe_the_path);

  ros::Publisher pub = n.advertise<std_msgs::Float64>("curve_param", 1000);
  ros::Rate loop_rate(10);

 
cout<<status.current_arrayposition;
 // pub.publish(s_0);
  


return 0;
}
