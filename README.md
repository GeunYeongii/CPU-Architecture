# CPU-Architecture
Implement CPU Architecture

## Register
   > Memory address register (MAR)
   - Specifies the address in memory for the next read or write.
   
   > Memory buffer register (MBR)
   - Contains the data to be written into memory or receives the data read from memory.
   
   > Instruction register (IR)
   - each instruction to be executed is loaded into the instruction register, which holds it while it is decoded, prepared and ultimately executed, which can take several steps.

   > Program counter register (PC)
   - indicate the current position of program sequence in a computer system.
   
   
## The fetch decode excute cycle
<img width="40%" src="https://user-images.githubusercontent.com/82564045/139231607-37d4eaa6-0510-459e-8d2e-8917af9cbfd6.gif"/>


## Basic Components : Top Level View
<img width="60%" src="https://user-images.githubusercontent.com/82564045/139232289-dee4b5e2-e47b-4e36-93fc-22d00f363228.gif"/>

## Instruction Set
Maching Language|Instruction|
|---|---|
|000|end|
|1xx|add|
|2xx|subtract|
|3xx|store|
|5xx|load|
|6xx|branch always|
|7xx|branch if 0|
|8xx|branch if >= 0|
|901|input|
|902|output|
