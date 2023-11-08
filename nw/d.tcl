u##### Declare Simulator 
set ns [new Simulator] 
##### Setting output file 
set file [open out.tr w] 
$ns trace-all $file 
set namfile [open out.nam w] 
$ns namtrace-all $namfile 
set tcpfile [open out.tcp w] 
Agent/TCP set trace_all_oneline_ true 
##### Setting Node 
set n0 [$ns node] 
set n1 [$ns node] 
set n2 [$ns node] 
set n3 [$ns node] 
##### Setting Link 
$ns duplex-link $n0 $n2 3Mb 5ms DropTail 
$ns duplex-link $n1 $n2 3Mb 5ms DropTail 
$ns duplex-link $n2 $n3 1.5Mb 10ms DropTail 
$ns duplex-link-op $n0 $n2 orient right-down 
$ns duplex-link-op $n1 $n2 orient right-up 
$ns duplex-link-op $n2 $n3 orient right 
$ns duplex-link-op $n2 $n3 queuePos 0.5 
##### Setting Queue Length 
$ns queue-limit $n2 $n3 20 
##### Setting UDP Agent 
set udp [new Agent/UDP] 
$ns attach-agent $n0 $udp 
set null [new Agent/Null] 
$ns attach-agent $n3 $null 
$ns connect $udp $null 
$udp set fid_ 0 
$ns color 0 blue 
##### Setting CBR Application 
set cbr [new Application/Traffic/CBR] 
$cbr attach-agent $udp 
##### Setting TCP Agent 
set tcp [new Agent/TCP] 
$ns attach-agent $n1 $tcp 
set sink [new Agent/TCPSink] 
$ns attach-agent $n3 $sink 
$ns connect $tcp $sink 
$tcp set fid_ 1 
$ns color 1 red 
### Setting output file of TCP Agent 
$tcp attach-trace $tcpfile 
$tcp trace cwnd_ 
##### Setting FTP Application 
set ftp [new Application/FTP] 
$ftp attach-agent $tcp 
##### Setting time schedule of simulation 
$ns at 1.0 "$cbr start" 
$ns at 1.5 "$ftp start" 
$ns at 3.0 "$ftp stop" 
$ns at 3.5 "$cbr stop" 
$ns at 4.0 "finish" 
proc finish {} { 
global ns file namfile tcpfile 
$ns flush-trace 
close $file 
close $namfile 
close $tcpfile 
exit 0 
} 
##### Finish setting and start simulation 
$ns run 
