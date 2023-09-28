# pig

API to read linux memory resource usage

## install

```
make
./pig
```

## example

```
// get all
curl localhost:8080/api/cpu/all  
curl localhost:8080/api/memory/all  

// get specified resources
curl localhost:8080/api/cpu/user_time  
{"note":"unit: MS(all core sum)","user_time":405844}

curl localhost:8080/api/memory/memtotal
{"memtotal":1969536,"note":"unit: KB(mlocked is n locks)"}

curl localhost:8080/api/random/system/8
{"number": -7}
```