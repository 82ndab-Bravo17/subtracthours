subtracthours
=============

subtracthours dll for Arma 3


(Compiled with Visual Studio 2013)

Called with the number of hours x to subtract from the current time, returns the time that was x hours ago as an array

eg  call compile ("subtracthours" callExtension ["10"]) will give you what the time was 10 hours ago.



1st value 0 if success, 1 if a error occurred
then

Day of Month (1-31)

Month (1-12)

Year (4 digits)

Hour (0-23)

Minute (0-59)

Seconds (0-59)





Place the dll in your Arma root folder.

Needs C++ redistributable for Visual Studio 2013, which can be found here:

http://www.microsoft.com/en-us/download/details.aspx?id=40784


