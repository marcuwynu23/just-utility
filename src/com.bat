@echo off

set co=(cppi,jvi,cci)

for %%i in %co% do (
	g++ -std=gnu++11 -o ..\dist\%%i %%i.cpp
)