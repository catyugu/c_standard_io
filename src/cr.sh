# Compile and run a certain cpp file using gcc
full_file_name=$1
out_file_name=/root/project/c_stdin_stdout/obj/${full_file_name%.*}
gcc -O0 $full_file_name -o $out_file_name
if [ $? -ne 0 ]; then
    echo "Compile failed"
    exit 1
fi
echo "Running $out_file_name"
echo "--------------------------------------------------------------------------------"
echo "Output:"
$out_file_name
echo "--------------------------------------------------------------------------------"
echo "Done"