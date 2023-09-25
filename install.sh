#!/bin/bash

hdir="/usr/include/libsenmath"
ldir="/usr/lib/libsenmath"

current_dir="$(dirname "$0")"

lib_dir=$current_dir/out/libsenmath.a
headers_dir=$current_dir/headers

if [ -d "$hdir" ]
then
	echo "Directory $hdir Found: Updating headers..."
	rm -rf $hdir/*
	echo "Copying headers from $headers_dir to $hdir"
	cp $headers_dir/* $hdir 
else
	echo "Directory $hdir Not Found: Installing headers..."
	mkdir $hdir
	echo "Copying headers from $headers_dir to $hdir"
	cp $headers_dir/* $hdir
fi

if test -f $hdir/../libsenmath.h
then
	echo "Big Header Found: Updating..."
	rm $hdir/../libsenmath.h
	cp $headers_dir/libsenmath.h $hdir/..
else
	echo "Big Header Not found: Installing..."
	cp $headers_dir/libsenmath.h $hdir/..
fi	

if [ -d "$ldir" ]
then
	echo "Directory $ldir Found: Updating library..."
	rm -rf $ldir/*
	echo "Copying $lib_dir to $ldir"
	cp $lib_dir $ldir 
else
	echo "Directory $ldir Not Found: Installing library..."
	mkdir $ldir
	echo "Copying $lib_dir to $ldir"
	cp $lib_dir $ldir
fi
