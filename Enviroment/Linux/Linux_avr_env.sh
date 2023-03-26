#!/bin/bash

# List of tools to check and install
tools=("code" "avr-gcc" "avrdude" )

# Function to check if a tool is installed
check_tool() {
    if command -v $1 &> /dev/null
    then
        return 1
    else
        return 0
    fi
}

# Function to install a tool
install_tool() {
    echo "Installing $1..."
    case $1 in
        avr-gcc)
            sudo apt-get install -y gcc-avr avr-libc
            ;;
        code)
            sudo snap install code --classic
            ;;
        *)
            sudo apt-get install -y $1
            ;;
    esac
}


# Loop through the list and check/install each tool
for tool in "${tools[@]}"
do
    check_tool $tool
    result=$?
    if [ $result -eq 1 ]
    then
        echo -e "$tool is \e[1;32minstalled\e[0m"

    else
	echo -e "$tool is \e[1;31mnot installed\e[0m"
	install_tool $tool
	check_tool $tool
	if [ $? -eq 1 ]
	then
	echo -e "$tool now is \e[1;32minstalled\e[0m"
	fi
    fi
done



