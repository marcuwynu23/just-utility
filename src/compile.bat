@echo off
set co=(justutil,fp,cat,dt,cppi,jvi,cci,snip,jpb,ctp,cf,ls,wr,xr,fstr,rm,mv)

for %%i in %co% do (
	g++ -std=gnu++11 -o ..\dist\%%i %%i.cpp runner.cpp
)
