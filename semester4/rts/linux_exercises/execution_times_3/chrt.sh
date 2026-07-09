#!/bin/bash

if [[ $1 == "" ]]
then
  echo Please run like taskset 2 ./chrt.sh 5000000
fi

# compile the source code
gcc job.c -o job1.x

# create copies of executable with different names. This can help to identify them in top.
cp job1.x job2.x
cp job1.x job3.x

# just to make the parameter verbose. Use a value that slice is around 90-99 milli-seconds
#export LOAD=$1
export LOAD=6550000

# launch all programs in parallel. Without the '&' they would be executed sequentially.

chrt --rr 20 taskset 1 ./job1.x 1 30 $LOAD &
sleep 0.1
chrt --rr 30 taskset 1 ./job2.x 2 10 $LOAD &
chrt --rr 10 taskset 1 ./job3.x 3 10 $LOAD &
sleep 0.5
chrt --rr 20 taskset 1 ./job1.x 4 30 $LOAD &
sleep 0.1
chrt --rr 30 taskset 1 ./job2.x 5 10 $LOAD &
chrt --rr 10 taskset 1 ./job3.x 6 10 $LOAD &
# ...
#
# feel free to add more requests!
#
