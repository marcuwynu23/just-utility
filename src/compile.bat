@echo off
set co=(ctp,cf,ls,wr,xr,justutil,fstr,rm,mv)

for %%i in %co% do (
	g++ -o ..\dist\%%i %%i.cpp
)
