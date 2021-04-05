if [[ $1 == "" ]]
then
	echo "need destination as first argument" >&2
else
	current_dir=$(pwd)
	output_dir= realpath $2
	echo $2

	mkdir $1
	cd $1
	if [[ $2 == "" ]] 
	then
		cmake ${current_dir}
		make
	else
		echo "CMAKE_INSTALL_PREFIX = " ${output_dir}
		cmake ${current_dir} -DENABLE_INSTALL=ON -DCMAKE_INSTALL_PREFIX="${output_dir}"
		make 
		make install
	fi
fi

