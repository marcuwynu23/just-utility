@echo off
set bins=(pyr,jr,justutil,sqlt3,wif,lc,fp,cat,dt,cppi,jvi,csi,cci,snip,jpb,ctp,cf,ls,wr,xr,fstr,rm,mv)
for %%i in %bins% do (
	echo compiling: %%i.cpp
	g++  -std=gnu++11  -I "src\include"  -o dist\%%i src\%%i.cpp src\runner.cpp -lshlwapi
)
echo compiling done..