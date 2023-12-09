**Virtual Machine**  
* Allows multiple operating systems to run on physical machine.  
* Creates virtual operating system on top of other opearating system.   
* All virtual machines are isolated and they share the resouces of the physical machine.
* If something breaks iside VM, it doesn't affect the host machine.  
**Benefits**
* Learn and experiment  
* Test your app on different OS  

**Debian vs Rocky**
* Debian is maintained by non-profit community. It uses AppArmor as its primary mandatory access control system which is easier to set up and manage.
* Rocky is based on Red Hat Enterprise Linux (enterprise operating system). 

**Aptitude vs Apt**
* APT is a lower-level package manager and aptitude is a high-level package manager.
* APT is gommand-line tool which is text-base and Aptitude is graphical user interface which is more user-friendly.

**APPArmor**
A security module in the Linux kernel that allows the system administrator to restrict the capabilities of a program.

* **Port**  
Range: 0-65535 (0-1023: System or well-known ports)  
Common port numbers  
80, 443 - Web pages (HTTP (Hypertext Transfer Protocol), HTTPS (Hypertext Transfer Protocol Secure))  
21 - FTP (File Transfer Protocal: The standard protocol used to transfer files over a network)  
25 - Email (SMTP) 

**Evaluation Command**
* Verify that no graphical interface is in use
     ls /usr/bin/*session
