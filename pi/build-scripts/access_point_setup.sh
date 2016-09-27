# https://frillip.com/using-your-raspberry-pi-3-as-a-wifi-access-point-with-hostapd/

apt-get install dnsmasq hostapd

cp ./etc /etc

iptables -t nat -A POSTROUTING -o eth0 -j MASQUERADE  
iptables -A FORWARD -i eth0 -o wlan0 -m state --state RELATED,ESTABLISHED -j ACCEPT  
iptables -A FORWARD -i wlan0 -o eth0 -j ACCEPT  


service hostapd start  
service dnsmasq start 