#!/usr/bin/env python
import rospy
#from dbw_mkz_msgs.msg import SteeringCmd
from std_msgs.msg import String

def CommandSender():
    pub = rospy.Publisher('subscriber', String, queue_size=10)
    rospy.init_node('Commands', anonymous=True)
    rate = rospy.Rate(10) # 10hz
    while not rospy.is_shutdown():
        hello_str = "Send string message %s" % rospy.get_time()
        cmd = String()
        cmd.data = "test"
        ## change this to see the difference
        rospy.loginfo(hello_str)
        pub.publish(cmd)
        rate.sleep()

if __name__ == '__main__':
    try:
        CommandSender()
    except rospy.ROSInterruptException:
        pass