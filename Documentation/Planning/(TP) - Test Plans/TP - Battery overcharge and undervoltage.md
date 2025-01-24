# 1 Test Overcharge Protection
```
Battery is charged full via USB
Then 
Charging LED shall be powered off
ADC of the Microcontroller monitors the Voltage of the battery
The Voltage must no longer increase, even though the usb connector remains connected
```
# 2 Test Undervoltage Protection
```
Battery is discharged completly
Microcontroller logs current measured voltage to the console
The last reported value of the log must be above the minimal discharge threshold
```

