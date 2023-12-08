#check service state
sudo service ssh status

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
