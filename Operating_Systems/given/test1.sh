./start 7
sleep 1
./producer 1 9 &
./producer 2 15 &
./producer 3 5 &
./producer 4 7 &
./producer 5 9 &
./producer 6 11 &
./consumer 1
