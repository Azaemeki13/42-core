Here is how to use the different scripts: 
If you want to run them globally, then they should be in /usr/local/bin .
To make sure that this works, please use nano ~/.bashrc then add the following at the end of configuration file : export PATH="$HOME/bin:$PATH" then reload with source ~/.bashrc
the script must also be runable , for this chmod +x nameofthescript.sh

automakefile allows you to automatically add and format the .c file on your makefile, even though they need to have a specific format for the SRC as follows :
# BEGIN SRC
SRC = \
# END SRC (line number: )

autonormy allows you to automatically format using c_formatter_42 given that you installed it correctly. 

For both of them, you can just type nameofthescript.sh or autonormy  .                (. if you want whole folder , classic command, otherwise for autonormy , if you just wnt one file, autonormy nameofthefile.filxtension) 
Cheers

