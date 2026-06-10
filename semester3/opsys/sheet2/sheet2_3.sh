#!/bin/sh

end=0
while [ $end -lt 1 ]
do
    echo "Input:"
    read input
    
    if [ $input = "END" ]; then
        end=$(( $end + 1))
    else
        echo $input | tr 'a-z' 'A-Z'
    fi

done