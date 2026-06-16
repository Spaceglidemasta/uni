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

Beware that my program does not take the website as an CL input because my program works with an UI class which already takes this input.

```Bash
sudo docker build -t website-monitor .

sudo docker run -it website-monitor
#<Program Routine>
```

## 4
#### b: Jenkins

Jenkins is a tool used for __Continous Integration / Deployment (CI/CD)__

Does what 2c) said

## 5

- Smaller test-scope
- Parallel tests
- caching: Cach things that didnt change (e.g. Dependencies, ...)
- Money $\rightarrow$ better hardware