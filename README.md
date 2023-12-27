# miniRT

# Welcome to the beautiful world of raytracing !

```
as i venture into the realm of raytracing, the only way out is rendering it as my new reality...
the boundaries between me and my creation blur, blurring the line that i have drawn
the line that was used to discern the echo of the real from the whisper of the rendered
here in the rendered... reality is a fragile word, a tightrope that can lead one into madness...
here in the rendered... the dance of light and shadow continues
```

- Mandatory part without any bonus
- Tested on Linux
- Success 100/100

## Installation

```bash
  git clone https://github.com/spookier/miniRT.git
  cd miniRT
  make
  make bonus
```

if compile fails with message "can't find a suitable X11 include directory",
install it via

```bash
  sudo apt-get install gcc make xorg libxext-dev libbsd-dev
```

## Usage

```bash
  ./miniRT [maps]
```

example
```bash
  ./miniRT maps/minirt_scene.rt
```

## Mandatory part

### scene

![image](https://github.com/spookier/miniRT/assets/78352910/d0fdfe3b-b74d-4fb7-88e1-6f967abdfe26)


### object

![image](https://github.com/spookier/miniRT/assets/78352910/bad0aafb-9166-4037-86df-a33763f1d7ba)
###### ↳ object: without any rotation

![image](https://github.com/spookier/miniRT/assets/78352910/20860035-9a93-49ad-b90a-babfc3f74f02)
###### ↳ object rotation applied: plane and cylinder


### camera

![image](https://github.com/spookier/miniRT/assets/78352910/8353d281-1ef3-4ebb-8cc5-2a578fb1ce40)
###### ↳ camera position(0,0,-10), normal vector(0,0,1)

![image](https://github.com/spookier/miniRT/assets/78352910/b9bd787d-babd-405c-b91c-6877710b5d47)
###### ↳ camera position(0,0,10), normal vector(0,0,-1)

![image](https://github.com/spookier/miniRT/assets/78352910/067f6243-3918-4c1c-84f3-6d57fb0705f6)
###### ↳ camera position(10,0,0), normal vector(-1,0,0)

![image](https://github.com/spookier/miniRT/assets/78352910/d86852ef-0793-4a24-8846-d278d5d22151)
###### ↳ camera position(-10,0,0), normal vector(1,0,0)

![image](https://github.com/spookier/miniRT/assets/78352910/f2aa2055-b06d-4f61-9f52-ac8c17b7392b)
###### ↳ camera position(0,10,0), normal vector(0,-1,0)

![image](https://github.com/spookier/miniRT/assets/78352910/c679e939-6f86-4039-8f0f-772d5c887a95)
###### ↳ camera position(0,-10,0), normal vector(0,1,0)

![image](https://github.com/spookier/miniRT/assets/78352910/424891ba-f741-4c15-9fc0-c18208649f83)
###### ↳ camera rotation applied

![image](https://github.com/spookier/miniRT/assets/78352910/75001649-7687-4326-a9a5-ac6b4a03d1ee)
###### ↳ camera rotation applied


### light

![image](https://github.com/spookier/miniRT/assets/78352910/a9116750-affc-462a-a1a0-070c1396a3fe)
###### ↳ light position(-3,0,-2)

![image](https://github.com/spookier/miniRT/assets/78352910/2832386a-9d2d-4819-9c6b-5315385d9382)
###### ↳ light position(3,0,-2)

![image](https://github.com/spookier/miniRT/assets/78352910/6e46e427-471f-48e4-b55e-c6b73753f635)
###### ↳ light position(0,-3,-2)

![image](https://github.com/spookier/miniRT/assets/78352910/12c1d9a8-5d15-4e25-903d-fee5b2ad507a)
###### ↳ light position(0,3,-2)

![image](https://github.com/spookier/miniRT/assets/78352910/6372f9df-b6ad-4954-a32e-8069d246ecaa)
###### ↳ light position(0,0,-5)

![image](https://github.com/spookier/miniRT/assets/78352910/05dba66d-2510-45e1-b738-6a5afeb50ccb)
###### ↳ light position(0,0,5)
