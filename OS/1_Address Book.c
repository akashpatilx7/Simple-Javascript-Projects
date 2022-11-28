opt=1
while [ $opt -ne 6 ]
do
        echo -e "Choose one of the Following\n1. Create a New Address Book\n2. View Records\n3. Insert new Record\n4. Delete a Record>        # echo -e, enables special features of echo to use \n \t \b etc.
        read opt
        case $opt in

        1)
                echo "Enter filename"
                read fileName
                if [ -e $fileName ]
                         then   # -e to check if file exists, if exits show message
                        echo " $fileName already exists , please enter new name "
                        read fileName
                fi
                cont=1
                echo -e  "NAME\tNUMBER\t\tADDRESS\n===============================\n" | cat >> $fileName
                while [ "$cont" -ne 0 ]
                do
                        echo -e "\nEnter Name"
                        read name
                        echo -e "Enter Phone Number of $name"
                        read number
                        echo "Enter Address of $name"
                        read address
                        echo -e "$name\t$number\t\t$address" | cat >> $fileName
                        echo "Enter 0 to Stop, 1 to Enter next"
                        read cont
                done
                ;;

        2)
                cat $fileName
                ;;
        3)
                echo -e "\nEnter Name"
                read name
                echo -e "Enter Phone Number of $name"
                read number
                echo -e "Enter Address of $name"
                read address
                echo -e "$name\t$number\t\t$address" | cat >> $fileName
                ;;
        4)
                echo -e "Delete record\nEnter Name/Phone Number"
                read pattern
                temp="temp"
                grep -v $pattern $fileName | cat >> $temp
                rm $fileName
                cat $temp | cat >> $fileName
                rm $temp
                ;;
        5)
                echo -e "Modify record\nEnter Name/Phone Number"
                ;;
        5)
                echo -e "Modify record\nEnter Name/Phone Number"
                read pattern
                temp="temp"
                grep -v $pattern $fileName | cat >> $temp
                rm $fileName
                cat $temp | cat >> $fileName
                rm $temp
                echo "Enter New  Name"
                read name
                echo "Enter New Phone Number of $name"
                read number
                echo "Enter New Address of $name"
                read address
                echo -e "$name\t$number\t$address" | cat >> $fileName
                ;;
        6)
                ;;
        esac
done