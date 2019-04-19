csrc="main.cpp"

for F in `find ./engine -type f`
do
	echo Adding $(basename ${F})...
	csrc="$csrc ${F}"
done


for F in `find ./game -type f`
do
	echo Adding $(basename ${F})...
	csrc="$csrc ${F}"
done

g++ ${csrc} -o main -lGL -lGLU -lglut && ./main
