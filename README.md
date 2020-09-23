# Figures
This is an application where you from a .txt file choose what will be shown on the screen and how it will be shown.<br/>

To see how this code was made, please read the [Documentation] (https://github.com/juamarCas/Figures/wiki/_new)

## Application execution
The .exe file is in _Figures/Figures/Executable/Figures.exe_ you just need to double click on it. <br/>
To reload the application after you modify the config.txt press __Enter__

### Configuration
The config.txt is in _Figures/Figures/Executable/res/config.txt_ open it with a text editor to modify the parameters.

#### Parameters
This are all the parámeters you can use to modify the config.txt: <br/>

|    Command      |  Variable  | Possible values | Default Values  |
|-----------------|:----------:|:---------------:|:---------------:|
|  -Color         |    red     |    0.0 - 1.0    |       0.5       |
|                 |    blue    |    0.0 - 1.0    |       0.5       |
|                 |    green   |    0.0 - 1.0    |       0.5       |
| -Charasteristic |   figure   |    Triangle     |      Square     |
|                 |            |    Circle       |                 |
|                 |            |    Square       |                 | 
|                 |            |    Hexagon      |                 |
|                 |    size    |    0.0 - 10.0   |       4.0       |
|                 |    rate    |    0.0 - 10.0   |       5.0       |
|                 |  animation |       Side      |       Side      | 
|                 |            |      UpDown     |                 |
|                 |            |      Circular   |                 |
|                 |            |        Box      |                 |

##### Example
Example 1:<br/>
```
-Color red =  0.8
-Color green = 0.4
-Color blue = 0.3

-Characteristic figure = Triangle
-Characteristic rate = 2
-Characteristic size = 4
-Characteristic animation = Box

```

Example 2:<br/>
```
-Color red =  0.5
-Color green = 0.3
-Color blue = 0.1

-Characteristic figure = Circle
-Characteristic rate = 4
-Characteristic size = 6
-Characteristic animation = Circular

```