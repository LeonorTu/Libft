#check service state
sudo service ufw status
sudo service ssh status
sudo service vsftpd status

#restart SSH Server
sudo systemctl restart ssh

#install the library for the Pluggable Authentication Modules (PAM) system
sudo apt install libpam-pwquality

#change root password
sudo passwd root

#connect via ssh from the machine to the virtual machine
ssh <user>@localhost -p 4242
#ssh jtu@localhost -p 4242

#each "physical id" represents a physical processor or socket
grep "physical id" /proc/cpuinfo | wc -l
#$() syntax is used for command substitution

#change timezone
timedatectl set-timezone Europe/Helsinki

#check ufw status
sudo ufw status

#open port 21
sudo ufw allow 21

#change user password
sudo passwd <username>

#chang sudo passwood
sudo passwd

#connect server to the web server
ftp 10.0.2.15

# find the current local directory
!pwd

# list the files in local directory
!ls

#add file to ftp server
echo "Hello" | sudo tee test.txt
#tee elevates privileges via sudo, writes to the file, or
sudo sh -c 'echo "Hello" > test.txt'
#runs the entire command (including the file redirection) with elevated privileges
