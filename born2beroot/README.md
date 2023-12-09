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
**Simple Setup**
* Check UFW service is in use.  
`sudo ufw status`  
`sudo service ufw status`  
* Check that the SSH service is in use.  
`sudo service ssh status`  
* Check that you are using the Debian or Centos operating system.  
`uname -v`  

**User**
* Check that your user is within the "sudo" and "user42" groups.  
`getent group sudo ` 
`getent group user42`
Output meaning
| Field | Description |  
|---|---|---|   
| sudo | Name of the group |  
| x | Group identifier (GID) |  
| 27 | Numerical identifier (GID) |  
| jtu | Member of the group |  

* Create a new user and show that it follows the password policy we have created.  
`sudo adduser username`

* Create a new group named "evaluating".  
`sudo addgroup evaluating`  

* Add the new user to the new group.  
`sudo adduser username evaluating`  
To verify that it has been entered correctly.  
`getent group evaluating`  

**Hostname and Partition**  
* Check that the machine's hostname is correct login42.  
`hostname`  

* Modify hostname to replace your login with the evaluator's. In this case, we will replace it with student42.  
`sudo nano /etc/hostname`   
`sudo nano /etc/hosts`  

* Reboot the machine.  
`sudo reboot`  

* View the partition  
`lsblk`  

**SUDO**  
* Check that sudo is installed.   
`which sudo`
The dpkg command is used to manage packages in Debian-based Linux distributions.  
`dpkg -s sudo`  
* Add the new user to the sudo group.  
`sudo adduser username sudo`   
check that it is within the group.  
`getent group sudo`  
* Show the application of the rules imposed for sudo by the subject.  
`nano /etc/sudoers.d/sudo_config`  
* Show that the path /var/log/sudo/ exists and contains at least one file, in this we should see a history of the commands used with sudo.  
`cd /var/log/sudo`  
`ls`  
`cat sudo_config`  

**UFW/Firewalld**

**SSH**

**Script Monitoring**

**Bonus**
