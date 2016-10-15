# https://www.raspberrypi.org/forums/viewtopic.php?f=43&t=43969&start=150

Pi:
cvlc v4l2:///dev/video0 --v4l2-width 800 --v4l2-height 600 --v4l2-chroma h264 --sout '#standard{access=http,mux=ts,dst=0.0.0.0:12345}' -vvv

Host:
vlc -vvv -I "dummy" http://picam:12345 --sout '#transcode{vcodec=theo,vb=1024}:http{dst=:8080/webcam.ogg}'

