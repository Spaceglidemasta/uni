# Exercise 8
## 1
A virtual machine is an complete OS, with an own Kernel and drivers

A Docker container uses the Kernel of the main OS, only implementing software: No kernel; no drivers

## 2
$\rightarrow$ c

a, b and d are nonsense

## 3

```Bash
sudo apt install docker.io -y

sudo systemctl start docker

#Testing
docker --version
# <version>
docker run hello-world
# <hello-world Image test output>

mkdir website-monitor & cd website-monitor

vim Dockerfile
```

[Inserted Dockerfile instructions](website-monitor/Dockerfile)

