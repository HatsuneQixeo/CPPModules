function wait_prompt()
{
	read -n 1 -s -r -p "Press any key to continue"
	echo
}

EXE="./convert"
make >/dev/null || exit 1

if [ ! -e "$EXE" ]
then
	echo "Error: $EXE not found"
	exit 1
elif [ ! -f "$EXE" ]
then
	echo "Error: $EXE is not a regular file"
	exit 1
elif [ ! -x "$EXE" ]
then
	echo "Error: $EXE not executable"
	exit 1
fi

[ "$1" == "prompt" ] && wait=wait_prompt || wait=""

function convert_test()
{
	for arg in "$@"
	do
		echo "$EXE $arg"
		$EXE "$arg"
		$wait
		echo
	done
	echo
}

function convert_numeric_test()
{
	echo "Integer"
	for arg in "$@"
	do
		convert_test "$arg" "+$arg" "-$arg"
	done
	echo "Double"
	for arg in "$@"
	do
		convert_test "$arg.$arg" "+$arg.$arg" "-$arg.$arg"
	done
	echo "Float"
	for arg in "$@"
	do
		convert_test "$arg.$arg"f "+$arg.$arg"f "-$arg.$arg"f
	done
}

# echo "Test: Alpha"
# convert_test {a..z} {A..Z}

# echo "Test: Special"
# convert_test \, \. \; \: \! \? \" \' \( \) \[ \] \{ \} \\ \/ \| \< \> \~ \` \@ \# \$ \% \^ \& \* \_ \= ' '

echo "Test: Numeric:"
convert_numeric_test 831

echo "Test: Sign"
convert_test + - +0 -0

echo "Test: InvalidSign"
convert_test +-01 -+01

echo "Test: INT_MIN"
convert_test -2147483648

echo "Test: INT_MAX"
convert_test 2147483647

echo "Test: Integer Overflow"
convert_test 2147483648

echo "Test: Integer Underflow"
convert_test -2147483649

echo "Test: Space"
convert_test ' ' '  831  ' '831  ' '  831'

echo "Tests: Invalid"
convert_test '' 'Hatsune Miku' '831Miku' 'Miku831'

echo "Test: Psuedo Literal"
convert_test -inf +inf nan -inff +inff nanf

echo "Test: Exception"
convert_test 8318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318318313939
