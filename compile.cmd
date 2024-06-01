@echo off
set bins=(arts,ct,chrome-dev,pyr,jr,justutil,sqlt3,wif,lc,fp,cat,dt,cppi,jvi,csi,cci,snip,jpb,ctp,cf,ls,wr,xr,fstr,rm,mv)
for %%i in %bins% do (
	echo compiling: %%i.cpp
	g++  -std=c++17  -I "src\include"  -o dist\%%i src\%%i.cpp src\runner.cpp -lshlwapi
)
echo compiling done..