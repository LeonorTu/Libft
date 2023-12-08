export PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin
wall  >/dev/tty1 "
========================= System Monitoring =========================
#Architecture: $(uname -a)
#CPU physical: $(grep "physical id" /proc/cpuinfo | wc -l)
#CPU virtual: $(nproc)
#Available RAM: $(free --mega | grep Mem | awk '{print $7}')/$(free --mega | grep Mem | awk '{print $2}')MB ($(free --mega | grep Mem | awk '{printf("%.2f"), $3/$2*100}')%)
#Memory utilization: $(df -BG | grep "/dev/" | grep -v "/boot" | awk '{memory_use += $3} END {print memory_use}')MB/$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $2} END {print disk_u}')GB ($(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} {disk_t+= $2} END {printf("%.2f"), disk_u/disk_t*100}')%)
#CPU utilization: $(vmstat | tail -1 | awk '{printf("%.2f"), 100-$15}')%
#Last reboot: $(who -b | awk '{print $3 " " $4}')
#LVM active: $(if [ $(lvscan | grep "ACTIVE" | wc -l) -gt 0 ]; then echo yes; else echo no; fi)
#Active connection: $(ss -ta | grep ESTAB | wc -l)
#Users: $(users | wc -w)
#Network address: IP $(hostname -I)($(ip link | grep "link/ether" | awk '{print $2}'))
#Sudo: $(journalctl _COMM=sudo | grep COMMAND | wc -l)
"
