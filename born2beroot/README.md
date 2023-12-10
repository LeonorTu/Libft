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
* APT is a lower-level package manager and Aptitude is a high-level package manager.
* APT is gommand-line tool which is text-base and Aptitude is graphical user interface which is more user-friendly.

**APPArmor**  
A security module in the Linux kernel that allows the system administrator to restrict the capabilities of a program.

**LVM**   
LVM(Logical Volume Manager) is an abstraction layer between a storage device and a file system.   

**SUDO**  
* sudo (superuser do) is a command in Linux and Unix-like operating systems that allows users to run commands with the privileges of another user, most commonly the root user.  
Value of sudo  
* Increased security: By allowing non-root users to perform administrative tasks, sudo reduces the need for users to log in as root, which can help to protect the system from unauthorized access and malicious actions.
* Simplified administration: sudo simplifies system administration by allowing non-root users to perform tasks without the need to manually switch to the root user. This can save time and effort for system administrators.
* Increased accountability: When non-root users run commands with sudo, their actions are logged, which can help to track who performed specific system changes and when they were made. This can aid in troubleshooting and identifying potential security issues.

**UFW**  
* UFW(Uncomplicated Firewall) is a software application responsible for ensuring that the system administrator can manage iptables in a simple way.

**SSH**  
SSH(Secure Shell) is a network protocol that allows users to securely access and manage remote machines.

**Cron**  
Linux task manager that allows us to execute commands at a certain time. We can automate some tasks just by telling cron what command we want to run at a specific time.

**Port**  
Range: 0-65535 (0-1023: System or well-known ports)  
Common port numbers  
* 80, 443 - Web pages (HTTP (Hypertext Transfer Protocol), HTTPS (Hypertext Transfer Protocol Secure))  
* 21 - FTP (File Transfer Protocal: The standard protocol used to transfer files over a network)  
* 25 - Email (SMTP)  

**WordPress**  
A content management system focused on the creation of any type of website.

**Lighttpd**  
A web server designed to be fast, secure, flexible, and standards-compliant. It is optimized for environments where speed is a top priority because it consumes less CPU and RAM than other servers.

**Mariadb**  
A database used for various purposes, such as data warehousing, e-commerce, enterprise-level functions, and logging applications.  

**PHP**  
A programming language used to develop dynamic web applications and interactive websites. PHP runs on the server side.  

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
`getent group sudo`  
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
* Check that the UFW program is installed on the virtual machine and check that it works correctly.  
`dpkg -s ufw`  
`sudo service ufw status`  

* List the active rules in UFW, if the bonus part is not done, the rule for port 4242 should only appear.  
`sudo ufw status`  

* Create a new rule for port 8080. Verify that it has been added to the active rules and then you can delete it.  
`sudo ufw allow 8080`  
`sudo ufw delete allow 8080`  

**SSH**
* Check that the ssh service is installed on the virtual machine, that it works correctly, and that it only works on port 4242.  
`which ssh`  
`sudo service ssh status`  

* Use ssh to log in with the newly created user. Make sure that you cannot use ssh with the root user.   
`ssh username@localhost -p 4242`  
`su -`  

**Script Monitoring**
* Modify the runtime of the script from 10 minutes to 1.   
`sudo crontab -u root -e`    
* Make the script stop running when the server has started, but without modifying the script.  
`sudo /etc/init.d/cron stop`  
`sudo /etc/init.d/cron start`  

**Bonus**  
FTP(File Transfer Protocal)  
* connect server to the web server  
`ftp 10.0.2.15`

* find the current local directory  
`!pwd`

* list the files in local directory  
`!ls`

* get the file from remote directory  
`mget file_name`
