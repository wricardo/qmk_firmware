e Whitefox
make whitefox:wricardo && echo "press the reset button" && sleep 3 && dfu-util -D whitefox_wricardo.bin

# DZ60
make dz60:wricardo:dfu

# TOFU (kbd6x)
make kbdfans/kbd6x:wricardo:dfu
