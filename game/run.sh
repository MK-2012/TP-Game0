if [[ $1 == "" ]]
then
	echo "need destination as first argument" >&2
else
	current_dir=$(pwd)
	mkdir $1
	cd $1
	cmake ${current_dir}
	make -j$(nproc)
fi

